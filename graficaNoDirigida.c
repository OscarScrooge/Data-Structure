#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <stdbool.h>


#define max 20
#define infinite 50000

int adj[max][max];
int n=5;
int visitated[4];


typedef struct NODO{
      int v,u;
      struct NODO *sig;
}NODO;


void create_graph();
void display();
void delete_node(char u);
void insert_node();
int min(int num1, int num2);
void inicializa();
void rellena();
int *getV_U(int *v_u,int u[]);
bool isInU(int n,int U[],int sizeU);
bool isInV_U(int v,int *v_u);
void prim();
void pritnL(NODO *L);
void pritnU(int U[],int sizeU);
NODO *getNewNode();

void main() {
    int choice;
    int node, origin, destin;
    //create_graph();
    inicializa();
    //rellena();
    while (1) {
        printf("1.Insert a node\n");
        printf("2.Delete a node\n");
        printf("3.Dispaly\n");
        printf("4.Prim  \n");
        printf("5.Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            insert_node();
            break;
        case 2:
            printf("Enter a node to be deleted : ");
            fflush(stdin);
            scanf("%d", &node);
            delete_node(node);
            break;
        case 3:
            display();
            break;
         case 4:
            prim();
            break;
        case 5:
            exit(0);
        default:
            printf("Wrong choice\n");
            break;
        }
    }
    getch();
}



void create_graph() {
    int i, max_edges, origin, destin,weight=0;

    printf("Enter number of nodes : ");
    scanf("%d", &n);
    max_edges = n * (n - 1);

    for (i = 1; i <= max_edges; i++) {
        printf("Enter edge %d and weight ( 0 0 ) to quit : ", i);
        scanf("%d %d %d", &origin, &destin, &weight);
        if ((origin == -1) && (destin == -1)){
            break;
        /*if (origin > n || destin > n || origin <= 0 || destin <= 0) {
            printf("Invalid edge!\n");
            i--;*/
        } else
            adj[origin][destin] = weight;
    }
}

void display() {
    int i, j;
      printf("\n\n");
    printf("   ");
    for (i = 0; i < n; i++) {
      printf("%4d",i);
    }
    printf("\n\n");
    for (i = 0; i < n; i++) {
        printf("%d  ",i);
        for (j = 0; j < n; j++)
            printf("%4d", adj[i][j]);
        printf("\n");
    }
    printf("\n\n");
}

void insert_node() {
    int i;
    n++;
    printf("The inserted node is %d \n", n);
    for (i = 0; i < n; i++) {
        adj[i][n] = 0;
        adj[n][i] = 0;
    }
}

void delete_node(char u) {
    int i, j;
    if (n == 0) {
        printf("Graph is empty\n");
        return;
    }
    if (u > n) {
        printf("This node is not present in the graph\n");
        return;
    }
    for (i = u; i <= n - 1; i++)
        for (j = 1; j <= n; j++) {
            adj[j][i] = adj[j][i + 1];
            adj[i][j] = adj[i + 1][j];
        }
    n--;
}


int min(int num1, int num2)
{
    return (num1 > num2 ) ? num2 : num1;
}


void prim(){

   int N =n,i,j,u=0,v=0,menor;
   int V[N],U[N];
   int *V_U= malloc(sizeof(int)*(N-1));
   int sizeV=0,sizeU=0;

   U[0]=0;
   NODO *L=NULL;
   V_U = getV_U(V_U,U);

   sizeV = sizeof(V)/sizeof(int);
   sizeU = 1;

   menor = adj[0][0];
   v=0;
   while(sizeU!=sizeV){

       for(i=0;i<N;i++){

             if(isInU(i,U,sizeU)){
                  for(j=0;j<N-1;j++){
                      if(isInV_U(j,V_U)){
                           if(menor==0){
                              menor = adj[i][j];
                              v=j;
                           }else{
                              if(menor>adj[i][j+1] && adj[i][j+1]!=0){
                                menor = adj[i][j+1];
                                v=j+1;
                              }
                           }
                      }
                  }
                  u=i;
                  if(L==NULL){
                     L = getNewNode();
                     L->u=u;
                     L->v=v;
                  }else{
                    NODO *aux =getNewNode();
                    aux->u=u;
                    aux->v=v;
                    NODO *end = L;
                    while(end->sig!=NULL){
                        end = end -> sig;
                    }
                    end->sig=aux;
                  }

                  U[sizeU]=v;
                  sizeU++;
                  menor = 0;
                  v=0;
             }
       }
   }

   printf("\n\n\n");
   pritnL(L);
    printf("\n\n\n");
   pritnU(U,sizeU);

   printf("\n\n\n");
}

bool isInU(int n,int U[],int sizeU){

    for(int i =0;i<=sizeU;i++){
         if(n==U[i]){
            return true;
         }
    }
    return false;
}

bool isInV_U(int v,int *v_u){
    int N=n-1;
    for(int i =0;i<N;i++){
         if(v==v_u[i]){
            return true;
         }
    }
    return false;
}

int *getV_U(int *v_u,int u[]){

    int i=0,j=0,N=n;

    while(i<=N-1){

        if(i!=u[0]){
           v_u[j]=i;
           j++;
        }
        i++;
    }

    return v_u;

}

NODO *getNewNode(){

       NODO *L = malloc(sizeof(NODO));
       L->sig = NULL;

       return L;
}



void inicializa(){


    /*adj[0][1]=1;
    adj[1][0]=1;

    adj[0][2]=1;
    adj[2][0]=1;

    adj[1][3]=1;
    adj[3][1]=1;

    adj[1][4]=1;
    adj[4][1]=1;

    adj[2][1]=1;
    adj[1][2]=1;

    adj[2][3]=1;
    adj[3][2]=1;

    adj[4][2]=1;
    adj[4][3]=1;*/

        adj[0][1]=1;
        adj[1][0]=1;

        adj[1][2]=3;
        adj[2][1]=3;

        adj[0][2]=3;
        adj[2][0]=3;

        adj[2][3]=4;
        adj[3][2]=4;

        adj[2][4]=2;
        adj[4][2]=2;

         adj[3][4]=5;
         adj[4][3]=5;

}


void pritnL(NODO *L){

     NODO *aux = L;

     while(aux!=NULL){
         printf("(%d,%d)  ",aux->u+1,aux->v+1);
         aux=aux->sig;
     }

}

void pritnU(int U[],int sizeU){

   printf("U: ");
   for (int i=0;i<sizeU;i++){
     printf("%d ", U[i]+1);
   }

}

void rellena(){

   for (int i=0; i<n;i++){
      for (int j=0; j<n;j++){
         if(adj[i][j]==-1){
            adj[i][j]=0;
         }else if(adj[i][j]==0){
           adj[i][j]=infinite;
         }
      }
   }

}
