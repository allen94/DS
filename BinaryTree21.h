//二叉树的非递归算法
//姓名：倪蔚青
//学号：5122119012
#ifndef _BinaryTree2_h
#define _BinaryTree2_h
#include <iostream>
#include "linkStack.h"
#include "linkQueue.h"
template <class T>
class BinaryTree2
{
private:
    struct Node
    {
        Node *left,*right;
        T data;
        Node():left(NULL),right(NULL) {}
        Node(T item,Node *L=NULL,Node *R=NULL):
            data(item),left(L),right(R) {}
        ~Node() {}
    };
    Node *root;
    struct StNode
    {
        Node *node;
        int TimePop;

        StNode(Node *N=NULL):node(N),TimePop(0) {}
    };

public:
    BinaryTree2() {root=NULL;}
    BinaryTree2(const T item) {root=new Node(item);}
    ~BinaryTree2() {clear();}
    T getRoot() const {return root->data;}
    T getLeft() const {return root->left->data;}
    T getRight() const{return root->right->data;}

    void makeTree(const T &x,BinaryTree2 &l,BinaryTree2 &r)
    {
        root=new Node(x,l.root,r.root);
        l.root=NULL;
        r.root=NULL;
    }

    void delLeft()
    {
        BinaryTree2 tmp=root->left;
        root->left=NULL;
        tmp.clear();
    }

    void delRight()
    {
        BinaryTree2 tmp=root->right;
        root->right=NULL;
        tmp.clear();
    }

    bool isEmpty() const {return root==NULL;}

    void clear()
    {
        if (root) clear(root);
        root=NULL;
    }
     int size() const {return size(root);}

     int height() const {return height(root);}

     void preOrder() const
     {
         linkStack <Node*> s;
         Node *current;
         cout<<"前序遍历"<<endl;
         s.push(root);
         while (!s.isEmpty())
         {
             current=s.pop();
             cout<<current->data;
             if (current->right) s.push(current->right);
             if (current->left) s.push(current->left);
         }

     }

     void midOrder() const
     {
         linkStack <StNode> s;
         StNode current(root);
         cout<<"中序遍历"<<endl;
         s.push(current);
         while(!s.isEmpty())
         {
             current=s.pop();
             if (++current.TimePop==2)
             {
                 cout<<current.node->data;
                 if (current.node->right) s.push(StNode(current.node->right));
                 else
                 {
                     s.push(current);
                     if (current.node->left) s.push(StNode(current.node->left));
                 }
             }
         }
     }

     void postOrder() const
     {
         linkStack <StNode> s;
         StNode current(root);
         cout<<"后序遍历"<<endl;
         s.push(current);
         while(!s.isEmpty())
         {
             current=s.pop();
             if (++current.TimePop==3)
             {
                 cout<<current.node->data;continue;
             }
             s.push(current);
             if (current.TimePop==1)
             {
                 if (current.node->left) s.push(StNode(current.node->left));
             }
             else
             {
                 if (current.node->right) s.push(StNode(current.node->right));
             }
         }

     }

     void createTree(T flag)
    {
        linkQueue <Node *> que;
        Node *tmp;
        T x,ld,rd;

        cout<<"请输入根节点"<<endl;
        cin>>x;
        root=new Node(x);
        que.enQueue(root);

        while(!que.isEmpty())
        {
            tmp=que.deQueue();
            cout<<"输入"<<tmp->data<<"的两个儿子（"<<flag<<"表示空结点）";
            cin>>ld>>rd;
            if (ld!=flag) {tmp->left=new Node(ld);que.enQueue(tmp->left);}
            if (rd!=flag) {tmp->right=new Node(rd);que.enQueue(tmp->right);}
        }
        cout<<"create completed!"<<endl;
    }


private:
    int height(Node *t) const
    {
        if (!t) return 0;
        else
        {
            int l=height(t->left),r=height(t->right);
            return 1+((l>r)? l:r);
        }
    }

    void clear(Node *t)
    {
        if (t->left) clear(t->left);
        if (t->right) clear(t->right);
        delete t;
    }

    int size(Node *t) const
    {
        if (!t) return 0;
        return 1+size(t->left)+size(t->right);
    }


};
#endif // _BinaryTree2_h
