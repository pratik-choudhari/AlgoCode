import heapq

class Dijkstra:
    def __init__(self,graph):
        self.graph = graph

    #print the shortest path
    def printPath(self,parent, j):
        if parent[j] == -1 :
            print(j,end=" ")
            return
        self.printPath(parent , parent[j])
        print(j,end=" ")

    #print the distances of each vertex from the source vertex
    def printDistances(self,distances,parent,source_vertex):
        print("-"*50)
        print("Source Vertex: %s"%(source_vertex))
        print("-"*50)
        print("Vertex\tShortest Distance\tShortest Path")
        print("-"*50)
        for vertex in distances:
            print("%s\t%d\t\t"%(vertex,distances[vertex]),end="\t")
            self.printPath(parent,vertex)
            print()

    #find shortest distance of each vertex from the source vertex
    def dijkstra(self,source_vertex):
        distances = {vertex: float("infinity") for vertex in self.graph}

        distances[source_vertex] = 0

        parent = {vertex:-1 for vertex in self.graph}

        priority_queue = [(0, source_vertex)]
        while len(priority_queue) > 0:
            current_distance, current_vertex = heapq.heappop(priority_queue)

            #Process a vertex when it is removed from the priority queue for the first time.
            if current_distance > distances[current_vertex]:
                continue

            for neighbor, weight in self.graph[current_vertex].items():
                distance = current_distance + weight

                # Consider the path if a better one is found
                if distance < distances[neighbor]:
                    distances[neighbor] = distance
                    heapq.heappush(priority_queue, (distance, neighbor))
                    parent[neighbor] = current_vertex

        self.printDistances(distances,parent,source_vertex)

#testing completed
test_graph = {
    "A": {"B": 3, "D": 4, "E": 2},
    "B": {"A": 3, "C": 4},
    "C": {"B": 4, "F": 2},
    "D": {"A": 4, "H": 8},
    "E": {"A": 2, "F": 6, "H": 1},
    "F": {"C": 2, "E": 6, "I": 1},
    "G": {"I": 8},
    "H": {"D": 8, "E": 1},
    "I": {"F": 1, "G": 8}
}

d = Dijkstra(test_graph)
d.dijkstra("A")
"""
--------------------------------------------------
Vertex  Shortest Distance       Shortest Path
--------------------------------------------------
A       0                       A
B       3                       A B
C       7                       A B C
D       4                       A D
E       2                       A E
F       8                       A E F
G       17                      A E F I G
H       3                       A E H
I       9                       A E F I
"""
d.dijkstra("B")
"""
--------------------------------------------------
Vertex  Shortest Distance       Shortest Path
--------------------------------------------------
A       3                       B A
B       0                       B
C       4                       B C
D       7                       B A D
E       5                       B A E
F       6                       B C F
G       15                      B C F I G
H       6                       B A E H
I       7                       B C F I
"""
d.dijkstra("C")
"""
--------------------------------------------------
Vertex  Shortest Distance       Shortest Path
--------------------------------------------------
A       7                       C B A
B       4                       C B
C       0                       C
D       11                      C B A D
E       8                       C F E
F       2                       C F
G       11                      C F I G
H       9                       C F E H
I       3                       C F I
"""
d.dijkstra("D")
"""
--------------------------------------------------
Vertex  Shortest Distance       Shortest Path
--------------------------------------------------
A       4                       D A
B       7                       D A B
C       11                      D A B C
D       0                       D
E       6                       D A E
F       12                      D A E F
G       21                      D A E F I G
H       7                       D A E H
I       13                      D A E F I
"""
d.dijkstra("E")
"""
--------------------------------------------------
Vertex  Shortest Distance       Shortest Path
--------------------------------------------------
A       2                       E A
B       5                       E A B
C       8                       E F C
D       6                       E A D
E       0                       E
F       6                       E F
G       15                      E F I G
H       1                       E H
I       7                       E F I
"""
d.dijkstra("F")
"""
--------------------------------------------------
Vertex  Shortest Distance       Shortest Path
--------------------------------------------------
A       8                       F E A
B       6                       F C B
C       2                       F C
D       12                      F E A D
E       6                       F E
F       0                       F
G       9                       F I G
H       7                       F E H
I       1                       F I
"""
d.dijkstra("G")
"""
--------------------------------------------------
Vertex  Shortest Distance       Shortest Path
--------------------------------------------------
A       17                      G I F E A
B       15                      G I F C B
C       11                      G I F C
D       21                      G I F E A D
E       15                      G I F E
F       9                       G I F
G       0                       G
H       16                      G I F E H
I       8                       G I
"""
d.dijkstra("H")
"""
--------------------------------------------------
Vertex  Shortest Distance       Shortest Path
--------------------------------------------------
A       3                       H E A
B       6                       H E A B
C       9                       H E F C
D       7                       H E A D
E       1                       H E
F       7                       H E F
G       16                      H E F I G
H       0                       H
I       8                       H E F I
--------------------------------------------------
"""
d.dijkstra("I")
"""
--------------------------------------------------
Vertex  Shortest Distance       Shortest Path
--------------------------------------------------
A       9                       I F E A
B       7                       I F C B
C       3                       I F C
D       13                      I F E A D
E       7                       I F E
F       1                       I F
G       8                       I G
H       8                       I F E H
I       0                       I
"""
