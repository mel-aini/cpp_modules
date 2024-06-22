#pragma once

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	private:
		std::string target;

    public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& S);
		ShrubberyCreationForm& operator= (const ShrubberyCreationForm& S);
		~ShrubberyCreationForm();

		ShrubberyCreationForm(const std::string& target);
		const std::string& getTarget() const;
		void	executeFormAction() const;
};