#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }

    bool hasNonSpace = false;
    for (int i = 1; i < argc && !hasNonSpace; ++i)
    {
        char *s = argv[i];
        for (int j = 0; s[j] != '\0'; ++j)
        {
            if (!std::isspace(static_cast<unsigned char>(s[j])))
            {
                hasNonSpace = true;
                break;
            }
        }
    }

    if (!hasNonSpace)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }

    for (int i = 1; i < argc; ++i)
    {
        char *s = argv[i];
        for (int j = 0; s[j] != '\0'; ++j)
            std::cout << static_cast<char>(std::toupper(static_cast<unsigned char>(s[j])));
        if (i + 1 < argc)
            std::cout << ' ';
    }
    std::cout << std::endl;
    return 0;
}