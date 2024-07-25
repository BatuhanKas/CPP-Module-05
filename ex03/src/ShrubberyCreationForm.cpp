/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkas <bkas@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 13:52:27 by bkas              #+#    #+#             */
/*   Updated: 2024/07/23 10:09:19 by bkas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */

#include "../inc/ShrubberyCreationForm.hpp"

/* **************************** [^] INCLUDES [^] **************************** */

/* ************************* [v] ORTHODOX FORM [v] ************************* */

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("Default Form", 145, 137) {
    setTarget("Default Target");
}

ShrubberyCreationForm::ShrubberyCreationForm(const string _target)
    : AForm("Shrubbery Form", 145, 137) {
    setTarget(_target);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &oth) {
    *this = oth;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(
    const ShrubberyCreationForm &oth) {
    if (this == &oth) return *this;
    AForm::operator=(oth);
    setTarget(oth.getTarget());
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

/* ************************* [^] ORTHODOX FORM [^] ************************* */

/* ************************ [v] SET & GET TARGET [v] ************************ */

void ShrubberyCreationForm::setTarget(const string _target) {
    const_cast<string &>(target) = _target;
}

string ShrubberyCreationForm::getTarget() const { return target; }

/* ************************ [^] SET & GET TARGET [^] ************************ */

/* **************************** [v] EXECUTOR [v] **************************** */

void ShrubberyCreationForm::execute(Bureaucrat const &executor) {
    if (executor.getGrade() <= this->getExecGrade()) {
        if (this->getSign() == true) {
            cout << LIGHT_YELLOW << executor.getName() << " executed "
                 << getName() << RESET << endl;
            drawAsciiTree();
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

/* ****************************** [v] TREE [v] ****************************** */

void ShrubberyCreationForm::tree(ofstream &of) {
    of << "   /\\  " << endl;
    of << "  /  \\ " << endl;
    of << " /____\\" << endl;
    of << "   ||   " << endl;
    of << "   ||   " << endl;
}

/* ****************************** [^] TREE [^] ****************************** */

/* ************************ [v] DRAW ASCII TREE [v] ************************ */

void ShrubberyCreationForm::drawAsciiTree() {
    string filename = getTarget() + "_shrubbery";
    ofstream outputfile(filename.c_str(), ofstream::trunc);
    if (!outputfile) {
        throw GradeTooLowException("Output File Error!");
    }
    tree(outputfile);
    outputfile.close();
}

/* ************************ [^] DRAW ASCII TREE [^] ************************ */
