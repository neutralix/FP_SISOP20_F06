#include "types.h"
#include "user.h"

// Sets the user UID and group GID for the target specified by pathname.
int
main(int argc, char* argv[])
{
    if(argc > 2)
    {
        char owner[1000], group[1000];
        int i=0,x=0,a=0,b=0;
        for (i=0; i>=0; i++) {
            if (argv[1][i] == '\0')
                break;
            if (argv[1][i] == ':') {
                x = 1;
                continue;
            }

            if (x == 0) {
                owner[a]=argv[1][i];
                a++;
            }
            else if (x == 1) {
                group[b]=argv[1][i];
                b++;
            }
        }

        printf(1, "owner : %s\ngroup : %s\n", owner, group);
        if(atoi(owner) >= 0 && atoi(group) >= 0)
        {
            if(chown(argv[2], atoi(owner), atoi(group)) < 0)
                printf(1, "chown %s failed \n", argv[2]);
            else
                printf(1, "Updating owner id...\n");
        }
        else
            printf(1, "Invalid argument(s) for chown...\n");
    }

    exit();
}