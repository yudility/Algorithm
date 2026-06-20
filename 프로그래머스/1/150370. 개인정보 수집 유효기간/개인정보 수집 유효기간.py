def dateToDays(date):
    y, m, d = map(int, date.split("."))
    return y * 28 * 12 + m * 28 + d 


def solution(today, terms, privacies):
    
    te = {terms[j].split()[0] : int(terms[j].split()[1]) for j in range(len(terms))}
    answer = []
    
    for i in range(len(privacies)):
        start_day, kind = privacies[i].split()
        if dateToDays(start_day) + te[kind] * 28 <= dateToDays(today):
            answer.append(i + 1)
    return answer
