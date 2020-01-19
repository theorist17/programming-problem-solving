from collections import deque
#tempcmd = deque(input().split('\n')); input = tempcmd.popleft

n = int(input())
m = int(input())

INF = 2**32 - 1

G = [[] for r in range(n + 1)]
L = [0] * (n + 1)
for i in range(m):
    p, q, r = map(int, input().split())
    G[p].append((q, r))
    L[q] += 1
L[1] = 1

M = [0] * (n + 1)
P = [0] * (n + 1)

Q = deque()
Q.append((0, 1, 0))

while Q:
    prev, curr, dist = Q.popleft()
    if M[curr] < dist:
        M[curr] = dist
        P[curr] = prev
    L[curr] -= 1

    if L[curr] == 0:
        for next, wght in G[curr]:
            Q.append((curr, next, M[curr] + wght))

print(M[1])

S = deque()
top = P[1]
S.append(top)
while top != 1:
    top = P[top]
    S.append(top)
while S:
    print(S.pop(), end=' ')
print(1)