#!/usr/bin/python3
"""Answer to UTF-8 Validation interview question. See specifics in README.md"""


def validUTF8(data):
    """ Checks if data is valid UTF8 data """

    i = 0
    while i < len(data):

        # If data[i]'s 8th byte is on, evaluate multi-byte character
        if (data[i] >> 7) & 1:

            # Find character byte size
            char_size = 4
            while (data[i] >> char_size) & ((1 << char_size) - 1) == 0:
                char_size -= 1
                # If no legal size, return False
                if char_size == 1:
                    return False

            # If not enough bytes to complete character, return False
            if char_size > len(data) - i:
                return False

            # Check character's other bytes.
            for j in range(i + 1, i + char_size):
                # If 7th byte is 1 or 8th byte is 0, return False
                if (data[j] >> 6) ^ 1 or (data[j] >> 7) & 1:
                    return False
            i += j
        i += 1
    return True
