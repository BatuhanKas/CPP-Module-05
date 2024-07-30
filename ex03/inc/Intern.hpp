/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkas <bkas@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 10:38:09 by bkas              #+#    #+#             */
/*   Updated: 2024/07/30 10:03:25 by bkas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] DEFINES [v] **************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

/* **************************** [^] DEFINES [^] **************************** */

/* **************************** [v] INCLUDES [v] **************************** */

#include <iostream>

#include "AForm.hpp"

using std::string;

class AForm;

/* **************************** [^] INCLUDES [^] **************************** */

/* ************************** [v] INTERN CLASS [v] ************************** */

class Intern {
   public:
    /* ***** [v] Orthodox Form [v] ***** */
    Intern();
    Intern(const Intern &oth);
    Intern &operator=(const Intern &oth);
    ~Intern();
    /* ***** [^] Orthodox Form [^] ***** */

    /* ********* [v] Form Functions [v] ********* */
    AForm *makeForm(string formName, string target);
    /* ********* [^] Form Functions [^] ********* */

    /* ****** [v] False Form Name Class [v] ****** */
    class FalseFormName : public exception {
        virtual const char *what() const throw();
    };
    /* ****** [^] False Form Name Class [^] ****** */
};

/* ************************** [^] INTERN CLASS [^] ************************** */

#endif
