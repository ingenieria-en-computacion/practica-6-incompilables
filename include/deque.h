#pragma once
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
typedef int size_t;
// ----------------------------
// Macro para declarar estructuras y prototipos
// ----------------------------
#define DEQUE(TYPE) \
    typedef struct Node_##TYPE { \
        TYPE data; \
        struct Node_##TYPE* next; \
    } Node_##TYPE; \
    \
    typedef struct { \
        Node_##TYPE* tail; \
        Node_##TYPE* head; \
        size_t length; \
    } List_##TYPE; \
    \
    List_##TYPE* list_##TYPE##_create(void); \
    void list_##TYPE##_destroy(List_##TYPE* list); \
    bool list_##TYPE##_insert(List_##TYPE* list, TYPE data, size_t pos); \
    bool list_##TYPE##_append(List_##TYPE* list, TYPE data); \
    bool list_##TYPE##_remove_at(List_##TYPE* list, size_t pos); \
    bool list_##TYPE##_get(const List_##TYPE* list, size_t pos, TYPE* out); \
    size_t list_##TYPE##_length(const List_##TYPE* list); \
    void list_##TYPE##_print(const List_##TYPE* list, void (*print_fn)(TYPE));

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
    \
    void list_##TYPE##_destroy(List_##TYPE* list) { \
        if (!list || !list->tail || !list->head) return; \
        Node_##TYPE* current = list->tail->next; \
        for (size_t i = 0; i < list->length; i++) { \
            Node_##TYPE* temp = current; \
            current = current->next; \
            free(temp); \
        } \
        free(list); \
    } \
    \
    bool list_##TYPE##_insert(List_##TYPE* list, TYPE data, size_t pos) { \
        if (!list || pos > list->length) return false; \
        Node_##TYPE* new_node = malloc(sizeof(Node_##TYPE)); \
        if (!new_node) return false; \
        new_node->data = data; \
        \
        if (list->length == 0) { \
            new_node->next = new_node; \
            list->tail = new_node; \ //Esto sirve para igual head y tail al mismo en caso de que se inserte en una lista de 0 elementos
            list->head = new_node; \
        } else { \
            if(pos == list->length){\
                list->tail->next= new_node; \
                list->tail= new_node; \
                new_node->next = list->head; \
                temp->next = new_node; \
                list->length++; \
                return true; \
            }\
            else{\
                if (pos == 0) {\
                    new_node->next= list->head;\
                    list->head= new_node;\
                    list->tail->next= new_node;\
                    list->length++; \
                    return true; \
                } \
                else{return false;}\
            }\
        } \
    } \
    \
    bool list_##TYPE##_append(List_##TYPE* list, TYPE data) { \
        return list_##TYPE##_insert(list, data, list->length); \
    } \
    \
    bool list_##TYPE##_remove_at(List_##TYPE* list, size_t pos) { \
        if (!list || pos > list->length) return false; \
        Node_##TYPE* delete; \
        \
        if (list->length == 0) { \
            printf("No hay datos");\
            return false;\
        } else { \
            if(pos == list->length){\
                for(int i= 0, delete= list->head; i<list->length -1; i++, delete= delete->next); \
                delete->next=head;\
                delete= list->tail;\
                delete->next= NULL;\
                free(delete);\
                list->length--;\
                return true;\
            }\
            else{\
                if (pos == 0) {\
                    delete= list->head;\
                    list->head= list->head->next;\
                    delete->next= NULL;\
                    free(delete);\
                    list->length--;\
                    return true;\
                }\
                else{return false;}\
            }\
        } \
    } \
    \
    void list_##TYPE##_print(const List_##TYPE* list, void (*print_fn)(TYPE)) { \
        if (!list || !print_fn || list->length == 0) return; \
        Node_##TYPE* current = list->tail->next; \
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