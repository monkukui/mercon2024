import random

MAX_LARGE = 200000
MAX_SMALL = 1000
MAX_H = 100
MAX_U = 1000000000
MAX_V = 1000000000

max_n = 10

for i in range(5):
    with open(f"01_small_random_0{i}.in", "w") as f:
        n = random.randint(1, max_n)
        print(n, file=f)
        for _ in range(n):
            u = random.randint(1, MAX_U)
            v = random.randint(1, MAX_V)
            h = random.randint(1, MAX_H)
            print(u, v, h, file=f)
