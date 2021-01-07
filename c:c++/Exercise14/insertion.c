/**
 @file insertion.c
 @author Revanth Bobba (rsbobba)
 Inserts Numbers in order with a linked list.
 */

// Code to read numbers from standard input inserting them into a list
// in sorted order as we read them.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node for building our linked list.
struct NodeStruct {
  // Value in this node.
  int value;

  // Pointer to the next node.
  struct NodeStruct *next;
};

// A short type name to use for a node.
typedef struct NodeStruct Node;

/*
  Create a node for the given value and insert it into the given list
  in the proper location to keep the list sorted.  Return an updated
  head pointer.  The head should only need to change if this value gets
  inserted at the front of the list.  Otherwise, you can just return
  the old head pointer.
*/
Node *insert( Node *head, int val )
{
  // ...

//    for (pp = head; pp != NULL; pp = pp->next) {
//        printf("%d ", pp->value);
//    }
//
//    printf("\n");
    
//    printf("hi insert\n");
    if (head == NULL) {
        Node *temp = (Node *) malloc(sizeof(Node));
        //Node temp = {val, NULL};
        temp->value = val;
        temp->next = NULL;
        head = temp;
    }
    else {
        //printf("yo1\n");
        Node * traveler = (Node *) malloc(sizeof(Node));
        traveler = head;
        //printf("yo2\n");
        while (traveler->next != NULL && val > traveler->next->value) {
            traveler = traveler->next;
        }
        
        if (val < head->value) {
            Node *temp = (Node *) malloc(sizeof(Node));
            temp->value = val;
            temp->next = head;
            head = temp;
        }
        else if (traveler->next == NULL) {
            //printf("traveler next is null\n");
            Node *temp = (Node *) malloc(sizeof(Node));
            //Node temp = {val, NULL};
            temp->value = val;
            temp->next = NULL;
            traveler->next = temp;
        }
        else {
            //Node temp = {val, traveler->next};
            Node *temp = (Node *) malloc(sizeof(Node));
            temp->value = val;
            temp->next = traveler->next;
            traveler->next = temp;
        }
    }

//    Node * pp;
//    for (pp = head; pp != NULL; pp = pp->next) {
//        printf("%d ", pp->value);
//    }
//
//    printf("\n");
    
    return head;
}

/**
 Program Starting Point
 Driver class fro program.
 @return Program exit success.
 */
int main()
{
  // Pointer to the head node.
  Node *head = NULL;

  // Read a list of numbers from building a sorted list as we
  // read them.
  int x;
  while ( scanf( "%d", &x ) == 1 ){
      //printf("hi main\n");
    // Insert the new value, and get back the (possibly updated) head pointer.
    head = insert( head, x );
  }

    //printf("hi after insert\n");
  // Print out the list.
  // ...
    Node * pp;
    for (pp = head; pp != NULL; pp = pp->next) {
        printf("%d ", pp->value);
    }
  
    printf("\n");
     //printf("hi free\n");
  // Free all the nodes.
  // ...
    for (pp = head; pp != NULL; pp = pp->next) {
        free(pp);
    }
  
  return 0;
}
