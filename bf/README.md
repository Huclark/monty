# Brainf*ck
`Brainf*ck` is an esoteric programming language created by Urban Muller which consists of eight commands, a data pointer and an instructioin pointer.<br>

This directory contains brainf*ck scripts that perform specific functions.

|	**FILE**	          |	**FUNCTION**	               |
| ----------------------- | ------------------------------ |
| `1000-school.bf`        | Prints `School`, followed by a new line|
| `1001-add.bf`           | Add two digits given by the user |
| `1002-mul.bf`           | Multiply two digits given by the user |
| `1003-mul.bf`           | Reads the two digits from stdin, multiply them, and print the result, followed by a new line|

## Usage
1. Install the `bf` interpreter to run a `bf` file: `sudo apt-get install bf`
2. Ensure the `bf` file is an executable: `chmod +x <file>` where `<file>` is the path to the `bf` file/
3. Run the executable. For example:
```
huclark@HUCLARK:~/monty/bf$ bf 1000-school.bf 
School
huclark@HUCLARK:~/monty/bf$ bf 1003-mul.bf 
56
30
huclark@HUCLARK:~/monty/bf$ 
```
