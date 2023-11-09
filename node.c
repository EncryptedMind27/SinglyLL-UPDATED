#include "node.h"

LINKED_LIST createList(){
    LINKED_LIST list = (LINKED_LIST)malloc(sizeof(struct Linked_List));
    list->head = NULL;
    list->size = 0; 
    return list;
}

NODE createNode(_element data){
    NODE newNode = (NODE)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;  
    return newNode;
}

void addFirst(LINKED_LIST list, _element data){
    NODE newNode = createNode(data);
    if(list->head == NULL){
        list->head = newNode;
    } else {
        newNode->next = list->head;
        list->head = newNode;
    }
    list->size++;
}

void addLast(LINKED_LIST list, _element data){
    NODE newNode = createNode(data);
    if(list->head == NULL){
        list->head = newNode;
    } else {
        NODE current = list->head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = newNode;
    }
    list->size++;
}

void insert(LINKED_LIST list, _element data, int pos){
    pos -= 1;
    if(pos < 0 || pos > list->size){
        printf("Invalid Position!\n");
        return;
    }

    if(pos == 0){
        addFirst(list,data);
    } else if(pos<list->size){
        NODE newNode = createNode(data);
        NODE current = list->head;
        while(--pos){
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
        list->size++;
    } else if(pos==list->size){
        addLast(list,data);
    }
 }

void display(LINKED_LIST list){
    NODE current = list->head;
    printf("Contents: ");
    while(current !=  NULL){
        printf("%d ",current->data);
        current = current->next;
    }
    printf("\nSize: %d\n",list->size);
}

//////////////////////////////////////////////////////

void deleteFirst(LINKED_LIST list) {
    if (list->head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    NODE temp = list->head;
    list->head = list->head->next;
    free(temp);
    list->size--;
}

void deleteLast(LINKED_LIST list) {
    if (list->head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    if (list->size == 1) {
        free(list->head);
        list->head = NULL;
        list->size = 0;
        return;
    }

    NODE current = list->head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    free(current->next);
    current->next = NULL;
    list->size--;
}

void deletePosition(LINKED_LIST list, int pos) {
    pos -= 1;
    if (pos < 0 || pos >= list->size) {
        printf("Invalid Position! Cannot delete.\n");
        return;
    }

    if (pos == 0) {
        deleteFirst(list);
    } else if (pos == list->size - 1) {
        deleteLast(list);
    } else {
        NODE current = list->head;
        for (int i = 1; i < pos; i++) {
            current = current->next;
        }

        NODE temp = current->next;
        current->next = temp->next;
        free(temp);
        list->size--;
    }
}
