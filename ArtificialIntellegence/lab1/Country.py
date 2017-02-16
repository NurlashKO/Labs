from math import sqrt
class City:
    def __init__(self, name, x, y):
        self.name = name
        self.x = int(x)
        self.y = int(y)
        self.H = 0
        self.G = 0
        self.F = 0

    @staticmethod
    def heuristic(a, b):
        return sqrt((a.x - b.x)**2 + (a.y - b.y)**2)
