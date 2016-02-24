//
//  main.c
//  seek
//
//  Created by nate on 15/12/17.
//  Copyright © 2015年 nate. All rights reserved.
//

#include <stdio.h>
#include "apue.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    
    if (lseek(STDIN_FILENO, 0, SEEK_CUR) == -1) {
        printf("can not seek\n");
    } else {
        printf("seek ok\n");
    }
    
    return 0;
}
