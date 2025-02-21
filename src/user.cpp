#include <iostream>
#include "user.h"

User::User(std::string name, int starting_amount) {
	m_current_amount = starting_amount;
	m_name = name;
}

User::~User() {}

void User::change_amount(int change) {
	// Cannot be below 0
	if (m_current_amount + change < 0) {
		std::cout << "Not enough balance!\n";
		return;
	}

	// Add wins/losses
	if (change < 0) {
		m_losses++;
	}
	else {
		m_wins++;
	}

	m_current_amount += change;
}

int User::get_current_amount() {
	return m_current_amount;
}