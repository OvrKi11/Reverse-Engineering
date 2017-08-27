#include <stdio.h>
int main()
{
	int PEB;
	int LDR;
	int LIST;
	int NTDLL;
	__asm
	{
		xor ebx, ebx //ensure ebx is clear
		mov ebx, fs:[0x30] // get PEB
		mov PEB, ebx
		mov ebx, [ebx + 0x0c] // get LDR
		mov LDR, ebx
		mov ebx, [ebx + 0x1c] //get LIST
		mov LIST, ebx
		mov ebx, [ebx + 0x08] // get NTDLL
		mov NTDLL, ebx
	}

	printf("\n\tPEB Address \t: 0x%08x\n", PEB);
	printf("\tLDR Address \t: 0x%08x\n", LDR);
	printf("\tLIST Address \t: 0x%08x\n", LIST);
	printf("\tNTDLL Address \t: 0x%08x\n", NTDLL);
}
