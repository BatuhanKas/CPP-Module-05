/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkas <bkas@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 14:06:35 by bkas              #+#    #+#             */
/*   Updated: 2024/07/22 19:30:54 by bkas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */

#include "../inc/AForm.hpp"

/* **************************** [^] INCLUDES [^] **************************** */

/* ************************* [v] ORTHODOX FORM [v] ************************* */

AForm::AForm() : name(""), sign(false), signGrade(MIN), execGrade(MIN) {}

AForm::AForm(string _name)
    : name(_name), sign(false), signGrade(MIN), execGrade(MIN) {}

AForm::AForm(string _name, int _grade, int _execGrade)
    : name(_name), sign(false), signGrade(_grade), execGrade(_execGrade) {
    if (getSignGrade() < MAX || getExecGrade() < MAX)
        throw GradeTooHighException("Grade is too high (AForm)");
    else if (getSignGrade() > MIN || getExecGrade() > MIN)
        throw GradeTooLowException("Grade is too low (AForm)");
}

AForm::AForm(const AForm &oth)
    : name(oth.name),
      sign(oth.sign),
      signGrade(oth.signGrade),
      execGrade(oth.execGrade) {
    *this = oth;
}

AForm &AForm::operator=(const AForm &oth) {
    if (this == &oth) return *this;
    setName(oth.getName());
    setSign(oth.getSign());
    setSignGrade(oth.getSignGrade());
    setExecGrade(oth.getExecGrade());
    return *this;
}

AForm::~AForm() {}

/* ************************* [^] ORTHODOX FORM [^] ************************* */

/* ********************** [v] SET & GET FUNCTIONS [v] ********************** */

void AForm::setName(const string _name) { const_cast<string &>(name) = _name; }
void AForm::setSign(const bool _sign) { const_cast<bool &>(sign) = _sign; }
void AForm::setSignGrade(const int _grade) {
    if (_grade > MIN)
        throw GradeTooLowException("Grade is too low (AForm)");
    else if (_grade < MAX)
        throw GradeTooHighException("Grade is too high (AForm)");
    const_cast<int &>(signGrade) = _grade;
}
void AForm::setExecGrade(const int _grade) {
    if (_grade > MIN)
        throw GradeTooLowException("Grade is too low (AForm)");
    else if (_grade < MAX)
        throw GradeTooHighException("Grade is too high (AForm)");
    const_cast<int &>(execGrade) = _grade;
}

string AForm::getName() const { return name; }
bool AForm::getSign() const { return sign; }
int AForm::getSignGrade() const { return signGrade; }
int AForm::getExecGrade() const { return execGrade; }

/* ********************** [^] SET & GET FUNCTIONS [^] ********************** */

/* ************************* [v] GRADE TOO HIGH [v] ************************* */

AForm::GradeTooHighException::GradeTooHighException(string msg)
    : message(msg) {}
AForm::GradeTooHighException::~GradeTooHighException() throw() {}

const char *AForm::GradeTooHighException::what() const throw() {
    return this->message.c_str();
}

/* ************************* [^] GRADE TOO HIGH [^] ************************* */

/* ************************* [v] GRADE TOO LOW [v] ************************* */

AForm::GradeTooLowException::GradeTooLowException(string msg) : message(msg) {}
AForm::GradeTooLowException::~GradeTooLowException() throw() {}

const char *AForm::GradeTooLowException::what() const throw() {
    return this->message.c_str();
}

/* ************************* [^] GRADE TOO LOW [^] ************************* */

/* ************************ [v] STREAM OPERATOR [v] ************************ */

ostream &operator<<(ostream &o, const AForm &oth) {
    o << LIGHT_WHITE << "/* ********* [v] Form Informations [v] ********* */" << RESET
      << endl;
    o << "Form Name: " << RESET << GREEN << oth.getName() << RESET
      << " | Form is Signed?: " << GREEN << (oth.getSign() ? "Yes" : "No")
      << RESET << endl;
    o << "Grade to Sign it: " << RESET << BLUE << oth.getSignGrade() << RESET
      << endl;
    o << "Grade to Execute it: " << RESET << BLUE << oth.getExecGrade() << RESET
      << endl;
    o << LIGHT_WHITE << "/* ********* [^] Form Informations [^] ********* */"
      << RESET;
    return o;
}

/* ************************ [^] STREAM OPERATOR [^] ************************ */

/* *************************** [v] BE SIGNED [v] *************************** */

void AForm::beSigned(const Bureaucrat &oth) {
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

/* *********************** [v] MY PRINT HELPERS [v] *********************** */

void clearInfos(void) {
    cout << endl << "press ENTER to continue" << endl;
    std::cin.ignore();
    cout << "\033c";
}

void printInfos(string color, string message) {
    cout << endl;
    cout << color << "[" << message << "] " << RESET;
    cout << endl;
}

/* *********************** [^] MY PRINT HELPERS [^] *********************** */
