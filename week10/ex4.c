#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>

int main() {
    DIR *dirp = opendir("./tmp/");
    struct stat buffer;
    struct dirent *file;
    char array[10][10];
    ino_t inode_array[100];
    int i = 0, j, k;
    while ((file = readdir(dirp)) != NULL) {
        char str[80];
        strcpy(str, "./tmp/");
        strcat(str, file->d_name);
        stat(str, &buffer);
        nlink_t count = buffer.st_nlink;
        if (count >= 2) {
            strcpy(array[i], file->d_name);
            ino_t inode = buffer.st_ino;
            inode_array[i] = inode;
            i++;
        }
    }
    printf("File -- Hard Links\n");
    for (j = 0; j < i; ++j) {
        ino_t tmp = inode_array[j];
        char str[80];
        strcpy(str, "");
        int count_files = 0;
        for (k = 0; k < i; ++k) {
            if (inode_array[k] == tmp && tmp != -1) {
                strcat(str, array[k]);
                if (k != i - 1) {
                    strcat(str, ", ");
                }
                count_files++;
                inode_array[k] = -1;
            }
        }
        if (count_files >= 2 && tmp != -1) {
            printf("file1 -- ");
            printf("%s ", str);
            printf("\n");
            printf("link1 -- ");
            printf("%s ", str);
            printf("\n");
        }
        inode_array[j] = -1;

    }
}