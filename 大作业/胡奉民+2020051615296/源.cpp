#include<algorithm>
#include"user.h"
#define rep(i,x,y) for(register int i = x; i <= y; ++ i)     
using namespace std;
const int MAX = 10101;

class person
{
private:
	string nm, rk, ph, i;    //��ź����������ȼ����绰������
	int tp;    //��ź��ѱ��
	bool op;
public:
	person() { op = 0; }
	bool operator < (person b)
	{
		return tp < b.tp;
	}
	int get();
	void del(int a);
	void add();     //��Ӻ���
	void addw();     //���ļ���ȡ����
	void save();     //���������Ϣ���ļ�
	void find();     //���Һ�����Ϣ
	void delm();      //ɾ��������Ϣ
	void put();       //���ȫ������
	void srt();      //��������
	void modify();      //�޸ĺ�����Ϣ
	friend person read();

}p[MAX];

int sz, cnt;
int stk[MAX], top;

void showMenu()
{
	cout << "*****************************" << endl;
	cout << "***1����Ӻ���***************" << endl;
	cout << "***2���ļ��������***********" << endl;
	cout << "***3���ļ��������***********" << endl;
	cout << "***4�����Һ���***************" << endl;
	cout << "***5��ɾ������***************" << endl;
	cout << "***6���������***************" << endl;
	cout << "***7���޸ĺ���***************" << endl;
	cout << "***8�����ȫ������***********" << endl;
	cout << "***0���˳�ͨѶ¼*************" << endl;
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
	cout << "�����������š����ơ��ȼ����绰������" << endl;
	p[get()] = read(); 
	cout << "�����" << endl;
	system("pause");
	system("cls");
}

void person::addw()
{
	cout << "�������ļ�����" << endl;
	string nm;
	cin >> nm;
	fstream f; f.open(nm.c_str(), ios::in);
	int num; f >> num;
    while (num--){
		int nw = get(); p[nw].op = 1;
		f >> p[nw].tp >> p[nw].nm >> p[nw].rk >> p[nw].ph >> p[nw].i;
	}
	f.close();
	cout << "�����";
	system("pause");
	system("cls");
}

void person::save()
{
	cout << "�����뱣���ļ�����" << endl;
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
	cout << "�����";
	system("pause");
	system("cls");
}

void person::find()
{
	cout << "���������������";
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
		cout << "δ�ҵ��ú���";
	else
		cout << "�����";
	system("pause");
	system("cls");
}

void person::delm()
{
	cout << "������ɾ����������";
	string nm; cin >> nm;
	bool chk = 0;
	rep(i, 1, cnt) if (p[i].op && p[i].nm == nm)
	{
		del(i);
		chk = 1;
		break;
	}
	if (!chk)
		cout << "δ�ҵ��ú���";
	else
		cout << "�����";
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
	cout << "�����";
	system("pause");
	system("cls");
}

void person::srt()
{
	sort(p + 1, p + 1 + cnt);		//����
	cout << "�����";
	system("pause");
	system("cls");
}

void person::modify()
{
	cout << "�������޸ĺ�������";
	string nm; cin >> nm; bool chk = 0;
	rep(i, 1, cnt) if (p[i].op && p[i].nm == nm)
	{
		cout << "�����������޸ĺ��š����ơ��ȼ����绰������";
		cin >> p[i].tp >> p[i].nm >> p[i].rk >> p[i].ph >> p[i].i;
		chk = 1; break;
	}
	if (!chk)
		cout << "δ�ҵ��ú���";
	else
		cout << "�����";
	system("pause");
	system("cls");
}

int main()
{
	Display();//��ʾ���桡����ע�᣻����¼��3�˳�
	cin.get();
	person p;
	while (true)
	{
		showMenu();//�˵�����
		int select;
		cin >> select;
		switch (select)
		{
		case 1:     //1����Ӻ���
			p.add();
			break;
		case 2:    //2���ļ��������
			p.save();
			break;
		case 3:    //3���ļ��������
			p.addw();
			break;
		case 4:    //4�����Һ���
			p.find();
			break;
		case 5:    //5��ɾ������
			p.delm();
			break;
		case 6:    //6���������
			p.srt();
			break;
		case 7:    //7���޸ĺ���
			p.modify();
			break;
		case 8:    //8�����ȫ������
			p.put();
			break;
		case 0:    //0���˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	return 0;
}
