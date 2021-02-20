/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 18:22:54 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/02/20 20:58:03 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cleanDir.hpp"

int main(int ac, char const **argv)
{
	try
	{
		char *actudir = (char *)calloc(4096, sizeof(char));

		actudir = strcat(actudir, getenv("HOME"));
		actudir = strcat(actudir, "/.cleanlist.txt");
		cleanDir(actudir, ac, argv);
	}
	catch (std::string &error)
	{
		std::cout << error << '\n';
	}
	return (0);
}
