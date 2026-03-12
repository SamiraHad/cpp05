/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamira <hsamira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 12:40:58 by hsamira           #+#    #+#             */
/*   Updated: 2026/02/24 12:40:59 by hsamira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <exception>
class Bureaucrat;

class AForm
{
    private:
        const std::string _name;
        bool _signed;
        const int _gradeSign;//grade nécessaire pour signer le Aformulaire
        const int _gradeExec;//grade nécessaire pour exécuter le Aformulaire
      
    public:
        AForm();
        AForm(std::string name, int gradeSign, int gradeExec);
        AForm(const AForm& other);
        AForm& operator=( const AForm& other);
        virtual ~AForm();
        std::string getName() const;
        bool getSigned() const;
        int getGradeExec() const;
        int getGradeSign() const;
        void beSigned(const Bureaucrat& bureaucrat);
        virtual void execute(Bureaucrat const & executor) const = 0;
        
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
        class  FormNotSignedException : public std::exception
        {
            public:
                const char* what() const throw();
        };
};

std::ostream&   operator<<(std::ostream &o, AForm const &other);

#endif