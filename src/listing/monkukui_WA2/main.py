#! /usr/bin/python3

n, p = map(int, input().split())
max_p_sold_out = 0
min_p_on_sale = 10**7

for _ in range(n):
    price, status = input().split()
    price = int(price)
    if status == "sold_out":
        max_p_sold_out = max(max_p_sold_out, price)
    else:
        min_p_on_sale = min(min_p_on_sale, price)

if max_p_sold_out <= p < min_p_on_sale:
    print("YES")
else:
    print("NO")
