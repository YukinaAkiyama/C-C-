#include<iostream>
#include<string>
#include <vector>
#include <conio.h>
#include<fstream>
//#include<Windows.h>
void Display();//调用display显示switch()界面
using namespace std;
class user {
private:
    string ID;
    string Name;
    string Email;
    string Password;
public:
    user() {};
    void Register();
    void Enter();
};

vector<user> people;
fstream users;


void user::Register()//注册
{
    users.open("用户信息.txt", ios::in | ios::out | ios::app);    //以读、追加模式打开，若本低无文件，则创建
    string temp;            //存储ID
    int i = 0;
    int flag = 0;

    char userID[20];
    char userPW[20];
    char userNM[20];
    char userEM[20];
    string pw1;
    string pw2;
    user person;
    cout << "请设置您的ID：";
flag:
    cin >> person.ID;
    while (!users.eof())
    {
        i++;
        getline(users, temp);
        if (i % 5 != 1)continue;    //访问的是不是ID这一行，跳出。
        //if (i % 3 == 0)continue;    //访问的是用户名这一行，跳出
        //if (i % 4 == 0)continue;    //访问的是邮箱这一行，跳出
        if (temp == person.ID)
        {
            cout << "该ID已存在，请重新设置:";
            flag = 1;         //flag=1，则ID已存在
            goto flag;
        }
    }
    cout << "请设置您的用户名：";
    cin >> person.Name;
    cout << "请绑定您的邮箱：";
    cin >> person.Email;
    cout << "请设置您的密码：";
flag0:
    cin >> pw1;
    cout << "请再次确认您的密码：";
    cin >> pw2;
    if (pw1 != pw2)
    {
        cout << "前后两次输入密码不一致，请重新设置密码:";
        goto flag0;
    }
    cout << "注册成功！" << endl << endl;

    person.Password = pw1;
    //拷贝用户信息
    strcpy_s(userID, person.ID.c_str());    //ID   
    strcpy_s(userPW, person.Password.c_str());      //密码
    strcpy_s(userNM, person.Name.c_str());          //用户名
    strcpy_s(userEM, person.Email.c_str());         //邮箱


    //cout << "密码是："<< userPW << endl;

    users.close();
    users.open("用户信息.txt", ios::out | ios::app);
    //users.seekg(0L, ios::end);

    users << userID << endl;          //向文件写入用户信息
    users << userPW << endl;
    users << userNM << endl;
    users << userEM << endl;
    users << "…………………………" << endl;
    //users.flush();
    users.close();          //关闭文件

    people.push_back(person);

    system("pause");
    system("cls");

    Display();

}
void user::Enter()//登录
{
    cout << "请输入您的ID：";
flag1:                                      //id查询环节
    users.open("用户信息.txt", ios::in);    //以读模式打开
    string temp;            //存储ID
    int i = 0;
    int flag = 0;

    string id;
    string pwd;

    string hao;             //账户信息
    string mima;
    string yonghuming;
    string youxiang;
    cin >> id;
    while (!users.eof())         //验证ID是否存在
    {
        i++;
        //cout << "这是第" << i << "行"<< endl;     //测试是否开始遍历
        getline(users, temp);
        hao = temp;
        if (i % 5 != 1)continue;    //访问的是不是ID这一行，跳出。
        if (temp == id)
        {
            flag = 2;
            getline(users, temp);
            mima = temp;
            getline(users, temp);
            yonghuming = temp;
            getline(users, temp);
            youxiang = temp;
            cout << "请输入您的密码：";
            users.close();
            goto flag2;
        }
    }
    users.close();
    cout << "该ID不存在，请重新输入:";
    goto flag1;

flag2:                                         //密码查询环节
    cin >> pwd;
    if (mima == pwd)
    {
        flag = 1;
        cout << "登录成功！" << endl << endl;

        system("pause");
        system("cls");

        cout << "   请选择操作以继续：" << endl;
        cout << "     (1)Information查看信息" << endl;
        cout << "     (2)进入系统" << endl;
        cout << "     (3)Exit退出" << endl;
        cout << "   请选择：";
        string choice;//选择界面
        string a = "1";
        string b = "2";
        string c = "3";
        cin >> choice;
        system("cls");

        while (choice != a && choice != b && choice != c)
        {
            cout << "   输入有误，请在操作1到操作3之间选择" << endl;
            cout << "     (1)Information查看信息" << endl;
            cout << "     (2)进入系统" << endl;
            cout << "     (3)Exit退出" << endl;
            cout << "   请重新选择：" << endl;
            cin >> choice;
            system("cls");

        };

        int change;
        change = atoi(choice.c_str());  //string转换int
        if (change == 2)
            return;

        switch (change)
        {
        case 1://查看信息
            cout << "您的ID为：" << hao << endl;
            cout << "您的密码为：" << mima << endl;
            cout << "您的用户名为：" << yonghuming << endl;
            cout << "您的邮箱为：" << youxiang << endl;
            cout << endl << endl;
            Display();
        case 3://退出
            cout << "已退出" << endl;
            exit(EXIT_FAILURE);
        }
    }

    cout << "密码错误，请重新输入：";
    goto flag2;

}

void Display()//界面
{
    cout << "     (1)Register注册\n     (2)Enter登录\n     (3)Exit退出\n";
    cout << "请选择：";
    string choice;//选择界面
    string a = "1";
    string b = "2";
    string c = "3";
    user u;
    cin >> choice;
    system("cls");
    while (choice != a && choice != b && choice != c)
    {

        cout << "输入有误，请在操作1到操作3之间选择" << endl;
        cout << "     (1)Register注册\n     (2)Enter登录\n     (3)Exit退出\n";
        cout << "请选择重新：";
        cin >> choice;
        system("cls");
    };
    int change;
    change = atoi(choice.c_str());    //string转换int
    switch (change)
    {
    case 1://注册
        u.Register();//调用函数
        break;
    case 2://登录
        u.Enter();//调用函数
        break;
    case 3://退出
        exit(EXIT_FAILURE);
    }
}
