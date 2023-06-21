//  stack_class.hpp
//  Stack_queue
//  Created by Qian on 6/21/23.

#ifndef stack_queue_hpp
#define stack_queue_hpp
#include <iostream>
using namespace::std;

/*stack struct: data, top, base, capacity*/
typedef int STDataType;
typedef struct StackTnfo{
    STDataType *data;
    int top;
    int base;
    int capacity;
}Stack;

void StackDestroy(StackTnfo *s);
void StackPush(StackTnfo *s, STDataType x);
void StackPop(StackTnfo *s);
STDataType StackTop(StackTnfo *s);
int StackSize(StackTnfo *s);
bool StackEmpty(StackTnfo *s);

#endif /* stack_queue_hpp */
