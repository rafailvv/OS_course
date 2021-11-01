#include <stdio.h>
#include <dirent.h>
int main(){
    struct dirent *files;
    DIR *my_dir = opendir(".");
    while ((files = readdir(my_dir)) != NULL)
        if(files->d_name[0] != '.')
            printf("%s ", files->d_name);

    printf("\n");
    closedir(my_dir);
    return 0;
}