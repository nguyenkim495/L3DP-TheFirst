#pragma once

#include <vector>
#include "Menu\Menu.h"

class MenuMgr
{
public:
	explicit MenuMgr();
	~MenuMgr();

public:
	void	Init();
	void	Destroy();
	void	OnLoad();
	void	Reset();

	void	Update(int dt);
	void	Render();

	void	AddMenu(Menu* menu);
	void	OpenMenu(Menu* menu);
	//void	RemoveMenu(Menu* menu);//menuId
	//void	RemoveMenu(Menu* menu);
	//void	CloseMenu(Menu* menu);
	void	DeleteMenu(Menu* menu);
	
	Menu*	GetTopMenu() const;


private:
	std::vector<Menu*>	m_openMenus;
	std::vector<Menu*>	m_queuedMenus;
};
