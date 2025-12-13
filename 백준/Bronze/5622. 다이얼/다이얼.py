s = input()
dial = ['ABC', 'DEF', 'GHI',
        'JKL', 'MNO', 'PQRS',
        'TUV', 'WXYZ']

ret = 0
for i in range(len(s)):
    for c in dial:
        if s[i] in c :
            ret += dial.index(c)+3

print(ret)