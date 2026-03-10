/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamira <hsamira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 12:35:10 by hsamira           #+#    #+#             */
/*   Updated: 2026/02/24 12:35:11 by hsamira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Form_HPP
#define Form_HPP

#include <string>
#include <iostream>
#include <exception>
//#include "Bureaucrat.hpp"
class Bureaucrat;

class Form
{
    private:
        const std::string _name;
        bool _signed;
        const int _gradeSign;//grade nécessaire pour signer le formulaire
        const int _gradeExec;//grade nécessaire pour exécuter le formulaire
      
    public:
        Form();
        Form(std::string name, int gradeSign, int gradeExec);
        Form(const Form& other);
        Form& operator=( const Form& other);
        ~Form();
        std::string getName() const;
        bool getSigned() const;
        int getGradeExec() const;
        int getGradeSign() const;
        void beSigned(const Bureaucrat& bureaucrat);
        
        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw();
        };
};

std::ostream&   operator<<(std::ostream &o, Form const &other);

#endif