
#include<bits/stdc++.h>
#define db double
#define ll long long
#define ldb long double
#define ull unsigned long long
#define work() system(opt.c_str())
using namespace std;

int id_l=11;
int id_r=20;
string std_name="std";
string rand_name="rand";
string data_name="swaps";

string in,out;
FILE * fp;

int main()
{
	printf("即将生成第 %d--%d 组数据\n",id_l,id_r);
	printf("标程：");cout<<std_name<<endl; 
	printf("生成器：");cout<<rand_name<<endl; 
	printf("数据文件：");cout<<data_name<<endl; 
	printf("确认无误");system("pause");
	for(int t=id_l;t<=id_r;t++)
	{
		cout<<"正在生成第   "<<t<<"   组数据"<<endl;
		string opt;
		in=data_name+to_string(t)+".in";
		out=data_name+to_string(t)+".out";
		opt=rand_name+".exe"+" > "+in;work();
		opt=std_name+".exe"+" < "+in+" > "+out;work();
		cout<<"生成成功"<<endl; 
	}
	printf("第 %d~%d 组数据已生成完毕\n",id_l,id_r);
	system("pause");
	return 0;
}

