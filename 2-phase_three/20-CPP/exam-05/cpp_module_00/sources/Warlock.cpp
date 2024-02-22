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
