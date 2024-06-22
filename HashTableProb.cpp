#include <iostream>
#include <vector>

class HashTable {
private:
    std::vector<int> table;
   
    int size;

    enum State {
        FREE,
        RESERVED,
        DELETED
    };

    std::vector<State> states;

    // Хэш-функция для вычисления индекса
    int hashFunction(int key) {
        return key % size;
    }

public:
    // Конструктор
    HashTable(int size) {
        this->size = size;
        table.resize(size, -1); 
        states.resize(size, FREE); 
    }

    // Вставка элемента в хэш-таблицу
    void insert(int key) {
        int index = hashFunction(key);
        int originalIndex = index;
        while (states[index] == RESERVED) {
            index = ((index + 1)*const) % size;
            if (index == originalIndex) {
                std::cerr << "Hash table is full" << std::endl;
                return;
            }
        }
        table[index] = key;
        states[index] = RESERVED;
    }

    // Удаление элемента из хэш-таблицы
    void remove(int key) {
        int index = hashFunction(key);
        int originalIndex = index;
        while (states[index] != FREE) {
            if (states[index] == RESERVED && table[index] == key) {
                states[index] = DELETED;
                return;
            }
            index = (index + 1) % size;
            if (index == originalIndex) {
                std::cerr << "Element not found" << std::endl;
                return;
            }
        }
        std::cerr << "Element not found" << std::endl;
    }

    // Поиск элемента в хэш-таблице
    bool search(int key) {
        int index = hashFunction(key);
        int originalIndex = index;
        while (states[index] != FREE) {
            if (states[index] == RESERVED && table[index] == key) {
                return true;
            }
            index = (index + 1) % size;
            if (index == originalIndex) {
                return false;
            }
        }
        return false;
    }

    // Вывод хэш-таблицы
    void display() {
        for (int i = 0; i < size; i++) {
            if (states[i] == FREE) {
                std::cout << "Index " << i << ": FREE" << std::endl;
            }
            else if (states[i] == DELETED) {
                std::cout << "Index " << i << ": DELETED" << std::endl;
            }
            else {
                std::cout << "Index " << i << ": " << table[i] << std::endl;
            }
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
