#include <iostream>
#include <list>
#pragma warning(disable:4996)
using namespace std;

class Doctor
{
public:
	void TreatEye()
	{
		cout << "Doctor treats eyes" << endl;
	}
	void TreatNose()
	{
		cout << "Doctor treats nose" << endl;
	}
};

class Commond
{
public:
	virtual void Treat() = 0;
};

class CommondTreatEye : public Commond
{
public:
	CommondTreatEye(Doctor* doctor)
	{
		m_pDoctor = doctor;
	}
	void Treat()
	{
		m_pDoctor->TreatEye();
	}
private:
	Doctor* m_pDoctor;
};

class CommondTreatNose : public Commond
{
public:
	CommondTreatNose(Doctor* doctor)
	{
		m_pDoctor = doctor;
	}
	void Treat()
	{
		m_pDoctor->TreatNose();
	}
private:
	Doctor* m_pDoctor;
};

class Norse
{
public:
	Norse(Commond* commond)
	{
		m_commond = commond;
	}
	void SubmitCase()
	{
		m_commond->Treat();
	}
private:
	Commond* m_commond;
};

class HeadNorse
{
public:
	HeadNorse()
	{
		m_listCommond = new list<Commond*>;
	}
	~HeadNorse()
	{
		delete m_listCommond;
	}
	void SetCase(Commond* commond)
	{
		m_listCommond->push_back(commond);
	}
	void SubmitCase()
	{
		for (list<Commond*>::iterator it = m_listCommond->begin(); it != m_listCommond->end(); ++it)
		{
			(*it)->Treat();
		}
	}

private:
	list<Commond*>* m_listCommond;
};

int main()
{
	Doctor* doctor = new Doctor;
	Commond* commond1 = new CommondTreatEye(doctor);
	Commond* commond2 = new CommondTreatNose(doctor);
	Norse* nurse = new Norse(commond1);
	nurse->SubmitCase();

	cout << "---" << endl;
	HeadNorse* headNurse = new HeadNorse;
	headNurse->SetCase(commond1);
	headNurse->SetCase(commond2);
	headNurse->SubmitCase();

	delete doctor;
	delete commond1;
	delete commond2;
	delete nurse;
	delete headNurse;
	return 0;
}