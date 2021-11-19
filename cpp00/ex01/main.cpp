/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 09:11:36 by user42            #+#    #+#             */
/*   Updated: 2021/11/03 09:11:38 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PhoneBook.hpp"

int main()
{
	PhoneBook phone_book;
	std::string command;	

	do
	{
		command = phone_book.getcommand();
		if(command.empty())
			return 0;
		if (!command.compare("ADD"))
			phone_book.add();
		else if (!command.compare("SEARCH"))
			phone_book.search();
		else if (command.compare("EXIT"))
		{
			std::cout << std::endl << "La commande \"" << command << "\" n'existe pas" << std::endl << "Vous pouvez ajouter des contacts a l'aide de la commande ADD, les consulter via SEARCH ou utiliser EXIT pour quitter" << std::endl;
		}
	} while (command.compare("EXIT"));
	return 0;
}
