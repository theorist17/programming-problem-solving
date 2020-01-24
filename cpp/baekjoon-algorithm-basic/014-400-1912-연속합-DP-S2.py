import sys

n = int(sys.stdin.readline())
temp = map(int, sys.stdin.readline().split())

arr = [0]
for t in temp:
    arr.append(t)
dp = [-1000] * (n + 1)

dp[n] = arr[n]
for i in reversed(range(1, n)):
    dp[i] = max(arr[i], dp[i+1]+arr[i])
print(dp)
print(max(dp))
