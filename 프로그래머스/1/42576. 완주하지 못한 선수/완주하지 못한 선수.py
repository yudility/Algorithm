def solution(participant, completion):
    pd = dict()
    for p in participant:
        pd[p] = pd.get(p, 0) + 1
    
    for c in completion:
        pd[c] -= 1
    
    for k in pd.keys():
        if pd.get(k) > 0:
            return k