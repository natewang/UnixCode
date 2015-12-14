//
//  main.c
//  testerror
//
//  Created by nate on 15/12/14.
//  Copyright © 2015年 nate. All rights reserved.
//

#include <stdio.h>
#include "apue.h"
#include <errno.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    fprintf(stderr, "EACCES: %s\n", strerror(EACCES));
    errno = ENOENT;
    perror(argv[0]);
    
    return 0;
}
