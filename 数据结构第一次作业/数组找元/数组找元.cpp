#include<iostream>
using namespace std;
int main()
{
    int a[10];
    cout<<"����ʮ�����ͣ�"<<endl;
    for(int i=1;i<=10;i++){
        cout<<"��"<<i<<"����"<<endl;
        cin>>a[i];
    }
    cout<<"����������ǣ�"<<endl;
    for(int i=1;i<=10;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    int key;
    cout<<"������Ҫ���ҵ����ͣ�"<<endl;
    cin>>key;
    cout<<"Ҫ���ҵ������ǣ�"<<key<<endl;
    for(int i=1;i<=10;i++){
        if(key==a[i]){
            cout<<"�����±���"<<i<<endl;
            exit(0);
        }
    }
    cout<<"δ�ҵ�������\n";
    return 0;
}
