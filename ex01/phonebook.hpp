# ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "contact.hpp"

class PhoneBook {

	public:	
		int	idcontact;
		int	nbr;
		Contact	contact[8];
		int		add(void);
		void	search(void);
		void	print_firstname(int i);
		void	print_lastname(int i);
		void	print_nickname(int i);	
};

#endif