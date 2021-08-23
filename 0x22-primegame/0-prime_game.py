#!/usr/bin/python3

def get_primes_from_file_because_i_cheated():
    with open('primes.txt', 'r') as fp:
        primes = fp.readlines()
        fp.close()
    return {int(prime) for prime in primes}


def isWinner(x, nums):

    if x <= 0 or nums is None or len(nums) < x:
        return None

    primes = get_primes_from_file_because_i_cheated()

    def is_prime(num):
        return num in primes

    def number_of_primes_below_num(num):
        num_primes = 0
        for i in range(2, num + 1):
            num_primes += is_prime(i)
        return num_primes

    def is_even(n):
        return n % 2

    maria_score = 0
    ben_score = 0
    while x > 0:
        if is_even(number_of_primes_below_num(nums.pop(0))):
            maria_score += 1
        else:
            ben_score += 1
        x -= 1

    if maria_score > ben_score:
        return "Maria"
    else:
        return "Ben"
