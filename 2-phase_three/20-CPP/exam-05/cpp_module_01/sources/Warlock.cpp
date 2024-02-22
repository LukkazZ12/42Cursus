#include "Warlock.hpp"

Warlock::Warlock(void)
{
	this->name = "Default";
	this->title = "Default";
	return ;
};

Warlock::Warlock(const std::string &name, const std::string &title)
{
	this->name = name;
	this->title = title;
	std::cout << this->name << ": This looks like another boring day.\n";
	return ;
};

Warlock::Warlock(const Warlock &warlock)
{
	*this = warlock;
	return ;
}

Warlock &Warlock::operator=(const Warlock &warlock)
{
	if (this != &warlock)
	{
		this->name = warlock.name;
		this->title = warlock.title;
	}
	return (*this);
};

Warlock::~Warlock(void)
{
	for (std::map<std::string, ASpell*>::iterator it = this->spellBook.begin(); it != this->spellBook.end(); ++it)
		delete (it->second);
	this->spellBook.clear();
	std::cout << this->name << ": My job here is done!\n";
	return ;
};

const std::string	&Warlock::getName(void) const
{
	return (this->name);
};

const std::string	&Warlock::getTitle(void) const
{
	return (this->title);
};

void	Warlock::setTitle(const std::string &title)
{
	this->title = title;
	return ;
};

void	Warlock::introduce(void) const
{
	std::cout << this->name << ": I am " << this->name << ", " << this->title << "!\n";
	return ;
};

void	Warlock::learnSpell(ASpell *spell)
{
	if (spell)
	{
		if (this->spellBook.find(spell->getName()) == this->spellBook.end())
			this->spellBook[spell->getName()] = spell->clone();
	}
};

void	Warlock::forgetSpell(std::string spellName)
{
	if (this->spellBook.find(spellName) != this->spellBook.end())
	{
		delete (this->spellBook[spellName]);
		this->spellBook.erase(this->spellBook.find(spellName));
	}
};

void	Warlock::launchSpell(std::string spellName, const ATarget &target)
{
	if (this->spellBook.find(spellName) != this->spellBook.end())
		this->spellBook[spellName]->launch(target);
};
