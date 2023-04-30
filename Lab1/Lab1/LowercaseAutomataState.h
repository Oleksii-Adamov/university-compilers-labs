#pragma once
#include <vector>
#include <stdexcept>
#include "checks.h"

class LowercaseAutomataState
{
private:
	static const std::size_t num_states = 'z' - 'a' + 1;

	// TODO: use smart pointers
	LowercaseAutomataState* next_states[num_states];

	bool accepted_state;

	std::size_t char_to_index(char c);

public:
	LowercaseAutomataState(bool accepted_state = false);

	void add_next_state(char c, LowercaseAutomataState* next_state);

	LowercaseAutomataState* next(char c);

	void set_accepted_state(bool accepted_state_);

	bool is_accepted_state();
};

