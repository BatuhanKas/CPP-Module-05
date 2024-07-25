/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkas <bkas@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 10:38:07 by bkas              #+#    #+#             */
/*   Updated: 2024/07/25 15:40:07 by bkas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

int main() {
    /* **** [v] Grade Too High [v] **** */
    cout << LIGHT_CYAN
        "/* ****************** [v] Ex00 [v] ****************** */"
         << RESET << endl;
    try {
        Bureaucrat b1("Batu", 2);
        cout << b1 << endl;
        b1.increaseGrade();
        cout << b1 << endl;
        b1.increaseGrade();
    } catch (const Bureaucrat::GradeTooHighException& e) {
        cerr << GREEN << e.what() << RESET << endl;
    }
    /* **** [^] Grade Too High [^] **** */

    /* **** [v] Grade Too Low [v] **** */
    try {
        Bureaucrat b2("Melih", 149);
        cout << b2 << endl;
        b2.decreaseGrade();
        cout << b2 << endl;
        b2.decreaseGrade();
    } catch (const Bureaucrat::GradeTooLowException& e) {
        cerr << BLUE << e.what() << RESET << endl;
    }
    /* **** [^] Grade Too Low [^] **** */
    cout << LIGHT_CYAN
        "/* ****************** [^] Ex00 [^] ****************** */"
         << RESET << endl;
}
