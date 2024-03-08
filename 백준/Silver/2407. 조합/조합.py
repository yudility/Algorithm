
def fact(x):
    if x<=1 :
        return 1
    else:
        return x*fact(x-1)

n, m = map(int,input().split())

result = fact(n)//(fact(m)*fact(n-m))

print(result)