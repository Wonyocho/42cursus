#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string>

class Harl
{
	public:
		Harl(void);
		~Harl(void);

		void complain(std::string level);

	private:
		void Debug();
		void Info();
		void Warning();
		void Error();
};

#endif
