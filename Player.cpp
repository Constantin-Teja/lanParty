#include "Player.hpp"

void Player::set_firstName(string name) {
	firstName = name;
}

void Player::set_secondName(string pre) {
	secondName = pre;
}

void Player::set_points(int pcts) {
	points = pcts;
}

int Player::get_points() const {
	return points;
}

Player& Player::operator=(const Player& player) {
	firstName = player.firstName;
	secondName = player.secondName;
	points = player.points;
	return *this;
}