#include<iostream>
#include<string>
#include <vector>
#include <conio.h>
#include<fstream>
//#include<Windows.h>
void Display();//����display��ʾswitch()����
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


void user::Register()//ע��
{
    users.open("�û���Ϣ.txt", ios::in | ios::out | ios::app);    //�Զ���׷��ģʽ�򿪣����������ļ����򴴽�
    string temp;            //�洢ID
    int i = 0;
    int flag = 0;

    char userID[20];
    char userPW[20];
    char userNM[20];
    char userEM[20];
    string pw1;
    string pw2;
    user person;
    cout << "����������ID��";
flag:
    cin >> person.ID;
    while (!users.eof())
    {
        i++;
        getline(users, temp);
        if (i % 5 != 1)continue;    //���ʵ��ǲ���ID��һ�У�������
        //if (i % 3 == 0)continue;    //���ʵ����û�����һ�У�����
        //if (i % 4 == 0)continue;    //���ʵ���������һ�У�����
        if (temp == person.ID)
        {
            cout << "��ID�Ѵ��ڣ�����������:";
            flag = 1;         //flag=1����ID�Ѵ���
            goto flag;
        }
    }
    cout << "�����������û�����";
    cin >> person.Name;
    cout << "����������䣺";
    cin >> person.Email;
    cout << "�������������룺";
flag0:
    cin >> pw1;
    cout << "���ٴ�ȷ���������룺";
    cin >> pw2;
    if (pw1 != pw2)
    {
        cout << "ǰ�������������벻һ�£���������������:";
        goto flag0;
    }
    cout << "ע��ɹ���" << endl << endl;

    person.Password = pw1;
    //�����û���Ϣ
    strcpy_s(userID, person.ID.c_str());    //ID   
    strcpy_s(userPW, person.Password.c_str());      //����
    strcpy_s(userNM, person.Name.c_str());          //�û���
    strcpy_s(userEM, person.Email.c_str());         //����


    //cout << "�����ǣ�"<< userPW << endl;

    users.close();
    users.open("�û���Ϣ.txt", ios::out | ios::app);
    //users.seekg(0L, ios::end);

    users << userID << endl;          //���ļ�д���û���Ϣ
    users << userPW << endl;
    users << userNM << endl;
    users << userEM << endl;
    users << "��������������������" << endl;
    //users.flush();
    users.close();          //�ر��ļ�

    people.push_back(person);

    system("pause");
    system("cls");

    Display();

}
void user::Enter()//��¼
{
    cout << "����������ID��";
flag1:                                      //id��ѯ����
    users.open("�û���Ϣ.txt", ios::in);    //�Զ�ģʽ��
    string temp;            //�洢ID
    int i = 0;
    int flag = 0;

    string id;
    string pwd;

    string hao;             //�˻���Ϣ
    string mima;
    string yonghuming;
    string youxiang;
    cin >> id;
    while (!users.eof())         //��֤ID�Ƿ����
    {
        i++;
        //cout << "���ǵ�" << i << "��"<< endl;     //�����Ƿ�ʼ����
        getline(users, temp);
        hao = temp;
        if (i % 5 != 1)continue;    //���ʵ��ǲ���ID��һ�У�������
        if (temp == id)
        {
            flag = 2;
            getline(users, temp);
            mima = temp;
            getline(users, temp);
            yonghuming = temp;
            getline(users, temp);
            youxiang = temp;
            cout << "�������������룺";
            users.close();
            goto flag2;
        }
    }
    users.close();
    cout << "��ID�����ڣ�����������:";
    goto flag1;

flag2:                                         //�����ѯ����
    cin >> pwd;
    if (mima == pwd)
    {
        flag = 1;
        cout << "��¼�ɹ���" << endl << endl;

        system("pause");
        system("cls");

        cout << "   ��ѡ������Լ�����" << endl;
        cout << "     (1)Information�鿴��Ϣ" << endl;
        cout << "     (2)����ϵͳ" << endl;
        cout << "     (3)Exit�˳�" << endl;
        cout << "   ��ѡ��";
        string choice;//ѡ�����
        string a = "1";
        string b = "2";
        string c = "3";
        cin >> choice;
        system("cls");

        while (choice != a && choice != b && choice != c)
        {
            cout << "   �����������ڲ���1������3֮��ѡ��" << endl;
            cout << "     (1)Information�鿴��Ϣ" << endl;
            cout << "     (2)����ϵͳ" << endl;
            cout << "     (3)Exit�˳�" << endl;
            cout << "   ������ѡ��" << endl;
            cin >> choice;
            system("cls");

        };

        int change;
        change = atoi(choice.c_str());  //stringת��int
        if (change == 2)
            return;

        switch (change)
        {
        case 1://�鿴��Ϣ
            cout << "����IDΪ��" << hao << endl;
            cout << "��������Ϊ��" << mima << endl;
            cout << "�����û���Ϊ��" << yonghuming << endl;
            cout << "��������Ϊ��" << youxiang << endl;
            cout << endl << endl;
            Display();
        case 3://�˳�
            cout << "���˳�" << endl;
            exit(EXIT_FAILURE);
        }
    }

    cout << "����������������룺";
    goto flag2;

}

void Display()//����
{
    cout << "     (1)Registerע��\n     (2)Enter��¼\n     (3)Exit�˳�\n";
    cout << "��ѡ��";
    string choice;//ѡ�����
    string a = "1";
    string b = "2";
    string c = "3";
    user u;
    cin >> choice;
    system("cls");
    while (choice != a && choice != b && choice != c)
    {

        cout << "�����������ڲ���1������3֮��ѡ��" << endl;
        cout << "     (1)Registerע��\n     (2)Enter��¼\n     (3)Exit�˳�\n";
        cout << "��ѡ�����£�";
        cin >> choice;
        system("cls");
    };
    int change;
    change = atoi(choice.c_str());    //stringת��int
    switch (change)
    {
    case 1://ע��
        u.Register();//���ú���
        break;
    case 2://��¼
        u.Enter();//���ú���
        break;
    case 3://�˳�
        exit(EXIT_FAILURE);
    }
}
