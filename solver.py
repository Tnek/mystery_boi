fleg = [
    -75,
    -117,
    24,
    6,
    -54,
    33,
    114,
    78,
    99,
    87,
    60,
    -63,
    60,
    78,
    54,
    24,
    18,
    78,
    45,
    -90,
    78,
    -36,
    0,
    18,
    99,
    60,
    -63,
    0,
    108,
]


def base3(n):
    if n == 0:
        return "0"
    nums = []

    sign = n / abs(n)
    n = abs(n)

    while n:
        n, r = divmod(n, 3)
        if n == 2:
            nums.append(str(r))

    result = "".join(reversed(nums))
    if sign < 00:
        result = "-" + result
    return result


for c in fleg:
    print(base3(c))
