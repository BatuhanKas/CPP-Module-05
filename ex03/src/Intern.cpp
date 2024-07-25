/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkas <bkas@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 10:38:08 by bkas              #+#    #+#             */
/*   Updated: 2024/07/25 16:33:34 by bkas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */

#include "../inc/Intern.hpp"

#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"

/* **************************** [^] INCLUDES [^] **************************** */

/* ************************* [v] ORTHODOX FORM [v] ************************* */

Intern::Intern() {}

Intern::Intern(const Intern &oth) { *this = oth; }

Intern &Intern::operator=(const Intern &oth) {
    if (this == &oth) return *this;
    return *this;
}

Intern::~Intern() {}

/* ************************* [^] ORTHODOX FORM [^] ************************* */

/* ************************ [v] WHAT ERROR MSG [v] ************************ */

const char *Intern::FalseFormName::what() const throw() {
    return "False Form Name!";
}

/* ************************ [^] WHAT ERROR MSG [^] ************************ */

/* ***************** [v] POINTER TO MEMBER FUNCTIONS [v] ***************** */

AForm *Intern::CreateShrubberyForm(string target) {
    return new ShrubberyCreationForm(target);
}

AForm *Intern::CreateRobotomyRequestForm(string target) {
    return new RobotomyRequestForm(target);
}

AForm *Intern::CreatePresidentialForm(string target) {
    return new PresidentialPardonForm(target);
}

/* ***************** [^] POINTER TO MEMBER FUNCTIONS [^] ***************** */

/* ************************* [v] FORM FUCTIONS [v] ************************* */

AForm *Intern::makeForm(string formName, string target) {
    string arr[3] = {"shrubbery creation", "robotomy request",
                     "presidential pardon"};

    size_t arrSize = sizeof(arr) / sizeof(arr[0]);

    size_t i = 0;
    while (i < arrSize && arr[i].compare(formName)) i++;

    AForm *(Intern::*ptr[])(string) = {
        &Intern::CreateShrubberyForm,
        &Intern::CreateRobotomyRequestForm,
        &Intern::CreatePresidentialForm,
    };

    switch (i) {
        case 0:
            cout << LIGHT_YELLOW << "Intern Creates " << arr[0] << " form"
                 << endl;
            return (this->*ptr[0])(target);
        case 1:
            cout << LIGHT_YELLOW << "Intern Creates " << arr[1] << " form"
                 << endl;
            return (this->*ptr[1])(target);
        case 2:
            cout << LIGHT_YELLOW << "Intern Creates " << arr[2] << " form"
                 << endl;
            return (this->*ptr[2])(target);
        default:
            throw FalseFormName();
    }
}

/* ************************* [^] FORM FUCTIONS [^] ************************* */
