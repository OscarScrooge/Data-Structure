/**

ESTE PROGRAMA INICIA UNA LISTA SIMPLEMENTE ENLAZADA Y AGREGA LEMENTOS AL INICIO, AL FINAL Y ENMEDIO

**/


#include <stdio.h>
#include <stdlib.h>


typedef struct Node{

   float value;
   struct Node *next;

}Node;

Node *newNodeToHeader(float value, Node *next);
Node *newNodeToCenter(float value, Node *next);
Node *newNodeToFooter(float value, Node *next);

void printList(Node *head);



void main(){

    int yes=1;
    float value =0.0;
    Node *head = NULL;
   
    printf("ANIADE AL PRINCIPIO DE LA LISTA\n");

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

    printf("ANIADE AL FINAL DE LA LISTA\n");
    yes =1;
    while(yes == 1){

      printf("\n\nAgregue un numero a la lista: ");
      scanf("%f",&value);

      head = newNodeToFooter(value,head);
      system("clear");
      printf("\n\nDesea agregar otro numero?: si = 1, no = 0\n");
      printf(": ");
      scanf("%d",&yes);
      system("clear");

    }

    printf("ANIADE ENMEDIO DE LA LISTA\n");

    yes =1;
    while(yes == 1){

      printf("\n\nAgregue un numero a la lista: ");
      scanf("%f",&value);

      head = newNodeToCenter(value,head);
      system("clear");
      printf("\n\nDesea agregar otro numero?: si = 1, no = 0\n");
      printf(": ");
      scanf("%d",&yes);
      system("clear");

    }



    printList(head);

}

Node *newNodeToCenter(float value,Node *previous){
   
    Node *newNode;
    newNode = (Node*) malloc(sizeof(Node));
    newNode -> value = value;
    newNode -> next = previous -> next;
    previous -> next = newNode;

    return previous;
}

Node *newNodeToHeader(float value,Node *prev){
   
    Node *newNode;
    newNode = (Node*) malloc(sizeof(Node));
    newNode -> value = value;
    newNode -> next = prev;

    return newNode;
}


Node *newNodeToFooter(float value,Node *head){
   
    Node *lastNode,*aux;
    lastNode = (Node*) malloc(sizeof(Node));
    lastNode -> value = value;
    lastNode -> next = NULL;  
    
    if(head == NULL){
      return lastNode;
    }else{
      aux = head;
      while(aux -> next !=NULL){
        aux = aux ->next;
        
      }
      aux ->next = lastNode;
      return head;
    }
    return NULL;
}

void printList(Node *head){

     printf("\n\n");
     while(head != NULL){
           printf("%4f\n", head -> value);
           head = head -> next;

     }

}







