#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf(1, "Usage: mv SOURCE DEST\n");
        exit();
    }
    if (!link(argv[1], argv[2]))
        unlink(argv[1]);
    else{
        printf(1, "Error moving file %s to %s", argv[1], argv[2]);
    }
    exit();
}