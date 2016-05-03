//
//  main.c
//  zap
//
//  Created by wangnate on 16/4/5.
//  Copyright © 2016年 wangnate. All rights reserved.
//

#include "apue.h"
#include <fcntl.h>


int
main(int argc, char *argv[])
{
    int i, fd;
    struct stat statbuf;
    struct timespec times[2];
    
    for (int i = 0; i < argc; ++i)
    {
        if (stat(argv[i], &statbuf) < 0) {
            err_ret("%s: stat error", argv[i]);
            continue;
        }
        
        if ((fd = open(argv[i], O_RDWR | O_TRUNC)) < 0) {
            err_ret("%s :open error", argv[i]);
            continue;
        }
        times[0] = statbuf.st_atim;
        times[1] = statbuf.st_mtim;
        if (futimens(fd, times) < 0)
            err_ret("%s: futimens error", argv[i]);
        close(fd);
    }
    exit(0);
}
