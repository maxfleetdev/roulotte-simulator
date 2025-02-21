# 🎰 C++ Roulette Game

A simple command-line **roulette game** built in C++ that allows players to place bets on **Odd/Even, Single Numbers, and Colours**. The game simulates a European roulette wheel with correct odds and payouts.

## 🎯 Features
- ✅ **Bet Types**:
- ✅ **Odd/Even** (1:1 payout)
- ✅ **Red/Black (Colour)** (1:1 payout)
- ✅ **Straight (Single Number)** (35:1 payout)
- ✅ **Randomized Roulette Wheel** using `std::random_device` and `std::mt19937`.
- ✅ **Player Bank System**: Start with a balance, place bets, win or lose.
- ✅ **Input Validation**: Prevents invalid choices and negative balances.
- ✅ **Object-Oriented Design (OOP)**: Uses `RouletteGame`, `User`, and `Generator` classes.

---

## 🚀 Getting Started

### **1️⃣ Clone the Repository**
```bash
git clone https://github.com/yourusername/cpp-roulette-game.git
cd cpp-roulette-game
2️⃣ Compile the Code
Use g++ or any modern C++ compiler:
bash
g++ -o roulette main.cpp user.cpp roulette.cpp number-generator.cpp -std=c++17
3️⃣ Run the Game
bash
./roulette
