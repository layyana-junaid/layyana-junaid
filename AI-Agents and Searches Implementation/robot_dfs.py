#implementing dfs to solve this 

def dfs(grid):
    N = len(grid)
    M = len(grid[0])
    
    directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]
    start = None
    goal = None
    for i in range(N):
        for j in range(M):
            if grid[i][j] == 'P':
                start = (i, j)
            elif grid[i][j] == 'T':
                goal = (i, j)
            
    stack = [(start, [start])]
    visited = set()
    visited.add(start)
    
    while stack:
        (x, y) , path = stack.pop()
        
        if (x, y) == goal:
            return path
        
        for dx, dy in directions:
            nx = x + dx
            ny = y + dy
            
            if 0 <= nx < N and 0 <= ny < M and (nx, ny) not in visited and grid[nx][ny] != 'X':
                stack.append(((nx, ny), path + [(nx, ny)]))
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


dfs_path = dfs(grid)

print("Depth First Search: ", dfs_path)