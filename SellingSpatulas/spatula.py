def find_maxes(arr,curr_max):
    maxes = []
    if curr_max > 0:
        for i in range(0,len(arr)):
            if arr[i] == curr_max:
                maxes.append(i)
    return maxes

def find_points(end):
    start = end
    for i in range(start,-1,-1):
        if E[i] > 0:
            start = i
        else:
            break
    return (start,end)

while True:
    n = int(input())

    if(n == 0):
        break

    times = []
    profits = []

    for _ in range(0,1440):
        profits.append(-8)

    for _ in range(n):
        line = str(input()).split()
        duo = (int(line[0]),int(round(round(float(line[1]),2)*100)))
        times.append(duo[0])
        profits[duo[0]] += duo[1]

    E = []
    E.append(profits[0])
    for i in range(1,len(profits)):
        E.append(max(E[i-1] + profits[i],profits[i]))

    max_E = max(E)
    maxes = find_maxes(E,max_E)

    if maxes == []:
        print('no profit')
        continue

    shortest_time = 1440
    start = -1
    end = -1
    for index in maxes:
        start_index,end_index = find_points(index)
        if shortest_time > end_index - start_index:
            shortest_time = end_index - start_index
            start = start_index
            end = end_index

    num_max_E = max_E

    if num_max_E < 10:
        max_E = '0' + str(max_E)

    if num_max_E < 100:
        max_E = '0' + str(max_E)

    # print(E[:20])

    output = str(max_E)[:-2] + '.' + str(max_E)[-2:] + ' ' + str(start) + ' ' + str(end) 
    print(output)