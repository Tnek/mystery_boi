from pwn import *
import base64

# r = remote("rev.chal.csaw.io", 1000)
r = remote("127.0.0.1", 1234)
with open("libfake.so", "r") as FILE:
    f = FILE.read()

b = base64.b64encode(f)
print(r.recvuntil(">>>"))
print(len(b))
r.sendline(str(len(b)))

r.sendline(b)

r.interactive()
