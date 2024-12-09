from collections import deque

def knight_moves(start, end):
   
    def chess_to_coords(pos):
        return ord(pos[0]) - ord('a') + 1, int(pos[1])
    
    start_x, start_y = chess_to_coords(start)
    end_x, end_y = chess_to_coords(end)

    moves = [(2, 1), (2, -1), (-2, 1), (-2, -1), (1, 2), (1, -2), (-1, 2), (-1, -2)]



    queue = deque([(start_x, start_y, 0)]) 

    visited = set((start_x, start_y))
    







    while queue:
        x, y, dist = queue.popleft()
        
        if (x, y) == (end_x, end_y):
            return dist
        
        for dx, dy in moves:
            nx, ny = x + dx, y + dy
            if 1 <= nx <= 8 and 1 <= ny <= 8 and (nx, ny) not in visited:
                visited.add((nx, ny))
                queue.append((nx, ny, dist + 1))
    
    return 




T = int(input())
for _ in range(T):
    start, end = input().split()
    print(knight_moves(start, end))
