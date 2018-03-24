Course Name: ece275 <br>
Author: <br>
NetID: <br>
Date: <br>
Project Name: project_8

# Description:
## High-Level Description
In this assignment you will calculate the frequency of hashtags appearing on Twitter at a particular time and analyzing the trend over time.

## Trending
You will be creating a C++ program that analyzes the frequency of the occurrence of **Hashtag**s within two input files, a *startHashtagFilePath* and an *endHashtagFilePath*. The program will analyze the change in rank of specific **Hashtag**s from the *startHashtagFilePath* to the endHashtagFile, where the highest ranked hashtag (i.e., **Hashtag** ranked in position 1) appears most frequently (has the highest count). Finally, the program will output a ranked list of all **Hashtag**s appearing in the *endHashtagFilePath* along with the relative change in the rank for each **Hashtag** from the *startHashtagFilePath* to the *endHashtagFilePath*.

## Classes
You will be given two classes to begin with. The rest is up to you.

The first class represents a **Hashtag** found in the input files. This should at least have a std::string _content data member and some members to represent the rank of the Hashtag in the start file and in the end file. The rest of the implementation of the class is up to you.

The second class is called **Trending** and represents the entire program that you intend to run. The purpose of this class is similar to CarSimulator and Chars in previous projects except that it has only one function called *Run*. In this function, you need to call all of the functions you need to run the program from beginning to end. A good program design would be evident by this function calling only a few other select functions that do the bulk of the work of the program just as the endToEnd tests did in the past.

The reason you are given this kind of class is mostly for the sake of grading your projects based on the end-to-end functionality. Since you are now given the freedom to write any functions or classes you choose, it is necessary for the grader to have a common function to call for all submissions in order to grade your project. So, you can think of this function, *Run* as your *main* function.

# Important Requirements
First and foremost, your project will be graded only on the end-to-end functionality. Writing unit tests are optional, but testing and developing your program in smaller steps will save you, and instructors, loads of time. You have been shown examples on how to do this until now.

Second, your program must finish in 5 seconds or less **on the server**. This has actually always been a requirement until now, but in this project, you will be handling substantially larger files at times. Therefore, having efficient algorithms actually becomes important. The most computationally complex portion of this assignment is likely the sorting algorithm. However, it is possible that through poor design choices that otherwise trivial operations can take much longer.

# Input File
## Formatting
For this assignment, the input text file will only consist of the uppercase and lowercase characters ('a' to 'z', 'A' to 'Z'). Each **Hashtag** within the text file will be separated by one or more whitespace characters (' ', '\t', '\n', '\r').
Both the *startHashtagFilePath* and *endHashtagFilePath* file is formatted according to the following specifications:
1. Every **Hashtag** will only consist of the uppercase and lowercase characters ('a' to 'z', 'A' to 'Z').
2. Each **Hashtag** within the text file will be separated by one or more whitespace characters (' ', '\t', '\n', '\r').

## Processing
As each **Hashtag** is read from the input text file, your program must keep track of **Hashtag**s and the number of times each **Hashtag** is used.
Note that the identification of unique **Hashtag**s is *case insensitive*. For example, "Party", "party", and "PARty" are all considered the same **Hashtag**.
You may use any ADT (e.g., list, vector) to store the **Hashtag**s, but the ADT elements should be **Hashtag** objects. While the input file may contain both uppercase and lowercase characters.

# Output File
The output *trendFilePath* should be formatted according to the following specification:
1. Only **Hashtag**s that are in the *endHashtagFilePath* are output to the *trendFilePath*
2. **Hashtag**s are sorted according to the rank found in *endHashtagFilePath*.
3. Each **Hashtag** should be output with one **Hashtag** per line using the following format, using a single space to separate the entries:

> R: W (RD)

4. R is the rank of the **Hashtag**.
a. If a tie exists for that position, the rank should be preceded with the character 'T'.
b. **Hashtag** with the same rank should be output alphabetically.
5. W is the **Hashtag** word itself.
6. RD is the rank difference between the *startHashtagFilePath* and *endHashtagFilePath*. If the word did not appear in the *startHashtagFilePath*, the rank difference should be reported as "(new)". If the rank did not change between the start file and the end file, the rank difference should be reported as "(+0)".

## Example
The following provides an example of the output file format:

```
T1: truth (+0)
T1: metal (+3)
2: ece275 (+1)
3: omgthisassignmenttho (-1)
4: yunodoc++ (new)
```

# Sorting Hashtags
## Ranking Hashtags
In this project, you must rank a set of **Hashtag** *twice*. First, you must rank Hashtags in the *startHashtagFilePath* and again in the *endHashtagFilePath*. Ranking the **Hashtag**s could be potentially very difficult without first *sorting* them. Therefore, it would be very convenient to be able to sort the **Hashtag**s from both the start and end files using the same overloaded < operator. The next section covers how to overload the **Hashtag** < operator such that it is possible to read in information from the *startHashtagFilePath*, sort the **Hashtag**s and rank them, then read in the *endHashtagFilePath* and rank them as well.

## Suggested Overloading
You should overload the < operator for the **Hashtag** class for the sake of sorting the hashtags according to rank. This allows you to use the std::sort() function or other similar library functions. The **Hashtag** with the largest count should appear first. To achieve this, a **Hashtag** with a larger count will be considered less than a **Hashtag** with a smaller count. The lefthand side **Hashtag** is the object on which the operator< function is called. The righthand side object is passed as a reference argument to the operator<  function.

The lefthand side (lhs) **Hashtag** is less than the righthand (rhs) if (all string comparisons are case insensitive):
1.    If the rhs' end count is less than the lhs end count
2.    If the rhs' end count is equal to the lhs' end count, and both end counts are not 0, and the lhs' word is less than rhs' word alphabetically
3.    If both the rhs' and the lhs' end counts are 0, and the rhs' start count is less than the lhs' start count
4.    If both the rhs' and lhs' end counts are 0, and the rhs' start count is equal to the lhs' start count, and the lhs' word is less than the rhs' word alphabetically



