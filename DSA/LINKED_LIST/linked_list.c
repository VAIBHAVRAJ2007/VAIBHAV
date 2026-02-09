#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

struct node *head = NULL; // global declaration

void display() {
  struct node *d;
  if (head == NULL) {
    printf("\nBlocks do not exist.\n");
  } else {
    d = head;
    printf("\nNumbers are: ");
    while (d != NULL) {
      printf("%d ", d->data);
      d = d->next;
    }
  }
  printf("\n");
}

struct node *createNode() {
  struct node *h1;
  h1 = (struct node *)malloc(sizeof(struct node));
  printf("\nEnter a number:");
  scanf("%d", &h1->data);
  h1->next = NULL;
  return h1;
}

void insertStart() {
  struct node *k1;
  k1 = createNode();
  if (head == NULL)
    head = k1;
  else {
    k1->next = head;
    head = k1;
  }
  printf("\nNumber inserted successfully.\n");
}

void insertEnd() {
  struct node *k1, *b1;
  k1 = createNode();
  if (head == NULL) {
    head = k1;
  } else {
    b1 = head;
    while (b1->next != NULL) {
      b1 = b1->next;
    }
    b1->next = k1;
  }
  printf("\nNumber inserted successfully.\n");
}

void insertMiddle() {
  struct node *k1, *j, *f;
  k1 = createNode();
  if (head == NULL) {
    head = k1;
  } else {
    int d;
    printf("Enter the number where you want to insert before: ");
    scanf("%d", &d);

    if (head->data == d) {
      k1->next = head;
      head = k1;
    } else {
      f = head;
      while (f->next != NULL && f->next->data != d) {
        f = f->next;
      }
      if (f->next == NULL) {
        printf("\nTarget %d not found. Insertion cancelled.\n", d);
        free(k1);
        return;
      }
      j = f->next;
      f->next = k1;
      k1->next = j;
    }
  }
  printf("\nNumber inserted successfully.\n");
}

void deleteStart() {
  struct node *x1;
  if (head == NULL) {
    printf("There is no any number to delete.\n");
  } else {
    x1 = head;
    head = head->next;
    x1->next = NULL;
    free(x1);
    printf("\nNumber deleted successfully.\n");
  }
}

void deleteEnd() {
  struct node *x1, *p1;

  if (head == NULL) {
    printf("There is no any number to delete.\n");
  } else if (head->next == NULL) {
    free(head);
    head = NULL;
    printf("Number deleted successfully\n");
  } else {
    x1 = head;
    while (x1->next->next != NULL) {
      x1 = x1->next;
    }
    p1 = x1->next;
    x1->next = NULL;
    free(p1);
    printf("Number deleted successfully\n");
  }
}

void deleteMiddle() {
  struct node *x1, *temp;
  int d;

  if (head == NULL) {
    printf("There is no any number to delete.\n");
    return;
  }

  printf("\nEnter a number you want to delete: ");
  scanf("%d", &d);

  if (head->data == d) {
    temp = head;
    head = head->next;
    free(temp);
    printf("Number deleted successfully\n");
  } else {
    x1 = head;
    while (x1->next != NULL && x1->next->data != d) {
      x1 = x1->next;
    }

    if (x1->next == NULL) {
      printf("Number not found in the list.\n");
    } else {
      temp = x1->next;
      x1->next = temp->next;
      free(temp);
      printf("Number deleted successfully\n");
    }
  }
}

int main() {
  while (1) {
    int ch;
    printf("\n   ------ MENU ------");
    printf("\n1. Insert from start");
    printf("\n2. Insert from end");
    printf("\n3. Insert from middle");
    printf("\n4. Delete from start");
    printf("\n5. Delete from end");
    printf("\n6. Delete from middle");
    printf("\n7. Display");
    printf("\n8. Exit");
    printf("\n\n Enter your choice: ");
    scanf("%d", &ch);

    switch (ch) {
    case (1): {
      insertStart();
      break;
    }
    case (2): {
      insertEnd();
      break;
    }
    case (3): {
      insertMiddle();
      break;
    }
    case (4): {
      deleteStart();
      break;
    }
    case (5): {
      deleteEnd();
      break;
    }
    case (6): {
      deleteMiddle();
      break;
    }
    case (7): {
      display();
      break;
    }
    case (8): {
      printf("\n__*___*___*____Good Bye__*___*___*__*__\n");
      exit(0);
    }
    default: {
      printf("\n******Wrong Input.******");
      printf("\n~~~~~~Please enter a valid input.~~~~~~~\n");
    }
    }
  }
  return 0;
}