#define _SCL_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	//初始化
	string s1 = "abcdefg";
	string s2("abcdabcd");
	string s3(10, 'a');
	
	//遍历
	for (unsigned i = 0; i < s1.length(); ++i)
	{
		cout << s1[i] << " "; //不会抛出异常
	}
	cout << endl;

	try
	{
		for (unsigned i = 0; i < s1.length() + 1; ++i)
		{
			cout << s1.at(i) << " "; //等同于s1[i],但是会抛出异常
		}
		cout << endl;
	}
	catch (...)
	{
		cout << "数组越界" << endl;
	}

	//迭代器方式遍历
	for (string::iterator it = s3.begin(); it != s3.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	//string --> char*
	const char* pStr = s3.c_str();
	cout << pStr << endl;

	//拷贝
	char buf[64] = { 0 };
	s1.copy(buf, 2, 0); //从0号位置开始，拷贝2个元素到buf数组里面
	cout << buf << endl;

	//赋值
	cout << "-----" << endl;
	const char* pChName = "abcd1234";
	string str1;
	str1.assign(pChName);
	cout << "str1 = " << str1 << endl;
	str1.assign(pChName, 5); //将前5个字符拷贝给str
	cout << "str1 = " << str1 << endl;
	str1.assign(s1); //把string字符串拷贝过去
	cout << "str1 = " << str1 << endl;
	str1.assign(s1, 0, 5); //拷贝5个字符串过去
	cout << "str1 = " << str1 << endl;
	str1.assign(5, 'c'); //用n个字符c去操作
	cout << "str1 = " << str1 << endl;
	cout << "-----" << endl;

	//连接
	string s5 = "aaa";
	string s6 = "bbb";
	s5.append(s6); //连接两个字符串 等同于:s5 = s5 + s6;
	cout << s5 << endl;

	//字符串的比较
	cout << "----" << endl;
	int n = str1.compare(s5); // =1 比它大 , =0 相等 =-1 比它小
	if (n == 0)
	{
		cout << "str1 == s5" << endl;
	}
	else if (n == 1)
	{
		cout << "str1 > s5" << endl;
	}
	else
	{
		cout << "str1 < s5" << endl;
	}

	cout << "----" << endl;
	//寻找子串
	cout << "--寻找子串" << endl;
	string str2 = "abcdefghijklmn";
	string sTmp = str2.substr(3, 7);
	cout << "sTmp = " << sTmp << endl;
	cout << endl;

	//查找字符串下标, 统计子串出现的次数 rfind是反向查找用法一样
	string s7 = "aayj 111 yj asdkh qwehjqyjqwe 132yj";
	unsigned unIndex = s7.find("yj", 0); //从下标0开始找
	while (unIndex != string::npos)
	{
		cout << unIndex << endl;
		unIndex += strlen("yj");
		unIndex = s7.find("yj", unIndex); //如果没找到对应的字符串，则返回npos
	}

	//替换上一个字符串的子串
	unIndex = s7.find("yj", 0);
	while (unIndex != string::npos)
	{
		s7.replace(unIndex, strlen("yj"), "YJ");
		unIndex += strlen("yj");
		unIndex = s7.find("yj", unIndex);
	}
	cout << s7 << endl;

	//删除某一区间和整个字符串
	string s8 = "hello world";
	string::iterator it = find(s8.begin(), s8.end(), 'o');
	if (it != s8.end())
	{
		s8.erase(it);
	}
	cout << s8 << endl;
	s8.erase(s8.begin(), s8.end() - 1);
	cout << s8 << endl;

	//插入字符串
	string s9 = "BBB";
	s9.insert(0, "aaa"); //头插法
	s9.insert(s9.length(), "ccc"); //尾插法
	cout << s9 << endl;

	//string算法 全部变大写全部变小写
	string s10 = "abcdABCD";
	transform(s10.begin(), s10.end(), s10.begin(), toupper); 
	//第一二个参数表示从哪里到哪里转换，第三个参数表示转换后的结果存放的位置，
	//第四个参数表示调用的函数或者函数入口的地址
	cout << s10 << endl;
	transform(s10.begin(), s10.end(), s10.begin(), tolower);
	cout << s10 << endl;
	return 0;
}