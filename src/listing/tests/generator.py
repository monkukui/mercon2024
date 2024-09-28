#! /usr/bin/python3

import itertools
import random

MAX_N = 10**5
MIN_N = 2
MAX_P = 9999999
MIN_P = 300
SOLD_OUT = "sold_out"
ON_SALE = "on_sale"


class TestCaseGenerator:
    def __init__(self, seed):
        self.random = random.Random(seed)

    def generate(self, n, is_overrange, is_underrange):
        if n is None:
            n = self.random.randint(MIN_N, MAX_N)

        assert MIN_N <= n <= MAX_N
        p = self.random.randint(MIN_P, MAX_P)

        if is_underrange:
            max_p_sold_out = self.random.randint(p, MAX_P)
        else:
            max_p_sold_out = max(p - 1, MIN_P)
        if is_overrange:
            min_p_on_sale = self.random.randint(MIN_P, p)
        else:
            min_p_on_sale = min(p + 1, MAX_P)

        num_sold_out = self.random.randint(1, n - 1)

        sold_out = self.random.choices(range(MIN_P, max_p_sold_out + 1), k=num_sold_out)
        if is_underrange:
            sold_out[0] = max_p_sold_out

        on_sale = self.random.choices(
            range(min_p_on_sale, MAX_P + 1), k=(n - num_sold_out)
        )
        if is_overrange:
            on_sale[0] = min_p_on_sale

        items = list(
            itertools.chain(
                zip(sold_out, itertools.repeat(SOLD_OUT)),
                zip(on_sale, itertools.repeat(ON_SALE)),
            )
        )
        self.random.shuffle(items)

        assert len(items) == n

        ans = not is_overrange and not is_underrange

        return n, p, items, ans


if __name__ == "__main__":
    import argparse
    import os

    variables = dict(
        n=[MIN_N, MAX_N, 10, 100, None],
        is_overrange=[False, True],
        is_underrange=[False, True],
    )

    parser = argparse.ArgumentParser()
    parser.add_argument("-s", "--seed", type=int, default=0)
    parser.add_argument("-n", "--num-tests", type=int, default=100)
    parser.add_argument("-o", "--output-dir", default=".")
    parser.add_argument("-p", "--prefix", default="01_test_gen_")
    args = parser.parse_args()

    os.makedirs(args.output_dir, exist_ok=True)

    gen = TestCaseGenerator(args.seed)

    cases = list(itertools.product(*variables.values()))

    digits = len(str(args.num_tests))

    for i in range(args.num_tests):
        n, is_overrange, is_underrange = cases[i % len(cases)]

        n, p, items, ans = gen.generate(n, is_overrange, is_underrange)
        with open(f"{args.output_dir}/{args.prefix}{i:0{digits}d}.in", "w") as f:
            f.write(f"{n} {p}\n")
            for price, state in items:
                f.write(f"{price} {state}\n")
        with open(f"{args.output_dir}/{args.prefix}{i:0{digits}d}.out", "w") as f:
            f.write("YES\n" if ans else "NO\n")
