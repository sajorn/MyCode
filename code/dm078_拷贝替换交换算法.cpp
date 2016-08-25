#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

void PrintVector(vector<int> &v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}

bool Great(int n)
{
	return n > 3;
}

int main()
{
	vector<int> v1, v2, v3;
	for (unsigned i = 0; i < 5; ++i)
	{
		v1.push_back(i * 2);
		v2.push_back(i * 2 + 1);
	}
	cout << "v1: ";
	PrintVector(v1);
	cout << "v2: ";
	PrintVector(v2);
	//����
	v3.resize(v1.size());
	copy(v1.begin(), v1.end(), v3.begin());
	cout << "v3: ";
	PrintVector(v3);

	//�滻
	replace(v1.begin(), v1.end(), 2, 3);
	cout << "v1: ";
	PrintVector(v1);
	//ͨ�������滻
	replace_if(v2.begin(), v2.end(), Great, 3);
	cout << "v2: ";
	PrintVector(v2);

	//����
	swap(v1, v2);
	cout << "v1: ";
	PrintVector(v1);
	cout << "v2: ";
	PrintVector(v2);
	return 0;
}
