#!/usr/bin/python3

import heapq

N, M = map(int, input().split())
items = [tuple(map(int, input().split())) for _ in range(N)]
Z = [int(input()) for _ in range(M)]


events = list()
for item in items:
    events.append((item[0], 1, item[1]))
for zi in Z:
    events.append((zi, 2, 0))

events.sort()

min_heap = []  # 商品の出品終了時間の小さい順に格納
res = 0

for event in events:
    if event[1] == 1:
        end_time = event[2]
        heapq.heappush(min_heap, end_time)
    else:
        while min_heap:
            min_expire_time = min_heap[0]
            buy_time = event[0]
            if min_expire_time >= buy_time: # 購入可能
                res += 1
                heapq.heappop(min_heap)
                break
            heapq.heappop(min_heap)

print(res)

