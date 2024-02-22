#pragma once
#include <iostream>

class Warlock
{
	private:
		std::string			name;
		std::string			title;
		Warlock(void);
		Warlock(const Warlock &warlock);
		Warlock &operator=(const Warlock &warlock);
	public:
		Warlock(const std::string &name, const std::string &title);
		~Warlock(void);
		const std::string	&getName(void) const;
		const std::string	&getTitle(void) const;
		void				setTitle(const std::string &title);
		void				introduce(void) const;
};