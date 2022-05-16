#include<iostream>
using namespace std;

class Date {
private:
	int month;
	int data;
	int year;
public:
	void riqi();
	void cout1();
	void cout2();
	void cout3();
	string eng_yue(int a);
};

void Date::riqi() {
	cout << "�������� �� ��:";
	cin >> year >> month >> data;
	if (data > 31 || data < 1) {
		throw "������Ч";
	}
	if (month > 12 || month < 1) {
		throw "�·���Ч";
	}
}

void Date::cout1() {
	cout << endl << "[" << month << "-" << data << "-" << year % 100 << "]" << endl;
}

void Date::cout2() {
	cout << endl << "[" << eng_yue(month) << " " << data << "," << year << "]" << endl;
}

void Date::cout3() {
	cout << endl << "[" << data << " " << eng_yue(month) << " " << year << "]" << endl;
}

string Date::eng_yue(int a) {
	switch (a) {
	case 1: return "January";
	case 2: return "February";
	case 3:  return "March";
	case 4:  return "April";
	case 5: return "May";
	case 6: return "June";
	case 7: return "July";
	case 8: return "August";
	case 9: return "September";
	case 10: return "October";
	case 11: return "November";
	case 12: return "December";
	}
}

int main()
{
	Date d1;
	int n;
	while (1) {
		while (1) {
			try {
				d1.riqi();
				break;
			}
			catch (const char* msg) {
				cerr << msg << endl;
			}
		}
		while (1) {
			cout << "1.���12-25-11��ʽ" << endl;
			cout << "2.���'December 25,2011'��ʽ" << endl;
			cout << "3.���'25 December 2011'��ʽ" << endl;
			cout << "4.������һ��" << endl;
			cout << "��ѡ��";
			cin >> n;
			if (n==4) {
				cout << endl;
				break;
			}
			switch (n) {
			case 1:d1.cout1(); break;
			case 2:d1.cout2(); break;
			case 3:d1.cout3(); break;
			default:break;
			}
		}
	}




}
