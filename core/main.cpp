/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 18:22:54 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/02/20 19:58:48 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cleanDir.hpp"

int main(int ac, char const **argv)
{
	try
	{
		cleanDir("cleanlist.txt", ac, argv);
	}
	catch (std::string &error)
	{
		std::cout << error << '\n';
	}
	return (0);
}
