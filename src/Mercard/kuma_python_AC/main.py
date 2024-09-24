#!/usr/bin/python3

N, X = map(int, input().split())
A = list(map(int, input().split()))

# dp[1%で購入した商品の金額の合計][2%で購入した商品の金額の合計] = 得たポイント
dp = [[-1 for k in range(X * 2)] for j in range(X * 2)]
dp[0][0] = 0

for i in range(N):
    a = A[i]
    for j in range(2 * X - 1, -1, -1):
        for k in range(2 * X - 1, -1, -1):
            if dp[j][k] == -1:
                continue
            if j < X:
                dp[j + a][k] = max(dp[j + a][k], dp[j][k] + a)
            if k < X:
                dp[j][k + a] = max(dp[j][k + a], dp[j][k] + a * 2)

sum_a = sum(A)
ans = 0
for i in range(2 * X):
    ans = max(ans, dp[i][0])
    if i >= X:
        for j in range(2 * X):
            ans = max(ans, dp[i][j])
            if j >= X:
                ans = max(ans, dp[i][j] + 4 * (sum_a - i - j))
print(ans)
