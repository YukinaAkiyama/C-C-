#include<iostream>
#include<fstream>
#include<string>
#include<queue>
using namespace std;

int main()                                                             
{
	fstream letter;
	string filename = "��ĸ";
	letter.open(filename,  ios::out | ios::in |ios::app);
	letter << "GIKugiKKOLpooRRT" << endl;
	letter.clear();
	letter.seekg(0, ios::beg);
	string buf;
	getline(letter, buf);
	cout << "��ȡ������ĸΪ��" << buf << endl;

	system("pause");

	queue<char>zimu; //Ĭ�Ϸ�ʽ����һ������
	queue<char>gai;
	char ch;
	for (int i = 1; i < 100; i++)    //���ļ���ȡ�ַ������� zimu
	{
		ch = letter.get();
		zimu.push(ch);	//Ԫ�����
		if (ch >= 'a' && ch <= 'z')
		{
			ch = ch - 32;
		}
		gai.push(ch);  //Ԫ�����

	}

	cout << "�г�zimu����Ԫ�أ�\n";
	int zimu_size = zimu.size();
	for (int i = 0; i < zimu_size; i++)  //��������	myqueue_size �����ǹ̶�ֵ
	{   
		cout << zimu.front() <<"  ";
		//zimu.push(zimu.front());
		zimu.pop();
	}
	cout << endl;
	cout << "Сдת����д��\n";
	int gai_size = gai.size();
	for (int i = 0; i < gai_size; i++)  //��������	myqueue_size �����ǹ̶�ֵ
	{
		cout << gai.front() << "  ";
		//gai.push(gai.front());
		gai.pop();
	}
	
	

	system("pause");

}