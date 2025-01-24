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
