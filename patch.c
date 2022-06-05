#include <stdio.h>
 
int main(void)
{
    unsigned char bytes[] = {0xB8, 0xFF, 0xFF, 0x90};
    int offset = 0x1DA69D; 
 
 
    FILE *fileH = fopen ("emu8086.exe", "r+");
 
    if (fileH == NULL) {
        perror("emu8086.exe");
        printf("Can't open the file please locate the patch at the same file as emu8068.exe\n");
        return 1;
    }
 
 
    if (fseek(fileH, offset, SEEK_SET)) {
        printf("Error reaching the offset\n");
        return 1;
    }
 
    if (fwrite(&bytes, sizeof(bytes), sizeof(bytes[0]), fileH) != 1) {
        printf("Error can't write to the file\n");
        return 1;
    }
 
 
    if (fclose(fileH))
        return 1;
 
 
    printf("File updated\n");
 
 
 
    char reg[] = "username=Patched By Mahmoud Ramadan\nregkey=x\nq=100";
    FILE *fileH2 = fopen ("reg.ini", "w");
 
    if (fileH2 == NULL)
        return 0;
 
    if (fwrite(&reg, sizeof(reg), sizeof(reg[0]), fileH2) != 1)
        return 0;
 
 
 
    return 0;
}
