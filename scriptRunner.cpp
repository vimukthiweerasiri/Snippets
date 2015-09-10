#include <string>
#include <iostream>
#include <stdio.h>
#include <math.h>

long exec(std::string cmdStr) {
    char* cmd = &cmdStr[0];
    FILE* pipe = popen(cmd, "r");
    if (!pipe) return -1l;
    char buffer[128];
    std::string result = "";
    while(!feof(pipe)) {
    	if(fgets(buffer, 128, pipe) != NULL)
    		result += buffer;
    }
    pclose(pipe);
    return std::stol(result);
}

double standard_deviation(long data[], int n, bool foundSamleSize)
{
    double mean=0.0, sum_deviation=0.0;

    for(int i=0; i<n;++i) {
        mean+=data[i];
    }

    mean=mean/n;

    for(int i=0; i<n;++i) {
        sum_deviation+=(data[i]-mean)*(data[i]-mean);
    }

    double standardDeviation = sqrt(sum_deviation/n);
    double sampleSize = (100 * 1.96 * standardDeviation) / (5 * mean);
    sampleSize = pow(sampleSize, 2);
    if(!foundSamleSize) {
        std::cout<<"std "<<standardDeviation<<std::endl;
        std::cout<<"mean "<<mean<<std::endl;
    } else {
        std::cout<<"sample size "<<n<<std::endl;
        std::cout<<"result "<<mean<<std::endl;
    }    
    return sampleSize;     
}

int main(int argc, const char* argv[]) {

    if(argc != 4) {
        std::cout<<"Error. Argument order should be,\n<programName> <matrixSize> <initSampleSize>"<<std::endl;
        exit(-1);
    }

    std::string programName = argv[1];
    int matrixSize = atoi(argv[2]), initSampleSize = atoi(argv[3]);

    std::cout<<"Running for matrixSize: "<<matrixSize<<"  and initial sample size: "<<initSampleSize<<std::endl;

    long data[initSampleSize];
    std::string cmd = "./" + programName + " " + std::to_string(matrixSize);
    for (int i = 0; i < initSampleSize; ++i) {
        data[i] = exec(cmd);
    }

    int calulatedSampleSize = standard_deviation(data, initSampleSize, false) + 1;

    long samplingData[calulatedSampleSize];
    for (int i = 0; i < calulatedSampleSize; ++i) {
        samplingData[i] = exec(cmd);
    }

    standard_deviation(samplingData, calulatedSampleSize, true);

    return 0;
}
