#pragma once
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
typedef int size_t;
// ----------------------------
// Macro para declarar estructuras y prototipos
// ----------------------------
#define DECLARE_CQUEUE(TYPE) \
    typedef struct Node_##TYPE { \
        TYPE data; \
        struct Node_##TYPE* next; \
    } Node_##TYPE; \
    \
    typedef struct { \
        Node_##TYPE* head; \
        Node_##TYPE* tail; \
        size_t length; \
    } List_##TYPE; \
    \
    List_##TYPE* list_##TYPE##_create(void); \
    Node_##TYPE* node_##TYPE##_createNode(TYPE data); \
    void list_##TYPE##_destroy(List_##TYPE* list); \
    bool list_##TYPE##_push(List_##TYPE* list, TYPE data); \
    TYPE list_##TYPE##_pop(List_##TYPE* list); \
    size_t list_##TYPE##_length(const List_##TYPE* list); \
    void list_##TYPE##_print(const List_##TYPE* list, void (*print_fn)(TYPE)); \
// ----------------------------
// Macro para implementación
// ----------------------------
#define IMPLEMENT_CIRCULAR_LINKED_LIST(TYPE) \
    List_##TYPE* list_##TYPE##_create(void) { \
        List_##TYPE* list = malloc(sizeof(List_##TYPE)); \
        if (!list) return NULL; \
        list->tail = NULL; \
        list->head = NULL; \
        list->length = 0; \
        return list; \
    } \
    Node_##TYPE* node_##TYPE##_createNode(TYPE data) { \
        node_##TYPE* node = malloc(sizeof(Node_##TYPE)); \
        if (!node) return NULL; \
         = NULL; \
        node->next = NULL; \
        node->data = 0; \
        return node; \
    } \
    \
    void list_##TYPE##_destroy(List_##TYPE* list) { \
        if (!list || !list->tail) return; \
        Node_##TYPE* current = list->head; \
        for (size_t i = 0; i < list->length; i++) { \
            Node_##TYPE* temp = current; \
            temp->next = NULL; \
            current = current->next; \
            free(temp); \
        } \
        free(list); \
    } \
    void list_##TYPE##_push(List_##TYPE* list, TYPE data) { \
        Node_##TYPE* NewNode = Node_##TYPE##_createNode(data);\
        \
        if (list == NULL) {\
        return false; \
        }\
        else{\
            if(list->length == 0){\
                list->head = list->tail = NewNode->next = NewNode; \
                list->length++; \
                return true;\
            }\
            else{\
                list->tail->next= NewNode; \
                list->tail = NewNode;\
                list->tail->next= list->head;\
                list->length++;\
                return true;\
            }\
        }\
    } \
    \
    TYPE list_##TYPE##_pop(List_##TYPE* list) { \
        TYPE dato;\
        if (list == NULL) {\
            return -1; \
            }\
            else{\
                if(list->length == 0){\
                    printf("No hay datos");\
                    return -1;\
                }\
                else{\
                    num = list->head->data;\
                    Node_##TYPE* delete;\
                    delete = list->head;\
                    list->head= list->head->next;\
                    list->tail->next = list->head;\
                    delete->next= NULL;\
                    free(delete);\
                    list->length--;\
                    \
                    return dato;\
                }\
            }\
    } \
    \
    size_t list_##TYPE##_length(const List_##TYPE* list) { \
        return list ? list->length : 0; \
    } \
    \
    void list_##TYPE##_print(const List_##TYPE* list, void (*print_fn)(TYPE)) { \
        if (!list || !print_fn || list->length == 0) return; \
        Node_##TYPE* current = list->head; \
        for (size_t i = 0; i < list->length; i++) { \
            print_fn(current->data); \
            if (i < list->length - 1) printf(", "); \
            current = current->next; \
        } \
        printf("\n"); \
    }

// ----------------------------
// Declaración para tipos concretos
// ----------------------------
DECLARE_CIRCULAR_LINKED_LIST(int)
DECLARE_CIRCULAR_LINKED_LIST(char)
DECLARE_CIRCULAR_LINKED_LIST(float)

// ----------------------------
// Implementación para tipos concretos
// ----------------------------
#ifdef LINKED_LIST_IMPLEMENTATION
IMPLEMENT_CIRCULAR_LINKED_LIST(int)
IMPLEMENT_CIRCULAR_LINKED_LIST(char)
IMPLEMENT_CIRCULAR_LINKED_LIST(float)
#endif
