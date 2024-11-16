#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
void task1()
{
    int size, length;
    printf("enter  length of words, that needed to be deleted\n");
    setNumber(&length);

char *string = (char*)malloc(sizeof(char));
printf("enter string\n");
    while(getchar()!='\n');
    scanString(&string, &size);

for(int i = 0;i < size;++i )
{
    int j = i;
    while(string[j] != ' ' && ++j < size);
    if(j - i > length){
        erase(&size, string, i, j - i + 1);
        i--;
    }
}
printf("here is your new string\n");
for(int i = 0;i<size;++i)
    printf("%c", string[i]);
printf("\n");
free(string);

}
void task2()
{
    int size;

    char *string = (char*)malloc(sizeof(char));
    if(string == NULL){printf("memory cant be allocated");return;}

    printf("enter string\n");
    scanString(&string, &size);

    printf("enter char that need to be deleted every second time\n");
    char CHAR;
    scanf("%c", &CHAR);

    int odd = 0;
    for(int i = 0;i < size;++i )
    {
        if(string[i] == CHAR){odd++;}
       if(odd & 1){erase(&size, string, i, 1);i--;}
    }
    printf("here is your new string\n");
    for(int i = 0;i<size;++i)
        printf("%c", string[i]);
    printf("\n");
    free(string);
}
void task3()
{
    printf("enter size of array\n");
    int size;
    setNumber(&size);
    while(getchar()!='\n');
    char **array = (char**)malloc(size * sizeof(char*));
    if(array == NULL){printf("memory cant be allocated");return;}
    struct pair *evenWords = (struct pair*)calloc(size, sizeof(struct pair));
    for(int i = 0;i < size;++i)
    {
        evenWords[i].second = i;
        array[i] = (char*)malloc(sizeof(char));
        if(array[i] == NULL){printf("memory cant be allocated");return;}
        int stringSize = 0;


        scanString(array+i, &stringSize);
        for(int j = 0; j < stringSize;)
        {
             int k = j;
             while(array[i][k] != ' ' && ++k < stringSize);
            evenWords[i].first += 1 - (k - j) & 1;
            j = k+1;
        }
    }
    insertionSort((struct pair *) evenWords, size);
    for(int i = 0;i < size;++i)
    {
        int j = evenWords[i].second;
        coutString(array[j]);
        printf("\n");
    }
    free(evenWords);
    free(array);
}
int main(void) {
    while(1)
    {
        int temp = 0;
        printf("Enter task number\n");
        int task;
        setNumber(&task);
        while(getchar() != '\n');
        switch(task)
        {
            case 1:
                task1();
                temp = 1;
                break;
            case 2:
                task2();
                break;
            case 3:
                task3();
                temp = 1;
                break;
            default:
                printf("There is no this task\n");
                temp = 1;
        }
        printf("You want to continue ?(Y\\N) ");

        if(!temp){while(getchar() != '\n'){}}
        int choice = getchar();
        if(choice == 'n' || choice == 'N'){ break;}
    }
    return 0;
}