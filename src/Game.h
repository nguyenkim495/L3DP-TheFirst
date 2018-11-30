#pragma once

#include <IVideoDriver.h>
#include "IrrlichtDevice.h"
#include <irrlicht.h>

#include "Core\Utils\Singleton.h"
//#include "Core\Dispatcher\MsgDispatcher.h"

using namespace irr;


class StateMgr;
class EventMgr;
class MsgDispatcher;
class MenuMgr;

class Game : public Singleton<Game>
{
private:
	irr::IrrlichtDevice* m_device;

public:
	Game();
	~Game();

	void	Init(irr::IrrlichtDevice*);

	void	BeginFrame();
	void	EndFrame();
	bool	IsInit();

	void	Render();
	void	Update(int dt);

	bool	OnKeyEvent(irr::SEvent::SKeyInput);
	bool	OnMouseEvent(irr::SEvent::SMouseInput);

public:
	IrrlichtDevice*				GetIrrDevice() const;
	irr::video::IVideoDriver*	GetIVideoDriver() const;
	irr::scene::ISceneManager*	GetISceneManager() const;

	StateMgr*		GetStateMgr() const;
	EventMgr*		GetEventMgr() const;
	MsgDispatcher*	GetMsgDispatcher() const;
	MenuMgr*		GetMenuMgr() const;

private:
	bool			m_IsInit;
	StateMgr*		m_stateMgr;
	EventMgr*		m_eventMgr;
	MsgDispatcher*	m_msgDispatcher;
	MenuMgr*		m_menuMgr;

};

inline Game* GetGame()
{
	return Game::Instance();
}