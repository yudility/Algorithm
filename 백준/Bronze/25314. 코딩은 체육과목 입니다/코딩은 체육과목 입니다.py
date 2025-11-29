n = int(input())

cnt = n // 4
if n % 4 != 0:
    cnt += 1

result = 'long'

for i in range(cnt-1):
    result += ' long'

print(result + ' int')

