#include "Dummy.hpp"

Dummy::Dummy(void) : ATarget("Target Practice Dummy")
{
	return ;
};

Dummy::~Dummy(void)
{
	return ;
};

ATarget *Dummy::clone(void) const
{
	return (new Dummy());
};
