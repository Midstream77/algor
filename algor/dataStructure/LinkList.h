//头文件LinkList.h
#include <iostream>
#include <cstdlib>
using namespace std;

typedef int DataType;

//构造节点
class node{
public:
    DataType data;
    node* next;
};

//构造链表
class LinkList{
public:
    //初始化
    LinkList(DataType data);

    //头插
    void pushfront(DataType data);
    //尾插
    void pushback(DataType data);
    //按下标插入
    void insert(DataType data, int index);
    //首端出栈
    DataType popfront();
    //弹栈
    DataType popback();

    //按下标删除
    void del(int index);
    //按值删除第一个
    int remove(DataType data);
    //按值删除全部
    int removeall(DataType data);

    //打印
    void print();

    node* head;
    int size;
};