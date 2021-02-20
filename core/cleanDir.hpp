/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanDir.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 18:21:22 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/02/20 20:08:44 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEANDIR_HPP
# define CLEANDIR_HPP

# include <iostream>
# include <string>
# include <fstream>

# include <vector>
# include <algorithm>

# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <dirent.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

// This is a minimal set of ANSI/VT100 color codes
# define _END "\033[0m"
# define _BOLD "\033[1m"
# define _UNDER "\033[4m"
# define _REV "\033[7m"

// Colors
# define _GREY "\033[1;30m"
# define _RED "\033[1;31m"
# define _GREEN "\033[1;32m"
# define _YELLOW "\033[1;33m"
# define _BLUE "\033[1;34m"
# define _PURPLE "\033[1;35m"
# define _CYAN "\033[1;36m"
# define _WHITE "\033[1;37m"

// Inverted, i.e. colored backgrounds
# define _IGREY "\033[1;40m"
# define _IRED "\033[1;41m"
# define _IGREEN "\033[1;42m"
# define _IYELLOW "\033[1;43m"
# define _IBLUE "\033[1;44m"
# define _IPURPLE "\033[1;45m"
# define _ICYAN "\033[1;46m"
# define _IWHITE "\033[1;47m"


class cleanDir {
private:
	std::string				_filename;
	std::ofstream			_ffile;
	std::vector<std::string> _cleanListRules;
	std::vector<char *>		_filesToRemove;

	bool					_useRecursif;
	bool					_displayOutput;

public:
	cleanDir ();
	cleanDir (std::string const filename, int argc, char const **argv);
	virtual ~cleanDir ();
	cleanDir (cleanDir const &lhs);
	cleanDir &operator=(cleanDir const &lhs);

	void initClean(int argc, char const **argv);
	void readInputFile();
	void getFilesToRemove();
	void getFiles(char *current_directory, bool recursif);
	bool containRule(const char *str);
	void removeFiles();
	void printResult();
};

#endif
