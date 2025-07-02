#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char buf[BUFFER_SIZE];
    static int n_read;
    static int pos;
    int i = 0;
    char *res = malloc(1000);

    if (fd < 0 || BUFFER_SIZE <= 0 || !res)
        return NULL;

    while (1)
    {
        if (pos >= n_read)
        {
            n_read = read(fd, buf, BUFFER_SIZE);
            pos = 0;
            if (n_read <= 0)
                break;
        }
        if ((res[i++] = buf[pos++]) == '\n')
            break;
    }
    res[i] = '\0';

    if (i == 0)
    {
        free(res);
        return NULL;
    }
    return res;
}
