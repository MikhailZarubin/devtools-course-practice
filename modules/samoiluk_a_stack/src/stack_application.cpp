// Copyright 2022 Zarubin Mikhail

#include "include/stack_application.h"
#include "include/stack.h"

#include <sstream>
#include <string>
#include <vector>

StackApplication::StackApplication() : m_message() {}

void StackApplication::help(const char* appname, const char* message) {
  std::ostringstream stream;
  stream << message << "This is a stack application.\n\n"
         << "Please provide arguments in the following format:\n\n"
         <<

      "  $ " << appname << " <value_or_values> "
         << "<operation> <operand>\n\n"
         <<

      "Where all arguments are integer numbers, "
         << "and <operation> is one of 'push', 'pop', 'getLast', 'getSize'.\n";

  m_message = stream.str();
}

bool isOnlyCharacter(const std::string& str) {
  return str.find_first_of("0123456789") == std::string::npos;
}

bool validateTypeOfArguments(int argc, const char** argv) {
  bool result = false;
  bool operationFinded = false;
  for (int i = 1; i < argc; ++i) {
    if (operationFinded) {
      if ((i + 1) == argc && !isOnlyCharacter(argv[i])) {
        result = true;
      }
    }

    if (isOnlyCharacter(argv[i])) {
      if (i + 2 == argc) {
        operationFinded = true;
      }
    }
  }

  return result;
}

bool StackApplication::validateArguments(int argc, const char** argv) {
  if (argc == 1) {
    help(argv[0]);
    return false;
  } else if (argc < 4) {
    help(argv[0], "ERROR: Should be at least 4 arguments.\n\n");
    return false;
  }

  if (!validateTypeOfArguments(argc, argv)) {
    help(argv[0]);
    return false;
  }

  return true;
}

double tryParseToInt(const char* arg) {
  int result = 0;

  try {
    result = std::stoi(arg);
  } catch (const std::invalid_argument& e) {
    throw std::string("ERROR: Cannot be cast to an integer!");
  } catch (const std::out_of_range& e) {
    throw std::string("ERROR : Number out of range!");
  }

  return result;
}

ConsoleOperation tryParseToOperation(const char* arg) {
  ConsoleOperation operation;

  if (strcmp(arg, "push") == 0) {
    operation = ConsoleOperation::push;
  } else if (strcmp(arg, "pop") == 0) {
    operation = ConsoleOperation::pop;
  } else if (strcmp(arg, "getLast") == 0) {
    operation = ConsoleOperation::getLast;
  } else if (strcmp(arg, "getSize") == 0) {
    operation = ConsoleOperation::getSize;
  } else {
    throw std::string("ERROR: Wrong operation!");
  }

  return operation;
}

std::string StackApplication::operator()(int argc, const char** argv) {
  if (!validateArguments(argc, argv)) {
    return m_message;
  }

  std::vector<int> vectorOfValues;
  ConsoleOperation operation;
  int operand;

  try {
    for (int i = 1; i < argc - 2; ++i) {
      vectorOfValues.push_back(tryParseToInt(argv[i]));
    }

    operation = tryParseToOperation(argv[argc - 2]);
    operand = tryParseToInt(argv[argc - 1]);
  } catch (const std::string& stringException) {
    return stringException;
  }

  std::ostringstream stream;
  Stack<int> stack(vectorOfValues);
  switch (operation) {
    case ConsoleOperation::push:
      stack.push(operand);
      stack.convertToString();
      stream << "stack: " << stack.convertToString();
      break;
    case ConsoleOperation::pop:
      stream << "popped element: " << std::to_string(stack.pop());
      break;
    case ConsoleOperation::getLast:
      stream << "last element: " << std::to_string(stack.getLast());
      break;
    case ConsoleOperation::getSize:
      stream << "stack size: " << std::to_string(stack.getSize());
  }

  m_message = stream.str();
  return m_message;
}
