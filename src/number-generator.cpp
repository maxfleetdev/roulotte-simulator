#include "number-generator.h"

constexpr int MIN = 0;		// first index
constexpr int MAX = 36;		// last index

// Public call to return a random ball on the roullete table
int Generator::roll_ball() {
	int rolled = random_number();
	m_last_number = rolled;
	return rolled;
}

// Protected call to generate a number in certain bounds
int Generator::random_number() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distrib(MIN, MAX);
	
	// Return the random number from roulette wheel
	return m_numbers[distrib(gen)];
}

// Returns the last generated number
int Generator::get_last_number() {
	return m_last_number;
}