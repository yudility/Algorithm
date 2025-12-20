a, b, c = map(int, input().split())

result = 0

if a == b and b == c:
    result = 10000 + a * 1000
elif a == b or b == c or c == a:
    result = 1000
    if a == b:
        result += (a * 100)
    elif b == c:
        result += (b * 100)
    else:
        result += (c * 100)
else:
    result = max(a, b, c) * 100

print(result)
