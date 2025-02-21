#include "roulette.h"
#include "number-generator.h"

bool RouletteGame::check_win(BetType type, int player_choice) {
	m_table_result = Generator().roll_ball();
	m_player_choice = player_choice;
	
	switch (type) {
	case ODD_EVEN:
		return odd_even();
	
	case COLOUR:
		return red_black();

	case SINGLE_NUMBER:
		return single_number();

	default:
		return false;
	}
}

bool RouletteGame::odd_even() {
	if (m_table_result == 0) {
		return false;
	}
	
	bool result = false;
	if (m_table_result % 2 == 0) {
		result = true;
	}
	std::cout << "Rolled: " << m_table_result << std::endl
		<< "Number is: " << (result ? "Even" : "Odd") << std::endl;
	return m_player_choice == result;
}

bool RouletteGame::red_black() {
	// Colour is green, loss
	if (m_table_result == 0) {
		return false;
	}

	bool isRed = m_red_numbers.find(m_table_result) != m_red_numbers.end();
	std::cout << "Rolled: " << m_table_result << std::endl 
		<< "Colour is: " << (isRed ? "Red" : "Black") << std::endl;
	return m_player_choice == isRed;
}

bool RouletteGame::single_number() {
	std::cout << "Rolled: " << m_table_result << std::endl
		<< "Number is: " << m_table_result << std::endl;
	return m_table_result == m_player_choice;
}