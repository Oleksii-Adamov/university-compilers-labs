#include "LowercaseAutomataState.h"
 
std::size_t LowercaseAutomataState::char_to_index(char c) {
	if (!is_lowercase_letter(c)) throw std::invalid_argument("not lowercase char in LowercaseAutomataState");
	return c - 'a';
}
LowercaseAutomataState::LowercaseAutomataState(bool accepted_state)
	: accepted_state(accepted_state)
{
	for (std::size_t i = 0; i < num_states; i++) {
		next_states[i] = nullptr;
	}
}

void LowercaseAutomataState::add_next_state(char c, LowercaseAutomataState* next_state) {
	next_states[char_to_index(c)] = next_state;
}

LowercaseAutomataState* LowercaseAutomataState::next(char c) {
	return next_states[char_to_index(c)];
}

void LowercaseAutomataState::set_accepted_state(bool accepted_state_) {
	accepted_state = accepted_state_;
}

bool LowercaseAutomataState::is_accepted_state() {
	return accepted_state;
}

LowercaseAutomataState::~LowercaseAutomataState() {
	// cascade deletion of next states (destructors of next will be called)
	for (std::size_t i = 0; i < num_states; i++) {
		if (next_states[i] != nullptr) delete next_states[i];
	}
}