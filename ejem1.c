#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Error al reservar memoria\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = head;
    return newNode; // nuevo nodo es la cabeza
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    // Insertar nodos
    head = insertAtBeginning(head, 5);
    head = insertAtBeginning(head, 10);
    head = insertAtBeginning(head, 15);

    printList(head);

    // Liberar memoria
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
