import random
import numpy as np

# Define the number of cities
NUM_CITIES = 10

# Generate random coordinates for 10 cities
city_positions = {i: (random.randint(0, 100), random.randint(0, 100)) for i in range(NUM_CITIES)}

# Function to calculate Euclidean distance between two cities
def distance(city1, city2):
    x1, y1 = city_positions[city1]
    x2, y2 = city_positions[city2]
    return np.sqrt((x2 - x1) ** 2 + (y2 - y1) ** 2)

# Function to calculate total tour distance
def total_distance(route):
    return sum(distance(route[i], route[i + 1]) for i in range(len(route) - 1)) + distance(route[-1], route[0])

# Generate a random individual (route)
def create_random_individual():
    route = list(range(NUM_CITIES))
    random.shuffle(route)
    return route

# Generate initial population
def generate_population(size=100):
    return [create_random_individual() for _ in range(size)]

# Tournament Selection: Pick k random individuals and select the best
def tournament_selection(population, k=5):
    selected = random.sample(population, k)
    return min(selected, key=total_distance)  # Lower distance is better

# Order Crossover (OX)
def order_crossover(parent1, parent2):
    size = len(parent1)
    start, end = sorted(random.sample(range(size), 2))
    
    child = [None] * size
    child[start:end] = parent1[start:end]

    remaining = [gene for gene in parent2 if gene not in child]
    idx = 0

    for i in range(size):
        if child[i] is None:
            child[i] = remaining[idx]
            idx += 1

    return child

# Swap Mutation
def swap_mutation(individual):
    idx1, idx2 = random.sample(range(len(individual)), 2)
    individual[idx1], individual[idx2] = individual[idx2], individual[idx1]
    return individual

# Genetic Algorithm
def genetic_algorithm(pop_size=100, generations=500, mutation_rate=0.1):
    population = generate_population(pop_size)

    for generation in range(generations):
        # Evaluate fitness (lower distance is better)
        population = sorted(population, key=total_distance)
        best_fitness = total_distance(population[0])

        print(f"Generation {generation + 1}, Best Distance: {best_fitness}")

        # Select parents
        parents = [tournament_selection(population) for _ in range(pop_size // 2)]

        # Generate new population using crossover
        new_population = []
        for _ in range(pop_size // 2):
            parent1, parent2 = random.sample(parents, 2)
            child = order_crossover(parent1, parent2)

            # Apply mutation
            if random.random() < mutation_rate:
                child = swap_mutation(child)

            new_population.append(child)

        # Keep the best individuals (Elitism)
        population = parents + new_population  

    best_solution = min(population, key=total_distance)
    return best_solution, total_distance(best_solution)

# Run Genetic Algorithm for TSP
best_route, best_distance = genetic_algorithm()

# Print the best solution found
print("\nBest Route:", best_route)
print("Best Distance:", best_distance)
