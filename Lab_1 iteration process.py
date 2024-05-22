def ex_sq_iter(n, result):
    if n == 0:
        return result
    else:
        return ex_sq_iter(n - 1, result * 2)


def ex_sq(n):
    return ex_sq_iter(n, 1)


print(ex_sq(4))

