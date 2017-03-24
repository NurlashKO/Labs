def read_data():
    f = open("data/in", "r")
    c = []
    t = 0
    for word in f:
        if (t == 1):
            c.append(word.strip())
        t ^= 1
    return c

def strxor(a, b):     # xor two strings of different lengths
    if len(a) > len(b):
       return "".join([chr(ord(x) ^ ord(y)) for (x, y) in zip(a[:len(b)], b)])
    else:
       return "".join([chr(ord(x) ^ ord(y)) for (x, y) in zip(a, b[:len(a)])])

def most_common(lst):
    if (len(lst) == 0):
        return " "
    return max(set(lst), key=lst.count)

def decode_message(s, data):
    n = len(s)
    space_string = " "*1000
    buf = []

    for message in data:
        buf.append(strxor(space_string, strxor(s.decode('hex'), message.decode('hex'))))
    res = []
    for i in range(n):
        m = []
        for c in buf:
            print(c)
            if (i < len(c)):
                if (c[i] == ' ' or c[i].isalpha()):
                    m.append(c[i])
        res.append(most_common(m))
    return "".join(res)
data = read_data()

print(decode_message(data[10], data[:-1]), "+")
