R, S, K = map(int, input().split())
# k-1 x k-1 mtx in r x s mtx
# kadane algorithm

rows = []
for i in range(R):
    row = input()
    rows.append(row)

max_flies = []
for i in range(R):
    for j in range(S):
        swat_range = rows[i][j-(K-1):j+K]
        print(f'[LOG]swat_range: {swat_range}, i: {i}, j: {j}')