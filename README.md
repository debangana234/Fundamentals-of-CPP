## Course Webpage
The project contains assignments from the course and some code snippets explaining the basic concepts in C++ like copy constructors, move constructors, copy assignment, move assignmenta and other data structures in C++
https://cms.sic.saarland/prog_bi_23/

## Structure
- Basic_tasks
- Assignment 0
- Assignment 1
- Assignment 2
- Assignment 3
- Assignment 4


 ## Setting up the development environment:

1. Student's license at https://www.jetbrains.com/shop/eform/students
and registration for an account was completed.
2. CLion was downloaded ( https://download-cf.jetbrains.com/cpp/CLion-2021.
2.3.tar.gz)
4. Execute: cd clion-2021.2.3/bin and clion script with ./clion.sh
5. login with  students account created in the first step.
6. File -> New Project -> C++ Executable: enter a location and use C++17  (this
creates an automatic "Hello World" example for including CMakeLists.txt
for running cmake)
7. Build the example by clicking the "build" button (upper right) or via Run ->
Build and run the example by clicking the "run" button.
8. In the newly created Project folder, the created Hello World file is named
main.cpp. The build folder (cmake-build-debug) contains a Makefile, the exe-
cutable, and some other files and folders.The executable could also be run  with
./name_of_executable if we are in the same folder
9. Then we delete the build folder (rm -r cmake-build-debug) and try to create the
same output that CLion gave us by clicking two buttons manually
10. A build folder is created and the path is changed into this directory
11. Cmake is called again to create a Makefile for our project
12. Call make to build your project/executable (we should now have again an executable that we can execute)



