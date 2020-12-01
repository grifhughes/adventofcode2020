from typing import Set
import random

# setup
def get_input_set(filename: str) -> Set[int]:
    with open(filename) as inputs:
        input_set = set(int(input) for input in inputs)
    return input_set

input_set = get_input_set("inputs.txt")
target = 2020
tup = tuple(input_set)

# part 1
for input in input_set:
    diff = target - input
    if diff in input_set:
        print(diff * input)
        break

# part 2 :)
while True:
    a = random.choice(tup)
    b = random.choice(tup)
    c = random.choice(tup)
    sum = a + b + c
    if sum == target:
        print(a * b * c)
        break
