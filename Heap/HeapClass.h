///@avtor ������� �.�.
///����� ����
#include <iostream>
#include <vector>

class Heap {
private:
    std::vector<int> data; //������ � ������� ����� ��������� �������� ����

public:
    //���������� ���� � ���� � ������������ �� ��������� 
    void insert(int value) {
        data.push_back(value);//��������� �������� � ����� ������� 
        int currentIndex = data.size() - 1; //������ ������������ ��������
        int parentIndex = (currentIndex - 1) / 2;   //������ ��������
        //���� ������� ������� �� ������ �������� ��������� (������ 0) 
        //��� �������� ������������� �������� �� ������ ������ ��� ����� �������� �������� ��������
        while (currentIndex > 0 && data[parentIndex] < data[currentIndex]) {
            //���������� �������� ������������� �������� � ������� ��������� � ������� �������
            //swap  ������� ������ �������� �������� ���� ����������, ������� �������� ���������� ���� ������
            std::swap(data[parentIndex], data[currentIndex]);
            //��������� �������� ��� ����������� �������� �������� ���� �����, ��������� ����� ������� ������� � ��� ���������
            currentIndex = parentIndex;
            parentIndex = (currentIndex - 1) / 2;
        }
    }
    //�������� ������������� ���� �� ����
    void remove() {
        //���� � ��� ���� ������ ������� ���������
        if (data.empty()) {
            std::cout << "Heap is empty." << std::endl;
            return;
        }
        //
        data[0] = data.back();//���������� �������� ���������� �������� � ������ ������� �������
        data.pop_back();//������� ��������� ������� �������

        int currentIndex = 0;
        while (true) {
            //������� ������ ������ ������� �������� ����
            int leftChildIndex = 2 * currentIndex + 1;
            //������� ������ ������� ������� �������� ����.
            int rightChildIndex = 2 * currentIndex + 2;
            //���������, �������� �� �� ����� ������� ������
            if (leftChildIndex >= data.size())
                break;
            //������������, ��� ������������ �������� ����� ����� ����� �������
            int maxChildIndex = leftChildIndex;
            //���������, ���������� �� ������ ������� � �������� �� ��� �������� ������, ��� � ������ �������
            if (rightChildIndex < data.size() && data[rightChildIndex] > data[leftChildIndex])
                //���� ��� �����, �� ��������� maxChildIndex
                maxChildIndex = rightChildIndex;
            //���������� �������� �������� ���� � ������������ �������� �����. 
            //���� �������� �������� ���� ������, �� �� ������ �������� �� �������, ����� ��������� �������� ����.
            if (data[currentIndex] < data[maxChildIndex]) {
                //��������� ����� ���������� �������� ���� � ������������� ��������� ����
                // � �������������� ������� std::swap
                //swap  ������� ������ �������� �������� ���� ����������, ������� �������� ���������� ���� ������
                std::swap(data[currentIndex], data[maxChildIndex]);
                currentIndex = maxChildIndex;
            }
            else {
                break;
            }
        }
    }
    //������� �������� ����
    void printHeap() {
        for (int value : data) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
};