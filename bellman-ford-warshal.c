/*
 * C program to Implement Bellmanford Algorithm
 */
 
#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
 
// Step 1 we are here initializing the node in the map.
// It has source node data and the destination node along with the weight of the edge.
struct Edge
{
    int source;
    int destination;
    struct Edge *next;
};
 
// Step 2: This is the pointer that points to the list that contains the edges list. 
 
struct Edge *HEAD=NULL;
void Insert_Edge(int, int);
 
int main()
{
    int vertices;
    // Here we are initializing the total number of nodes in the graph
    vertices = 5;
    int graph[vertices][vertices];
 
    // Here we initialised the weight to be infinite at first 
    for(int i=0;i<vertices;i++)
    {
        for(int j=0;j<vertices;j++)
        {
            graph[i][j]=INT_MAX;
        }
    }
 
    // Add edges in the node 
    graph[0][1]=200;
    graph[0][2]=-20;
    graph[0][3]=100;
    graph[1][4]=70;
    graph[2][3]=50;
    graph[3][4]=10;
    graph[4][2]=40;
 
    // This will print the graph in adjacency matrix form. 
    // We are using an adjacency matrix for representing the graph.
    printf("GRAPH AFTER FILLING THE NODE IS :::\n");
    for(int i=0;i<vertices;i++)
    {
        for(int j=0;j<vertices;j++)
        {
            if(graph[i][j] == INT_MAX)
            {
                printf("%-10c", '-');
            }
            else
            {
                printf("%-10d", graph[i][j]);
            }
        }
        printf("\n");
    }
 
    printf("**********************************************************************\n");
    // Inserting edges in the linked list.
    for(int i=0;i<vertices;i++)
    {
        for(int j=0;j<vertices;j++)
        {
            if(graph[i][j] != INT_MAX)
            {
                Insert_Edge(i,j);
            }
        }
    }
    int source;
    printf("Enter the source node::  ");
 
    //source is the node from where the cost is to be found for all other nodes.
    scanf("%d",&source); // Choose the source as 0 for our first test case.
    int shortest_path[vertices];
    for(int i=0;i<vertices;i++)
    {
        shortest_path[i]=INT_MAX;
    }
    shortest_path[source]=0; //As Source cost to itself is 0
 
    // This Loop Runs |VERTICES-1| Times
    for(int i=1;i<vertices;i++)
    {
        struct Edge *temp=HEAD; 
        while(temp!=NULL)
        {
            //here we check if the node is reachable from the source vertex or not.
            if(shortest_path[temp->source] != INT_MAX)
            {
                if(shortest_path[temp->source] + graph[temp->source][temp->destination]
                < shortest_path[temp->destination])
                {
                    shortest_path[temp->destination]=shortest_path[temp->source]
                    + graph[temp->source][temp->destination];
                }
            }
            temp= temp->next;
        }
    }
    printf("MINUMUM COSTS FOUND AFTER APPLYING THE BELLMAN FORD ALGORITHM FOR SOURCE NODE [%c] COMES OUT TO BE::: \n",source+97);
    printf("*****************************************************************\n");
    for(int i=0;i<vertices;i++)
    {
        if(shortest_path[i]==INT_MAX)
        {
            printf("Node [%c] to [%c] is unreachable \n",source+97,i+97);
            continue;
        }
        else
        {
            printf("Node [%c] TO [%c] MINIMUM COST IS:: %d\n",source+97,i+97,shortest_path[i]);
        }
    }
    return 0;
}
void Insert_Edge(int src, int des)
{
    struct Edge *ptr = (struct Edge*)malloc(sizeof(struct Edge));
    struct Edge *temp=HEAD;
    ptr->source=src;
    ptr->destination=des;
    if(HEAD==NULL)
    {
        HEAD=ptr;
        HEAD->next=NULL;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=(struct Edge*)temp->next;
        }
        temp->next=ptr;
        ptr->next=NULL;
    }
    return ;
}
OUTPUT:
GRAPH AFTER FILLING THE NODE IS :::
-         200       -20       100       -         
-         -         -         -         70        
-         -         -         50        -         
-         -         -         -         10        
-         -         40        -         -         
****************************************************************************************************
Enter the source node::  4
MINUMUM COSTS FOUND AFTER APPLYING THE BELLMAN FORD ALGORITHM FOR SOURCE NODE [e] COMES OUT TO BE::: 
****************************************************************************************************
Node [e] to [a] is unreachable 
Node [e] to [b] is unreachable 
Node [e] TO [c] MINIMUM COST IS:: 40
Node [e] TO [d] MINIMUM COST IS:: 90
Node [e] TO [e] MINIMUM COST IS:: 0

EXPLAIN:
Structure Definition (struct Edge):

The program defines a structure struct Edge to represent an edge in the graph. It contains three fields:
source (source vertex), destination (destination vertex), and next (a pointer to the next edge in the linked list).
Global Linked List (HEAD):

The program uses a global variable HEAD to maintain a linked list of edges. 
Each element in this linked list represents an edge in the graph.
Initializing the Graph:

The program initializes a 2D array graph to represent the adjacency matrix of the graph. 
Initially, all edge weights are set to INT_MAX to indicate that there is no direct edge between nodes.
Adding Edges to the Graph:

The program manually adds edges with corresponding weights to the graph 2D array. It specifies which nodes are connected and the weight of each edge.
Printing the Graph:

After filling the graph with edge weights, the program prints the graph in adjacency matrix form. 
It uses '-' to represent INT_MAX (infinity) for unconnected nodes.
Inserting Edges into the Linked List:

The program inserts each edge (non-infinity weight) from the graph into the global linked list. 
The Insert_Edge function is responsible for adding edges to the linked list.
Bellman-Ford Algorithm:

The user is prompted to enter the source node from which the minimum cost to other nodes will be computed.

The program initializes an array shortest_path to store the minimum cost from the source node to each other node.
Initially, all costs are set to INT_MAX except for the source node itself, which is set to 0.

The Bellman-Ford algorithm is applied, which runs for vertices - 1 iterations, where vertices is the number 
of nodes in the graph.

In each iteration, the program iterates over all edges in the linked list and relaxes the edges.
If it finds a shorter path to a node, it updates the shortest_path array accordingly.
After running the Bellman-Ford algorithm, the program checks for negative weight cycles to ensure the graph is free from such cycles. If it detects a negative weight cycle, it prints a warning message.

Output:

Finally, the program prints the minimum costs from the source node to all other nodes.
It also handles cases where certain nodes are unreachable from the source node.
Edge Insertion (Insert_Edge Function):

The Insert_Edge function is used to insert edges into the linked list. 
It allocates memory for a new edge, sets its source and destination, and appends it to the linked list.
The program provides a basic implementation of the Bellman-Ford algorithm to find the shortest path in a directed
weighted graph and is designed to work with a specific graph structure and input format.
