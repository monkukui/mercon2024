n = int(input())

item_max_dict = {}

for i in range(n):
    u,v,h = map(int, input().split())
    if v in item_max_dict:
        if item_max_dict[v][0] < h:
            item_max_dict[v] = (h, u)
    else:
        item_max_dict[v] = (h, u)

print(len(item_max_dict))
for k,v in item_max_dict.items():
    print(v[1], k)