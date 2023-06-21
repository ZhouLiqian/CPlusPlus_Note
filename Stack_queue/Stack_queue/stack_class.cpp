//  stack_class.cpp
//  Stack_queue
//  Created by Qian on 6/21/23.

#include "stack_class.hpp"

/*销毁栈需要明白一点: 是否可以销毁, 因为可能会出现不插入元素的情况下, 结束程序, 此时如果继续执行销毁, 就会发生空指针的解引用情况*/
void StackDestroy(StackTnfo *s){
    //报错函数
    assert(s);
    if(s -> data){
        //释放已分配的内存
        free(s -> data);
        s -> data = NULL;
        s -> top = s -> capacity = 0;
    }
    
}

/*入栈、出栈*/
void StackPush(StackTnfo *s, STDataType x){
    assert(s);
    //判断栈满
    if(s -> top == s -> capacity){
        //扩容
        int newcapacity = s -> capacity == 0 ? 4 : s -> capacity * 2;
        STDataType *tmp = (STDataType*) realloc(s -> data, sizeof(s -> data) * newcapacity);
        if(tmp == NULL){
            perror("realloc :: fail");
            exit(-1);
        }
    }
    s -> data[s -> top] = x;
    s -> top++;
}
void StackPop(StackTnfo *s){
    assert(s);
    assert(s -> top > 0);
    s -> top--;
}

/*查看栈顶元素*/
STDataType StackTop(StackTnfo *s){
    assert(s);
    assert(s -> top > 0);
    return s -> data[s -> top - 1];
}

/*查看栈内有效元素个数*/
int StackSize(StackTnfo *s){
    assert(s);
    return s -> top;
}

/*判断栈为空*/
bool StackEmpty(StackTnfo *s){
    assert(s);
    return s -> top == 0;
}
