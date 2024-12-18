# C-Huffman

# Huffman Coding for Lossless Data Compression

This project implements the Huffman coding algorithm for lossless data compression. It uses a MinHeap data structure to construct a Huffman tree, which assigns variable-length binary codes to characters based on their frequencies in the input text. This ensures efficient encoding and decoding of data.

## Features

- **Encoding**: Compresses input text into a binary format using Huffman codes.
- **Decoding**: Reconstructs the original text from the encoded binary data.
- **File Output**: Saves the encoded text in `encoded.txt` and the decoded text in `decoded.txt`.
- **Console Output**: Displays the original text, encoded text, and decoded text for verification.

## How It Works

1. **Frequency Calculation**: Counts the frequency of each character in the input text.
2. **MinHeap Construction**: Builds a priority queue of nodes, where each node represents a character and its frequency.
3. **Huffman Tree Creation**: Combines nodes with the smallest frequencies to create a binary tree with characters as leaves.
4. **Code Assignment**: Traverses the tree to assign binary codes to each character.
5. **Encoding**: Converts the input text to a binary string using the assigned codes.
6. **Decoding**: Traverses the Huffman tree to reconstruct the original text from the encoded binary string.

## File Structure

- **`main.cpp`**: Contains the implementation of the Huffman coding algorithm.
- **`encoded.txt`**: Stores the binary representation of the input text after encoding.
- **`decoded.txt`**: Contains the reconstructed original text after decoding.

## How to Run

1. **Compile the Code**:
   ```bash
   g++ -o huffman main.cpp
   ```
2. **Run the Program**:
   ```bash
   ./huffman
   ```
3. **Check Output**:
   - Encoded text will be saved in `encoded.txt`.
   - Decoded text will be saved in `decoded.txt`.
   - Original, encoded, and decoded texts will be displayed on the console.

## Example

Input Text:
```
Computer and Information Science Cleveland State University
```

Console Output:
```
Original text: Computer and Information Science Cleveland State University
Encoded text: [Binary String]
Decoded text: Computer and Information Science Cleveland State University
```

## Dependencies

- C++ Standard Library:
  - `<bits/stdc++.h>` for all standard functionalities.
  - `<unordered_map>` for character-to-code mapping.
  - `<stack>` for tree traversal.
  - `<fstream>` for file operations.

## Applications

- File compression (e.g., ZIP, RAR).
- Data transmission in networks.
- Efficient storage in constrained environments.
