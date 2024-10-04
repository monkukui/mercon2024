#!/usr/bin/python3

w,h,t = map(int, input().split())
sx, sy = map(int, input().split())

x = sx + t % (2 * w)
if x > w and x < 2 * w:
    x = 2 * w - x
elif x >= 2 * w:
    x = x - 2 * w

y = sy + t % (2 * h)
if y > h and y < 2 * h:
    y = 2 * h - y
elif y >= 2 * h:
    y = y - 2 * h

print(x, y)