#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdio>
#include <Windows.h>

using namespace std;

#define MAX_TITLE 100
#define MAX_BOOKS 1000

struct Book {
    char title[MAX_TITLE]; 
    char author[MAX_TITLE]; 
    int year; 
};

Book library[MAX_BOOKS];
int bookCount = 0;

void AddBook(){
    if (bookCount >= MAX_BOOKS){
        cout << "Помилка: Бібліотека переповнена!" << endl;
        return;
    }

    cin.ignore(); 
    cout << "Введіть назву книги: ";
    cin.getline(library[bookCount].title, MAX_TITLE);

    cout << "Введіть автора: ";
    cin.getline(library[bookCount].author, MAX_TITLE);

    cout << "Введіть рік видання: ";
    cin >> library[bookCount].year;

    bookCount++;
    cout << "Книгу додано успішно!" << endl;
}

void PrintBooks(){
    if (bookCount == 0){
        cout << "Бібліотека порожня." << endl;
        return;
    }

    cout << "\nСписок всіх книг:" << endl;
    for (int i = 0; i < bookCount; i++){
        cout << i + 1 << ". " << library[i].title << " | " << library[i].author << " | " << library[i].year << endl;
    }
    
    cout << endl;
}

void DeleteBook(){
    int index;
    cout << "Введіть номер книги для видалення: ";
    cin >> index;
    index--; 

    if (index < 0 || index >= bookCount){
        cout << "Помилка: Невірний індекс!" << endl;
        return;
    }

    for (int i = index; i < bookCount - 1; i++){
        library[i] = library[i + 1];
    }

    bookCount--;
    cout << "Книгу видалено." << endl;
}

void FindBook(){
    char search[MAX_TITLE];
    cin.ignore();
    cout << "Введіть назву для пошуку: ";
    cin.getline(search, MAX_TITLE);

    bool found = false;
    for (int i = 0; i < bookCount; i++){
        if (strcmp(library[i].title, search) == 0){
            cout << "Знайдено: "<< library[i].title << " [" << library[i].author << "] " << library[i].year << endl;
            found = true;
        }
    }
    if (!found){
        cout << "Книгу не знайдено." << endl;
    }
}

void SortBooks(){
    int choice;
    cout << "1. Сортувати за назвою\n2. Сортувати за роком\nВиберіть варіант: ";
    cin >> choice;

    for (int i = 0; i < bookCount - 1; i++){
        for (int j = 0; j < bookCount - i - 1; j++){
            bool needSwap = false;

            if (choice == 1){
                if (strcmp(library[j].title, library[j + 1].title) > 0)
                    needSwap = true;
            }
            else if (choice == 2){
                if (library[j].year > library[j + 1].year)
                    needSwap = true;
            }

            if (needSwap){
                Book temp = library[j];
                library[j] = library[j + 1];
                library[j + 1] = temp;
            }
        }
    }
    cout << "Сортування завершено!" << endl;
}

void SaveToFile(){
    FILE* f = fopen("library.dat", "wb");
    if (f == NULL){
        cout << "Помилка відкриття файлу для запису!" << endl;
        return;
    }

    fwrite(&bookCount, sizeof(int), 1, f); 
    fwrite(library, sizeof(Book), bookCount, f); 

    fclose(f);
    cout << "Дані успішно збережені у файл library.dat" << endl;
}

void LoadFromFile(){
    FILE* f = fopen("library.dat", "rb");
    if (f == NULL){
        cout << "Файл не знайдено!" << endl;
        return;
    }

    fread(&bookCount, sizeof(int), 1, f);
    fread(library, sizeof(Book), bookCount, f);

    fclose(f);
    cout << "Дані завантажені! Кількість книг: " << bookCount << endl;
}

int main(){

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int choice;

    do{
        cout << "1. Додати книжку" << endl;
        cout << "2. Видалити книжку" << endl;
        cout << "3. Знайти книжку" << endl;
        cout << "4. Вивести книжки" << endl;
        cout << "5. Відсортувати книжки" << endl;
        cout << "6. Зберегти у файл" << endl;
        cout << "7. Завантажити з файла" << endl;
        cout << "8. Вихід" << endl;
        cout << "Я обираю: ";

        cin >> choice;

        switch (choice){
        case 1: AddBook();
            break;
        case 2: 
            DeleteBook();
            break;
        case 3: 
            FindBook();
            break;
        case 4: 
            PrintBooks();
            break;
        case 5: 
            SortBooks();
            break;
        case 6: 
            SaveToFile();
            break;
        case 7: 
            LoadFromFile();
            break;
        case 8: 
            cout << "Завершення роботи" << endl; break;
        default: 
            cout << "Неправильне число!" << endl;
        }

    } 
    while (choice != 8);

    return 0;
}