# Interview Prep: Count It!

## Description of Problem

Write a _recursive_ function that queries the Reddit API, parses the title of all hot articles, and prints a sorted count of given keywords (case-insensitive, delimited by spaces).

### Requirements:

* Prototype: `def count_words(subreddit, word_list)`
* If `word_list` contains the same word (case-insensitive), the final count should be the sum of each duplicate
* Results should be printed following these specifications:
    * in descending order, by the count
    * break ties by sorting alphabetically (ascending, from A to Z).
    * Words with no matches should be skipped and not printed.
    * Words must be printed in lowercase.
* Results are based on the number of times a keyword appears, not titles it appears in.
    * Example: `java java java` counts as 3 separate occurrences of `java`.
* To make life easier, `java.` or `java!` or `java_` should not count as `java`
* If no posts match or the subreddit is invalid, print a newline.
* NOTE: Invalid subreddits may return a redirect to search results. Ensure that you are NOT following redirects.

## My Solution 💡

See the [0-count.py](./0-count.py) file.
