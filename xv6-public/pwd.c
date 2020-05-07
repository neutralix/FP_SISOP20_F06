#include "types.h"
#include "user.h"

int
main(int argc, char *argv[])
{
    char path[512];
    getcwd(path, 512);
    printf(1, "%s\n", path);
    exit();
}
