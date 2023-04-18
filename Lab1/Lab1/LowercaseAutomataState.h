#pragma once
#include <vector>
#include <stdexcept>

class LowercaseAutomataState
{
private:
	static const std::size_t num_states = 'z' - 'a' + 1;

	// TODO: use smart pointers
	LowercaseAutomataState* next_states[num_states];
	bool is_accepted_state;

	std::size_t char_to_index(char c) {
		if (!(c >= 'a' && c <= 'z')) throw std::invalid_argument("not lowercase char in LowercaseAutomataState");
		return c - 'a';
	}
public:
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
};

