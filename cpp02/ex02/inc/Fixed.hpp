#ifndef	FIXED_HPP
#define	FIXED_HPP

#include <iostream>

class	Fixed {
	private:
		int	raw;
		static const int	bits = 8;
	public:
		Fixed();
		/*
			non default constructors
				int and float
		*/
		Fixed(const int fixed);
		Fixed(const float fixed);
		~Fixed();
		Fixed(const Fixed &other);
		Fixed	&operator=(const Fixed &other);
		int	getRawBits(void) const;
		void	setRawBits(int const raw);
		/*
			Converters and bypass
				int and float
		*/
		int	toInt(void) const;
		float	toFloat(void) const;
		/*
			bool operators
			> < == != >= <=
		*/
		bool	operator>(const Fixed &other) const;
		bool	operator<(const Fixed &other) const;
		bool	operator>=(const Fixed &other) const;
		bool	operator<=(const Fixed &other) const;
		bool	operator==(const Fixed &other) const;
		bool	operator!=(const Fixed &other) const;
		/*
			sum and substraction
			pre and post changes
		*/
		Fixed	&operator++();
		Fixed	operator++(int);
		Fixed	&operator--();
		Fixed	operator--(int);
		/*
			helper functions for min and max
			with variations const and non const
		*/
		static Fixed	&min(Fixed &a, Fixed &b);
		static const Fixed	&min(const Fixed &a, const Fixed &b);
		static Fixed	&max(Fixed &a, Fixed &b);
		static const Fixed	&max(const Fixed &a, const Fixed &b);
};
/*
	all the math operations + ostream thing
		plus, minus, times, division
*/
Fixed	operator+(const Fixed &a, const Fixed &b);
Fixed	operator-(const Fixed &a, const Fixed &b);
Fixed	operator*(const Fixed &a, const Fixed &b);
Fixed	operator/(const Fixed &a, const Fixed &b);
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif