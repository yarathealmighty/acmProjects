N = int(input())

for _ in range(N):
    M, C = map(int, input().split())
    garments = []
    for _ in range(C):
        prices = list(map(int, input().split()[1:]))
        garments.append(prices)

    # no solution check
    min_costs = [min(garment) for garment in garments]
    if sum(min_costs) > M:
        print("no solution")
        continue

    # brute force dp since small N M C K
    # dp setup
    max_spent = [0] * (M + 1)

    for row in garments:
        # iter through money
        for i in range(M, -1, -1):
            for price in row:
                if price <= i:
                    # spendable money
                    max_spent[i] = max(max_spent[i], max_spent[i - price] + price)

    # print
    print(max(max_spent))