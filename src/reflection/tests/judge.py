#!/Users/deadbeef/.pyenv/shims/python

import re
import sys

MAX = 10**12


def main():
    m = re.match(r"^(\d+) (\d+) (\d+)\n(\d+) (\d+)$", sys.stdin.read())
    assert m, "Does not match with regexp"

    w, h, t, x, y = map(int, m.groups())

    dx, dy = 1, 1

    for ti in range(t):
        x, y = x + dx, y + dy

        if x == 0:
            dx = 1
        elif x == w:
            dx = -1
        if y == 0:
            dy = 1
        elif y == h:
            dy = -1

    print(x, y)


if __name__ == "__main__":
    main()
