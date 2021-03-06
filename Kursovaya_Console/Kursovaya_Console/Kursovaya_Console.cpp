// подключение сторонних библиотек
#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <clocale>
#include <windows.h>
#include <malloc.h>

// коды определенных кнопок
#define ENTER 13
#define ESC 27
#define UP 72
#define DOWN 80
#define PAGEUP 73
#define PAGEDOWN 81
#define HOME 71
#define END 79

using namespace std;
using namespace System;
using namespace System::IO;

// шаблон структуры для исходных данных
struct z {
    char companyName[20]; // имя космической компании
    char rocketName[20]; // название ракеты
    int pricePerLaunch; // цена в миллионах $ за один запуск
    int successfulFlights; // количество успешных запусков
    int failureFlights; // количество неуспешных запусков
};

// шаблон структуры для вывода алфавитного списка
struct sp {
    char companyName[20]; // имя компании
    int successfulFlights; // сумма успешных полетов
    struct sp* sled; // ссылка на следующий элемент в списке
    struct sp* pred; // ссылка на предыдущий элемент в списке
} *spisok;

// список вопросов, пункты меню
char dan[7][70] = {
        "Среднее арифметическое успешных запусков?                      ",
        "Какая самая дешевая ракета для запуска?                        ",
        "Размах ряда цены?                                              ",
        "Есть ли одинаковая цена запуска у разных компаний?             ",
        "Алфавитный список всех компаний                                ",
        "Диаграмма. Процентное соотношение всех запусков каждой компании",
        "Выход                                                          "
};

int NC = 0; // количество строчек с данными в файле

// шаблоны функций
int menu(int);
void avrSuccessfulFlights(struct z*);
void cheapestRocket(struct z*);
void rangeInPrice(struct z*);
void samePrice(struct z*);
void alphabet(struct z*);
void vstavka(struct z*, char*);
void diagram(struct z*);

int main(array<System::String ^> ^args)
{
    char BlankLine[80]; memset(BlankLine, ' ', 65); BlankLine[65] = 0;
    char filePath[90] = "D:\\University\\прога\\курсач\\Kursovaya_Console\\Kursovaya_Console\\SpaceCompanies.dat"; // путь до файла, который необходимо прочесть
    int i, n;
    FILE* in;
    struct z* companies;

    // добавляем поддержку русского языка
    setlocale(LC_CTYPE, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Console::BufferHeight = Console::WindowHeight; // устанавливаем высоту окна
    Console::BufferWidth = Console::WindowWidth; // устанавливаем ширину окна
    Console::CursorVisible::set(false); // выключаем видимость курсора
    // установка цветов для фона и текста
    Console::ForegroundColor = ConsoleColor::Yellow;
    Console::BackgroundColor = ConsoleColor::Blue;
    Console::Clear();
    Console::BackgroundColor = ConsoleColor::Red;

    // открываем файл
    if ((in = fopen(filePath, "r")) == NULL)
    {
        // если файл не открыт
        printf("\nФайл %s не открыт!", filePath);
        _getch();
        exit(1);
    }

    // если файл открыт, то читаем количество строчек
    fscanf(in, "%d", &NC);
    companies = (struct z*)malloc(NC * sizeof(struct z)); // выделяем память для списка структур

    // читаем строчки
    for (i = 0; i < NC; i++)
        fscanf(in, "%s%s%d%d%d", 
            companies[i].companyName, 
            companies[i].rocketName, 
            &companies[i].pricePerLaunch, 
            &companies[i].successfulFlights, 
            &companies[i].failureFlights);

    // выводим заголовок таблицы
    Console::CursorTop = 8;
    Console::CursorLeft = 20;
    printf(" %-20s %-20s %-15s %-15s %-15s ", 
        "Компания", 
        "Ракета",
        "Стоимость в M$", 
        "Удачные пуски", 
        "Неудачные пуски");

    char separator[95];
    memset(separator, '-', 91);
    separator[91] = 0;
    Console::CursorTop = 9;
    Console::CursorLeft = 20;
    printf("%s", separator);

    // выводим данные из файла на экран
    for (i = 0; i < NC; i++)
    {
        Console::CursorTop = 10 + i;
        Console::CursorLeft = 20;
        printf(" %-20s %-20s %-15d %-15d %-15d ",
            companies[i].companyName,
            companies[i].rocketName,
            companies[i].pricePerLaunch,
            companies[i].successfulFlights,
            companies[i].failureFlights);
    }

    _getch();

    // рисуем пункты меню
    while (1)
    {
        // устанавливаем цвета для текста и фона
        Console::ForegroundColor = ConsoleColor::Red;
        Console::BackgroundColor = ConsoleColor::Blue;
        Console::Clear();
        Console::ForegroundColor = ConsoleColor::Yellow;
        Console::BackgroundColor = ConsoleColor::Red;
        Console::CursorLeft = 35;
        Console::CursorTop = 6;
        printf(BlankLine);

        // вывод вопросов как пунктов меню
        for (i = 0; i < 7; i++)
        {
            Console::CursorLeft = 35;
            Console::CursorTop = i + 7;
            printf(" %s ", dan[i]);
        }

        Console::CursorLeft = 35;
        Console::CursorTop = 14;
        printf(BlankLine);

        n = menu(7); // выбор вопроса в меню

        // отвечаем на вопросы, если пользователь нажал кнопку
        switch (n)
        {
            case 1: avrSuccessfulFlights(companies); break;
            case 2: cheapestRocket(companies); break;
            case 3: rangeInPrice(companies); break;
            case 4: samePrice(companies); break;
            case 5: alphabet(companies); break;
            case 6: diagram(companies); break;
            case 7: exit(0);
        }
    }

    return 0;
}

int menu(int n)
{
    int y1 = 0, y2 = n - 1; // выделяем пункт меню
    char c = 1;

    while (c != ESC) // если нажать ESC, то меню закрывается
    {
        switch (c)
        {
            case HOME: y2 = y1;  y1 = 0; break; // кнопка HOME - выбор первого пункта меню
            case END: y2 = y1;  y1 = n - 1; break; // кнопка END - выбор последнего пункта меню
            case PAGEDOWN: // кнопка PGDN и DOWN - выбор пункта ниже
            case DOWN: y2 = y1; y1++; break;
            case PAGEUP: // кнопка PGUP и UP - выбор пункта выше
            case UP: y2 = y1; y1--; break;
            case ENTER: return y1 + 1; // кнопка ENTER - выбор вопроса
        }

        if (y1 > n - 1) // условие, когда срабатывает выбор пункта ниже
        {
            y2 = n - 1; 
            y1 = 0;
        }
        if (y1 < 0) // условие, когда срабатывает выбор пункта выше
        {
            y2 = 0;
            y1 = n - 1;
        }

        // установка стилей для активного и неактивного пункта меню
        Console::ForegroundColor = ConsoleColor::White;
        Console::BackgroundColor = ConsoleColor::Green;
        Console::CursorLeft = 35;
        Console::CursorTop = y1 + 7;
        printf(" %s ", dan[y1]);

        Console::ForegroundColor = ConsoleColor::Yellow;
        Console::BackgroundColor = ConsoleColor::Red;
        Console::CursorLeft = 35;
        Console::CursorTop = y2 + 7;
        printf(" %s ", dan[y2]);
        c = _getch();
    }

    exit(0);
}

// среднее арифметическое успешных запусков
void avrSuccessfulFlights(struct z* company)
{
    int totalFlights = 0; // общая сумма всех успешных запусков

    for (int i = 0; i < NC; i++)
    {
        totalFlights += company[i].successfulFlights;
    }

    float avrg = (float) totalFlights / NC; // находим среднее арифметическое

    Console::ForegroundColor = ConsoleColor::Yellow;
    Console::BackgroundColor = ConsoleColor::Blue;
    Console::CursorLeft = 35;
    Console::CursorTop = 20;
    printf("Среднее арифметическое успешных запусков: %.3f", avrg); // вывод ответа

    _getch();
}

// какая самая дешевая ракета для запуска
void cheapestRocket(struct z* company)
{
    struct z cheapest = company[0]; // самая дешевая ракета (структура)
    int minPrice = cheapest.pricePerLaunch; // самая низкая цена запуска
    
    for (int i = 1; i < NC; i++)
    {
        if (company[i].pricePerLaunch < minPrice)
        {
            cheapest = company[i];
            minPrice = cheapest.pricePerLaunch;
        }
    }

    // вывод информации 
    Console::ForegroundColor = ConsoleColor::Yellow;
    Console::BackgroundColor = ConsoleColor::Blue;
    Console::CursorLeft = 35;
    Console::CursorTop = 20;
    printf("Самая дешевая ракета для запуска: %s", cheapest.rocketName);
    Console::CursorLeft = 35;
    Console::CursorTop = 21;
    printf("Компания: %s", cheapest.companyName);
    Console::CursorLeft = 35;
    Console::CursorTop = 22;
    printf("Стоимость запуска в миллионах $: %d", cheapest.pricePerLaunch);

    _getch();
}

// размах ряда цены
void rangeInPrice(struct z* company)
{
    int minPrice = company[0].pricePerLaunch; // минимальная цена
    int maxPrice = minPrice; // максимальная цена

    for (int i = 1; i < NC; i++)
    {
        if (company[i].pricePerLaunch < minPrice)
            minPrice = company[i].pricePerLaunch;

        if (company[i].pricePerLaunch > maxPrice)
            maxPrice = company[i].pricePerLaunch;
    }

    // вывод размаха ряда цены
    Console::ForegroundColor = ConsoleColor::Yellow;
    Console::BackgroundColor = ConsoleColor::Blue;
    Console::CursorLeft = 35;
    Console::CursorTop = 20;
    printf("Размах ряда цены в миллионах $: %d", (maxPrice - minPrice));

    _getch();
}

// есть ли одинаковая цена запуска у разных компаний (сложный вопрос)
void samePrice(struct z* company)
{
    bool isSamePrice = false;

    Console::ForegroundColor = ConsoleColor::Yellow;
    Console::BackgroundColor = ConsoleColor::Blue;

    for (int i = 0; i < NC; i++)
    {
        for (int j = i + 1; j < NC; j++)
        {
            if (company[i].pricePerLaunch == company[j].pricePerLaunch) { // совпадения есть
                isSamePrice = true;
                Console::CursorLeft = 35;
                Console::CursorTop = 20;
                printf("Совпадения есть!");
                Console::CursorLeft = 35;
                Console::CursorTop = 21;
                printf("%s (%dM$) = %s (%dM$)", company[i].rocketName, company[i].pricePerLaunch, company[j].rocketName, company[j].pricePerLaunch);
                break;
            }
        }
        if (isSamePrice) 
            break;
    }

    if (!isSamePrice) // совпадений нет
    {
        Console::CursorLeft = 35;
        Console::CursorTop = 20;
        printf("Совпадений нет!");
    }

    _getch();
}

// вывод алфавитного списка всех компаний
void alphabet(struct z* company)
{
    int i = 0;
    struct sp *nt, *z;
    Console::ForegroundColor = ConsoleColor::White;
    Console::BackgroundColor = ConsoleColor::Blue;
    Console::Clear();

    // сортируем список, если он еще не отсортирован
    if (!spisok)
        for (int i = 0; i < NC; i++)
            vstavka(company, company[i].companyName);

    Console::Clear();

    // вывод списка в прямом порядке (А->Я)
    Console::CursorLeft = 5;
    Console::CursorTop = 10;
    printf("Алфавитный список А->Я");
    Console::CursorLeft = 5;
    Console::CursorTop = 11;
    printf("----------------------------");

    for (nt = spisok; nt != 0; nt = nt->sled)
    {
        Console::CursorLeft = 5;
        Console::CursorTop = 12 + i;
        i++;
        printf("%-20s %-10d", nt->companyName, nt->successfulFlights);
    }

    // вывод списка в обратном порядке (Я->А)
    i = 0;
    Console::CursorLeft = 100;
    Console::CursorTop = 10;
    printf("Алфавитный список Я->А");
    Console::CursorLeft = 100;
    Console::CursorTop = 11;
    printf("----------------------------");

    for (z = 0, nt = spisok; nt != 0; z = nt, nt = nt->sled);
    for (nt = z; nt != 0; nt = nt->pred) 
    {
        Console::CursorLeft = 100;
        Console::CursorTop = 12 + i;
        i++;
        printf("%-20s %-10d", nt->companyName, nt->successfulFlights);
    }

    _getch();  
}

// вставка элемента в алфавитный список
void vstavka(struct z* company, char* companyName)
{
    struct sp *nov, *nt, *z = 0;

    for (nt = spisok; nt != 0 && strcmp(nt->companyName, companyName) < 0; z = nt, nt = nt->sled);

    if (nt && strcmp(nt->companyName, companyName) == 0) return;

    nov = (struct sp*)malloc(sizeof(struct sp));
    strcpy(nov->companyName, companyName);
    nov->sled = nt;
    nov->pred = z;
    nov->successfulFlights = 0;

    // суммируем число успешных полетов у одинаковых компаний (группируем)
    for (int i = 0; i < NC; i++)
        if (strcmp(company[i].companyName, companyName) == 0)
            nov->successfulFlights += company[i].successfulFlights;
    
    if (!z) spisok = nov;
    else z->sled = nov;
    if (nt) nt->pred = nov;
    return; 
}

// диаграмма, процентное соотношение всех запусков каждой компании
void diagram(struct z* company)
{
    struct sp *nt;
    int len, i, NColor;
    long flights = 0;

    // ищем общее количество успешных полетов всех компаний
    for (i = 0; i < NC; i++)
        flights = flights + company[i].successfulFlights;

    System::ConsoleColor Color;
    Console::ForegroundColor = ConsoleColor::White;
    Console::BackgroundColor = ConsoleColor::Blue;
    Console::Clear();
    Color = ConsoleColor::Black;
    NColor = 0;

    // сортируем список, если он еще не отсортирован
    if (!spisok)
        for (i = 0; i < NC; i++)
            vstavka(company, company[i].companyName);

    Console::ForegroundColor = ConsoleColor::White;
    Console::BackgroundColor = ConsoleColor::Blue;
    Console::CursorLeft = 5;
    Console::CursorTop = 10;
    printf("Компания");
    Console::CursorLeft = 25;
    Console::CursorTop = 10;
    printf("Соотношение удачных полетов в %%");

    // рисуем диаграмму
    for (nt = spisok, i = 0; nt != 0; nt = nt->sled, i+=2)
    {
        Console::ForegroundColor = ConsoleColor::White;
        Console::BackgroundColor = ConsoleColor::Blue;
        Console::CursorLeft = 5;
        Console::CursorTop = 12 + i;
        printf(nt->companyName);
        Console::CursorLeft = 25;
        printf("%3.1f%%", (nt->successfulFlights * 100. / flights));

        Console::BackgroundColor = ++Color;
        NColor++;
        Console::CursorLeft = 35;

        for (len = 0; len < (nt->successfulFlights * 100 / flights); len++)
            printf(" ");

        Console::BackgroundColor = ConsoleColor::White;
        for (len + 1; len < 100; len++)
            printf(" ");
        
        if (NColor == 14) // в диаграмме 14 цветов
        {
            Color = ConsoleColor::Black;
            NColor = 0;
        }
    }

    _getch();
    return;
}
