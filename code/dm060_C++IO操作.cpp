/*
	1 ���ʵ��������������/�����
	(1)������뷽ʽ�������,���Ϊ12��
	(2)�԰˽��ơ�ʮ���ơ�ʮ����������/���������
	(3)ʵ�ָ�������ָ����ʽ�Ͷ����ʽ������/���,��ָ�����ȡ�
	(4)���ַ��������ַ������������,�Ӽ�������,Ҫ�����봮�Ŀո�Ҳȫ������,�Իس���������
	(5)������Ҫ��������Ա�����Ͳ���������һ�顣
	2��дһ���򣬽������ļ��ϲ���һ���ļ���
	3��дһ����ͳ��һƪӢ�������е��ʵĸ�����������
	4��дһ���򣬽�C++Դ����ÿ��ǰ�����к���һ���ո�
	5��дһ������� ASCII��ֵ��20��127��ASCII���ַ�����ʽΪÿ��10����

*/

#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

int main01()
{
	/*��һ��*/
	//����Ա����ʵ��
	cout.setf(ios::left); //�����
	cout.width(12); //���
	cout.fill('*'); //����ַ�
	cout << 26 << endl;
	cout.unsetf(ios::left); //����Ҫȡ���趨�������Ӱ���������

	int a = 10;
	cout.setf(ios::showbase); //��ʽ����ʾ��ͬ���Ƶı�ʾ
	cout.unsetf(ios::dec); //������Ĭ�������������治������
	cout.setf(ios::hex);
	cout << a << ", ";
	cout.unsetf(ios::hex);
	cout.setf(ios::oct);
	cout << a << ", ";
	cout.unsetf(ios::oct);
	cout.setf(ios::dec);
	cout << a << endl;
	cout.unsetf(ios::showbase);

	double b = 3.1415926585;
	cout.setf(ios::fixed); //�����ʽ���
	cout.precision(4); //����С������
	cout << b << endl;
	cout.unsetf(ios::fixed);
	cout.setf(ios::scientific);
	cout << b << endl;
	cout.unsetf(ios::scientific);

	cout << "----�ָ���----" << endl;

	//������
	cout << setiosflags(ios::left) << setw(12) << setfill('*') << 25 << endl;
	cout << resetiosflags(ios::dec);
	cout << setiosflags(ios::hex) << a << resetiosflags(ios::hex) << ", " <<
		setiosflags(ios::oct) << a << resetiosflags(ios::oct) << ", " <<
		setiosflags(ios::dec) << a << endl;

	cout << setiosflags(ios::fixed) << setprecision(6) << b << resetiosflags(ios::fixed)
		<< setiosflags(ios::scientific) << b << endl;

	char buf[100];
	cin.getline(buf, strlen(buf), '\n');
	cout << buf << ", buflen = " << strlen(buf) << endl;

	return 0;
}

int main02()
{
	ofstream fout;
	fout.open("TestFile\\dm60_2_file1.txt", ios::out); //�������ʽ���ļ�
	if (fout.fail())
	{
		cout << "���ļ�ʧ��" << endl;
		exit(1);
	}

	fout << "hello world\n";
	fout << "how are you\n";
	fout.close();

	fout.open("TestFile\\dm60_2_file2.txt", ios::out);
	if (!fout)
	{
		cout << "���ļ�ʧ��" << endl;
		exit(1);
	}

	fout << "my name is Mike" << endl;
	fout << "nice to meet you" << endl;
	fout.close();

	fout.open("TestFile/dm60_2_file.txt", ios::out);
	if (fout.fail())
	{
		cout << "���ļ�ʧ��" << endl;
		exit(1);
	}

	ifstream fin;
	fin.open("TestFile\\dm60_2_file1.txt", ios::in);
	if (fin.fail())
	{
		cout << "���ļ�ʧ��" << endl;
		exit(1);
	}

	char ch;
	while (fin.get(ch))
	{
		fout << ch;
	}
	fin.close();
	fin.open("TestFile\\dm60_2_file2.txt", ios::in);
	if (!fin)
	{
		cout << "���ļ�ʧ��" << endl;
		exit(1);
	}

	while (fin.get(ch))
	{
		fout << ch;
	}
	fin.close();
	cout << "done" << endl;
	return 0;
}

bool IsAlph(char c){
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

int main()
{
	ifstream fFile;
	fFile.open("TestFile/dm60_3_art.txt", ios::in); //ʹ��fstreamʱҪָ���򿪷�ʽ
	if (fFile.fail())
	{
		cout << "Error\n";
		exit(1);
	}
	char chTmp[1024];
	bool isWord;
	unsigned cWords = 0;
	unsigned cLines = 0;
	while (!fFile.eof())
	{
		fFile.getline(chTmp, sizeof(chTmp));
		cLines++;
		int i = 0;
		while (chTmp[i] != 0){
			if (!IsAlph(chTmp[i]))
				isWord = false;
			else if (IsAlph(chTmp[i]) && isWord == false){
				cWords++;
				isWord = true;
			}
			i++;
		}
	}
	cout << "Words: " << cWords << endl;
	cout << "Lines: " << cLines << endl;
	fFile.close();
	return 0;
}