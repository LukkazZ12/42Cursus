#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(void)
{
	return ;
};

TargetGenerator::TargetGenerator(const TargetGenerator &target)
{
	*this = target;
	return ;
}

TargetGenerator &TargetGenerator::operator=(const TargetGenerator &target)
{
	if (this != &target)
		this->target = target.target;
	return (*this);
};

TargetGenerator::~TargetGenerator(void)
{
	for (std::map<std::string, ATarget*>::iterator it = this->target.begin(); it != this->target.end(); ++it)
		delete (it->second);
	this->target.clear();
	return ;
};

void	TargetGenerator::learnTargetType(ATarget *target)
{
	if (target)
	{
		if (this->target.find(target->getType()) == this->target.end())
			this->target[target->getType()] = target->clone();
	}
};

void	TargetGenerator::forgetTargetType(const std::string &type)
{
	if (this->target.find(type) != this->target.end())
	{
		delete (this->target[type]);
		this->target.erase(this->target.find(type));
	}
};

ATarget	*TargetGenerator::createTarget(const std::string &target)
{
	ATarget*	tmp = NULL;
	if (this->target.find(target) != this->target.end())
		tmp = this->target[target];
	return (tmp);
}
