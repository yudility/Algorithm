n = int(input())
arr = list(map(int, input().split()))

left, right = 0, n-1
ans_left=arr[left]
ans_right=arr[right]
sum_lr = abs(ans_left + ans_right)

while left < right:
  t = arr[left] + arr[right]
  abs_t = abs(t)
  if abs_t < sum_lr:
    sum_lr = abs_t
    ans_left = arr[left]
    ans_right = arr[right]

  if t < 0: 
    left += 1
  else:
    right -= 1

print(ans_left, ans_right)
