////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Вопрос 1 - Понятие хэширования. Функция хэширования. Преимущества и недостатки хэш-
таблиц. Основные операции при работе с хэш-таблицами.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  
Пусть есть массив table из N элементов, каждая ячейка массива может хранить отдельный элемент и пусть есть механизм вычисления адреса, 
который по ключу элемента находит номер ячейки i в таблице table, в которую будет вставлен данный элемент. 
• Механизм вычисления адреса называется хэш-функцией. 
• Процесс вычисления адреса и помещения в таблицу называется хэшированием, а table - хэш таблицей, т.е. 
  h(k) = i 
  table[i] = NewItem  ,
где k - ключ элемента NewItem, a h(k) - хэш функция.

Преимущества хэш таблиц:
1) Операции поиска и вставки выполняются за константное время.
2) Данные хранятся в неупорядоченном виде

Недостатки хэш-таблиц:
1) Необходимость расширения массива. Массивы труднорасширяемые.
2) При заполнении таблицы может резко падать быстродействие.
3) Возможное возникновение случая, когда для различных ключей совпадают значения хэш-функций, т.е. h(k1)=h(k2), k1!=k2 . Данная ситуация называется "коллизия"

Основные операции при работе с хэш-таблицами:
1. Вставка (Insert) Добавление нового элемента в хэш таблицу. Элементу присваивается ключ, на основе которого вычисляется хэш-код и определяется местоположение элемента в таблице.

2. Поиск (Search): Поиск элемента по ключу в хэш таблице. Ключ также используется для вычисления хэш-кода и быстрого нахождения местоположения элемента.

3. Удаление (Delete): Удаление элемента из хэш таблицы по ключу. Поиск элемента по ключу происходит аналогично операции поиска.

4. Коллизии (Collision Handling): Разрешение коллизий, которые возникают, когда два или более ключей дают одинаковый хэш-код. 
  Существуют различные методы разрешения коллизий, такие как метод открытой адресации и метод цепочек.
  
5. Изменение размера (Resize): Изменение размера хэш таблицы для улучшения эффективности операций добавления, удаления и поиска.
  При переполнении таблицы ее размер может увеличиваться или уменьшаться.
  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Вопрос 2 Понятие коллизии. Примеры возникновения коллизий.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Возникновение случая, когда для различных ключей совпадают значения хэш-функций, т.е. h(k1)=h(k2), k1!=k2 . Данная ситуация называется "коллизия"

Пример возникновения коллизии:
Этап 1: Вставка ключа 3
Хэш-функция: 3 % 5 = 3
Ключ 3 помещается в индекс 3.
Этап 2: Вставка ключа 8
Хэш-функция: 8 % 5 = 3
Ключ 8 также хэшируется в индекс 3, где уже находится ключ 3. Возникает коллизия.

То же самое в виде кода:
...
    int hashFunction(int key) { //Хэш функция для примера
        return key % size;
    }
...
int main() { //Коллизия возникнет при использовании хэш-функции, описанной выше.
    HashTable hashTable(5);

    hashTable.insert(3); // Хэш-индекс 3
    hashTable.insert(8); // Хэш-индекс 3 (коллизия с 3)

    hashTable.display();

    return 0;
}  

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Вопрос 3. Разрешение коллизий методом открытой адресации.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  
