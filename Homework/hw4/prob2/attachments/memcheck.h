// memcheck.h
#ifndef CS100_MEMCHECK_H
#define CS100_MEMCHECK_H 1

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_RECORDS 1000

struct Record
{
    void *ptr;             // address of the allocated memory
    size_t size;           // size of the allocated memory
    int line_no;           // line number, at which a call to malloc or calloc happens
    const char *file_name; // name of the file, in which the call to malloc or calloc happens
};

struct Record records[MAX_RECORDS];

int count = 0;

void *recorded_malloc(size_t size, int line, const char *file)
{
    void *ptr = malloc(size);
    if (ptr != NULL)
    {
        records[count].ptr = ptr;
        records[count].size = size;
        records[count].line_no = line;
        records[count].file_name = file;
        // printf("malloc solved: count = %d\n", count);
        count++;
    }
    return ptr;
}

void *recorded_calloc(size_t cnt, size_t each_size, int line, const char *file)
{
    void *ptr = calloc(cnt, each_size);
    if (ptr != NULL)
    {
        records[count].ptr = ptr;
        records[count].size = cnt * each_size;
        records[count].line_no = line;
        records[count].file_name = file;
        // printf("calloc solved: count = %d\n", count);
        count++;
    }
    return ptr;
}

void recorded_free(void *ptr, int line, const char *file)
{
    if (ptr == NULL)
    {
        return;
    }

    for (int i = 0; i < count; i++)
    {
        if (records[i].ptr == ptr)
        {
            free(ptr);
            records[i].ptr = NULL;
            return;
        }
    }

    printf("Invalid free in file %s, line %d\n", file, line);
}

void check_leak(void) __attribute__((destructor));

void check_leak(void)
{
    printf("Summary:\n");
    int num = 0;
    size_t total = 0;
    for (int i = 0; i < count; i++)
    {
        if (records[i].ptr != NULL)
        {
            printf("%llu bytes memory not freed (allocated in file %s, line %d)\n", (unsigned long long)records[i].size, records[i].file_name, records[i].line_no);
            num++;
            total += records[i].size;
        }
    }

    if (num == 0)
    {
        printf("All allocations have been freed.");
    }
    else
    {
        printf("%d allocation records not freed (%llu bytes in total).\n", num, (unsigned long long)total);
    }
}

#define malloc(SIZE) recorded_malloc(SIZE, __LINE__, __FILE__)
#define calloc(CNT, EACH_SIZE) recorded_calloc(CNT, EACH_SIZE, __LINE__, __FILE__)
#define free(PTR) recorded_free(PTR, __LINE__, __FILE__)

#endif // CS100_MEMCHECK_H