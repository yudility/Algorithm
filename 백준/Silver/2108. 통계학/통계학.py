import sys
input = sys.stdin.readline

n = int(input())
arr = [int(input()) for i in range(n)]

# 산술평균(소수점 이하 첫째 자리에서 반올림)
print(round(sum(arr)/n)) # 23.5 --> 24

# 중앙값
# N개의 수들을 증가하는 순서로 나열했을 경우 그 중앙에 위치하는 값
arr2=sorted(arr)
print(arr2[n//2]) 

# 최빈값
# N개의 수들 중 가장 많이 나타나는 값
num_cnt = dict() # 숫자: 나온횟수
for i in range(n):
    if arr[i] in num_cnt:
        num_cnt[arr[i]] +=1
    else: 
        num_cnt[arr[i]] = 1

mx = max(num_cnt.values())
mx_list = [] # 최빈값들이 들어가는 배열

for num in num_cnt:
    if num_cnt[num] == mx:
        mx_list.append(num) # 가장 자주 나온숫자를 mx_list에 넣는다.


# 여러 개 있을 때에는 최빈값 중 두 번째로 작은 값을 출력한다.
if len(mx_list) == 1:
    print(mx_list[0])
else: 
    mx_list.sort()
    print(mx_list[1])

# 범위
print(max(arr)-min(arr))