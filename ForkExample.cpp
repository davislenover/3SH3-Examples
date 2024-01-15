// Example by Davis Lenover

#include "ForkExample.h"
// Include for fork()
#include "unistd.h"
// For printf (stdio.h is deprecated)
#include "cstdio"

ForkExample::ForkExample() {

    // The fork() command (linux only) will create a duplicated process (child process) from the current process (the parent)
    // The program counter for the process will start on the next line after the fork call

    // One child will be created from the parent
    // Returns the processID (the PID) of the child process TO THE PARENT if creation was successful, -1 for failure
    // For the child process ITSELF 0 is returned. This is done to distinguish from the parent and child
    int processId = fork();

    if (processId == 0) {
        printf("Hi I am a child process!\n");
    } else {
        printf("Hi I am the parent process!\n");
    }

    // Both the parent and the previous child created will execute this line, resulting in two children being created via this line
    fork();

    // In total now, there are 4 processes (technically 3 children and 1 actual parent)
    // As a result, the line below will be executed 4 times
    // getpid() returns the processId for the current process
    printf("Hello from process %d!\n",getpid());

}
