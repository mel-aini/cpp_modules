#pragma once

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string target;
		static int	time;
	
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm& R);
		RobotomyRequestForm& operator= (const RobotomyRequestForm& R);
		~RobotomyRequestForm();

		RobotomyRequestForm(const std::string& target);
		const std::string& getTarget() const;
        void	executeFormAction() const;
};