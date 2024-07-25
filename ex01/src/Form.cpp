/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkas <bkas@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 14:06:35 by bkas              #+#    #+#             */
/*   Updated: 2024/07/20 11:46:12 by bkas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */

#include "../inc/Form.hpp"

/* **************************** [^] INCLUDES [^] **************************** */

/* ************************* [v] ORTHODOX FORM [v] ************************* */

Form::Form() : name("None"), sign(false), signGrade(MIN), execGrade(MIN) {}

Form::Form(string _name)
    : name(_name), sign(false), signGrade(MIN), execGrade(MIN) {}

Form::Form(string _name, int _grade, int _execGrade)
    : name(_name), sign(false), signGrade(_grade), execGrade(_execGrade) {
    if (getSignGrade() < MAX || getExecGrade() < MAX)
        throw GradeTooHighException("Grade is too high (Form)");
    else if (getSignGrade() > MIN || getExecGrade() > MIN)
        throw GradeTooLowException("Grade is too low (Form)");
}

Form::Form(const Form &oth)
    : name(oth.name),
      sign(oth.sign),
      signGrade(oth.signGrade),
      execGrade(oth.execGrade) {
    *this = oth;
}

Form &Form::operator=(const Form &oth) {
    if (this == &oth) return *this;
    setName(oth.getName());
    setSign(oth.getSign());
    setSignGrade(oth.getSignGrade());
    setExecGrade(oth.getExecGrade());
    return *this;
}

Form::~Form() {}

/* ************************* [^] ORTHODOX FORM [^] ************************* */

/* ********************** [v] SET & GET FUNCTIONS [v] ********************** */

void Form::setName(const string _name) { const_cast<string &>(name) = _name; }
void Form::setSign(const bool _sign) { const_cast<bool &>(sign) = _sign; }
void Form::setSignGrade(const int _grade) {
    if (_grade > MIN)
        throw GradeTooLowException("Grade is too low (Form)");
    else if (_grade < MAX)
        throw GradeTooHighException("Grade is too high (Form)");
    const_cast<int &>(signGrade) = _grade;
}
void Form::setExecGrade(const int _grade) {
    if (_grade > MIN)
        throw GradeTooLowException("Grade is too low (Form)");
    else if (_grade < MAX)
        throw GradeTooHighException("Grade is too high (Form)");
    const_cast<int &>(execGrade) = _grade;
}

string Form::getName() const { return name; }
bool Form::getSign() const { return sign; }
int Form::getSignGrade() const { return signGrade; }
int Form::getExecGrade() const { return execGrade; }

/* ********************** [^] SET & GET FUNCTIONS [^] ********************** */

/* ************************* [v] GRADE TOO HIGH [v] ************************* */

Form::GradeTooHighException::GradeTooHighException(string msg) : message(msg) {}
Form::GradeTooHighException::~GradeTooHighException() throw() {}

const char *Form::GradeTooHighException::what() const throw() {
    return this->message.c_str();
}

/* ************************* [^] GRADE TOO HIGH [^] ************************* */

/* ************************* [v] GRADE TOO LOW [v] ************************* */

Form::GradeTooLowException::GradeTooLowException(string msg) : message(msg) {}
Form::GradeTooLowException::~GradeTooLowException() throw() {}

const char *Form::GradeTooLowException::what() const throw() {
    return this->message.c_str();
}

/* ************************* [^] GRADE TOO LOW [^] ************************* */

/* ************************ [v] STREAM OPERATOR [v] ************************ */

ostream &operator<<(ostream &o, const Form &oth) {
    o << WHITE << "/* ********* [v] Form Informations [v] ********* */" << RESET
      << endl;
    o << MAGENTA << "Form Name: " << RESET << LIGHT_WHITE << oth.getName()
      << RESET << MAGENTA << " | Form is Signed?: " << GREEN
      << (oth.getSign() ? "Yes" : "No") << RESET << endl;
    o << MAGENTA << "Grade to Sign it: " << RESET << BLUE << oth.getSignGrade()
      << RESET << endl;
    o << MAGENTA << "Grade to Execute it: " << RESET << BLUE
      << oth.getExecGrade() << RESET << endl;
    o << WHITE << "/* ********* [^] Form Informations [^] ********* */"
      << RESET;
    return o;
}

/* ************************ [^] STREAM OPERATOR [^] ************************ */

/* *************************** [v] BE SIGNED [v] *************************** */

void Form::beSigned(const Bureaucrat &oth) {
    if (oth.getGrade() <= this->getSignGrade()) {
        setSign(true);
        cout << BLUE << oth.getName() << " signed " << getName() << RESET
             << endl;
    } else {
        cout << BLUE << oth.getName() << " couldn't sign " << getName()
             << " because " << RESET;
        throw GradeTooLowException("Grade is too low");
    }
}

/* *************************** [^] BE SIGNED [^] *************************** */
