#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <sys/stat.h>

void    replace(std::string &str, const std::string to_find, const std::string to_replace);
int ft_error(std::string error_msg, int ret);