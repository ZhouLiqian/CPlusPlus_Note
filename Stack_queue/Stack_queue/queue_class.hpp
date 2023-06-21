//  queue_class.hpp
//  Stack_queue
//  Created by Qian on 6/21/23.

#ifndef queue_class_hpp
#define queue_class_hpp
#include <iostream>
using namespace::std;

typedef int QListDataType;
//单个节点
typedef struct QListNode{
    QListDataType data;
    QListNode *next;
    QListNode(QListDataType x) : data(x), next(NULL){}
}QNode;
//整个队列
typedef struct QueueNode{
    QNode *front;
    QNode *rear;
    size_t size;
}Queue;

void QueueInit(Queue *pq);
void QueueDestroy(Queue *pq);
bool QueueEmpty(Queue *pq);
void QueuePush(Queue *pq, QListDataType x);
void QueuePop(Queue* pq);
QListDataType QueueFront(Queue* pq);
QListDataType QueueRear(Queue* pq);
int QueueSize(Queue* pq);

#endif /* queue_class_hpp */
