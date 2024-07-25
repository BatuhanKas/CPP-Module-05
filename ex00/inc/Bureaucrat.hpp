/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkas <bkas@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 10:38:09 by bkas              #+#    #+#             */
/*   Updated: 2024/07/25 15:37:38 by bkas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] DEFINES [v] **************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#define MIN 150
#define MAX 1

#define YELLOW "\033[1;33m"
#define LIGHT_GREEN "\033[1;32m"
#define WHITE "\033[1;37m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define BLUE "\033[0;34m"
#define RESET "\033[0m"
#define LIGHT_CYAN "\033[1;36m"

/* **************************** [^] DEFINES [^] **************************** */

/* **************************** [v] INCLUDES [v] **************************** */

#include <iostream>

class GradeTooHighException;
class GradeTooLowException;

using std::cerr;
using std::cout;
using std::endl;
using std::exception;
using std::ostream;
using std::string;

/* **************************** [^] INCLUDES [^] **************************** */

/* ************************ [v] BUREAUCRAT CLASS [v] ************************ */

class Bureaucrat {
   private:
    const string name;
    int grade;

   public:
    /* ***** [v] Orthodox Form [v] ***** */
    Bureaucrat();
    Bureaucrat(string _name, int _grade);
    Bureaucrat(const Bureaucrat &oth);
    Bureaucrat &operator=(const Bureaucrat &oth);
    ~Bureaucrat();
    /* ***** [^] Orthodox Form [^] ***** */

    /* * [v] Increase & Decrease Grade [v] * */
    void increaseGrade() throw(GradeTooHighException);
    void decreaseGrade() throw(GradeTooLowException);
    /* * [^] Increase & Decrease Grade [^] * */

    /* **** [v] Get & Set Functions [v] **** */
    void setName(const string _name);
    string getName() const;
    void setGrade(const int _grade);
    int getGrade() const;
    /* **** [^] Get & Set Functions [^] **** */

    /* ***** [v] Grade Exceptions [v] ***** */
    class GradeTooHighException : public exception {
       private:
        string message;

       public:
        GradeTooHighException(string msg);
        ~GradeTooHighException() throw();
        virtual const char *what() const throw();
    };
    class GradeTooLowException : public exception {
       private:
        string message;

       public:
        GradeTooLowException(string msg);
        ~GradeTooLowException() throw();
        virtual const char *what() const throw();
    };
    /* ***** [^] Grade Exceptions [^] ***** */
};

/* ************ [v] Stream Operator [v] ************ */
ostream &operator<<(ostream &o, const Bureaucrat &oth);
/* ************ [^] Stream Operator [^] ************ */

/* ************************ [^] BUREAUCRAT CLASS [^] ************************ */

#endif
