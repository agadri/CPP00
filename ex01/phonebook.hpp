# ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "contact.hpp"

int	ft_strlen(char *str);

class PhoneBook {

	public:	
		
		int	nbr;
		Contact contact[8];
		int		add(void);
		void	search(void);
		void	print_firstname(int i);
		void	print_lastname(int i);
		void	print_nickname(int i);
	private:
		int	idcontact;
};

#endif