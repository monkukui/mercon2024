#! /usr/bin/python3

# input
n, p = map(int, input().split())
c, s = [], []
for i in range(n):
    ci, si = input().split()
    c.append(int(ci))
    s.append(si)


def solve():
    lb, ub = -1, 10000000
    for i in range(n):
        if s[i] == "sold_out":
            lb = max(lb, c[i])
        elif s[i] == "on_sale":
            ub = min(ub, c[i])
    return "YES" if lb < p < ub else "NO"


print(solve())
