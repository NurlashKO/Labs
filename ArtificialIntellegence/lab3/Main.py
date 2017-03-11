from queue import PriorityQueue

cities = []
n, m = 0, 0
d = []
dir = [(1, 0), (-1, 0), (0, 1), (0, -1)]

def readData(fname):
    f = open(fname, "r")
    global n, m, d
    n, m = map(int, f.readline().split())
    for i in range(n):
        d.append(f.readline())

def heuristic_euq(a, b):
    return ((a[0] - b[0])**2 + (a[1] - b[1])**2)**0.5

def heuristic_manh(a, b):
    return (abs(a[0] - b[0]) + abs(a[1] - b[1]))

def heuristic_bfs(a, b):
    return 0

def astar(S, F, heuristic):
    global n, m
    frontier = PriorityQueue()
    frontier.put((1, S))
    came_from = {}
    cost_so_far = {}
    came_from[S] = None
    cost_so_far[S] = 1
    cnt = 0
    while not frontier.empty():
        buf, current = frontier.get()
        if current == F:
            break
        for dx, dy in dir:
            to = (current[0] + dx, current[1] + dy)
            if ((not to[0] in range(n)) or (not to[1] in range(m))):
                continue;
            if (d[to[0]][to[1]] == '1'):
                continue;
            new_cost = cost_so_far[current] + 1
            if (to not in cost_so_far or new_cost < cost_so_far[to]):
                cost_so_far[to] = new_cost
                cnt += 1
                priority = new_cost + heuristic(to, F)
                frontier.put((priority, to))
                came_from[to] = current

    return (cnt, came_from)
readData("map.txt")
S = (1, 1)
F = (50, 50)

def back(pos, came_from):
    if not pos in came_from:
        return
    back(came_from[pos], came_from)
    print(pos[0], pos[1])

cnt, came_from = astar(S, F, heuristic_euq)
print("Number of pops from queue", cnt)
back(F, came_from)

cnt, came_from = astar(S, F, heuristic_manh)
print("Number of pops from queue", cnt)
back(F, came_from)

cnt, came_from = astar(S, F, heuristic_bfs)
print("Number of pops from queue", cnt)
back(F, came_from)
