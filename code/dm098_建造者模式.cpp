#include <iostream>
#include <string>
using namespace std;

class CHouse
{
public:
	void SetDoor(const char* ch)
	{
		m_door = ch;
	}
	void SetWindow(const char* ch)
	{
		m_window = ch;
	}
	void SetWall(const char* ch)
	{
		m_wall = ch;
	}
	string GetDoor()
	{
		cout << "Door" << endl;
		return m_door;
	}
	string GetWindow()
	{
		cout << "Window" << endl;
		return m_window;
	}
	string GetWall()
	{
		cout << "Wall" << endl;
		return m_wall;
	}
private:
	string m_door;
	string m_window;
	string m_wall;
};

class CBuilder
{
public:
	virtual void BuildWindow() = 0;
	virtual void BuildDoor() = 0;
	virtual void BuildWall() = 0;
	virtual CHouse* GetHouse() = 0;
};

//公寓工程队
class CFlatBuilder : public CBuilder
{
public:
	CFlatBuilder() : m_pHouse(new CHouse){}
	void BuildWindow()
	{
		m_pHouse->SetWindow("Flat Window");
	}
	void BuildDoor()
	{
		m_pHouse->SetDoor("Flat Door");
	}
	void BuildWall()
	{
		m_pHouse->SetWall("Flat Wall");
	}
	CHouse* GetHouse()
	{
		return m_pHouse;
	}
private:
	CHouse* m_pHouse;
};

//别墅工程队
class CVilBuilder : public CBuilder
{
public:
	CVilBuilder() : m_pHouse(new CHouse){}
	void BuildWindow()
	{
		m_pHouse->SetWindow("Village Window");
	}
	void BuildDoor()
	{
		m_pHouse->SetDoor("Village Door");
	}
	void BuildWall()
	{
		m_pHouse->SetWall("Village Wall");
	}
	CHouse* GetHouse()
	{
		return m_pHouse;
	}
private:
	CHouse* m_pHouse;
};

//设计师
class CDesigner
{
public:
	CDesigner(CBuilder* builder)
	{
		m_pBuilder = builder;
	}
	void Construct()
	{
		m_pBuilder->BuildDoor();
		m_pBuilder->BuildWall();
		m_pBuilder->BuildWindow();
	}

private:
	CBuilder* m_pBuilder;
};

int main()
{
	CBuilder* builder = new CVilBuilder;
	CDesigner* designer = new CDesigner(builder);
	designer->Construct();

	CHouse* house = builder->GetHouse();
	cout << house->GetDoor() << endl;
	cout << house->GetWall() << endl;
	cout << house->GetWindow() << endl;
	return 0;
}