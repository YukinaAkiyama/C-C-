#include<iostream>
using namespace std;
int main()
{
    int a[10];
    cout<<"输入十个整型："<<endl;
    for(int i=1;i<=10;i++){
        cout<<"第"<<i<<"个："<<endl;
        cin>>a[i];
    }
    cout<<"输入的数组是："<<endl;
    for(int i=1;i<=10;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    int key;
    cout<<"请输入要查找的整型："<<endl;
    cin>>key;
    cout<<"要查找的整型是："<<key<<endl;
    for(int i=1;i<=10;i++){
        if(key==a[i]){
            cout<<"它的下标是"<<i<<endl;
            exit(0);
        }
    }
    cout<<"未找到该整型\n";
    return 0;
}
