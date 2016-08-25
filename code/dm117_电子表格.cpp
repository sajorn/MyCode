#include <iostream>
#include <sstream> //�ַ���ת����
#include <string>
#include <memory>
#include <vector>
#pragma warning(disable:4996)
using namespace std;

//��Ԫ���࣬�洢һ�����ֻ�һ���ı�����
class SpreadsheetCell
{
public:
	SpreadsheetCell() = default;
	SpreadsheetCell(double initialValue);
	explicit SpreadsheetCell(string& str);
	~SpreadsheetCell();
public:
	void setValue(double inValue = 0);
	double getValue() const;
	void setString(string& str);
	const string& getString() const;

	void printCell(const SpreadsheetCell& inCell);

public:
	SpreadsheetCell operator+(const SpreadsheetCell& rhs);
	SpreadsheetCell operator+(const double dNum);
	friend SpreadsheetCell operator+(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);

	SpreadsheetCell operator-(const SpreadsheetCell& rhs);
	SpreadsheetCell operator-(const double dNum);
	friend SpreadsheetCell operator-(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);

	SpreadsheetCell operator*(const SpreadsheetCell& rhs);
	SpreadsheetCell operator*(const double dNum);
	friend SpreadsheetCell operator*(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);

	SpreadsheetCell operator/(const SpreadsheetCell& rhs);
	SpreadsheetCell operator/(const double dNum);
	friend SpreadsheetCell operator/(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);

	SpreadsheetCell& operator=(const SpreadsheetCell& rhs);

	SpreadsheetCell& operator+=(const SpreadsheetCell& rhs);
	SpreadsheetCell& operator+=(const double dNum);
	SpreadsheetCell& operator-=(const SpreadsheetCell& rhs);
	SpreadsheetCell& operator-=(const double dNum);
	SpreadsheetCell& operator*=(const SpreadsheetCell& rhs);
	SpreadsheetCell& operator*=(const double dNum);
	SpreadsheetCell& operator/=(const SpreadsheetCell& rhs);
	SpreadsheetCell& operator/=(const double dNum);

	bool operator==(const SpreadsheetCell& rhs);
	bool operator!=(const SpreadsheetCell& rhs);
	bool operator>(const SpreadsheetCell& rhs);
	bool operator<(const SpreadsheetCell& rhs);
	bool operator>=(const SpreadsheetCell& rhs);
	bool operator<=(const SpreadsheetCell& rhs);

private:
	//����ת�����������������Ϊstring�������ݾͻ�ת����double
	static string doubleToString(double inValue);
	static double stringTodouble(string& str);

private:
	double m_Value;
	string m_string;
	mutable int m_numAccesses = 0; //�����������const�������޸�,ֻ�����ηǾ�̬��Ա
};

SpreadsheetCell::SpreadsheetCell(double initialValue /* = 0*/)
{
	setValue(initialValue);
}

SpreadsheetCell::SpreadsheetCell(string& str) : SpreadsheetCell(stringTodouble(str))
{
	//ί�й��캯��������ͬһ�������һ�����캯������ʼ��
}

SpreadsheetCell::~SpreadsheetCell()
{
	
}

void SpreadsheetCell::setValue(double inValue)
{
	m_Value = inValue;
	m_string = doubleToString(m_Value);
}

double SpreadsheetCell::getValue() const
{
	m_numAccesses++;
	return m_Value;
}

void SpreadsheetCell::setString(string& str)
{
	m_string = str;
	m_Value = stringTodouble(m_string);
}

const string& SpreadsheetCell::getString() const
{
	m_numAccesses++;
	return m_string;
}

string SpreadsheetCell::doubleToString(double inValue)
{
	ostringstream ostr;
	ostr << inValue;
	return ostr.str();
}

double SpreadsheetCell::stringTodouble(string& str)
{
	double temp;
	istringstream istr(str);
	istr >> temp;
	if (istr.fail() || !istr.eof())
	{
		return 0;
	}
	return temp;
}

void SpreadsheetCell::printCell(const SpreadsheetCell& inCell)
{
	cout << inCell.getString() << endl;
}

SpreadsheetCell SpreadsheetCell::operator+(const SpreadsheetCell& rhs)
{
	SpreadsheetCell newCell;
	newCell.setValue(m_Value + rhs.m_Value);
	return newCell;
}

SpreadsheetCell SpreadsheetCell::operator+(const double dNum)
{
	return SpreadsheetCell(m_Value + dNum);
}

SpreadsheetCell operator+(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
	return SpreadsheetCell(lhs.m_Value + rhs.m_Value);
}

SpreadsheetCell SpreadsheetCell::operator-(const SpreadsheetCell& rhs)
{
	return SpreadsheetCell(m_Value - rhs.m_Value);
}

SpreadsheetCell SpreadsheetCell::operator-(const double dNum)
{
	return SpreadsheetCell(m_Value - dNum);
}

SpreadsheetCell operator-(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
	return SpreadsheetCell(lhs.m_Value - rhs.m_Value);
}

SpreadsheetCell SpreadsheetCell::operator*(const SpreadsheetCell& rhs)
{
	return SpreadsheetCell(m_Value * rhs.m_Value);
}

SpreadsheetCell SpreadsheetCell::operator*(const double dNum)
{
	return SpreadsheetCell(m_Value * dNum);
}

SpreadsheetCell operator*(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
	return SpreadsheetCell(lhs.m_Value * rhs.m_Value);
}

SpreadsheetCell SpreadsheetCell::operator/(const SpreadsheetCell& rhs)
{
	if (rhs.m_Value == 0)
	{
		throw invalid_argument("Divide by 0");
	}
	return SpreadsheetCell(m_Value / rhs.m_Value);
}

SpreadsheetCell SpreadsheetCell::operator/(const double dNum)
{
	if (dNum == 0)
	{
		throw invalid_argument("Divide by 0");
	}
	return SpreadsheetCell(m_Value / dNum);
}

SpreadsheetCell operator/(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
	if (rhs.m_Value == 0)
	{
		throw invalid_argument("Divide by 0");
	}
	return SpreadsheetCell(lhs.m_Value / rhs.m_Value);
}

SpreadsheetCell& SpreadsheetCell::operator=(const SpreadsheetCell& rhs)
{
	if (this == &rhs)
	{
		return *this; //�����Ը�ֵ
	}
	m_string = rhs.m_string;
	m_Value = rhs.m_Value;
	return *this;
}

SpreadsheetCell& SpreadsheetCell::operator+=(const SpreadsheetCell& rhs)
{
	m_Value = m_Value + rhs.m_Value;
	return *this;
}

SpreadsheetCell& SpreadsheetCell::operator+=(const double dNum)
{
	m_Value = m_Value + dNum;
	return *this;
}

SpreadsheetCell& SpreadsheetCell::operator-=(const SpreadsheetCell& rhs)
{
	m_Value = m_Value - rhs.m_Value;
	return *this;
}

SpreadsheetCell& SpreadsheetCell::operator-=(const double dNum)
{
	m_Value = m_Value - dNum;
	return *this;
}

SpreadsheetCell& SpreadsheetCell::operator*=(const SpreadsheetCell& rhs)
{
	m_Value = m_Value * rhs.m_Value;
	return *this;
}

SpreadsheetCell& SpreadsheetCell::operator*=(const double dNum)
{
	m_Value = m_Value * dNum;
	return *this;
}

SpreadsheetCell& SpreadsheetCell::operator/=(const SpreadsheetCell& rhs)
{
	m_Value = m_Value / rhs.m_Value;
	return *this;
}

SpreadsheetCell& SpreadsheetCell::operator/=(const double dNum)
{
	if (dNum == 0)
	{
		throw invalid_argument("Divide by 0");
	}
	m_Value = m_Value / dNum;
	return *this;
}

bool SpreadsheetCell::operator==(const SpreadsheetCell& rhs)
{
	return m_Value == rhs.m_Value;
}

bool SpreadsheetCell::operator!=(const SpreadsheetCell& rhs)
{
	return (m_Value != rhs.m_Value);
}

bool SpreadsheetCell::operator>(const SpreadsheetCell& rhs)
{
	return m_Value > rhs.m_Value;
}

bool SpreadsheetCell::operator<(const SpreadsheetCell& rhs)
{
	return m_Value < rhs.m_Value;
}

bool SpreadsheetCell::operator>=(const SpreadsheetCell& rhs)
{
	return m_Value >= rhs.m_Value;
}

bool SpreadsheetCell::operator<=(const SpreadsheetCell& rhs)
{
	return m_Value <= rhs.m_Value;
}

class SpreadsheetApplication; //Ӧ�ó�����

//���ӱ����
class Spreadsheet
{
public:
	//Spreadsheet(int inWeight, int inHeight, const SpreadsheetApplication& app);
	Spreadsheet(int inWeight, int inHeight);
	Spreadsheet(const Spreadsheet& rhs);
	~Spreadsheet();
public:
	//�ƶ����캯�����ƶ���ֵ�����
	Spreadsheet(Spreadsheet&& rhs) ;
	Spreadsheet& operator=(Spreadsheet&& rhs);

	void setCellAt(int x, int y, const SpreadsheetCell& cell);
	SpreadsheetCell& getCellAt(int x, int y);
	int getID() const;

public:
	Spreadsheet& operator=(const Spreadsheet& rhs);

private:
	void clearMemory(); //���������ڴ�
	void copyForm(const Spreadsheet& rhs); //���𿽱�����
	bool inRange(int val, int upper);
	int m_weight, m_height;
	SpreadsheetCell** m_cells;
	//const SpreadsheetApplication& m_app;

private:
	static int m_sCounter; //������
	int m_id;

public:
	//�ƶ���Ԫ��� ��Ⱥ͸߶�
	static const int m_kMaxHeight = 100;
	static const int m_kMaxWidth = 100;
};

Spreadsheet::Spreadsheet(int inWeight, int inHeight)
: m_weight(inWeight < m_kMaxWidth ? inWeight : m_kMaxWidth),
m_height(inHeight < m_kMaxHeight ? inHeight : m_kMaxHeight)//, m_app(0);
{
	m_id = m_sCounter++;
	m_cells = new SpreadsheetCell*[m_weight];
	for (int i = 0; i < m_weight; ++i)
	{
		m_cells[i] = new SpreadsheetCell[m_height];
	}
}


//Spreadsheet::Spreadsheet(int inWeight, int inHeight, const SpreadsheetApplication& app) 
//	: m_weight(inWeight < m_kMaxWidth ? inWeight : m_kMaxWidth), 
//	m_height(inHeight < m_kMaxHeight ? inHeight : m_kMaxHeight), m_app(app)
//{
//	m_id = m_sCounter++;
//	m_cells = new SpreadsheetCell*[m_weight];
//	for (int i = 0; i < m_weight; ++i)
//	{
//		m_cells[i] = new SpreadsheetCell[m_height];
//	}
//}

Spreadsheet::Spreadsheet(const Spreadsheet& rhs) //: m_app(rhs.m_app)
{
	m_id = m_sCounter++;
	copyForm(rhs);
}

Spreadsheet::~Spreadsheet()
{
	clearMemory();
}

Spreadsheet::Spreadsheet(Spreadsheet&& rhs) //: m_app(rhs.m_app)
{
	cout << "call &&" << endl;
	m_weight = rhs.m_weight;
	m_height = rhs.m_height;
	m_cells = rhs.m_cells;
	rhs.m_weight = 0;
	rhs.m_height = 0;
	rhs.m_cells = NULL;
}

void Spreadsheet::setCellAt(int x, int y, const SpreadsheetCell& cell)
{
	if (!inRange(x, m_weight) || !inRange(y, m_height))
	{
		throw out_of_range("out of range!");
	}
	m_cells[x][y] = cell;
}

SpreadsheetCell& Spreadsheet::getCellAt(int x, int y)
{
	if (!inRange(x, m_weight) || !inRange(y, m_height))
	{
		throw out_of_range("out of range!");
	}
	return m_cells[x][y];
}

Spreadsheet& Spreadsheet::operator=(const Spreadsheet& rhs)
{
	if (this == &rhs)
	{
		return *this;
	}

	clearMemory();

	copyForm(rhs);

	return *this;
}

Spreadsheet& Spreadsheet::operator=(Spreadsheet&& rhs)
{
	cout << "call &&=" << endl;
	if (this == &rhs)
	{
		return *this;
	}
	clearMemory();
	m_weight = rhs.m_weight;
	m_height = rhs.m_height;
	m_cells = rhs.m_cells;

	rhs.m_weight = 0;
	rhs.m_height = 0;
	rhs.m_cells = NULL;
	return *this;
}

void Spreadsheet::clearMemory()
{
	for (int i = 0; i < m_weight; ++i)
	{
		if (m_cells[i] != NULL)
		{
			delete[] m_cells[i];
		}
	}
	if (m_cells != NULL)
	{
		delete[] m_cells;
		m_cells = nullptr;
	}
}

void Spreadsheet::copyForm(const Spreadsheet& rhs)
{
	m_height = rhs.m_height;
	m_weight = rhs.m_weight;
	m_cells = new SpreadsheetCell*[m_weight];
	for (int i = 0; i < m_weight; ++i)
	{
		m_cells[i] = new SpreadsheetCell[m_height];
	}

	for (int i = 0; i < m_weight; ++i)
	{
		for (int j = 0; j < m_height; ++j)
		{
			m_cells[i][j] = rhs.m_cells[i][j];
		}
	}
}

bool Spreadsheet::inRange(int val, int upper)
{
	return true;
}

int Spreadsheet::m_sCounter = 0;

using MyInt = int; //�ȼ� typedef int MyInt
using Func = int(*)(int, int); //�ȼ�typedef int(*Func)(int, int);

int main()
{
	vector<Spreadsheet> vec;
	for (int i = 0; i < 2; ++i)
	{
		cout << "Iteration: " << i << endl;
		vec.push_back(Spreadsheet(100, 100));
		cout << endl;
	}
	constexpr int a = 5;
	Spreadsheet s(2, 3);
	s = Spreadsheet(3, 2);
	Spreadsheet s2(5, 6);
	s2 = s;
	return 0;
}