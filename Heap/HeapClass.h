///@avtor ������� �.�.
///����� ����
#include <iostream>
#include <vector>

//����� Heap
template <class T>
class Heap
{
private:
    //std::vector<int> data; //������ � ������� ����� ��������� �������� ����

    T* hlist;       //��������� �� ������
    int inArray;    //�������� �������

    // ������������ � ������� ������� ��������
    int maxheapsize;
    int heapsize; // ���������� ����� ������

    // ������� �������������� ������������� ���������
    void FilterDown(int i);
    void FilterUp(int i);

public:
    Heap(T arr[], int n);           //������������� ������ � ��������
    T Delete();                     //����� �������� ������
    void Insert(const T& item);     //����� ���������� �������� � ������
    void PrintHeap();               //����� ����

};

// ������� ��� �������������� ��������, ������� � ������� i,
    // ����������� ����� �� ������, �������� �� ������ � ������.
    // ������ �������� �������, ���� ��� ������ ��������
template <class T>
void Heap<T>::FilterUp(int i)
{
    int currentpos, parentpos;
    T target;
    // currentpos � ������ ������� ������� �� ���� �������.
    // target � ����������� ��������, ��� �������� ����������
    // ���������� ������� � ��������
    currentpos = i;
    parentpos = (i - 1) / 2;
    target = hlist[i];

    // ����������� � ����� �� ���� ���������
    while (currentpos != 0)
    {
        // ���� �������� <= target, �� ��� � �������,
        if (hlist[parentpos] <= target)
            break;
        else
            // �������� ������� �������� � ����� � �������� �������
            // ��� �������� ���������� ��������
        {
            // ����������� ������ �� ������������ ������� � �������.
            // ��������� ������������ ������� �������.
            // ��������� ���������� ��������
            hlist[currentpos] = hlist[parentpos];
            currentpos = parentpos;
            parentpos = (currentpos - 1) / 2;
        }
    }
    // ���������� ������� �������, ��������� ���� target
    hlist[currentpos] = target;
}



// ������� ��� �������������� ��������, ������� � ������� i,
// ������ ������� �������� � ���� ���, ����� ���������,
// ������������ � ���� i, ���� ���������
template <typename T>
void Heap<T>::FilterDown(int i)
{
    int currentpos, childpos;
    T target;

    // ������ � ���� i � ��������� ��� �������� ���������� target
    currentpos = i;
    target = hlist[i];

    // ��������� ������ ������ ���� � ������ �������� ���� �� ����,
    // ����������� ����� ������� ������� �� ����� ������
    childpos = 2 * i + 1;

    while (childpos < heapsize) // ���� �� ����� ������
    {
        // ������ ������� ���� ����� childpos+1. ��������� ����������
        // childpos ������ ����������� �� ���� �������
        if ((childpos + 1 < heapsize) && (hlist[childpos + 1] <= hlist[childpos]))
            childpos = childpos + 1;

        // ���� �������� ������ ����, �������� � �������, �����
        if (target <= hlist[childpos])
            break;
        else
        {
            // ����������� �������� �������� ���� � ������������ ����.
            // ������ ������� �������� ���� �� ������
            hlist[currentpos] = hlist[childpos];
            // �������� ������� � ���������� ������������
            currentpos = childpos;
            childpos = 2 * currentpos + 1;
        }
    }

    // ��������� target � ������ ��� ������� ��������� �������
    hlist[currentpos] = target;
};

//������ ���� 
template <typename T>
void Heap<T>::PrintHeap()
{
    //���� �������� �� ������ � �������
    for (int i = 0; i < heapsize; i++)
    {
        std::cout << hlist[i] << " ";
    }
}

// ������� �������� ��������� �������� � �������� ��������
template <typename T>
T Heap<T>::Delete()
{
    T tempitem;

    // ���������, �� ����� �� ��������
    if (heapsize != 0) {

        // ���������� ������ � tempitem. �������� ������ ��������� ���������
        // �������� � ���������� ��������� ���������� heapsize
        tempitem = hlist[0];
        hlist[0] = hlist[heapsize - 1];
        heapsize--;
        // ������� FilterDown ��� ��������� ������ �������� �����
        FilterDown(0);
        // ���������� �������� �������� �����
        return tempitem;
    }
}
//��������� �������� � ����
template<class T>
void Heap<T>::Insert(const T& item)
{
    hlist[heapsize] = item;     //�������� � ����� �������� � ��������� heapsize
    FilterUp(heapsize);         //�������� FilterUp
    heapsize++;
}

//����������� ������ �� ��������
template<class T>
void HeapSort(T A[], int n) {
    //�����������, ������������� � � ��������
    Heap<T> H(A, n);
    T elt;
    //���� ���������� ��������� �
    for (int i = n - 1; i >= 1; i--)
    {
        //��������� ���������� ������� �� �������� � ��������� ��� � A[i]
        elt = H.Delete();
        A[i] = elt;
    }
}
//����������� ����������� �������� ������ � ��������
template <class T>
Heap<T>::Heap(T arr[], int n)
{
    int currenpos;

    //������������ n ��� ��������� ������� �������� � ������������� ������� ��������
    //���������� ������ arr � ������ ��������
    maxheapsize = n;
    heapsize = n;
    hlist = arr;

    //��������� ���������� currenpos ������ ���������� ��������
    //������� FilterDown � ����� � ��������� currenpos...0
    currenpos = (heapsize - 2) / 2;
    while (currenpos >= 0)
    {
        //��������� ������� ��������������� ��� ���������
        // � ������ hlist [currenpos]
        FilterDown(currenpos);
        currenpos--;
    }
    //��������� inArray �������� True
    inArray = 1;
}