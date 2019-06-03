#include <stdio.h>

int main() {
    int cookie = 0x274adc8a;
    int cnt = 5;
    srandom(cookie);
    int cookie_tweak = (random() & 0x0FF0) + 0x100;
    int *offsets = (int *) calloc(cnt, sizeof(int));
    offsets[0] = 0;
    for (int i = 1; i < cnt; i++) {
        offsets[i] = 128 - (random() & 0xF0);
        printf("offset%d: %d\n", i, offsets[i]);
    }
}
