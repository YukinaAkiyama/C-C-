#include <stdio.h>
#define MAX 100

void detect(char s[])
{
	char ch[MAX];/*记录出现的字符*/
	int num[MAX] = { 0 };/*记录每个字符出现的次数*/
	int i, j, n = 0;
	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; j < n; j++)
			if (s[i] == ch[j] || (ch[j] >= 'a' && ch[j] <= 'z' && s[i] + 32 == ch[j])) break;/*判断该字符是否已经出现过*/
		if (j < n)/*该字符出现过,对应的记数器num[j]加一*/
			num[j]++;
		else/*该字符是新出现的字符，记录到ch[j]中，对应计数器num[j]加一*/
		{
			if (s[i] >= 'A' && s[i] <= 'Z')
				ch[j] = s[i] + 32;
			else
				ch[j] = s[i];
			num[j]++;
			n++;/*出现的字符的种类数加1*/
		}
	}
	for (i = 0; i < n; i++)/*输出*/
		printf("\'%c\'出现了%d次\n", ch[i], num[i]);
}

int main()
{
	int i = 0;
	char s[MAX];
	printf("请输入一个字符串:");
	while ((s[i] = getchar()) != '\n')/*输入*/
		i++;
	s[i] = '\0';
	detect(s);
}