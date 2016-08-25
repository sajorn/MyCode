#ifndef _TARRAY_H_
#define _TARRAY_H_
#include <iostream>
using namespace std;

template <typename T>
class TArray
{
public:
	TArray();
	TArray(const unsigned len);
	TArray(TArray& refArr);
	~TArray();
	int GetLen()
	{
		return m_len;
	}

	//[] = 
	T& operator[](unsigned len);
	TArray& operator=(TArray& refArr);

	//<< >>
	friend ostream &operator<< <T>(ostream& os, TArray& refArr);
	friend istream& operator>> <T>(istream& is, TArray& refArr);

private:
	T* m_arr;
	unsigned m_len;
};

template <typename T>
TArray<T>::TArray()
{
	m_len = 0;
	m_arr = nullptr;
}

template <typename T>
TArray<T>::TArray(const unsigned len)
{
	m_len = len;
	m_arr = new T[m_len];
}

template <typename T>
TArray<T>::TArray(TArray<T>& refArr)
{
	m_len = refArr.GetLen();
	m_arr = new T[m_len];
	for (int i = 0; i < m_len; ++i)
	{
		m_arr[i] = refArr.m_arr[i];
	}
}

template <typename T>
TArray<T>::~TArray()
{
	m_len = 0;
	if (m_arr != nullptr)
	{
		delete[] m_arr;
		m_arr = nullptr;
	}
}

//[] = 
template <typename T>
T& TArray<T>::operator[](unsigned len)
{
	if (m_len <= len)
	{
		cout << "数组越界" << endl;
		return m_arr[0];
	}
	return m_arr[len];
}

template <typename T>
TArray<T>& TArray<T>::operator=(TArray<T>& refArr)
{
	m_len = refArr.GetLen();
	if (m_arr != nullptr)
	{
		delete[] m_arr;
		m_arr = nullptr;
	}
	m_arr = new T[m_len];
	for (unsigned i = 0; i < refArr.m_len; ++i)
	{
		m_arr[i] = refArr.m_arr[i];
	}
	return *this;
}

//<< >>
template <typename T>
ostream& operator<<(ostream& os, TArray<T>& refArr)
{
	for (unsigned i = 0; i < refArr.m_len; ++i)
	{
		os << refArr.m_arr[i] << " ";
	}
	return os;
}

template <typename T>
istream& operator>>(istream& is, TArray<T>& refArr)
{
	for (int i = 0; i < refArr.GetLen(); ++i)
	{
		is >> refArr.m_arr[i];
	}
	return is;
}

#endif