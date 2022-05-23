/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegadri <adegadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 18:01:41 by adegadri          #+#    #+#             */
/*   Updated: 2022/05/23 20:42:05 by adegadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "phonebook.hpp"

void	PhoneBook::print_firstname(int i)
{
	unsigned long	j;
	int	size;

	j = 0;
	size = 0;
	std::cout << "|";
	//std::cout << this->contact[i].getfirstname().size() << std::endl;
	if (this->contact[i].getfirstname().size() <= 10)
	{
		//std::cout << this->contact[i].getfirstname() << std::endl;
		while (j <= this->contact[i].getfirstname().size() - 1)
		{
			std::cout << this->contact[i].getfirstname()[j];//
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
			if (size < 10 && this->contact[i].getfirstname()[j] != '\0')
				std::cout << this->contact[i].getfirstname()[j];
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
	unsigned long	j;
	int	size;

	j = 0;
	size = 0;
	if (this->contact[i].getlastname().size() < 10)
	{
		while (j <= this->contact[i].getlastname().size() - 1)
		{
			std::cout << this->contact[i].getlastname()[j];
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
			if (size < 10 && this->contact[i].getlastname()[j] != '\0')
				std::cout << this->contact[i].getlastname()[j];
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
	unsigned long	j;
	int	size;

	j = 0;
	size = 0;
	if (this->contact[i].getnickname().size() < 10)
	{
		while (j <= this->contact[i].getnickname().size() - 1)
		{
			std::cout << this->contact[i].getnickname()[j];
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
			if (size < 10 && this->contact[i].getnickname()[j] != '\0')
				std::cout << this->contact[i].getnickname()[j];
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
	std::string str;

	if (this->idcontact == 8)
		this->idcontact = 0;
	std::cout << "" << std::endl;
	std::cout << "firstname : ";
	std::cin >> str;
	this->contact[idcontact].Set_firstname(str);
	std::cout << "lastname : ";
	std::cin >> str;
	this->contact[idcontact].Set_lastname(str);
	std::cout << "nickname : ";
	std::cin >> str;
	this->contact[idcontact].Set_nickname(str);
	while (1)
	{	
		std::cout << "phone number : ";
		std::cin >> tmp;
		this->contact[idcontact].Set_number(std::atoi(tmp.c_str()));
		if (this->contact[idcontact].getnumber() != 0 && tmp.size() < 9)
			break;
		else
		{
			std::cout << "Wrong phonenumber " << std::endl;
			this->contact[idcontact].Set_number(0);
		}
	}
	std::cout << "darkest secret : ";
	std::cin >> str;
	this->contact[idcontact].Set_darksecret(str);
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
		std::cout << "Firstname :" << this->contact[index].getfirstname() << std::endl;
		std::cout << "Lastname :" << this->contact[index].getlastname() << std::endl;
		std::cout << "Nickname :" << this->contact[index].getnickname() << std::endl;
		if (this->contact[index].getnumber() != 0)
			std::cout << "Phonenumber :+33" << this->contact[index].getnumber() << std::endl;
		else
			std::cout << "Phonenumber : incorrect number " << std::endl;
		std::cout << "Darkest secret :" << this->contact[index].getdarksecret() << std::endl;
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