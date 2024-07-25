/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkas <bkas@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 10:38:07 by bkas              #+#    #+#             */
/*   Updated: 2024/07/25 15:41:42 by bkas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"

int main() {
    cout << LIGHT_CYAN
        "/* ****************** [v] Ex01 [v] ****************** */"
         << RESET << endl;
    /* **** [v] Form Informations [v] **** */
    try {
        Form f1("Batu", 15, 15);
        Bureaucrat b1("Ali", 20);
        cout << b1 << endl;
        cout << f1 << endl;
        // b1.signForm(f1);
        b1.increaseGrade(10);
        cout << b1 << endl;
        b1.signForm(f1);
    } catch (const exception &e) {
        cout << BLUE << e.what() << RESET << endl;
    }
    /* **** [^] Form Informations [^] **** */
    cout << LIGHT_CYAN
        "/* ****************** [^] Ex01 [^] ****************** */"
         << RESET << endl;
}
