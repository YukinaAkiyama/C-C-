#include <stdio.h>
#define MAX 100

void detect(char s[])
{
	char ch[MAX];/*��¼���ֵ��ַ�*/
	int num[MAX] = { 0 };/*��¼ÿ���ַ����ֵĴ���*/
	int i, j, n = 0;
	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; j < n; j++)
			if (s[i] == ch[j] || (ch[j] >= 'a' && ch[j] <= 'z' && s[i] + 32 == ch[j])) break;/*�жϸ��ַ��Ƿ��Ѿ����ֹ�*/
		if (j < n)/*���ַ����ֹ�,��Ӧ�ļ�����num[j]��һ*/
			num[j]++;
		else/*���ַ����³��ֵ��ַ�����¼��ch[j]�У���Ӧ������num[j]��һ*/
		{
			if (s[i] >= 'A' && s[i] <= 'Z')
				ch[j] = s[i] + 32;
			else
				ch[j] = s[i];
			num[j]++;
			n++;/*���ֵ��ַ�����������1*/
		}
	}
	for (i = 0; i < n; i++)/*���*/
		printf("\'%c\'������%d��\n", ch[i], num[i]);
}

int main()
{
	int i = 0;
	char s[MAX];
	printf("������һ���ַ���:");
	while ((s[i] = getchar()) != '\n')/*����*/
		i++;
	s[i] = '\0';
	detect(s);
}