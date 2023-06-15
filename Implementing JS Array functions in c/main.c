#include "stdio.h"
#include "functions.h"

void print(int *a, int l)
{
    for (int i = 0; i < l; ++i)
    {
        printf("%d ", a[i]);
    }
}
int foo(int a)
{
    if (a == 2)
    {
        return 1;
    }
    return 0;
}
int foo2(int acc, int el)
{
    return acc + el;
}
int main()
{
    const int N = 6;
    const int M = 3;
    int arr1[] = {1, 2, 3, 4, 3999999, 2};
    int arr2[] = {77, 5, 9};
    int(*(matrix[])) = {
        (int[]){1, 2, 3},
        (int[]){4, 5, 6},
        (int[]){7, 8, 9}};

    // print(concat(arr1,N,arr2,M),N+M);

    // printf("%d",every(arr1,N,foo));

    // print(filter(arr1,N,foo),4); ?????

    // print(flat(matrix, 3, 3, 1), 9); ????

    // forEach(arr1,N,foo);
    // printf("%d ", indexOf(arr1, N, 2, 0));
    // printf("%d ", lastIndexOf(arr1, N, 2, 0));
    // print(map(arr1,N,foo),N);

    // printf("%d", reduce(arr1, N, foo2,33));

    // reverse(arr2, M);
    // print(arr2, M);

    // slice(arr1, N, 2, 5); // return dynamic memory

    // printf("%d",some(arr1,N,foo));
    // sort(arr1, N);

    // splice(arr1, N, 4, 2, 99); // return dynamic memory

    // =======   iterator   ============
    struct iterator it = entries(arr1, N);
    struct iteratorInfo info = next(&it);
    while (!info.done)
    {
        printf("done %d  val %d\n", info.done, info.value);
        info = next(&it);
    }
    //===============================

    // fill(arr1, N, 0, 2, N);
    // print(arr1,N);

    // printf(" %d", find(arr1, N, foo));
    // printf(" %d\n", findIndex(arr1, N, foo));
    // printf(" %d", findLastIndex(arr1, N, foo));

    // char *str = join(arr1, N, '.'); // use dynamic memory
    // printf("%s", str);
    // free(str);

    // int *newArr = with(arr1, N, 4, 0);
    // print(newArr, N);
    // free(newArr);
}