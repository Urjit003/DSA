#include <stdio.h>
#include <stdlib.h>
int main() {
     wchar_t gujarati_alphabets[] = {0x0A95, 0x0A96, 0x0A97, 0x0A98, 0x0A99, 0x0A9A, 0x0A9B, 0x0A9C, 0x0A9D, 0x0A9E};

    // Printing Gujarati alphabets
    wprintf(L"Gujarati Alphabets:\n");
    for (int i = 0; i < sizeof(gujarati_alphabets) / sizeof(gujarati_alphabets[0]); i++) {
        printf("%lc ", gujarati_alphabets[i]);
    }

    return 0;
return 0 ;
}