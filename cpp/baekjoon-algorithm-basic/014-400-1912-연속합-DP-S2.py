#from collections import deque; tempcmd = deque(input().replace(' ', '\n').split('\n'));input = tempcmd.popleft

n = int(input())
temp = map(int, input().split())

arr = [0]
for t in temp:
    arr.append(t)
dp = [-1000] * (n + 1)

dp[n] = arr[n]
for i in reversed(range(1, n)):
    dp[i] = max(arr[i], dp[i+1]+arr[i])

print(max(dp))
