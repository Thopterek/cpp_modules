/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:58:33 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/04/29 15:13:49 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Base.hpp"
#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"

int	main(void) {
	std::cout << std::string(44, '#') << std::endl;
	std::cout << "\tfirst the normal tests" << std::endl;
	std::cout << std::string(44, '#') << std::endl;
	Base	*tmp = generate();
	Base	*nu = nullptr;
	identify(tmp);
	identify(*tmp);
	std::cout << std::string(44, '#') << std::endl;
	std::cout << "\tthen working with nullptr" << std::endl;
	std::cout << std::string(44, '#') << std::endl;
	identify(nu);
	identify(*nu);
	delete tmp;
	return (EXIT_SUCCESS);
}