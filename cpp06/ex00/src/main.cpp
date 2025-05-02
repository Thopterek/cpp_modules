/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 09:20:19 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/04/25 14:48:29 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"

int	main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "Error: usage ./scalar <one_argument>" << std::endl;
		return (EXIT_FAILURE);
	}
	ScalarConverter::convert(av[1]);
	return (0);
}