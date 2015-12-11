//
//  main.c
//  getcputc
//
//  Created by nate on 15/12/11.
//  Copyright © 2015年 nate. All rights reserved.
//

#include <stdio.h>
#include "apue.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    int c ;
    while ((c = getc(stdin)) != EOF) {
        if (putc(c, stdout) == EOF) {
            err_sys("output error");
        }
    }
    
    if (ferror(stdin)) {
        err_sys("input error");
    }
    
    return 0;
}
