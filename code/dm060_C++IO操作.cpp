/*
	1 编程实现以下数据输入/输出：
	(1)以左对齐方式输出整数,域宽为12。
	(2)以八进制、十进制、十六进制输入/输出整数。
	(3)实现浮点数的指数格式和定点格式的输入/输出,并指定精度。
	(4)把字符串读入字符型数组变量中,从键盘输入,要求输入串的空格也全部读入,以回车符结束。
	(5)将以上要求用流成员函数和操作符各做一遍。
	2编写一程序，将两个文件合并成一个文件。
	3编写一程序，统计一篇英文文章中单词的个数与行数。
	4编写一程序，将C++源程序每行前加上行号与一个空格。
	5编写一程序，输出 ASCII码值从20到127的ASCII码字符表，格式为每行10个。

*/

#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

int main01()
{
	/*第一题*/
	//流成员函数实现
	cout.setf(ios::left); //左对齐
	cout.width(12); //域宽
	cout.fill('*'); //填充字符
	cout << 26 << endl;
	cout.unsetf(ios::left); //用完要取消设定，否则会影响后面的输出

	int a = 10;
	cout.setf(ios::showbase); //显式的显示不同进制的表示
	cout.unsetf(ios::dec); //先消除默认输出，否则后面不起作用
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
	cout.setf(ios::fixed); //定点格式输出
	cout.precision(4); //设置小数精度
	cout << b << endl;
	cout.unsetf(ios::fixed);
	cout.setf(ios::scientific);
	cout << b << endl;
	cout.unsetf(ios::scientific);

	cout << "----分割线----" << endl;

	//操作符
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
	fout.open("TestFile\\dm60_2_file1.txt", ios::out); //输出的形式打开文件
	if (fout.fail())
	{
		cout << "打开文件失败" << endl;
		exit(1);
	}

	fout << "hello world\n";
	fout << "how are you\n";
	fout.close();

	fout.open("TestFile\\dm60_2_file2.txt", ios::out);
	if (!fout)
	{
		cout << "打开文件失败" << endl;
		exit(1);
	}

	fout << "my name is Mike" << endl;
	fout << "nice to meet you" << endl;
	fout.close();

	fout.open("TestFile/dm60_2_file.txt", ios::out);
	if (fout.fail())
	{
		cout << "打开文件失败" << endl;
		exit(1);
	}

	ifstream fin;
	fin.open("TestFile\\dm60_2_file1.txt", ios::in);
	if (fin.fail())
	{
		cout << "打开文件失败" << endl;
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
		cout << "打开文件失败" << endl;
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
	fFile.open("TestFile/dm60_3_art.txt", ios::in); //使用fstream时要指明打开方式
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