#!/usr/bin/python3

w,h,t = map(int, input().split())
sx, sy = map(int, input().split())

a,b = 1,1
for i in range(t):
    if sx+a<=w and sx+a>=0:
        sx+=a
    else:
        a=-a
        sx+=a
    if sy+b<=h and sy+b>=0:
        sy+=b
    else:
        b=-b
        sy+=b
print(sx,sy)