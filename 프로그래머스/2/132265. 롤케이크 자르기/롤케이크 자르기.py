from collections import Counter

def solution(topping):
    right = {}
    for t in topping:
        right[t] = right.get(t, 0) + 1

    left = set()
    answer = 0

    for t in topping:
        left.add(t)
        right[t] -= 1 
        if right[t] == 0:
            del right[t]
        if len(left) == len(right):
            answer += 1

  # dic = Counter(topping)
  # set_dic = set()
  # answer = 0
  # for i in topping:
  #   dic[i] -= 1
  #   set_dic.add(i)
  #   if dic[i] == 0:
  #     dic.pop(i)
  #   if len(dic) == len(set_dic):
  #     answer += 1
    return answer
