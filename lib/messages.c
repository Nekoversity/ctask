#include "commands.c"

// Message showing on start
void welcome_message() {
    printf("Welcome to CTask! Mini task manager written on pure C");
    printf("\n\nStarting");
    // Dots drawing second by second
    for (int i = 0; i < 3; ++i) {
        wait_for(1);
        printf(".");
    }
    wait_for(1);
    clrscr();
}

void bye_message() {
    clrscr();
    printf("Closing app");
    for (int i = 0; i < 3; ++i) {
        wait_for(1);
        printf(".");
    }
    wait_for(1);
}

// Doing something based on answer arg
void switch_messager(char* answer) {
    clrscr();
    if (strcmp(answer, "help") == 0)
        cmd_help();
    else if (cmdcmp(answer, "uls") || strcmp(answer, "") == 0)
        cmd_uls();
    else if (cmdcmp(answer, "new"))
        cmd_new(answer);
    else if (cmdcmp(answer, "cmp"))
        cmd_cmp(answer);
    else if (cmdcmp(answer, "del"))
        cmd_del(answer);
    else if (cmdcmp(answer, "dls"))
        cmd_dls();
    else
        printf("I don`t know command \"%s\"", answer);
}