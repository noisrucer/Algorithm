def maxDepth():
    x = 10
    def change():
        nonlocal x
        x += 10
    change()
    print(x)
    return 1

maxDepth()