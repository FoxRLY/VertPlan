#pragma once
#include <stack>
#include <map>
#include <vector>
#include <string>

class Calculator
{
private:
    std::string expression;
    std::string RPNstring;
    static double getValue(std::map<std::string, double>& var_map, std::string& str);
    static std::string RPN(std::string str);
public:
    Calculator();
    void setExpression(const std::string& new_expression);
    std::string& getExpression();
    double getResult(std::map<std::string, double>& var_map);
    void getResultRange(std::vector<double>& results, double start, double end, double step);
    double getSimpleResult(const std::string& expression);
};