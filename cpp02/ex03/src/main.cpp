/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:58:44 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/04/09 09:16:42 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Point.hpp"

int main (void) {
	std::cout << "First is clearly in the middle" << std::endl;
	Point	a(0, 0);
	Point	b(10, 0);
	Point	c(5, 10);
	Point	p(5, 5);
	std::cout << "a is equal to: " << a.getX() << " " << a.getY() << std::endl;
	std::cout << "b is equal to: " << b.getX() << " " << b.getY() << std::endl;
	std::cout << "c is equal to: " << c.getX() << " " << c.getY() << std::endl;
	std::cout << "point is equal to: " << p.getX() << " " << p.getY() << std::endl;
	std::cout << "If value is 1 it means true: " << bsp(a, b, c, p) << std::endl;
	std::cout << "Now its a flipped triange, point is the same" << std::endl;
	Point a2(0, 10);
	Point b2(10, 10);
	Point c2(5, 0);
	std::cout << "a2 is equal to: " << a2.getX() << " " << a2.getY() << std::endl;
	std::cout << "b2 is equal to: " << b2.getX() << " " << b2.getY() << std::endl;
	std::cout << "c2 is equal to: " << c2.getX() << " " << c2.getY() << std::endl;
	std::cout << "If value is 1 it means true: " << bsp(a2, b2, c2, p) << std::endl;
	std::cout << "Now we are testing all the edges with first triangle" << std::endl;
	Point edge1(5, 0);
	Point edge2(2.5f, 5);
	Point edge3(7.5f, 5);
	std::cout << edge1.getX() << " " << edge1.getY() << " AB: " << bsp(a, b, c, edge1) << std::endl;
	std::cout << edge2.getX() << " " << edge2.getY() << " AC: " << bsp(a, b, c, edge2) << std::endl;
	std::cout << edge3.getX() << " " << edge3.getY() << " BC: " << bsp(a, b, c, edge3) << std::endl;
	std::cout << "Plus really close to those edges like here: inside" << std::endl;
	Point near1(5, 0.018f);
	std::cout << "point x: " << near1.getX() << " point y: " << near1.getY() << std::endl;
	std::cout << "The result is true if result is 1: " << bsp(a, b, c, near1) << std::endl;
	std::cout << "The lower precision fails, from what I understand its the constant 8 bits" << std::endl;
	std::cout << "Plus really close to those edges but outside" << std::endl;
	Point near2(5, -0.018f);
	std::cout << "point x: " << near2.getX() << " point y: " << near2.getY() << std::endl;
	std::cout << "The result is true if result is 1: " << bsp(a, b, c, near2) << std::endl;
	return (0);
}
