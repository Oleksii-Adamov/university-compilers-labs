#include "LowercaseAutomataState.h"
/*
* 
* std::size_t char_to_index(char c) {
		if (!(c >= 'a' && c <= 'z')) throw std::invalid_argument("not lowercase char in LowercaseAutomataState");
		return c - 'a';
	}

LowercaseAutomataState(bool is_accepted_state = false)
		: is_accepted_state(is_accepted_state)
	{
		for (std::size_t i = 0; i < num_states; i++) {
			next_states[i] = nullptr;
		}
	}

	void add_next_state(char c, LowercaseAutomataState* next_state) {
		next_states[char_to_index(c)] = next_state;
	}

	LowercaseAutomataState* next(char c) {
		return next_states[char_to_index(c)];
	}

	void set_accepted_state(bool is_accepted_state_) {
		is_accepted_state = is_accepted_state_;
	}

	bool is_accepted_state() {
		return is_accepted_state;
	}
*/
/*
std::size_t LowercaseAutomataState::char_to_index(char c)
{
	if (!(c >= 'a' && c <= 'z')) throw std::invalid_argument("not lowercase char in LowercaseAutomataState");
	return c - 'a';
}

LowercaseAutomataState::LowercaseAutomataState(bool accepted_state_)
	: accepted_state(is_accepted_state)
{
	for (std::size_t i = 0; i < num_states; i++) {
		next_states[i] = nullptr;
	}
}

void LowercaseAutomataState::add_next_state(char c, LowercaseAutomataState* next_state)
{
}

LowercaseAutomataState* LowercaseAutomataState::next(char c)
{
	return nullptr;
}

void LowercaseAutomataState::set_accepted_state(bool is_accepted_state_)
{
}

bool LowercaseAutomataState::is_accepted_state()
{
	return false;
}
*/