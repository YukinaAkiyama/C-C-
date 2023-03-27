#include <iostream>
#include <cstdlib>
#include <string>
#include <stack>

using namespace std;

int IsHuiWen2(string str)
{
	stack<char> s;
	int i, len;
	char temp;
	len = str.size();            // 求字符串长度
	for (i = 0; i < len / 2; i++)  // 将一半字符入栈
		s.push(str[i]);

	if (len % 2 == 0)
	{
		while (!s.empty())
		{                       // 每弹出一个字符与相应字符比较
			temp = s.top();
			s.pop();
			if (temp != str[i])
				return 0;       // 不等则返回0                
			else
				i++;
		}

		return 1;      // 比较完毕均相等则返回1
	}
	else if (len % 2 != 0)
	{
		++i;
		while (!s.empty())
		{                       // 每弹出一个字符与相应字符比较
			temp = s.top();
			s.pop();
			if (temp != str[i])
				return 0;     // // 不等则返回0                
			else
				i++;
		}

		return 1; // 比较完毕均相等则返回 1
	}
}

int main()
{
	string str;
	cout << "请输入字符串:";
	getline(cin, str);

	if (str.empty())
	{
		cout << "输入有误，请输入字符串:";
		getline(cin, str);
	}

	if (IsHuiWen2(str))
	{
		printf("是回文字符串!\n");
	}
	else
	{
		printf("不是回文字符串!\n");
	}

	system("pause");

	return 0;
}