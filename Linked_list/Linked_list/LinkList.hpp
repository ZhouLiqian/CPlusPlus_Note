//  LinkList.hpp
//  Linked_list
//  Created by Qian on 6/12/23.

#ifndef LinkList_hpp
#define LinkList_hpp
#include "List.hpp"
#include <iostream>
using namespace::std;

template <typename T>
struct Node{
    T data;
    Node<T> *next;
};
template <typename T>
class LinkList : public List<T>{
    //要点：模板体内要另建模板
    template <typename C>
    friend ostream &operator << (ostream &, LinkList<C> &);
public:
    LinkList(){ InitList();}
    LinkList(T a[], int n);
    ~LinkList(){DestroyList();}
    virtual void InitList();
    virtual void DestroyList();
    virtual int Length();
    virtual T Get(int i);
    virtual int Locate(T &x);
    virtual void Insert(int i, T x);
    virtual T Delete(int i);
    virtual bool Empty();
    virtual bool Full();
private:
    Node<T> *head;
};
//初始化链表: n个元素
template <typename T>
LinkList<T>::LinkList(T a[], int n){
    InitList();
    Node<T> *p = head, *s;
    for(int i = 0; i < n; i++){
        s = new Node<T>;
        s -> data = a[i];
        s -> next = p -> next;
        p -> next = s;
        p = s;
    }
}
//初始化链表: 0个元素
template <typename T>
void LinkList<T>::InitList(){
    head = new Node<T>;
    head -> next = nullptr;
}
//释放元素
template <typename T>
void LinkList<T>::DestroyList(){
    Node<T> *p = head, *q;
    while (p) {
        q = p;
        p = p -> next;
        delete q;
    }
}
//链表长度
template <typename T>
int LinkList<T>::Length(){
    int num = 0;
    Node<T> *p = head -> next;
    while (p) {
        num++;
        p = p -> next;
    }
    return num;
}
//获取元素
template <typename T>
T LinkList<T>::Get(int i){
    T tmp;
    Node<T> *p = head;
    tmp = p -> data;
    int k = 0;
    if(i <= 0 || i > Length())
        throw "查询元素位置错误!";
    while (p) {
        if(k == i)
            return p -> data;
        p = p -> next;
        k++;
    }
    return tmp;
}
//定位元素
template <typename T>
int LinkList<T>::Locate(T &x){
    Node<T> *p = head;
    int l = 0;
    while (p && p -> data != x) {
        p = p -> next;
        l++;
    }
    return p?l:0;
}
//插入元素
template <typename T>
void LinkList<T>::Insert(int i, T x){
    Node<T> *p = head, *s;
    if(i <= 0 || i > Length() + 1)
        throw "元素插入位置错误!";
    for(int j = 0; j < i - 1; j++)
        p = p -> next;
    s = new Node<T>;
    s -> data = x;
    s -> next = p -> next;
    p -> next = s;
}
//删除元素
template <typename T>
T LinkList<T>::Delete(int i){
    Node<T> *p = head, *q = nullptr;
    T tmp;
    if(i <= 0 || i > Length())
        throw "元素插入位置错误!";
    for(int j = 0; j < i; j++){
        q = p;
        p = p -> next;
    }
    tmp = p -> data;
    q -> next = p -> next;
    delete p;
    return tmp;
}
//判断空
template <typename T>
bool LinkList<T>::Empty(){
    return head -> next == nullptr;
}
//判断满
template <typename T>
bool LinkList<T>::Full(){
    return false;
}
//输出函数
template <typename C>
ostream &operator << (ostream &os, LinkList<C> &l){
    Node<C> *p = l.head -> next;
    while (p) {
        os << p -> data << "\n";
        p = p -> next;
    }
    return os;
}
#endif /* LinkList_hpp */
