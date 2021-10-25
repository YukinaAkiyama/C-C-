/**
 * 题目：四个同学参加某个考核，考核分为理论，操作和问答三个环节，每个环节结束后给出分数，最后根据每个同学总分排名。
 * 要求：
 *      1、设计一个学生类，每门课程录入时要求进行有效性检验，录入成绩必须在0~100之间；
 *      2. 类中定义三个静态成员变量存储每个环节学生的平均分，以反映每个环节情况；
 *      3、在类外定义一个计算排名的函数，声明为学生类的友元函数进行操作；
 *      4、编写完整程序输出考核最终排名，以及每个环节的平均分。
 */

#ifndef student_h
#define student_h
class student
{
private:
    static float avg1, avg2, avg3;
    static int total;
    static int rank[2][4];//0成绩 1序号
    float theory;
    float operate;
    float qa;
public:
    friend void printrank();
    friend void printavg();
    student();
};

#endif /* student_h */
