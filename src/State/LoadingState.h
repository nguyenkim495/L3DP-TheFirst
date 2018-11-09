#pragma once
#include "State.h"
#include <Sprite\SimpleSprite.h>

class LoadingState : public State

{
public:
	LoadingState();
	~LoadingState();
private:
	SimpleSprite *m_SpriteLogo;
public:
	void		Init();
	void		Render();
	void		Update(float dt);
	void		Pause();
	void		Resume();
	void		Release();//

};