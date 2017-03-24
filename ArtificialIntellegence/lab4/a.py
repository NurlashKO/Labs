import random

n = 0
T = 0
a = []
cleaner = (-1, -1)
dirt = []

def read_data(filename):
    f = open(filename, "r");
    global n, T, a
    n, T = map(int, f.readline().split())
    for i in range(n):
        a.append(f.readline().strip());

def get_dist(p1, p2):
    return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1])

#read_data("in")

n = 30
T = 300
a = [['.']*n for x in range(n)]
for i in range(n):
    a[i][0] = a[0][i] = a[i][n - 1] = a[n - 1][i] = 'X';
for i in range(100):
    x = random.randint(1, n - 2)
    y = random.randint(1, n - 2)
    a[x][y] = 'X'

for i in range(300):
    x = random.randint(1, n - 2)
    y = random.randint(1, n - 2)
    a[x][y] = '*'

a[n//2][n//2] = 'A'

for i in range(n):
    for j in range(n):
        if (a[i][j] == 'A'):
            cleaner = (i, j)
        if (a[i][j] == '*'):
            dirt.append((i, j))

POP_SIZE = 50
GENERATIONS = 1000
SOL_SIZE = len(dirt)

def weighted_choice(items):
    weight_total = sum((item[1] for item in items))
    n = random.uniform(0, weight_total)
    for item, weight in items:
        if n < weight:
            return item
        n = n - weight
    return item

def random_population(data):
    pop = []
    for i in range(POP_SIZE):
        random.shuffle(data)
        pop.append(list(data))
    return pop


def fitness(data):
    global T, cleaner
    last = cleaner
    fitness = 0
    dist = 0
    for point in data:
        dist += get_dist(last, point)
        if (dist > T):
            break
        fitness += 1
        last = point
    return fitness

def mutate(data):
    mutation_chance = 10
    new_data =list(data)
    for i in range(len(data)):
        if (int(random.random()*mutation_chance) == 1):
            p1 = random.randint(0, len(data) - 1)
            new_data[i], new_data[p1] = new_data[p1], new_data[i]
    return new_data

def crossover(ind1, ind2):
    pos = int(random.random()*len(ind1))
    return (ind1[:pos]+ind2[pos:], ind2[:pos]+ind1[pos:])


population = random_population(dirt)
fitnesses = [(0, 0)]

for gen in range(GENERATIONS):
    weighted_population = []

    for individual in population:
        fitness_val = fitness(individual)
        pair = (individual, fitness_val/(len(dirt)))

        weighted_population.append(pair)

    population = []

    for _ in range(POP_SIZE//2):
        ind1 = weighted_choice(weighted_population)
        ind2 = weighted_choice(weighted_population)

        # Crossover
        #ind1, ind2 = crossover(ind1, ind2)

        population.append(mutate(ind1))
        population.append(mutate(ind2))

    fittest_path = population[0]
    max_fitness = fitness(fittest_path)

    for individual in population:
        fit_path = fitness(individual)
        if (fit_path > max_fitness):
            fittest_path = individual
            max_fitness = fit_path

    if max_fitness > fitnesses[-1][0]:
        fitnesses.append((max_fitness, gen))

for f, g in fitnesses:
    print("Generation: ", g)
    print("Fitness: ", f)

