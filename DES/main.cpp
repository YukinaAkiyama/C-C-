#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include "DES.h"
using namespace std;
void printHead();
void des();
string getText(const string& filename);
void writeCiphertext(const string& ciphertext, const string& fileName);
int main()
{
    printHead();
    int a;
    while (cin>>a)
    {
        if(a==1){
            des();
        }
        else{
            cout << "谢谢使用" << endl;
            break;
        }
        system("pause");
        system("cls");
        printHead();
    }
    system("pause");
}

void printHead() {
    cout << "---------------------------------------" << endl;
    cout << "-            1.DES加密算法            -" << endl;
    cout << "-            2.退出                   -" << endl;
    cout << "---------------------------------------" << endl;
    cout << "明文内容为："+ getText("plaintext.txt") +"\n" << endl;
    cout << "选择：";
}



void des() {
    string keyword;
    cout << "\n***  DES加密算法  ***" << endl;
    cout << "输入密钥:" << endl;
    cin >> keyword;
    DES d(keyword);
    d.Encrypt(getText("plaintext.txt"));
    cout << "加密后密文为：" << d.ciphertext << endl;
    writeCiphertext(d.ciphertext, "ciphertext.des");
    d.Decrypt(getText("ciphertext.des"));
    cout << "解密后明文为：" << d.plaintext << endl;
    cout << "密文已写入 ciphertext.des 文件" << endl;
}

//读入文本
string getText(const string& filename) {
    ifstream infile;
    infile.open("plaintext.txt",ios::in);
    cout << filename<<endl;
    if (!infile.is_open()){
        cout << "读取文件失败" << endl;
    }
    string plaintext;
    getline(infile, plaintext);
    infile.close();
    return plaintext;
}

//创建并写入文本
void writeCiphertext(const string& ciphertext, const string& fileName) {
    ofstream outfile(fileName, ofstream::out);
    outfile << ciphertext;
    outfile.close();
}
