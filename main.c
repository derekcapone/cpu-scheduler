#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100
#define MAX_FILE_SIZE 1000

void tokenize_str(char *arr);
void fillProcArr(void);

/* Struct for process values */
struct Process{
    int name;
    int arrival;
    int burst;
};

/* Variables to hold file information */
struct Process tasks[MAX_TASKS];
int n_tasks;

int main()
{
    fillProcArr();

    return 0;
}

/*
 * Uses "TaskSpec.txt" to fill
 */
void fillProcArr(void)
{
    FILE *fp = fopen("TaskSpec.txt", "r");

    int i, length;
    char tmp_char;
    char ch_arr[MAX_FILE_SIZE];

    /* Iterate through file characters */
    for(i=0; i<MAX_FILE_SIZE; i++){
        tmp_char = fgetc(fp);
        if(tmp_char == EOF) break;

        /* Add character to temporary array */
        ch_arr[i] = tmp_char;

        printf("%c", tmp_char);
    }

    /* Tokenize string and fill unsorted array */
    tokenize_str(ch_arr);
}


void tokenize_str(char *arr)
{
    int tmp_val;

    /* Reset n_tasks to zero */
    n_tasks = 0;

    char *tok = strtok(arr, "\n");

    while(tok != NULL){
        tasks[n_tasks].name = atoi(&tok[1]);
        tasks[n_tasks].arrival = atoi(&tok[3]);
        tasks[n_tasks].burst = atoi(&tok[5]);

        /* Get next task */
        tok = strtok(NULL, "\n");

        /* Increment number of tasks in array */
        n_tasks++;
    }
}








