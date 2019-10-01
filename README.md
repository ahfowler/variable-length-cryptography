# cse310-project1
Implementation of a variable-length encoding and decoding scheme.

### Student Information
**Name:** Azaria Fowler

**ID:** 1214875077

**Lecture:** TTH at 10:30am

### How to Use
There is a makefile with four tests.

Running `encode` with text files:

```
make encode 
./encode < yourInput.txt > yourOutput.txt
```

Running `decode` with text files:
```
make decode
./decode < yourInput.txt > yourOutput.txt
```

Running the default tests:
```
make insertionTest
make mergeTest
make mixedTest
make encodingTest
```
insertionTest and mergeTest run both encode and decode with the appropriate sorting method and compares the original text with the decoded output.
encodingTest runs encode with merge and insertion sort and compared both encoding outputs.

Remove the `encode` and `decode` executable files:
```
make clean
```
