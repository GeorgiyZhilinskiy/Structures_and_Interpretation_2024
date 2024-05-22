def my_rat(a, b):
    return [a, b]


def add_rat(x, y):
    return my_rat((x[0] * y[1]) + (y[0] * x[1]), x[1] * y[1])


x = my_rat(1, 2)
y = my_rat(3, 4)
print(add_rat(x, y))


# def my_rat1(*args):
#     if len(args) == 2:
#         return [args[0], args[1]]
#     if len(args) == 4:
#         return my_rat1((args[0] * args[3]) + (args[2] * args[1]), args[1] * args[3])
#
#
# print(my_rat1(1, 2, 3, 4))
#
#
# def my_rat1(*args):
#     if len(args) == 2:
#         return [args[0], args[1]]
#     if len(args) == 4:
#         return my_rat1((args[0] * args[3]) + (args[2] * args[1]), args[1] * args[3])
#
#
# def my_rat2(*args):
#     try:
#         a = len(args[1])
#     except:
#         return [args[0], args[1]]
#     return my_rat2((args[0][0] * args[1][1]) + (args[1][0] * args[0][1]), args[0][1] * args[1][1])
#
#
# print(my_rat2(my_rat2(1, 2), my_rat2(3, 4)))
