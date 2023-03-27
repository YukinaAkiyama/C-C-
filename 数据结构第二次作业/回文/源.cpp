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
	len = str.size();            // ���ַ�������
	for (i = 0; i < len / 2; i++)  // ��һ���ַ���ջ
		s.push(str[i]);

	if (len % 2 == 0)
	{
		while (!s.empty())
		{                       // ÿ����һ���ַ�����Ӧ�ַ��Ƚ�
			temp = s.top();
			s.pop();
			if (temp != str[i])
				return 0;       // �����򷵻�0                
			else
				i++;
		}

		return 1;      // �Ƚ���Ͼ�����򷵻�1
	}
	else if (len % 2 != 0)
	{
		++i;
		while (!s.empty())
		{                       // ÿ����һ���ַ�����Ӧ�ַ��Ƚ�
			temp = s.top();
			s.pop();
			if (temp != str[i])
				return 0;     // // �����򷵻�0                
			else
				i++;
		}

		return 1; // �Ƚ���Ͼ�����򷵻� 1
	}
}

int main()
{
	string str;
	cout << "�������ַ���:";
	getline(cin, str);

	if (str.empty())
	{
		cout << "���������������ַ���:";
		getline(cin, str);
	}

	if (IsHuiWen2(str))
	{
		printf("�ǻ����ַ���!\n");
	}
	else
	{
		printf("���ǻ����ַ���!\n");
	}

	system("pause");

	return 0;
}