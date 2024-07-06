# Compressing/Decompressing a file using Huffman codes

NOTE - very untidy code, needs to be cleaned up. Implemented back in July 2022.

Compress a file using Huffman codes and decompress a file
encoded using Huffman codes. The inputs of the program are the following:

1. The name of the input file
2. The name of the output file
3. Mode (0/1) : 0 for compression, 1 for decompression

## Compression Mode:

In compression mode, the input file is the name of the file that needs to be compressed, and the
output file is the name of the file that will be created during the compression. The input file
contains a sequence of 8-bit characters. The output file stores the metadata for Huffman codes
followed by the encoded sequence. The program also prints the Huffman codes for each
character in the file in compression mode.

## Decompression mode:

In decompression mode, the input file is the file's name that is created during the compression
mode. The output file will be created during the decompression. The decompression algorithm
first builds the tree containing Huffman codes using the metadata and then uses the tree to
decode the encoded sequence in the input file. The decoded data is written to the output file.

## Sample file.

A sample input file (in.txt) is provided for compression. Below are some sample inputs/outputs of
your program.

Input
./a.out
Enter the name of the input file
in.txt
Enter the name of the output file
out.txt
Enter mode (0 for compression, 1 for decompression)
0

Output:
a -> 0
c -> 1 0 0
b -> 1 0 1
f -> 1 1 0 0
e -> 1 1 0 1
d -> 1 1 1

Generating out.txt

Input:
./a.out
Enter the name of the input file
out.txt
Enter the name of the output file
res.txt
Enter mode (0 for compression, 1 for decompression)
1
Output:
Generating res.txt
