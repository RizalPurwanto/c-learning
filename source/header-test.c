// another note: for #include, <> is usually used for builtin header files. ""
// is the one that's commonly used for user-made headers.
#include <stdio.h>
#include "player.h"

int gPlayerHP = PLAYER_MAXHEALTH;
//notice you can now use external variable and macros from the header files included above

int main () {
    gPlayerHP -= PLAYER_DAMAGEVAL;
    printf("Player HP: %d\n", gPlayerHP);
    return 0;
};
