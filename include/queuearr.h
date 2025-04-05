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
void queue_enqueue(Queue* , Data);
int queue_dequeue(Queue*);
bool queue_is_empty(Queue*);
Data queue_front(Queue*);
void queue_empty(Queue*);
void queue_delete(Queue*);

Node *new_node(Data d) {
    Node *node = (Node *)malloc(sizeof(Node));
    if (node == NULL) {
        return NULL;
    }
    node->data = d;
    node->next = NULL;
    return node;
}
void delete_node(Node *n) {
    if (n != NULL && n->next == NULL) {
        free(n);
    }
}
void print_node(Node *n) {
    if (n != NULL) {
        printf("Nodo: %d\n", n->data);
    } else {
        printf("Nodo inválido\n");
    }
}

Queue* queue_create() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    if (q == NULL) {
        return NULL;
    }
    q->head = q->tail = NULL;
    return q;
}

void queue_enqueue(Queue* q, Data d) {
    if (q == NULL) return;
    Node *node = new_node(d);
    if (node == NULL) return;
    if (q.length = 0) {
        q->head = q->tail = node;
        q.length++;
    } else {
        q->tail->next = node;
        q->tail = node;
        q->tail->next= q->head;
        q.length++;
    }
}

Data queue_dequeue(Queue* q) {
    if (q == NULL || q->head == NULL) return -1; 
    Node *temp = q->head;
    Data value = temp->data;
    if (q.length == 0) {
    q->head = q->tail = NULL;
         
    }
    else{
        q->head = q->head->next;
        q->tail= q->head;
    }
    delete_node(temp);  
    return value;
}

bool queue_is_empty(Queue* q) {
    return q == NULL || q->head == NULL;
}

Data queue_front(Queue* q) {
    if (q == NULL || q->head == NULL) return -1;
    return q->head->data;
}

void queue_empty(Queue* q) {
    while (!queue_is_empty(q)) {
        queue_dequeue(q);
    }
}

void queue_delete(Queue* q) {
    if (q == NULL) return;
    queue_empty(q);
    free(q);
}




#endif 