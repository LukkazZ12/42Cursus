#include "SpellBook.hpp"

SpellBook::SpellBook(void)
{
	return ;
};

SpellBook::SpellBook(const SpellBook &spellBook)
{
	*this = spellBook;
	return ;
}

SpellBook &SpellBook::operator=(const SpellBook &spellBook)
{
	if (this != &spellBook)
		this->spellBook = spellBook.spellBook;
	return (*this);
};

SpellBook::~SpellBook(void)
{
	for (std::map<std::string, ASpell*>::iterator it = this->spellBook.begin(); it != this->spellBook.end(); ++it)
		delete (it->second);
	this->spellBook.clear();
	return ;
};

void	SpellBook::learnSpell(ASpell *spell)
{
	if (spell)
	{
		if (this->spellBook.find(spell->getName()) == this->spellBook.end())
			this->spellBook[spell->getName()] = spell->clone();
	}
};

void	SpellBook::forgetSpell(const std::string &spellName)
{
	if (this->spellBook.find(spellName) != this->spellBook.end())
	{
		delete (this->spellBook[spellName]);
		this->spellBook.erase(this->spellBook.find(spellName));
	}
};

ASpell*	SpellBook::createSpell(std::string const &spellName)
{
	ASpell*	tmp = NULL;
	if (this->spellBook.find(spellName) != this->spellBook.end())
		tmp = this->spellBook[spellName];
	return (tmp);
}
