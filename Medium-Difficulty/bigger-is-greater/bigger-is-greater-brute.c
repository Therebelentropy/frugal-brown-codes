#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();

// Complete the biggerIsGreater function below.

// Please either make the string static or allocate on the heap. For example,
// static char str[] = "hello world";
// return str;
//
// OR
//
// char* str = "hello world";
// return str;
//
char* biggerIsGreater(char* w) {    
    int u= strlen(w);
    int j;
    int flag=0;
    for(int i=0;i<u-1;i++)
    {
        if(w[i]<w[i+1])
        {
            flag++;
        }
    }
    printf("%d Flag\n",flag);
    if(flag==0)
    {
        return "no answer";
    }
    for(int i=u-1;i>0;i--)
    {
        if(w[i]>w[i-1])
        {
            j=i-1;
            break;
        }
        else if(i-1==0)
        {
            j=0;
        }
    }
    printf("%d\n",j);
    int o[u-j];
    for(int i=j;i<u;i++)
    {
        o[i-j]=w[i];
    }
    char temp=o[0];
    for(int i=1;i<u-j;i++)
    {
        if(o[0]<o[u-j-i])
        {
            flag=u-j-i;
            break;
        }
    }
    printf("%d Flag Reader\n",flag);
    o[0]=o[flag];
    o[flag]=temp;
    printf("%c Cha\n\n\n",o[flag]);
    for(int i=1;i<=(u-j)/2;i++)
    {
        char temp1=o[i];
        o[i]=o[u-j-i];
        o[u-j-i]=temp1;
    }
    for(int i=j;i<u;i++)
    {
        w[i]=o[i-j];
    }
    return w;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* T_endptr;
    char* T_str = readline();
    int T = strtol(T_str, &T_endptr, 10);

    if (T_endptr == T_str || *T_endptr != '\0') { exit(EXIT_FAILURE); }

    for (int T_itr = 0; T_itr < T; T_itr++) {
        char* w = readline();

        char* result = biggerIsGreater(w);

        fprintf(fptr, "%s\n", result);
    }

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}
