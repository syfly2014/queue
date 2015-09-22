// queue.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include "LinkQueue.h"
#include <string>

#include <queue>

using namespace std;

//����������Ϣ
struct dancer
{
	string name;
	char sex;
};

void dancerCompare()
{
	cout << "����������������";
	int num;
	cin >> num;

	LinkQueue<dancer> Mdancer;
	LinkQueue<dancer> Fdancer;

	for (int i = 0; i < num; i++)
	{
		cout << "����������Ա�f��m��������";
		char sex;
		cin >> sex;
		string name;
		cin >> name;

		dancer newDancer;
		newDancer.sex = sex;
		newDancer.name = name;

		if (sex == 'f')
		{
			Fdancer.EnQueue(newDancer);
		}
		else if (sex == 'm')
		{
			Mdancer.EnQueue(newDancer);
		}

		while (!Fdancer.IsEmpty() && !Mdancer.IsEmpty())
		{
			cout << Mdancer.DelQueue().name << "\t<---->\t" << Fdancer.DelQueue().name << endl;

		}
	
		if (!Mdancer.IsEmpty())
			cout << "Ms. " << Mdancer.GetFront().name << "is waiting" << endl;
		else if (!Fdancer.IsEmpty())
			cout << "Mr. " << Fdancer.GetFront().name << "is waiting" << endl;
		else
			cout << "OK" << endl;
	}

}

//ʵ�ֶ��и�ֵ����
template <class T>  void evaluate(LinkQueue<T>& ori, LinkQueue<T>& target)
{
	ori.MakeEmpty();
	while (!target.IsEmpty())
	{
		T temp = target.GetFront();
		ori.EnQueue(temp);
		target.DelQueue();
	}
}

void YangHui()
{
	cout << "��������������ν���i(i>2)��";
	int num;
	cin >> num;

	LinkQueue<int> ori;
	ori.EnQueue(1);
	ori.EnQueue(1);

	LinkQueue<int> next;
	for (int i = 0; i < num - 2; i++)
	{
		next.EnQueue(1);

		while (!ori.IsEmpty())
		{
			int element = ori.DelQueue();

			if (!ori.IsEmpty())
			{
				next.EnQueue(element + ori.GetFront());
			}
			else
			{
				next.EnQueue(element);
			}
		}

		evaluate(ori, next);
	}

	cout << "��������ε�" << num << "�е��������£�" << endl;
	while (!ori.IsEmpty())
	{
		cout << ori.DelQueue() << " ";
	}

	cout << endl;
}


//�γ̱�������,ʹ��STL�Դ��Ķ���
void youcheng()
{
	queue<int> picture;
	char a;
	float pow = 0, oriSize;

	cout << "Please input 01 (end with #):";
     
	do
	{
		cin >> a;
		if (a != '#')
		{
			picture.push(a);
		}
	} while (a != '#');

	char pic = picture.front();
	picture.pop();

	int size = picture.size() + 1;
	oriSize = size;

	cout << "�����";
	while (!picture.empty())
	{
		if (pic == picture.front())
		{
			pic = picture.front();
			picture.pop();
		}
		else
		{
			cout << size - picture.size();
			pow++;

			size = picture.size();
			pic = picture.front();

			picture.pop();
		}
	}

	cout << size << endl;
	pow++;
	cout << "ѹ����Ϊ��" << pow / oriSize << endl;

}

int _tmain(int argc, _TCHAR* argv[])
{
	//dancerCompare();
	//YangHui();
	youcheng();
	system("pause");
	return 0;
}

