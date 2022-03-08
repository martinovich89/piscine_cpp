#include "replace.hpp"

int ft_error(std::string error_msg, int ret)
{
    std::cout << error_msg;
    return (ret);
}