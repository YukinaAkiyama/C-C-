/**
 * ��Ŀ���ĸ�ͬѧ�μ�ĳ�����ˣ����˷�Ϊ���ۣ��������ʴ��������ڣ�ÿ�����ڽ��������������������ÿ��ͬѧ�ܷ�������
 * Ҫ��
 *      1�����һ��ѧ���࣬ÿ�ſγ�¼��ʱҪ�������Ч�Լ��飬¼��ɼ�������0~100֮�䣻
 *      2. ���ж���������̬��Ա�����洢ÿ������ѧ����ƽ���֣��Է�ӳÿ�����������
 *      3�������ⶨ��һ�����������ĺ���������Ϊѧ�������Ԫ�������в�����
 *      4����д��������������������������Լ�ÿ�����ڵ�ƽ���֡�
 */

#ifndef student_h
#define student_h
class student
{
private:
    static float avg1, avg2, avg3;
    static int total;
    static int rank[2][4];//0�ɼ� 1���
    float theory;
    float operate;
    float qa;
public:
    friend void printrank();
    friend void printavg();
    student();
};

#endif /* student_h */
