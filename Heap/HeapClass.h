///@avtor Мирошин В.И.
///Класс Кучи
#include <iostream>
#include <vector>

//класс Heap
template <class T>
class Heap
{
private:
    //std::vector<int> data; //вектор в котором будет храниться знавение кучи

    T* hlist;       //указатель на массив
    int inArray;    //параметр массива

    // максимальный и текущий размеры пирамиды
    int maxheapsize;
    int heapsize; // определяет конец списка

    // утилиты восстановления пирамидальной структуры
    void FilterDown(int i);
    void FilterUp(int i);

public:
    Heap(T arr[], int n);           //преобразовать массив в пирамиду
    T Delete();                     //метод удаление списка
    void Insert(const T& item);     //метод добавление жлемента в список
    void PrintHeap();               //вывод кучи

};

// утилита для восстановления пирамиды, начиная с индекса i,
    // подниматься вверх по дереву, переходя от предка к предку.
    // менять элементы местами, если сын меньше родителя
template <class T>
void Heap<T>::FilterUp(int i)
{
    int currentpos, parentpos;
    T target;
    // currentpos — индекс текущей позиции на пути предков.
    // target — вставляемое значение, для которого выбирается
    // правильная позиция в пирамиде
    currentpos = i;
    parentpos = (i - 1) / 2;
    target = hlist[i];

    // подниматься к корню по пути родителей
    while (currentpos != 0)
    {
        // если родитель <= target, то все в порядке,
        if (hlist[parentpos] <= target)
            break;
        else
            // поменять местами родителя с сыном и обновить индексы
            // для проверки следующего родителя
        {
            // переместить данные из родительской позиции в текущую.
            // назначить родительскую позицию текущей.
            // проверить следующего родителя
            hlist[currentpos] = hlist[parentpos];
            currentpos = parentpos;
            parentpos = (currentpos - 1) / 2;
        }
    }
    // правильная позиция найдена, поместить туда target
    hlist[currentpos] = target;
}



// утилита для восстановления пирамиды, начиная с индекса i,
// менять местами родителя и сына так, чтобы поддерево,
// начинающееся в узле i, было пирамидой
template <typename T>
void Heap<T>::FilterDown(int i)
{
    int currentpos, childpos;
    T target;

    // начать с узла i и присвоить его значение переменной target
    currentpos = i;
    target = hlist[i];

    // вычислить индекс левого сына и начать движение вниз по пути,
    // проходящему через меньших сыновей до конца списка
    childpos = 2 * i + 1;

    while (childpos < heapsize) // пока не конец списка
    {
        // индекс правого сына равен childpos+1. присвоить переменной
        // childpos индекс наименьшего из двух сыновей
        if ((childpos + 1 < heapsize) && (hlist[childpos + 1] <= hlist[childpos]))
            childpos = childpos + 1;

        // если родитель меньше сына, пирамида в порядке, выход
        if (target <= hlist[childpos])
            break;
        else
        {
            // переместить значение меньшего сына в родительский узел.
            // теперь позиция меньшего сына не занята
            hlist[currentpos] = hlist[childpos];
            // обновить индексы и продолжить сканирование
            currentpos = childpos;
            childpos = 2 * currentpos + 1;
        }
    }

    // поместить target в только что ставшую незанятой позицию
    hlist[currentpos] = target;
};

//печать кучи 
template <typename T>
void Heap<T>::PrintHeap()
{
    //цикл проходит по списку и выводит
    for (int i = 0; i < heapsize; i++)
    {
        std::cout << hlist[i] << " ";
    }
}

// удалить значение корневого элемента и обновить пирамиду
template <typename T>
T Heap<T>::Delete()
{
    T tempitem;

    // проверить, не пуста ли пирамида
    if (heapsize != 0) {

        // копировать корень в tempitem. заменить корень последним элементом
        // пирамиды и произвести декремент переменной heapsize
        tempitem = hlist[0];
        hlist[0] = hlist[heapsize - 1];
        heapsize--;
        // вызвать FilterDown для установки нового значения корня
        FilterDown(0);
        // возвратить исходное значение корня
        return tempitem;
    }
}
//добавлние элемента в кучу
template<class T>
void Heap<T>::Insert(const T& item)
{
    hlist[heapsize] = item;     //записать в конце пирамиды и увеличить heapsize
    FilterUp(heapsize);         //вызываем FilterUp
    heapsize++;
}

//сортировать массив по убыванию
template<class T>
void HeapSort(T A[], int n) {
    //конструктор, преобразующий А в пирамиду
    Heap<T> H(A, n);
    T elt;
    //цикл заполнения элементов А
    for (int i = n - 1; i >= 1; i--)
    {
        //исключать наименьший элемент из пирамиды и заполнить его в A[i]
        elt = H.Delete();
        A[i] = elt;
    }
}
//констурктор преобразует исходный массив в пирамиду
template <class T>
Heap<T>::Heap(T arr[], int n)
{
    int currenpos;

    //использовать n для установки размера пирамиды и максимального размера пирамиды
    //копировать массив arr в список пирамиды
    maxheapsize = n;
    heapsize = n;
    hlist = arr;

    //присвоить переменной currenpos индекс последнего родителя
    //вызвать FilterDown в цикле с индексами currenpos...0
    currenpos = (heapsize - 2) / 2;
    while (currenpos >= 0)
    {
        //выполнить условие пирамидальности для поддерева
        // с корнем hlist [currenpos]
        FilterDown(currenpos);
        currenpos--;
    }
    //присвоить inArray значение True
    inArray = 1;
}