#include <iostream>
#include <cstdlib>
using namespace std;

typedef int DataType;

class node{
public:
    node(DataType data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

    DataType data;
    node* left;
    node* right;

    //provide recursive choice for public functions
    node* find(node* pnode, DataType data){
        if(pnode == NULL) return NULL;
        if(pnode->data == data) return pnode;
        if(pnode->data > data) return find(pnode->left,data);
        if(pnode->data < data) return find(pnode->right,data);
    }

    node* find_pre(node* pnode, DataType data){
        if(pnode == NULL) return NULL;
        if(pnode->right!=NULL&&pnode->right->data==data) return pnode;
        if(pnode->left!=NULL&&pnode->left->data==data) return pnode;
        if(pnode->data > data) return find_pre(pnode->left,data);
        if(pnode->data < data) return find_pre(pnode->right,data);
    }

    int find_min(){
        node* tmp = this;
        if(tmp==NULL){
            return -1;
        }
        while(tmp->left!=NULL){
            tmp = tmp->left;
        }
        return tmp->data;
    }
};

class BST{

public:
    BST();
    BST(DataType data);
    BST(DataType* arr, int length);
    void insert(DataType data);
    int del(DataType data);
    int del_all(DataType data);
    int find_max();
    int find_min();
    int find(DataType data);
    void preorder(node* root);
    void inorder(node* root);
    void postorder(node* root);

    node* root;

};