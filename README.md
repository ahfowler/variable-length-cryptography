# cse310-project1
Implementation of a variable-length encoding and decoding scheme.

### Student Information
**Name:** Azaria Fowler

**ID:** 1214875077

**Lecture:** TTH at 10:30am

### How to Use
There is a makefile with five commands.

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

Running the default test:
```
make test
```
This test will run both encode and decode and check to see if the input to encode equals the output from decode.

Remove the `encode` and `decode` executable files:
```
make clean
```
