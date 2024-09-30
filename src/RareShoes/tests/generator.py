#! /usr/bin/python3

# テストケースの計画
# 合計30ケース
# -  2ケース / サンプル
# - 10ケース / NとMが同じくらい & ランダム
# - 10ケース / NとMが同じくらい & 中心にたくさんあるパターン
# -  4ケース / Nが少ない・Mが多い & ランダム
# -  4ケース / Mが少ない・Nが多い & ランダム

import os
import random

# Constraints
# N: 1 <= N <= 200000
# M: 1 <= M <= 200000
# x, y: 0 <= x, y <= 10^9
# z: 0 <= z <= 10^9
MIN_N = 1
MAX_N = 10
MIN_M = 1
MAX_M = 10
MIN_XY = 0
MAX_XY = 10**9
MIN_Z = 0
MAX_Z = 10**9

random.seed(0)

# NとMが同じケースを生成する, x, y, zは一様ランダム
def generate_random_case_N_M_equal_random():
    small = random.randint(10 * 7, 10 * 8)
    N = random.randint(MAX_N - small, MAX_N)
    M = N

    entries = []
    for _ in range(N):
        a = random.randint(MIN_XY, MAX_XY)
        b = random.randint(MIN_XY, MAX_XY)
        x = min(a, b)
        y = max(a, b)
        entries.append((x, y))
    queries = [random.randint(MIN_Z, MAX_Z) for _ in range(M)]

    return N, M, entries, queries


# NとMが同じケースを生成する, x, y, zは中心に集まるようにたくさん生成
def generate_random_case_N_M_equal_center():
    small = random.randint(10 * 7, 10 * 8)
    N = random.randint(MAX_N - small, MAX_N)
    M = N
    XY_CENTER = 10**9 // 2
    SIGMA = XY_CENTER  # 標準偏差

    entries = []
    for _ in range(N):
        while True:
            a = int(random.gauss(XY_CENTER, SIGMA))
            b = int(random.gauss(XY_CENTER, SIGMA))
            x = min(a, b)
            y = max(a, b)
            if 0 <= x and y <= MAX_XY:
                entries.append((x, y))
                break

    queries = [random.randint(MIN_Z, MAX_Z) for _ in range(M)]

    return N, M, entries, queries


# Nが小さい・Mが大きいケースを生成する, x, y, zは一様ランダム
def generate_random_case_N_small_M_big():
    small = random.randint(10 * 7, 10 * 8)
    N = random.randint(MIN_N, MIN_N + small)
    M = random.randint(MAX_M - small, MAX_M)

    entries = []
    for _ in range(N):
        a = random.randint(MIN_XY, MAX_XY)
        b = random.randint(MIN_XY, MAX_XY)
        x = min(a, b)
        y = max(a, b)
        entries.append((x, y))

    queries = [random.randint(MIN_Z, MAX_Z) for _ in range(M)]

    return N, M, entries, queries


# Nが大きい・Mが小さいケースを生成する, x, y, zは一様ランダム
def generate_random_case_N_big_M_small():
    small = random.randint(10 * 7, 10 * 8)
    N = random.randint(MAX_N - small, MAX_N)
    M = random.randint(MIN_M, MIN_M + small)

    entries = []
    for _ in range(N):
        a = random.randint(MIN_XY, MAX_XY)
        b = random.randint(MIN_XY, MAX_XY)
        x = min(a, b)
        y = max(a, b)
        entries.append((x, y))

    queries = [random.randint(MIN_Z, MAX_Z) for _ in range(M)]

    return N, M, entries, queries


def write_case_to_file(filename, N, M, entries, queries):
    with open(filename, "w") as f:
        f.write(f"{N} {M}\n")
        for x, y in entries:
            f.write(f"{x} {y}\n")
        for z in queries:
            f.write(f"{z}\n")


# テストケースの計画
# -  3ケース / サンプル
# - 10ケース / NとMが同じくらい & ランダム
# - 10ケース / NとMが同じくらい & 中心にたくさんあるパターン
# - 10ケース / Nが少ない・Mが多い & ランダム
# - 10ケース / Mが少ない・Nが多い & ランダム

if __name__ == "__main__":
    output_dir = "./"
    if not os.path.exists(output_dir):
        os.makedirs(output_dir)

    # - 10ケース / NとMが同じくらい & ランダム
    for i in range(10):
        N, M, entries, queries = generate_random_case_N_M_equal_random()
        filename = os.path.join(output_dir, f"10_N_M_equal_random_{i:02d}.in")
        write_case_to_file(filename, N, M, entries, queries)

    # - 10ケース / NとMが同じくらい & 中心にたくさんあるパターン
    for i in range(10):
        N, M, entries, queries = generate_random_case_N_M_equal_center()
        filename = os.path.join(output_dir, f"20_N_M_equal_center_{i:02d}.in")
        write_case_to_file(filename, N, M, entries, queries)

    # -  10ケース / Nが少ない・Mが多い & ランダム
    for i in range(10):
        N, M, entries, queries = generate_random_case_N_small_M_big()
        filename = os.path.join(output_dir, f"30_N_small_M_big_{i:02d}.in")
        write_case_to_file(filename, N, M, entries, queries)

    # -  10ケース / Mが少ない・Nが多い & ランダム
    for i in range(10):
        N, M, entries, queries = generate_random_case_N_big_M_small()
        filename = os.path.join(output_dir, f"40_N_big_M_small_{i:02d}.in")
        write_case_to_file(filename, N, M, entries, queries)

    print(f"40 cases have been written to the '{output_dir}' directory.")
