#pragma once
#include "State.h"
#include <Sprite\SimpleSprite.h>

class LoadingState : public State
{
public:
	explicit LoadingState();
	~LoadingState();
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

private:
	SimpleSprite *m_SpriteLogo;


};