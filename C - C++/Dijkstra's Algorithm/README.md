## Dijkstra's Algorithm for Single Source Shortest Path to All Vertices:  
Conditions:  
- The edges weights are non negative.  

## Algorithm:  
1. Set the source vertex distance to zero and all remaining verticex distances to INF.
2. Construct a priority queue and push the source vertex.
3. Now, while the queue is not empty, we select the vertex which has least distance from the source vertex in the queue and pop it.
4. Then we look at the neighbours of the popped vertex and update the distances if the distance till popped vertex + edge weight is less than the current distance.
5. We then push the updated vertices in the priority queue.

Note: There may be multiple instances of a vertex in the priority queue, and that is why we use this `-d != dist[a]` *smart* line of code to see if the vertex has already been visited. Once a vertex is popped, it means that it has the shortest distance from the source vertex to it.  

> Sample input:  
> 5 7  
> 1 2 1  
> 2 3 2  
> 1 3 7  
> 2 4 5  
> 3 4 1  
> 3 5 3  
> 4 5 1  
> 1  
> Output:  
> Distance of vertex 1 from source 1 : 0  
> Distance of vertex 2 from source 1 : 1  
> Distance of vertex 3 from source 1 : 3  
> Distance of vertex 4 from source 1 : 4  
> Distance of vertex 5 from source 1 : 5  
 


Proof and detailed explanation of the algorithm:-  
[CP- Algorithms website](https://cp-algorithms.com/graph/dijkstra_sparse.html)  
Motivation of the algorithm:-  
[NPTEL-Madhavan Mukund](https://www.youtube.com/watch?v=OGsPQy-lM1w&feature=emb_logo)