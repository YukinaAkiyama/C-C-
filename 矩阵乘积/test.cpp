#include<iostream>
using namespace std;
#include <stdlib.h>

/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
            佛祖保佑       永无BUG
*/

class population
{
private:
	int all;
	int die;
	int born;
	float birth_rate;
	float death_rate;
public:
	void setData(float, float, float);
	void Birth_Rate();
	void Death_Rate();
	float getBirth_Rate();
	float getDeath_Rate();
};
void population::setData(float t, float d, float b)
{
	all = t;
	die = d;
	born = b;
}
void population::Birth_Rate()
{
	birth_rate = float(born) / float(all);
}
void population::Death_Rate()
{
	death_rate = float(die) / float(all);
}
float population::getBirth_Rate()
{
	return birth_rate;
}
float population::getDeath_Rate()
{
	return death_rate;
}
int main()
{
	population people;
	int birth, death, total;
	cout << "计算出生率和死亡率\n"; 
	cout << "请输入城市人口：";
	cin >> total;
	if (total < 1)
	{
		cout << "人口数不能小于1，请重新输入！"<< endl;
		cin >> total;
	}
	cout << "请输入死亡人数：";
	cin >> death;
	cout << "请输入出生人数：";
	cin >> birth;
	people.setData(total, death, birth);
	people.Birth_Rate();
	people.Death_Rate();
	cout << "人口参数：";
	cout << "出生率" << people.getBirth_Rate() << "，";
	cout << "死亡率" << people.getDeath_Rate() << "，";
	system("pause");
	return 0;
}
