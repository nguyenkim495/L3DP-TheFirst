#pragma once

#include "Core\Dispatcher\MsgReceiver.h"

class Menu : public MsgReceiver
{
public:
	explicit Menu();
	~Menu();

public:
	void	Init();
	void	Destroy();
	void	Update(int dt);
	void	Render();

	void	GotFocus();
	void	LostFocus();
	
	virtual void	Start();
	virtual void	Resume();
	virtual void	OnLoad();
	virtual void	Update();

protected:
	void	Register(MessageType msgType);
	virtual	void	OnMsgReceived(MessageType msgType, const Message*);

private:
	Menu*	m_parent;
	Menu*	m_child;

	bool	m_closed;
	bool	m_visible;
	bool	m_onFocus;
	

};