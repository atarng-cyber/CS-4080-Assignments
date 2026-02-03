#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char* data;
    struct Node* prev;
    struct Node* next;
} Node;

// Insert at the beginning
Node* insert(Node* head, const char* text) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = strdup(text); // Allocate string on heap
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL) {
        head->prev = newNode;
    }
    return newNode;
}

// Find a node by string value
Node* find(Node* head, const char* text) {
    Node* current = head;
    while (current != NULL) {
        if (strcmp(current->data, text) == 0) return current;
        current = current->next;
    }
    return NULL;
}

// Delete a specific node and free memory
Node* deleteNode(Node* head, Node* target) {
    if (head == NULL || target == NULL) return head;

    if (head == target) head = target->next;
    if (target->next != NULL) target->next->prev = target->prev;
    if (target->prev != NULL) target->prev->next = target->next;

    free(target->data);
    free(target);
    return head;
}

int main() {
    Node* list = NULL;

    // Test Insert
    list = insert(list, "World");
    list = insert(list, "Hello");

    // Test Find
    Node* search = find(list, "Hello");
    if (search) printf("Found: %s\n", search->data);

    // Test Delete
    list = deleteNode(list, search);
    
    printf("Remaining head: %s\n", list->data);

    return 0;
}