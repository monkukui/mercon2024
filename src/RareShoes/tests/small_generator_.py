
import random
# ranomly generate 5 small test cases
for i in range(5):
    N, M = random.randint(1, 5), random.randint(1, 5)
    # generate N pairs of x, y, where x <= y
    entries = [(random.randint(1, 5), random.randint(1, 5)) for _ in range(N)]

    # generate M random z values
    queries = [random.randint(1, 8) for _ in range(M)]

    # file_name = f"src/RareShoes/tests/00_random_0{i}.in"
    # with open(file_name, "w") as f:
    #     f.write(f"{N} {M}\n")
    #     for x, y in entries:
    #         if x > y:
    #             x, y = y, x
    #         f.write(f"{x} {y}\n")
    #     for z in queries:
    #         f.write(f"{z}\n")
    # print(f"Generated {file_name}")
    print(N, M)
    for x, y in entries:
        if x > y:
            x, y = y, x
        print(x, y)
    for z in queries:
        print(z)
    print()
