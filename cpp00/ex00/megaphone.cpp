/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:46:06 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/04/07 11:46:08 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int	main(int ac, char **av) {
	if (ac < 2) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	std::string str;
	for (int i = 1; i < ac; i++){
		str += av[i];
		if (i != ac - 1)
			str += ' ';
	}
	for (int c = 0; c < (int)str.length(); c++)
		str[c] = std::toupper(str[c]);
	std::cout << str << std::endl;
	return (0);
}
