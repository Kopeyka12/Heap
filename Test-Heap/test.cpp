#include "pch.h"
#include <cassert>
#include <sstream>

//тест пирамидной сортировки
TEST(TestHeap, TestPrint)
{
    int arr1[3] = { 50, 4, 45 };
    Heap<int> h(arr1, 3);

    std::ostringstream oss;
    std::streambuf* p_cout_streambuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());
    h.PrintHeap();

    std::cout.rdbuf(p_cout_streambuf);

    // тестируем наш метод
    assert(oss.str() == "4 50 45 ");


    int arr2[8] = {73, 65, 26, 23, 97, 6, 98, 70};
    Heap<int> h2(arr2, 8);

    std::ostringstream oss2;
    std::streambuf* p_cout_streambuf2 = std::cout.rdbuf();
    std::cout.rdbuf(oss2.rdbuf());
    h2.PrintHeap();

    std::cout.rdbuf(p_cout_streambuf2);

    // тестируем наш метод
    assert(oss2.str() == "6 23 26 65 97 73 98 70 ");
}


//тест пирамидной сортировки
TEST(TestHeap, TestHeapSort)
{
    int arr3[6] = { 144, 18, 138, 51, 72, 91 };
    Heap<int> h3(arr3, 6);

    std::ostringstream oss3;
    std::streambuf* p_cout_streambuf3 = std::cout.rdbuf();
    std::cout.rdbuf(oss3.rdbuf());
    HeapSort(arr3, 6);
    h3.PrintHeap();

    std::cout.rdbuf(p_cout_streambuf3);

    // тестируем наш метод 
    assert(oss3.str() == "144 138 91 72 51 18 ");


    int arr4[12] = { 80, 36, 42, 21, 98, 37, 63, 53, 89, 93, 27, 66 };
    Heap<int> h4(arr4, 12);

    std::ostringstream oss4;
    std::streambuf* p_cout_streambuf4 = std::cout.rdbuf();
    std::cout.rdbuf(oss4.rdbuf());
    HeapSort(arr4, 12);
    h4.PrintHeap();

    std::cout.rdbuf(p_cout_streambuf4);

    // тестируем наш метод
    assert(oss4.str() == "98 93 89 80 66 63 53 42 37 36 27 21 ");
}

//тест удаление узла
TEST(TestHeap, TestDelete)
{
    int arr1[3] = { 50, 4, 45 };
    Heap<int> h(arr1, 3);

    std::ostringstream oss;
    std::streambuf* p_cout_streambuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());
    
    h.Delete();
    h.PrintHeap();
    
    std::cout.rdbuf(p_cout_streambuf);

    // тестируем наш метод
    assert(oss.str() == "45 50 ");


    int arr2[8] = { 73, 65, 26, 23, 97, 6, 98, 70 };
    Heap<int> h2(arr2, 8);

    std::ostringstream oss2;
    std::streambuf* p_cout_streambuf2 = std::cout.rdbuf();
    std::cout.rdbuf(oss2.rdbuf());
    
    h2.Delete();
    h2.PrintHeap();

    std::cout.rdbuf(p_cout_streambuf2);

    // тестируем наш метод
    assert(oss2.str() == "23 65 26 70 97 73 98 ");
}