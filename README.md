# File Compression Tool (C++)

A simple file compression and decompression program written in C++ using Run-Length Encoding (RLE).

## Features

- Compresses text files using Run-Length Encoding
- Decompresses compressed files back to original text
- Supports repetition counts greater than 9
- Simple command-line interface
- Uses standard C++ libraries only

## How It Works

### Compression

The program reads `input.txt` and compresses consecutive repeating characters.

Example:

Input:
```
aaaaabbbbcc
```

Compressed Output:
```
a5b4c2
```

The compressed data is stored in:

```
output.swastik
```

---

### Decompression

The program reads:

```
output.swastik
```

and reconstructs the original file.

Example:

Compressed:
```
a5b4c2
```

Output:
```
aaaaabbbbcc
```

The decompressed data is stored in:

```
Input2.txt
```

---

## Project Structure

```
.
├── FileCompression.cpp
├── input.txt
├── output.swastik
└── Input2.txt
```

## Compilation

Using g++:

```bash
g++ FileCompression.cpp -o FileCompression
```

## Running

```bash
./FileCompression
```

### Menu

```
1 for Compress
2 for Decompress
3 for Exit
```

## Example Workflow

1. Create an `input.txt` file.
2. Select option `1` to compress.
3. Compressed data is saved to `output.swastik`.
4. Select option `2` to decompress.
5. Original content is restored in `Input2.txt`.

## Technologies Used

- C++
- STL (`vector`, `string`)
- File Handling (`fstream`)

## Limitations

- Best suited for files containing many consecutive repeating characters.
- Compression may increase file size for data with few repetitions.
- Current implementation is text-based only.

## Future Improvements

- Binary file support
- Better compression algorithms (Huffman Coding, LZW)
- Custom input/output file names
- Compression statistics
- File size comparison

## Author

**Swastik Raghav**

Learning C++ through practical projects and file handling applications.
