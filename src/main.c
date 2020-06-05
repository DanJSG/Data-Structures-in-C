#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <ctype.h>
#include <time.h>
#include "./arraylist/ArrayList.h"
#include "./singlylinkedlist/SinglyLinkedList.h"
#include "./doublylinkedlist/DoublyLinkedList.h"
#include "./queue/Queue.h"
#include "./queue/QNode.h"
#include "./common/BitMath.h"
#include "./common/Hashes.h"

int main() {
    // for(int i=0; i < 10; i++) {
    //     if(is_even(i)) printf("%d is even.\n", i);
    //     else printf("%d is odd.\n", i);
    // }

    // printf("%d\n", hash("test"));
    // printf("%d\n", hash("Dan"));
    // printf("%d\n", hash("Name"));
    // printf("%d\n", hash("Key"));
    // printf("%d\n", hash("Message"));
    // printf("%d\n", hash("Person"));
    // printf("%d\n", hash("Man"));
    // printf("%d\n", hash("Content"));
    // printf("%d\n", hash("msg"));
    // printf("%d\n", hash("ZZZZCCCCXXXXXXjasdiohjasdohj"));

    printf("%lu\n", hashcode("test"));
    printf("%lu\n", fnv1a_32("test"));
    printf("%lu\n", fnv1a_64("test"));

    // char* alph = "abcdefghijklmnopqrstuvwxyz";
    // int output = 0;

    // clock_t start;
    // clock_t end;

    // double hashcode_time;
    // double fnv1a_time;

    // start = clock();
    // for(int i=0; i < strlen(alph); i++) {
    //     for(int j=0; j < strlen(alph); j++) {
    //         for(int k=0; k < strlen(alph); k++) {
    //             char str[4] = "";
    //             strncat(str, (alph + i), 1);
    //             strncat(str, (alph + j), 1);
    //             strncat(str, (alph + k), 1);
    //             printf("%lu\n", hashcode(str) % 512);
    //         }
    //     }
    // }
    // end = clock();
    // hashcode_time = ((double)(end - start));

    // start = clock();
    // for(int i=0; i < strlen(alph); i++) {
    //     for(int j=0; j < strlen(alph); j++) {
    //         for(int k=0; k < strlen(alph); k++) {
    //             char str[4] = "";
    //             strncat(str, (alph + i), 1);
    //             strncat(str, (alph + j), 1);
    //             strncat(str, (alph + k), 1);
    //             printf("%lu\n", fnv1a_32(str) % 512);
    //         }
    //     }
    // }
    // end = clock();
    // fnv1a_time = ((double)(end - start));

    // printf("Hash code took: %lf.\n", hashcode_time);
    // printf("FNV1a took: %lf.\n", fnv1a_time);

    // for(int i=0; i < strlen(alph); i++) {
    //     printf("%d\n", hash((alph + i)));
    // }

    // printf("%d\n", hashcode("test") % 256);
    // printf("%d\n", hashcode("stet") % 256);
    // printf("%d\n", hashcode("etst") % 256);

    // printf("%d\n", fnv_1a("test") % 256);
    // printf("%d\n", fnv_1a("stet") % 256);
    // printf("%d\n", fnv_1a("etst") % 256);

    // printf("%d\n", fnv_1a("Test"));
    // printf("%d\n", fnv_1a("hello"));
    // printf("%d\n", fnv_1a("HELLO"));
    // printf("%d\n", fnv_1a("LEHOL"));
    // printf("%d\n", fnv_1a("leHoL"));
    // printf("%d\n", fnv_1a("Name"));
    // printf("%d\n", fnv_1a("Messaging"));

    // unsigned int arr[256];
    // for(int i=0; i < 256; i++) {
    //     arr[i] = i;
    // }
    // for(int i=0; i < 128; i++) {
    //     int idx_a = rand() % 256;
    //     int idx_b = rand() % 256;
    //     if(idx_a == idx_b) continue;
    //     swap_vals(&arr[idx_a], &arr[idx_b]);
    // }
    
    // printf("{%d", arr[0]);
    // for(int i=1; i < 256; i++) {
    //     printf(", %d", arr[i]);
    // }
    // printf("}\n");
    // clock_t start = clock();
    // for(int i=0; i<100000000;i++) {
    //     int a = i + 1;
    //     int b = (i + 1) * 5;
    //     int temp = a;
    //     a = b;
    //     b = temp;
    // }
    // clock_t end = clock();
    // double total = ((double) (end - start)) / CLOCKS_PER_SEC;
    // printf("Total time for temp method was %lf s\n", total);

    
    // start = clock();
    // for(int i=0; i<100000000;i++) {
    //     int c = i + 1;
    //     int d = (i + 1) * 5;
    //     d ^= d;
    //     d ^= c;
    //     c ^= d;
    // }
    // end = clock();
    // total = ((double) (end - start)) / CLOCKS_PER_SEC;
    // printf("Total time for xor method was %lf s\n", total / (double)1000);

    // int x = 100;
    // int y = 25;
    // printf("X is %d and y is %d\n", x, y);
    // swap_vals(&x, &y);
    // printf("X is %d and y is %d\n", x, y);
    
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
