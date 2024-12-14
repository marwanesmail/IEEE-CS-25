def find_min_difference(weights):
    total_weight = sum(weights)
    n = len(weights)
    min_diff = float('inf')

    for i in range(1 << n):
        group1_weight = 0
        for j in range(n):
            if i & (1 << j):
                group1_weight += weights[j]
        group2_weight = total_weight - group1_weight
        min_diff = min(min_diff, abs(group1_weight - group2_weight))

    return min_diff

n = int(input())
weights = list(map(int, input().split()))

print(find_min_difference(weights))
