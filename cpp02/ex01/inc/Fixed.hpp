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
};
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif