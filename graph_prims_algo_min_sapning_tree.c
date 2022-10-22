//Kruskal Min spaning tree
#include<stdio.h>
#include<stdlib.h>
int parent[10];

int fipar(int);
int unionn(int, int);


void Kruskals(int n, int cost[10][10])
{
    int visited[10], ne=1, u, v, minCost = 0, min, a, b;  // taking path from node 1

    

    printf("\n\n\nThe Edges consist for MST from Kruskal algo  are : \n");
   

    while (ne<n)
    {
        for (int i = 1, min =999; i <= n; i++) 
        {
            for (int j = 1; j <= n; j++)
            {
                if (cost[i][j]<min)
                {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;

                    u = fipar(u);
            
                    v = fipar(v);

                    if (unionn(u,v))//if orignal parent different
                    {
                        printf("\n%d Edge ( %d , %d ) = %d \n", ne++, a, b, min);
                        minCost = minCost + min;
                    }
                    cost[a][b] = cost[b][a] = 999;//making it infinite
                    
                }
            }
        } 
    }
    printf("Minnimum cost = %d",minCost);
}
int fipar(int i)
{
    while (parent[i])
    {
        i = parent[i];
        return i;
    }
    
}

int unionn (int i,int j)
{

    if (i != j)
    {
        parent[j] = i;
        return 1;
    }
    return 0;
}


int main()
{
    int n; //number of nodes
    int cost[10][10];

    printf("Number of Nodes : ");
    scanf("%d", &n);

    printf("Enter Cost of %d %d Matrix : \n",n,n);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
            {
                cost[i][j] == 999;
            }
 
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (cost[i][j] != 0)
            {
                parent[j] = i;
            }   
        }
    }


    // prims(n, cost);
    Kruskals(n, cost);

    return 0;

}
//minimum heap