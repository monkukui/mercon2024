#!/Users/deadbeef/.pyenv/shims/python

import re
import sys

MAX = 10**12


def main():
    m = re.match(r"^(\d+) (\d+) (\d+)\n(\d+) (\d+)$", sys.stdin.read())
    assert m, "Does not match with regexp"

    w, h, t, s_x, s_y = map(int, m.groups())
    assert 1 <= w <= MAX, "w out of range: %d" % w
    assert 1 <= h <= MAX, "h out of range: %d" % h
    assert 1 <= t <= MAX, "t out of range: %d" % t
    assert 0 <= s_x <= MAX, "s_x out of range: %d" % s_x
    assert 0 <= s_y <= MAX, "s_y out of range: %d" % s_y


if __name__ == "__main__":
    main()
