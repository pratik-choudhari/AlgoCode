#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
//Function to input the graph as adjacency matrix
int ** read_graph(int n,int e)
{
    int ** graph;
    graph=malloc(n*sizeof(int*));
    int i,j;
    for(i=0;i<n;i++)
    {
        graph[i]=calloc(n,sizeof(int));
    }
    printf("\nEnter vertex pairs with edge in between : Eg. (0 1) -> Edge between V0 and V1\n");
    for(i=0;i<e;i++)
    {
        int v1,v2;
        printf("Edge%d :",i+1);
        scanf("%d %d",&v1,&v2);
        graph[v1][v2]=1;
        graph[v2][v1]=1;
    }
    return graph;
}
//Function to print the graph as adjacency matrix
void print_graph(int ** graph,int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d",graph[i][j]);
        }
        printf("\n");
    }
}
//Function to get vertices in decreasing order of degree
int * Sort(int **  graph, int n) 
{ 
    int i, j;
    int*  arr=calloc(n,sizeof(int));
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
            if(graph[i][j]==1)
                {arr[i]++;arr[j]++;}
    }
    int * desc=malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
    {
        int max=INT_MIN;
        int idx;
        for(j=0;j<n;j++)
            if(arr[j]>max)
            {
                max=arr[j];
                idx=j;
            }
        desc[i]=idx;
        arr[idx]=INT_MIN;
    }
    return desc;
} 
int main()
{
    int i,j;
    int n;
    printf("Number of vertices: ");
    scanf("%d",&n);
    int e;
    printf("Number of edges: ");
    scanf("%d",&e);
    int ** graph=read_graph(n,e);
    //print_graph(graph,n);
    int * desc=Sort(graph,n);
    //for(i=0;i<n;i++)
        //printf("%d ",desc[i]);
    int col=1;//first color is 1
    int * colored=calloc(n,sizeof(int));//0 means uncolored,else the value is color value
    int flag;//uncolored vertices exist
    while(1)
    {
        flag=1;
        //see if any uncolored edges exist &
        //find first uncolored vertex
        int uncolored_vertex;
        int uv;
        for(i=0;i<n;i++)
        {
            if(colored[desc[i]]==0)
            {
                flag=0;
                uncolored_vertex=desc[i];
                uv=i;
                break;
            }
        }
        //no uncolored vertex
        if(flag==1)
            break;
        //uncolored vertex exists
        else
        {
            //color with current color
            colored[uncolored_vertex]=col;
            //store all vertices with current color
            int * temp=malloc(sizeof(n)*n-1);
            int t=0;
            temp[t++]=uncolored_vertex;
            for(i=uv;i<n;i++)
            {
                if(colored[desc[i]]==0)
                {
                    int f=1;//not adjacent
                    //checking if its adjacent to any current color vertex
                    for(j=0;j<t;j++)
                    {
                        if(graph[i][temp[j]]==1)
                            f=0;
                    }
                    if(f)
                    {
                        colored[i]=col;
                        temp[t++]=i;
                    }
                }
            }
        }
        col++;

    }
    printf("The vertices are colored in the following pattern:\n");
    for(i=0;i<n;i++)
        printf("Vertex %d Color %d \n",i,colored[i]);
    printf("Chormatic number is : %d",col-1);
}

