//
//  main.c
//  mycat
//
//  Created by wangnate on 15/12/1.
//  Copyright © 2015年 wangnate. All rights reserved.
//

#include <stdio.h>
#include "apue.h"

#define BUFFSIZE  4096

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n;
    char  buf[BUFFSIZE];
    
    while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0) {
        if (write(STDOUT_FILENO, buf, n) != n) {
            err_sys("write error");
        }
    }
    
    if (n< 0) {
        err_sys("read error");
    }
    
    
    return 0;
}
