/* ��װ�Լ���������������CIntArray*/

#include <iostream>
#pragma warning (disable:4996)
using namespace std;

class CIntArray{
public:
	CIntArray(int nLen = 0);
	CIntArray(CIntArray& cIntArr);
	~CIntArray();
	int GetLen() {	return m_len;	}

	//�쳣������
	class eSize
	{
	public:
		eSize(int size)
		{
			m_size = size;
		}
		int GetSize()
		{
			return m_size;
		}
		virtual void PrintErr() = 0;
	private:
		int m_size;
	};

	//С��0
	class eLessZero :public eSize
	{
	public:
		eLessZero(int size) :eSize(size)
		{
			;
		}
		void PrintErr()
		{
			cout << "����С��0�� size = " << GetSize() << endl;
		}
	};

	//����0
	class eZero :public eSize
	{
	public:
		eZero(int size) :eSize(size)
		{
			;
		}
		void PrintErr()
		{
			cout << "���ȵ���0�� size = " << GetSize() << endl;
		}
	};

	//����̫��
	class eBigSize :public eSize
	{
	public:
		eBigSize(int size) :eSize(size)
		{
			;
		}
		void PrintErr()
		{
			cout << "����̫���� size = " << GetSize() << endl;
		}
	};

	//����̫��
	class eSmallSize :public eSize
	{
	public:
		eSmallSize(int size) :eSize(size)
		{
			;
		}
		void PrintErr()
		{
			cout << "����̫��, size = " << GetSize() << endl;
		}
	};

	int& operator[](int nIndex); //[]����
	CIntArray& operator=(CIntArray& cIntArr); //��ֵ���������

	//+ - * /
	CIntArray operator+(int nValue); 
	CIntArray operator-(int nValue);
	CIntArray operator*(int nValue);
	CIntArray operator/(int nValue);
	friend CIntArray operator+(int nValue, CIntArray& cIntArr);
	friend CIntArray operator-(int nValue, CIntArray& cIntArr);
	friend CIntArray operator*(int nValue, CIntArray& cIntArr);
	friend CIntArray operator/(int nValue, CIntArray& cIntArr);

	//++ --
	CIntArray& operator++(); //++a a.operator++(); ǰ��++
	CIntArray& operator--(); //--a a.operator--(); ǰ��--
	friend CIntArray operator++(CIntArray& cIntArr, int); //a++
	friend CIntArray operator--(CIntArray& cIntArr, int); //a--

	//+= -= *= /=
	CIntArray& operator+=(int nValue); // a += b += c
	CIntArray& operator-=(int nValue);
	CIntArray& operator*=(int nValue);
	CIntArray& operator/=(int nValue);

	//== != 
	bool operator==(CIntArray& cIntArr);
	bool operator!=(CIntArray& cIntArr);

	//>> <<
	friend ostream& operator<<(ostream& os, CIntArray& cIntArr); //������������
	friend istream& operator>>(istream& is, CIntArray& cIntArr); //�������������

private:
	int m_len; //����ĳ���
	int* m_pArr; //�洢�����ָ��
};

CIntArray::CIntArray(int nLen)
{
	m_len = nLen;
	if (m_len < 0)
	{
		throw eLessZero(m_len);
	}
	else if (m_len == 0)
	{
		throw eZero(m_len);
	}
	else if (m_len < 2)
	{
		throw eSmallSize(m_len);
	}
	else if (m_len > 1000)
	{
		throw eBigSize(m_len);
	}

	else
	{
		m_pArr = new int[m_len];
	}
}

CIntArray::CIntArray(CIntArray& cIntArr)
{
	m_len = cIntArr.m_len;
	m_pArr = new int[m_len];

	for (int i = 0; i < m_len; ++i)
	{
		m_pArr[i] = cIntArr.m_pArr[i];
	}
}

CIntArray::~CIntArray()
{
	if (m_pArr)
	{
		delete m_pArr;
	}
	m_len = 0;
}

int& CIntArray::operator[](int nIndex)
{
	if (nIndex < 0)
	{
		throw eLessZero(nIndex);
	}
	else if (nIndex == 0)
	{
		throw eZero(nIndex);
	}
	else if (nIndex < 2)
	{
		throw eSmallSize(nIndex);
	}
	else if (nIndex > 1000)
	{
		throw eBigSize(nIndex);
	}
	else
	{
		return m_pArr[nIndex];
	}
}

CIntArray& CIntArray::operator=(CIntArray& cIntArr)
{
	if (this == &cIntArr)
	{
		return *this;
	}
	delete[] m_pArr;

	m_len = cIntArr.m_len;
	m_pArr = new int[m_len];
	for (int i = 0; i < m_len; ++i)
	{
		m_pArr[i] = cIntArr.m_pArr[i];
	}
	return *this;
}

CIntArray CIntArray::operator+(int nValue)
{
	CIntArray cTmp(*this);

	for (int i = 0; i < m_len; ++i)
	{
		cTmp.m_pArr[i] += nValue;
	}

	return cTmp;
}

CIntArray operator+(int nValue, CIntArray& cIntArr)
{
	CIntArray cTmp(cIntArr);
	int nLen = cIntArr.GetLen();
	cTmp = cTmp + nValue;
	return cTmp;
}

CIntArray CIntArray::operator-(int nValue)
{
	CIntArray cTmp(*this);
	for (int i = 0; i < cTmp.GetLen(); ++i)
	{
		cTmp.m_pArr[i] -= nValue;
	}
	return cTmp;
}

CIntArray operator-(int nValue, CIntArray& cIntArr)
{
	CIntArray cTmp(cIntArr);
	for (int i = 0; i < cTmp.GetLen(); ++i)
	{
		cTmp.m_pArr[i] = nValue - cTmp.m_pArr[i];
	}
	return cTmp;
}

CIntArray CIntArray::operator*(int nValue)
{
	CIntArray cTmp(*this);
	for (int i = 0; i < cTmp.GetLen(); ++i)
	{
		cTmp.m_pArr[i] *= nValue;
	}
	return cTmp;
}

CIntArray operator*(int nValue, CIntArray& cIntArr)
{
	CIntArray cTmp(cIntArr);
	cTmp = cTmp * nValue;
	return cTmp;
}

CIntArray CIntArray::operator/(int nValue)
{
	if (nValue == 0)
	{
		cout << "��������Ϊ0" << endl;
		return *this;
	}

	CIntArray cTmp(*this);
	for (int i = 0; i < cTmp.GetLen(); ++i)
	{
		cTmp.m_pArr[i] /= nValue;
	}
	return cTmp;
}

CIntArray operator/(int nValue, CIntArray& cIntArr)
{
	//�ж������ÿһ��Ԫ����û��0�������쳣�˳�
	for (int i = 0; i < cIntArr.GetLen(); ++i)
	{
		if (cIntArr.m_pArr[i] == 0)
		{
			cout << "���ڳ���Ϊ0�Ĳ���" << endl;
			return cIntArr;
		}
	}

	CIntArray cTmp(cIntArr);
	for (int i = 0; i < cIntArr.GetLen(); ++i)
	{
		cTmp.m_pArr[i] = nValue / cTmp.m_pArr[i];
	}
	return cTmp;
}

CIntArray& CIntArray::operator++()
{
	for (int i = 0; i < m_len; ++i)
	{
		m_pArr[i]++;
	}
	return *this;
}

CIntArray& CIntArray::operator--()
{
	for (int i = 0; i < m_len; ++i)
	{
		m_pArr[i]--;
	}
	return *this;
}

CIntArray operator++(CIntArray& cIntArr, int)
{
	CIntArray cTmp(cIntArr);
	++cIntArr;
	return cTmp;
}

CIntArray operator--(CIntArray& cIntArr, int)
{
	CIntArray cTmp(cIntArr);
	--cIntArr;
	return cTmp;
}

CIntArray& CIntArray::operator+=(int nValue)
{
	(*this) = (*this) + nValue;
	return *this;
}

CIntArray& CIntArray::operator-=(int nValue)
{
	(*this) = (*this) - nValue;
	return *this;
}

CIntArray& CIntArray::operator*=(int nValue)
{
	(*this) = (*this) * nValue;
	return *this;
}

CIntArray& CIntArray::operator/=(int nValue)
{
	(*this) = (*this) / nValue;
	return *this;
}

bool CIntArray::operator==(CIntArray& cIntArr)
{
	if (m_len != cIntArr.GetLen())
	{
		return false;
	}
	for (int i = 0; i < cIntArr.GetLen(); ++i)
	{
		if (m_pArr[i] != cIntArr.m_pArr[i])
		{
			return false;
		}
	}

	return true;
}

bool CIntArray::operator!=(CIntArray& cIntArr)
{
	if ((*this) == cIntArr)
	{
		return false;
	}
	return true;
}

ostream& operator<<(ostream& os, CIntArray& cIntArr)
{
	int nLen = cIntArr.GetLen();
	for (int i = 0; i < nLen; ++i)
	{
		os << cIntArr.m_pArr[i] << " ";
	}
	return os;
}

istream& operator>>(istream& is, CIntArray& cIntArr)
{
	int nLen = cIntArr.GetLen();
	for (int i = 0; i < nLen; ++i)
	{
		is >> cIntArr.m_pArr[i];
	}
	return is;
}

int main()
{
	try
	{
		CIntArray a1(1234);
		cout << "Input array: ";
		cin >> a1;
		CIntArray a2(a1 + 2);
		if (a1 == a2)
		{
			cout << "���" << endl;
		}
		else
		{
			cout << "����" << endl;
		}
	}
	catch (CIntArray::eLessZero& e)
	{
		e.PrintErr();
	}
	catch (CIntArray::eZero& e)
	{
		e.PrintErr();
	}
	catch (CIntArray::eSmallSize& e)
	{
		e.PrintErr();
	}
	catch (CIntArray::eBigSize& e)
	{
		e.PrintErr();
	}
	catch (...)
	{
		cout << "δ֪����" << endl;
	}
	return 0;
}