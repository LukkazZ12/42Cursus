#include "ASpell.hpp"

ASpell::ASpell(const std::string &name, const std::string &effects)
{
	this->name = name;
	this->effects = effects;
	return ;
};

ASpell::ASpell(const ASpell &spell)
{
	*this = spell;
	return ;
}

ASpell &ASpell::operator=(const ASpell &spell)
{
	if (this != &spell)
	{
		this->name = spell.name;
		this->effects = spell.effects;
	}
	return (*this);
};

ASpell::~ASpell(void)
{
	return ;
};

std::string	ASpell::getName(void) const
{
	return (this->name);
};

std::string	ASpell::getEffects(void) const
{
	return (this->effects);
};

void	ASpell::launch(const ATarget &target) const
{
	target.getHitBySpell(*this);
};
