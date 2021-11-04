#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/input.h>
#include <string.h>
#include <stdio.h>

int main(){
        char* device = "/dev/input/by-path/platform-i8042-serio-0-event-kbd";
        int fd = open(device, O_RDONLY);
        if(fd == -1){
                return EXIT_FAILURE;
        }else{
                struct input_event evt;
		int pe[2], cap[3], raf[3];
		pe[0] = 0, pe[1] = 0;
		cap[0] = 0, cap[1] = 0, cap[2] = 0;
		raf[0] = 0, raf[1] = 0, raf[2] = 0;
                while(1){
                   	ssize_t b = read(fd, &evt, sizeof(evt));
                   	int printed = 0;
			if (evt.value == 1){
				
				if (evt.code == 25){
					pe[0] = 1, cap[2] = 1;
					raf[0] = 0, raf[1] = 0, raf[2] = 0;
				} else if (evt.value == 1 && evt.code == 18){
					pe[1] = 1;
					cap[0] = 0, cap[1] = 0, cap[2] = 0;
					raf[0] = 0, raf[1] = 0, raf[2] = 0;		
				}else if (evt.value == 1 && evt.code == 46){
					cap[0] = 1;
					pe[0] = 0, pe[1] = 0;
					raf[0] = 0, raf[1] = 0, raf[2] = 0;
				}else if (evt.value == 1 && evt.code == 30){
					cap[1] = 1, raf[1] = 1;
					pe[0] = 0, pe[1] = 0;
				}else if (evt.value == 1 && evt.code == 19){
					raf[0] = 1;
					pe[0] = 0, pe[1] = 0;
					cap[0] = 0, cap[1] = 0, cap[2] = 0;
				} else if (evt.value == 1 && evt.code == 33){
					raf[2] = 1;
					pe[0] = 0, pe[1] = 0;
					cap[0] = 0, cap[1] = 0, cap[2] = 0;
				} else {
					pe[0] = 0, pe[1] = 0;
					cap[0] = 0, cap[1] = 0, cap[2] = 0;
					raf[0] = 0, raf[1] = 0, raf[2] = 0;
				}
				
			}
			if (pe[0] && pe[1]){
				printed = 1;
				printf("\t%s\n", "I passed the Exam!");
			} 
			if (cap[0] && cap[1] && cap[2]){
				printed = 1;
				printf("\t%s\n", "Get some cappuccino!");
			}
			if (raf[0] && raf[1] && raf[2]){
				printed = 1;
				printf("\t%s\n", "My name is Rafail");
			}
			if (printed == 1){
				pe[0] = 0, pe[1] = 0;
				cap[0] = 0, cap[1] = 0, cap[2] = 0;
				raf[0] = 0, raf[1] = 0, raf[2] = 0;
			}
                }

        }
        fflush(stdout);
        return EXIT_SUCCESS;
}