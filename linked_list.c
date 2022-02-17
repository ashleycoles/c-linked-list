#include <stdio.h>
#include <stdlib.h>

typedef struct Item {
    char *item;
    struct Item *next;
} Item;

void print_linked_list(Item *head) {
    Item *current = head;

    while (current != NULL) {
        printf("%s\n", current->item);
        current = current->next;
    }
}

void push_end(Item *head, char *item) {
    Item *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = malloc(sizeof(Item));
    current->next->item = item;
    current->next->next = NULL;
}

void push_start(Item ** head, char *item) {
    Item *new_item;
    new_item = malloc(sizeof(Item));

    new_item->item = item;
    new_item->next = *head;
    *head = new_item;
}


char* remove_last(Item *head) {
    char *return_value;
    if (head->next == NULL) {
        return_value = head->item;
        free(head);
        return return_value;
    }

    Item *current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    return_value = current->next->item;
    free(current->next);
    current->next = NULL;
    return return_value;
}


char* pop(Item ** head) {
    Item *next_item = NULL;

    next_item = (*head)->next;
    char *return_value = (*head)->item;
    free(*head);
    *head = next_item;

    return return_value;
}

char* remove_by_value(Item ** head, char *item) {
    Item *previous, *current;

    // Start by checking the first item
    if ((*head)->item == item) {
        // If it is the first item, just hand it over to pop()
        return pop(head);
    }

    // Keep track of the previous and current items
    previous = *head;
    current = (*head)->next;

    while (current) {
        if (current->item == item) {
            previous->next = current->next;
            free(current);
            return item;
        }
        previous = current;
        current = current->next;
    }
    return "";
}


int main(void) {
    Item *head = NULL;
    head = malloc(sizeof(Item));

    if (head == NULL) {
        return 1;
    }

    head->item = "Blind - Korn";
    head->next = malloc(sizeof(Item));
    head->next->item = "Duality - Slipknot";
    head->next->next = NULL;
    push_end(head, "Wish You Were Here - Pink Floyd");
    push_end(head, "Welcome Home - Metallica");
    remove_last(head);

    print_linked_list(head);
}