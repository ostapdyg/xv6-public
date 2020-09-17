#include "types.h"
#include "stat.h"
#include "user.h"

int write_t(int fd, const char* s){
    write(fd, s, strlen(s));
    return 0;
}

int main(int argc, char *argv[])
{
    printf(1, "Hello from %s", argv[0]);
    // write_t(1, "Hello, world");
    exit();
}
