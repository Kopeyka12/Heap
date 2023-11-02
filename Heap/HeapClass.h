///@avtor Мирошин В.И.
///Класс Кучи
#include <iostream>
#include <vector>

class Heap {
private:
    std::vector<int> data; //вектор в котором будет храниться знавение кучи

public:
    //добавление узла в кучу и восстановить ее структуру 
    void insert(int value) {
        data.push_back(value);//добавляет значение в конец вектора 
        int currentIndex = data.size() - 1; //индекс вставляемого элемента
        int parentIndex = (currentIndex - 1) / 2;   //индекс родителя
        //ПОКА текущий элемент не станет корневым элементом (индекс 0) 
        //ИЛИ значение родительского элемента не станет больше или равно значению текущего элемента
        while (currentIndex > 0 && data[parentIndex] < data[currentIndex]) {
            //обменивает значение родительского элемента с текущим элементом с помощью функции
            //swap  простой способ обменять значения двух переменных, которые содержат одинаковые типы данных
            std::swap(data[parentIndex], data[currentIndex]);
            //обновляем значение для продолжения проверки свойства кучи вверх, сравнивая новый текущий элемент с его родителем
            currentIndex = parentIndex;
            parentIndex = (currentIndex - 1) / 2;
        }
    }
    //удаление максимального узла из кучи
    void remove() {
        //если у нас куча пустая выводим сообщение
        if (data.empty()) {
            std::cout << "Heap is empty." << std::endl;
            return;
        }
        //
        data[0] = data.back();//записываем значение последнего элемента в первый элемент вектора
        data.pop_back();//удаляет последний элемент вектора

        int currentIndex = 0;
        while (true) {
            //находим индекс левого ребенка текущего узла
            int leftChildIndex = 2 * currentIndex + 1;
            //находим индекс правого ребенка текущего узла.
            int rightChildIndex = 2 * currentIndex + 2;
            //проверяем, достигли ли мы конца вектора данных
            if (leftChildIndex >= data.size())
                break;
            //предполагаем, что максимальным дочерним узлом будет левый ребенок
            int maxChildIndex = leftChildIndex;
            //проверяем, существует ли правый ребенок и является ли его значение больше, чем у левого ребенка
            if (rightChildIndex < data.size() && data[rightChildIndex] > data[leftChildIndex])
                //Если это верно, то обновляем maxChildIndex
                maxChildIndex = rightChildIndex;
            //сравниваем значение текущего узла с максимальным дочерним узлом. 
            //Если значение текущего узла меньше, то мы должны поменять их местами, чтобы сохранить свойство кучи.
            if (data[currentIndex] < data[maxChildIndex]) {
                //выполняем обмен значениями текущего узла и максимального дочернего узла
                // с использованием функции std::swap
                //swap  простой способ обменять значения двух переменных, которые содержат одинаковые типы данных
                std::swap(data[currentIndex], data[maxChildIndex]);
                currentIndex = maxChildIndex;
            }
            else {
                break;
            }
        }
    }
    //выводим значение кучи
    void printHeap() {
        for (int value : data) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
};