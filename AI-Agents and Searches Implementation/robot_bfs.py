#implementing search with respect to agents 

from collections import deque

'''grid = [
    ['P', 'O', 'X', 'O', 'O', 'O'],
    ['O', 'X', 'O', 'X', 'O', 'O'],
    ['O', 'O', 'O', 'X', 'O', 'O'],
    ['X', 'X', 'O', 'X', 'O', 'T'],
    ['O', 'O', 'O', 'O', 'X', 'O'],
    ['O', 'X', 'X', 'O', 'O', 'O']
]'''
def bfs(grid):
    
    N = len(grid)
    M = len(grid[0])
    
    directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]
    start = None
    goal = None
    
    #finding the starting and goal positions
    for i in range(N):
        for j in range(M):
            if grid[i][j] == 'P':
                start = (i, j)
            elif grid[i][j] == 'T':
                goal = (i, j)
        
    queue = deque([(start, [start])])
    visited = set()
    visited.add(start)
    
    while queue:
        (x, y), path = queue.popleft() #getting the next node to explore 
        
        if (x, y) == goal: 
            return path
        
        for dx, dy in directions:
            nx = x + dx
            ny = y + dy
            
            if 0 <= nx < N and 0 <= ny < M and (nx, ny) not in visited and grid[nx][ny] != 'X':
                queue.append(((nx, ny), path + [(nx, ny)]))
                visited.add((nx, ny))
    
    return None


grid = [
    ['P', 'O', 'X', 'O', 'O', 'O'],
    ['O', 'X', 'O', 'X', 'O', 'O'],
    ['O', 'O', 'O', 'X', 'O', 'O'],
    ['X', 'X', 'O', 'X', 'O', 'T'],
    ['O', 'O', 'O', 'O', 'X', 'O'],
    ['O', 'X', 'X', 'O', 'O', 'O']
]

bfs_path = bfs(grid)

print("The shortest path using breadth first search: ", bfs_path)