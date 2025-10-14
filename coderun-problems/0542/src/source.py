import sys

def main():
    n = int(input())
    a = list(map(int, input().split()))
    a.sort()
    s = sum(a)
    res = a[n - 1] * n
    y = max(a)
    for j in range(n):
        x = a[j]
        cur = x * (j + 1) + y * (n - 1 - j) - s
        res = min(res, cur)
    print(res)

if __name__ == '__main__':
    main()