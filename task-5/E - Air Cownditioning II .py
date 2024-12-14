def is_sufficient(cooling, cows):
    for s, t, c in cows:
        for i in range(s, t + 1):
            if cooling[i] < c:
                return False
    return True

def min_cost(n, m, cows, conditioners):
    from itertools import combinations

    min_cost = float('inf')
    for r in range(1, m + 1):
        for combo in combinations(conditioners, r):
            cooling = [0] * 101
            cost = 0
            for a, b, p, cost_i in combo:
                cost += cost_i
                for i in range(a, b + 1):
                    cooling[i] += p
            if is_sufficient(cooling, cows):
                min_cost = min(min_cost, cost)
    return min_cost

n, m = map(int, input().split())
cows = [tuple(map(int, input().split())) for _ in range(n)]
conditioners = [tuple(map(int, input().split())) for _ in range(m)]

print(min_cost(n, m, cows, conditioners))
