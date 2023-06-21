//  queue_class.cpp
//  Stack_queue
//  Created by Qian on 6/21/23.

#include "queue_class.hpp"

/*初始化*/
void QueueInit(Queue *pq){
    assert(pq);
    pq -> front = pq -> rear = 0;
    pq -> size = 0;
}

/*队列销毁原理和单链表差不多，需要借助一个临时指针指向当前队头，然后队头指针移向下一个位置
 销毁临时指针, 直到临时指针指向NULL，此时整个队列都会被销毁*/
void QueueDestroy(Queue *pq){
    assert(pq);
    QNode *cur = pq -> front;
    while (cur) {
        QNode *tmp = cur -> next;
        free(cur);
        cur = tmp;
    }
    pq -> front = pq -> rear = NULL;
    pq -> size = 0;
}

/*判断队是否为空*/
bool QueueEmpty(Queue *pq){
    assert(pq);
    return pq -> front == NULL;
}

/*入队、出队*/
void QueuePush(Queue *pq, QListDataType x){
    assert(pq);
    QNode *new_node = new QListNode(x);
    if(pq -> front == NULL){
        pq -> front = pq -> rear = new_node;
        pq -> size++;
    }
    else
    {
        pq -> rear -> next = new_node;
        pq -> rear = new_node;
        pq -> size++;
    }
}
void QueuePop(Queue* pq)
{
    assert(pq);
    QNode* cur = pq->front;
    pq->front = pq->front->next;
    free(cur);
    cur = NULL;
    pq->size--;
}

/*查看队头、队尾元素*/
QListDataType QueueFront(Queue* pq)
{
    assert(pq);
    assert(!QueueEmpty(pq));
    return pq->front->data;
}
QListDataType QueueRear(Queue* pq)
{
    assert(pq);
    assert(!QueueEmpty(pq));
    return pq->rear->data;
}

/*查看队内有效元素个数*/
int QueueSize(Queue* pq)
{
    assert(pq);
    return int(pq->size);
}
