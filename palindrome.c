#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool chkPalin(char *txt) {
    int a = 0, b = strlen(txt) - 1;
    while (a < b) {
        if (!isalnum(txt[a])) a++;
        else if (!isalnum(txt[b])) b--;
        else if (tolower(txt[a]) != tolower(txt[b])) return false;
        else { a++; b--; }
    }
    return true;
}
