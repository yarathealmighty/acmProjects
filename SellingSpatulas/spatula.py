while True:
    n = int(input())

    if(n == 0):
        break

    times = []
    profits = []

    for _ in range(0,1439):
        profits.append(-8)

    for _ in range(n):
        line = str(input()).split()
        duo = (int(line[0]),int(round(float(line[1]),2)*100))
        times.append(duo[0])
        profits[duo[0]] += duo[1]

    E = []
    E.append(profits[0])
    for i in range(1,len(profits)):
        E.append(max(E[i-1] + profits[i],profits[i]))

    max_E = max(E)
    if max_E <= 0:
        print('no profit')
        continue

    max_index = E.index(max_E)

    start_index = max_index
    for i in range(start_index,0,-1):
        if E[i] > 0:
            start_index = i
        else:
            break

    if max_E < 100:
        max_E = '00' + str(max_E)

    output = str(max_E)[:-2] + '.' + str(max_E)[-2:] + ' ' + str(start_index) + ' ' + str(max_index) 
    print(output)