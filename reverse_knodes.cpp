#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node* next;
};
typedef struct node* NODE;

NODE getnode()
{
	NODE p;
	p=(NODE)malloc(sizeof(struct node));
	if(p!=NULL)
		return p;
	else
        exit(0);
}
NODE insert_front(NODE head,int item)
{
	NODE p;
	p=getnode();
	p->data=item;
	p->next=head;
	head=p;
	return head;
}
void display(NODE head)
{
	NODE p;
	if(head==NULL)
	{
		printf("List is empty\n");
		exit(0);
	}
	p=head;
	while(p!=NULL)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
}
NODE reverse_list(NODE *head ,int k)
{
     NODE temp,next=NULL,prev=NULL;
     //temp= *head;
    int count = k;
     while(count>0 && *head !=NULL)
     {
       next = (*head)->next;
       (*head)->next = prev;
       prev = (*head);
       (*head) = next;
       count--;
     }
     return prev;
}

NODE reverse_knodes(NODE head, int k)
{
	if (head == NULL)
		return NULL;
	NODE p = head;
	NODE q = reverse_list(&p, k);
	head->next = reverse_knodes(p, k);
	return q;
}

int main()
{
    int n,k;
    NODE head = NULL;
    cout<<"Enter no of elements in list"<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        head=insert_front(head,x);
    }
    cout<<"Initial elements in list are"<<endl;
    display(head);
    cout<<"Enter the breaking point"<<endl;
    cin>>k;
    head = reverse_knodes(head,k);
    cout<<"After performing the operations"<<endl;
    display(head);
    return 0;
}
