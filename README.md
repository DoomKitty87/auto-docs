# auto-docs
Automatic documentation for any code, following simple formatting guidelines. To get documentation for your code, just run main.cpp in the directory it is in and provide the file name.

Compile and run to use.

Formatting:
All lines to be read must start with comments.

Functions should be formatted as:
//F{function_name}:{parameters}:{description}
//{param_name}:{description}

//Ffunction:2:processes two parameters into nothing
//:param1:the first input, gets made into nothing
//:param2:the second input, gets made into nothing
(F for function, function is the name, and 2 for number of parameters, then description.)
void function(type1 param1, type2 param2) {
  return;
}

Add footnotes as:
//Ncontent of footnote