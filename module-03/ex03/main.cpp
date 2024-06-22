#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main() {

	DiamondTrap d1("D1");

	d1.attack("T1");
	d1.whoAmI();
}