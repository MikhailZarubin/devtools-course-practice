// Copyright 2022 Zarubin Mikhail

#include <iostream>
#include <string>

#include "include/stack_application.h"

int main(int argc, const char** argv) {
    StackApplication app;
    std::string output = app(argc, argv);
    std::cout << output;
  return 0;
}
