Finale result:
D:\CLionProjects\Avito_HW\cmake-build-debug\Avito_HW.exe
/cygdrive/d/CLionProjects/Avito_HW/main.cpp:23 ::int main() d.size() is 213637
/cygdrive/d/CLionProjects/Avito_HW/main.cpp:24 ::int main() Oh, So long: 5362.65 milliseconds

Pay your attention to build flags -O2 allow to get such speed, without optimization it takes 2-3 times longer

Solution description:
1. Read big file by referencing it to memory with lazy initialization. takes about 5-15 ms from my hdd
2. Create unordered map as temporary storage. Reordering requires additional time, and make executions about 5 times longer
3. Fill u_map by values
4. Create map from u_map - execute reordering(sort by keys) only one time.

Gtest has been used for self check.

Project structure:
|- main.cpp - main execution and time calculation
|- files/ - provided files
|- service/ - main implementation
|- tests/ - tests implementation