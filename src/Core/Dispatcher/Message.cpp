#pragma once

#include "Message.h"

Message::~Message()
{

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
std::string Message::GetData() const
{
	return m_sData;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Message::SetData(std::string data)
{
	m_sData = data;
}