#include <iostream>
#include <string>
#include <list>
using namespace std;

class IFile
{
public:
	virtual void display() = 0;
	virtual int add(IFile* iFile) = 0;
	virtual int remove(IFile* iFile) = 0;
	virtual list<IFile*>* getChild() = 0;
};

//file node
class File : public IFile
{
public:
	File(string name)
	{
		m_name = name;
	}
	void display()
	{
		cout << m_name << endl;
	}
	int add(IFile* iFile)
	{
		return -1;
	}
	int remove(IFile* iFile)
	{
		return -1;
	}
	list<IFile*>* getChild()
	{
		return NULL;
	}
private:
	string m_name;
};

//dir node
class Dir : public IFile
{
public:
	Dir(string name)
	{
		m_name = name;
		m_list = new list<IFile*>;
		m_list->clear();
	}
	void display()
	{
		cout << m_name << endl;
	}
	int add(IFile* iFile)
	{
		m_list->push_back(iFile);
		return 0;
	}
	int remove(IFile* iFile)
	{
		m_list->remove(iFile);
		return 0;
	}
	list<IFile*>* getChild()
	{
		return m_list;
	}
private:
	string m_name;
	list<IFile*>* m_list;
};

void show(IFile* root, int level)
{
	if (root == NULL)
	{
		return;
	}

	for (int i = 0; i < level; ++i)
	{
		cout << "  ";
	}

	root->display();

	list<IFile*>* l = root->getChild();
	if (l != NULL) //是目录
	{
		for (list<IFile*>::iterator it = l->begin(); it != l->end(); ++it)
		{
			if ((*it)->getChild() == NULL) //是文件
			{
				for (int i = 0; i < level; ++i)
				{
					cout << "  ";
				}
				(*it)->display();
			}
			else //目录
			{
				show(*it, level + 1);
			}
		}
	}
	
}

int main()
{
	Dir* root = new Dir("C");

	Dir* dir1 = new Dir("111dir");
	File* file1 = new File("222.txt");

	root->add(dir1);
	root->add(file1);
	dir1->add(file1);
	
	show(root, 0);
	return 0;
}