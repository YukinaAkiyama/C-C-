#include <iostream>
using namespace std;
struct LinkNode
{
    int data;
    LinkNode* next;
};
LinkNode* minus_LinkList(LinkNode* A, LinkNode* B)
{
    LinkNode* finalA = A;
    LinkNode* tempA = A->next;
    LinkNode* tempB = B->next;
    while (tempA && tempB)
    {
        if (tempB->data == tempA->data)
        {
            tempA=tempA->next;
            A->next = tempA;
        }
        else if (tempB->data < tempA->data)
        {
            tempB = tempB->next;
            B = B->next;
        }
        else
        {
            tempA = tempA->next;
            A = A->next;
        }
    }
    return finalA;
}
void print_LinkList(LinkNode* finalA)
{
    while (finalA->next)
    {
        cout << finalA->next->data << " ";
        finalA=finalA->next;
    }
}
LinkNode* Create_LinkList(int* arr,int len)
{
    LinkNode* temp = new LinkNode();
    temp->next = NULL;
    LinkNode* head = temp;
    for (int i = 0; i < len; ++i)
    {
        LinkNode* newN = new LinkNode();
        newN->data = arr[i];
        newN->next = NULL;
        temp->next=newN;
        temp = temp->next;
    }
    return head;
}
int main()
{
    int arrA[] = { 1, 3, 5, 7 };
    int arrB[] = { 2, 3, 4, 5,6,8 };
    LinkNode* A = Create_LinkList(arrA, sizeof(arrA) / sizeof(int));
    LinkNode* B = Create_LinkList(arrB, sizeof(arrB) / sizeof(int));
    LinkNode* finalA = minus_LinkList(A, B);
    //print_LinkList(A);
    //print_LinkList(B);
    print_LinkList(finalA);
}
