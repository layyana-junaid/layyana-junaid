#implemeting depth first search to find the path 

def dfs(grid):
    N = len(grid)
    M = len(grid[0])
    
    start = (0,0)
    goal = (N-1, M-1)
    
    directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]
    
    stack = [(start, [start])] 
    visited = set()
    
    while stack:
        (x, y), path = stack.pop()
        
        if (x, y) == goal:
            return path 
        
        if (x, y) in visited:
            continue
        visited.add((x, y))
        
        for dx, dy in directions:
            nx = x + dx
            ny = y + dy
            
            if 0 <= nx < N and 0 <= ny < M and (nx, ny) not in visited:
                stack.append(((nx, ny), path + [(nx, ny)]))
    
    return None

grid = [
    [1, 1, 1],
    [1, 1, 1],
    [1, 1, 1]
]

dfs_path = dfs(grid)

print("Depth First Path: ", dfs_path)