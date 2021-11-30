#include "../stdafx.h"

// Clearing console output
void clrscr() {
    system("@cls||clear");
}

// Initialize task list with empty string value
void init_empty_task_list(char task_list[][MAX_TASK_NAME_LEN]) {
    for (int i = 0; i < MAX_TASKS_COUNT; ++i) {
        strcpy(task_list[i], "");
    }
}

// Moving all empty elements to right (bubble sort)
void order_task_list(char task_list[][MAX_TASK_NAME_LEN]) {
    int moved;

    do {
        moved = 0;
        for (int i = 1; i < MAX_TASKS_COUNT; ++i) {
            if (strcmp(task_list[i - 1], "") == 0 && strcmp(task_list[i], "") != 0) {
                strcpy(task_list[i - 1], task_list[i]);
                strcpy(task_list[i], "");
                ++moved;
            }
        }
    } while (moved);
}

// Waiting for some time, then continue code execution
void wait_for (unsigned int secs) {
    unsigned int stopTime = time(NULL) + secs;
    while (time(NULL) < stopTime);
}

// Checking 3 first chars for equality with given command
int cmdcmp(char* answer, char* command) {
    return answer[0] == command[0] && answer[1] == command[1] && answer[2] == command[2];
}
