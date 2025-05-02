/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:58:44 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/04/08 17:31:07 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

/*
	Mostly copy paste from subject
	but added unused setRawBits
*/
int	main() {
	Fixed	a;
	Fixed	b(a);
	Fixed	c;
	c = b;
	a.setRawBits(1);
	std::cout << "I set the raw for the first one" << std::endl;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return (0);
}
