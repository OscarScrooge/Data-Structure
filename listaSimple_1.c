/**

ESTE PROGRAMA INICIA UNA LISTA SIMPLEMENTE ENLAZADA Y AGREGA LOS ELEMENTOS EN LA CABEZA DE LA LISTA

**/


#include <stdio.h>
#include <stdlib.h>


typedef struct Node{

   float value;
   struct Node *next;

}Node;

Node *newNodeToHeader(float value, Node *next);

void printList(Node *head);



void main(){

    int yes=1;
    float value =0.0;
    Node *head = NULL;
   
    while(yes == 1){

      printf("\n\nAgregue un numero a la lista: ");
      scanf("%f",&value);

      if(head==NULL){
         head = newNodeToHeader(value,NULL);      	
      }else{
         head = newNodeToHeader(value,head);
      }
      system("clear");
      printf("\n\nDesea agregar otro numero?: si = 1, no = 0\n");
      printf(": ");
      scanf("%d",&yes);
      system("clear");

    }

    printList(head);

}

<<<<<<< HEAD
Node *newNodeToHeader(float value,Node *prev){
   
    Node *newNode;
    newNode = (Node*) malloc(sizeof(Node));
    newNode -> value = value;
    newNode -> next = prev;
=======
Node *newNode(float value,Node *previous){
   
    Node *ptr;
    ptr = (Node*) malloc(sizeof(Node));
    ptr -> value = value;
    ptr -> next = previous;
>>>>>>> proffesor

    return newNode;
}

void printList(Node *head){

     printf("\n\n");
     while(head != NULL){
           printf("%4f\n", head -> value);
           head = head -> next;

     }

}







