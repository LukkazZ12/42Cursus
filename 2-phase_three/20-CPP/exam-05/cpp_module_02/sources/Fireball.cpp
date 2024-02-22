#include "Fireball.hpp"

Fireball::Fireball(void) : ASpell("Fireball", "burnt to a crisp")
{
	return ;
};

Fireball::~Fireball(void)
{
	return ;
};

ASpell *Fireball::clone(void) const
{
	return (new Fireball());
};
