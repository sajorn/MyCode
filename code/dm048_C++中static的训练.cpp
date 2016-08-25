/*
	ĳ�̵꾭��һ�ֻ�����ﹺ��������ʱ����Ϊ��λ�������������һ����
	��ˣ��̵���Ҫ��¼Ŀǰ������������������C++ģ���̵���ﹺ���������������
*/

#include <iostream>

using namespace std;

class Good{
public:
	Good(double weight)
	{
		weight_ = weight;
		tWeight_ += weight_;
	}
	~Good()
	{
		tWeight_ -= weight_;
	}
	static double GetTWeight()
	{
		return tWeight_;
	}
	Good* next; //������¼��Ʒ�ƶ���λ��
private:
	double weight_; //���ι������۵�������
	static double tWeight_; //��¼��Ʒ��������

};

double Good::tWeight_ = 0.0;

void BuyGood(Good* &f, Good* &r, double weight)
{
	Good* pGood = new Good(weight);
	pGood->next = nullptr;
	if (f == nullptr)
	{
		f = r = pGood;
	}
	else
	{
		r->next = pGood;
		r = r->next;
	}
}

void SaleGood(Good* &f, Good* &r)
{
	if (f == nullptr)
	{
		cout << "No Goods" << endl;
	}
	else
	{
		Good* tmp = f;
		f = f->next;
		delete tmp;
	}
}

int main()
{
	Good* front = nullptr; 
	Good* rear = nullptr;
	cout << "Input your choice: 1.BUY 2.SALE 0.QUIT" << endl;
	char choice;

	while (1)
	{
		cin >> choice;
		switch (choice)
		{
		case '1':
			cout << "Input your weight: " << endl;
			double weight;
			cin >> weight;
			BuyGood(front, rear, weight);
			cout << "Buy Successful! Now Total Weight: " << Good::GetTWeight() << endl;
			break;
		case '2':
			SaleGood(front, rear);
			cout << "Sale Successful! Now Total Weight: " << Good::GetTWeight() << endl;
			break;
		default:
			return 0;
		}
	}

	return 0;
}