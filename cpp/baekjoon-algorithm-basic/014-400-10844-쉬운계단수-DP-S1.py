n = int(input())

cnt = [1] * 10
cnt[0] = 0
#print(cnt)

for round in range(n-1):
    new_cnt = cnt.copy()
    for i in range(1, 9):
        new_cnt[i] = cnt[i-1] + cnt[i+1]
    new_cnt[0] = cnt[1]
    new_cnt[9] = cnt[8]
    cnt = new_cnt
    #print(cnt)

ans = 0
for i in range(10):
    ans += cnt[i]

print(ans % 1000000000)
