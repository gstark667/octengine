#include "file.h"

#include <fstream>
#include <sstream>

using namespace std;


File::File(string filePath)
{
    m_filePath = filePath;
}


string File::getContent()
{
    ifstream file(m_filePath);
    stringstream stream;
    stream << file.rdbuf();
    return stream.str();
}

