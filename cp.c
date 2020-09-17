#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

char buf[512];

void cp(int fsrc, int fdst)
{
    int n;
    while ((n = read(fsrc, buf, sizeof(buf))) > 0)
    {
        if (write(fdst, buf, n) != n)
        {
            printf(1, "cp: write error\n");
            exit();
        }
    }
    if (n < 0)
    {
        printf(1, "cp: read error\n");
        exit();
    }
}

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf(1, "Usage: cp SOURCE DEST\n");
        exit();
    }
    int fsrc, fdst;
    fsrc = open(argv[1], O_RDONLY);
    if (fsrc < 0)
    {
        printf(1, "cp: cannot open %s\n", argv[1]);
        exit();
    }
    fdst = open(argv[2], O_CREATE | O_WRONLY);
    if (fdst < 0)
    {
        printf(1, "cp: cannot create %s\n", argv[2]);
        exit();
    }
    cp(fsrc, fdst);
    close(fdst);
    close(fsrc);
    exit();
}