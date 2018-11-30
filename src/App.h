#pragma once

#include <time.h>

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
	
	explicit	App();
	~App();

	void	Init();

	void	Render();
	void	Update();
	void	Update(int dt);
	void	Destroy();

	virtual bool OnEvent(const irr::SEvent&);
	void	onKeyEvent(irr::SEvent::SKeyInput);
	void	onMouseEvent(irr::SEvent::SMouseInput);

	void	SetTargetFps(unsigned int fps);
	void	BeginFrame();
	void	EndFrame();

private:
	unsigned int m_TargetFps;
	time_t m_previousStartFrame;
	time_t m_currentStartFrame;

	Game*	m_game;

};