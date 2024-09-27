#!/usr/bin/python3
# [ref] atcoder naming
# 00_sample_01.in
# 00_sample_02.in
# 01_test_01.in
# 01_test_02.in
# ...

import random

MAX_LARGE = 500000
MAX_SMALL = 1000
MAX_H = 100


def write_or_print(file_name, test_case, write_to_file):
    if write_to_file:
        with open(f"BuyItem/tests/{file_name}", 'w') as f:
            f.write(str(test_case[0]) + '\n')
            for i in range(1, len(test_case)):
                f.write(' '.join(map(str, test_case[i])) + '\n')
    else:
        print(test_case[0])
        for i in range(1, len(test_case)):
            print(' '.join(map(str, test_case[i])))

def generate_random_test_case(i, N, max_u, max_v, max_h, is_sample=True, write_to_file=False):
    file_name = '00_sample_' + str(i).zfill(2) + '.in' if is_sample else '01_test_' + str(i).zfill(2) + '.in'
    print(file_name)
    test_case = []
    test_case.append(N)
    uvset = set()
    vhset = set()
    for i in range(N):
        u = random.randint(1, max_u)
        v = random.randint(1, max_v)
        # if i!=j, (ui, vi)!=(uj,vj)
        while (u,v) in uvset:
            u = random.randint(1, max_u)
            v = random.randint(1, max_v)
        uvset.add((u,v))
        h = random.randint(1, max_h)
        while (v,h) in vhset:
            h = random.randint(1, max_h)
        vhset.add((v,h))

        test_case.append([u, v, h])
    # write to file
    # pad i to 2 digits
    write_or_print(file_name, test_case, write_to_file)


random.seed(0)
# # generate 3 samples
# generate_random_test_case(1, 4, 2, 2, MAX_H, write_to_file=True)
# generate_random_test_case(2, 10, 5, 5, MAX_H, write_to_file=True)
# generate_random_test_case(3, 15, 10, 20, MAX_H, write_to_file=True)

# # generate random test cases
# for i in range(10):
#     N = random.randint(1, MAX_SMALL)
#     generate_random_test_case(i+1, N, MAX_SMALL, MAX_SMALL, MAX_H, is_sample=False, write_to_file=True)

# for i in range(11,20):
#     N = random.randint(1, MAX_LARGE)
#     generate_random_test_case(i+1, N, MAX_LARGE, MAX_LARGE, MAX_H, is_sample=False, write_to_file=True)

# 21, 22 is hand-crafted

# large cases
# for i in range(22, 25):
#     N = random.randint(MAX_LARGE-100, MAX_LARGE)
#     generate_random_test_case(i+1, N, MAX_LARGE, MAX_LARGE, MAX_H, is_sample=False, write_to_file=True)