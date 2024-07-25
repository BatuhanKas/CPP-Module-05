/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkas <bkas@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 13:45:00 by bkas              #+#    #+#             */
/*   Updated: 2024/07/22 13:52:40 by bkas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] DEFINES [v] **************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

/* **************************** [^] DEFINES [^] **************************** */

/* **************************** [v] INCLUDES [v] **************************** */

#include <fstream>

#include "Bureaucrat.hpp"

using std::ofstream;

/* **************************** [^] INCLUDES [^] **************************** */

/* ************************ [v] SHRUBBERY CLASS [v] ************************ */

class ShrubberyCreationForm : public AForm {
   private:
    /* **** [v] Private Values [v] **** */
    const string target;
    ShrubberyCreationForm();
    /* **** [^] Private Values [^] **** */

   public:
    /* ****** [v] Orthodox Form [v] ****** */
    ShrubberyCreationForm(const string _target);
    ShrubberyCreationForm(const ShrubberyCreationForm &oth);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &oth);
    ~ShrubberyCreationForm();
    /* ****** [^] Orthodox Form [^] ****** */

    /* ***** [v] Set & Get Target [v] ***** */
    void setTarget(const string _target);
    string getTarget() const;
    /* ***** [^] Set & Get Target [^] ***** */

    /* ****** [v] Executor [v] ****** */
    void execute(Bureaucrat const &executor);
    /* ****** [^] Executor [^] ****** */

    /* ***** [v] Ascii Tree [v] ***** */
    void tree(ofstream &of);
    void drawAsciiTree();
    /* ***** [^] Ascii Tree [^] ***** */
};

/* ************************ [^] SHRUBBERY CLASS [^] ************************ */

#endif
