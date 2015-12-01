//
//  main.c
//  ls1
//
//  Created by wangnate on 15/11/30.
//  Copyright © 2015年 wangnate. All rights reserved.
//

#include <stdio.h>
#include "apue.h"
#include <dirent.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    DIR *dp;
    struct dirent *drip;
    
    if (argc != 2) {
        err_quit("usage: ls directory_name");
    }
    
    if ((dp = opendir(argv[1])) == NULL) {
        err_sys("can not open %s", argv[1]);
    }
    
    while ((drip = readdir(dp)) != NULL) {
        printf("%s\n", drip->d_name);
    }
    
    closedir(dp);
    exit(0);
}
