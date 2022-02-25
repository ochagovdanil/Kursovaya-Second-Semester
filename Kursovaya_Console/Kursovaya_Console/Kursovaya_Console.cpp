﻿#include "pch.h"
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
#define PAGEUP 73
#define PAGEDOWN 81
#define HOME 71
#define END 79

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

struct sp {
    char companyName[20];
    int successfulFlights;
    struct sp* sled;
} *spisok;

char dan[7][70] = {
        "Среднее арифметическое успешных запусков?                      ",
        "Какая самая дешевая ракета для запуска?                        ",
        "Список ракет, у которых число удачных запусков больше X        ",
        "Есть ли одинаковая цена запуска у разных компаний?             ",
        "Алфавитный список всех компаний                                ",
        "Диаграмма. Процентное соотношение всех запусков каждой компании",
        "Выход                                                          "
};

int NC = 0;

int menu(int);
void avrSuccessfulFlights(struct z*);
void cheapestRocket(struct z*);
void successfulFlightsBiggerThan(struct z*);
void samePrice(struct z*);
void alphabet(struct z*);
void vstavka(struct z*, char*);
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
    Console::CursorTop = 6;
    Console::CursorLeft = 15;
    printf("%-20s %-20s %-15s %-15s %-15s", 
        "Компания", 
        "Ракета",
        "Стоимость в M$", 
        "Удачные пуски", 
        "Неудачные пуски");

    char separator[90];
    memset(separator, '-', 89);
    separator[89] = 0;
    Console::CursorTop = 7;
    Console::CursorLeft = 15;
    printf("%s", separator);

    for (i = 0; i < NC; i++)
    {
        Console::CursorTop = 8 + i;
        Console::CursorLeft = 15;
        printf("%-20s %-20s %-15d %-15d %-15d",
            companies[i].companyName,
            companies[i].rocketName,
            companies[i].pricePerLaunch,
            companies[i].successfulFlights,
            companies[i].failureFlights);
    }

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
    int y1 = 0, y2 = n - 1;
    char c = 1;

    while (c != ESC)
    {
        switch (c)
        {
            case HOME: y2 = y1;  y1 = 0; break;
            case END: y2 = y1;  y1 = n - 1; break;
            case PAGEDOWN:
            case DOWN: y2 = y1; y1++; break;
            case PAGEUP:
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
    int biggerThan;
    int counter = 0;

    Console::ForegroundColor = ConsoleColor::Yellow;
    Console::BackgroundColor = ConsoleColor::Blue;
    Console::CursorLeft = 25;
    Console::CursorTop = 15;
    printf("Список ракет, у которых число удачных полетов больше чем: ");
    scanf("%d", &biggerThan);

    for (int i = 0; i < NC; i++)
    {
        if (company[i].successfulFlights > biggerThan)
        {
            counter++;
            Console::CursorLeft = 25;
            Console::CursorTop = 15 + counter;
            printf(company[i].rocketName);
        }
    }

    Console::CursorLeft = 25;
    Console::CursorTop = 15 + counter + 1;
    printf("Всего: %d", counter);

    _getch();
}

void samePrice(struct z* company)
{
    bool isSamePrice = false;

    for (int i = 0; i < NC; i++)
    {
        for (int j = i + 1; j < NC; j++)
        {
            if (company[i].pricePerLaunch == company[j].pricePerLaunch) {
                isSamePrice = true;
                Console::CursorLeft = 25;
                Console::CursorTop = 15;
                printf("Совпадения есть!");
                Console::CursorLeft = 25;
                Console::CursorTop = 16;
                printf("%s (%dM$) = %s (%dM$)", company[i].rocketName, company[i].pricePerLaunch, company[j].rocketName, company[j].pricePerLaunch);
                break;
            }
        }
        if (isSamePrice) 
            break;
    }

    if (!isSamePrice)
    {
        Console::CursorLeft = 25;
        Console::CursorTop = 15;
        printf("Совпадений нет!");
    }

    _getch();
}

void alphabet(struct z* company)
{
    struct sp* nt;
    Console::ForegroundColor = ConsoleColor::Yellow;
    Console::BackgroundColor = ConsoleColor::Red;
    Console::Clear();

    if (!spisok)
        for (int i = 0; i < NC; i++)
            vstavka(company, company[i].companyName);

    Console::Clear();
    printf("\nАлфавитный список");
    printf("\n====================================\n");

    for (nt = spisok; nt != 0; nt = nt->sled)
        printf("\n%-20s %d", nt->companyName, nt->successfulFlights);

    _getch();
}

void vstakva(struct z* company, char* companyName)
{
    struct sp* nov, * nt, * z = 0;

    for (nt = spisok; nt != 0 && strcmp(nt->companyName, companyName) < 0; z = nt, nt = nt->sled);

    if (nt && strcmp(nt->companyName, companyName) == 0) return;

    nov = (struct sp*)malloc(sizeof(struct sp));
    strcpy(nov->companyName, companyName);
    nov->sled = nt;
    nov->successfulFlights = 0;

    for (int i = 0; i < NC; i++)
        if (strcmp(company[i].companyName, companyName) == 0)
            nov->successfulFlights += company[i].successfulFlights;

    if (!z) spisok = nov;
    else z->sled = nov;
    return;
}

void diagram(struct z* company)
{
    _getch();
}
