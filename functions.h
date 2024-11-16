
#ifndef LAB7_FUNCTIONS_H
#define LAB7_FUNCTIONS_H

#endif //LAB7_FUNCTIONS_H

void swap(int *firstNumber, int *secondNumber);
void erase(int *size, char** array, int i, int length);
void setNumber(int* number);
void scanString(char **string, int *size);
struct pair {
    int first;
    int second;
};
void insertionSort(struct pair *array, int size);
void coutString(char** string);
void swapString(char* first, int sizeFirst, char* second, int sizeSecond);

void merge(struct pair* array, int n);

