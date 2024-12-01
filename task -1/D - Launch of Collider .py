def first_collision_time(n, directions, positions):
    min_time = float('inf')
    collision_found = False

    for i in range(n - 1):
        if directions[i] == 'R' and directions[i + 1] == 'L':
            time_to_collision = (positions[i + 1] - positions[i]) // 2
            if time_to_collision < min_time:
                min_time = time_to_collision
                collision_found = True

    if collision_found:
        return min_time
    else:
        return -1

n = 4
directions = "RLRL"
positions = [2, 4, 6, 10]

print(first_collision_time(n, directions, positions))
