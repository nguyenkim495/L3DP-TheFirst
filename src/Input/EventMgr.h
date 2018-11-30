#pragma once

#include <irrlicht.h>

class EventMgr
{
public:
	explicit	EventMgr();
	~EventMgr();

	void	Init();
	void	Destroy();

	bool OnEvent(const irr::SEvent& event);

	void	Update(int dt);
private:

};
