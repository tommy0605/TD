//�̱��� ���� : �ϳ��� ��ü�� �����ؼ� �ٸ� ��ü����
//���� �����ؼ� ��� �� �� �ְ� �ϴ� ������ ���� �� �ϳ�
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
