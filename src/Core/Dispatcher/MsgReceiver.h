#pragma once

#include "Message.h"

struct MsgReceiver
{
	enum EPriority
	{
		VERY_LOW,
		LOW,
		MEDIUM,
		HIGH,
		VERY_HIGH
	};

	const EPriority Priority;

	MsgReceiver(EPriority p = LOW) : Priority(p) {}
	virtual ~MsgReceiver() {}

	virtual void OnMsgReceived(MessageType, const Message*) = 0;
	//virtual void OnMsgReceived(int stream) = 0;
};