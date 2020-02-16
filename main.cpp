#include <iostream>
using namespace std;

//Тип книга
struct Book { //структура
    string name;
    string autor;
    string price;
};

//Класс библиотека
class Lib { //класс
public:
    Lib(); //конструктор
    ~Lib(); //диструктор
    void book_list(); //Вывод списка книг
    void book_add(); //Вывод добовления книги

private:
    int* count_books = new int; //счетчик количества книг
    Book* books = new Book[10]; //массив книг
};

//Конструктор
Lib::Lib() {
    *count_books = 0;
}

//Диструктор
Lib::~Lib(){
    delete count_books;
    delete[] books;
}

//Метод вывода списка книг
void Lib::book_list() {
    for(int count_book = 0; count_book < 10; count_book++){
        if (books[count_book].name == ""){
            continue;
        }
        cout << "Наименование книги: \t\t" << books[count_book].name << endl
             << "Автор: \t\t" << books[count_book].autor << endl
             << "Цена: \t\t" << books[count_book].price << endl
             << endl;
    }
}

//Метод добавление книги
void Lib::book_add() {
    Book book;
    cout << "Введите наименование книги: ";
    cin >> book.name;
    cout << "Введите автора: ";
    cin >> book.autor;
    cout << "Введите цену: ";
    cin >> book.price;
    books[*count_books] = book;
    *count_books += 1;
}

int main(){
    char com = ' ';
    Lib* lib = new Lib();
    cout << "Бибилотека!";
    for(;com != '4';){
        cout << "Меню\n1.-Список книг\n2.-Добавление книги\n3.-Удаление книги\n4.-Выход\n>> ";
        cin >> com;
        if (com == '1'){
            cout << "Список книг: \n";
            lib->book_list();
        } else if (com == '2'){
            cout << "Добавление книги: \n";
            lib->book_add();
        } else if (com == '3'){
            cout << "Удаление книги: \n";
        } else if (com == '4'){
            //Exit app
            cout << "Exit...";
            continue;
        } else {
            cout << "Команда не найдена! Повторите ввод...";
        }
    }
    delete lib;
    return 0;
}
