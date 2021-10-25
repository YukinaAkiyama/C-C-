#include<iostream>
using namespace std;
class Float
{
public:
	Float(int count = 10);//构造函数,count默认为10
	~Float();//析构函数
	bool setData(float a);//存储数据
	float Aver();//计算平均值
private:
	float* p;
	int num;//数据元素个数
};
Float::Float(int count)
{
	p = new float[count];
	num = 0;
	if (p == NULL)
	{
		cout << "内存不足" << endl;
		exit(0);
	}
	cout << endl << "构造完成" << endl << endl;
}
Float::~Float()
{
	delete[]p;
	cout << endl << "数组已完成析构" << endl << endl;
}
bool Float::setData(float a)
{
	p[num] = a;
	num++;
	return 0;
}
float Float::Aver()
{
	float sum = 0;
	for (int i = 0; i < num; i++)
		sum += p[i];
	return sum / num;
}
int main()
{
	cout << "输入数据数目：";
	int n;
	cin >> n;
	Float myfloat(n);//调用构造函数
	cout << "请输入" << n << "个数据：" << endl;
	for (int i = 0; i < n; i++)//调用setData函数
	{
		float a;
		cin >> a;
		myfloat.setData(a);
	}
	cout << "数据的平均值为：" << myfloat.Aver() << endl;//调用求平均值函数
	return 0;
}