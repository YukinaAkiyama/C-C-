/*
描述
编写算法，实现下面函数的功能。函数void insert(chars,chart,int pos)将字符串t插入到字符串s中，插入位置为pos（插在第pos个字符前）。假设分配给字符串s的空间足够让字符串t插入。(说明：不得使用任何库函数)
输入
多组数据，每组数据有三行，第一行为插入的位置pos，第二行为要被插入的字符串s，第三行为待插入的字符串t。当pos为“0”时输入结束。
输出
对于每组数据输出一行，为t插入s后的字符串。
输入样例 1
1
abcde
abc
2
acd
baaaa
0
输出样例 1
abcabcde
abaaaacd

*/

#include<iostream>
using namespace std;
void Insert(char a[], char b[], int pos)
{
    int i, len1 = 0, len2 = 0;
    while (a[len1] != '\0')
        len1++;                    //求字符串a的长度
    while (b[len2] != '\0')
        len2++;                    //求字符串b的长度        
    for (i = len1 - 1; i >= pos - 1; i--)     //字符串a的末尾先后移，记得补充接刚来
        a[i + len2] = a[i];
    for (i = pos - 1; i < pos - 1 + len2; i++)
        a[i] = b[i - pos + 1];           //再将字符串b填入
    len1 += len2;                 //更新字符串a的长度    
    a[len1] = '\0';                  //补充字符串末尾的结束符'\0'
    for (i = 0; i < len1; i++)
        cout << a[i];
    cout << endl;
}
int main()
{
    int pos;
    while (cin >> pos && pos != 0)    	   //输入插入位置
    {
        char a[200], b[100];
        cin >> a >> b;            	   //输入字符串ab
        Insert(a, b, pos);
    }
    return 0;
}