#pragma once

#include <bitset>

using namespace std;

#define KEYMAX 256

class KeyManager : public SingletonBase<KeyManager>
{
private:
	bitset<KEYMAX> _keyUp;
	bitset<KEYMAX> _keyDown;

public:
	void Init();
	bitset<KEYMAX> GetKeyUp() { return _keyUp; }
	bitset<KEYMAX> GetKeyDown() { return _keyDown; }
	void SetKeyUp(int key, bool state) { _keyUp.set(key, state); }
	void SetKeyDonw(int key, bool state) { _keyDown.set(key, state); }

	bool isOnceKeyDown(int key);
	bool isOnceKeyUp(int key);
	bool isStayKeyDown(int key);
};