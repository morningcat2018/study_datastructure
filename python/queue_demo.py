import queue

task_q  = queue.Queue(maxsize=0)

def add_data(data_list=None):
    global task_q
    if data_list!=None:
        for data in data_list:
            task_q.put(data)

# python3 queue_demo.py
if __name__ == "__main__":
    l = [1,2,3,4,5,6,7]
    add_data(l)
    print("size =",task_q.qsize())

    # 不弹出数据遍历
    for i in range(task_q.qsize()):
        print(task_q.queue[i])
    print("size =",task_q.qsize())

    # 弹出数据遍历
    while not task_q.empty():
        print(task_q.get())
    print("size=",task_q.qsize())

    # 清除数据
    add_data([2,3,4])
    task_q.queue.clear()
    print("size=",task_q.qsize())