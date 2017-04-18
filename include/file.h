#ifndef H_FILE
#define H_FILE

#include <string>


class File
{
private:
    std::string m_filePath;

public:
    File(std::string filePath);

    std::string getContent();
};

#endif
