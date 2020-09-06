#include "../include/hw2.h"

#include "../include/util/macro.h"
#include "../include/util/process.h"
#include "../include/util/guard.h"

#include <sys/types.h>
#include <stdio.h>

/**
 * Run CSCI 451 HW2.
 *
 * @param argv The argv value from the main function.
 */
void hw2(char ** const argv) {
    guardNotNull(argv, "argv", "hw2");
    guardNotNull(argv[0], "argv[0]", "hw2");

    puts("Parent: Forking");
    pid_t const childProcessId = safeFork("hw2");
    if (childProcessId == 0) {
        // Child only

        puts("Child: Running xclock");
        safeExecvp(
            "xclock",
            (char * const []){
                MUTABLE_STRING("xclock"),
                NULL
            },
            "hw2"
        );
    } else {
        // Parent only

        puts("Parent: Restarting");
        safeExecvp(argv[0], argv, "hw2");
    }
}
