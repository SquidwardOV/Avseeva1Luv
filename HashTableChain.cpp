#include <iostream>
#include <list>
#include <vector>

class HashTable {
private:
    std::vector<std::list<int>> table;
    int size;

    // Хэш-функция для вычисления индекса
    int hashFunction(int key) {
        return key % size;
    }

public:
    // Конструктор
    HashTable(int size) {
        this->size = size;
        table.resize(size);
    }

    // Вставка элемента в хэш-таблицу
    void insert(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    // Удаление элемента из хэш-таблицы
    void remove(int key) {
        int index = hashFunction(key);
        table[index].remove(key);
    }

    // Поиск элемента в хэш-таблице
    bool search(int key) {
        int index = hashFunction(key);
        for (int item : table[index]) {
            if (item == key) {
                return true;
            }
        }
        return false;
    }

    // Вывод хэш-таблицы
    void display() {
        for (int i = 0; i < size; i++) {
            std::cout << "Index " << i << ":";
            for (int item : table[i]) {
                std::cout << " " << item;
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    HashTable hashTable(10);

    hashTable.insert(15);
    hashTable.insert(25);
    hashTable.insert(35);
    hashTable.insert(45);

    hashTable.display();

    std::cout << "Search 25: " << (hashTable.search(25) ? "Found" : "Not Found") << std::endl;
    std::cout << "Search 50: " << (hashTable.search(50) ? "Found" : "Not Found") << std::endl;

    hashTable.remove(25);
    hashTable.display();

    return 0;
}
