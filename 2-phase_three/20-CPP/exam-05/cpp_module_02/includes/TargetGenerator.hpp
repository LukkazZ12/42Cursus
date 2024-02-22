#pragma once
#include <map>
#include "ATarget.hpp"

class TargetGenerator
{
	private:
		std::map <std::string, ATarget*>	target;
		TargetGenerator(const TargetGenerator &target);
		TargetGenerator &operator=(const TargetGenerator &target);
	public:
		TargetGenerator(void);
		~TargetGenerator(void);
		void	learnTargetType(ATarget *target);
		void	forgetTargetType(const std::string &target);
		ATarget	*createTarget(const std::string &target);
};