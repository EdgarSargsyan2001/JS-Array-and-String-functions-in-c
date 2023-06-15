#ifndef FUNCTIONS
#define FUNCTIONS
#include "stdio.h"
#include "stdlib.h"

int *concat(int *a1, int l1, int *a2, int l2) //  return dynamic memory
{
    int *newArr = (int *)malloc(sizeof(int) * (l1 + l2));
    if (newArr == NULL)
    {
        return newArr;
    }
    int k = 0;
    for (int i = 0; i < l1; ++i)
    {
        newArr[k++] = a1[i];
    }
    for (int i = 0; i < l2; ++i)
    {
        newArr[k++] = a2[i];
    }
    return newArr;
}

int every(int *arr, int l, int (*callBack)(int))
{
    for (int i = 0; i < l; ++i)
    {
        if (!callBack(arr[i]))
        {
            return 0;
        }
    }
    return 1;
}

int *filter(int *arr, int l, int (*callBack)(int)) //  return dynamic memory
{
    int *newArr = (int *)malloc(sizeof(int) * l);
    if (newArr == NULL)
    {
        return newArr;
    }
    int k = 0;
    for (int i = 0; i < l; ++i)
    {
        if (callBack(arr[i]))
        {
            newArr[k++] = arr[i];
        }
    }
    if (k == l)
    {
        return newArr;
    }
    return (int *)realloc(newArr, k * sizeof(int));
}

int *flat(int **arr, int n, int m, int depth) //  return dynamic memory
{
    int *newArr = (int *)malloc(sizeof(int) * (n * m));
    if (newArr == NULL)
    {
        return newArr;
    }
    int k = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            newArr[k++] = arr[i][j];
        }
    }
    return newArr;
}

void forEach(int *arr, int size, int (*callBack)(int))
{
    for (int i = 0; i < size; ++i)
    {
        callBack(arr[i]);
    }
}

int indexOf(int *arr, int size, int el, int startIndex)
{
    if (size <= startIndex)
    {
        return -1;
    }
    for (int i = startIndex; i < size; ++i)
    {
        if (arr[i] == el)
        {
            return i;
        }
    }
    return -1;
}

int lastIndexOf(int *arr, int size, int el, int startIndex)
{
    if (size <= startIndex)
    {
        return -1;
    }
    for (int i = (size - startIndex - 1); i >= 0; --i)
    {
        if (arr[i] == el)
        {
            // printf("%d ", i);
            return i;
        }
    }
    return -1;
}

int *map(int *arr, int size, int (*callBack)(int)) //  return dynamic memory
{
    int *newArr = (int *)malloc(sizeof(int) * size);
    if (newArr == NULL)
    {
        return NULL;
    }
    for (int i = 0; i < size; ++i)
    {
        newArr[i] = callBack(arr[i]);
    }
    return newArr;
}

int reduce(int *arr, int size, int (*callBack)(int, int), int initVal)
{

    int accumulator = initVal;
    int i = 0;
    while (i < size)
    {
        accumulator = callBack(accumulator, arr[i]);
        ++i;
    }
    return accumulator;
}

void reverse(int *arr, int size)
{
    for (int i = 0; i < size / 2; ++i)
    {
        int tmp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = tmp;
    }
}

int *slice(int *arr, int size, int l, int r) //  return dynamic memory
{
    int *newArr = (int *)malloc(sizeof(int) * size);
    int k = 0;
    if (newArr == NULL)
    {
        return NULL;
    }
    for (int i = 0; i < size; ++i)
    {
        if (i >= l && i < r)
        {
            newArr[k++] = arr[i];
        }
    }

    if (k == size)
    {
        return newArr;
    }
    return (int *)realloc(newArr, sizeof(int) * k);
}

int some(int *arr, int size, int (*callBack)(int))
{
    for (int i = 0; i < size; ++i)
    {
        if (callBack(arr[i]))
        {
            return 1;
        }
    }
    return 0;
}

void sort(int *arr, int size)
{

    int swapped = 0;
    for (int i = 0; i < size; ++i)
    {
        swapped = 0;
        for (int j = 0; j < size - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                swapped = 1;
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
        if (!swapped)
        {
            break;
        }
    }
}

int *splice(int *arr, int size, int index, int spase, int el) //  return dynamic memory
{
    int length = size + (spase ? (-spase + 1) : 1);
    // printf(" length %d \n", length);
    int *newArr = (int *)malloc(sizeof(int) * length);
    int k = 0;
    for (int i = 0; i < size; ++i)
    {

        if (i == index)
        {
            newArr[k++] = el;
            i += spase;
            if (i == size)
            {
                break;
            }
        }
        newArr[k++] = arr[i];
    }
    // for (int i = 0; i < k; ++i)
    // {
    //     printf("%d ", newArr[i]);
    // }
    return newArr;
}

// =======   iterator   ============
struct iterator
{
    int *ptr;
    int size;
    int index;
};
struct iteratorInfo
{
    int value;
    int done;
};

struct iteratorInfo next(struct iterator *it)
{
    struct iteratorInfo info;
    info.done = 0;
    if (it->index >= it->size)
    {
        info.done = 1;
        return info;
    }
    info.value = it->ptr[it->index++];
    return info;
}

struct iterator entries(int *arr, int size)
{
    struct iterator it;
    it.size = size;
    it.index = 0;
    it.ptr = arr;
    return it;
}

//=======================================================

void fill(int *arr, int size, int el, int l, int r)
{
    if (r > size)
    {
        r = size;
    }
    if (l < 0)
    {
        l = 0;
    }
    for (int i = l; i < r; ++i)
    {
        arr[i] = el;
    }
}

int find(int *arr, int size, int (*callBack)(int))
{
    for (int i = 0; i < size; ++i)
    {
        if (callBack(arr[i]))
        {
            return arr[i];
        }
    }
    return -1;
}
int findIndex(int *arr, int size, int (*callBack)(int))
{
    for (int i = 0; i < size; ++i)
    {
        if (callBack(arr[i]))
        {
            return i;
        }
    }
    return -1;
}
int findLastIndex(int *arr, int size, int (*callBack)(int))
{
    for (int i = size - 1; i > 0; i--)
    {
        if (callBack(arr[i]))
        {
            return i;
        }
    }
    return -1;
}
int includes(int *arr, int size, int el)
{
    for (int i = 0; i < size; ++i)
    {
        if (arr[i] == el)
        {
            return 1;
        }
    }
    return 0;
}

char *intToString(int a) //  return dynamic memory
{
    char str[10]; // because int can be at most 10 in length;
    int c = 0;
    while (a != 0)
    {
        str[c++] = a % 10;
        a /= 10;
    }
    char *line = (char *)malloc(sizeof(char) * c + 1);
    int k = 0;
    for (int i = c - 1; i >= 0; --i)
    {
        line[k++] = str[i] + '0';
    }
    line[c++] = '\0';
    return line;
}

char *join(int *arr, int size, char ch) // return dynamic memory
{
    char *str = (char *)malloc(sizeof(char) * 11 * size); // // because int can be at most 10 in length;
    int k = 0;

    for (int i = 0; i < size; ++i)
    {
        char *line = intToString(arr[i]); // line is a dynamic memory
        for (int i = 0; line[i]; ++i)
        {
            str[k++] = line[i];
        }
        free(line);
        str[k++] = ch;
    }
    str[--k] = '\0';
    return (char *)realloc(str, sizeof(char) * k);
}

int *with(int *arr, int size, int index, int el) //  return dynamic memory
{
    int *newArr = (int *)malloc(sizeof(int) * size);
    if (newArr == NULL || index >= size || index < 0)
    {
        return NULL;
    }
    for (int i = 0; i < size; ++i)
    {
        newArr[i] = arr[i];
    }
    newArr[index] = el;
    return newArr;
}

#endif