#pragma once

#include <irrlicht.h>
#include "Game.h"

namespace Screen
{
	static const int SCREEN_WIDTH = 1900;
	static const int SCREEN_HEIGHT = 1000;
}

class App : public irr::IEventReceiver
{
private:
	//graphics
	
	//physic
	//audio
public:
	irr::IrrlichtDevice* m_DEVICE;
	irr::video::IVideoDriver* m_DRIVER;
	irr::scene::ISceneManager* m_SMGR;

	static App* m_Instance;
	App* GetInstance();
	void CreatApplication();
	virtual bool OnEvent(const irr::SEvent&)
	{
		return false;
	}

	void	Init();

	void	Render();
	void	Update();
	void	Destroy();

	void	onKeyEvent(irr::EKEY_CODE);
	void	onMouseEvent(irr::EMOUSE_INPUT_EVENT);

private:
	float	delta;
	Game*	m_game;

};