/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamira <hsamira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 14:08:04 by hsamira           #+#    #+#             */
/*   Updated: 2026/03/12 15:43:34 by hsamira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() 
{
    std::cout << "Intern default constructor called" << std::endl;
}


Intern::Intern( const Intern& other)
{
    std::cout << "Intern copy constructor called" << std::endl;
    (void)other;
}
Intern& Intern::operator=( const Intern& other)
{
    std::cout << "Intern assignment operator called" << std::endl; 
    (void)other;
    return(*this);
}

Intern::~Intern()
{
    std::cout << "Intern destructor called" << std::endl;
}

AForm* Intern::makeForm(std::string name, std::string target)
{ 
    // un tableau de pointeurs sur AForm qui contient les noms de formulaires
    std::string forms[3] = {"shrubbery creation",
                            "robotomy request",
                            "presidential pardon"};
    
    //un tableau de fonctions qui créent les formulaires
    AForm* formsCreated[3] = { new ShrubberyCreationForm(target),
                               new RobotomyRequestForm(target),
                               new PresidentialPardonForm(target)};
    for(int i = 0; i < 3; i++)
    {
        //on cherche le bon index
        if(name == forms[i])
        {
            std::cout << "Intern creates " << forms[i] << std::endl;
            //delete les 2 autres fonctions
            for (int j = 0; j < 3; j++)
                if (j != i)
                    delete formsCreated[j];
            return formsCreated[i];
        }
    }
    std::cout << "Intern cannot create " << name << std::endl;

    for(int i = 0; i < 3; i++)
        delete formsCreated[i];

    return NULL;
}
