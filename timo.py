while True:
    try:
        m = int(input())
        s = int(input())
        k = int(input())

        print((k + s) % m)
    except ValueError:
        break
