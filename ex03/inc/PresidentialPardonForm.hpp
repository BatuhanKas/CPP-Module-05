/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkas <bkas@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 13:45:00 by bkas              #+#    #+#             */
/*   Updated: 2024/07/25 14:09:54 by bkas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] DEFINES [v] **************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

/* **************************** [^] DEFINES [^] **************************** */

/* **************************** [v] INCLUDES [v] **************************** */

#include "Bureaucrat.hpp"

/* **************************** [^] INCLUDES [^] **************************** */

/* ************************ [v] SHRUBBERY CLASS [v] ************************ */

class PresidentialPardonForm : public AForm {
   private:
    /* **** [v] Private Values [v] **** */
    const string target;
    PresidentialPardonForm();
    /* **** [^] Private Values [^] **** */

   public:
    /* ****** [v] Orthodox Form [v] ****** */
    PresidentialPardonForm(const string _target);
    PresidentialPardonForm(const PresidentialPardonForm &oth);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &oth);
    ~PresidentialPardonForm();
    /* ****** [^] Orthodox Form [^] ****** */

    /* ***** [v] Set & Get Target [v] ***** */
    void setTarget(const string _target);
    string getTarget() const;
    /* ***** [^] Set & Get Target [^] ***** */

    /* ****** [v] Executor [v] ****** */
    void execute(Bureaucrat const &executor);
    /* ****** [^] Executor [^] ****** */

    /* ***** [v] Robotomize [v] ***** */
    void pardonTarget();
    /* ***** [^] Robotomize [^] ***** */
};

/* ************************ [^] SHRUBBERY CLASS [^] ************************ */

#endif
