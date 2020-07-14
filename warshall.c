#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <stdbool.h>


void create_graph();
void display();
void delete_node(char u);
void warshall();
void insert_node();
int min(int num1, int num2);
void inicializa();
void rellena();

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
        printf("4.Warshall\n");
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
            warshall();
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
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%4d", adj[i][j]);
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

void warshall(){

    int N = n,k=0,i=0,j=0;

    for(k=0;k<N;k++){
         for(i=1;i<N;i++){
              for(j=1;j<N;j++){
                    if(adj[i][k] + adj[k][j] < adj[i][j]){
                       //adj[i][j] = adj[i][k] + adj[k][j]
                       adj[i][j] = adj[i][k] + adj[k][j];
                    }
              }
         }
    }

    printf("LISTO");

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
