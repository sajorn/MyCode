/*
	某学校举行一场唱歌比赛，共有24个人参加，按参加顺序设置参赛号(参赛号为100至123)。
每个选手唱完一首歌之后，由10个评委分别打分。该选手的最终得分是去掉一个最高分和一个最低分，
求得剩下的8个评分的平均分。
	比赛共三轮，前两轮为淘汰赛，第三轮为决赛。选手的名次按得分降序排列，若得分一样，按参赛号升序排名。
第一轮分为4个小组，根据参赛号顺序依次划分，比如100-105为一组，106-111为第二组，依次类推，每组6个人，
每人分别按参赛号顺序演唱。当小组演唱完后，淘汰组内排名最后的三个选手，然后继续下一个小组的比赛。
	第二轮分为2个小组，每组6人，每个人分别按参赛号顺序演唱。当小组演唱完后，淘汰组内排名最后的三个选手，
然后继续下一个小组的比赛。第三轮只剩下6个人，本轮为决赛，不淘汰选手，本轮目的是赛出每个人的名次。
该6人按参赛号顺序分别演唱。

1. 请打印出所有选手的名字与参赛号，并以参赛号的升序排列。

2. 请打印出第1轮和第2轮淘汰赛中，各小组选手的名字与选手得分，并以名次的顺序排列。

3. 请打印出第1轮淘汰赛中被淘汰的歌手的名字(不要求打印顺序)。

4. 请打印出第2轮淘汰赛中被淘汰的歌手的分数，并以名次的降序排列。

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

string g_strSingerName = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; //26个选手随机选出24位

struct Singer
{
	string strName; //姓名
	int uScore; //得分
};

class CSingerGame
{
public:
	CSingerGame();

	void JoinGame(); //预选赛
	void FirstGame(); //第一轮淘汰
	void SecondGame(); //第二轮淘汰
	void Finals(); //决赛

private:
	map<int, Singer> m_mSingers; //参赛选手
	list<int> m_lSingersID; //记录没有淘汰歌手的ID
	multimap<int, int, greater<int>> m_mCurSingerScore; //记录该ID选手的分数
	vector<int> m_vOutSingers; //记录淘汰的选手
	multiset<int> m_sSecondSingerScore; //记录第二次淘汰选手的分数

	int m_iRound; //第几轮比赛
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
		singer.strName = "选手";
		singer.strName += g_strSingerName[i];
		singer.uScore = 0;
		m_mSingers.insert(pair<int, Singer>(i + 100, singer)); //插入选手
		m_lSingersID.push_back(i + 100); //插入选手ID
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
