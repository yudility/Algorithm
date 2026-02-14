N, M =map(int, input().split(" "))

A =[0 for i in range(N)]
B =[0 for i in range(N)]

for n in range(N):
    A[n]=list(map(int, input().split()))

for n in range(N):
    B[n]= list(map(int, input().split()))

for n in range(N):
    for m in range(M):
        print(A[n][m]+B[n][m], end=" ")
    print("")