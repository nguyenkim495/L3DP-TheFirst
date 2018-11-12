#include "StateMgr.h"


///////////////////////////////////////////////////////////////////////////////
void StateMgr::AddCommand(const Command& command)
{
	m_commands.push_back(command);
}

///////////////////////////////////////////////////////////////////////////////
void StateMgr::Push(State* state)
{
	Command command;
	command.command = Commandlist::PUSH;
	command.Obj = state;
	AddCommand(command);
}

///////////////////////////////////////////////////////////////////////////////
void StateMgr::Pop()
{
	Command command;
	command.command = Commandlist::POP;
	command.Obj = nullptr;
	AddCommand(command);
}

///////////////////////////////////////////////////////////////////////////////
void StateMgr::PopAll()
{
	//
}

///////////////////////////////////////////////////////////////////////////////
void StateMgr::Switch(State* state)
{
	//delete the current state and focus on a new state
	Command command;

	command.command = Commandlist::POP;
	command.Obj = nullptr;
	AddCommand(command);

	command.command = Commandlist::PUSH;
	command.Obj = state;
	AddCommand(command);
}
///////////////////////////////////////////////////////////////////////////////
State* StateMgr::Current() const
{
	if(!m_states.empty())
		return m_states.back();

	return nullptr;
}
///////////////////////////////////////////////////////////////////////////////

void StateMgr::Update(float dt)
{
	while(!m_commands.empty())
	{
		Command command = m_commands.front();
		switch(command.command)
		{
		case Commandlist::PUSH:
		{
			auto newState = command.Obj;
			m_states.push_back(newState);
			newState->GotFocus();
		}
			break;
		case Commandlist::POP:
		{
			auto current = Current();
			if(current != nullptr)
			{
				current->LostFocus();
				m_states.pop_back();
			}
		}			
			break;
		default:
			break;
		}
		m_commands.pop_front();
	};

	if(!m_states.empty())
	{
		auto state = m_states.back();
		state->Update(dt);
	}

}
///////////////////////////////////////////////////////////////////////////////
void StateMgr::Render()
{
	if(!m_states.empty())
	{
		auto state = m_states.back();
		state->Render();
	}
}
///////////////////////////////////////////////////////////////////////////////