words = []
for i in range(5):
    a = input()
    words.append(a)
# words = [ input() for i in range(5)]

for i in range(15):
    for j in range(5):
        if len(words[j]) <= i:
            continue
        print(words[j][i], end="")