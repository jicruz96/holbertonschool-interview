#!/usr/bin/python3
""" See README.md for a description of this task """

from requests import get


def count_words(subreddit, word_list):
    """Counts the number of occurences of a word in word_list in the titles of
    the hot posts of a subreddit and prints the results.

    Words with no occurences are not printed and duplicate words are printed
    once with its count multiplied by the number of duplicates.

    Args:
        subreddit (str): subreddit to find posts for
        word_list (List[str]): words to count
    """

    def to_word_dict(word_list):
        """Creates a word count dictionary for words in word_list.

        Args:
            word_list (list[str]): words to add to word count dictionary

        Returns:
            dict[str]: Word dictionary. Each word's value is a dict[str, str]
                    with keys 'weight' and 'count'. 'weight' is the number of
                    times the word appeared in word_list; 'count' will be the
                    word count later on.
        """
        word_dict = {}
        for word in word_list:
            word = word.lower()
            if word in word_dict:
                word_dict[word]['weight'] += 1
            else:
                word_dict[word] = {'weight': 1, 'count': 0}
        return word_dict

    def request_and_count(url, word_dict, after=None):
        """Requests Hot posts from a subreddit as JSON data, finds all post
        titles and counts all occurences of words in word_dict.

        Args:
            url (str): URL to request
            word_dict (dict[str]): Word dictionary. Each word's value is a
                                   dict[str, str] (keys 'weight' and 'count').
                                   This function updates the 'count' attribute.
            after (str, optional): request query parameter. Defaults to None.
                                   This function returns when the request to
                                   URL returns a None value for after.

        Returns:
            word_dict (dict[str]): Same arg, just updated.
        """

        query = url
        if after is not None:
            query += '&after=' + after

        response = get(
            query,
            allow_redirects=False,
            headers={'User-agent': ''}
        )

        if response.status_code != 200:
            return None

        data = response.json()['data']
        for post in data['children']:
            for word in post['data']['title'].lower().split():
                if word in word_dict:
                    word_dict[word]['count'] += 1

        if data['after'] is None:
            return word_dict

        return request_and_count(url, word_dict, data['after'])

    def to_word_count_list(word_dict):
        """Creates a sorted list of tuples (word, word count) using word_dict
        as its source.

        Args:
            word_dict (dict[str]): Word dictionary. Each word's value is a
                                   dict[str, str] (keys 'weight' and 'count')

        Returns:
            list[tuple[str, int]]: sorted list of tuples (word, count)
        """

        if word_dict is None:
            return None

        res = []
        for word in word_dict:
            count = word_dict[word]['count'] * word_dict[word]['weight']
            if count == 0:
                continue
            i = 0
            while i < len(res) and res[i][1] >= count:
                if res[i][1] == count and res[i][0] > word:
                    break
                i += 1
            res.insert(i, (word, count))

        return res

    def print_words_and_counts(word_count_list):
        """prints out a list of word counts

        Args:
            word_count_list (list[tuple[str, int]]): list of (word, count)'s
        """

        if word_count_list is None:
            print('')
            return

        for word, count in word_count_list:
            print('{}: {}'.format(word, count))

    URL = 'https://www.reddit.com/r/{}/hot/.json?count=1000'.format(subreddit)
    word_dict = request_and_count(URL, to_word_dict(word_list))
    word_count_list = to_word_count_list(word_dict)
    print_words_and_counts(word_count_list)
