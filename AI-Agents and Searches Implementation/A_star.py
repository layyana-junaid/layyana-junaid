import heapq

def a_star(grid):
    """Finds the shortest path from (0,0) to (N-1,M-1) using A*."""
    N, M = len(grid), len(grid[0])  # Grid dimensions
    start, goal = (0, 0), (N-1, M-1)

    # Possible moves: Down, Up, Right, Left
    directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]
    
    # Priority queue (min-heap)
    open_list = []
    heapq.heappush(open_list, (0, 0, start))  # (f(n), g(n), position)
    
    came_from = {}  # Tracks path
    g_score = {start: 0}  # Cost from start to node
    f_score = {start: heuristic(start, goal)}  # Estimated total cost

    while open_list:
        _, g, current = heapq.heappop(open_list)  # Pop lowest-cost node
        x, y = current

        if current == goal:
            return reconstruct_path(came_from, current)  # Return shortest path
        
        for dx, dy in directions:
            nx, ny = x + dx, y + dy

            if 0 <= nx < N and 0 <= ny < M:
                tentative_g_score = g + grid[nx][ny]  # Cost of moving to neighbor

                if (nx, ny) not in g_score or tentative_g_score < g_score[(nx, ny)]:
                    came_from[(nx, ny)] = current
                    g_score[(nx, ny)] = tentative_g_score
                    f_score[(nx, ny)] = tentative_g_score + heuristic((nx, ny), goal)
                    heapq.heappush(open_list, (f_score[(nx, ny)], tentative_g_score, (nx, ny)))

    return None  # No path found

def heuristic(node, goal):
    """Manhattan Distance heuristic."""
    x, y = node
    gx, gy = goal
    return abs(gx - x) + abs(gy - y)

def reconstruct_path(came_from, current):
    """Reconstructs the shortest path from goal to start."""
    path = [current]
    while current in came_from:
        current = came_from[current]
        path.append(current)
    return path[::-1]  # Reverse to get start-to-goal order

# Define a 3x3 grid (without obstacles, all costs = 1)
grid = [
    [1, 1, 1],
    [1, 1, 1],
    [1, 1, 1]
]

# Run A* Search
a_star_path = a_star(grid)
print("A* Search Path:", a_star_path)
