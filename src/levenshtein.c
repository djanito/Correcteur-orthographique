#include <string.h>
#include <stdlib.h>

#include "../include/levenshtein.h"

// Returns a size_t, depicting the difference between `a` and `b`.
// See <https://en.wikipedia.org/wiki/Levenshtein_distance> for more information.
unsigned int levenshtein(const char *a, const char *b)
{
    const int a_len = strlen(a);
    const int b_len = strlen(b);

    int a_idx = 0, b_idx = 0, a_dist, b_dist, result;
    int *cache = calloc(a_len, sizeof(int));
    char code;

    if (a == b)
        return 0;

    if (a_len == 0)
        return b_len;

    if (b_len == 0)
        return a_len;

    while (a_idx < a_len)
    {
        cache[a_idx] = a_idx + 1;
        ++a_idx;
    }

    while (b_idx < b_len)
    {
        code = b[b_idx];
        result = a_dist = b_idx++;
        a_idx = -1;
        while (++a_idx < a_len)
        {
            b_dist = (code == a[a_idx]) ? (a_dist) : (a_dist + 1);
            a_dist = cache[a_idx];

            cache[a_idx] = result = (a_dist > result) ? ((b_dist > result) ? (result + 1) : (b_dist)) : ((b_dist > a_dist) ? (a_dist + 1) : (b_dist));
        }
    }

    free(cache);

    return result;
}

unsigned int damerau_levenshtein(const char *a, const char *b)
{
    int a_len = strlen(a);
    int b_len = strlen(b);

    int *v = calloc(b_len + 1, sizeof(int));
    int i, j, current, next, cost;

    while (a_len > 0 && b_len > 0 && *a == *b)
    {
        a++, b++, a_len--, b_len--;
    }

    if (!a_len)
        return b_len;

    if (!b_len)
        return a_len;

    for (j = 0; j < b_len + 1; j++)
        v[j] = j;

    for (i = 0; i < a_len; i++)
    {
        current = i + 1;
        for (j = 0; j < b_len; j++)
        {
            cost = !(a[i] == b[j] || (i && j && a[i - 1] == b[j] && a[i] == b[j - 1]));

            next = MIN3(v[j + 1] + 1, current + 1, v[j] + cost);
            v[j] = current;
            current = next;
        }

        v[b_len] = next;
    }

    free(v);
    return next;
}
