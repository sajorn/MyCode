/*
	ĳѧУ����һ���������������24���˲μӣ����μ�˳�����ò�����(������Ϊ100��123)��
ÿ��ѡ�ֳ���һ�׸�֮����10����ί�ֱ��֡���ѡ�ֵ����յ÷���ȥ��һ����߷ֺ�һ����ͷ֣�
���ʣ�µ�8�����ֵ�ƽ���֡�
	���������֣�ǰ����Ϊ��̭����������Ϊ������ѡ�ֵ����ΰ��÷ֽ������У����÷�һ����������������������
��һ�ַ�Ϊ4��С�飬���ݲ�����˳�����λ��֣�����100-105Ϊһ�飬106-111Ϊ�ڶ��飬�������ƣ�ÿ��6���ˣ�
ÿ�˷ֱ𰴲�����˳���ݳ�����С���ݳ������̭����������������ѡ�֣�Ȼ�������һ��С��ı�����
	�ڶ��ַ�Ϊ2��С�飬ÿ��6�ˣ�ÿ���˷ֱ𰴲�����˳���ݳ�����С���ݳ������̭����������������ѡ�֣�
Ȼ�������һ��С��ı�����������ֻʣ��6���ˣ�����Ϊ����������̭ѡ�֣�����Ŀ��������ÿ���˵����Ρ�
��6�˰�������˳��ֱ��ݳ���

1. ���ӡ������ѡ�ֵ�����������ţ����Բ����ŵ��������С�

2. ���ӡ����1�ֺ͵�2����̭���У���С��ѡ�ֵ�������ѡ�ֵ÷֣��������ε�˳�����С�

3. ���ӡ����1����̭���б���̭�ĸ��ֵ�����(��Ҫ���ӡ˳��)��

4. ���ӡ����2����̭���б���̭�ĸ��ֵķ������������εĽ������С�

*/

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
#include <functional>
#include <string>
#include <ctime>

using namespace std;

string g_strSingerName = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; //26��ѡ�����ѡ��24λ

struct Singer
{
	string strName; //����
	int uScore; //�÷�
};

class CSingerGame
{
public:
	CSingerGame();

	void JoinGame(); //Ԥѡ��
	void FirstGame(); //��һ����̭
	void SecondGame(); //�ڶ�����̭
	void Finals(); //����

private:
	map<int, Singer> m_mSingers; //����ѡ��
	list<int> m_lSingersID; //��¼û����̭���ֵ�ID
	multimap<int, int, greater<int>> m_mCurSingerScore; //��¼��IDѡ�ֵķ���
	vector<int> m_vOutSingers; //��¼��̭��ѡ��
	multiset<int> m_sSecondSingerScore; //��¼�ڶ�����̭ѡ�ֵķ���

	int m_iRound; //�ڼ��ֱ���
};

CSingerGame::CSingerGame()
{
	m_iRound = 0;
	srand(time(0));
}

void CSingerGame::JoinGame()
{
	random_shuffle(g_strSingerName.begin(), g_strSingerName.end());

	Singer singer;

	for (int i = 0; i < 24; ++i)
	{
		singer.strName = "ѡ��";
		singer.strName += g_strSingerName[i];
		singer.uScore = 0;
		m_mSingers.insert(pair<int, Singer>(i + 100, singer)); //����ѡ��
		m_lSingersID.push_back(i + 100); //����ѡ��ID
	}

	for (map<int, Singer>::iterator it = m_mSingers.begin(); it != m_mSingers.end(); ++it)
	{
		cout << "ID: " << it->first << ", Name: " << it->second.strName << endl;
	}

}

void CSingerGame::FirstGame()
{
	m_iRound = 1;

}

int main()
{
	CSingerGame game;
	game.JoinGame();
	game.FirstGame();
	game.SecondGame();
	game.Finals();
	return 0;
}
