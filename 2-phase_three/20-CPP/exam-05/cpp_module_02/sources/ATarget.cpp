#include "ATarget.hpp"

ATarget::ATarget(const std::string &type)
{
	this->type = type;
	return ;
};

ATarget::ATarget(const ATarget &target)
{
	*this = target;
	return ;
}

ATarget &ATarget::operator=(const ATarget &target)
{
	if (this != &target)
		this->type = target.type;
	return (*this);
};

ATarget::~ATarget(void)
{
	return ;
};

const std::string	&ATarget::getType(void) const
{
	return (this->type);
};

void	ATarget::getHitBySpell(const ASpell &spell) const
{
	std::cout << this->type << " has been " << spell.getEffects() << "!\n";
};
