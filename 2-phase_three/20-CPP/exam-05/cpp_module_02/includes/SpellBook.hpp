#pragma once
#include <map>
#include "ASpell.hpp"

class SpellBook
{
	private:
		std::map <std::string, ASpell*>	spellBook;
		SpellBook(const SpellBook &spellBook);
		SpellBook &operator=(const SpellBook &spellBook);
	public:
		SpellBook(void);
		~SpellBook(void);
		void	learnSpell(ASpell *spell);
		void	forgetSpell(const std::string &spellName);
		ASpell	*createSpell(const std::string &spell);
};