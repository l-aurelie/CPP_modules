/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 08:54:32 by user42            #+#    #+#             */
/*   Updated: 2021/11/03 08:57:08 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <string>

class PhoneBook {
public:

	PhoneBook(void);
	~PhoneBook(void);

	std::string getcommand(void) const;
	void add(void);
	void search(void) const;
private:
	
	Contact _contact[9];
};

#endif
