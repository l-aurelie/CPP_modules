/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 09:10:34 by user42            #+#    #+#             */
/*   Updated: 2021/11/03 09:10:43 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <limits>
#include <ios>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	std::cout << std::endl << "Bienvenue dans PhoneBook, votre annuaire nul." << std::endl << std::endl;
	std::cout << "Vous pouvez ajouter des contacts a l'aide de la commande ADD, les consulter via SEARCH ou utiliser EXIT pour quitter" << std::endl;
}

PhoneBook::~PhoneBook(void){}

std::string	PhoneBook::getcommand(void) const
{
		std::string command;

		std::cout << "Que souhaitez-vous faire ?" << std::endl;
		std::cin >> command;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (std::cin.eof())
			return "";
		return (command);
}

void PhoneBook::add(void)
{
	if (Contact::nb_contact < 8)
	{
		this->_contact[Contact::nb_contact].init_contact();
	}
	else
	{
		std::cout << "Nombre maximum de contacts atteint, merci de souscrire a l'offre premium pour plus de contenu" << std::endl;
	}
}

void PhoneBook::search(void) const
{
	int index;
	for (int i = 0; i < Contact::nb_contact; i++)
	{
		_contact[i].list_contact(i);
	}
	if(Contact::nb_contact == 0)
		std::cout << "Vous n'avez pas de contacts" << std::endl;
	else
	{
		std::cout << "Saisir l'index du contact a consulter : " << std::endl;
		while (! (std::cin >> index) || index <= 0 || index > Contact::nb_contact)
		{
			if(std::cin.fail())
			{
				std::cout << "Saisie incorrecte, recommencez : ";  
          		std::cin.clear();  
            	std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' ); 
			}
			else if(index <= 0 || index > Contact::nb_contact)
				std::cout << "Aucun contact a cet index, recommencez :" << std::endl;
		}
		_contact[index - 1].display_contact();
		std::cin.ignore();
	}
}
