/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanDir.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 18:20:31 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/02/20 20:09:56 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cleanDir.hpp"

// Default

cleanDir::cleanDir(std::string const filename, int argc, char const **argv) : _filename(filename)
{
	initClean(argc, argv);
	readInputFile();
	getFilesToRemove();
	removeFiles();
	if (_displayOutput)
		printResult();
}

cleanDir::~cleanDir () {}
cleanDir::cleanDir (cleanDir const &lhs) { *this = lhs; }

cleanDir &cleanDir::operator=(cleanDir const &lhs)
{
	if (this == &lhs)
		return (*this);
	_filename = lhs._filename;
	return (*this);
}

// Functions

void cleanDir::initClean(int argc, char const **argv)
{
	std::string line;

	_useRecursif = false;
	_displayOutput = false;
	if (argc > 1)
	{
		for (size_t i = 0; argv[i]; i++) {
			line = argv[i];
			if (line.find("-r") != std::string::npos)
				_useRecursif = true;
			if (line.find("-o") != std::string::npos)
				_displayOutput = true;
		}
	}
}

void cleanDir::readInputFile()
{
	std::ifstream inputFile;
	std::string line;
	int			i = 0;

	inputFile.open(_filename.c_str(), std::ios::in);
	if (!(inputFile.is_open()))
		throw std::string("Error : Invalid Filename, can't open it !");

		while (std::getline(inputFile, line))
		{
			if (line.find("*.") != std::string::npos)
				_cleanListRules.push_back(line);
			++i;
		}

	for (size_t i = 0; i < _cleanListRules.size(); i++) {
		_cleanListRules[i].erase(std::remove(_cleanListRules[i].begin(), _cleanListRules[i].end(), '*'), _cleanListRules[i].end());
	}
	inputFile.close();
}

bool cleanDir::containRule(const char *str)
{
	std::string s_str(str);

	for (size_t i = 0; i < _cleanListRules.size(); i++) {
		if ((s_str.find(_cleanListRules[i]) != std::string::npos))
			return (true);
	}
	return (false);
}

void cleanDir::getFiles(char *current_directory, bool recursif)
{
	DIR					*dir;
	struct dirent		*diread;

	if (!(dir = opendir(current_directory)))
		throw std::string("Error : failed to open dir !");
	while ((diread = readdir(dir)) != NULL)
	{
		if (diread->d_type == DT_REG && containRule(diread->d_name))
		{
			char *str = (char *)calloc(strlen(current_directory) +
			strlen(diread->d_name) +
			strlen("/") + 1, sizeof(char));

			str = strcat(str, current_directory);
			str = strcat(str, "/");
			str = strcat(str, diread->d_name);
			_filesToRemove.push_back(str);
		}
		else if (diread->d_type == DT_DIR && recursif &&
			strcmp(diread->d_name, ".") &&
			strcmp(diread->d_name, "..")
		)
			getFiles(strcat(strcat(current_directory, "/"), diread->d_name), recursif); // recursif
	}
	closedir(dir);
}

void cleanDir::removeFiles()
{
	for (size_t i = 0; i < _filesToRemove.size(); i++)
		std::remove(_filesToRemove[i]);
}

void cleanDir::getFilesToRemove()
{
	char				actudir[4096];

	if (!(getcwd(actudir, sizeof(actudir))))
		throw std::string("Error : failed to get directory !");
	getFiles(actudir, _useRecursif);
}
void cleanDir::printResult()
{
	std::cout << _GREEN << "Files removed : " << _END << '\n';
	if (_filesToRemove.size() == 0)
		std::cout << _YELLOW << "\t - No files removed !" << '\n';
	for (size_t i = 0; i < _filesToRemove.size(); i++) {
		std::cout << _YELLOW << "\t- " << _filesToRemove[i] << _END << '\n';
	}
}
