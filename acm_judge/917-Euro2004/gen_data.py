#!/usr/bin/python

from __future__ import print_function
import random
import string

NUM_TEAMS = 10
NUM_GAMES = 20
NUM_CASES = 10

def gen_one_random_name():
    length = random.choice(range(4, 21))
    return ''.join(random.choice(string.ascii_lowercase) for _ in range(length))

def gen_team_names():
    return [gen_one_random_name() for _ in range(NUM_TEAMS)]

def gen_test_cases():
    print(NUM_GAMES)
    games = 0
    team_names = gen_team_names()
    while games < NUM_GAMES:
        one = random.choice(team_names)
        two = random.choice(team_names)
        if one != two:
            score1 = random.choice(string.digits)
            score2 = random.choice(string.digits)
            print(one + " " + two + " " + score1 + " " + score2)
            games += 1

def main():
    print(NUM_CASES)
    for _ in range(NUM_CASES):
        gen_test_cases()

if __name__ == "__main__":
    main()
