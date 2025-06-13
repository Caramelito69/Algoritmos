while True:
    try:
        entrada = input().split()

        m = int(entrada[0])
        s = int(entrada[1])
        k = int(entrada[2])

        print((k + s) % m)
    except:
        break
