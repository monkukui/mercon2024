# input
n, p = map(int, input().split())
c, s = [], []
for i in range(n):
    ci, si = int(input()), input()
    c.append(ci)
    s.append(si)


def solve():
    lb, ub = -1, 10000000
    for i in range(n):
        if s[i] == "sold_out":
            ub = min(ub, c[i])
        elif s[i] == "on_sale":
            lb = max(lb, c[i])
    return "YES" if lb <= p <= ub else "NO"


print(solve())
