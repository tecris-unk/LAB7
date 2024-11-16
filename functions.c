
#include <stdlib.h>
#include <stdio.h>
void coutString(char** string)
{
int i = 0;
while((*string)[i] != '\0'){printf("%c", (*string)[i++]);}
}
void swap(int *firstNumber, int *secondNumber)
{
    *firstNumber ^= *secondNumber ^= *firstNumber ^= *secondNumber;
}
void erase(int *size, char** array, int i, int length)
{
    if(i < 0 || length < 0) {
        printf("Wrong enters\n");
        return;
    }
    if(i + length > *size){length = *size - i;}
    for (; i + length < *size; ++i)
        (*array)[i] = (*array)[i + length];

    *size -= length;
    (*array) = (char*)realloc(*array, sizeof(char) * (*size));
    if(*array == NULL){printf("safasf");return;}
    (*array)[*size] = '\0';
}
void setNumber(int* number)
{
    int i = 0;
    *number = 0;
    char digits[256];
    scanf("%s", digits);
    int negative = 1;
    if(digits[0] == '-'){negative = -1;i++;}
    do {
        if (digits[i] < '0' || digits[i] > '9') {
            printf("Enter a valid number\n");
            setNumber(number); break;
        }
        else { *number = *number * 10 + digits[i] - '0'; }
    } while(digits[++i] != 0);
    *number *= negative;
}
void scanString(char **string, int *size)
{
    int c;
    (*string)[0]='\0';
    for(int i=0; i<100 && (c=getchar())!='\n' && c != EOF ;)
    {
        *size = i+1;
        (*string) = (char*)realloc((*string), (i+2)*sizeof(char));
        if(*string == NULL){printf("memory cant be allocated");return;}
        (*string)[i] = (char) c;

        (*string)[++i] = '\0';
    }

}
struct pair {
    int first;
    int second;
};
void insertionSort(struct pair *array, int size)
{
    int *newIndex = (int*)malloc(sizeof(int) * size);
    for(int i = 0; i < size; ++i){
        newIndex[i] = i;
    }
    for (int i = 1; i < size; i++) {
        int key = array[i].first;
        int j = i - 1;

        while (j >= 0 && array[j].first > key) {
            array[j + 1].first = array[j].first;
            newIndex[j+1] = array[j].second;
            j--;
        }
        array[j + 1].first = key;
        newIndex[j+1] = i;
        for(j = 0;j < size; ++j)
        {
            array[j].second = newIndex[j];
        }
    }
free(newIndex);
}

void swapString(char* first,int sizeFirst, char* second, int sizeSecond)
{
    char* helpStr = (char*)malloc(sizeof(char) * sizeFirst);
    for(int i = 0;i < sizeFirst; ++i)
    {
        helpStr[i] = first[i];
        if(i < sizeSecond){first[i] = second[i];}
    }
   first = realloc(first, sizeSecond * sizeof(char));
    for(int i = sizeFirst;i < sizeSecond; ++i)
    {
        first[i] = second[i];
    }
    second = realloc(second, sizeFirst * sizeof(char));
    for(int i = 0;i < sizeFirst; ++i)
    {
        second[i] = helpStr[i];
    }
    free(helpStr);
}

void merge(struct pair *array, int n)
{
    int* newArray = (int*)calloc(n, sizeof(int) );
    int* newIndex = (int*)calloc(n, sizeof(int) );
    for (int k = 1; k < n; k<<=1)
    {
        for (int left = 0; left + k< n; left += k<<1)
        {
            int right = left + k;
            int rend = right + k;
            if (rend > n) {rend = n;}
            int m = left, i = left, j = right;

            while ( i < right && j < rend)
            {
                if (array[i].first<= array[j].first)
                {
                    newIndex[m] = array[i].second;
                    newArray[m++] = array[i++].first;
                }
                else
                {
                    newIndex[m] = array[j].second;
                    newArray[m++] = array[j++].first;
                }
            }
            while (i < right)
            {
                newIndex[m] = array[i].second;
                newArray[m++] = array[i++].first;
            }

            while (j < rend)
            {
                newIndex[m] = array[j].second;
                newArray[m++] = array[j++].first;
            }

            for (i = left; i < rend; i++)
            {
                array[i].first = newArray[i];
                array[i].second = newIndex[i];
            }
        }
    }
    free(newIndex);
    free(newArray);
}