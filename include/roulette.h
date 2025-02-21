#ifndef ROULETTE_H
#define ROULETTE_H

#include <set>

enum BetType {
	ODD_EVEN = 1,
	SINGLE_NUMBER = 2,
	COLOUR = 3
};

class RouletteGame {
public:
	bool check_win(BetType type, int player_choice);

protected:
	bool odd_even();
	bool red_black();
	bool single_number();

	int m_table_result = 0;
	int m_player_choice = 0;
	std::set<int> m_red_numbers = 
	{ 
		1,3,5,7,9,12,14,16,
		18,19,21,23,25,27,
		30,32,34,36 
	};
};

#endif