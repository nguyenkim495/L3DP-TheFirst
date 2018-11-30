#pragma once

#include "MsgReceiver.h"
#include <vector>
#include <map>

class MsgDispatcher
{
public:
	explicit MsgDispatcher();
	~MsgDispatcher();

protected:
	typedef std::vector<MsgReceiver*> RecieverContainer;
	typedef std::map<MessageType, RecieverContainer> RecieverMap;
public:
	void	Raise(MessageType msgType, const Message& msg);

	void	Register(MsgReceiver* msgReceiver, MessageType msgType);

	void	Unregister(MsgReceiver* msgReceiver);

private:
	RecieverMap m_receivers;
};