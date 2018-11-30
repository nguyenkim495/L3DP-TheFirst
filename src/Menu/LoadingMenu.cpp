#include "LoadingMenu.h"

LoadingMenu::LoadingMenu()
{
	OnLoad();
}

///////////////////////////////////////////////////////////////////////////////
LoadingMenu::~LoadingMenu()
{

}

///////////////////////////////////////////////////////////////////////////////
void LoadingMenu::OnLoad()
{
	Register(MessageType::MT_LoadingDone);
}

///////////////////////////////////////////////////////////////////////////////
void LoadingMenu::OnMsgReceived(MessageType msgType, const Message* msg)
{
	Menu::OnMsgReceived(msgType, msg);
	switch (msgType)
	{
	case MT_LoadingDone:
		printf("data has received %s \n", msg->GetData().c_str());
		break;
	default:
		break;
	}
}