#include "gtest/gtest.h"
#include <fstream>
#include <string>
#include <vector>
#include "../parser.h"
#include "../Iprocessor.h"
#include "../OperatorFactory.h"
TEST(input_tests,one_parameter)
{
    std::string str= "print";
    Parser parser;
    std::vector<string> result = parser.parser(str);
    std::vector<string> rightResult;
    rightResult.push_back("print");
    rightResult.push_back("");
    rightResult.push_back("");
    ASSERT_EQ(result,rightResult);
}

TEST(input_tests,two_parameter)
{
    std::string str= "push 4";
    Parser parser;
    std::vector<string> result = parser.parser(str);
    std::vector<string> rightResult;
    rightResult.push_back("push");
    rightResult.push_back("4");
    rightResult.push_back("");
    ASSERT_EQ(result,rightResult);
}

TEST(input_tests,three_parameter)
{
    std::string str= "define a 5";
    Parser parser;
    std::vector<string> result = parser.parser(str);
    std::vector<string> rightResult;
    rightResult.push_back("define");
    rightResult.push_back("a");
    rightResult.push_back("5");
    ASSERT_EQ(result,rightResult);
}

TEST(test_push, test1)
{
    std::string str= "push 5";
    Context a;
    Iprocessor iprocessor;
    iprocessor.calculate(str,&a);
    ASSERT_EQ(a.numbers.top().getValue(), 5.0);

    str = "push 4545.45";
    iprocessor.calculate(str, &a);
    ASSERT_EQ(a.numbers.top().getValue(), 4545.45);

    str = "push kfork";
    ASSERT_THROW(iprocessor.calculate(str,&a), exceptions::InvalidOperands);
}

TEST(test_pop, test1)
{
    std::string str= "push 12430304";
    Context a;
    Iprocessor iprocessor;
    iprocessor.calculate(str,&a);
    str = "push 4454.23434";
    iprocessor.calculate(str,&a);

    str = "pop";
    iprocessor.calculate(str,&a);
    ASSERT_EQ(a.numbers.top().getValue(), 12430304);
}


TEST(math, plus)
{
    Context a;
    Iprocessor iprocessor;
    std::string str= "push 2";
    iprocessor.calculate(str,&a);
    str = "push 10.5";
    iprocessor.calculate(str,&a);
    str = "+";
    iprocessor.calculate(str,&a);
    ASSERT_EQ(a.numbers.top().getValue(), 12.5);
}

TEST(math, minus)
{
    Context a;
    Iprocessor iprocessor;
    std::string str= "push 2";
    iprocessor.calculate(str,&a);
    str = "push 10.5";
    iprocessor.calculate(str,&a);
    str = "-";
    iprocessor.calculate(str,&a);
    ASSERT_EQ(a.numbers.top().getValue(), 8.5);
}

TEST(math, mult)
{
    Context a;
    Iprocessor iprocessor;
    std::string str= "push 2";
    iprocessor.calculate(str,&a);
    str = "push 10.5";
    iprocessor.calculate(str,&a);
    str = "*";
    iprocessor.calculate(str,&a);
    ASSERT_EQ(a.numbers.top().getValue(), 21);
}

TEST(math, div)
{
    Context a;
    Iprocessor iprocessor;
    std::string str= "push 2";
    iprocessor.calculate(str,&a);
    str = "push 10.5";
    iprocessor.calculate(str,&a);
    str = "/";
    iprocessor.calculate(str,&a);
    ASSERT_EQ(a.numbers.top().getValue(), 5.25);
    str = "push 0";
    iprocessor.calculate(str,&a);

    str = "push 34";
    iprocessor.calculate(str,&a);
    str = "/";
    ASSERT_THROW(iprocessor.calculate(str,&a), exceptions::DivizionByZero);
}

TEST(math, sqrt)
{
    Context a;
    Iprocessor iprocessor;
    std::string str= "push 4";
    iprocessor.calculate(str,&a);
    str = "sqrt";
    iprocessor.calculate(str,&a);
    ASSERT_EQ(a.numbers.top().getValue(), 2);
}

TEST(math, define)
{
    Context a;
    Iprocessor iprocessor;
    std::string str= "define abba 4";
    iprocessor.calculate(str,&a);
    str = "push abba";
    iprocessor.calculate(str,&a);
    ASSERT_EQ(a.numbers.top().getValue(), 4);

    str= "define qwer 56.6";
    iprocessor.calculate(str,&a);
    str = "push qwer";
    iprocessor.calculate(str,&a);
    str = "+";
    iprocessor.calculate(str,&a);
    ASSERT_EQ(a.numbers.top().getValue(), 60.6);

    str = "define 34324 klklt";
    ASSERT_THROW(iprocessor.calculate(str,&a), exceptions::InvalidOperands);

    str = "define gkrl klgkrl";
    ASSERT_THROW(iprocessor.calculate(str,&a), exceptions::InvalidOperands);
}
