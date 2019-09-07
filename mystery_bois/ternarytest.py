import random
def fuck(n):
    add = 0
    while add == 0:
        add = random.randint(-n, n)

    result = n - add

    if add < 0:
        op = '+'
        add = abs(add)
    else:
        op = '-'
    
    mul = random.randint(1, 20)
    result *= mul

    prog = '%d == (inp %s %d) / %d)' %(result, op, add, mul)
    return prog
#print(len(flag)) #f = map(ord, flag) # #fucked_up_conds = map(fuck, f) #print(fucked_up_conds) a = "flag{jk_there_was_no_mystery}" print(len(a))

a = "flag{jk_there_was_no_mystery}"
print(len(a))
a = map(ord, a)

def base3 (n):
    if n == 0:
        return '0'
    nums = []

    while n:
        n, r = divmod(n, 3)
        nums.append(str(r))

    return ''.join(reversed(nums))

built_eqs = []
totals = []
for i in a:
    gen = []
    b3i = base3(i)
    total = 0

    for n in range(len(b3i)):
        val = int(b3i[n]) - 1
        total += val*(3**n)

    built_eq = " + ".join(gen)
    totals.append(total)

print(totals)
