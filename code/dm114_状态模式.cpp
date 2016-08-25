#include <iostream>
#pragma warning(disable:4996)
using namespace std;

class Worker;

class State
{
public:
	virtual void DoWork(Worker* worker) = 0;
};

class Worker
{
public:
	Worker();
	
	void SetHour(int hour)
	{
		m_hour = hour;
	}
	int GetHour()
	{
		return m_hour;
	}
	void SetState(State* state)
	{
		m_state = state;
	}
	State* GetState()
	{
		return m_state;
	}
	void DoThing()
	{
		m_state->DoWork(this);
	}
private:
	int m_hour;
	State* m_state;
};

class State1 : public State
{
public:
	void DoWork(Worker* worker);
	
};

class State2 : public State
{
public:
	void DoWork(Worker* worker);
};

void State1::DoWork(Worker* worker)
{
	if (worker->GetHour() == 7)
	{
		cout << "Eat Breakfast" << endl;
	}
	else
	{
		delete worker->GetState();
		worker->SetState(new State2);
		worker->GetState()->DoWork(worker);
	}
}

void State2::DoWork(Worker* worker)
{
	if (worker->GetHour() == 9)
	{
		cout << "DoWork" << endl;
	}
	else
	{
		delete worker->GetState();
		worker->SetState(new State1);
		cout << "Nothing can do" << endl;
	}
}

Worker::Worker()
{
	m_state = new State1;
}

int main()
{
	Worker* worker = new Worker;
	worker->SetHour(9);
	worker->DoThing();
	worker->SetHour(8);
	worker->DoThing();
	worker->SetHour(9);
	worker->DoThing();

	return 0;
}