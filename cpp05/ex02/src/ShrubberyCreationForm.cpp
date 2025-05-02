/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:57:23 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/04/22 10:05:56 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
:	AForm("ShrubberyCreationForm", 145, 137), target("")
{
	std::cout << "SCF default constructor, most likely never called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string set_target)
:	AForm("ShrubberyCreationForm", 145, 137), target(set_target)
{
	std::cout << "SCF construtor with name per subject" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "SCF destructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
:	AForm(other), target(other.target)
{
	std::cout << "SCF copy constructor" << std::endl;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	if (this != &other) {
		target = other.getTarget();
	}
	std::cout << "SCF copy assingment operator" << std::endl;
	return (*this);
}

void	ShrubberyCreationForm::action() const {
	std::ofstream	file(getTarget() + "_shrubbery");
	file << "                                              .         ;  \n"
	<< "                 *              *              0     ;;   \n"
	<< "                   ,           ,                :0  %;   \n"
	<< "                    i         ;                   i0;'     *,\n"
	<< "           ,*        %;     %;            ;        %;'    ,;\n"
	<< "             ;       0;  %%;        ,     %;    0;    ,%'\n"
	<< "              %;       %0;      ,  ;       %;  0;   ,%;'\n"
	<< "               0;      %;        0;        % 0;  ,%;'\n"
	<< "                `%;*     0;     %;'         `0%;*%;'\n"
	<< "                 `i0*    0%* %@;        %; ;@%0'\n"
	<< "                    `i%;*  i;bd%;          %;@%;'\n"
	<< "                      `@%i*  i0*         ;@@%;'\n"
	<< "                        `@%*  `;@%*      ;@@%;\n"
	<< "                          `@%%* `@%%    ;@@%;\n"
	<< "                            ;@%* i@%%  %@@%;\n"
	<< "                              %@bd%%%bd%%i;\n"
	<< "                                #@%%%%%i;\n"
	<< "                                %@@%%%:i;\n"
	<< "                                %@@@%(o);  * '\n"
	<< "                                %@@@o%;i(*,'\n"
	<< "                            `.* %@@@o%:i;\n"
	<< "                               `)@@@o%:i;\n"
	<< "                                %@@(o):i;\n"
	<< "                               *%@@@@%:i;\n"
	<< "                               0@@@@%:i;*\n"
	<< "                              0@@@@%%i;;;*\n"
	<< "                          ..*0@@@@@%%i;;;;,*\n";
	file.close();
}

std::string const	&ShrubberyCreationForm::getTarget() const {
	return (target);
}