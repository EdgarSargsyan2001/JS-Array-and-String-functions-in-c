#ifndef FUNCTION_H
#define FUNCTION_H
#include <string.h>
#include "stdlib.h"

char at(const char *str, int index)
{
    int l = strlen(str);
    if (index >= l || (index * -1) > l)
    {
        return '\0';
    }
    return index >= 0 ? str[index] : str[l + index];
}

char charAt(const char *str, int index)
{
    int l = strlen(str);
    if (index >= l || index < 0)
    {
        return '\0';
    }
    return str[index];
}

short charCodeAt(const char *str, int index)
{

    if (index >= strlen(str) || index < 0)
    {
        return -1;
    }
    return str[index];
}

char *concat(const char *s1, const char *spase, const char *s2) // return dynamic memory
{
    char *newSrt = (char *)malloc(sizeof(char) * (strlen(s1) + strlen(spase) + strlen(s2) + 1));
    if (newSrt == NULL)
    {
        return NULL;
    }
    int k = 0;
    while (*s1 != '\0')
    {
        newSrt[k++] = *s1;
        s1++;
    }
    while (*spase != '\0')
    {
        newSrt[k++] = *spase;
        spase++;
    }
    while (*s2 != '\0')
    {
        newSrt[k++] = *s2;
        s2++;
    }
    newSrt[k] = '\0';
    return newSrt;
}

int endsWith(const char *s1, const char *s2)
{
    int l1 = strlen(s1) - 1;
    for (int i = strlen(s2) - 1; i >= 0; --i)
    {
        if (s2[i] != s1[l1--])
        {
            return 0;
        }
    }
    return 1;
}
int endsWith1(const char *s1, const char *s2, int index)
{
    int l1 = index - 1;
    if (l1 < 0)
    {
        return 0;
    }
    for (int i = strlen(s2) - 1; i >= 0; --i)
    {
        if (s2[i] != s1[l1--])
        {
            return 0;
        }
    }
    return 1;
}

int includes(const char *s1, const char *s2)
{
    if (strlen(s2) > strlen(s1))
    {
        return 0;
    }

    for (int i = 0; s1[i] != '\0'; ++i)
    {
        if (s1[i] == s2[0])
        {
            int same = 1;
            for (int j = 1; s2[j] != '\0'; ++j)
            {
                if (s1[i + j] != s2[j])
                {
                    same = 0;
                    break;
                }
            }
            if (same)
                return 1;
        }
    }
    return 0;
}
int indexOf(const char *s1, const char *s2)
{
    if (strlen(s2) > strlen(s1))
    {
        return -1;
    }

    for (int i = 0; s1[i] != '\0'; ++i)
    {
        if (s1[i] == s2[0])
        {
            int same = 1;
            for (int j = 1; s2[j] != '\0'; ++j)
            {
                if (s1[i + j] != s2[j])
                {
                    same = 0;
                    break;
                }
            }
            if (same)
                return i;
        }
    }
    return -1;
}
int indexOf1(const char *s1, const char *s2, int index)
{
    if (strlen(s2) > strlen(s1))
    {
        return -1;
    }

    for (int i = index; s1[i] != '\0'; ++i)
    {
        if (s1[i] == s2[0])
        {
            int same = 1;
            for (int j = 1; s2[j] != '\0'; ++j)
            {
                if (s1[i + j] != s2[j])
                {
                    same = 0;
                    break;
                }
            }
            if (same)
                return i;
        }
    }
    return -1;
}
int lastIndexOf(const char *s1, const char *s2)
{
    if (strlen(s2) > strlen(s1))
    {
        return -1;
    }

    for (int i = strlen(s1) - 1; i >= 0; --i)
    {
        if (s1[i] == s2[0])
        {
            int same = 1;
            for (int j = 1; s2[j] != '\0'; ++j)
            {
                if (s1[i + j] != s2[j])
                {
                    same = 0;
                    break;
                }
            }
            if (same)
                return i;
        }
    }
    return -1;
}
int lastIndexOf1(const char *s1, const char *s2, int index)
{
    if (strlen(s2) > strlen(s1))
    {
        return -1;
    }

    for (int i = index; i >= 0; --i)
    {
        if (s1[i] == s2[0])
        {
            int same = 1;
            for (int j = 1; s2[j] != '\0'; ++j)
            {
                if (s1[i + j] != s2[j])
                {
                    same = 0;
                    break;
                }
            }
            if (same)
                return i;
        }
    }
    return -1;
}
char *padEnd(const char *str, int index) // return dynamic memory
{
    int l = strlen(str);
    int newLength = l >= index ? l : index;

    char *newStr = (char *)malloc(sizeof(char) * newLength + 1);
    if (newStr == NULL)
    {
        return NULL;
    }

    int i = 0;
    while (i < l)
    {
        newStr[i] = str[i];
        ++i;
    }
    while (i < index)
    {
        newStr[i++] = ' ';
    }
    newStr[i] = '\0';
    return newStr;
}
char *padEnd1(const char *str, int index, const char *el) // return dynamic memory
{
    int l = strlen(str);
    int newLength = l >= index ? l : index;
    // printf("%d\n", newLength);

    char *newStr = (char *)malloc(sizeof(char) * newLength + 1);
    if (newStr == NULL)
    {
        return NULL;
    }
    int i = 0;
    while (i < l)
    {
        newStr[i] = str[i];
        ++i;
    }
    // printf("%d\n", i);
    while (i < index)
    {
        for (int j = 0; ((i < index) && (el[j] != '\0')); ++j)
        {
            newStr[i++] = el[j];
        }
    }
    newStr[i] = '\0';
    return newStr;
}

char *padStart(const char *str, int index) // return dynamic memory
{
    int l = strlen(str);
    int newLength = l >= index ? l : index;

    char *newStr = (char *)malloc(sizeof(char) * newLength + 1);
    if (newStr == NULL)
    {
        return NULL;
    }
    int i = 0;
    while (i < (index - l))
    {
        newStr[i++] = ' ';
    }
    int k = 0;
    while (i < newLength)
    {
        newStr[i] = str[k++];
        ++i;
    }

    newStr[i] = '\0';
    return newStr;
}
char *padStart1(const char *str, int index, const char *el) // return dynamic memory
{
    int l = strlen(str);
    int newLength = l >= index ? l : index;

    char *newStr = (char *)malloc(sizeof(char) * newLength + 1);
    if (newStr == NULL)
    {
        return NULL;
    }
    int i = 0;
    while (i < (index - l))
    {
        for (int j = 0; ((i < (index - l)) && (el[j] != '\0')); ++j)
        {
            newStr[i++] = el[j];
        }
    }
    int k = 0;
    while (i < newLength)
    {
        newStr[i] = str[k++];
        ++i;
    }

    newStr[i] = '\0';
    return newStr;
}

char *repeat(const char *str, int count) // return dynamic memory
{
    if (count <= 0)
    {
        printf("%s", "Error: Invalid count value");
        return NULL;
    }
    int l = strlen(str);
    char *newStr = (char *)malloc(sizeof(char) * l * count + 1);
    if (newStr == NULL)
    {
        return NULL;
    }
    int i = 0;
    while (i < (l * count))
    {
        newStr[i] = str[i % l];
        ++i;
    }
    newStr[i] = '\0';
    return newStr;
}

char *replace(const char *str, const char *s1, const char *s2) // return dynamic memory
{
    int l = strlen(str);
    int index = indexOf(str, s1);
    int newLength = index == -1 ? l : (l + strlen(s2) - strlen(s1));

    char *newStr = (char *)malloc(sizeof(char) * newLength + 1);
    if (newStr == NULL)
    {
        return NULL;
    }
    int k = 0;
    for (int i = 0; i < l; ++i)
    {
        if (i == index)
        {
            for (int j = 0; s2[j] != '\0'; ++j)
            {
                newStr[k++] = s2[j];
            }
            i += strlen(s1) - 1;
        }
        else
        {
            newStr[k++] = str[i];
        }
    }
    newStr[k] = '\0';
    return newStr;
}
char *replaceAll(const char *str, const char *s1, const char *s2) // return dynamic memory
{
    char *ans = replace(str, s1, s2); //  return dynamic memory
    int index = indexOf(ans, s1);

    while (index != -1)
    {
        char *k = ans;
        ans = replace(ans, s1, s2); //  return dynamic memory
        index = indexOf(ans, s1);
        free(k);
    }
    return ans;
}

char *slice(const char *str, int index) //  return dynamic memory
{
    int l = strlen(str);
    if (index >= l || (index * -1) > l)
    {
        printf("%s", "out of range");
        return NULL;
    }
    int newSize = index >= 0 ? l - index : index * -1;
    char *newStr = (char *)malloc(sizeof(char) * newSize + 1);
    if (newStr == NULL)
    {
        return NULL;
    }

    int i = index >= 0 ? index : l + index;
    int k = 0;
    while (i < l)
    {
        newStr[k++] = str[i];
        ++i;
    }
    newStr[k] = '\0';
    return newStr;
}

char *slice1(const char *str, int l, int r) //  return dynamic memory
{
    int len = strlen(str);
    if (r > len || len < l)
    {
        printf("%s", "out of range");
        return NULL;
    }

    int newSize = r - l;
    char *newStr = (char *)malloc(sizeof(char) * newSize + 1);
    if (newStr == NULL)
    {
        return NULL;
    }

    int k = 0;
    for (int i = l; i < r; ++i)
    {
        newStr[k++] = str[i];
    }
    newStr[k] = '\0';
    return newStr;
}

// ================= split =========================

char **split(const char *str) // return dynamic memory
{
    char **Vector = (char **)malloc(sizeof(char) * 1);
    Vector[0] = (char *)malloc(sizeof(char) * strlen(str) + 1);
    int i = 0;
    while (str[i] != '\0')
    {
        Vector[0][i] = str[i];
        ++i;
    }
    Vector[0][i] = '\0';
    return Vector;
}
void deleteVector(char **v, int size)
{
    for (int i = 0; i < size; ++i)
    {
        free(v[i]);
    }
    free(v);
}

int findMaxTokenLength(const char *str, const char *ch)
{
    int len = strlen(str);
    int maxWordSize = 0;
    int wordSize = 0;
    for (int i = 0; i <= len; ++i)
    {
        if (str[i] == *ch || str[i] == '\0')
        {
            if (wordSize > maxWordSize)
            {
                maxWordSize = wordSize;
            }
            wordSize = 0;
        }
        else
        {
            wordSize++;
        }
    }
    return maxWordSize;
}

int TokenCount(const char *str, const char *ch)
{
    int len = strlen(str);
    int splitingCount = 0;
    for (int i = 0; i <= len; ++i)
    {
        if (str[i] == *ch || str[i] == '\0')
        {
            splitingCount++;
        }
    }
    return splitingCount;
}

char **split1(const char *str, const char *ch) // return dynamic memory
{
    char **Vector = (char **)malloc(sizeof(char *) * TokenCount(str, ch) + 1);
    int Vsize = 0;
    if (Vector == NULL)
    {
        return NULL;
    }

    char *token = (char *)malloc(sizeof(char) * findMaxTokenLength(str, ch) + 1);
    int tokenSize = 0;
    int len = strlen(str);
    for (int i = 0; i <= len; ++i)
    {
        if (str[i] == *ch || str[i] == '\0')
        {
            char *newToken = (char *)malloc(sizeof(char) * tokenSize + 1);
            if (newToken == NULL)
            {
                deleteVector(Vector, Vsize);
                free(token);
                return NULL;
            }

            token[tokenSize++] = '\0';
            for (int j = 0; j < tokenSize; ++j)
            {
                newToken[j] = token[j];
            }
            tokenSize = 0;
            Vector[Vsize++] = newToken;
        }
        else
        {
            token[tokenSize++] = str[i];
        }
    }
    free(token);
    Vector[Vsize++] = NULL;
    printf("Vsize: %d m:%d \n", Vsize, TokenCount(str, ch) + 1);
    return Vector;
}
//================================================
int startsWith(const char *s1, const char *s2)
{
    int k = 0;
    for (int i = 0; i < strlen(s2); ++i)
    {
        if (s2[i] != s1[k++])
        {
            return 0;
        }
    }
    return 1;
}
int startsWith1(const char *s1, const char *s2, int index)
{
    int k = index;
    for (int i = 0; i < strlen(s2); ++i)
    {
        if (s2[i] != s1[k++])
        {
            return 0;
        }
    }
    return 1;
}

char *substring(const char *str, int index) // return dynamic memory
{
    int l = strlen(str);
    if (index >= l || index < 0)
    {
        printf("%s", "out of range");
        return NULL;
    }
    char *newStr = (char *)malloc(sizeof(char) * (l - index) + 1);
    int k = 0;
    if (newStr == NULL)
    {
        return NULL;
    }

    for (int i = index; i < l; ++i)
    {
        newStr[k++] = str[i];
    }
    newStr[k] = '\0';
    return newStr;
}
char *substring1(const char *str, int l, int r) // return dynamic memory
{
    int len = strlen(str);
    if (r >= len || l < 0 || r <= l)
    {
        printf("%s", "out of range");
        return NULL;
    }
    char *newStr = (char *)malloc(sizeof(char) * (r - l) + 1);
    int k = 0;
    if (newStr == NULL)
    {
        return NULL;
    }

    for (int i = l; i < r; ++i)
    {
        newStr[k++] = str[i];
    }
    newStr[k] = '\0';
    return newStr;
}

char *toLowerCase(const char *str) // return dynamic memory
{

    char *newStr = (char *)malloc(sizeof(char) * strlen(str) + 1);
    int i = 0;
    if (newStr == NULL)
    {
        return NULL;
    }
    while (str[i] != '\0')
    {

        newStr[i] = str[i] + ((str[i] >= 'A' && str[i] <= 'Z') ? ('a' - 'A') : 0);
        ++i;
    }
    newStr[i] = '\0';
    return newStr;
}
char *toUpperCase(const char *str) // return dynamic memory
{

    char *newStr = (char *)malloc(sizeof(char) * strlen(str) + 1);
    int i = 0;
    while (str[i] != '\0')
    {
        newStr[i] = str[i] - ((str[i] >= 'a' && str[i] <= 'z') ? ('a' - 'A') : 0);
        ++i;
    }
    newStr[i] = '\0';
    return newStr;
}
char *trimEnd(const char *str) // return dynamic memory
{
    int l = strlen(str);
    int c = 0;
    for (int i = l - 1; str[i] == ' '; --i)
    {
        c++;
    }
    char *newStr = (char *)malloc(sizeof(char) * (l - c) + 1);
    if (newStr == NULL)
    {
        return NULL;
    }

    int index = 0;
    while (index < (l - c))
    {
        newStr[index] = str[index];
        ++index;
    }
    newStr[index] = '\0';
    return newStr;
}
char *trimStart(const char *str) // return dynamic memory
{
    int l = strlen(str);
    int c = 0;
    for (int i = 0; str[i] == ' '; ++i)
    {
        c++;
    }
    char *newStr = (char *)malloc(sizeof(char) * (l - c) + 1);
    if (newStr == NULL)
    {
        return NULL;
    }

    int index = 0;
    while (index < (l - c))
    {
        newStr[index] = str[index + c];
        ++index;
    }
    newStr[index] = '\0';
    return newStr;
}
char *trim(const char *str) // return dynamic memory
{
    char *a = trimStart(str);
    char *b = trimEnd(a);
    free(a);
    return b;
}

#endif