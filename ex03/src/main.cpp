/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkas <bkas@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 10:38:07 by bkas              #+#    #+#             */
/*   Updated: 2024/07/25 16:30:01 by bkas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"
#include "../inc/Intern.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"

int main() {
    {
        cout << LIGHT_CYAN
            "/* **************** [v] Ex03 [v] **************** */"
             << RESET << endl;

        /* **** [v] Variables [v] **** */
        Intern someRandomIntern;
        AForm *form;
        AForm *form3;
        AForm *form2;
        // AForm *form4;
        /* **** [^] Variables [^] **** */

        try {
            /* ************* [v] Shrubbery Creation Form [v] ************* */
            printInfos(BLUE, "Shrubbery Creation from Intern");
            form2 = someRandomIntern.makeForm("shrubbery creation", "Blade");
            cout << *form2 << endl;
            /* ************* [^] Shrubbery Creation Form [^] ************* */

            /* ************** [v] Robomoty Request Form [v] ************** */
            printInfos(GREEN, "Robotomy Request from Intern");
            form = someRandomIntern.makeForm("robotomy request", "Bender");
            cout << *form << endl;
            /* ************** [^] Robomoty Request Form [^] ************** */

            /* ************ [v] Presidential Pardon Form [v] ************ */
            printInfos(RED, "Presidential Pardon from Intern");
            form3 = someRandomIntern.makeForm("presidential pardon", "Batuhan");
            cout << *form3 << endl;
            /* ************ [^] Presidential Pardon Form [^] ************ */

            /* *************** [v] False Form Example [v] *************** */
            // printInfos(BLUE, "False Form Example");
            // form4 = someRandomIntern.makeForm("False Form", "False Target");
            /* *************** [^] False Form Example [^] *************** */

            /* **** [v] Delete Forms [v] **** */
            delete form;
            delete form2;
            delete form3;
            /* **** [^] Delete Forms [^] **** */
        } catch (exception &e) {
            cout << RED << e.what() << RESET << endl;
            delete form;
            delete form2;
            delete form3;
        }

        cout << endl
             << LIGHT_CYAN
            "/* **************** [^] Ex03 [^] **************** */"
             << RESET << endl;
    }
}
