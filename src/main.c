#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include "./arraylist/ArrayList.h"
#include "./singlylinkedlist/SinglyLinkedList.h"
#include "./doublylinkedlist/DoublyLinkedList.h"
#include "./queue/Queue.h"
#include "./queue/QNode.h"
#include "./common/BitMath.h"

int main() {
    // for(int i=0; i < 10; i++) {
    //     if(is_even(i)) printf("%d is even.\n", i);
    //     else printf("%d is odd.\n", i);
    // }

    clock_t start = clock();
    for(int i=0; i<100000000;i++) {
        int a = i + 1;
        int b = (i + 1) * 5;
        int temp = a;
        a = b;
        b = temp;
    }
    clock_t end = clock();
    double total = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Total time for temp method was %lf s\n", total);

    
    start = clock();
    for(int i=0; i<100000000;i++) {
        int c = i + 1;
        int d = (i + 1) * 5;
        d ^= d;
        d ^= c;
        c ^= d;
    }
    end = clock();
    total = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Total time for xor method was %lf s\n", total / (double)1000);

    int x = 100;
    int y = 25;
    printf("X is %d and y is %d\n", x, y);
    swap_vals(&x, &y);
    printf("X is %d and y is %d\n", x, y);
    
    // unsigned char* str = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    // for(int i=0; i < strlen(str); i++) {
    //     unsigned int int_val = (int)*(str + i);
    //     unsigned int one_shift = (int)*(str + i) >> 1;
    //     unsigned int two_shift = (int)*(str + i) << 2;

    //     unsigned int or = int_val | one_shift;
    //     unsigned int and = int_val & two_shift;
    //     unsigned int xor = or ^ and;

    //     printf("Char: %c; Hash: %d\n", *(str + i), xor);
    // }
    // printf("%s", *str << 1);
    // printf("%d %d %d %d %d %d %d %d\n", i, i << 1, i << 2, i << 3, i << 4, i << 5, i << 6, i << 7);

    // srand(time(NULL));
    // char* alpha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    // Queue* q = q_construct();
    // for(int i=0; i < 32; i++) {
    //     char new_str[8] = "";
    //     for(int i=0; i < 8; i++) {
    //         int al_char = rand() % 52;
    //         strncat(new_str, alpha + al_char, 1);
    //     }
    //     q_enqueue(q, new_str);
    // }
    // q_print(q);
    // for(int i=0; i < 17; i++) {
    //     q_dequeue(q);
    // }
    // q_print(q);
    // for(int i=0; i < 27; i++) {
    //     char new_str[8] = "";
    //     for(int i=0; i < 8; i++) {
    //         int al_char = rand() % 52;
    //         strncat(new_str, alpha + al_char, 1);
    //     }
    //     q_enqueue(q, new_str);
    // }
    // q_print(q);
    // for(int i=0; i< 80; i++) {
    //     char new_str[8] = "";
    //     for(int i=0; i < 8; i++) {
    //         int al_char = rand() % 52;
    //         strncat(new_str, alpha + al_char, 1);
    //     }
    //     q_enqueue(q, new_str);
    // }
    // q_print(q);
    exit(0);
}
