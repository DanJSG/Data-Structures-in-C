#ifndef ARRAYLIST_H_INCLUDED
#define ARRAYLIST_H_INCLUDED

/** Enumeration containing constants for the initial capacity of the array list
    and the rate at which it shrinks and grows. */
typedef enum ArrayListConstants{
    INIT_CAPACITY = 16,
    RESIZE_FACTOR = 2
} ArrayListConstants;

/** Structure for an array list of integers. */
typedef struct ArrayList {
	int* array;
	int capacity;
	int size;
} ArrayList;

/** Constructor for an array list of integers. */
ArrayList* arr_constructor();

/** Get the item at the given index from the list.*/
int arr_get(ArrayList* list, int index);

/** Push a new item onto the end of the array list.*/
int arr_push(ArrayList* list, int value);

/** Return the size of the array list. */
int arr_size(ArrayList* list);

/** Return the capacity of the array list.*/
int arr_capacity(ArrayList* list);

/** Return true if the array is empty, false if not. */
int arr_is_empty(ArrayList* list);

/** Insert an item into the array list at a given index.*/
int arr_insert_at(ArrayList* list, int index, int value);

/** Read the last item in the array list and remove it from the list. */
int arr_pop(ArrayList* list);

/** Remove all occurrences of an item from the array list. */
int arr_remove_value(ArrayList* list, int value);

/** Delete the item at a given index. */
int arr_delete_at(ArrayList* list, int index);

/** Returns the index of a particular item in the array list. Returns -1 if it does not exist. */
int arr_find_value(ArrayList* list, int value);

/** Method for printing the array list in the console. */
void arr_print(ArrayList* list);

/** Method for deleting all items in the array and freeing the memory associated with them whilst keeping
    the structure in tact.*/
void arr_clear(ArrayList* list);

/** Destructor for an array list. Frees memory associated with the elements and structure. */
void arr_destructor(ArrayList* list);

#endif // ARRAYLIST_H_INCLUDED
