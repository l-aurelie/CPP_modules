/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 08:44:47 by user42            #+#    #+#             */
/*   Updated: 2021/11/09 12:17:09 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"

int Contact::nb_contact = 0;

Contact::Contact(void){}

Contact::~Contact(void){}

void Contact::init_contact(void)
{
	int number_ok = 0;
	Contact::nb_contact++;
	std::cout << "first name : " << std::endl;
	std::getline (std::cin, this->_first_name);
	std::cout << "last name : " << std::endl;
	std::getline (std::cin, this->_last_name);
	std::cout << "nickname : " << std::endl;
	std::getline (std::cin, this->_nickname);
	while(!number_ok)
	{
		std::cout << "phone_number : " << std::endl;
		std::getline (std::cin, this->_phone_number);
		number_ok = 1;
		for (size_t i = 0; i < _phone_number.length(); i++)
		{
			if(i == 0 && _phone_number[i] == '+')
				i++;
			if (!std::isdigit(_phone_number[i]))
			{
				number_ok = 0;
				std::cout << "entree erronee, recommencez :" << std::endl;
				break;
			}
		}
	}
	std::cout << "darkest secret : " << std::endl;
	std::getline (std::cin, this->_darkest_secret);
}

		void Contact::list_contact(const int index) const
{	
	std::cout << "         " << index + 1;
	std::cout << "|" ;
 	this->_write_form_string(this->_first_name);
	std::cout << "|" ;
	this->_write_form_string(this->_last_name);
	std::cout << "|" ;
	this->_write_form_string(this->_nickname);
	std::cout << std::endl;
}

void Contact::display_contact(void) const
{
	std::cout << "first name :" << this->_first_name << std::endl;
	std::cout << "last name :"  << this->_last_name << std::endl;
	std::cout << "nickname :" << this->_nickname << std::endl;
	std::cout << "phone number :" << this->_phone_number << std::endl;
	std::cout << "darkest secret :" << this->_darkest_secret << std::endl;
}

void Contact::_write_form_string(const std::string str) const
{
	int res; 
	res = 10 - str.length();
	if (res >= 0)
	{

		for (int i = 0; i < res; i++)
			std::cout << " " ;
		std::cout << str;
	}
	else
	{
		for (int i = 0; i < 9 ; i++)
			std::cout << str[i];
		std::cout << ".";
	}
}

