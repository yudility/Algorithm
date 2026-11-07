def solution(order):
    length = len(order)
    n = 1
    stack = []

    answer = 0

    for o in order:
        while n < o :
            stack.append(n)
            n+=1

        if n == o:
            answer += 1
            n += 1
            continue

        if stack.pop() == o:
            answer += 1
            continue

        break

    return answer
      