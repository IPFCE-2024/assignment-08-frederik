/*
 * Exercise 2: Insertion Sort for Singly Linked List
 * Assignment 8 - IPFCE 2025
 *
 * Implement insertion sort for a singly linked list of integers.
 * The list should be sorted in-place from smallest to largest.
 * No new nodes should be allocated - only pointers should be changed.
 */

#include "./include/exercise2.h"

/*
 * Sort a singly linked list in-place using insertion sort
 * list: pointer to the first node of the list
 *
 * The function should sort the list by rearranging pointers,
 * not by creating new nodes or swapping data values.
 */
void isort(node* list) {
    if (list == NULL || list->next == NULL)
        return;

    node* sorted = list;          
    node* current = list->next;   
    sorted->next = NULL;          

    while (current != NULL) {
        node* next = current->next;   

        if (current->data < sorted->data) {
            int tmp = current->data;
            current->data = sorted->data;
            sorted->data = tmp;

            current->next = sorted->next;
            sorted->next = current;
        }
        else {
            // find insertion place in sorted part
            node* search = sorted;
            while (search->next != NULL && search->next->data < current->data)
                search = search->next;

            current->next = search->next;
            search->next = current;
        }

        current = next;
    }
}

node* create_node(int data) {
    node* new_node = malloc(sizeof(node));
    if (!new_node) {
        perror("malloc");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void free_list(node* list) {
    node* temp;
    while (list != NULL) {
        temp = list;
        list = list->next;
        free(temp);
    }
}

/* Helper function to print the list */
void print_list(node *list)
{
    node *current = list;
    while (current != NULL)
    {
        printf("%d", current->data);
        if (current->next != NULL)
        {
            printf(" -> ");
        }
        current = current->next;
    }
    printf(" -> NULL\n");
}

