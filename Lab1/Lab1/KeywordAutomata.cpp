#include "KeywordAutomata.h"
void KeywordAutomata::add_keyword(std::string keyword) {
	if (keyword != "_") {
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
}

void KeywordAutomata::feed(char c) {
	if (c == '_' && current_state == starting_state) {
		is_underline = true;
	}
	else {
		is_underline = false;
		if (is_lowercase_letter(c)) {
			if (current_state != nullptr) {
				current_state = current_state->next(c);
			}
		}
		else {
			current_state = nullptr;
		}
	}
}

bool KeywordAutomata::is_in_accepted_state() {
	if (current_state != nullptr) return current_state->is_accepted_state() || is_underline;
	else return false || is_underline;
}

void KeywordAutomata::reset_state() {
	current_state = starting_state;
}