#pragma once

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Singleton Template
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<typename S>
class Singleton
{
public:
	Singleton()
	{
		m_Instance = static_cast<S*>(this);

	}
	
	virtual ~Singleton()
	{
		m_Instance = 0;
	}

	static S* Instance()
	{
		return m_Instance;
	}

private:
	static S* m_Instance;
};

template <typename S>
S* Singleton<S>::m_Instance = 0;