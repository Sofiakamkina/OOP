#include <iostream>
#include <gtest/gtest.h>
#include <locale.h>
//#include <gmock/gmock.h>

#include "Calculator.h"
#include "Exceptions.h"
int main(int argc, char * argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    /*try{
        Calculator calculator(argc,argv);
        calculator.run();
    }
    catch(exceptions::WrongNumberOfParamter &e)
    {
        std::cerr<<e.what();
    }
    return 0;*/
}
