#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;

    node(int x)
    {
        data=x;
        left=NULL;
        right=NULL;
    }
};
void print(struct node *p)
{
    //inorder traves  of binery search tree
    //making own stack
    //left root right
    stack<node *>d;
    node *curr=p;
    while(curr!=NULL || d.empty()==false)
    {
        while(curr!=NULL)
        {
            d.push(curr);
            curr=curr->left;
        }
        curr=d.top();
        d.pop();
        cout<<curr->data<<"-";
        curr=curr->right;
    }
}
void print2(struct node *p)
{
    //postorder traves in binery tree 
    //making own stack
    //left right root
    stack<node *>d,d1;
    node *curr;
    d.push(p);
    while(!d.empty())
    {
             curr=d.top();
             d.pop();
             d1.push(curr);

             if(curr->left)
             d.push(curr->left);
             if(curr->right)
             d.push(curr->right);
    }
    while(!d1.empty())
    {
        curr=d1.top();
        d1.pop();
        cout<<curr->data<<"-";
    }
}

void print1(struct node *p )
{
    //preorder traves of binery tree
    //root left right
    stack<node *>d;
    d.push(p);
    while(d.empty()==false)
    {
        struct node *curr=d.top();
        cout<<curr->data<<"-";
        d.pop();
        if(curr->right)
            d.push(curr->right);
        if(curr->left)
            d.push(curr->left);

    }

}


int main()
{
    struct node *p=new node(5);
    p->left=new node(4);
    p->right=new node(3);

    print(p);
    cout<<endl;
    print1(p);
    cout<<endl;
    print2(p);
    return 0;
}
