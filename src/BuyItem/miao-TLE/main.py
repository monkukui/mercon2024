#!/usr/bin/pypy3
n = int(input())

res = []
uset, vset = set(), set()
uv2h = {}

for i in range(n):
    u,v,h = map(int, input().split())
    uset.add(u)
    vset.add(v)
    uv2h[(u,v)] = h

for v in vset:
    cur_max = 0
    cur_max_u = 0
    for u in uset:
        if (u,v) in uv2h:
            if uv2h[(u,v)] > cur_max:
                cur_max = uv2h[(u,v)]
                cur_max_u = u
    res.append((cur_max_u, v))

print(len(res))
for u,v in res:
    print(u, v)
