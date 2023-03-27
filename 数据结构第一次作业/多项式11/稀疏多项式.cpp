#include<stdio.h>
//#include<stdlib.h>
#include<iostream> 
//
using namespace std;


typedef struct PNode{
	float coef;
	int expn;
	struct PNode *next;
}PNode,*Polynomial;


//单个多项式指数相同时未进行处理。f(x)=3x^2+4x^2 
void CreatePolyn(Polynomial &p,int n){
	p = new PNode;
	PNode *s , *pre , *q;
//	Polynomial s , pre , q; 
	p->next = NULL;
	int i;
	for(i = 1;i<=n;++i){
		printf("请输入第%d系数和指数:\n",i);
		s = new PNode; 
		cin>>s->coef>>s->expn;
//		scanf("%f %d",&s->coef,&s->expn);
		pre = p;
		q = p->next;
		while(q && q->expn<s->expn){
			pre = q;
			q = q->next;
		}
		s->next = q;
		pre->next = s;
	}
}

void PrintPolyn(Polynomial &L){
	PNode *p;
	p = L->next;
	while(p){
		printf("%fX^%d+", p->coef,p->expn);
		p = p->next;
	}

}

void AddPolyn(Polynomial &Pa, Polynomial &Pb){
	PNode *p1 , *p2 , *p3 , *r;
	p1 = Pa->next;
	p2 = Pb->next;
	p3 = Pa;
	int sum = 0;
	while(p1&&p2){
		if(p1->expn == p2->expn){
			sum = p1->coef+p2->coef;
			if(sum != 0){
				p1->coef = sum;
				p3->next = p1;
				p3 = p1;
				p1 = p1->next;
				r = p2;
				p2 = p2->next;
				delete r;
			}else{
				r = p1;
				p1 = p1->next;
				delete r;
				r = p2;
				p2 = p2->next;
				delete r;
			}
		}else if(p1->expn < p2->expn){
			p3->next = p1;
			p3 = p1;
			p1 = p1->next;
		}else{
			p3->next = p2;
			p3 = p2;
			p2 = p2->next;
		}
	}
	p3->next = p1?p1:p2;
	delete Pb;
	PrintPolyn(Pa);
} 

int main(){
	PNode *p1,*p2;
	int n1,n2; 
	printf("请输入p1的项数\n"); 
	scanf("%d",&n1); 
	CreatePolyn(p1,n1); 
	
	printf("请输入p2的项数\n"); 
	scanf("%d",&n2); 
	CreatePolyn(p2,n2); 
	
	AddPolyn(p1,p2);
	return 0;
}
