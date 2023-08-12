#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>

double getTimeElapsed(struct timeval startTime, struct timeval endTime);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s source_file destination_file\n", argv[0]);
        return 1;
    }

    const char *srcFilename = argv[1];
    const char *dstFilename = argv[2];

    // Measure time taken by the "trans" command
    struct timeval startTrans, endTrans;
    gettimeofday(&startTrans, NULL);
    char transCommand[512];
    snprintf(transCommand, sizeof(transCommand), "./trans %s %s", srcFilename, dstFilename);
    int retTrans = system(transCommand);
    gettimeofday(&endTrans, NULL);
    double elapsedTimeTrans = getTimeElapsed(startTrans, endTrans);

    if (retTrans != 0) {
        fprintf(stderr, "Error running \"trans\" command.\n");
        return 1;
    }

    // Measure time taken by the "cp" command
    struct timeval startCP, endCP;
    gettimeofday(&startCP, NULL);
    char cpCommand[512];
    snprintf(cpCommand, sizeof(cpCommand), "cp %s %s", srcFilename, dstFilename);
    int retCP = system(cpCommand);
    gettimeofday(&endCP, NULL);
    double elapsedTimeCP = getTimeElapsed(startCP, endCP);

    if (retCP != 0) {
        fprintf(stderr, "Error running \"cp\" command.\n");
        return 1;
    }

    printf("\"trans\" Command Time: %.6f seconds\n", elapsedTimeTrans);
    printf("\"cp\" Command Time: %.6f seconds\n", elapsedTimeCP);

    return 0;
}

double getTimeElapsed(struct timeval startTime, struct timeval endTime) {
    return (endTime.tv_sec - startTime.tv_sec) + 
           (endTime.tv_usec - startTime.tv_usec) / 1000000.0;
}
