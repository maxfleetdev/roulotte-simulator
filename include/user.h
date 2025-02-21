#ifndef USER_H
#define USER_H

#include <string>

class User {
public:
	User(std::string name, int start_amount);
	~User();

	int get_current_amount();
	void change_amount(int change);

protected:
	int m_current_amount = 0;
	int m_wins = 0;
	int m_losses = 0;

	std::string m_name = "";
};

#endif