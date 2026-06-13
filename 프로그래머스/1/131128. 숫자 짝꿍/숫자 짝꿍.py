def solution(X, Y):
    answer = ''
    
    for i in range(9, -1, -1):
        countX = X.count(str(i))
        countY = Y.count(str(i))
        
        if (countX != 0 and countY != 0):
            if (len(answer) == 0) and (i == 0):
                answer = "0"
            else:
                result = countX if (countX < countY) else countY
                for _ in range(result):
                    answer += str(i)
        
    if (len(answer) == 0):
        answer = '-1'
        
    return answer