def fun1(f1, f2):
    def fun(q, h, ro, p, p_n):
        if p_n is None:
            return f1(q, h, ro, p)
        else:
            return f2(q, h, ro, p, p_n, f1)
    return fun


def ef(q, h, ro, p):
    return (9.81 * ro * q * h) / (p * 1000)


def pN(q, h, ro, p, p_n, f1):
    print("pN\n")
    return (9.81 * ro * q * h) / (p_n * 1000 * f1(q, h, ro, p))


print(fun1(ef, pN)(12, 12, 3, 5, 12))
