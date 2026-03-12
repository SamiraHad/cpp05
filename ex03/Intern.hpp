/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamira <hsamira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 14:08:08 by hsamira           #+#    #+#             */
/*   Updated: 2026/03/12 15:43:29 by hsamira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <iostream>
#include <exception>


class AForm; 

class Intern
{
    public:
        Intern();
        Intern(const Intern& other);
        Intern& operator=( const Intern& other);
        ~Intern();
        AForm* makeForm(std::string name, std::string target);
        
        class FormNotExistException : public std::exception
        {
            public:
                const char* what() const throw();
        };
};

#endif