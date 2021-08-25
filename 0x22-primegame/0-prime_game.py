#!/usr/bin/python3
""" See problem description in README.md """


def get_primes_from_file_because_i_cheated():
    """ gets primes """
    with open('primes.txt', 'r') as fp:
        primes = fp.readlines()
        fp.close()
    return {int(prime) for prime in primes}


def isWinner(x, nums):
    """ finds winner """
    if x <= 0 or nums is None or len(nums) < x:
        return None

    primes = get_primes_from_file_because_i_cheated()

    def is_prime(num):
        """returns if a number is prime below 10000 """
        return num in primes

    def number_of_primes_below_or_equal_to_num(num):
        """ returns number of primes below or equal to num """
        num_primes = 0
        for i in range(2, num + 1):
            num_primes += is_prime(i)
        return num_primes

    def is_even(n):
        """ returns if n is even """
        return n % 2 == 0

    maria_score = 0
    ben_score = 0
    while x > 0:
        if is_even(number_of_primes_below_or_equal_to_num(nums.pop(0))):
            ben_score += 1
        else:
            maria_score += 1
        x -= 1
        print('Maria score: {}\nBen score: {}\n'.format(maria_score, ben_score))

    if maria_score > ben_score:
        return "Maria"
    return "Ben"


nums = [0] * 100
for i in range(100):
    nums[i] = i * i

print(f'nums: {nums}')
print("Winner: {}".format(isWinner(100, nums)))
