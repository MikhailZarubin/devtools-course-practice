// Copyright 2022 Zarubin Mikhail

#ifndef MODULES_SAMOILUK_A_STACK_INCLUDE_STACK_APPLICATION_H_
#define MODULES_SAMOILUK_A_STACK_INCLUDE_STACK_APPLICATION_H_

#include <string>
#include <vector>

enum class ConsoleOperation { push, pop, getLast, getSize };

class StackApplication {
 public:
  StackApplication();

  std::string operator()(int argc, const char** argv);

 private:
  void help(const char* appname, const char* message = "");
  bool validateArguments(int argc, const char** argv);

  std::string m_message;
};

#endif  // MODULES_SAMOILUK_A_STACK_INCLUDE_STACK_APPLICATION_H_
