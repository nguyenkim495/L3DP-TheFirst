#pragma once

#include "State\State.h"
#include <vector>
#include <deque>

enum Commandlist
{
	POP,
	PUSH,
};

struct Command
{
	Commandlist command;
	State* Obj;
};

class StateMgr
{
public:
	void	Push(State*);
	void	Pop();
	void	PopAll();
	void	Switch(State*);

	State*	Current() const;//state on top
	State*	GetStateId(StateId& id) const;
	State*	GetPreviousState() const;

	void	AddCommand(const Command& command);
	void	Update(float dt);
	void	Render();
	void	ChangeState(State, bool deleteState);
	void	MarkStateToDelete(State);

	void	OnBackeyEvent();

private:
	std::vector<State*> m_states;
	std::deque<Command> m_commands;

};
