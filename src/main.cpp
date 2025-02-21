#include <iostream>
#include <string>
#include "roulette.h"
#include "user.h"

void simulate_choice(BetType type, int option);
BetType print_bet_choices(bool allow_simulation = true);
int print_option(BetType type);
void place_bet(BetType type, int option);
void clear_screen();

User me = User("Max", 10000);

int main() {
    while (true) {
        BetType type = print_bet_choices();
        int choice = print_option(type);
        if (choice == -1) {
            continue;
        }
        place_bet(type, choice);
    }
    return 0;
}

BetType print_bet_choices(bool allow_simulation) {
    std::cout <<
        "Balance: $" << me.get_current_amount() <<
        "\nChoose an option:\n"
        "1. Odd/Even\n"
        "2. Number\n"
        "3. Black/Red";

    if (allow_simulation) {
        std::cout << "\n4. Simulation\n5. Exit";
    }

    std::cout << "\n\n>> ";

    int choice;
    std::cin >> choice;

    clear_screen();

    if (allow_simulation && choice == 4) return SIMULATION;
    if (allow_simulation && choice == 5) return EXIT;

    if (choice < 1 || choice > 3) {
        std::cout << "Invalid choice. Try again.\n";
        return print_bet_choices(allow_simulation);
    }

    return static_cast<BetType>(choice);
}

int print_option(BetType type) {
    int option;

    switch (type) {
    case COLOUR:
        std::cout << "Choose a colour:\n0. Black\n1. Red\n\n>> ";
        break;
    case ODD_EVEN:
        std::cout << "Choose an option:\n0. Odd\n1. Even\n\n>> ";
        break;
    case SINGLE_NUMBER:
        std::cout << "Choose a number (0-36):\n>> ";
        break;
    case SIMULATION: {
        BetType sim_type = print_bet_choices(false);
        int sim_option = print_option(sim_type);
        if (sim_option != -1) {
            simulate_choice(sim_type, sim_option);
        }
        return -1;
    }
    case EXIT:
        std::cout << "Thanks for playing!\n";
        exit(0);
    default:
        return -1;
    }

    std::cin >> option;

    if (type == SINGLE_NUMBER && (option < 0 || option > 36)) {
        std::cout << "Invalid number. Choose between 0-36.\n";
        return print_option(type);
    }

    return option;
}

void simulate_choice(BetType type, int option) {
    clear_screen();

    int wins = 0;
    int total = 0;
    int per_bet = 10;
    int num_simulations = 100;

    std::cout << "Simulating " << num_simulations << " rounds...\n\n";

    for (int i = 0; i < num_simulations; i++) {
        bool has_won = RouletteGame().check_win(type, option);
        total += has_won ? per_bet : -per_bet;
        wins += has_won ? 1 : 0;
    }

    std::cout << "Simulation Results:\n";
    std::cout << "Wins: " << wins << "/" << num_simulations << " (" << (wins * 100 / num_simulations) << "%)\n";
    std::cout << "Total Winnings/Losses: $" << total << "\n\n";
}

void place_bet(BetType type, int option) {
    clear_screen();

    std::cout << "Place a bet:\n>> ";

    int bet;
    std::cin >> bet;

    if (bet <= 0) {
        std::cout << "Invalid bet amount! Please enter a positive value.\n";
        return;
    }

    clear_screen();

    if (me.get_current_amount() - bet < 0) {
        std::cout << "Not enough balance!\n\n";
        return;
    }

    bool has_won = RouletteGame().check_win(type, option);
    if (has_won) {
        int winnings = (type == ODD_EVEN || type == COLOUR) ? bet * 2 : bet * 35;
        me.change_amount(winnings);
        std::cout << "\nYou won $" << winnings << "!\n";
    }
    else {
        me.change_amount(-bet);
        std::cout << "\nYou lost!\n";
    }

    std::cout << "New Balance: $" << me.get_current_amount() << "\n";
}

void clear_screen() {
    std::cin.clear();
    system("cls");
}
