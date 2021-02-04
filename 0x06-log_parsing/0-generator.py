#!/usr/bin/python3
import random
import sys
from time import sleep
import datetime

str = "{:d}.{:d}.{:d}.{:d} - [{}] \"GET /projects/260 HTTP/1.1\" {} {}\n"
for i in range(10000):
    sleep(random.random() * 0.1)
    sys.stdout.write(str.format(
        random.randint(1, 255), random.randint(1, 255),
        random.randint(1, 255), random.randint(1, 255),
        datetime.datetime.now(),
        random.choice([200, 301, 400, 401, 403, 404, 405, 500]),
        random.randint(1, 1024)
    ))
    sys.stdout.flush()
