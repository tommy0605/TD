//싱글톤 패턴 : 하나의 객체를 생성해서 다른 객체들이
//쉽게 접근해서 사용 할 수 있게 하는 디자인 패턴 중 하나
#pragma once

template <typename T>
class SingletonBase
{
protected:
	static T* singleton;

public:
	static T* GetSingleton();
	void ReleaseSingleton();
};

template<typename T>
T* SingletonBase<T>::singleton = 0;

template<typename T>
T * SingletonBase<T>::GetSingleton()
{
	if (!singleton)
	{
		singleton = new T;
	}

	return singleton;
}

template<typename T>
void SingletonBase<T>::ReleaseSingleton()
{
	if (singleton)
	{
		delete = singleton;
		singleton = NULL;
	}
}
