#!/usr/bin/python3

# 左からマッチングしていく貪欲

n,m = map(int,input().split())

xys = []
for i in range(n):
    x,y = map(int,input().split())
    xys.append((x,y,i))

zs = []
for i in range(m):
    z = int(input())
    zs.append(z)

zs.sort()

used = [False] * n
res = 0
sorted_left = sorted(xys, key=lambda x: x[0])

cur_z = 0
for i in range(n):
    while cur_z < m and zs[cur_z] < sorted_left[i][0]:
        cur_z += 1
    if cur_z == m:
        break
    if zs[cur_z] >= sorted_left[i][0] and zs[cur_z] <= sorted_left[i][1]:
        used[sorted_left[i][2]] = True
        res += 1
        cur_z += 1
print(res)