/***********************************
 * MMIR01. Challenge 1
 * Convert from Hex to Base 64
************************************/

#include <iostream>
#include <string_view>
#include <vector>


std::string_view BASE64_CHARS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";


/*
First. Transform hex char into a byte

Base HEX
10 (0-9) + 6 (A-F) = 16 characters
4 bits for char (2^4=16)
*/
uint8_t hexCharToByte(char c) {
    uint8_t result = 0;

    // When substracting two character, it will give you the distance between them
    // So for example: '9' - '0' = 9 (decimal)
    // If we store 9 in a byte > 1001
    if ('0' <= c && c <= '9') 
    {
        result = c - '0';
    } 
    else if ('a' <= c && c <= 'f') 
    {   
        // In this case: 
        // 1) 'c' - 'a' = 2.
        // 2) 2 + 10 = 12 (dec) > 0b1100
        result = c - 'a' + 10;
    } 
    else if ('A' <= c && c <= 'F') 
    {
        result = c - 'A' + 10;
    }
    else
    {
        throw std::invalid_argument("Invalid hex character");
    }

    return result;
}


/*
Second. Convert a hex string to a byte vector
*/
std::vector<uint8_t> hexToBytes(std::string_view hex) {
    // Hex lenght has to be even  
    // 1 hex character can only store 4 bits, we need 2 hex chars
    // to form a full byte. If the length is odd, the last hex char 
    // will not have a partner to form a complete byte 
    if (hex.length() % 2 != 0) {
        throw std::invalid_argument("Invalid hex length");
    }

    std::vector<uint8_t> bytes;
    for (size_t i = 0; i < hex.length(); i += 2)
    {
        // For example 4A:
        // 4 = 4 (base10) = 0b0100
        // A = 10 (base10) = 0b1010
        // So, the two combined would be > 0100 1010 = 74
        bytes.push_back((hexCharToByte(hex[i]) << 4) | hexCharToByte(hex[i + 1]));
    }
    return bytes;
}


/*
Third. Convert a byte vector into base64

Base64 character set
26 (a-z) + 26 (A-Z) + 10 (0-9) + 2 (+,/) = 64 characters
6 bits for char (2^6=64)
*/
std::string base64Encode(const std::vector<uint8_t>& bytes)
{
    // 1) Divide the bits into groups of 6 bits each
    // Considering we are storing in a byte (8 bits)
    // LCL is 24 = 3 bytes
    // So, base64 will enconde 3 bytes per time, if the input
    // lenght is less than 24 bits we will use padding
    // We can check input lenght at the beginning and pad with ¡
    // zeroes, or directly check the output lenght and pad with =

    std::string base64_output;

    // We would save 2 bits every time to be taken next loop.
    // When we have 6, we don't have to take the next byte
    int bits_saved = 0;
    
    // It can save 32 bits, this is 4 blocks of 1 byte
    // (6 bits)
    int val = 0;

    for (uint8_t byte : bytes)
    {
        // Add byte at the end
        val = (val << 8) | byte;

        // 1) get first 6 bits and save the other 2 for later
        // 2) get 2 bits saved + 4 new, and save 4
        // 3) get 4 saved + 2 new, save 6
        // 4) get 6 saved
        // 5) like 1)
       
        bits_saved +=2;
        //Select value from BASE64_CHARS. Max index 63 (2^6-1)
        //0b0011 1111 = 63
        base64_output.push_back(BASE64_CHARS[(val >> bits_saved) & 0b00111111]);

        if (bits_saved == 6)
        {
            bits_saved = 0;
            base64_output.push_back(BASE64_CHARS[(val >> bits_saved) & 0b00111111]);
        }
    }
    
    // Base64 output is always a multiple of otherwise
    // Padding the leftover bits with 0 and
    // insert "=" as a padding
    if (bits_saved > 0)
    {
        int padding = 6 - bits_saved;
        base64_output.push_back(BASE64_CHARS[(val << padding) & 0b00111111]);
    }

    while (base64_output.size() % 4)
    {
        base64_output.push_back('=');
    }
    
    return base64_output;
}


int main()
{
    std::string_view inputString = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
    std::cout << "Input string in Hex: \n" << inputString << std::endl;;
    
    std::vector<uint8_t> bytes_vector = hexToBytes(inputString);
    //std::vector<uint8_t> bytes_vector(1, 77);
    
    std::string outputString = test(bytes_vector);
    std::cout << "Output string in Base64: \n" << outputString << std::endl;;

    std::string outputString2 = base64Encode(bytes_vector);
    std::cout << "My output string in Base64: \n" << outputString2 << std::endl;;
}