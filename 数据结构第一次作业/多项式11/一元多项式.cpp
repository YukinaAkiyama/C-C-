#include<stdio.h>
#include<stdlib.h>
#include<math.h> 
 
#define LEN sizeof(Poly)
 
typedef struct term{
    float coef;        //ϵ�� 
    int expn;        //ָ�� 
    struct term *next;
}Poly,*Link;
int LocateElem(Link p, Link s, Link &q); 
void CreatePolyn(Link &p,int m);    //��������ʽ 
void PrintPolyn(Link p);            //��ӡ����ʽ����ʾ��            
int cmp(Link a, Link b);
Link AddPolyn(Link pa, Link pb);    //����ʽ��� 
Link SubPolyn(Link pa, Link pb);    //����ʽ��� 
Link Reverse(Link p);                //���ö���ʽ 
Link MultiplyPolyn(Link A,Link B);    //����ʽ��� 
void Calculate(Link p,float x);        //����ʽ��ֵ 
//������
int main()
{
    Link P1,P2,P3;    //����ʽ 
    int L1,L2;        //����ʽ���� 
    printf("                        -------------------------------------------------------------------\n");
    printf("                        |==================       һԪ����ʽ������       =================|\n");
    printf("                        |==================          1.��ӣ�+��         =================|\n");
    printf("                        |==================          2.�����-��         =================|\n");
    printf("                        |==================          3.��ˣ�*��         =================|\n");
    printf("                        -------------------------------------------------------------------\n\n");
    printf("�������һ������ʽ��������");
    scanf("%d",&L1);
    CreatePolyn(P1,L1);
    printf("��һ������ʽΪ��");
    printf("P1(X)=");
    PrintPolyn(P1);
    printf("������ڶ�������ʽ��������");
    scanf("%d",&L2);
    CreatePolyn(P2,L2);
    printf("�ڶ�������ʽΪ��");
    printf("P2(X)=");
    PrintPolyn(P2); 
    printf("\n");
    
    printf("������Ҫѡ�������(+ , - , *): ");
    char ch1;
    getchar();        //������������Ļس��� 
    scanf("%c",&ch1);
    getchar();        //������������Ļس���
     switch(ch1){
         case '+':{
             printf("����һԪ����ʽ��ӣ�   ");
             printf("P1(X)+P2(X)=");
             P3=AddPolyn(P1, P2);
            PrintPolyn(P3);
         }break;
         case '-':{
             printf("����һԪ����ʽ�����   ");
             printf("P1(X)-P2(X)=");
             P3=SubPolyn(P1, P2);
            PrintPolyn(P3);
         }break;
         case '*':{
             printf("����һԪ����ʽ��ˣ�   ");
             printf("P1(X)*P2(X)=");
             P3=MultiplyPolyn(P1, P2);
            PrintPolyn(P3);
         }break;
         default:printf("�������˴���ָ�� %c ��",ch1); 
     }
 
    char ch2;
    printf("\n�Ƿ����X������ֵ��(Y/N): ");
    ch2=getchar();        //������������Ļس���  
    getchar();
    switch(ch2){
        case 'Y':{
            float x;
            printf("\n���������ʽ��X��ֵ��");
            scanf("%f",&x); 
            Calculate(P3,x);
            break;    
        }
        case 'N':break;
        default:printf("�������˴���ָ�� %c ��",ch2); 
    } 
    return 0;
}
//��������ʽ����
int LocateElem(Link p, Link s, Link &q){
/*
��������p��ÿһ�������s�Ƚ�ָ����
����ͬ,qָ����ָͬ����Ľ�㣬����1��
������ͬ������s��ָָ����С������p�е�λ����ȷ��q��ָ���㣬����0 
*/ 
    Link p1 = p->next;
    Link p2 = p;
    while(p1){
        if(s->expn > p1->expn){
            p1 = p1->next;
            p2 = p2->next;
        }else if(s->expn == p1->expn){
            q = p1; 
            return 1;
        }else{
            q = p2;
            return 0;
        }
    }
    if(!p1){
        q = p2;
        return 0;
    }
}
 
void CreatePolyn(Link &p,int m) 
/*
������ͷ��������(����ʽ) 
�����۰�ʲô˳�����룬��������ָͬ����
�����ڶ���ʽ�ж�������˳�� 
*/
{
    Link s,q;
    int i;
    p=(Link)malloc(LEN);
    p->next=NULL;
    for(i=0;i<m;i++)
    {
        s=(Link)malloc(LEN);
        printf("����ϵ����ָ�����Կո������:");
        scanf("%f %d", &s->coef, &s->expn);
        if(!LocateElem(p, s, q)){    //��û����ָͬ��������� 
            s->next = q->next;
            q->next = s;
        }else{                        //������ָͬ�����ϵ�����                        
            q->coef+=s->coef;
        }
    }
}
//��ӡ����ʽ����
void PrintPolyn(Link p)
//��ӡ��ʾ����ʽ 
{
    Link s;
    s = p->next;
    while(s)
    {
            printf(" %.2f X^%d", s->coef, s->expn);
            s = s->next;
            if(s!=NULL)  
                if(s->coef>=0) printf(" +");
                //����һ��ϵ��Ϊ�������ӡ'+',���򲻴�ӡ 
    }
    printf("\n");
}
//����ʽ��ӣ��������
int cmp(Link a, Link b)
//�Ƚ������ָ����С������������ز�ֵͬ 
{
    if (a->expn<b->expn) return  -1;
    else if(a->expn == b->expn) return  0;
    else return 1;
}
 
Link AddPolyn(Link pa, Link pb)//pa,pb��ָ��ͷ��� 
//��������ʽ��ӵ�һ���¶���ʽ�����ҷ����¶���ʽ��ͷ����ָ��   
{
    Link newp, p, q, s, pc;
    float sum;
    p = pa->next; 
    q = pb->next;
    newp=(Link)malloc(LEN); //�¶���ʽ��ͷ��� 
    pc = newp;    //pcָ���¶���ʽ��ͷ���
    while(p&&q){
        switch(cmp(p, q))
        {
            case -1:// //��ָ����p<q,��p��ָ�������ͷ���Ϊnewp�������У���p������   
                s = (Link)malloc(LEN); 
                s->coef = p->coef;
                s->expn = p->expn;
                pc->next = s;
                pc = s;
                p = p->next;
                break;
            case 0://���Ƚ������ָ����ȣ�������ϵ����Ӻ�õ��������ͷ���Ϊnewp�������� ����p,qͬʱ������  
                sum = p->coef+q->coef; 
                if(sum!=0.0)//������ϵ�����Ϊ0���򲻷���ͷ���Ϊnewp��������
                {
                    s = (Link)malloc(LEN);
                    s->coef = sum;
                    s->expn = p->expn;
                    pc->next = s;
                    pc = s;
                }
                p = p->next;
                q = q->next;
                break;
            case 1://��ָ����q<p,��q��ָ�������ͷ���Ϊnewp�������У���q������    
                s = (Link)malloc(LEN);
                s->coef = q->coef;
                s->expn = q->expn;
                pc->next = s;
                pc = s;
                q = q->next;
                break;
        }
    }
    pc->next=p?p:q;//����pa��pb��ʣ���� 
    return newp;//�����¶���ʽ��ͷָ�� 
}
Link SubPolyn(Link pa, Link pb)
/*
��������ʽ�����һ���¶���ʽ�����ҷ����¶���ʽ��ͷ����ָ��
��������Ƚ�������ÿһ���ϵ����Ϊ�����ٽ���������ʽ��� 
*/ 
{
    Link newp, p, q, s, pc;
    float sum;
    newp=(Link)malloc(LEN); 
    pc = newp;
    p = pa->next; 
    q = pb->next;
    while(q){// ��pb��ÿһ���ϵ����Ϊ�� 
        q->coef=0-q->coef;
        q=q->next;
    }
    q=pb->next;
    while(p&&q){
        switch(cmp(p, q))
        {
            case -1:  
                s = (Link)malloc(LEN); 
                s->coef = p->coef;
                s->expn = p->expn;
                pc->next = s;
                pc = s;
                p = p->next;
                break;
            case 0: 
                sum = p->coef + q->coef;//�����ѣ�����ǰ�����ϵ���ѱ䣬�������ﻹ����ӣ�лл�� 
                if(sum!=0.0)
                {
                    s = (Link)malloc(LEN);
                    s->coef = sum;
                    s->expn = p->expn;
                    pc->next = s;
                    pc = s;
                }
                p = p->next;
                q = q->next;
                break;
            case 1:    
                s = (Link)malloc(LEN);
                s->coef = q->coef;
                s->expn = q->expn;
                pc->next = s;
                pc = s;
                q = q->next;
                break;
        }
    }
    pc->next=p?p:q;
    return newp;
}
//����ʽ��˲���
Link Reverse(Link p)
/*
��ͷ�巨��������
ʹ����ʽ�ɽ��ݱ������˳��
��ʹ����ʽ�����ݱ�ɽ���˳��
*/ 
{
    Link head=p; 
    Link q1,q2;
    q2=head->next;
    head->next=NULL;//�Ͽ�ͷ������һ����� 
    while(q2)
    {
        q1=q2;      
        q2=q2->next; 
        q1->next=head->next; //ͷ�� 
        head->next=q1;  
    }      
    return head;//�����������ú��ͷ��� 
}
Link MultiplyPolyn(Link A,Link B)
/*
    ��������ʽ��˵�һ���¶���ʽ�����ҷ����¶���ʽ��ͷ����ָ��
    ���ǰ��A��B��������ʽ������������ 
    ���ʱ��AΪ��������BΪ��������  
*/
{
  Link pa,pb,pc,s,head;
  int k,maxExpn,minExpn;
  float coef;
  
  head=(Link)malloc(LEN);//ͷ��� 
  head->next=NULL;
  
  if(A->next!=NULL&&B->next!=NULL){
      minExpn=A->next->expn+B->next->expn; //minExpnΪ��������ʽ��ָ���͵���Сֵ 
     A=Reverse(A);//��A�������� 
    B=Reverse(B);//��B�������� 
      maxExpn=A->next->expn+B->next->expn; //maxExpnΪ��������ʽ��ָ���͵����ֵ
  }
  else{
          return head;
  }       
   pc=head;
   B=Reverse(B);//��B�������� 
   
   for(k = maxExpn;k>=minExpn;k--){ //����ʽ�ĳ˻�ָ����ΧΪ��minExpn~maxExpn
           //���������ָ����ʹÿһ��ѭ�����õ��¶���ʽ��һ��  
           pa = A->next;
           while(pa !=NULL&&pa->expn>k){  //�ҵ�pa��λ�� 
               pa = pa->next;
           }
           pb = B->next;
           while(pb!=NULL&&pa!=NULL&&pa->expn+pb->expn<k){//���ָ���ͺ�С��k��pb���ƽ�� 
               pb = pb->next;
           }
        coef=0.0;
        while(pa!=NULL&&pb!=NULL){
            if(pa->expn+pb->expn==k){ //���ָ���͵���k,ϵ�����ۼӣ���pa��pb�����ƽ�� 
                coef+=pa->coef*pb->coef;
                pa=pa->next;
                pb=pb->next;
            }
            else if(pa->expn+pb->expn>k){//���ָ���ʹ���k��pb���ƽ��
                pa = pa->next;
            }
            else{//���ָ���ͺ�С��k��pb���ƽ��
                    pb = pb->next;
            }    
        }
        if(coef!=0.0){
        //���ϵ���Ͳ�Ϊ0���������½�㣬��ϵ����ָ�������½�����뵽�¶���ʽ�� 
            s=(Link)malloc(LEN);
            s->coef=coef;
            s->expn=k;
            s->next=pc->next;
            pc->next=s;
            pc=s;
        }
   }
   B = Reverse(B);
   head=Reverse(head);
   return head;    //�����¶���ʽ��ͷ��� 
}
//����ʽ��ֵ����
void Calculate(Link p,float x)
//����ȷ����x������ʽ����ֵ 
{
    Link q=p->next;
    float sum;
    float result=0;//��Ľ�� 
    while(q){
        sum=1.0;
        for(int i=1;i<=q->expn;i++){//����ÿһ��� X^expn ��ֵ 
                sum=sum*x;
        }
        result+=sum*q->coef; //��ʹϵ����sum��˺���ÿһ���ֵ������ۼ�
        q=q->next; 
    }
    printf("��X��ֵ�������ʽ�м���Ľ��Ϊ��%.5f\n",result);
} 