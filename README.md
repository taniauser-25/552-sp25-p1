# How I ran the code
For Task 1 and Task 2:
I did in it Google Colab. To make the lab.h and lab.c I used the following lines of code
``` %%writefile lab.h ```
and 
``` %%writefile lab.c ```
so if you are runnining it in colab make sure to add these 2 lines to code in each cell of lab.h and lab.c. 

To run this code in Google Colab:

1. Install GCC by running:
```bash
!apt-get update && apt-get install -y gcc
```

2. Upload the lab.h and lab.c files to Colab or write them using %%writefile.
Compile and run the program:
```bash
!gcc lab.c -o lab && ./lab
```
Expected Output:

# For Task 3:

# How to Run the Project
Prerequisites
Before running this project, ensure you have the following installed:
  - GCC (GNU Compiler Collection)
  - Unity Test Framework (if using Unity for testing)
## Project Structure
Ensure your project directory has the following structure:

```bash
project/
├── lab.h          # Header file with function declarations
├── lab.c          # Implementation file
├── test_lab.c     # Test file with Unity tests
├── Unity/         # Unity Test Framework (downloaded from GitHub)
│   ├── src/
│   │   ├── unity.c
│   │   ├── unity.h

```
## Step 1: Clone Unity Framework
If Unity Test Framework is not already downloaded, clone it into your project directory:
```bash
git clone https://github.com/ThrowTheSwitch/Unity.git
```
## Step 2: Compile the Project
Run the following command to compile the program:
```bash
gcc test_lab.c lab.c Unity/src/unity.c -o test_lab
```
  - ``` test_lab.c ```: The test file that includes test cases
  - ``` lab.c ```: The implementation of the functions declared in ``` lab.h ```.
  - ``` Unity/src/unity.c ```: Unity Test Framework source file.
  - ``` -o test_lab ```: Output binary file.
## Step 3: Run the Tests
Execute the compiled binary to run the tests:
```bash
./test_lab
```
## Step 4: Output
If all tests pass, you will see output similar to this:
```bash
Running test_create_destroy...PASS
Running test_add1...PASS
Running test_add2...PASS
Running test_removeIndex0...PASS
Running test_removeIndex3...PASS
Running test_removeIndex4...PASS
Running test_invaidIndex...PASS
Running test_removeAll...PASS
Running test_indexOf0...PASS
Running test_indexOf3...PASS
Running test_notInList...PASS
Running test_destroyEmptyList...PASS
Running test_removeFromEmptyList...PASS
Running test_removeMiddleElement...PASS
Running test_removeLastElement...PASS
-----------------------
14 Tests 0 Failures 0 Ignored
OK
```
If any test fails, the output will include the failed test name and a line number indicating the failure.

# Makefile Project Template

Steps to configure, build, run, and test the project.

## Building

```bash
make
```

## Testing

```bash
make check
```

## Clean

```bash
make clean
```

## Install Dependencies

In order to use git send-mail you need to run the following command:

```bash
make install-deps
```
