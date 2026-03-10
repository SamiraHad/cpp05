/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    ShrubberyCreationForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamira <hsamira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 12:40:51 by hsamira           #+#    #+#             */
/*   Updated: 2026/02/24 12:40:52 by hsamira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <string>
#include <iostream>
#include <exception>
#include <fstream>
#include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
    private:
        std::string _target;
        
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ShrubberyCreationForm& operator=( const ShrubberyCreationForm& other);
        ~ShrubberyCreationForm();
        void execute(Bureaucrat const & executor) const;
};

#endif