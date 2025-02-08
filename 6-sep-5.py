def foo(n, p):
    if n == 0:
        return 0
    K = n % 10
    n = n // 10
    P = p + K + n
    print(f"K = {K}, n = {n}, P = {P}")
    foo(n, P)

foo(3042, 0) 
