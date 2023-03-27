

#include <cstdio>
#include <fstream>
#include <Windows.h>

#include <cstdio>
#include <iostream>
#include <string>
#include <io.h>
#include <vector>

#include <direct.h>
#include <cstdlib>
#include <memory>

using namespace std;

void getFilesAll( string path, vector<string>& files)
{
    //获取文件夹下面的所有文件名字
    //文件句柄
    long  hFile  =  0;
    //文件信息
    struct _finddata_t fileinfo;
    string p;
    if((hFile = _findfirst(p.assign(path).append("\\*").c_str(),&fileinfo)) != -1)
    {
        do {
            if  ((fileinfo.attrib & _A_SUBDIR))
            {
                if  (strcmp(fileinfo.name,".") != 0 && strcmp(fileinfo.name,"..") != 0)
                {
                    getFilesAll(  p.assign(path).append("\\").append(fileinfo.name) , files   );
                }
            }
            else
            {
                files.push_back(p.assign(path).append("\\").append(fileinfo.name) );
            }
        }while(_findnext(hFile, &fileinfo) == 0);
        _findclose(hFile);
    }
}

void postfix()
{
    char *filePath="G:\\image\\";
    char strname[60];
    vector<string> filesa;
    getFilesAll(filePath ,filesa );
    for(unsigned int i=0 ; i<filesa.size(); i++)
    {
        char newname[80]; //store the folder's name
        char oldname[80];

        strcpy(oldname, filesa[i].c_str());

        cout<<filesa[i].c_str()<<endl;
        //strcpy(newname, filesa[i].c_str());
        sprintf(newname,"G:\\result\\%d.jpg",i);
        //sprintf(newname,"%d.jpg",i);
        rename(oldname,newname);
        if (rename(oldname,newname))
        {
            cout<<"第"<<i<<"个文件名字"<<filesa[i].c_str()<<"修改为"<<newname<<"成功"<<endl;
        }
        cout<<strname<<endl;
    }
}
int main()
{
    postfix();
    system("pause");
}