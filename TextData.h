#pragma once
#define MAXCHARNUM 2048

class TextData : public SingletonBase<TextData>
{
public:
	TextData();
	~TextData();

	void Init();
	void Release();

	//Save
	void TextSave(const TCHAR* saveFileName, vector<string> vStr);
	char* VectorArrayCombine(vector<string> vArray);

	//Load
	vector<string> TextLoad(const TCHAR* loadFileName);
	vector<string> CharArraySeparation(char charArray[]);
};