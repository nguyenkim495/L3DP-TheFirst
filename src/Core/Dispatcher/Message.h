#pragma once

#include <string>

#include "MessageType.h"

class Message
{
public:
	inline Message(std::string data)
	{
		m_sData = data;
	};
	~Message();

public:
	std::string	GetData() const;
	void		SetData(std::string data);

private:
	std::string m_sData;
};