#pragma once

#include <IVideoDriver.h>
#include "IrrlichtDevice.h"
#include <irrlicht.h>

#include "Core\Utils\Singleton.h"

using namespace irr;


class StateMgr;

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
	void	Update(float dt);

	bool	OnKeyEvent(irr::EKEY_CODE);
	bool	OnMouseEvent(irr::EMOUSE_INPUT_EVENT);

public:
	StateMgr* GetStateMgr() const;
	IrrlichtDevice* GetIrrDevice() const;
	irr::video::IVideoDriver* GetIVideoDriver() const;
	irr::scene::ISceneManager* GetISceneManager() const;


private:
	bool	m_IsInit;
	StateMgr*	m_stateMgr;

};

inline Game* GetGame()
{
	return Game::Instance();
}