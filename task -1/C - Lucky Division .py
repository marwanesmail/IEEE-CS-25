def is_lucky(number):
    for digit in str(number):
        if digit != '4' and digit != '7':
            return False
    return True

def is_almost_lucky(n):
    for i in range(1, n + 1):
        if is_lucky(i) and n % i == 0:
            return True
    return False

n = int(input("int num : "))

if is_almost_lucky(n):
    print("YES")
else:
    print("NO")
