
print(len("If qualified opinions incline to believe in the exponential conjecture, then I think we cannot afford not to make use of it."))
print(len("The significance of this general conjecture, assuming its truth, is easy to see. It means that it may be feasible to design ciphers that are effectively unbreakable."))
print(len("In this letter I make some remarks on a general principle relevant to enciphering in general and my machine."))

def strxor(a, b):     # xor two strings of different lengths
    if len(a) > len(b):
       return "".join([chr(ord(x) ^ ord(y)) for (x, y) in zip(a[:len(b)], b)])
    else:
       return "".join([chr(ord(x) ^ ord(y)) for (x, y) in zip(a, b[:len(a)])])

k1 = "140b41b22a29beb4061bda66b6747e14"
m1 = "4ca00ff4c898d61e1edbf1800618fb2828a226d160dad07883d04e008a7897ee2e4b7465d5290d0c0e6c6822236e1daafb94ffe0c5da05d9476be028ad7c1d81"

def dCBC(m, k):
    blockSize = len(k)
    k = k.decode('hex')
    mBlock = [m[i:i+(blockSize)].decode('hex') for i in range(0, len(m), (blockSize))]
    iv =  mBlock.pop(0)
    print(mBlock[0].encode('hex'), "^")
    print(strxor(strxor(iv, k), mBlock[0]))

dCBC(m1, k1)
