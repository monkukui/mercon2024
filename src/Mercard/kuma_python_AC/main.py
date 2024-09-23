#!/usr/bin/python3

N, X = map(int, input().split())
A = list(map(int, input().split()))

# dp[1%で購入した商品の金額の合計][2%で購入した商品の金額の合計][3%で購入した商品の金額の合計] = 得たポイント
dp = [[[-1 for k in range(X * 2)] for j in range(X * 2)] for i in range(X * 2)]
dp[0][0][0] = 0

for i in range(N):
    a = A[i]
    for j in range(2 * X - 1, -1, -1):
        for k in range(2 * X - 1, -1, -1):
            for l in range(2 * X - 1, -1, -1):
                if dp[j][k][l] == -1:
                    continue
                if j < X:
                    dp[j + a][k][l] = max(dp[j + a][k][l], dp[j][k][l] + a)
                if k < X:
                    dp[j][k + a][l] = max(dp[j][k + a][l], dp[j][k][l] + a * 2)
                if l < X:
                    dp[j][k][l + a] = max(dp[j][k][l + a], dp[j][k][l] + a * 3)

sum_a = sum(A)
ans = 0
for i in range(2 * X):
    ans = max(ans, dp[i][0][0])
    if i >= X:
        for j in range(2 * X):
            ans = max(ans, dp[i][j][0])
            if j >= X:
                for k in range(2 * X):
                    ans = max(ans, dp[i][j][k])
                    if k >= X and dp[i][j][k] != -1:
                        ans = max(ans, dp[i][j][k] + 4 * (sum_a - i - j - k))
print(ans)
