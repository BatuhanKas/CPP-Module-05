/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkas <bkas@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 10:38:07 by bkas              #+#    #+#             */
/*   Updated: 2024/07/30 18:37:08 by bkas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"

int main() {
    {
        /* **************** [v] Shrubbery Creation Form [v] **************** */
        cout << RED "/* ******** [v] Shrubbery Creation Form [v] ******** */"
             << RESET << endl;

        /* **** [v] Objects [v] **** */
        Bureaucrat b1("Ali", 130);
        ShrubberyCreationForm scf("Shrubbery");
        /* **** [^] Objects [^] **** */

        /* ****** [v] Status [v] ****** */
        printInfos(GREEN, "Status");
        cout << b1 << endl;
        printInfos(GREEN, "Form");
        cout << scf << endl;
        /* ****** [^] Status [^] ****** */

        /* **** [v] Sign the Form [v] **** */
        try {
            printInfos(LIGHT_YELLOW, "Sign");
            b1.signForm(scf);
        } catch (const exception &e) {
            cerr << BLUE << e.what() << RESET << endl;
        }
        /* **** [^] Sign the Form [^] **** */

        /* ****** [v] Status [v] ****** */
        printInfos(GREEN, "Status");
        cout << scf << endl;
        /* ****** [^] Status [^] ****** */

        /* **** [v] Execute the Form [v] **** */
        try {
            printInfos(RED, "Execute");
            b1.executeForm(scf);
        } catch (const exception &e) {
            cerr << BLUE << e.what() << RESET << endl;
        }
        /* **** [^] Execute the Form [^] **** */

        cout << endl
             << RED << "/* ******** [^] Shrubbery Creation Form [^] ******** */"
             << RESET << endl;
        /* **************** [^] Shrubbery Creation Form [^] **************** */
    }

    clearInfos();

    {
        /* **************** [v] Robotomy Request Form [v] **************** */
        cout << RED "/* ********* [v] Robotomy Request Form [v] ********* */"
             << RESET << endl;

        /* ***** [v] Objects [v] ***** */
        Bureaucrat b2("Batuhan", 40);
        RobotomyRequestForm r1("F16");
        /* ***** [^] Objects [^] ***** */

        /* ****** [v] Status [v] ****** */
        printInfos(GREEN, "Status");
        cout << b2 << endl;
        printInfos(GREEN, "Form");
        cout << r1 << endl;
        /* ****** [^] Status [^] ****** */

        /* ***** [v] Sign the Form [v] ***** */
        try {
            printInfos(LIGHT_YELLOW, "Sign");
            b2.signForm(r1);
        } catch (exception &e) {
            cerr << BLUE << e.what() << RESET << endl;
        }
        /* ***** [^] Sign the Form [^] ***** */

        /* **** [v] Execute the Form [v] **** */
        try {
            for (size_t i = 0; i < 4; i++) {
                printInfos(RED, "Execute");
                b2.executeForm(r1);
                std::system("sleep 0.5");
            }
        } catch (exception &e) {
            cerr << BLUE << e.what() << RESET << endl;
        }
        /* **** [^] Execute the Form [^] **** */

        printInfos(GREEN, "Form");
        cout << r1 << endl;

        cout << endl
             << RED "/* ********* [^] Robotomy Request Form [^] ********* */"
             << RESET << endl;
        /* **************** [^] Robotomy Request Form [^] **************** */
    }

    clearInfos();

    {
        /* ************** [v] Presidential Pardon Form [v] ************** */
        cout << RED "/* ******* [v] Presidential Pardon Form [v] ******* */"
             << RESET << endl;

        /* ***** [v] Objects [v] ***** */
        PresidentialPardonForm pf1("P1");
        Bureaucrat b3("Atalay", 3);
        /* ***** [^] Objects [^] ***** */

        /* ***** [v] Status [v] ***** */
        printInfos(GREEN, "Status");
        cout << b3 << endl;
        printInfos(GREEN, "Form");
        cout << pf1 << endl;
        /* ***** [^] Status [^] ***** */

        /* ***** [v] Sign the Form [v] ***** */
        try {
            printInfos(LIGHT_YELLOW, "Sign");
            b3.signForm(pf1);
        } catch (exception &e) {
            cerr << BLUE << e.what() << RESET << endl;
        }
        /* ***** [^] Sign the Form [^] ***** */

        /* ***** [v] Status [v] ***** */
        printInfos(GREEN, "Form");
        cout << pf1 << endl;
        /* ***** [^] Status [^] ***** */

        /* **** [v] Execute the Form [v] **** */
        try {
            printInfos(RED, "Execute");
            b3.executeForm(pf1);
        } catch (exception &e) {
            cerr << BLUE << e.what() << RESET << endl;
        }
        /* **** [^] Execute the Form [^] **** */

        cout << endl
             << RED "/* ******* [^] Presidential Pardon Form [^] ******* */"
             << RESET << endl;
        /* ************** [v] Presidential Pardon Form [v] ************** */
    }
}
