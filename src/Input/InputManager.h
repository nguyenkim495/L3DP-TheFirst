#pragma once

#include <irrlicht.h>

class InputManager : public irr::IEventReceiver
{
public:
	explicit	InputManager();
	~InputManager();

	void	Init();
	void	Destroy();

	virtual bool OnEvent(const irr::SEvent& event);

	void	Update(int dt);
private:

};
