#include "lib/messages.c"
#include "stdafx.h"
#include "storage.c"

int start_ctask() {
    init_empty_task_list(tasks);
    init_empty_task_list(done_tasks);

    int first_message = 1;

    welcome_message();

    while (1) {
        // User input consists of command name (4 chars) and, possibly, task name
        char answer[MAX_TASK_NAME_LEN + 4];

        if (first_message) {
            printf("You have no tasks! \nType help for more info");
            printf("\n\n> ");
            first_message = 0;
        }

        if (gets(answer)) {
            if (strcmp(answer, "stop") == 0) {
                bye_message();
                break;
            }
            switch_messager(answer);
            printf("\n\n> ");
        }
        else {
            return -1;
        }
    }

    return 1;
}

int main() {
    return start_ctask();
}
