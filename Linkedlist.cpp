#include<bits/stdc++.h>
using namespace std;


class node
{
    public:
    int data;
    node* next;
};


void print(node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}

void reverse(node* head)
{
    if(head==NULL) return;
    reverse(head->next);
    cout<<head->data<<" ";
}

void addfront(node** f)
{
    node* add=new node();
    add->data=0;
    add->next=*f;
    *f=add;
}

void addbw(node* s)
{
        node* bw=new node();
        bw->data=-1;
        bw->next=s->next;
        s->next=bw;
}


void addlast(node* f)
{
    node* last=new node();
    node* head=new node();
    head=f;
    while(head->next!=NULL)
    head=head->next;
    last->data=4;
    head->next=last;
    last->next=NULL;
}


void swap(node **head,int x,int y)
{
  if(x==y) return;
  node *prevx=0;
  node *curx=*head;
  while(curx and curx->data!=x)
  {
      prevx=curx;
      curx=curx->next;
  }
  node *prevy=0;
  node *cury=*head;
  while(cury and cury->data!=y)
  {
      prevy=cury;
      cury=cury->next;
  }
  if(curx==NULL || cury==NULL) return;
  if(prevx!=NULL)
  {
      prevx->next=cury;
  }
  else
  {
      *head=cury;
  }
   if(prevy!=NULL)
  {
      prevy->next=curx;
  }
  else
  {
      *head=curx;
  }
  node *tmp=curx->next;
  curx->next=cury->next;
  cury->next=tmp;


}

void movelast(node **head)
{
    node *prev=*head;
    node *fst=*head;
    while(fst->next!=NULL)
    {
        prev=fst;
        fst=fst->next;
    }
    prev->next=NULL;
    fst->next=*head;
    *head=fst;

}
int main()
{
    node* f=new node();
    node* s=new node();
    node* t=new node();
    f->data=1;
    f->next=s;
    s->data=2;
    s->next=t;
    t->data=3;
    t->next=NULL;
    addfront(&f);
    addbw(s);
    addlast(f);

     print(f);
     movelast(&f);
    // swap(&f,2,4);

        
cout<<endl;
    print(f);
    
   
}