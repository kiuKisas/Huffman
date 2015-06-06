# Huffman

Huffman is a tiny tool using the Huffman compression algorithm written in C. It can compress/decompress any file or text from standard input and save it in a file or just print it to standard output.

## How to Use

By typing ./huffman -h, you will see this message

> Usage: ./huffman [options]...
> Compress a text with Huffman coding and save it.
> By default, reads standard input and save compression in "./huff.bin"
>
> Options :
> -d		huffman in decompression mode
> --BIN=<path>	specify the path of the binary
> --FILE=<path>	specify the path of the file
> -h		print this message
