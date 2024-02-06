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
        self.capacity = 1

    def push(self, item):
        self.count += 1
        if self.count < self.capacity:
            self.data[self.count] = item
        else:
            self.data.append(item)
            self.capacity += 1
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


class KHeap(MinHeap):

    def __init__(self, k):
        super().__init__()
        self.limit_count = k
    
    def push(self, item):
        if self.count < self.limit_count:
            super().push(item)
            return 
        if super().get_min() < item:
            super().pop()
            super().push(item)
    
    def pop(self):
        raise Exception("Unsupported operation")


def test_MinHeap():
    minH = MinHeap()
    minH.push(23)
    minH.push(17)
    minH.push(3)
    minH.push(33)
    minH.push(123)
    minH.pop()
    minH.push(1024)
    while not minH.is_empty():
        print(minH.get_min())
        minH.pop()


def test_KHeap():
    heap = KHeap(3)
    heap.push(23)
    heap.push(17)
    heap.push(3)
    heap.push(33)
    heap.push(123)
    heap.push(1024)
    print(heap.get_min())


if __name__ == '__main__':
    test_MinHeap()
    print("*" * 30)
    test_KHeap()