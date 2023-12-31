#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Default"), hitPoint(10), energyPoint(10), attackDamage(0) {
	std::cout << "ClapTrap default constructor called" << std::endl;
};

ClapTrap::ClapTrap(std::string _name) : name(_name), hitPoint(10), energyPoint(10), attackDamage(0) {
	std::cout << "ClapTrap " << name << " is born!" << std::endl;
	std::cout << "     Hit points(" << hitPoint << ")" << std::endl;
	std::cout << "  Energy points(" << energyPoint << ")" << std::endl;
	std::cout << "  Attack damage(" << attackDamage << ")" << std::endl;
	std::cout << std::endl;
};

ClapTrap::ClapTrap(const ClapTrap &other) {
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = other;
};

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
	std::cout << "ClapTrap assignation operator called" << std::endl;
	if (this != &other) {
		name = other.name;
		hitPoint = other.hitPoint;
		energyPoint = other.energyPoint;
		attackDamage = other.attackDamage;
	}
	return (*this);
};

void ClapTrap::attack(const std::string &target) {
	if (hitPoint == 0 || energyPoint == 0)
		std::cout << "ClapTrap " << name << " can't attack!" << std::endl;
	else
	{
		std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
		energyPoint--;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (hitPoint == 0)
		std::cout << "ClapTrap " << name << " is already dead!" << std::endl;
	else
	{
		if (hitPoint < amount)
			amount = hitPoint;
		hitPoint -= amount;
		std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << std::endl;
		if (hitPoint == 0)
			std::cout << "ClapTrap " << name << " is dead!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (hitPoint == 0 || energyPoint == 0)
		std::cout << "ClapTrap " << name << " can't be repaired!" << std::endl;
	else
	{
		std::cout << "ClapTrap " << name << " is repaired " << amount << " points of damage!" << std::endl;
		hitPoint += amount;
		energyPoint--;
	}
}

void ClapTrap::setDamage(unsigned int amount) {
	attackDamage = amount;
	std::cout << "ClapTrap " << name << " set damage (" << amount << ')' << std::endl;
}

unsigned int ClapTrap::getDamage(void) const {
	return (attackDamage);
}

unsigned int ClapTrap::getHitPoint(void) const {
	return (hitPoint);
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap destructor called" << std::endl;
};
