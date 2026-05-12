#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char name[20];
    int score;
    struct Node* next;
} Node;
Node *head = NULL;

void add(char* name, int score) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->score = score;
    newNode->next = NULL; 
    if (head == NULL) {
        head=newNode;    } 
    else {
         Node *temp = head;
         while (1) {
            if (temp->next == NULL) {
                break; 
            }
        temp=temp->next;
        }
            temp->next=newNode;
    }
}
void delete(char *name) {

    if (head == NULL) {
        return; 
    }

    if (strcmp(head->name, name) == 0) {
        Node *delh = head;    
        head = head->next;      
        free(delh);           
        return;                 
    }

    Node *p = head; 
    while (1) {
           if (p->next == NULL) {
            break; 
        }
        if (strcmp(p->next->name, name) == 0) {
            Node *de = p->next;             
            p->next = de->next; 
            free(de); 
            return; 
        }
        p = p->next;
    }
}
void print() {
    Node* cur =head;
    while (cur != NULL) {
        printf("%s %d\n",cur->name,cur->score);
        cur= cur->next;
    }
}
void quit() {
    Node* cur=head;
    while (cur != NULL) {
        Node* a=cur;
        cur=cur->next;
        free(a);
    }
    head = NULL;
}
int main() {
    char cmd[20];
    char name[20];
    int score;

    while (1) {
        scanf("%s", cmd);

        if (strcmp(cmd, "add") == 0) {
            scanf("%s %d", name, &score);
            add(name, score);
        } else if (strcmp(cmd, "delete") == 0) {
            scanf("%s", name);
            delete(name);
        } else if (strcmp(cmd, "print") == 0) {
            print();
        } else if (strcmp(cmd, "quit") == 0) {
            quit();
            return 0;
        }
    }

    return 0;
}
