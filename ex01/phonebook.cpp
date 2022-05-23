/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegadri <adegadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 18:01:41 by adegadri          #+#    #+#             */
/*   Updated: 2022/05/23 16:59:16 by adegadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

#include "phonebook.hpp"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	PhoneBook::print_firstname(int i)
{
	int	j;
	int	size;

	j = 0;
	size = 0;
	std::cout << "|";
	if (ft_strlen(this->contact[i].firstname) < 10)
	{
		while (j <= ft_strlen(this->contact[i].firstname) - 1)
		{
			std::cout << this->contact[i].firstname[j];
			j++;
		}
		while (j <= 10)
		{
			std::cout << " ";
			j++;
		}
	}
	else
	{
		while (j <= 10)
		{
			if (size < 10 && this->contact[i].firstname[j] != '\0')
				std::cout << this->contact[i].firstname[j];
			else
			{
				std::cout << ".";
				break;
			}
			size++;
			j++;
		
		}
	}
	std::cout << "|";
}

void	PhoneBook::print_lastname(int i)
{
	int	j;
	int	size;

	j = 0;
	size = 0;
	if (ft_strlen(this->contact[i].lastname) < 10)
	{
		while (j <= ft_strlen(this->contact[i].lastname) - 1)
		{
			std::cout << this->contact[i].lastname[j];
			j++;
		}
		while (j <= 10)
		{
			std::cout << " ";
			j++;
		}
	}
	else
	{
		while (j <= 10)
		{
			if (size < 10 && this->contact[i].lastname[j] != '\0')
				std::cout << this->contact[i].lastname[j];
			else
			{
				std::cout << ".";
				break;
			}
			size++;
			j++;
		
		}
	}
	std::cout << "|";
}

void	PhoneBook::print_nickname(int i)
{
	int	j;
	int	size;

	j = 0;
	size = 0;
	if (ft_strlen(this->contact[i].nickname) < 10)
	{
		while (j <= ft_strlen(this->contact[i].nickname) - 1)
		{
			std::cout << this->contact[i].nickname[j];
			j++;
		}
		while (j <= 10)
		{
			std::cout << " ";
			j++;
		}
	}
	else
	{
		while (j <= 10)
		{
			if (size < 10 && this->contact[i].nickname[j] != '\0')
				std::cout << this->contact[i].nickname[j];
			else
			{
				std::cout << ".";
				break;
			}
			size++;
			j++;
		
		}
	}
	std::cout << "|" << std::endl;
}

int	PhoneBook::add(void)
{
	std::string tmp;


	if (this->idcontact == 8)
		this->idcontact = 0;
	std::cout << "" << std::endl;
	std::cout << "firstname : ";
	std::cin >> this->contact[idcontact].firstname;
	std::cout << "lastname : ";
	std::cin >> this->contact[idcontact].lastname;
	std::cout << "nickname : ";
	std::cin >> this->contact[idcontact].nickname;
	std::cout << "phone number : ";
	std::cin >> tmp;
	if (ft_strlen(tmp) <= 9)
		this->contact[idcontact].phonenumber = std::atoi(tmp);
	else
	{
		std::cout << "Wrong phonenumber " << std::endl;
		this->contact[idcontact].phonenumber = 0;
	} 
	std::cout << "darkest secret : ";
	std::cin >> this->contact[idcontact].darkestsecret;
	if (this->nbr < 8)
		this->nbr++;
	return (this->nbr);
}

void	PhoneBook::search(void)
{
	int	i;
	int	index;

	i = 0;
	while (i <= this->nbr - 1)
	{
		std::cout << "|";
		std::cout << i;
		print_firstname(i);
		print_lastname(i);
		print_nickname(i);
		i++;
	}
	std::cout << "Index ?";
	std::cin >> index;
	if (this->idcontact >= index)
	{
		std::cout << index << std::endl;
		std::cout << "Firstname :" << this->contact[index].firstname << std::endl;
		std::cout << "Lastname :" << this->contact[index].lastname << std::endl;
		std::cout << "Nickname :" << this->contact[index].nickname << std::endl;
		if (this->contact[index].phonenumber != 0)
			std::cout << "Phonenumber :+33" << this->contact[index].phonenumber << std::endl;
		else
			std::cout << "Phonenumber : incorrect number " << std::endl;
		std::cout << "Darkest secret :" <<this->contact[index].darkestsecret << std::endl;
	}
	else
	{
		std::cout << "there is no contact" << std::endl;
		return;
	}
}

int main(void)
{
	PhoneBook	repertoire;
	std::string str;
	repertoire.idcontact = 0;
	repertoire.nbr = 0;
	while (getline(std::cin, str))
	{
		if (str == "ADD")
		{
			repertoire.nbr = repertoire.add();
			repertoire.idcontact++;
		}
		else if (str == "EXIT")
			return (0);
		else if (str == "SEARCH")
			repertoire.search();
	}
}