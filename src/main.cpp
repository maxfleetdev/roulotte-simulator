#include <iostream>
#include <string>
#include "roulette.h"
#include "user.h"

void print_bet_choices();
void print_option(int choice);
void place_bet(BetType type, int option);
void clear_screen();

// placeholder
User me = User("Max", 10000);

int main() {
	while (1) {
		print_bet_choices();
	}
	return 0;
}

void print_bet_choices() {
	std::cout <<
		"Balance: " << me.get_current_amount() <<
		"\nChoose an option:\n" <<
		"1. Odd/Even\n2. Number\n3. Black/Red\n4. Exit\n\n>> ";
	int choice;
	std::cin >> choice;

	if (choice == 4) {
		std::cout << "\nThanks for playing!\n";
		exit(0);
	}
	
	clear_screen();
	print_option(choice);
}

void print_option(int choice) {
	BetType type = (BetType)choice;
	int option;

	switch (type) {
	case COLOUR:
		std::cout << "Choose a colour:\n";
		std::cout << "0. Black\n1. Red\n\n>> ";
		break;

	case ODD_EVEN:
		std::cout << "Choose an option:\n";
		std::cout << "0. Odd\n1. Even\n\n>> ";
		break;

	case SINGLE_NUMBER:
		std::cout << "Choose a number:\n>> ";
		break;

	default:
		return;
	}

	std::cin >> option;

	place_bet(type, option);
}

void place_bet(BetType type, int option) {

	clear_screen();

	std::cout << "Place a bet:\n>> ";
	
	int bet;
	std::cin >> bet;
	clear_screen();

	if (me.get_current_amount() - bet < 0) {
		std::cout << "Not enough balance!\n\n";
		return;
	}

	bool has_won = RouletteGame().check_win(type, option);
	if (has_won) {
		if (type == ODD_EVEN || type == COLOUR) {
			me.change_amount(bet);
			std::cout << "\nYou won " << bet * 2 << "!\n";
		}
		else {
			me.change_amount(bet * 35);
			std::cout << "\nYou won " << bet * 35 << "!\n";
		}
	}

	else {
		me.change_amount(-bet);
		std::cout << "\nYou lost!\n";
	}
}

void clear_screen() {
	std::cin.clear();
	system("cls");
}