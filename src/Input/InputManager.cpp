#include <time.h>

#include "App.h"
#include <Game.h>


using namespace irr;


App* App::m_Instance = 0;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void App::CreatApplication()
{
	if(this == nullptr)
		m_Instance = new App();
	else
		m_Instance = this;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
App* App::GetInstance()
{
	return m_Instance;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
App::App():
	m_currentStartFrame(0),
	m_previousStartFrame(0)
{

}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
App::~App()
{
	if(m_Instance)
	{
		Destroy();
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void App::Init()
{
	m_game = new Game();
	m_game->Init(m_DEVICE);

	SetTargetFps(60);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void App::Destroy()
{
	if(m_Instance)
		delete m_Instance;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void App::Render()
{
	m_game->Render();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void App::Update()
{
	BeginFrame();

	int dt = (int)m_currentStartFrame - m_previousStartFrame;
	Update(dt);

	EndFrame();

}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void App::Update(int dt)
{
	if(!m_game)
		return;

	if(!m_game->IsInit())
	{
		m_game->Init(m_DEVICE);
		return;
	}

	m_game->Update(dt);
	Render();
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void App::SetTargetFps(unsigned int fps)
{
	m_TargetFps = fps;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void App::BeginFrame()
{
	m_previousStartFrame = m_currentStartFrame;

	time_t now = time(0);

	//limit the fps
	unsigned int target = unsigned int(1000/m_TargetFps);
	unsigned int elapsed = unsigned int (now - m_previousStartFrame);
	unsigned int delay = target - elapsed;
	if(delay > 0 && delay <= elapsed)
	{
		_sleep(delay);
		time(&now);
	}
	m_currentStartFrame = now;

	if(m_game)
	{
		m_game->BeginFrame();
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void App::EndFrame()
{

}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool App::OnEvent(const irr::SEvent& event)
{
	switch (event.EventType)
	{
	case irr::EET_GUI_EVENT:
		break;
	case irr::EET_MOUSE_INPUT_EVENT:
		//event.MouseInput.ButtonStates;
		onMouseEvent(event.MouseInput.Event);
		break;
	case irr::EET_KEY_INPUT_EVENT:
		//onKeyEvent(event.KeyInput);
		break;
	case irr::EET_JOYSTICK_INPUT_EVENT:
		break;
	case irr::EET_LOG_TEXT_EVENT:
		break;
	case irr::EET_USER_EVENT:
		break;

	default:
		break;
	}
	return false;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void App::onKeyEvent(irr::EKEY_CODE keyCode)
{
	Game::Instance()->OnKeyEvent(keyCode);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void App::onMouseEvent(irr::EMOUSE_INPUT_EVENT mouseCode)
{
	Game::Instance()->OnMouseEvent(mouseCode);
}








//#pragma comment(lib, "irrKlang.lib") //prefer setting in Game_2012/properties/Linker/Input/Additional Dependencies
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//WIN32
int main(int argc, char** argv) //lol this function, cant run as name Main
{
	App* m_AppGlobal = new App();
	irr::IrrlichtDevice* DEVICE = createDevice(video::EDT_OPENGL, core::dimension2d<u32>(Screen::SCREEN_WIDTH, Screen::SCREEN_HEIGHT), 32, false, false, true, m_AppGlobal);

	m_AppGlobal->CreatApplication();
	m_AppGlobal->GetInstance()->m_DEVICE = DEVICE;
	m_AppGlobal->GetInstance()->m_DRIVER = DEVICE->getVideoDriver();
	m_AppGlobal->GetInstance()->m_SMGR = DEVICE->getSceneManager();
	m_AppGlobal->GetInstance()->Init();

	DEVICE->setResizable(false);

	while (m_AppGlobal->GetInstance()->m_DEVICE->run())
	{
		m_AppGlobal->Update();
	}

	delete m_AppGlobal;

	return 0;
}