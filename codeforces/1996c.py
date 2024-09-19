t = int(input())

for _ in range(t):
    n, q = map(int, input().split())
    
    a = input().strip()
    b = input().strip()
    
    # prefix arrays
    freq_a = [[0] * 26 for _ in range(n + 1)]
    freq_b = [[0] * 26 for _ in range(n + 1)]
        
    # count frequencies
    for i in range(1, n + 1):
        char_a = ord(a[i - 1]) - ord('a')
        char_b = ord(b[i - 1]) - ord('a')
        for j in range(26):
            freq_a[i][j] = freq_a[i - 1][j] + (1 if j == char_a else 0)
            freq_b[i][j] = freq_b[i - 1][j] + (1 if j == char_b else 0)

    # queries
    for _ in range(q):
        l, r = map(int, input().split())

        count_a = [0] * 26
        count_b = [0] * 26
            
        # count differences
        for j in range(26):
            count_a[j] = freq_a[r][j] - freq_a[l - 1][j]
            count_b[j] = freq_b[r][j] - freq_b[l - 1][j]
            
        # count operations
        operations = 0
        for j in range(26):
            if count_a[j] != count_b[j]:
                operations += abs(count_a[j] - count_b[j])
            
        print(operations//2)