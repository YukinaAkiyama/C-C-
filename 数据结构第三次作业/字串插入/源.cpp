/*
����
��д�㷨��ʵ�����溯���Ĺ��ܡ�����void insert(chars,chart,int pos)���ַ���t���뵽�ַ���s�У�����λ��Ϊpos�����ڵ�pos���ַ�ǰ�������������ַ���s�Ŀռ��㹻���ַ���t���롣(˵��������ʹ���κο⺯��)
����
�������ݣ�ÿ�����������У���һ��Ϊ�����λ��pos���ڶ���ΪҪ��������ַ���s��������Ϊ��������ַ���t����posΪ��0��ʱ���������
���
����ÿ���������һ�У�Ϊt����s����ַ�����
�������� 1
1
abcde
abc
2
acd
baaaa
0
������� 1
abcabcde
abaaaacd

*/

#include<iostream>
using namespace std;
void Insert(char a[], char b[], int pos)
{
    int i, len1 = 0, len2 = 0;
    while (a[len1] != '\0')
        len1++;                    //���ַ���a�ĳ���
    while (b[len2] != '\0')
        len2++;                    //���ַ���b�ĳ���        
    for (i = len1 - 1; i >= pos - 1; i--)     //�ַ���a��ĩβ�Ⱥ��ƣ��ǵò���Ӹ���
        a[i + len2] = a[i];
    for (i = pos - 1; i < pos - 1 + len2; i++)
        a[i] = b[i - pos + 1];           //�ٽ��ַ���b����
    len1 += len2;                 //�����ַ���a�ĳ���    
    a[len1] = '\0';                  //�����ַ���ĩβ�Ľ�����'\0'
    for (i = 0; i < len1; i++)
        cout << a[i];
    cout << endl;
}
int main()
{
    int pos;
    while (cin >> pos && pos != 0)    	   //�������λ��
    {
        char a[200], b[100];
        cin >> a >> b;            	   //�����ַ���ab
        Insert(a, b, pos);
    }
    return 0;
}