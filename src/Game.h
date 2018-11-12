#ifndef __GAME__
#define __GAME__

#include <IVideoDriver.h>
#include "IrrlichtDevice.h"
#include <irrlicht.h>

using namespace irr;


class StateMgr;

class Game
{
private:
	irr::IrrlichtDevice* m_device;
	static Game* m_Instance;
public:

	static Game* Instance();

	IrrlichtDevice* GetIrrDevice();
	irr::video::IVideoDriver* GetIVideoDriver();

	Game();
	~Game();

	void	Init(irr::IrrlichtDevice*);

	void	Render();
	void	Update(float dt);

	bool	OnKeyEvent(irr::EKEY_CODE);
	bool	OnMouseEvent(irr::EMOUSE_INPUT_EVENT);

public:
	static	StateMgr*	GetStateMgr();

private:
	bool	m_Init;
	StateMgr*	m_stateMgr;

};
#endif