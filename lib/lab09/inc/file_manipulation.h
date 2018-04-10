#ifndef CMPE126S18_LABS_FILE_MANIPULATION_H
#define CMPE126S18_LABS_FILE_MANIPULATION_H

#include <string>

namespace lab9{
    class file_manipulation{
    public:
        file_manipulation(std::string input_file, std::string output_file);
        void compress();
        void decompress();
        ~file_manipulation();
    };
}

#endif //CMPE126S18_LABS_FILE_MANIPULATION_H
