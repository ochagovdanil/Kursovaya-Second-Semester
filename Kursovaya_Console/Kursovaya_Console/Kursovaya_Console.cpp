#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <clocale>
#include <windows.h>
#include <malloc.h>

#define ENTER 13
#define ESC 27
#define UP 72
#define DOWN 80

using namespace std;
using namespace System;
using namespace System::IO;

struct z {
    char companyName[20];
    char rocketName[20];
    int pricePerLaunch;
    int successfulFlights;
    int failureFlights;
};

char dan[7][70] = {
       "Среднее арифметическое успешных запусков?                      ",
       "Какая самая дешевая ракета для запуска?                        ",
       "Список ракет, у которых число удачных запусков больше X        ",
       "Список ракет, запуск которых стоит больше XM$ и меньше XM$     ",
       "Алфавитный список всех компаний                                ",
       "Диаграмма. Процентное соотношение всех запусков каждой компании",
       "Выход                                                          "
};

int NC = 0;

int menu(int);
void avrSuccessfulFlights(struct z*);
void cheapestRocket(struct z*);
void successfulFlightsBiggerThan(struct z*);
void costPerLaunchBiggerAndLessThan(struct z*);
void alphabet(struct z*);
void diagram(struct z*);

int main(array<System::String ^> ^args)
{
    // Some variables
    char BlankLine[80]; memset(BlankLine, ' ', 65); BlankLine[65] = 0;
    char filePath[90] = "D:\\University\\прога\\курсач\\Kursovaya_Console\\Kursovaya_Console\\SpaceCompanies.dat";
    int i, n;
    FILE* in;
    struct z* companies;

    // Add Russian support
    setlocale(LC_CTYPE, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Add styles
    Console::BufferHeight = Console::WindowHeight;
    Console::BufferWidth = Console::WindowWidth;
    Console::CursorVisible::set(false);
    Console::ForegroundColor = ConsoleColor::Yellow;
    Console::BackgroundColor = ConsoleColor::Blue;
    Console::Clear();
    Console::BackgroundColor = ConsoleColor::Red;

    // Open data file
    if ((in = fopen(filePath, "r")) == NULL)
    {
        printf("\nФайл %s не открыт!", filePath);
        _getch();
        exit(1);
    }

    // Read the file
    fscanf(in, "%d", &NC);
    companies = (struct z*)malloc(NC * sizeof(struct z));

    for (i = 0; i < NC; i++)
        fscanf(in, "%s%s%d%d%d", 
            companies[i].companyName, 
            companies[i].rocketName, 
            &companies[i].pricePerLaunch, 
            &companies[i].successfulFlights, 
            &companies[i].failureFlights);

    // Outputting the file
    printf("\n%-20s %-20s %-15s %-15s %-15s", 
        "Компания", 
        "Ракета",
        "Стоимость в M$", 
        "Удачные пуски", 
        "Неудачные пуски");

    char separator[90];
    memset(separator, '-', 89);
    separator[89] = 0;
    printf("\n%s", separator);

    for (i = 0; i < NC; i++)
        printf("\n%-20s %-20s %-15d %-15d %-15d", 
            companies[i].companyName,
            companies[i].rocketName,
            companies[i].pricePerLaunch,
            companies[i].successfulFlights,
            companies[i].failureFlights);

    _getch();

    // Dispaly menu
    while (1)
    {
        Console::ForegroundColor = ConsoleColor::Red;
        Console::BackgroundColor = ConsoleColor::Blue;
        Console::Clear();
        Console::ForegroundColor = ConsoleColor::Yellow;
        Console::BackgroundColor = ConsoleColor::Red;
        Console::CursorLeft = 25;
        Console::CursorTop = 4;
        printf(BlankLine);

        for (i = 0; i < 7; i++)
        {
            Console::CursorLeft = 25;
            Console::CursorTop = i + 5;
            printf(" %s ", dan[i]);
        }

        Console::CursorLeft = 25;
        Console::CursorTop = 12;
        printf(BlankLine);

        n = menu(7); // Select current item in menu

        switch (n)
        {
            case 1: avrSuccessfulFlights(companies); break;
            case 2: cheapestRocket(companies); break;
            case 3: successfulFlightsBiggerThan(companies); break;
            case 4: costPerLaunchBiggerAndLessThan(companies); break;
            case 5: alphabet(companies); break;
            case 6: diagram(companies); break;
            case 7: exit(0);
        }
    }

    return 0;
}

int menu(int n)
{
    int y1 = 0, y2 = n - 1;
    char c = 1;
    while (c != ESC)
    {
        switch (c)
        {
            case DOWN:y2 = y1; y1++; break;
            case UP: y2 = y1; y1--; break;
            case ENTER: return y1 + 1;
        }

        if (y1 > n - 1)
        {
            y2 = n - 1; 
            y1 = 0;
        }
        if (y1 < 0)
        {
            y2 = 0;
            y1 = n - 1;
        }

        Console::ForegroundColor = ConsoleColor::White;
        Console::BackgroundColor = ConsoleColor::Green;
        Console::CursorLeft = 25;
        Console::CursorTop = y1 + 5;
        printf(" %s ", dan[y1]);

        Console::ForegroundColor = ConsoleColor::Yellow;
        Console::BackgroundColor = ConsoleColor::Red;
        Console::CursorLeft = 25;
        Console::CursorTop = y2 + 5;
        printf(" %s ", dan[y2]);
        c = _getch();
    }

    exit(0);
}

void avrSuccessfulFlights(struct z* company)
{
    int totalFlights = 0;

    for (int i = 0; i < NC; i++)
    {
        totalFlights += company[i].successfulFlights;
    }

    float avrg = (float) totalFlights / NC;

    Console::ForegroundColor = ConsoleColor::Yellow;
    Console::BackgroundColor = ConsoleColor::Blue;
    Console::CursorLeft = 25;
    Console::CursorTop = 15;
    printf("Среднее арифметическое успешных запусков: %.3f", avrg);

    _getch();
}

void cheapestRocket(struct z* company)
{
    struct z cheapest = company[0];
    int minPrice = cheapest.pricePerLaunch;
    
    for (int i = 1; i < NC; i++)
    {
        if (company[i].pricePerLaunch < minPrice)
        {
            cheapest = company[i];
            minPrice = cheapest.pricePerLaunch;
        }
    }

    Console::ForegroundColor = ConsoleColor::Yellow;
    Console::BackgroundColor = ConsoleColor::Blue;
    Console::CursorLeft = 25;
    Console::CursorTop = 15;
    printf("Самая дешевая ракета для запуска: %s", cheapest.rocketName);
    Console::CursorLeft = 25;
    Console::CursorTop = 16;
    printf("Компания: %s", cheapest.companyName);
    Console::CursorLeft = 25;
    Console::CursorTop = 17;
    printf("Стоимость запуска в миллионах $: %d", cheapest.pricePerLaunch);

    _getch();
}

void successfulFlightsBiggerThan(struct z* company)
{
    _getch();
}

void costPerLaunchBiggerAndLessThan(struct z* company)
{
    _getch();
}

void alphabet(struct z* company)
{
    _getch();
}

void diagram(struct z* company)
{
    _getch();
}
