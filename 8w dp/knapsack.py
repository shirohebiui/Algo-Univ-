def knapSack_dp_A(W, wt, val, n):
    A = [[0 for x in range(W + 1)] for x in range(n + 1)]
    for i in range(1, n + 1): 
        for w in range(1, W + 1):
            if wt[i-1]>w: #i번째 물건이 배낭 용량 초과 
                A[i][w] = A[i-1][w]
            else: #i번째 물건이 배낭 용량 이하
                valWith = val[i-1] + A[i-1][w-wt[i-1]] # 넣는 경우
                valWithout = A[i-1][w]
                A[i][w] = max(valWith, valWithout)
    return A # 최종 결과가 저장됨
val = [60, 100, 190, 120, 200, 150] 
wt = [2, 5, 8, 4, 7, 6]
W = 18
n = len(val)
# 빼는 경우
# 더 큰 값 선택
table = knapSack_dp_A(W, wt, val, n)
print("0-1배낭문제(분할 정복): ", knapSack_dp_A(W, wt, val, n)) 
print("0-1배낭문제(동적 계획-A): ", table[n][W])
for i in range(n):
    print(table[i])