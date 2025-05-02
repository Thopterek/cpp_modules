/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:15:28 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/04/08 13:30:36 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Harl.hpp"

int	main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "Error: you didn't use the filter, one argument please" << std::endl;
		return (EXIT_FAILURE);
	}
	Harl harl(av[1]);
	harl.complain();
	return (EXIT_SUCCESS);
}
