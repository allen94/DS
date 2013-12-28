//二叉树的递归算法
//姓名：倪蔚青
//学号：5122119012
#ifndef _BinaryTree_h
#define _BinaryTree_h
#include <iostream>
#include "linkStack.h"
#include "linkQueue.h"
template <class T>
class BinaryTree
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

public:
    BinaryTree() {root=NULL;}
    BinaryTree(const T item) {root=new Node(item);}
    ~BinaryTree() {clear();}
    T getRoot() const {return root->data;}
    T getLeft() const {return root->left->data;}
    T getRight() const{return root->right->data;}

    void makeTree(const T &x,BinaryTree &l,BinaryTree &r)
    {
        root=new Node(x,l.root,r.root);
        l.root=NULL;
        r.root=NULL;
    }

    void delLeft()
    {
        BinaryTree tmp=root->left;
        root->left=NULL;
        tmp.clear();
    }

    void delRight()
    {
        BinaryTree tmp=root->right;
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
         if (root)
         {
             cout<<"前序遍历"<<endl;
             preOrder(root);
        }
     }

     void midOrder() const
     {
         if (root)
         {
             cout<<"中序遍历"<<endl;
             midOrder(root);
         }
     }

     void postOrder() const
     {
         if (root)
         {
             cout<<"后序遍历"<<endl;
             postOrder(root);
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

    void preOrder(Node *t) const
    {
        if (t)
        {
            cout<<t->data<<endl;
            preOrder(t->left);
            preOrder(t->right);
        }
    }

    void midOrder(Node *t) const
    {
        if (t)
        {
            midOrder(t->left);
            cout<<t->data<<endl;
            midOrder(t->right);
        }
    }

    void postOrder(Node *t) const
    {
        if (t)
        {
            postOrder(t->left);
            postOrder(t->right);
            cout<<t->data<<endl;
        }
    }



};
#endif // _BinaryTree_h
