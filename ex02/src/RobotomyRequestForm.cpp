/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkas <bkas@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 13:52:27 by bkas              #+#    #+#             */
/*   Updated: 2024/07/30 17:54:09 by bkas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */

#include "../inc/RobotomyRequestForm.hpp"

/* **************************** [^] INCLUDES [^] **************************** */

/* ************************* [v] ORTHODOX FORM [v] ************************* */

RobotomyRequestForm::RobotomyRequestForm() : AForm("Default Form", 72, 45) {
    setTarget("Default Target");
}

RobotomyRequestForm::RobotomyRequestForm(const string _target)
    : AForm("Robotomy Form", 72, 45) {
    setTarget(_target);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &oth) {
    *this = oth;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(
    const RobotomyRequestForm &oth) {
    if (this == &oth) return *this;
    AForm::operator=(oth);
    setTarget(oth.getTarget());
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

/* ************************* [^] ORTHODOX FORM [^] ************************* */

/* ************************ [v] SET & GET TARGET [v] ************************ */

string RobotomyRequestForm::getTarget() const { return target; }
void RobotomyRequestForm::setTarget(const string _target) {
    const_cast<string &>(target) = _target;
}

/* ************************ [^] SET & GET TARGET [^] ************************ */

/* **************************** [v] EXECUTOR [v] **************************** */

void RobotomyRequestForm::execute(Bureaucrat const &executor) {
    if (executor.getGrade() <= this->getExecGrade()) {
        if (this->getSign() == true) {
            cout << LIGHT_YELLOW << executor.getName() << " executed "
                 << getName() << RESET << endl;
            robotomizeTarget();
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

void RobotomyRequestForm::robotomizeTarget() {
    cout << "--> * making some drilling noises * <--" << endl;
    srand(time(0));
    if (rand() % 2 == 0) {
        cout << GREEN << getTarget() << " has been Robotomized Succesfully."
             << RESET << endl;
    } else {
        cout << RED << getTarget() << " Robotomized Failed." << RESET << endl;
    }
}

/* *********************** [^] ROBOTOMIZE TARGET [^] *********************** */
