#implementing breadth first search 

from collections import deque

def bfs(grid):
    '''Finding the path using bfs''' 
    N = len(grid) #rows
    M = len(grid[0]) #columns
    
    #defining goal and starting states
    start = (0,0)
    goal = (N-1, M-1)
    
    #defining possible directions
    directions = [(-1, 0), (1, 0), (0, 1), (0, -1)]
    
    #(current position, path taken)
    queue = deque([(start, [start])])
    visited = set() #to keeo track of the visited cells
    
    while queue:
        (x, y) , path = queue.popleft() #getting the next position to explore
        
        #if the path is found return it
        if(x, y) == goal:
            return path 
        
        if(x, y) in visited:
            continue #if any node is visited then we skip it
        visited.add((x, y))
        
        for dx, dy in directions:
            #for determining the next node add the values of 
            #x and y to the first , ie for down add -1 in y and 0 in x
            nx, ny = x + dx, y + dy
            
            #check if whether it is with in bounds
            if 0 <= nx < N and 0 <= ny < M:
                queue.append(((nx, ny), path +[(nx, ny)]))
    return None


#defining a grid    
grid = [
    [1, 1, 1],
    [1, 1, 1],
    [1, 1, 1]
]

bfs_path = bfs(grid)
print("BFS Path: ", bfs_path)