#!/usr/bin/python3

def main():
    n, x = map(int, input().split())
    a = list(map(int, input().split()))

    max_val = 2 * x
    dp = [0 for _ in range(max_val)]
    _dp = [0 for _ in range(max_val)]

    dp[0] = 1  # 初期状態

    for num in a:
        for j1 in range(max_val):
            if dp[j1]:
                _dp[j1] |= dp[j1]

                if j1 + num < max_val:
                    _dp[j1 + num] |= dp[j1]

                _dp[j1] |= (dp[j1] << num)
        dp, _dp = _dp, dp

    ans = 0
    sum_a = sum(a)

    for j1 in range(max_val):
        for j2 in range(max_val):
            if dp[j1] & (1 << j2):
                is_valid = True
                b = [j1, j2, sum_a - j1 - j2]
                amount = 0
                for i in range(3):
                    e = b[i]
                    amount += e
                    if amount < x:
                        for j in range(i + 1, 3):
                            if b[j] > 0:
                                is_valid = False
                                break
                        if not is_valid:
                            break
                    amount -= x
                if not is_valid:
                    continue

                point = j1 * 1 + j2 * 2 + (sum_a - j1 - j2) * 3
                if ans < point:
                    ans = point

    print(ans)

if __name__ == "__main__":
    main()
