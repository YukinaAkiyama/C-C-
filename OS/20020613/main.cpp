/*磁盘调度算法:
  先来先服务：按进程的先后顺序进行调度
  最短寻道：对磁道距离最短的磁道进行访问
  扫描算法：沿着一个方向，由里向外扫描磁道，到最外层磁道，然后变换为由外向里扫描磁道
  循环扫描算法：只能沿着一个方向，有里向外扫描磁道，到最外层磁道时转换为最里层的磁道

  测试数据：
  9个磁道：55 58 39 18 90 160 150 38 184
  9个磁道：67 92 79 64 130 150 45 28 12
  8个磁道：90 87 101 76 12 64 73 23
  8个磁道：87 90 76 101 12 64 73 120
*/

#include<iostream>
#include<cmath>
using namespace std;

typedef struct Disk_Schedule
{
    int NextTrack;
    int MovedTrack;
}Disk;

Disk *Track;
float SumMovedTrack=0;
int TrackNum;  //要访问的磁盘数
int NowTrack; //当前磁道号

void Input()  //输入起始磁道号、访问磁盘数量、磁道顺序
{
    cout<<"请输入当前的磁道号:";
    cin>>NowTrack;
    cout<<"请输入进程要访问的磁盘数:";
    cin>>TrackNum;
    Track=new Disk[TrackNum];
    cout<<"请依次输入进程要访问的磁盘号：";
    for(int i=0;i<TrackNum;i++)
    {
        cin>>Track[i].NextTrack;
    }
    cout<<"输入完毕!"<<endl<<endl;
}

void Output() //输出磁道访问信息,下个访问磁道编号,移动磁道数
{
    cout<<"输出磁道访问信息:"<<endl;
    cout<<"下一个被访问磁道"<<"\t"<<"移动的磁道数"<<endl;
    for(int i=0;i<TrackNum;i++)
    {
        cout<<"\t"<<Track[i].NextTrack<<"\t\t"<<Track[i].MovedTrack<<endl;
    }
    float SumMovedTrack=0;      //初始化SumMovedTrack为0
    for(int i=0;i<TrackNum;i++)
    {
        SumMovedTrack+=Track[i].MovedTrack;
    }
    cout<<"磁头移动总距离:"<<SumMovedTrack<<endl;
    cout<<"平均磁盘移动长度:"<<SumMovedTrack/TrackNum<<endl;
    cout<<"输出完毕！"<<endl<<endl;

}

void FCFS()
{
    Input();
    Track[0].MovedTrack=abs(NowTrack-Track[0].NextTrack);
    for(int i=1;i<TrackNum;i++)
    {
        Track[i].MovedTrack=abs(Track[i-1].NextTrack-Track[i].NextTrack);
    }
    cout<<"FCFS调度算法:"<<endl;
    Output();
}

void SSTF()                       //定义最短寻道算法
{
    Input();
    int NewTrack[50],Moved[50];     //定义两个数组，分别存放下次要访问的磁道数和磁道移动数
    int i,j,k,t,n,m=0,temp;
    /*for(i=0;i<TrackNum-1;i++)
    {
        for(j=i+1;j<TrackNum;j++)
        {
            if(Track[i].NextTrack>Track[j].NextTrack)
            {
                int temp;
                temp=Track[i].NextTrack;
                Track[i].NextTrack=Track[j].NextTrack;
                Track[j].NextTrack=temp;
            }
        }
    }*/                           //对存放下次要访问磁道数的数组进行冒泡排序
    for(i=0;i<TrackNum;i++)
    {
        for(j=m;j<TrackNum;j++)
            Moved[j]=abs(Track[j].NextTrack-NowTrack);         //计算出移动磁道数，并赋值到数组
        n=1000;                          //最大移动磁道数为1000
        for(k=m;k<TrackNum;k++)
        {
            if(Moved[k]<n)
            {
                n=Moved[k];
                t=k;
            }
        }           //找出移动磁道数最小的磁道序号并赋值给t
        NewTrack[m]=Track[t].NextTrack;               //根据最短寻道算法，对每次下次要访问的磁道赋值
        Track[m].MovedTrack=Moved[t];           //计算移动的磁道数
        NowTrack=Track[t].NextTrack;           //改变当前所在磁道数

        temp=Track[m].NextTrack;
        Track[m].NextTrack=Track[t].NextTrack;
        Track[t].NextTrack=temp;                 //交换
        m++;
    }
    for(i=0;i<TrackNum;i++)
        Track[i].NextTrack=NewTrack[i];

    cout<<"SSTF调度算法:"<<endl;
    Output();
}

void SCAN()
{
    int i,j,key,index=0;
    int NewTrack[50];
    Input();
    for (i=1; i < TrackNum; i++)          //对磁道进行降序排序
    {
        key= Track[i].NextTrack;
        for(j=i-1;j >=0 && key > Track[j].NextTrack;j--)
        {
            Track[j + 1].NextTrack = Track[j].NextTrack;
        }
        Track[j+1].NextTrack = key;
    }
    for(i=0;i<TrackNum;i++)           //找出当前磁道所在的位置
    {
        if(Track[i].NextTrack>NowTrack)
        { 	index++;  }
        else
            break;
    }
    for(i=0;i<index;i++)                     //由里向外，从当前磁道开始依次访问
        NewTrack[i]=Track[index-i-1].NextTrack;
    for(i=index;i<TrackNum;i++)             //到达最外层磁道，则由最外层磁道向里，依次访问内部磁道
        NewTrack[i]=Track[i].NextTrack;
    for(i=0;i<TrackNum;i++)             //将排好序的下一个被访问的磁道的中间变量数组赋给原始数组
        Track[i].NextTrack=NewTrack[i];
    Track[0].MovedTrack=abs(NowTrack-Track[0].NextTrack);    //计算每一磁道的移动数
    for(i=1;i<TrackNum;i++)
    {
        Track[i].MovedTrack=abs(Track[i-1].NextTrack-Track[i].NextTrack);
    }
    cout<<"SCAN调度算法:"<<endl;
    Output();
}

void CSCAN()
{
    int i,j,key,index=0;
    int NewTrack[50];
    Input();
    for (i=1; i < TrackNum; i++)           //对磁道进行降序排序
    {
        key= Track[i].NextTrack;
        for(j=i-1;j >=0 && key > Track[j].NextTrack;j--)
        {
            Track[j + 1].NextTrack = Track[j].NextTrack;
        }
        Track[j+1].NextTrack = key;
    }
    for(i=0;i<TrackNum;i++)            //找出当前磁道所在的位置
    {
        if(Track[i].NextTrack>NowTrack)
        { 	index++;  }
        else
            break;
    }
    for(i=0;i<index;i++)		       //由里向外，从当前磁道开始依次访问
        NewTrack[i]=Track[index-1-i].NextTrack;
    /*for(i=index;i<(TrackNum-index)/2;i++)
    {
        t=Track[i].NextTrack;
        Track[i].NextTrack=Track[TrackNum-1-i].NextTrack;
        Track[TrackNum-1-i].NextTrack=t;
    }*/
    /*for(i=index,j=TrackNum-1;Track[i].NextTrack>Track[j].NextTrack;i++,j--)
    {    key=Track[i].NextTrack;
        Track[i].NextTrack=Track[j].NextTrack;
        Track[j].NextTrack=key;   }*/
    for(i=index;i<TrackNum;i++)            //到达最外层磁道，则由最内层磁道向外，依次访问剩余磁道
        NewTrack[i]=Track[TrackNum+(index-1)-i].NextTrack;
    for(i=0;i<TrackNum;i++)
        Track[i].NextTrack=NewTrack[i];
    Track[0].MovedTrack=abs(NowTrack-Track[0].NextTrack);
    for(i=1;i<TrackNum;i++)
    {
        Track[i].MovedTrack=abs(Track[i-1].NextTrack-Track[i].NextTrack);
    }
    cout<<"CSCAN调度算法:"<<endl;
    Output();
}


void Menu() //展示界面
{
    cout<<"*************************磁盘调度系统*******************************"<<endl;
    cout<<"\t"<<endl;
    cout<<"\t┣  0:退出系统            ┫"<<endl;
    cout<<"\t┣  1:FCFS调度算法        ┫"<<endl;
    cout<<"\t┣  2:SSTF调度算法        ┫"<<endl;
    cout<<"\t┣  3:SCAN调度算法        ┫"<<endl;
    cout<<"\t┣  4:CSCAN调度算法       ┫"<<endl;
    cout<<"\t"<<endl;
}

int main()
{

    int choice;
    choice=-1;
    while(choice!=0)
    {   Menu();
        cout<<"请输入你的选择:";
        cin>>choice;
        switch(choice)
        {
            case 1: FCFS();break;
            case 2: SSTF();break;
            case 3: SCAN();break;
            case 4: CSCAN();break;
        }
    }
    return 0;
}
