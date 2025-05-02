#ifndef	POINT_HPP
#define	POINT_HPP

#include "Fixed.hpp"

class	Point {
	private:
		const Fixed	x;
		const Fixed	y;
	public:
		Point();
		~Point();
		Point(const Point &other);
		Point	&operator=(const Point &other);
		/*
			per subject other usefull stuff
			- getter for x and y
			- init with values
		*/
		Fixed	getX() const;
		Fixed	getY() const;
		Point(const Fixed x, const Fixed y);
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif