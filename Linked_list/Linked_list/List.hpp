//  List.hpp
//  Linked_list
//  Created by Qian on 6/12/23.

#ifndef List_hpp
#define List_hpp
template <typename T>
class List{
public:
    virtual void InitList() = 0;
    virtual void DestroyList() = 0;
    virtual int Length() = 0;
    virtual T Get(int i) = 0;
    virtual int Locate(T &x) = 0;
    virtual void Insert(int i, T x) = 0;
    virtual T Delete(int i) = 0;
    virtual bool Empty() = 0;
    virtual bool Full() = 0;
};
#endif /* List_hpp */
