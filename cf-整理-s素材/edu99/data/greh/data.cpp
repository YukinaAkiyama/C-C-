
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
	printf("�������ɵ� %d--%d ������\n",id_l,id_r);
	printf("��̣�");cout<<std_name<<endl; 
	printf("��������");cout<<rand_name<<endl; 
	printf("�����ļ���");cout<<data_name<<endl; 
	printf("ȷ������");system("pause");
	for(int t=id_l;t<=id_r;t++)
	{
		cout<<"�������ɵ�   "<<t<<"   ������"<<endl;
		string opt;
		in=data_name+to_string(t)+".in";
		out=data_name+to_string(t)+".out";
		opt=rand_name+".exe"+" > "+in;work();
		opt=std_name+".exe"+" < "+in+" > "+out;work();
		cout<<"���ɳɹ�"<<endl; 
	}
	printf("�� %d~%d ���������������\n",id_l,id_r);
	system("pause");
	return 0;
}

