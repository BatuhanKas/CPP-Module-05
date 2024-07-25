/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkas <bkas@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 13:52:27 by bkas              #+#    #+#             */
/*   Updated: 2024/07/23 10:12:05 by bkas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */

#include "../inc/PresidentialPardonForm.hpp"

/* **************************** [^] INCLUDES [^] **************************** */

/* ************************* [v] ORTHODOX FORM [v] ************************* */

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("Default Form", 25, 5) {
    setTarget("Default Target");
}

PresidentialPardonForm::PresidentialPardonForm(const string _target)
    : AForm("Pardon Form", 25, 5) {
    setTarget(_target);
}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &oth) {
    *this = oth;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(
    const PresidentialPardonForm &oth) {
    if (this == &oth) return *this;
    AForm::operator=(oth);
    setTarget(oth.getTarget());
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

/* ************************* [^] ORTHODOX FORM [^] ************************* */

/* ************************ [v] SET & GET TARGET [v] ************************ */

string PresidentialPardonForm::getTarget() const { return target; }
void PresidentialPardonForm::setTarget(const string _target) {
    const_cast<string &>(target) = _target;
}

/* ************************ [^] SET & GET TARGET [^] ************************ */

/* **************************** [v] EXECUTOR [v] **************************** */

void PresidentialPardonForm::execute(Bureaucrat const &executor) {
    if (executor.getGrade() <= this->getExecGrade()) {
        if (this->getSign() == true) {
            cout << LIGHT_YELLOW << executor.getName() << " executed "
                 << getName() << RESET << endl;
            pardonTarget();
            return;
        }
        cout << RED << executor.getName() << " couldn't execute " << getName()
             << " because " << RESET;
        throw GradeTooLowException("Form is not signed!");
    }
    cout << LIGHT_YELLOW << executor.getName() << " couldn't execute "
         << getName() << " because " << RESET;
    throw GradeTooLowException("Grade is too low");
}

/* **************************** [^] EXECUTOR [^] **************************** */

/* *********************** [v] ROBOTOMIZE TARGET [v] *********************** */

void PresidentialPardonForm::pardonTarget() {
    cout << GREEN << getTarget() << " has been pardoned by Zaphod Beeblebrox."
         << RESET << endl;
}

/* *********************** [^] ROBOTOMIZE TARGET [^] *********************** */
