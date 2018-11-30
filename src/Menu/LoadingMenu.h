#pragma once

#include "Menu\Menu.h"

class LoadingMenu : public Menu
{
public:
	explicit LoadingMenu();
	~LoadingMenu();

public:
	void	OnLoad();
	virtual void	OnMsgReceived(MessageType msgType, const Message* msg);

};