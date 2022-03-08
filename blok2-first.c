#include <stdio.h>

void main() {
	short int a = 5, b = 6, c;

	__asm{
		mov ax,a
		mov bx,b
		add ax,bx
		mov c,ax
	}

	printf("c = %d", c);
}
