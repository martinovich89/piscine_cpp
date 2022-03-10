#include "replace.hpp"

int main(int argc, char *argv[])
{
    // args checks
    if (argc != 4)
        return (ft_error("program needs 3 arguments : <Filename>, <to_find>, <to_replace>\n", 0));
    struct stat buffer;
    if (stat(argv[1], &buffer))
        return (ft_error("unreachable file\n", 0));

    // init
    std::string filename(argv[1]);
    std::string to_find(argv[2]);
    std::string to_replace(argv[3]);
    std::string to_append(".replace");
    std::string replace_file(filename.append(to_append));
    std::string line;

    // starting reading file and replacing    
    std::ifstream fin;
    fin.open(argv[1]);
    if (!fin.is_open())
        return (ft_error("failed to open file\n", 0));
    std::ofstream fout;
    fout.open(replace_file.c_str(), std::ofstream::trunc);
    if (!fout.is_open())
        return (ft_error("failed to open file\n", 0));
    while (std::getline(fin, line))
    {
        replace(line, to_find, to_replace);
        fout << line << std::endl;
    }
    return (0);
}