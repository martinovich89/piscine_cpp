#pragma once

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <iomanip>

#define INT_MAX 2147483647
#define INT_MIN -2147483648

typedef			void (*converter)(const std::string &arg);

void			fromInt(const std::string &arg);
void			fromChar(const std::string &arg);
void			fromFloat(const std::string &arg);
void			fromDouble(const std::string &arg);

bool			isChar(std::string arg);
bool			isInt(std::string arg);
bool			isFloat(std::string arg);
bool			isDouble(std::string arg);
int				whichType(std::string arg);
