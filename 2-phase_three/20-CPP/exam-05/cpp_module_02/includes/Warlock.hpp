#pragma once
#include <iostream>
#include <map>
#include "ASpell.hpp"
#include "SpellBook.hpp"

class Warlock
{
	private:
		std::string			name;
		std::string			title;
		SpellBook			spellBook;
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
		void				learnSpell(ASpell *spell);
		void				forgetSpell(std::string spellName);
		void				launchSpell(std::string spellName, const ATarget &target);
};