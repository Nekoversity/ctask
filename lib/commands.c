#include "systools.c"
#include "../storage.c"

void cmd_help() {
    printf("If you want to add task, type new with task name: new My task name\n");
    printf("If you want to remove task, type del with task index: del 1\n");
    printf("If you done task, type cmp with task index: cmp 1\n");
    printf("If want to see uncompleted tasks, press [Enter] or type: uls\n");
    printf("If want to see done tasks, type: dls\n");
}

void cmd_new(char *answer) {
    int ans_len = strlen(answer);
    char text[ans_len - 4];

    for (int i = 0; i < ans_len; ++i) {
        if (i > 3) {
            text[i - 4] = answer[i];
        }
    }

    for (int i = 0; i < MAX_TASKS_COUNT; ++i) {
        if (strcmp(tasks[i], "") == 0) {
            strcpy(tasks[i], text);
            break;
        }
    }

    printf("New task [%s] added!", text);
}

void cmd_cmp(char *answer) {
    int i;
    if (sscanf(answer, "cmp %d", &i) == 1) {
        i -= 1;
        if (i >= 0) {
            if (strcmp(tasks[i], "") != 0) {
                for (int j = 0; i < MAX_TASKS_COUNT; ++j) {
                    if (strcmp(done_tasks[i], "") == 0) {
                        strcpy(done_tasks[j], tasks[i]);
                        strcpy(tasks[i], "");
                        printf("Task [%s] marked as done!", done_tasks[j]);
                        order_task_list(tasks);
                        break;
                    }
                }
            }
            else {
                printf("Task isn`t exist!");
            }
        }
        else {
            printf("Wrong index given!");
        }
    }
    else {
        printf("Wrong command input!");
    }
}

void cmd_del(char *answer) {
    int i;
    if (sscanf(answer, "del %d", &i) == 1) {
        i -= 1;
        if (i >= 0)
            if (strcmp(tasks[i], "") != 0) {
                strcpy(tasks[i], "");
                printf("Task successfully deleted!");
                order_task_list(tasks);
            }
            else {
                printf("Task isn`t exist!");
            }
        else {
            printf("Wrong index given!");
        }
    }
    else {
        printf("Wrong command input!");
    }
}

void cmd_dls() {
    int showed = 0;
    for (int i = 0; i < MAX_TASKS_COUNT; ++i)
        if (strcmp(done_tasks[i], "") != 0) {
            printf("%d. ---[%s]---\n", i+1, done_tasks[i]);
            ++showed;
        }
    if (!showed)
        printf("You have no completed tasks! \nType help for more info");
}

void cmd_uls() {
    int showed = 0;
    for (int i = 0; i < MAX_TASKS_COUNT; ++i)
        if (strcmp(tasks[i], "") != 0) {
            printf("%d. %s\n", i+1, tasks[i]);
            ++showed;
        }
    if (!showed)
        printf("You have no tasks! \nType help for more info");
}
