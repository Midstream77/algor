#include "BST.hpp"

BST::BST(){
    this->root = NULL;
}

BST::BST(DataType data){
    this->root = new node(data);
    this->root->left = NULL;
    this->root->right = NULL;
}

BST::BST(DataType* arr, int length){
    this->root->data = arr[0];
    for(int i=1;i<length;i++){
        this->insert(arr[i]);
    }
}

int BST::find(DataType data){
//1 means find and 0 means can't find
    node* tmp = this->root;

    //iterative
    while(tmp!=NULL){
        if(tmp->data==data){
            return 1;
        }
        if(tmp->data<data){
            tmp = tmp->right;
            continue;
        }
        if(tmp->data>data){
            tmp = tmp->left;
        }
    }
    return 0;

/*  recursive
    if (this->root->find(tmp,data)==NULL)
        return 0;
    return 1;
*/
}

void BST::insert(DataType data){
    node* tmp = this->root;

    //iterative
    while(true){
        if(tmp->data==data){
            cout<<"key existed"<<endl;
            return;
        }
        if(tmp->data<data){
            if(tmp->right==NULL){
                tmp->right = new node(data);
                return;
            }
            tmp = tmp->right;
            continue;
        }
        if(tmp->data>data){
            if(tmp->left==NULL){
                tmp->left = new node(data);
                return;
            }
            tmp = tmp->left;
        }
    }
}

int BST::find_max(){
    node* tmp = this->root;
    if(tmp==NULL){
        cout<<"empty tree"<<endl;
        return -1;
    }
    while(tmp->right!=NULL){
        tmp = tmp->right;
    }
    return tmp->data;
}

int BST::find_min(){
    node* tmp = this->root;
    if(tmp==NULL){
        cout<<"empty tree"<<endl;
        return -1;
    }
    while(tmp->left!=NULL){
        tmp = tmp->left;
    }
    return tmp->data;
}

int BST::del(DataType data){
//0 means can't delete

    node* tmp = this->root;
    node* delnode = this->root->find(tmp,data);

    if(delnode == NULL) return 0;

    if(delnode->left==NULL&&delnode->right==NULL){
        node* predelnode = this->root->find_pre(tmp,data);
        if(predelnode->left!=NULL&&predelnode->left->data==data){
            predelnode->left=NULL;
            return 1;
        }
        predelnode->right=NULL;
        return 1;
    }

    if(delnode->left == NULL){
        delnode = delnode->right;
        return 1;
    }
    
    if(delnode->right == NULL){
        delnode = delnode->left;
        return 1;
    }

    int right_min = delnode->right->find_min();
    node* t = delnode->right->find(delnode->right,right_min);
    delnode->data = right_min;
    t = NULL;
}

void BST::preorder(node* root){
    if(root==NULL) return;
    cout<<root->data<<"\t";
    preorder(root->left);
    preorder(root->right);
}
void BST::inorder(node* root){
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<"\t";
    inorder(root->right);
}
void BST::postorder(node* root){
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<"\t";
}


//test
int main(){
    BST* p = new BST(3);
    p->insert(5);
    p->insert(4);
    p->insert(7);
    cout<<p->find(4)<<endl;//1
    cout<<p->find(9)<<endl;//0
    cout<<p->find_max()<<endl;//7
    p->del(7);
    p->inorder(p->root);//3 4 5
}