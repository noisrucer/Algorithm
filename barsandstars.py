def barsAndStars(s, startIndex, endIndex):
    n = len(s)
    prefix = [0] * (n+1)
    barPos = 0
    prefix[0] = 0
    for i in range(len(s)):
        if s[i-1] == '|':
            prefix[i] = prefix[i-1] + i - barPos - 1
            barPos = i
        else:
            if i == 0:
                prefix[i] = 0
            else:
                prefix[i] = prefix[i-1]

    res = []
    print(prefix)

    for i in range(len(startIndex)):
        start, end = startIndex[i]-1, endIndex[i]-1

    res.append(prefix[end] - prefix[start])


    return res


print(barsAndStars("|**|*|*", [1],[6]))
