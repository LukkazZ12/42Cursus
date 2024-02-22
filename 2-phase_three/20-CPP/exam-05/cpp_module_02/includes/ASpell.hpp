#pragma once
#include <iostream>
#include "ATarget.hpp"

class ATarget;

class ASpell
{
	private:
		std::string		name;
		std::string		effects;
	public:
		ASpell(const std::string &name, const std::string &effects);
		ASpell(const ASpell &spell);
		ASpell &operator=(const ASpell &spell);
		virtual ~ASpell(void);
		std::string		getName(void) const;
		std::string		getEffects(void) const;
		virtual ASpell	*clone(void) const = 0;
		void			launch(const ATarget &target) const;
};