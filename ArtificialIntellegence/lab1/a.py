from Country import City
from queue import PriorityQueue

cities = []
n, m = 0, 0
name_map = {}
g = []

def readData(fname):
    f = open(fname, "r")
    global n, m, g
    n, m = list(map(int, f.readline().split()))
    g = [[] for x in range(n)]
    for i in range(n):
        name, x, y = f.readline().split()
        name_map[name] = i
        cities.append(City(name, x, y))

    for i in range(m):
        cities_from, cities_to, d = f.readline().split()
        d = int(d)
        cities_from = name_map[cities_from]
        cities_to = name_map[cities_to]
        g[cities_from].append((cities_to, d))
        g[cities_to].append((cities_from, d))


def astar(cities, g, S, F):
    n = len(cities)
    frontier = PriorityQueue()
    frontier.put(S, 0)
    came_from = {}
    cost_so_far = {}
    came_from[S] = None
    cost_so_far[S] = 0

    while not frontier.empty():
        current = frontier.get()
        for next in g[current]:
            to, cost = next
            new_cost = cost_so_far[current] + cost
            if (to not in cost_so_far or new_cost < cost_so_far[to]):
                cost_so_far[to] = new_cost
                priority = new_cost + City.heuristic(cities[current], cities[to])
                frontier.put(to, priority)
                came_from[to] = current
                cities[to].H = priority
                cities[to].G = new_cost
                cities[to].F = priority + new_cost

    return cities
readData("data.txt")
result = astar(cities, g, 0, n - 1)
for c in result:
    print(c.name, c.G, c.H, c.F)




