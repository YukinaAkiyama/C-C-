#include<algorithm>
#include"user.h"
#define rep(i,x,y) for(register int i = x; i <= y; ++ i)     
using namespace std;
const int MAX = 10101;

class person
{
private:
	string nm, rk, ph, i;    //存放好友姓名，等级，电话，爱好
	int tp;    //存放好友编号
	bool op;
public:
	person() { op = 0; }
	bool operator < (person b)
	{
		return tp < b.tp;
	}
	int get();
	void del(int a);
	void add();     //添加好友
	void addw();     //从文件读取好友
	void save();     //保存好友信息到文件
	void find();     //查找好友信息
	void delm();      //删除好友信息
	void put();       //输出全部好友
	void srt();      //好友排序
	void modify();      //修改好友信息
	friend person read();

}p[MAX];

int sz, cnt;
int stk[MAX], top;

void showMenu()
{
	cout << "*****************************" << endl;
	cout << "***1、添加好友***************" << endl;
	cout << "***2、文件保存好友***********" << endl;
	cout << "***3、文件读入好友***********" << endl;
	cout << "***4、查找好友***************" << endl;
	cout << "***5、删除好友***************" << endl;
	cout << "***6、排序好友***************" << endl;
	cout << "***7、修改好友***************" << endl;
	cout << "***8、输出全部好友***********" << endl;
	cout << "***0、退出通讯录*************" << endl;
	cout << "*****************************" << endl;
}

person read()
{
	person a; a.op = 1;
	cin >> a.tp >> a.nm >> a.rk >> a.ph >> a.i;
	return a;

}

int person::get() { ++sz; return top ? stk[top--] : ++cnt; }

void person::del(int a) { p[a].op = 0; stk[++top] = a; --sz; }

void person::add() 
{ 
	cout << "请依次输入编号、名称、等级、电话、爱好" << endl;
	p[get()] = read(); 
	cout << "已完成" << endl;
	system("pause");
	system("cls");
}

void person::addw()
{
	cout << "请输入文件名称" << endl;
	string nm;
	cin >> nm;
	fstream f; f.open(nm.c_str(), ios::in);
	int num; f >> num;
    while (num--){
		int nw = get(); p[nw].op = 1;
		f >> p[nw].tp >> p[nw].nm >> p[nw].rk >> p[nw].ph >> p[nw].i;
	}
	f.close();
	cout << "已完成";
	system("pause");
	system("cls");
}

void person::save()
{
	cout << "请输入保存文件名称" << endl;
	string nm;
	cin >> nm;
	fstream f(nm.c_str(), ios::out | ios::app);
	f << sz << endl;
	rep(i, 1, cnt) if (p[i].op)
	{
		f << p[i].tp << ' ' << p[i].nm << ' ' << p[i].rk;
		f << ' ' << p[i].ph << ' ' << p[i].i << endl;
	}
	f.close();
	cout << "已完成";
	system("pause");
	system("cls");
}

void person::find()
{
	cout << "请输入查找人姓名";
	string nm;
	cin >> nm; bool chk = 0;
	rep(i, 1, cnt) if (p[i].op && p[i].nm == nm)
	{
		cout << p[i].tp << ' ' << p[i].nm << ' ' << p[i].rk;
		cout << ' ' << p[i].ph << ' ' << p[i].i << endl;
		chk = 1;
		break;
	}
	if (!chk)
		cout << "未找到该好友";
	else
		cout << "已完成";
	system("pause");
	system("cls");
}

void person::delm()
{
	cout << "请输入删除好友姓名";
	string nm; cin >> nm;
	bool chk = 0;
	rep(i, 1, cnt) if (p[i].op && p[i].nm == nm)
	{
		del(i);
		chk = 1;
		break;
	}
	if (!chk)
		cout << "未找到该好友";
	else
		cout << "已完成";
	system("pause");
	system("cls");
}

void person::put()
{
	rep(i, 1, cnt) if (p[i].op)
	{
		cout << p[i].tp << ' ' << p[i].nm.c_str() << ' ' << p[i].rk;
		cout << ' ' << p[i].ph << ' ' << p[i].i << endl;
	}
	cout << endl;
	cout << "已完成";
	system("pause");
	system("cls");
}

void person::srt()
{
	sort(p + 1, p + 1 + cnt);		//排序
	cout << "已完成";
	system("pause");
	system("cls");
}

void person::modify()
{
	cout << "请输入修改好友姓名";
	string nm; cin >> nm; bool chk = 0;
	rep(i, 1, cnt) if (p[i].op && p[i].nm == nm)
	{
		cout << "请依次输入修改后编号、名称、等级、电话、爱好";
		cin >> p[i].tp >> p[i].nm >> p[i].rk >> p[i].ph >> p[i].i;
		chk = 1; break;
	}
	if (!chk)
		cout << "未找到该好友";
	else
		cout << "已完成";
	system("pause");
	system("cls");
}

int main()
{
	Display();//显示界面　　１注册；２登录；3退出
	cin.get();
	person p;
	while (true)
	{
		showMenu();//菜单调用
		int select;
		cin >> select;
		switch (select)
		{
		case 1:     //1、添加好友
			p.add();
			break;
		case 2:    //2、文件保存好友
			p.save();
			break;
		case 3:    //3、文件读入好友
			p.addw();
			break;
		case 4:    //4、查找好友
			p.find();
			break;
		case 5:    //5、删除好友
			p.delm();
			break;
		case 6:    //6、排序好友
			p.srt();
			break;
		case 7:    //7、修改好友
			p.modify();
			break;
		case 8:    //8、输出全部好友
			p.put();
			break;
		case 0:    //0、退出通讯录
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	return 0;
}
