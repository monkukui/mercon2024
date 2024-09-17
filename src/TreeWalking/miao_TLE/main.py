#!/usr/bin/python3

import sys
sys.setrecursionlimit(100000000)

from collections import defaultdict

n,k = map(int,input().split())

tree = defaultdict(list)

us, vs = [], []
for i in range(n-1):
    u,v = map(int,input().split())
    us.append(u)
    vs.append(v)

a = list(map(int,input().split()))
root = a[0]

for i in range(n-1):
    u,v = us[i], vs[i]
    tree[a[u-1]].append(a[v-1])
    tree[a[v-1]].append(a[u-1])

# pre-calculate the height of each node
heights = {}
fas = {}


def dfs_height(u, fa):
    fas[u] = fa
    h = 0
    for v in tree[u]:
        if v != fa:
            h = max(h, dfs_height(v, u))
    heights[u] = h + 1
    return h + 1

dfs_height(root, -1)

def dfs_find_min(root, fa, curk, include_root=True):
    # find the min next node that d >= k
    if heights[root] == curk:
        if include_root:
            return root
        else:
            return -1
    if heights[root] < curk:
        return -1
    cands = []
    if include_root:
        cands.append(root)
    for nex in tree[root]:
        if nex == fa:
            continue
        nex_min = dfs_find_min(nex, root, curk)
        if nex_min != -1:
            cands.append(nex_min)
    if len(cands) == 0:
        return -1
    return min(cands)


start = dfs_find_min(root, -1, k)
if start == -1:
    print(-1)
else:
    res = []
    res.append(start)
    cur = start
    for i in range(k-1):
        nex = dfs_find_min(cur, fas[cur], k-1-i, include_root=False)
        res.append(nex)
        cur = nex
    print(*res)


        
