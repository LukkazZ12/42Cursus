#include "BrickWall.hpp"

BrickWall::BrickWall(void) : ATarget("Inconspicuous Red-brick Wall")
{
	return ;
};

BrickWall::~BrickWall(void)
{
	return ;
};

ATarget *BrickWall::clone(void) const
{
	return (new BrickWall());
};
