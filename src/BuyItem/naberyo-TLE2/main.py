#! /usr/bin/python3
from collections import defaultdict

n = int(input())

l = defaultdict(set)

for _ in range(n):
    u, v, h = map(int, input().split())
    l[v].add((h, u))

q = [(0, [])]
for v in l:
    qnew = []
    while q:
        hsum, vulist = q.pop()
        for h, u in l[v]:
            qnew.append((hsum + h, vulist + [(v, u)]))
    q = qnew

print(len(l))
for v, u in sorted(max(q)[1]):
    print(v, u)
