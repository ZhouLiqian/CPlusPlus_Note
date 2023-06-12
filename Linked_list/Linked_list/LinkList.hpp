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
    friend ostream &operator << (ostream &, LinkList<T> &);
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
#endif /* LinkList_hpp */
