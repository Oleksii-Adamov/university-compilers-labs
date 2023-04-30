#pragma once
#include "LowercaseAutomataState.h"
#include "checks.h"

// using automata for keywords in explicit form, because all other solutions I could think of was inefficient (e.g check for all keywords on each iteration)
class KeywordAutomata
{
private:
	// TODO: use smart pointers
	LowercaseAutomataState* starting_state = new LowercaseAutomataState();
	LowercaseAutomataState* current_state = starting_state;
	// keyword underline handling separately to allow automata deal only with lowercase letters for convenience
	bool is_underline = false;
public:
	void add_keyword(std::string keyword);

	void feed(char c);

	bool is_in_accepted_state();

	void reset_state();
};

