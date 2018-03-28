#include "stdafx.h"

TextData::TextData()
{
}

TextData::~TextData()
{
}

void TextData::Init()
{
}

void TextData::Release()
{
}

void TextData::TextSave(const TCHAR * saveFileName, vector<string> vStr)
{
	HANDLE file;

	char str[MAXCHARNUM];
	DWORD write;
	
	strncpy_s(str, MAXCHARNUM, VectorArrayCombine(vStr), MAXCHARNUM - 2);

	file = CreateFile(saveFileName, GENERIC_WRITE, 0, NULL,
		CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	WriteFile(file, str, MAXCHARNUM, &write, NULL);

	CloseHandle(file);
}

char * TextData::VectorArrayCombine(vector<string> vArray)
{
	char str[MAXCHARNUM];

	ZeroMemory(str, sizeof(str));

	for (int i = 0; i < vArray.size(); i++)
	{
		strncat_s(str, MAXCHARNUM, vArray[i].c_str(), MAXCHARNUM - 2);
		if (i + 1 < vArray.size())
			strcat_s(str, ",");
	}

	return str;
}

vector<string> TextData::TextLoad(const TCHAR * loadFileName)
{
	HANDLE file;

	char str[MAXCHARNUM];
	DWORD read;

	file = CreateFile(loadFileName, GENERIC_READ, 0, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	ReadFile(file, str, MAXCHARNUM, &read, NULL);

	CloseHandle(file);

	return CharArraySeparation(str);
}

vector<string> TextData::CharArraySeparation(char charArray[])
{
	vector<string> vArray;

	char* temp;
	char separator[] = ",";
	char* token;
	char* context = NULL;

	token = strtok_s(charArray, separator, &context);
	vArray.push_back(token);

	while (NULL != (token = strtok_s(NULL, separator, &context)))
	{
		vArray.push_back(token);
	}

	return vArray;
}
