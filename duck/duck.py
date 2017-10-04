import sys
import math

def log(s):
    print(s, file=sys.stderr)

w, h = [int(i) for i in input().split()]
food = [[int(j) for j in input().split()] for i in range(h)]

if w > h:
    log("Exchange")
    food = [[food[j][i] for j in range(h)] for i in range(w)]
    w,h = h,w

log("w,h = {},{}".format(w,h))
log("food:")
for raw in food:
    log(raw)

log("")

m = [food[-1][-1]]

log(m)
log('First')
for k in range((h-1) + (w-1) - 1, h-2, -1):
    m = [m[0] + food[h-1][k - (h-1)]] + \
        [max(
            m[j - (k - (h-1)) - 1],
            m[j - (k - (h-1))]
        ) + food[k - j][j] for j in range(k - (h-1) + 1, w-1)] + \
        [m[-1] + food[k - (w-1)][w-1]]
    log(m)

log('Second')
for k in range(h-2, w-2, -1):
    m = [max(m[j], m[j+1]) + food[k-j][j] for j in range(0, w-1)] + \
        [m[-1] + food[k - (w-1)][w-1]]
    log(m)

log('Third')
for k in range(w-2, 0, -1):
    m = [max(m[j],m[j+1]) + food[k-j][j] for j in range(0, k+1)]
    log(m)

print(food[0][0] + max(m))
