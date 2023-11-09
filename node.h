#ifndef NODE_LIST
#define NODE_LIST

#include <stdio.h>
#include <stdlib.h>

typedef int _element;

typedef struct Node{
	_element data;
	struct Node* next;
}*NODE;

typedef struct Linked_List{
	NODE head;
	_element size;
}*LINKED_LIST; 

LINKED_LIST createList();
NODE createNode(_element data);
void addFirst(LINKED_LIST list,_element data);
void addLast(LINKED_LIST list, _element data); 
void insert(LINKED_LIST list, _element data, int pos);
void deleteFirst(LINKED_LIST list);
void display(LINKED_LIST list);


#endif
