n = int(input())

inf = 2 ** 32 - 1
d = [[inf] * (n + 1) for x in range(n + 1)]
for k in range(1, n + 1):
    d[k][k] = 0

m = int(input())

for i in range(m):
    f, t = map(int, input().split())
    d[f][t] = 1
    d[t][f] = 1

def dfs(v, mem):
    if visited[v]:
        return
    visited[v] = True
    mem.add(v)
    for i in range(1, n + 1):
        if d[v][i] != inf and d[v][i] != 0:
            dfs(i, mem)

visited = [False] * (n + 1)
council = list()
for i in range(1, n + 1):
    if not visited[i]:
        mem = set()
        dfs(i, mem)
        council.append(mem)

ans = list()
root = list(range(n + 1))
for member in council:
    for k in member:
        for r in member:
            for c in member:
                d[r][c] = min(d[r][c], d[r][k] + d[k][c])
    #import numpy as np ; print(np.matrix(d))

    minv = inf
    idx = -1
    for r in member:
        maxv = -1
        for c in member:
            if maxv < d[r][c]:
                maxv = d[r][c]
        if maxv < minv:
            minv = maxv
            idx = r
        #print('maxv', maxv, 'idx', idx)
    ans.append(idx)

ans.sort()
print(len(ans))
for a in ans:
    print(a)