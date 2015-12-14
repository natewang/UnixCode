//
//  main.c
//  uidgid
//
//  Created by nate on 15/12/14.
//  Copyright © 2015年 nate. All rights reserved.
//

#include <stdio.h>
#include "apue.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    
    printf("uid=%d, gid = %d\n", getuid(), getpid());
    
    return 0;
}
