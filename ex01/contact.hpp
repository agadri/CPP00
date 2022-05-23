# ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

class Contact{

	public:
		int		id;
		void	Set_firstname(std::string s);
		std::string getfirstname() const;
		void	Set_lastname(std::string s);
		std::string getlastname() const;
		void	Set_nickname(std::string s);
		std::string getnickname() const;
		void	Set_number(int s);
		long getnumber() const;
		void	Set_darksecret(std::string s);
		std::string getdarksecret() const;
	private:
		std::string	firstname;
		std::string	lastname;
		std::string	nickname;
		long	phonenumber;
		std::string	darkestsecret;
};

#endif