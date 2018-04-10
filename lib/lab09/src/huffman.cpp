#include "../inc/huffman.h"
#include <fstream>
#include <bitset>

namespace lab9{
    void huffman::compress(std::string input_file_name, std::string output_file_name) {
        //TODO: Create huffman tree
        huffman_tree tree();

        // Open up the input file and read it character by character
        std::ifstream input_file(input_file_name);
        char character_from_file;
        if(input_file.good()){
            while(input_file.get(character_from_file)){
                //TODO: Use `character_from_file` for frequency
            }
        }
        else return; // If the file can't be read, quit.

        //TODO: Create huffman dictionary from huffman tree
        huffman_dictionary dict = huffman_dictionary(nullptr);

        // Open up the output file
        std::ofstream output_file(output_file_name, std::ios::binary);

        // Reset input_file location to beginning of file
        input_file.clear();
        input_file.seekg(0,std::ios::beg);

        // Do stuff with the files
        if(input_file.good() && output_file.good()){
            //Write dictionary to first "line" of output file
            output_file << dict << std::endl;

            // Create string stream to hold binary string and fill stream
            std::stringstream binary_string;
            while(input_file.get(character_from_file)){
                // TODO: Write the binary value of the character to the stream
                binary_string;
            }

            // Write an EOF character to signify the end of the text
            binary_string << dict.get(04);

            // Read through the binary string stream, create bytes, and write them to output file
            char character_from_binary_string;
            std::bitset<8> to_write;
            int bit_location = 7;
            while(binary_string.get(character_from_binary_string)){
                to_write[bit_location--] = (character_from_binary_string == '1');
                if(bit_location < 0){
                    bit_location = 7;
                    output_file << static_cast<unsigned char>(to_write.to_ulong());
                    to_write.set();
                }
            }
            output_file << static_cast<unsigned char>(to_write.to_ulong());
        }
        else return; // If something isn't good, quit.
    }

    void huffman::decompress(std::string input_file_name, std::string output_file_name) {
        // Open input file and read first line which contains the huffman
        std::ifstream input_file(input_file_name, std::ios::binary);
        std::string huffman_dict_string;
        if(input_file.good()){
            std::getline(input_file, huffman_dict_string);
            if(huffman_dict_string.back() != '0' && huffman_dict_string.back() != '1'){
                huffman_dict_string += '\n';
                std::string fix_newline;
                std::getline(input_file, fix_newline);
                huffman_dict_string += fix_newline;
            }
        } else return; // If we can't read the file, quit.

        // TODO: Generate the huffman_tree from huffman_dict_string
        huffman_tree tree;

        // Setup variables for decoding
        char character_from_file;
        node* current = tree.get_root();

        // Open output file
        std::ofstream output_file(output_file_name);
        if( input_file.good() && output_file.good()){
            while(input_file.get(character_from_file)){
                // Convert character into a byte that we can see the individual bits
                std::bitset<8> bit_set(static_cast<unsigned char>(character_from_file));
                for(int bit_location = 7; bit_location >= 0; bit_location--){
                    // TODO: Traverse the tree given the individual bits. Do this using current

                    // We have gotten to a node that holds an actual character
                    if(current->get_character() != '\0'){
                        // If we see the EOF character, end the decoding process
                        if(current->get_character() == 04) break;
                        // Write the character to the output file
                        output_file << current->get_character();

                        // TODO: Reset the tree for traversal

                    }
                }
            }
        } else return;
    }
}

