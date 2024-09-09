call=["FreqStack", "push", "push", "push", "push", "push", "push", "pop", "pop", "pop", "pop"]
args=[[], [5], [7], [5], [7], [4], [5], [], [], [], []]
ret=[None, None, None, None, None, None, None, 5, 7, 5, 4]


call=["FreqStack","push","push","push","push","push","push","pop","push","pop","push","pop","push","pop","push","pop","pop","pop","pop","pop","pop"]
args=[[],[4],[0],[9],[3],[4],[2],[],[6],[],[1],[],[1],[],[4],[],[],[],[],[],[]]

for i in range(len(call)):
    op = call[i]
    if op == "push":
        print(f"obj->{call[i]}({args[i][0]});")
    if op == "pop":
        print(f"EXPECT_EQ(obj->pop(), 0);")
