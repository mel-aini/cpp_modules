#include "ClapTrap.hpp"

ClapTrap::ClapTrap() 
	: 
	name("default"),
	hitPoints(10),
	energyPoints(10),
	attackDamage(0) {
	std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& C) {
	*this = C;
}

ClapTrap& ClapTrap::operator= (const ClapTrap& C) {
	this->name = C.getName();
	this->hitPoints = C.getHitPoints();
	this->energyPoints = C.getEnergyPoints();
	this->attackDamage = C.getAttackDamage();
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap Default destructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) 
	: 
	name(name),
	hitPoints(10),
	energyPoints(10),
	attackDamage(0) {
	std::cout << "ClapTrap name constructor called" << std::endl;
}

const std::string& ClapTrap::getName(void) const {
	return this->name;
}

const int& ClapTrap::getHitPoints(void) const {
	return this->hitPoints;
}

const int& ClapTrap::getEnergyPoints(void) const {
	return this->energyPoints;
}

const int& ClapTrap::getAttackDamage(void) const {
	return this->attackDamage;
}

void ClapTrap::setAttackDamage(int damage) {
	this->attackDamage = damage;
}

void ClapTrap::setHitPoints(int points) {
	this->hitPoints = points;
}

void ClapTrap::setEnergyPoints(int points) {
	this->energyPoints = points;
}

void ClapTrap::attack(const std::string& target) {
	if (this->energyPoints <= 0 || this->hitPoints <= 0) {
		std::cout << "ClapTrap " << this->name << " can't attack" << std::endl;
		return;	
	}
	this->setEnergyPoints(this->energyPoints - 1);
	std::cout << "ClapTrap " << this->name;
	std::cout << " attacks " << target;
	std::cout << " causing " << this->attackDamage;
	std::cout << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	this->hitPoints -= amount;
	std::cout << "ClapTrap " << this->name;
	std::cout << " takes " << amount << " damage" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->energyPoints <= 0 || this->hitPoints <= 0) {
		std::cout << "ClapTrap " << this->name << " can't be repaired" << std::endl;
		return;	
	}
	this->hitPoints += amount;
	this->setEnergyPoints(this->energyPoints - 1);
	std::cout << "ClapTrap " << this->name;
	std::cout << " is repaired and gains " << amount << " hitPoints!" << std::endl;
}

void ClapTrap::log(void) {
	std::cout << "hitPoints: " << this->hitPoints << std::endl;
	std::cout << "energyPoints: " << this->energyPoints << std::endl;
	std::cout << "energyPoints: " << this->attackDamage << std::endl;
}
