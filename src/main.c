#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "./arraylist/ArrayList.h"
#include "./singlylinkedlist/SinglyLinkedList.h"
#include "./doublylinkedlist/DoublyLinkedList.h"
#include "./queue/Queue.h"
#include "./queue/QNode.h"


int main() {
    srand(time(NULL));
    char* alpha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    Queue* q = q_construct();
    for(int i=0; i < 32; i++) {
        char new_str[8] = "";
        for(int i=0; i < 8; i++) {
            int al_char = rand() % 52;
            strncat(new_str, alpha + al_char, 1);
        }
        q_enqueue(q, new_str, strlen(new_str));
    }
    q_print(q);
    for(int i=0; i < 17; i++) {
        q_dequeue(q);
    }
    q_print(q);
    for(int i=0; i < 27; i++) {
        char new_str[8] = "";
        for(int i=0; i < 8; i++) {
            int al_char = rand() % 52;
            strncat(new_str, alpha + al_char, 1);
        }
        q_enqueue(q, new_str, strlen(new_str));
    }
    q_print(q);
    for(int i=0; i< 80; i++) {
        char new_str[8] = "";
        for(int i=0; i < 8; i++) {
            int al_char = rand() % 52;
            strncat(new_str, alpha + al_char, 1);
        }
        q_enqueue(q, new_str, strlen(new_str));
    }
    q_print(q);
    exit(0);
}
