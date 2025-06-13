while True:
    try:
        array = input().split()
        
        a = int(array[0])
        b = int(array[1])
        c = int(input())

        print((c + b) % a)
    except:
        break