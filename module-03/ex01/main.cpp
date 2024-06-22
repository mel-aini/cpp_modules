#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
	ScavTrap s1("S1");

	s1.attack("T1");
	s1.guardGate();
}