import random

# Converts a 6-bit binary string to integer (x in range [0, 31])
def binary_to_int(binary_str):
    return int(binary_str, 2)

# Fitness function: f(x) = 2x² - 1
def fitness(binary_str):
    x = binary_to_int(binary_str)
    return 2 * (x ** 2) - 1

# Generate random 6-bit binary string
def random_individual():
    return ''.join(random.choice('01') for _ in range(6))

# Generate initial population
def generate_population(size=10):
    return [random_individual() for _ in range(size)]

# Tournament Selection: Pick best individual from k random choices
def tournament_selection(population, k=3):
    selected = random.sample(population, k)
    return max(selected, key=fitness)

# Uniform Crossover: Mix genes randomly from both parents
def uniform_crossover(parent1, parent2):
    child = ''.join(random.choice([p1, p2]) for p1, p2 in zip(parent1, parent2))
    return child

# Adaptive Mutation: Adjust mutation rate based on generation count
def adaptive_mutation(individual, generation, max_generations):
    mutation_prob = 0.1 * (1 - generation / max_generations)  # Higher mutation early on
    mutated = ''.join(
        str(1 - int(bit)) if random.random() < mutation_prob else bit
        for bit in individual
    )
    return mutated

# Genetic Algorithm Execution
def genetic_algorithm(pop_size=10, generations=50):
    population = generate_population(pop_size)

    for generation in range(generations):
        # Evaluate fitness for all individuals
        population = sorted(population, key=fitness, reverse=True)

        # Select top 50% for breeding
        parents = [tournament_selection(population) for _ in range(pop_size // 2)]

        # Generate new population using crossover and mutation
        new_population = []
        for _ in range(pop_size // 2):
            parent1, parent2 = random.sample(parents, 2)
            child = uniform_crossover(parent1, parent2)
            child = adaptive_mutation(child, generation, generations)
            new_population.append(child)

        population = parents + new_population  # Replace old population

        # Print best solution in current generation
        best_individual = max(population, key=fitness)
        print(f"Generation {generation + 1}, Best x: {binary_to_int(best_individual)}, Fitness: {fitness(best_individual)}")

    return max(population, key=fitness)  # Return best individual

# Run Genetic Algorithm
best_solution = genetic_algorithm()
print("\nBest solution found:", best_solution)
print("Best x:", binary_to_int(best_solution))
print("Best fitness:", fitness(best_solution))
