from itertools import permutations # combinations

def solution(k, dungeons):
    answer = 0
    
    for i in permutations(dungeons, len(dungeons)):
        temp = k
        cnt = 0
        for e, r in i:
            if temp >= e:
                temp -= r
                cnt += 1
        answer = max(cnt, answer)
    
    return answer