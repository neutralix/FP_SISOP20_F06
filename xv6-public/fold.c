#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

char buf[512];

void fold(int fd, int column)
{
    int red;
    int i;
    int count = 1; 

    while ((red = read(fd, buf, sizeof(buf))) > 0) 
    {
        for(i=0; i<=red; i++){
            if(count <= column){
                if(buf[i] == '\n'){
                    count = 0;
                    printf(1, "%c", buf[i]);
                }
                else{
                    printf(1, "%c", buf[i]);
                }
            }
            else if(count > column){
                if(buf[i] == '\n'){
                    count = 0;
                    printf(1, "%c", buf[i]);
                }
                else{
                    printf(1, "\n");
                    printf(1, "%c", buf[i]);
                    count = 1;
                }
            }
            count++;
        }
    }
    if(red < 0){
        printf(1, "fold: read error\n");
        exit();
    }
}

int main(int argc, char *argv[])
{
    int fd;
    int i;
	
    if(argc < 3){
        printf(1, "Usage: fold -w[number] [file]\n");
        exit();
    }

    char format[200];
    strcpy(format, argv[1]);

    char check[3];
    for(i=0; i<2; i++){
        check[i] = format[i];
    }
    check[i] = '\0';

    if(strcmp(check, "-w") != 0){
        printf(1, "Usage: fold -w[number] [file]\n");
        exit();
    }

    char *number;
    number = format + 2;

    int column = atoi(number);

    if ((fd = open(argv[2], O_RDONLY)) < 0) 
    { 
        printf(1, "Cannot open file %s\n", argv[2]); 
        exit(); 
    }
    fold(fd, column);
    close(fd);
}
