
n = int(input())

arr = [[0] * 3 for _ in range(n)]
for i in range(n):
    arr[i] = list(map(int, input().split()))

if n == 1:
    print(min(arr[0]))
else:
    minv = []
    for head in range(3):
        dp = [[1000] * 3 for _ in range(n)]
        dp[0][head] = arr[0][head]

        for i in range(1, n):
            for j in range(3):
                dp[i][j] = arr[i][j] + min(dp[i-1][(j+1)%3], dp[i-1][(j+2)%3])
        
        candidate = []
        for j in range(3):
            if j != head:
                candidate.append(dp[n-1][j])
        minv.append(min(candidate))
        #print(dp)
    print(min(minv))