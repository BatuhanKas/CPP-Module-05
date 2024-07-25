/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkas <bkas@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 13:45:00 by bkas              #+#    #+#             */
/*   Updated: 2024/07/25 14:28:10 by bkas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] DEFINES [v] **************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

/* **************************** [^] DEFINES [^] **************************** */

/* **************************** [v] INCLUDES [v] **************************** */

#include "Bureaucrat.hpp"
using std::srand;
using std::time;

/* **************************** [^] INCLUDES [^] **************************** */

/* ************************ [v] SHRUBBERY CLASS [v] ************************ */

class RobotomyRequestForm : public AForm {
   private:
    /* **** [v] Private Values [v] **** */
    const string target;
    RobotomyRequestForm();
    /* **** [^] Private Values [^] **** */

   public:
    /* ****** [v] Orthodox Form [v] ****** */
    RobotomyRequestForm(const string _target);
    RobotomyRequestForm(const RobotomyRequestForm &oth);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &oth);
    ~RobotomyRequestForm();
    /* ****** [^] Orthodox Form [^] ****** */

    /* ***** [v] Set & Get Target [v] ***** */
    void setTarget(const string _target);
    string getTarget() const;
    /* ***** [^] Set & Get Target [^] ***** */

    /* ****** [v] Executor [v] ****** */
    void execute(Bureaucrat const &executor);
    /* ****** [^] Executor [^] ****** */

    /* ***** [v] Robotomize [v] ***** */
    void robotomizeTarget();
    /* ***** [^] Robotomize [^] ***** */
};

/* ************************ [^] SHRUBBERY CLASS [^] ************************ */

#endif
