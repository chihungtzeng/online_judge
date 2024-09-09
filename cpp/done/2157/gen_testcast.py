import random
import string

res = []
for _ in range(100):
    s = [random.choice(string.ascii_lowercase) for __ in range(5)]
    s = set(s)
    s = list(s)
    res.append("".join(s))
print(res)
