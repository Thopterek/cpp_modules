/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 20:28:44 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/04/08 20:39:13 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Point.hpp"

/*
	on the edge or vertex it has to return false
	returns true only if point is inside triangle
		The Barycentric Coordinate Concept
		Point = a + w1(b - a) + w2(c - a)
	we assume that a is our starting point (like 0,0)
		P.x = A.x + w1*(B.x-A.x) + w2*(C.x-A.x)
		P.y = A.y + w1*(B.y-A.y) + w2*(C.y-A.y)
*/
bool	bsp(Point const a, Point const b, Point const c, Point const point) {
	/*
		Starting point needed for the rest of calculations
		its messy but easier to follow through for me (sorry)
	*/
	Fixed	vertical_a_to_c = c.getY() - a.getY();
	Fixed	horizontal_a_to_c = c.getX() - a.getX();
	Fixed	vertical_a_to_b = b.getY() - a.getY();
	Fixed	vertical_a_to_p = point.getY() - a.getY();
	/*
		Calculating everything for 'numerator'
		'n.' is the first number of division
	*/
	Fixed	relative_p_to_a = a.getX() * vertical_a_to_c;
	Fixed	p_vertical_offset = vertical_a_to_p * horizontal_a_to_c;
	Fixed	p_horizontal_pos = point.getX() * vertical_a_to_c;
	Fixed	numerator = relative_p_to_a + p_vertical_offset - p_horizontal_pos;
	/*
		now for the 'denominator'
		'd.' second nbr of division
		twice the signed are of triangle
		and getting their difference
	*/
	Fixed	first_area = vertical_a_to_b * horizontal_a_to_c;
	Fixed	second_area = (b.getX() - a.getX()) * vertical_a_to_c;
	Fixed	denominator = first_area - second_area;
	/*
		putting the above one together
		having weight one and making second
		then reuting the bool result
	*/
	Fixed	weight_one = numerator / denominator;
	Fixed	weight_two = (vertical_a_to_p - weight_one * vertical_a_to_b) / vertical_a_to_c;
	return (weight_one > 0 && weight_two > 0 && (weight_one + weight_two) < 1);
}
