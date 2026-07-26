def solution(clothes):
    
    dic = {} 
    for i in range(len(clothes)):
        if clothes[i][1] in dic :
            dic[clothes[i][1]] += 1
        else :
            dic[clothes[i][1]] = 1
            
    answer = 1
    for cnt in dic.values() :
        answer *= (cnt + 1)
    
    return answer-1