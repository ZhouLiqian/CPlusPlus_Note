//  LinkList.cpp
//  Linked_list
//  Created by Qian on 6/12/23.

#include "LinkList.hpp"

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
    Node<T> *p = head;
    int k = 0;
    if(i <= 0 || i > Length())
        throw "查询元素位置错误!";
    while (p) {
        if(k == i)
            return p -> data;
        p = p -> next;
        k++;
    }
}
//定位元素
template <typename T>
int LinkList<T>::Locate(T &x){
    Node<T> *p = head;
    int l = 0;
    while (p && p -> next != x) {
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
    Node<T> *p = head, *q;
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
template <typename T>
ostream &operator << (ostream &os, LinkList<T> &l){
    Node<T> *p = l.head -> next;
    while (p) {
        os << p -> data << "\n";
        p = p -> next;
    }
    return os;
}
