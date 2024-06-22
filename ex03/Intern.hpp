#pragma once

# include "AForm.hpp"

class Intern
{
    public:
        Intern();
        Intern(const Intern& C);
        Intern& operator= (const Intern& C);
        ~Intern();

        AForm*  makeForm(std::string formName, std::string formTarget);

        AForm*  makeShrubbery(std::string formName, std::string formTarget);
        AForm*  makeRobotomy(std::string formName, std::string formTarget);
        AForm*  makePresidential(std::string formName, std::string formTarget);
};