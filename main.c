#include <stdio.h>
#include <stdlib.h>
#include<time.h>

void generate_data(char* strFileName) {
    // File Path
    FILE *fp = NULL;
    // Random Point X
    int x = 0;
    // Random Point Y
    int y = 0;
    // Total number of data points
    const int intNumOfDataPoints = 25; 
    // Min/Max values for the generated data points
    const int intXMax = 100;
    const int intXMin = 100;
    const int intYMax = -100;
    const int intYMin = -50;

    // Open File
    fp = fopen (strFileName, "w");



    // Generate random X and Y coordinate, save to data.tmp file
    for (int i = 0; i < intNumOfDataPoints; i++) {
        x = (rand() % intXMax) + intXMin;
        y = (rand() % intYMax) + intYMax;
        fprintf(fp, "%d %d\n", x, y);
    }
}

int main(void) {
    // Pipe to GNU Plot
    FILE *gnupipe = NULL;
    
    // File Names
    char* FileName1 = "data.tmp";
    char* FileName2 = "data2.tmp";
    char* FileName3 = "data3.tmp";

    // Set seed for random generator
    srand(time(NULL));

    // Generate New Data
    generate_data(FileName1);
    generate_data(FileName2);
    generate_data(FileName3);

    // Set GNU Plot Commands, use plot command to load data.tmp
    char *GnuCommands [] = {"set title \"k-means clustering\"", 
                            "plot 'data.tmp'  pt 7 ps 2 lc \"blue\", 'data2.tmp'  pt 7 ps 2 lc \"red\", 'data3.tmp'  pt 7 ps 2 lc \"#FF00FF\""};
    int intNumOfCommands = sizeof(GnuCommands)/sizeof(GnuCommands[0]);

    // Open GNU Plot, -persistent will keep the window open after execution has completed
    gnupipe = _popen("gnuplot -persistent", "w");

    // Send commands to GNU plot
    for (int i = 0; i < intNumOfCommands; i++) {
        fprintf(gnupipe, "%s\n", GnuCommands[i]);
    }

    // Return
    return 0;
}
