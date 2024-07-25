/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkas <bkas@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 13:44:01 by bkas              #+#    #+#             */
/*   Updated: 2024/07/20 13:50:26 by bkas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] DEFINES [v] **************************** */

#ifndef FORM_HPP
#define FORM_HPP

#define MAX 1
#define MIN 150

/* ***************************** [^] DEFINES [^] **************************** */

/* **************************** [v] INCLUDES [v] **************************** */

#include <iostream>

#include "Bureaucrat.hpp"

class Bureaucrat;

using std::cerr;
using std::cout;
using std::endl;
using std::exception;
using std::ostream;
using std::string;

/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] FORM CLASS [v] *************************** */

class Form {
   private:
    /* **** [v] Values [v] **** */
    const string name;
    bool sign;
    const int signGrade;
    const int execGrade;
    /* **** [^] Values [^] **** */

   public:
    /* **** [v] Orthodox Form [v] **** */
    Form();
    Form(string _name);
    Form(string _name, int _grade, int _execGrade);
    Form(const Form &oth);
    Form &operator=(const Form &oth);
    ~Form();
    /* **** [^] Orthodox Form [^] **** */

    /* **** [v] Set & Get Functions [v] **** */
    void setName(const string _name);
    void setSign(const bool _sign);
    void setSignGrade(const int _grade);
    void setExecGrade(const int _grade);

    string getName() const;
    bool getSign() const;
    int getSignGrade() const;
    int getExecGrade() const;
    /* **** [^] Set & Get Functions [^] **** */

    /* ********* [v] Be Signed [v] ********* */
    void beSigned(const Bureaucrat &oth);
    /* ********* [^] Be Signed [^] ********* */

    /* ****** [v] Grade Too High Class [v] ****** */
    class GradeTooHighException : public exception {
       private:
        string message;

       public:
        GradeTooHighException(string msg);
        ~GradeTooHighException() throw();
        virtual const char *what() const throw();
    };
    /* ****** [^] Grade Too High Class [^] ****** */

    /* ******* [v] Grade Too Low Class [v] ******* */
    class GradeTooLowException : public exception {
       private:
        string message;

       public:
        GradeTooLowException(string msg);
        ~GradeTooLowException() throw();
        virtual const char *what() const throw();
    };
    /* ******* [^] Grade Too Low Class [^] ******* */
};

/* *************************** [^] FORM CLASS [^] *************************** */

/* ********* [v] Stream Operator [v] ********* */
ostream &operator<<(ostream &o, const Form &oth);
/* ********* [^] Stream Operator [^] ********* */

#endif
