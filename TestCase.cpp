#include "TestCase.hpp"
TestCase:: TestCase(string name,ostream& error){
    passedTests = 0;
    count = 0;
    failedTests =0;
    testName = name;
    err = error;
}

TestCase:: print(){

}