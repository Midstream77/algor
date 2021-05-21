// LinkList.cpp
#include "LinkList.h"
#include <string>

LinkList::LinkList(DataType data){
    head = new node{data,NULL};
    size = 1;
}
void LinkList::pushfront(DataType data){
    this->head = new node{data,this->head};
    this->size++;
}
void LinkList::pushback(DataType data){
    node* tmp;
    tmp = this->head;
    while(tmp->next!=NULL){
        tmp = tmp->next;
    }
    tmp->next = new node{data,NULL};
    this->size++;
}
void LinkList::insert(DataType data, int index){
    if(index<=0){
        this->pushfront(data);
        return;
    }
    if(index>=this->size){
        this->pushback(data);
        return;
    }
    node* tmp;
    tmp = this->head;
    for(int i=1;i<index;i++){
        tmp=tmp->next;
    }
    tmp->next = new node{data,tmp->next};
    this->size++;
}
DataType LinkList::popfront(){
    DataType tmp = head->data;
    head = head->next;
    size--;
    return tmp;
}
DataType LinkList::popback(){
    node* tmp = head;
    for(int i=2;i<size;i++){
        tmp = tmp->next;
    }
    tmp->next = NULL;
    size--;
    return tmp->data;
}
void LinkList::del(int index){
    if(index<1){
        this->popfront();
        return;
    }
    if(index>=this->size){
        this->popback();
        return;
    }
    node* tmp = head;
    for(int i=1;i<index;i++){
        tmp = tmp->next;
    }
    tmp->next = tmp->next->next;
    size--;
}
int LinkList::remove(DataType data){
    node* tmp = this->head;
    if(tmp->data==data){
        this->popfront();
        return 0;
    }
    while(tmp->next!=NULL){
        if(tmp->next->data==data){
            tmp->next = tmp->next->next;
            size--;
            return 0;
        }
        tmp = tmp->next;
    }
    return 1;
}
int LinkList::removeall(DataType data){
    int tmp = 0;
    while(tmp!=1){
        tmp = this->remove(data);
    }
    if(tmp==1) return 0;
    return 1;
}
void LinkList::print(){
    string res;
    node* tmp;
    tmp = this->head;
    while(tmp!=NULL){
        res = res.append(std::to_string(tmp->data).append("->"));
        tmp = tmp->next;
    }
    res = res.substr(0,res.find_last_of('-'));
    cout<<res<<endl;
}

int main(){
    LinkList* plist = new LinkList(3);

    //test
    plist->pushfront(2);
    plist->pushfront(1);
    plist->pushback(4);
    plist->pushback(5);
    plist->print();//1->2->3->4->5

    plist->insert(3,2);
    plist->print();//1->2->3->3->4->5
    
    plist->popfront();
    plist->popback();
    plist->removeall(3);
    plist->print();//2->4

    plist->insert(3,1);
    plist->del(1);
    plist->print();//2->4
}
