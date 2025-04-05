#ifndef __DEQUEUEARR_H__
#define __DEQUEUEARR_H__
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    Node* head;
    Node *tail;
    int length;
} Queue;

typedef int Data;
typedef struct Node {
    Data data;
    struct Node* next;
} Node;

Node *new_node(Data);
void delete_node(Node*);
void print_node(Node*);
Queue* queue_create();
void queue_enqueue_head(Queue* , Data);
void queue_enqueue(Queue* , Data);
int queue_dequeue_head(Queue*);
int queue_dequeue_tail(Queue*);
bool queue_is_empty(Queue*);
Data queue_front(Queue*);
void queue_empty(Queue*);
void queue_delete(Queue*);


#endif 