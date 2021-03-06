#include<bits/stdc++.h>
using namespace std;

struct node
{
    int value;
    struct node* npx;
};
typedef struct node* NODE;

NODE XOR(NODE x, NODE y)
{
    //cout<<x->value<<" "<<y->value<<endl;
    return (NODE) ((uintptr_t) (x) ^ (uintptr_t) (y));

}
void insert_front(NODE *head,int data)
{
    NODE new_node;
    new_node=(NODE)malloc(sizeof(struct node));
    new_node->value = data;
    new_node->npx = XOR(*head,NULL);
    //cout<<head->value<<" "<<head->npx<<" ";
    if(*head!=NULL)
    {
        NODE p;
        p = XOR((*head)->npx,NULL);
        (*head)->npx = XOR(new_node,p);
        //cout<<head->value<<" "<<head->npx<<" ";
    }
    *head = new_node;

}
void insert_end(NODE *head, int data)
{
    NODE new_node;
    new_node=(NODE)malloc(sizeof(struct node));
    new_node->value = data;
    if(*head==NULL)
        {
            new_node->npx = XOR(*head,NULL);
            *head = new_node;
        }
    else
    {
        NODE curr;
        NODE prev=NULL;
        NODE next;
        curr = *head;
        while(XOR(prev,curr->npx)!=NULL)
        {
            next = XOR(prev,curr->npx);
            prev = curr;
            curr = next;
        }
        new_node->npx = curr;
        curr->npx = XOR(prev,new_node);

    }
    //return *head;
}
NODE del_front(NODE *head)
{

    if(*head==NULL)
    {
        return *head;
    }
    else
    {
        NODE curr = *head,next;
        next = XOR(curr->npx,NULL);
        next->npx = XOR(*head,XOR(next->npx,NULL));
        free(curr);
        *head = next;
        return *head;
    }
}
NODE del_end(NODE *head)
{
     if(*head==NULL)
    {
        return *head;
    }
    else
    {
        NODE curr = *head,next,prev=NULL;
         while(XOR(prev,curr->npx)!=NULL)
        {
            next = XOR(prev,curr->npx);
            prev = curr;
            curr = next;
        }
        prev->npx = XOR(prev->npx,XOR(curr,NULL));
        free(curr);
        return *head;
    }
}
void printNode(NODE *head)
{
    NODE curr;
    NODE prev=NULL;
    NODE next;
    curr = *head;
    while(curr!= NULL)
    {
        cout<< curr->value<<" ";
        next = XOR(prev,curr->npx);
        prev = curr;
        curr = next;
    }
}
int main()
{
    NODE head = NULL;
    int x,y;
    cout<<"Enter no of elements to be inserted at the beginning"<<endl;
    int n;
    cin>>n;
    cout<<"Enter elements"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        insert_front(&head,x);
    }
    cout<<"Elements in the list are: "<<endl;
    printNode(&head);
    cout<<endl;
    cout<<"Enter no of elements to be inserted at the end"<<endl;
    int k;
    cin>>k;
    cout<<"Enter elements"<<endl;
    for(int i=0;i<k;i++)
    {
        cin>>y;
        insert_end(&head,y);
    }
    cout<<"Elements in the list are: "<<endl;
    printNode(&head);
    cout<<endl;
    cout<<"Deletion at front"<<endl;
    head = del_front(&head);
    printNode(&head);
    cout<<endl;
    cout<<"Deletion at end"<<endl;
    head=del_end(&head);
    printNode(&head);
    return 0;

}


/*
Enter no of elements to be inserted at the beginning
3
Enter elements
1 2 3
Elements in the list are:
3 2 1
Enter no of elements to be inserted at the end
2
Enter elements
4 5
Elements in the list are:
3 2 1 4 5
Deletion at front
2 1 4 5
Deletion at end
2 1 4
*/



