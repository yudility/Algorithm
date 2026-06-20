def solution(k, tangerine):
    answer = 0
    t_count = {}
    for t in tangerine:
        if t in t_count.keys():
            t_count[t] += 1
        else:
            t_count[t] = 1
    
    t_list = sorted(t_count.values(), reverse=True)

    for i in t_list:
        if k <= 0:
            return answer
        else:
            k -= i
            answer += 1
    return answer

print(solution(6,[1, 3, 2, 5, 4, 5, 2, 3]))

    #t_count = dict(sorted(t_count.items(), key=lambda x:x[1], reverse=True))
    # for i in t_count:
    #     if k <= 0:
    #         return answer
    #     k -= t_count[i]
    #     answer += 1

    