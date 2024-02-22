#pragma once
#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget
{
	private:
		std::string			type;
	public:
		ATarget(const std::string &type);
		ATarget(const ATarget &target);
		ATarget &operator=(const ATarget &target);
		virtual ~ATarget(void);
		const std::string	&getType(void) const;
		virtual ATarget		*clone(void) const = 0;
		void				getHitBySpell(const ASpell &spell) const;
};