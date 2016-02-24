//
//  main.c
//  hole
//
//  Created by nate on 15/12/17.
//  Copyright © 2015年 nate. All rights reserved.
//

#include <stdio.h>
#include "apue.h"
#include <fcntl.h>

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int fd;
    if ((fd = creat("file.hole", FILE_MODE)) < 0) {
        err_sys("creat error");
    }
    
    if (write(fd, buf1, 10) != 10) {
        err_sys("buf1 wrte error");
    }
    
    if (lseek(fd, 16384, SEEK_SET) == -1) {
        err_sys("seek error");
    }
    
    if (write(fd, buf2, 10) != 10) {
        err_sys("buf2 wrte error");
    }
    
    return 0;
}
