def main():
    a, b = map(int, input().split())
    print(a+b)
    print(a-b)
    print(a*b)
    print(a//b)
    print(a%b)
    print(a**b)
    print(a<b)
    print(a>b)
    print(a<=b)
    print(a>=b)
    print(a==b)
    print(a!=b)
    print(a) #a++
    a += 1
    print(a + 1) #++a
    a += 1
    print(b) #b--
    b -= 1
    print(b - 1) #--b
    b -= 1

if __name__ == '__main__':
    main()