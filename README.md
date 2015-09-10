# Script Runner

###### scriptRunner runs the input program and find the mean value of its output to 95% confidence with ±5% accuracy

####How to use script runner,

comile it with,

```g++ -std=c++11 scriptRunner.cpp -o scriptRunner```

then if your program is ```myProgram``` and run it like,

```(./myProgram <arg1> <arg2> ... <argN>)```
then the script to run it is,

```./scriptRunner myProgram <arg1> <arg2> ... <argN> <initSampleSize>```

Eg:

1. ```g++ myProgram.cpp -o myProgram```
2. ```g++ scriptRunner.cpp -o scriptRunner```
3. ```./scriptRunner myProgram 100 100```
