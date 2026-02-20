#pragma once
#ifndef FUNC2_HOMEDYN2_H
#define FUNC2_HOMEDYN2_H
#include <string>

void readF(const std::string& fileName, int& N, int mass[80][80]);
long findMinFunc(int N, int mass[80][80]);
void outFileFunc(const std::string& fileName, long res);


#endif