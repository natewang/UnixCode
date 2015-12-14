//
//  main.c
//  shell1
//
//  Created by nate on 15/12/14.
//  Copyright © 2015年 nate. All rights reserved.
//

#include <stdio.h>
#include "apue.h"
#include <sys/wait.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    char buf[MAXLINE];
    pid_t pid = 0;
    int status;
    
    printf("%%");
    while (fgets(buf, MAXLINE, stdin) != NULL) {
        if (buf[strlen(buf) - 1] == '\n') {
            buf[strlen(buf) - 1] = 0;
        }
    
    pid = fork();
    if (pid < 0) {
        err_sys("fork error");
    } else if (pid == 0) {
        
        execlp(buf, buf, (char*)0);
        err_ret("couldnt execute:%s", buf);
        
        exit(127);
    }
    
    if ((pid = waitpid(pid, &status, 0)) < 0) {
        
        err_sys("waitpid error");
    }
        
    printf("%% ");
        
    }
    
    return 0;
}
