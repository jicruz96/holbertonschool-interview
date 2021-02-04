#!/usr/bin/python3
"""
Solution to the Log Parsing interview question. See `README.md` for description
"""

from sys import stdin
from string import Template
import signal
import re


class Log_Parser:
    """
    Parses standard input for lines that match a specific pattern:
        * <IP> - [<date>] "<request-type>" <status-code> <file-size>

    where <request-type> and a list of valid integers for <status-code> are
    inputted during instantiation.
    """

    def __init__(self, request, status_codes, print_frequency=10):
        """
        creates new instance of Log_Parser.

        Args:
            * request            (str): type of request to track
            * status_codes (list[int]): valid codes to track
            * print_frequency    (int): number of lines to read between prints

        Attributes:
            * total_size         (int): total size of all file sizes parsed
            * status_codes (dict(int: int)): frequency table for status codes
            * Pattern_Matcher    (re.Pattern obj): validates user input
        """
        # signal.signal(signal.SIGINT, self.sigint_handler)
        self.total_size = 0
        self.status_codes = {code: 0 for code in status_codes}
        self.print_frequency = print_frequency
        self.Pattern_Matcher = self.get_Pattern_Matcher(request)

        self.run()

    # def sigint_handler(self, signum, frame):
    #     """
    #     prints stats if a Keyboard Interruption (CTRL + C) occurs
    #     """
    #     self.print_stats()
    #     exit(0)

    def get_Pattern_Matcher(self, request):
        """
        Returns a Pattern object (from re module). Used to validate input lines
        """

        # This is the string pattern we want to match.
        template = r'^$ip - \[$date] "$request" $status_code $file_size\n'

        # re_8bit is a regex pattern that matches numbers between 1-255.
        # We use this value to build our regex pattern for an IP address
        re_8bit = r'\b(1\d\d|[1-9]\d?|2([0-4]\d|5[0-5]))\b'

        # These regular expressions complete the template string
        re_dict = {

            'ip': r'{0}\.{0}\.{0}\.{0}'.format(re_8bit),
            'date': r'\b\d{4}(-\d{2}){2} \d{2}(:\d{2}){2}\.\d{6}\b',

            # Escape characters from request string as needed
            'request': re.escape(request),

            # Include a regex group name to extract values from matched lines
            'status_code': r'(?P<status_code>\b\d{3}\b)',
            'file_size': r'(?P<file_size>\b\d+\b)'
        }

        # Create a pattern matcher for template string with all values sub'd
        return re.compile(Template(template).substitute(re_dict))

    def run(self):
        """
        Reads input line-by-line. If input matches pattern, then status
        code and file size are logged
        """
        count = 0
        for line in stdin:
            count += 1
            match = self.Pattern_Matcher.fullmatch(line)
            if match:
                self.total_size += int(match.group('file_size'))
                status_code = int(match.group('status_code'))
                if status_code in self.status_codes.keys():
                    self.status_codes[status_code] += 1
            if count == self.print_frequency:
                count = 0
                self.print_stats()
        self.print_stats()
        return (0)

    def print_stats(self):
        """
        prints status code frequency table and total file sizes for all
        evaluated lines
        """
        print('File size: {}'.format(self.total_size))
        for status_code, frequency in sorted(self.status_codes.items()):
            if frequency:
                print('{}: {}'.format(status_code, frequency))


if __name__ == '__main__':
    request = "GET /projects/260 HTTP/1.1"
    status_codes = [200, 301, 400, 401, 403, 404, 405, 500]
    Log_Parser(request, status_codes)
