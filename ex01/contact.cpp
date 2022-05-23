/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegadri <adegadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:48:28 by adegadri          #+#    #+#             */
/*   Updated: 2022/05/23 16:54:56 by adegadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

std::string 	Contact::getfirstname() const
{
	return(this->firstname);
}
std::string 	Contact::getlastname() const
{
	return(this->lastname);
}
std::string 	Contact::getnickname() const
{
	return(this->nickname);
}
std::string 	Contact::getnumber() const
{
	return(this->phonenumber);
}
std::string 	Contact::getdarksecret() const
{
	return(this->darksecret);
}

std::string 	Contact::getid() const
{
	return(this->id);
}



void	Contact::Set_firstname(std::string s)
{
	firstname = s;
}

void	Contact::Set_lastname(std::string s)
{
	lastname = s;
}

void	Contact::Set_nickname(std::string s)
{
	nickname = s;
}

void	Contact::Set_number(std::string s)
{
	phonenumber = s;
}

void	Contact::Set_darksecret(std::string s)
{
	darksecret = s;
}
void	Contact::Set_id(std::string s)
{
	darksecret = s;
}