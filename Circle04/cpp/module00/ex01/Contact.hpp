#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>
# include <string>

class Contact {
	private:
		std::string	firstname;
		std::string	lastname;
		std::string	nickname;
		std::string	phonenumber;
		std::string	darkestsecret;
	public:
		void		set_firstname(void);
		void		set_lastname(void);
		void		set_nickname(void);
		void		set_phonenumber(void);
		void		set_darkestsecret(void);
		std::string	get_firstname(void);
		std::string	get_lastname(void);
		std::string	get_nickname(void);
		std::string	get_phonenumber(void);
		std::string	get_darkestsecret(void);

		Contact(void);
		~Contact(void);
};

#endif