#include "pch.h"
#include <cassert>
#include <sstream>


TEST(TestList, TestPrint)
{
    int arr1[10] = { 50, 4, 45 };
    Heap<int> h(arr1, 3);

    std::ostringstream oss;
    std::streambuf* p_cout_streambuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());
    HeapSort(arr1, 3);
    h.PrintHeap();

    std::cout.rdbuf(p_cout_streambuf);

    // тестируем наш метод
    assert(oss.str() == "50 45 4 ");
}


//TEST(TestCaseName, TestName) {
//  EXPECT_EQ(1, 1);
//  EXPECT_TRUE(true);
//}