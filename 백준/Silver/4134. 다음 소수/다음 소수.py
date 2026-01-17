import sys
input = sys.stdin.readline
t = int(input())

def check(m):
    for i in range(2, int(m**0.5)+1):
        if m % i == 0:
            return False
    return True

for i in range(t):
    n = int(input())
    while True:
        if n == 1 or n==0:
            print(2)
            break
        if check(n):
            print(n)
            break
        else:
            n+=1

    