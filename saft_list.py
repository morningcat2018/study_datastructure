import threading

class SafeList(list):
    def __init__(self, count=4, init_value=0):
        self.lock = threading.Lock()
        self.list = list([])
        for i in range(count):
            self.list.append(init_value)

    def __getitem__(self, index):
        with self.lock:
            return self.list[index]

    def __setitem__(self, index, value):
        with self.lock:
            self.list[index] = value

    def append(self, value):
        with self.lock:
            self.list.append(value)

# sl = list([0])
sl = SafeList()

def tag():
    sl[0] +=1

if __name__ == '__main__':
    # threads = [threading.Thread(target=tag) for i in range(10000)]
    # for t in threads:
    #     t.start()
    # for t in threads:
    #     t.join()
    # print(sl[0])
    my_list = []
    def add_to_list():
        for i in range(100000):
            my_list.append(i)
    threads = []
    for i in range(10):
        t = threading.Thread(target=add_to_list)
        threads.append(t)
        t.start()
    for t in threads:
        t.join()
    print(len(my_list))
