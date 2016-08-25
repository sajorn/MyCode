#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <cctype>
using namespace std;

template <typename T>
class ShowElem
{
public:
	void operator()(T& t)
	{
		cout << t << " ";
	}
};

template <typename T>
bool SortElem(const T& a, const T& b)
{
	return a > b;
}

class FindAndSortElem
{
public:
	bool operator()(const string& s1, const string& s2)
	{
		string tmpStr1;
		tmpStr1.resize(s1.size()); //重新分配空间大小
		transform(s1.begin(), s1.end(), tmpStr1.begin(), tolower); //将s1的字符串变成小写字母

		string tmpStr2;
		tmpStr2.resize(s2.size());
		transform(s2.begin(), s2.end(), tmpStr2.begin(), tolower);

		return (tmpStr1 > tmpStr2);
	}
};

int main()
{
	vector<int> v1;
	int nTmp;
	for (unsigned i = 0; i < 10; ++i)
	{
		nTmp = rand() % 10;
		v1.push_back(nTmp);
	}

	for_each(v1.begin(), v1.end(), ShowElem<int>());
	cout << endl;

	sort(v1.begin(), v1.end(), SortElem<int>);

	for_each(v1.begin(), v1.end(), ShowElem<int>());
	cout << endl;

	cout << "-----分割线-----" << endl;

	set<string, FindAndSortElem> s1; //不区分大小写的查找
	s1.insert("bbb");
	s1.insert("ccc");
	s1.insert("aaa");

	set<string, FindAndSortElem>::iterator it = s1.find("aAa");

	if (it == s1.end())
	{
		cout << "没有查找到aAa" << endl;
	}
	else
	{
		cout << "查找到aAa" << endl;
	}

	return 0;
}