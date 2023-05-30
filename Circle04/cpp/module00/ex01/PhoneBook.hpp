#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact		arr[8];
		int			idx;
	public:
		void		add();
		void		search();
		void		wrong();
		void		print_info(int idx);

		PhoneBook(void);
		~PhoneBook(void);
};

#endif