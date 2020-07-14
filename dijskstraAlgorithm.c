#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <stdbool.h>


void create_graph();
void display();
void delete_node(char u);
void dijkstra(int s, int e);
void insert_node();
int min(int num1, int num2);
void inicializa();
void rellena();
bool isVisitated(int j);
char getChar(int n);

#define max 20
#define infinite 50000

int adj[max][max];
int n=5;
int visitated[4];

void main() {
    int choice;
    int node, origin, destin;
    //create_graph();
    inicializa();
    rellena();
    while (1) {
        printf("1.Insert a node\n");
        printf("2.Delete a node\n");
        printf("3.Dispaly\n");
        printf("4.Dijkstra\n");
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
            dijkstra(3,2);
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
    char c1='a',c2='a';
    for (j = 0; j < n; j++){
        printf("%4c", c2);
        c2++;
    }
    printf("\n");
    for (i = 0; i < n; i++) {
        printf("%4c", c1);
        for (j = 0; j < n; j++){
            printf("%4d", adj[i][j]);
        }
        c1++;
        printf("\n");
    }
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
void dijkstra(int s,int e){

     int N=n,v=0,contS=0,menor,i,j,contvs=0;
     int S[N],D[N], v_s[N-1], v_sSize=N-1;
     int start=s,end=e;

      S[0] = start;

       for(j=0;j<N;j++){
             if(j!=S[0]){
                v_s[contvs]=j;

                contvs++;
             }
       }

      for(i=0;i<N;i++){
          D[i]=adj[start][i];
      }
      printf("\n\n\n");

     menor = D[1];
     int visitado=0;
     int recorrido=1;
     v=1;

     for(i=1;i<N;i++){

         for (j=1; j<=N-1; j++){
             if (D[j]!= infinite && D[j]< menor && !isVisitated(j)){
                menor=D[j];

                v=j;
             }
         }

         visitated[visitado]=v;
         visitado++;


         contS= contS+1;
         S[contS]= v;

         for(int r = 0; r<v_sSize;r++){
              if(v_s[r] == v){
                 for(int rr=r;rr<v_sSize-1;rr++){
                   v_s[rr] = v_s[rr+1];
                 }
                 v_sSize--;
                 break;
              }
         }

         for(int k=0;k<v_sSize;k++){
            int w = v_s[k];
            D[w] = min(D[w],D[v]+adj[v][w]);
         }

         for(int kk=1;kk<N;kk++){
            if(!isVisitated(kk)){
               menor = D[kk];
               v = kk;
               break;
            }
         }

     }


     printf("D \n");
     for(int i=0;i<N;i++){
        printf("%d ",D[i]);
     }

     printf("\n\nS \n");
          for(int i=0;i<N;i++){
             printf("%c ",getChar(S[i]));
          }

     printf("\n\n\n");
}

int min(int num1, int num2)
{
    return (num1 > num2 ) ? num2 : num1;
}

void inicializa(){

    adj[0][0]=-1;
    adj[0][1]=4;
    adj[0][2]=11;
    adj[1][1]=-1;
    adj[1][3]=6;
    adj[1][4]=2;
    adj[2][1]=3;
    adj[2][2]=-1;
    adj[2][3]=6;
    adj[3][3]=-1;
    adj[4][2]=5;
    adj[4][3]=3;
    adj[4][4]=-1;

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

bool isVisitated(int j){

    for(int i=0;i<n-1;i++){
        if(j==visitated[i]){
           return true;
        }
    }
    return false;
}


char getChar(int n){

     switch(n){

         case 0: return 'a';
         case 1: return 'b';
         case 2: return 'c';
         case 3: return 'd';
         case 4: return 'e';
     }

     return '0';

}
