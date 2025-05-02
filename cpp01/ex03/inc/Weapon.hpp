#ifndef	WEAPON_HPP
#define	WEAPON_HPP

class	Weapon {
	private:
		std::string	type;
	public:
		Weapon();
		~Weapon();
		Weapon(const Weapon &other);
		Weapon	&operator=(const Weapon &other);
		const std::string	&getType();
		void	setType(std::string new_value);
		Weapon(std::string new_value);
};

#endif