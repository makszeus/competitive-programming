import sys

def main():
    n = int(input())
    a = list(map(int, input().split()))

    if n < 3:
        print(0)
        return

    a.sort()
    suff = 0
    pref = 0
    ans = sys.maxsize

    for i in range(n):
        suff += a[-1] - a[i]

    for i in range(n - 1):
        suff -= (a[-1] - a[i])
        ans = min(ans, suff + pref)
        pref += (a[i + 1] - a[i]) * (i + 1)

    print(ans)

if __name__ == "__main__":
    main()