# ifndef CONTACT_H
#define CONTACT_H

#include "phonebook.hpp"

class Contact{

	public:
		void	Set_firstname(std::string s);
		std::string getfirstname() const;
		void	Set_lastname(std::string s);
		std::string getlastname() const;
		void	Set_nickname(std::string s);
		std::string getnickname() const;
		void	Set_number(std::string s);
		std::string getnumber() const;
		void	Set_darksecret(std::string s);
		std::string getdarksecret() const;
	private:
		int		id;
		std::string	firstname;
		std::string	lastname;
		std::string	nickname;
		long	phonenumber;
		std::string	darkestsecret;
};

#endif