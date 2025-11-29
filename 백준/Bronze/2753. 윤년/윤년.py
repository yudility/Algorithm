years = int(input())

is_y = ((years % 4 == 0 and years % 100 != 0) 
 or years % 400 == 0)

if is_y:
    print(1)
else:
    print(0)