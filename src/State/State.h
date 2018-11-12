#pragma once

#include <irrlicht.h>
#include <string>

//#include "State\StateMgr.h"

enum StateIdlist
{
	STATE_LOADING = 0, //"LoadingState"
	STATE_GAMEPLAY,	  //GamePlayState
	STATE_ABOUT,      //AboutState
	STATE_SETTING     //SettingState
};

struct StateId
{
	StateId(const std::string id)
	{
		m_stateId = id;
	};


	std::string m_stateId;
	std::string value()
	{
		return m_stateId;
	}
};

class State : public irr::IEventReceiver
{
protected:
	const StateId m_stateId;
public:
	State():m_stateId(""){};
	explicit	State(const std::string&);
	virtual		~State(){};

	friend class StateMgr;
public:
	virtual void	Init();
	virtual void	Render();
	virtual void	Update(float dt);

	virtual void	Pause();
	virtual void	Resume();
	virtual void	Release();

	virtual void	GotFocus();
	virtual void	LostFocus();

	virtual bool	OnEvent(const irr::SEvent& event);

	StateId	GetStateId() const;
};