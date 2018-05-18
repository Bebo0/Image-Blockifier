pa4 for CPSC 221 - Data Structures and Algorithms. 

Given a PNG, neighbouring pixels that are similar in RGB values are replaced with a rectangle that has RGB values of the average of the pixels. The result is a "blocky" effect in the image whereby areas that don't contain much colour variability appear more "blocky" than areas that have a lot of colour variability. 

Initially, the PNG is represented as a binary tree whose nodes contain information about the rectangles. At the beginning of the program, the binary tree contains only one node/rectangle (the whole image). The rectangle (and any subsequent rectangle) is then recursively split horizontally or vertically into smaller rectangles. To split a rectangle R, we choose the horizontal or vertical partitions R1 and R2 that minimize the sum of the variability scores of R1 and R2. The end product is a binary tree (which is eventually transformed into a PNG) with nodes/rectangle that minimize the colour variability of the whole image.

Assignment page: https://www.ugrad.cs.ubc.ca/~cs221/2017W2/mps/p3/
