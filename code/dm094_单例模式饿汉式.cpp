#include <iostream>
using namespace std;

class CSampleton
{
private:
	CSampleton() //1.����˽�еĹ��캯��
	{
		;
	}

public:
	static CSampleton* ReturnSample() //�ṩȫ�ַ���
	{
		if (sample == NULL) //��ֻ֤��һ��ʵ����
		{
			sample = new CSampleton;
		}
		return sample;
	}

private:
	static CSampleton* sample; //�ṩһ��˽��ʵ����ָ�����
};

CSampleton* CSampleton::sample = NULL; //��̬��Ա��ʼ��
//CSampleton* CSampleton::sample = new CSampleton; //����ʽ���ܱ��ⵥ��ģʽ�Ķ��߳�����
int main()
{
	CSampleton* s1 = CSampleton::ReturnSample();
	CSampleton* s2 = CSampleton::ReturnSample();
	if (s1 == s2)
	{
		cout << "Equal" << endl;
	}
	else
	{
		cout << "Not Equal" << endl;
	}
	return 0;
}