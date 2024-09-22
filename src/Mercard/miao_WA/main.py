#!/usr/bin/python3

# すべての昇格パタンで貪欲:
# 1% -> 2% -> 3% -> 4%,
# 1% -> 3% -> 4%, 
# 1% -> 2% -> 4%, 
# 1% -> 4%
# 次のランクまで行ける商品セットは商品価格の和が最小になるような商品を選ぶ
# たぶんWA（今回使った商品は実は次で使ったほうがいいみたいな例がありそう）
n,x = map(int,  input().split())
a = list(map(int, input().split()))
max_sum = sum(a)

patterns =[[1,2,3], [1,3], [2,3], [3]]

candidates = []
for pattern in patterns:
    cur_res = max_sum
    cur_min_sum = 0
    cur_a = a.copy()
    pre_rank = 0
    for p in range(len(pattern)):
        cur_sum = pattern[p]*x - cur_min_sum # the target sum in this round
        if cur_sum <0:
            continue
        dp = [float('inf') for _ in range(max_sum + 1)]
        dp[0] = 0 # nothing chosen
        chosen = [[] for _ in range(max_sum + 1)]

        for i in range(len(cur_a)):
            for j in range(max_sum, cur_a[i]-1, -1):
                # print(j, a[i])
                if dp[j] > dp[j-cur_a[i]]+1:
                    dp[j] = dp[j-cur_a[i]]+1
                    chosen[j] = chosen[j-cur_a[i]] + [i]

        cur_min_sum = -1
        cur_chosen = []
        for i in range(cur_sum, max_sum+1):
            if dp[i] < float('inf'):
                # print(dp[i], end=' ')
                # print(*chosen[i])
                # print(i)
                cur_chosen = set(chosen[i])
                cur_min_sum = i
                break
        
        if cur_min_sum == -1: # can't upgrade anymore
            # ("can't upgrade anymore")
            break
        
        next_a = []
        for i in range(len(cur_a)):
            if i not in cur_chosen:
                next_a.append(cur_a[i])
        cur_a = next_a
        # print(cur_a)
        # print(pattern[p], pre_rank)
        cur_res += sum(cur_a) * (pattern[p] - pre_rank)
        pre_rank = pattern[p]

    candidates.append(cur_res)

# print(candidates)
print(max(candidates))

