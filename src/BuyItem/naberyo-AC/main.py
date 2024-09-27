#! /usr/bin/python3
from collections import defaultdict

n = int(input())

l = defaultdict(set)

for _ in range(n):
    u, v, h = map(int, input().split())
    l[v].add((h, u))

print(len(l))
for v in sorted(l):
    h, u = max(l[v])
    print(v, u)

    # 一意性のチェック
    l[v].discard((h, u))
    assert not l[v] or h != max(l[v])[0]
