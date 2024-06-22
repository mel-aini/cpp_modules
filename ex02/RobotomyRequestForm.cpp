#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

int	RobotomyRequestForm::time = 0;

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 45, 72), target("default") {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& P) {
	*this = P;
}

RobotomyRequestForm& RobotomyRequestForm::operator= (const RobotomyRequestForm& R) {
	if (this != &R) {
		this->target = R.getTarget();
		this->setIsSigned(R.getIsSigned());
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 45, 72), target(target) {}

const std::string& RobotomyRequestForm::getTarget() const {
	return this->target;
}

void	RobotomyRequestForm::executeFormAction() const {
	if (RobotomyRequestForm::time == 0) {
        std::cout << target << " has been robotomized successfully" << std::endl;
        RobotomyRequestForm::time++;
    } else {
        std::cout << "the robotomy failed" << std::endl;
        RobotomyRequestForm::time--;
    }
}