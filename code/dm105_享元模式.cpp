#include <iostream>
#include <map>
#include <string>
#pragma warning(disable:4996)
using namespace std;

class Person 
{
public:
	Person(string name, int age)
	{
		m_name = name;
		m_age = age;
	}
private:
	string m_name;
	int m_age;
};

class Teacher : public Person
{
public:
	Teacher(string name, int age, int id) : Person(name, age)
	{
		m_id = id;
	}
private:
	int m_id;
};

class TeacherFactory
{
public:
	TeacherFactory()
	{
		m_map.clear();
	}
	~TeacherFactory()
	{
		while (!m_map.empty())
		{
			Person* tmp = NULL;
			map<int, Person*>::iterator it = m_map.begin();
			tmp = it->second;
			m_map.erase(it);
			delete tmp;
		}
	}

	Person* GetTeacher(int id)
	{
		map<int, Person*>::iterator it;
		Person* tmp = NULL;
		it = m_map.find(id);
		if (it == m_map.end())
		{
			string name;
			cout << "Name: ";
			cin >> name;
			int age;
			cout << "Age: ";
			cin >> age;
			tmp = new Teacher(name, age, id);
			m_map.insert(pair<int, Person*>(id, tmp));
		}
		else
		{
			tmp = it->second;
		}
		return tmp;
	}
private:
	map<int, Person*> m_map;
};

int main()
{
	Person* p1 = NULL;
	Person* p2 = NULL;
	TeacherFactory* tFactory = new TeacherFactory;
	p1 = tFactory->GetTeacher(1);
	p2 = tFactory->GetTeacher(1);
	delete tFactory;
	return 0;
}