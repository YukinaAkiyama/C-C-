#include<iostream>
#include<fstream>
#include<string>
#include<queue>
using namespace std;

int main()                                                             
{
	fstream letter;
	string filename = "字母";
	letter.open(filename,  ios::out | ios::in |ios::app);
	letter << "GIKugiKKOLpooRRT" << endl;
	letter.clear();
	letter.seekg(0, ios::beg);
	string buf;
	getline(letter, buf);
	cout << "读取到的字母为：" << buf << endl;

	system("pause");

	queue<char>zimu; //默认方式创建一个队列
	queue<char>gai;
	char ch;
	for (int i = 1; i < 100; i++)    //从文件读取字符到队列 zimu
	{
		ch = letter.get();
		zimu.push(ch);	//元素入队
		if (ch >= 'a' && ch <= 'z')
		{
			ch = ch - 32;
		}
		gai.push(ch);  //元素入队

	}

	cout << "列出zimu队列元素：\n";
	int zimu_size = zimu.size();
	for (int i = 0; i < zimu_size; i++)  //遍历队列	myqueue_size 必须是固定值
	{   
		cout << zimu.front() <<"  ";
		//zimu.push(zimu.front());
		zimu.pop();
	}
	cout << endl;
	cout << "小写转换大写：\n";
	int gai_size = gai.size();
	for (int i = 0; i < gai_size; i++)  //遍历队列	myqueue_size 必须是固定值
	{
		cout << gai.front() << "  ";
		//gai.push(gai.front());
		gai.pop();
	}
	
	

	system("pause");

}