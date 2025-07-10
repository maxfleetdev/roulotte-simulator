# C++ Roulette Game

A simple command-line **roulette game** built in C++ that allows players to place bets on **Odd/Even, Single Numbers, and Colours (Black/Red)**. The game simulates a European roulette wheel with correct odds and payouts.

## Features
- **Bet Types**:
- **Odd/Even** (1:1 payout)
- **Red/Black (Colour)** (1:1 payout)
- **Straight (Single Number)** (35:1 payout)
- **Randomized Roulette Wheel** using `std::random_device` and `std::mt19937`.
- **Player Bank System**: Start with a balance, place bets, win or lose.
- **Betting Simulation**: Choose a betting option and see if you can make money!
- **Input Validation**: Prevents invalid choices and negative balances.
- **Object-Oriented Design (OOP)**: Uses `RouletteGame`, `User`, and `Generator` classes.

---

## Getting Started

### **1 Clone the Repository**
```bash
git clone https://github.com/maxfleetdev/roulotte-simulator.git
cd roulotte-simulator
```

2 Compile the Code
Use g++ or any modern C++ compiler:
```bash
g++ -o roulette main.cpp user.cpp roulette.cpp number-generator.cpp -std=c++17
```

3 Run the Game
```bash
./roulette
```

---
## How to Play
1. The game starts with $1000 balance.
2. Choose an option type:
   - 1 → Odd/Even
   - 2 → Single Number
   - 3 → Black/Red
   - 4 → Simulation
3. Enter your specific bet:
   - 0 for Black, 1 for Red (for Colour bets)
   - 0 for Odd, 1 for Even (for Odd/Even bets)
   - 0-36 for Single Number bets
4. Enter the amount you want to bet.
5. The roulette spins and determines the winning number.
6. Your balance updates based on the result.
7. Play again or exit.
