import random
import json
from pprint import pprint

n = 0
T = 0
a = []
cleaner = (-1, -1)
dirt = []

def read_courses(filename):
    with open(filename) as data_file:
        data = json.load(data_file)
    pprint(data)
    return data

def read_students(filename):
    with open(filename) as data_file:
        data = json.load(data_file)
    pprint(data)
    return data

def get_dist(p1, p2):
    return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1])

courses = read_courses("courses")
students = read_students("students")

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
        for item in data:
            data[item] = data[item]['day'] = random.randint(0, 5)
            data[item] = data[item]['time'] = random.randint(0, 8)

        pop.append(list(data))
    return pop


def fitness(data):
    fitness = 0
    global students
    for student in students:
        classes = studetnts[student]["classes"]
        schedule = []*7
        for CLASS in classes:
            c = classes[CLASS]
            schedule[c['day']].append((c["time"], CLASS))
            for i in range(7):
                day = [0]*24
                mi = 24
                ma = 0
                for item in range(schedule[i]):
                    for j in range(item[0], item[0] + classes[item[1]]['duration'] + 1):
                        day[j] += 1
                        mi = min(mi, j)
                        ma = max(ma, j)
                if (mi > ma):
                    continue
                for i in range(mi, ma + 1):
                    if (day[i] == 0):
                        fitness +=  10
                    else:
                        fitness += 1000 * (day[i] - 1)
    return fitness

def mutate(data):
    mutation_chance = 10
    new_data = list(data)
    for i in range(len(data)):
        if (int(random.random()*mutation_chance) == 1):
            p1 = random.randint(0, len(data) - 1)
            new_data[i], new_data[p1] = new_data[p1], new_data[i]
    return new_data

def crossover(ind1, ind2):
    pos = int(random.random()*len(ind1))
    return (ind1[:pos]+ind2[pos:], ind2[:pos]+ind1[pos:])


population = random_population(classes)
print(population)
exit()
fitnesses = [(0, 0)]

for gen in range(GENERATIONS):
    weighted_population = []

    for individual in population:
        fitness_val = fitness(individual)
        pair = (individual, fitness_val)

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

