num = int(input())

line = 1
line_end = 1

while line_end < num:
    line += 1
    line_end += line

k = line_end - num

if line % 2 == 0:
    a = line - k 
    b = k + 1
else:
    a = k + 1
    b = line - k

print(f"{a}/{b}")
