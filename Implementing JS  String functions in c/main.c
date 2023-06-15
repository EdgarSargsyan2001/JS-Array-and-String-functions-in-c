#include "stdio.h"
#include "function.h"
int main()
{
    char str[] = {"hello world"};
    char str2[] = {"i am a programmer"};
    char str3[] = {"The quick brown fox jumps over the lazy dog. If the dog barked, was it rea"};

    // printf("%c\n", at(str, 10));
    // printf("%c", at(str, -11));

    // printf("%c\n", charAt(str, 4));
    // printf("%d", charCodeAt(str, 100));

    // char *k = concat(str, " , ", str2); // return dynamic memory
    // printf("%s", k);
    // free(k);

    // printf("%d\n", endsWith(str, "ld"));
    // printf("%d", endsWith1(str, "hello",5));

    // printf("%d", includes(str, "worl"));

    // printf("%d\n", indexOf(str3, "dog"));
    // printf("%d", indexOf1(str3, "dog",40+1));
    // printf("%d\n", lastIndexOf(str3, "dog"));
    // printf("%d", lastIndexOf1(str3, "dog",52));

    // char *m = padEnd(str, 11); // return dynamic memery
    // char *n = padEnd1(str, 20,".123456"); // return dynamic memery
    // printf("%s", m);
    // printf("%s", n);
    // free(m);
    // free(n);

    // char *m = padStart(str, 15);       // return dynamic memery
    // char *n = padStart1(str, 15, ".p"); // return dynamic memery
    // printf("%s\n", m);
    // printf("%s", n);
    // free(m);
    // free(n);

    // char *k = repeat(str, 2); // return dynamic memery
    // printf("%s", k);
    // free(k);

    char str4[] = {"The fox brown fox brown brown fox"};

    // char *j = replace(str4, "brown", "w");// return dynamic memery
    // printf("%s", j);
    // free(j);
    // char *u = replaceAll(str4, "fox", "w"); // return dynamic memery
    // printf("%s", u);
    // free(u);

    // char *sl = slice(str4, -32); // return dynamic memery
    // char *sl1 = slice1(str4, 0, 5);
    // printf("%s\n", sl);
    // printf("%s\n", sl1);
    // free(sl);
    // free(sl1);

    // char **k = split(str4); // return dynamic memery (matrix)
    // printf("%s", k[0]);
    // free(k[0]);
    // free(k);
    char str5[] = {"The quick brown fox jumps over the lazy dog."};

    // struct split1Ans k = split1(str5, " "); // return dynamic memery (matrix)
    // for (int i = 0; i < k.size; ++i)
    // {
    //     printf("%s \n", k.arrforString[i]);
    //     free(k.arrforString[i]);
    // }
    // free(k.arrforString);

    // printf("%d\n", startsWith(str5, "The"));
    // printf("%d", startsWith1(str5, "quick",4));

    char str6[] = {"MozIlla"};
    // char *l = substring(str6, 4);      // return dynamic memery
    // char *l1 = substring1(str6, 1, 3); // return dynamic memery
    // printf("%s\n", l);
    // printf("%s", l1);
    // free(l);
    // free(l1);

    // char *y = toLowerCase(str6); // return dynamic memery
    // char *x = toUpperCase(str6);
    // printf("%s\n", y);
    // printf("%s", x);
    // free(y);
    // free(x);

    char str7[] = {"    Hello world!    "};

    char *t = trimEnd(str7);    // return dynamic memery
    char *t1 = trimStart(str7); // return dynamic memery
    char *t2 = trim(str7);      // return dynamic memery
    // printf("%s$\n", t);
    // printf("%s$\n", t1);
    printf("%s", t2);
    free(t);
    free(t1);
    free(t2);
}