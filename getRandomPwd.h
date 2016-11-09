#include "stdafx.h"
#include <ctime>
#include <iostream>

using namespace std;

const int AVAILABLE_CHAR_COUNT_10 = 10; //纯数字
const char g_availablechar10[AVAILABLE_CHAR_COUNT_10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

const int AVAILABLE_CHAR_COUNT_26_1 = 26; //纯小写字母
const char g_availablechar261[AVAILABLE_CHAR_COUNT_26_1] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q',
'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };

const int AVAILABLE_CHAR_COUNT_26_2 = 26; //纯大写字母
const char g_availablechar262[AVAILABLE_CHAR_COUNT_26_2] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S',
'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };

const int AVAILABLE_CHAR_COUNT_9 = 9; //纯特殊字符
const char g_availablechar9[AVAILABLE_CHAR_COUNT_9] = { '@', '!', '#', '$', '%', '&', '*', '(', ')' };

const int AVAILABLE_CHAR_COUNT_36_2 = 36; //纯数字加小写
const char g_availablechar362[AVAILABLE_CHAR_COUNT_36_2] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q',
'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };


const int AVAILABLE_CHAR_COUNT_36_1 = 36; //纯数字加大写
const char g_availablechar361[AVAILABLE_CHAR_COUNT_36_1] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S',
'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };

const int AVAILABLE_CHAR_COUNT_19 = 19; //纯数字加特殊符号
const char g_availablechar19[AVAILABLE_CHAR_COUNT_19] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '@', '!', '#', '$', '%', '&', '*', '(', ')' };

const int AVAILABLE_CHAR_COUNT_52 = 52; //大小写字母
const char g_availablechar52[AVAILABLE_CHAR_COUNT_52] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q',
'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S',
'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };

const int AVAILABLE_CHAR_COUNT_35_2 = 35; //纯小写字母加特殊符号
const char g_availablechar352[AVAILABLE_CHAR_COUNT_35_2] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q',
'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '@', '!', '#', '$', '%', '&', '*', '(', ')' };



const int AVAILABLE_CHAR_COUNT_35_1 = 35; //纯大写字母加特殊符号
const char g_availablechar351[AVAILABLE_CHAR_COUNT_35_1] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S',
'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '@', '!', '#', '$', '%', '&', '*', '(', ')' };

const int AVAILABLE_CHAR_COUNT_62 = 62; //大小写数字
const char g_availablechar62[AVAILABLE_CHAR_COUNT_62] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q',
'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S',
'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

const int AVAILABLE_CHAR_COUNT_45_1 = 45; //小写数字特殊
const char g_availablechar451[AVAILABLE_CHAR_COUNT_45_1] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S',
'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '@', '!', '#', '$', '%', '&', '*', '(', ')' };

const int AVAILABLE_CHAR_COUNT_45_2 = 45; //大写数字特殊
const char g_availablechar452[AVAILABLE_CHAR_COUNT_45_2] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q',
'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '@', '!', '#', '$', '%', '&', '*', '(', ')' };

const int AVAILABLE_CHAR_COUNT_61 = 61; //大小写特殊符号
const char g_availablechar61[AVAILABLE_CHAR_COUNT_61] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q',
'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S',
'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '@', '!', '#', '$', '%', '&', '*', '(', ')' };


const int AVAILABLE_CHAR_COUNT_71 = 71; //大小写数字特殊符号
const char g_availablechar71[AVAILABLE_CHAR_COUNT_71] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q',
'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S',
'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '@', '!', '#', '$', '%', '&', '*', '(', ')' };

//生成密码函数
char * getRandomStringPwd(int length,int pwdType)
{
	if (length < 0)
	{
		return 0;
	}
	char *pwd = new char[length + 1];
	srand(time(NULL)); //初始化为系统时间，在短时间内生成的密码应该是一样的。
	for (int i = 0; i < length; ++i)
	{
		if (pwdType == 10)
		{
			int randomNum = rand() % AVAILABLE_CHAR_COUNT_10;//生成0-61之间的随机数
			pwd[i] = g_availablechar10[randomNum];
		}
		if (pwdType == 261)
		{
			int randomNum = rand() % AVAILABLE_CHAR_COUNT_26_1;//生成0-61之间的随机数
			pwd[i] = g_availablechar261[randomNum];
		}
		if (pwdType == 262)
		{
			int randomNum = rand() % AVAILABLE_CHAR_COUNT_26_2;//生成0-61之间的随机数
			pwd[i] = g_availablechar262[randomNum];
		}
		if (pwdType == 9)
		{
			int randomNum = rand() % AVAILABLE_CHAR_COUNT_9;//生成0-61之间的随机数
			pwd[i] = g_availablechar9[randomNum];
		}
		if (pwdType == 361)
		{
			int randomNum = rand() % AVAILABLE_CHAR_COUNT_36_1;//生成0-61之间的随机数
			pwd[i] = g_availablechar361[randomNum];
		}
		if (pwdType == 362)
		{
			int randomNum = rand() % AVAILABLE_CHAR_COUNT_36_2;//生成0-61之间的随机数
			pwd[i] = g_availablechar362[randomNum];
		}
		
		if (pwdType == 19)
		{
			int randomNum = rand() % AVAILABLE_CHAR_COUNT_19;//生成0-61之间的随机数
			pwd[i] = g_availablechar19[randomNum];
		}
		if (pwdType == 52)
		{
			int randomNum = rand() % AVAILABLE_CHAR_COUNT_52;//生成0-61之间的随机数
			pwd[i] = g_availablechar52[randomNum];
		}
		if (pwdType == 352)
		{
			int randomNum = rand() % AVAILABLE_CHAR_COUNT_35_2;//生成0-61之间的随机数
			pwd[i] = g_availablechar352[randomNum];
		}
		if (pwdType == 351)
		{
			int randomNum = rand() % AVAILABLE_CHAR_COUNT_35_1;//生成0-61之间的随机数
			pwd[i] = g_availablechar351[randomNum];
		}
		if (pwdType == 62)
		{
			int randomNum = rand() % AVAILABLE_CHAR_COUNT_62;//生成0-61之间的随机数
			pwd[i] = g_availablechar62[randomNum];
		}
		if (pwdType == 451)
		{
			int randomNum = rand() % AVAILABLE_CHAR_COUNT_45_1;//生成0-61之间的随机数
			pwd[i] = g_availablechar451[randomNum];
		}
		if (pwdType == 452)
		{
			int randomNum = rand() % AVAILABLE_CHAR_COUNT_45_2;//生成0-61之间的随机数
			pwd[i] = g_availablechar452[randomNum];
		}
		if (pwdType == 61)
		{
			int randomNum = rand() % AVAILABLE_CHAR_COUNT_61;//生成0-61之间的随机数
			pwd[i] = g_availablechar61[randomNum];
		}
		if (pwdType == 71)
		{
			int randomNum = rand() % AVAILABLE_CHAR_COUNT_71;//生成0-61之间的随机数
			pwd[i] = g_availablechar71[randomNum];
		}
	}
	pwd[length] = '\0';
	
	return pwd;//返回堆上指针pwd
}

//判断密码是否符合需求，有大写、小写、数字
bool isPwdCorrect(char * pwd)
{
	bool isHasLower = false;
	bool isHasUpper = false;
	bool isHasNum = false;
	bool isHasSpecial = false;
	
	if (pwd != NULL)
	{
		for (int i = 0; pwd[i] != '\0'; ++i)
		{
			
			if (pwd[i] >= 'A' && pwd[i] <= 'Z')
			{
				isHasUpper = true;
			}
			if (pwd[i] >= 'a' && pwd[i] <= 'z')
			{
				isHasLower = true;
			}
			if (pwd[i] >= '0' && pwd[i] <= '9')
			{
				isHasNum = true;
			}
			if (pwd[i] == '!' || pwd[i] == '@' || pwd[i] == '#'|| pwd[i] == '$' || pwd[i] == '%' || pwd[i] == '&' || pwd[i] == '*' || pwd[i] == '(' || pwd[i] == ')')
			{
				isHasSpecial = true;
			}
			
		}
	}
	return (isHasNum && isHasUpper && isHasLower && isHasSpecial);
}

//获取正确的随机密码
char *getCorrectPwd(int length,int pwdType)
{
	char *pwd = getRandomStringPwd(length,pwdType);
	//while (!isPwdCorrect(pwd))
	//{
	//	if (pwd != NULL)
	//	{
	//		delete pwd;
	//		pwd = NULL;
	//	}
	//	pwd = getRandomStringPwd(length, pwdType);
	//}

	return pwd;
}
