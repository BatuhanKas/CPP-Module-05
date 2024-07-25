/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkas <bkas@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 10:38:08 by bkas              #+#    #+#             */
/*   Updated: 2024/07/22 13:50:33 by bkas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */

#include "../inc/Bureaucrat.hpp"

/* **************************** [^] INCLUDES [^] **************************** */

/* ************************* [v] ORTHODOX FORM [v] ************************* */

Bureaucrat::Bureaucrat() : name("None"), grade(150) {}
Bureaucrat::Bureaucrat(string _name, int _grade) : name(_name), grade(_grade) {}
Bureaucrat::Bureaucrat(const Bureaucrat &oth) { *this = oth; }
Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &oth) {
    if (this == &oth) return *this;
    setName(oth.getName());
    setGrade(oth.getGrade());
    return *this;
}

/* ************************* [^] ORTHODOX FORM [^] ************************* */

/* ********************** [v] GET & SET FUNCTIONS [v] ********************** */

string Bureaucrat::getName() const { return name; }
void Bureaucrat::setGrade(const int _grade) { grade = _grade; }
int Bureaucrat::getGrade() const { return grade; }

void Bureaucrat::setName(const string _name) {
    const_cast<string &>(name) = _name;
}

/* ********************** [^] GET & SET FUNCTIONS [^] ********************** */

/* ************************* [v] GRADE TOO HIGH [v] ************************* */

Bureaucrat::GradeTooHighException::GradeTooHighException(string msg)
    : message(msg) {}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return this->message.c_str();
}

/* ************************* [^] GRADE TOO HIGH [^] ************************* */

/* ************************* [v] GRADE TOO LOW [v] ************************* */

Bureaucrat::GradeTooLowException::GradeTooLowException(string msg)
    : message(msg) {}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return this->message.c_str();
}

/* ************************* [^] GRADE TOO LOW [^] ************************* */

/* ******************* [v] INCREASE & DECREASE GRADE [v] ******************* */

void Bureaucrat::increaseGrade() {
    if (grade > MAX) {
        this->grade--;
        return;
    }
    throw GradeTooHighException("Grade is too high (Bureaucrat)");
}

void Bureaucrat::decreaseGrade() {
    if (grade < MIN) {
        this->grade++;
        return;
    }
    throw GradeTooLowException("Grade is too low (Bureaucrat)");
}

void Bureaucrat::increaseGrade(int value) {
    if (grade - value > MAX) {
        setGrade(grade - value);
        return;
    }
    throw GradeTooHighException("Grade is too high (Bureaucrat)");
}

void Bureaucrat::decreaseGrade(int value) {
    if (grade + value < MIN) {
        setGrade(grade + value);
        return;
    }
    throw GradeTooLowException("Grade is too low (Bureaucrat)");
}

/* ******************* [^] INCREASE & DECREASE GRADE [^] ******************* */

/* ************************* [v] FORM FUCTIONS [v] ************************* */

void Bureaucrat::signForm(AForm &form) { form.beSigned(*this); }
void Bureaucrat::executeForm(AForm const &form) {
    const_cast<AForm &>(form).execute(*this);
}

/* ************************* [^] FORM FUCTIONS [^] ************************* */

/* ************************ [v] STREAM OPERATOR [v] ************************ */

ostream &operator<<(ostream &o, const Bureaucrat &oth) {
    o << oth.getName() << ", bureaucrat grade " << oth.getGrade() << ".";
    return o;
}

/* ************************ [^] STREAM OPERATOR [^] ************************ */
