/**

ESTE PROGRAMA INICIA UNA LISTA SIMPLEMENTE ENLAZADA Y AGREGA LOS ELEMENTOS EN LA CABEZA DE LA LISTA

**/


#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
   
   int id;
   float value;
   struct Node *next;

}Node;

Node *newNodeToHeader(float value, Node *next);
Node* findNode(Node *head, int goal);

void printList(Node *head);



void main(){

    int yes=1, goal;
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
    
    printf("id a buscar: ");    
    scanf("%d",&goal);

    Node *finded = findNode(head,goal);
    printf("\n finded id = %i", finded -> id);
    printf("finded val = %f", finded -> value);



}

Node *newNodeToHeader(float value,Node *prev){
   
    Node *newNode;
    newNode = (Node*) malloc(sizeof(Node));
    newNode -> id = rand()%(100-1+1)+100;
    newNode -> value = value;
    newNode -> next = prev;

    return newNode;
}

void printList(Node *head){

     printf("\n\n");
     while(head != NULL){
           printf("%4i  ", head -> id);
           printf("%4f\n", head -> value);
           head = head -> next;

     }

}


Node* findNode(Node *head, int goal){

     Node *index;
     for(index = head; index !=NULL; index = index->next){

           if(goal == index->id){
            return index;
           }

     }
     return NULL;

}







