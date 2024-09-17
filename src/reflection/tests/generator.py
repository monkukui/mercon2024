#!/Users/deadbeef/.pyenv/shims/python

"""
This generator generates the follwoing cases:
- small: 1 <= w, h, t, s_x, s_y <= 1e3
- medium: 1 <= w, h, t, s_x, s_y <= 1e8
- large: 1 <= w, h, t, s_x, s_y <= 1e12

There're 5 test cases for each.
"""

import random


def main():
    # small
    for i in range(5):
        w = random.randint(1, 1000)
        h = random.randint(1, 1000)
        t = random.randint(1, 1000)
        s_x = random.randint(1, 1000)
        s_y = random.randint(1, 1000)
        with open(f"small_{i}.in", "w") as f:
            f.write(f"{w} {h} {t}\n{s_x} {s_y}\n")

    # medium
    for i in range(5):
        w = random.randint(1, 100000000)
        h = random.randint(1, 100000000)
        t = random.randint(1, 100000000)
        s_x = random.randint(1, 100000000)
        s_y = random.randint(1, 100000000)
        with open(f"medium_{i}.in", "w") as f:
            f.write(f"{w} {h} {t}\n{s_x} {s_y}\n")

    # large
    for i in range(5):
        w = random.randint(1, 1000000000000)
        h = random.randint(1, 1000000000000)
        t = random.randint(1, 1000000000000)
        s_x = random.randint(1, 1000000000000)
        s_y = random.randint(1, 1000000000000)
        with open(f"large_{i}.in", "w") as f:
            f.write(f"{w} {h} {t}\n{s_x} {s_y}\n")


if __name__ == "__main__":
    main()
