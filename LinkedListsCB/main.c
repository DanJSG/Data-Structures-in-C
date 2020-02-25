#include <stdio.h>
#include <stdlib.h>
#include "SinglyLinkedList.h"

int main()
{
    SinglyLinkedList* list = list_constructor();
    for(int i=0; i<9; i++) {
        list_push_front(list, (i + 1) * 3);
    }

    list_print(list);
    list_remove_value(list, 100);
    list_print(list);

    return 0;
}
