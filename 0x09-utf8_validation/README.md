# Interview Prep: UTF8 Data Validation

## Description of Problem

Write a method that determines if a given data set represents a valid UTF-8 encoding.

* The data will be represented by a list of integers
* Each integer represents 1 byte of data, therefore you only need to handle the 8 least significant bits of each integer


## Proposed Solution 💡

### 21 february 2021

My solution scans through the data set one integer at a time.

If an integer's 8th byte is 1, then we're dealing with a multi-byte character:
	We first figure out how many bytes the multi-byte character is, then make sure all those bytes follow the UTF8 pattern. 
	If any of these are true, we return `False`:
		- we cannot figure out how many bytes the multi-byte character is,
		- there aren't enough bytes left to complete the multi-byte character,
		- or the characters' bytes don't follow the unicode standard

If we make it through the entire list, we return True.
	 


```python
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
```
