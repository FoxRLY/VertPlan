#include <cmath>
#include <stack>
#include <cctype>
#include <map>
#include <algorithm>
#include <sstream>
#include <string>
#include <iostream>
#include "translator.h"


double Calculator::getValue(std::map<std::string, double>& var_map, std::string& str)
{
    std::stack<double> value_stack;

    std::map<std::string, size_t> map; // карта весов операций
    map.insert({"!", 3});
    map.insert({"cot", 4});
    map.insert({"tan", 4});
    map.insert({"cos", 4});
    map.insert({"sin", 4});
    map.insert({"^", 4});
    map.insert({"*", 3});
    map.insert({"/", 3});
    map.insert({"+", 2});
    map.insert({"-", 2});
    std::stringstream str_stream(str);
    while(!str_stream.eof())
    {
        std::string buffer;
        str_stream >> buffer;
        if(buffer == "")
        {
            break;
        }
        bool digit_flag = true;
        if(map[buffer] != 0)
        {
            digit_flag = false;
        }
        if(digit_flag)
        {
            if(var_map.find(buffer) != var_map.end())
            {
                value_stack.push(var_map[buffer]);
            }
            else
            {
                double value;
                std::stringstream value_stream(buffer);
                value_stream >> value;
                value_stack.push(value);
            }
        }
        else
        {
            if(buffer == "+")
            {
                double b = value_stack.top();
                value_stack.pop();
                double a = value_stack.top();
                value_stack.pop();
                value_stack.push(a + b);
            }
            else if(buffer == "-")
            {
                double b = value_stack.top();
                value_stack.pop();
                double a = value_stack.top();
                value_stack.pop();
                value_stack.push(a - b);
            }
            else if(buffer == "*")
            {
                double b = value_stack.top();
                value_stack.pop();
                double a = value_stack.top();
                value_stack.pop();
                value_stack.push(a * b);
            }
            else if(buffer == "/")
            {
                double b = value_stack.top();
                value_stack.pop();
                double a = value_stack.top();
                value_stack.pop();
                value_stack.push(a / b);
            }
            else if(buffer == "^")
            {
                double b = value_stack.top();
                value_stack.pop();
                double a = value_stack.top();
                value_stack.pop();

                value_stack.push(std::pow(a,b));
            }
            else if(buffer == "sin")
            {
                double a = value_stack.top();
                value_stack.pop();
                value_stack.push(sin(a));
            }
            else if(buffer == "cos")
            {
                double a = value_stack.top();
                value_stack.pop();
                value_stack.push(cos(a));
            }
            else if(buffer == "tan")
            {
                double a = value_stack.top();
                value_stack.pop();
                value_stack.push(tan(a));
            }
            else if(buffer == "cot")
            {
                double a = value_stack.top();
                value_stack.pop();
                value_stack.push(1.0/tan(a));
            }
            else if(buffer == "!")
            {
                double a = value_stack.top();
                value_stack.pop();
                value_stack.push(-a);
            }
        }
    }
    return value_stack.top();
}

std::string Calculator::RPN(std::string str)
{
    for(int i = 0; i < str.length(); i++)           // Цикл разделения строки пробелами
    {
        if(!isalnum(str[i]) && ('.' != str[i]) && (' ' != str[i]))
        {
            str.insert(i, " ");
            str.insert(i+2, " ");
            i += 1;
        }
    }


    std::map<std::string, size_t> map; // карта весов операций
    map.insert({"!", 3});
    map.insert({"cot", 4});
    map.insert({"tan", 4});
    map.insert({"cos", 4});
    map.insert({"sin", 4});
    map.insert({"^", 4});
    map.insert({"*", 3});
    map.insert({"/", 3});
    map.insert({"+", 2});
    map.insert({"-", 2});
    map.insert({"(", 1});
    map.insert({")", 1});

    std::stack<std::string> stack;
    std::stringstream str_stream(str);
    std::string result_str;
    while(!str_stream.eof())
    {
        std::string chunk;
        str_stream >> chunk;
        if(map[chunk] != 0)
        {
            result_str += " ";
            if (")" == chunk)
            {
                while (stack.top() != "(")
                {
                    result_str += stack.top();
                    stack.pop();
                    result_str += " ";
                }
                stack.pop();
            }
            else if (stack.empty() || (map[stack.top()] < map[chunk]) || ("(" == chunk))
            {
                stack.push(chunk);
            }
            else
            {
                do
                {
                    result_str += stack.top();
                    result_str += " ";
                    stack.pop();
                } while (!(stack.empty() || (map[stack.top()] < map[chunk])));
                stack.push(chunk);
            }
        }
        else
        {
            result_str += chunk;
        }
    }
    while (!stack.empty())// остаток из стека добавляется в результ. строку
    {
        result_str += ' ';
        result_str += stack.top();
        result_str += ' ';
        stack.pop();
    }
    return result_str;
}

void Calculator::setExpression(const std::string& new_expression)
{
    expression = new_expression;
    RPNstring = RPN(new_expression);
}

std::string& Calculator::getExpression()
{
    return expression;
}

double Calculator::getResult(std::map<std::string, double>& var_map)
{
    if(RPNstring.empty())
    {
        return 0;
    }
    return getValue(var_map, RPNstring);
}

void Calculator::getResultRange(std::vector<double> &results, double start, double end, double step)
{
    std::map<std::string, double> x_range = {{"pi", 3.14159265},
                                             {"e", 2.71828182},
                                             {"x", 0}};
    for(double x = start; x <= end; x += step)
    {
        x_range["x"] = x;
        results.push_back(getResult(x_range));
    }
}

Calculator::Calculator()
{
    RPNstring = "";
    expression = "";
}
