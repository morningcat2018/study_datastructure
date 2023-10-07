def parent(index: int):
    return int(index / 2)


def left(index: int):
    return int(index * 2)


def right(index: int):
    return int(index * 2 + 1)


class MinHeap(object):

    def __init__(self):
        self.data = []
        self.data.append('\0')
        self.count = 0

    def push(self, item):
        self.count += 1
        self.data.append(item)
        self.__up(self.count)
        return True

    def pop(self):
        assert self.count > 0
        data = self.data[1]
        # swap data[1] data[count]
        self.data[1], self.data[self.count] = self.data[self.count], self.data[1]
        self.count -= 1
        self.__down(1)
        return data

    def __up(self, index: int):
        while index > 1 and self.data[parent(index)] > self.data[index]:
            # swap data[parent(index)] data[index]
            self.data[parent(index)], self.data[index] = (
                self.data[index], self.data[parent(index)])
            index = parent(index)

    def __down(self, index: int):
        while left(index) <= self.count:
            temp = left(index)
            if right(index) <= self.count and self.data[right(index)] < self.data[left(index)]:
                temp = right(index)
            # swap data[temp] data[index]
            self.data[temp], self.data[index] = self.data[index], self.data[temp]
            index = temp

    def is_empty(self):
        return self.count == 0

    def get_min(self):
        assert self.count > 0
        return self.data[1]


if __name__ == '__main__':
    minH = MinHeap()
    minH.push(23)
    minH.push(17)
    minH.push(3)
    minH.push(33)
    minH.push(123)
    while not minH.is_empty():
        print(minH.get_min())
        minH.pop()
