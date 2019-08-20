/**

ESTE PROGRAMA INICIA UNA LISTA SIMPLEMENTE ENLAZADA Y AGREGA LOS ELEMENTOS EN LA CABEZA DE LA LISTA

**/


#include <stdio.h>
#include <stdlib.h>


typedef struct Node{

   float value;
   struct Node *next;

}Node;

Node *newNodeToFooter(float value, Node *next);

void printList(Node *head);



void main(){

    

    int yes=1;
    float value =0.0;
    Node *head = NULL;
   
    while(yes == 1){

      printf("\n\nAgregue un numero a la lista: ");
      scanf("%f",&value);

      if(head==NULL){
         head = newNodeToFooter(value,NULL);        
      }else{

         head = newNodeToFooter(value,head);
      }
      //system("clear");
      printf("\n\nDesea agregar otro numero?: si = 1, no = 0\n");
      printf(": ");
      scanf("%d",&yes);
      //system("clear");

    }

    printList(head);

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







