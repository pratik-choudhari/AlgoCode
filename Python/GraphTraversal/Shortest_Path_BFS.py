#Approach: Start from src,perform level order traversal and keep incrementing the count till dest node is not found

def find_count(src,des,adjacency_list):
    cnt_nodes=0
    queue = [src]                       # insert first node in queue
    while len(queue)>0:
        cnt_nodes += 1
        sz = len(queue)
        for i in range(sz):             #iterate over each level
            node = queue[0]
            queue.pop(0)
            for j in adjacency_list[node]:
                if j==des:                      #check if dest node found
                    return cnt_nodes-1
                else:
                    queue.append(j)
                    
    return -1
    
nodes = 8
edges = 10
edges_list = [[0,1],[0,3],[1,2],[3,4],[3,7],[4,5],[4,6],[4,7],[5,6],[6,7]]
src = 0
des = 7
adjacency_list = {}                         # create adjacency list
for i in range(edges):
    v1 = edges_list[i][0]
    v2 = edges_list[i][1]
    if v1 not in adjacency_list:
        adjacency_list[v1]=[v2]
    else:
        adjacency_list[v1].append(v2)
        
print(find_count(src,des,adjacency_list))

        
    
