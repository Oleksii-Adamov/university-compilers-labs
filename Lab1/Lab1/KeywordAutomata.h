#pragma once
#include "LowercaseAutomataState.h"

class KeywordAutomata
{
private:
	// TODO: use smart pointers
	LowercaseAutomataState* starting_state = new LowercaseAutomataState();
	LowercaseAutomataState* current_state = starting_state;
public:
	void add_keyword(std::string keyword) {
		LowercaseAutomataState* add_cur_state = starting_state;
		for (std::size_t i = 0; i < keyword.size(); i++) {
			LowercaseAutomataState* next_state = add_cur_state->next(keyword[i]);
			if (next_state == nullptr) {
				next_state = new LowercaseAutomataState();
				add_cur_state->add_next_state(keyword[i], next_state);
			}
			add_cur_state = next_state;
		}
		add_cur_state->set_accepted_state(true);
	}

	void feed(char c) {
		if (current_state != nullptr) {
			current_state = current_state->next(c);
		}
	}

	bool is_in_accepted_state() {
		if (current_state != nullptr) return current_state->is_accepted_state();
		else return false;
	}
};

