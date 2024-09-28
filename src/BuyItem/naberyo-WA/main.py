#! /usr/bin/python3
import random
from collections import defaultdict

n = int(input())

l = defaultdict(set)

for _ in range(n):
    u, v, h = map(int, input().split())
    l[v].add((h, u))

print(len(l))
for v in sorted(l):
    h, u = random.choice(list(l[v]))
    print(v, u)
