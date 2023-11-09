#include "node.h"

int main(){
    LINKED_LIST list = createList();
    addFirst(list,1);
    addFirst(list,2);
    addFirst(list,3);
    display(list);
    addLast(list,4);
    addLast(list,5);
    display(list);
    insert(list,0,1);
    display(list);
    deleteFirst(list);
    display(list);

    return 0;
}
