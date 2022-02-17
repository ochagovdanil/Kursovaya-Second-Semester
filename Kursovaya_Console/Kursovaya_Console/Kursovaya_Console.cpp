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

// int menu(int);
// void maxim(struct z*);
// void first(struct z*);
// void text_data(char*, char*);
// void kolvo(struct z*);
// void alfalist(struct z*);
// void vstavka(struct z*, char*);
// void listing(struct z*);
// void diagram(struct z*);

int main(array<System::String ^> ^args)
{
    // Some variables
    char dan[7][70] = {
        "Какая компания имеет больше всего неудачных запусков?",
        "Какая самая дешевая ракета для запуска?",
        "Список ракет, у которых число удачных запусков больше X",
        "Список ракет, запуск которых стоит меньше XM$",
        "Алфавитный список всех компаний",
        "Диаграмма. Процентное соотношение всех запусков каждой компании",
        "Выход"
    };

    char BlankLine[80]; memset(BlankLine, ' ', 56);
    char filePath[90] = "D:\\University\\прога\\курсач\\Kursovaya_Console\\Kursovaya_Console\\SpaceCompanies.dat";
    int NC, i, n;
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
    for (i = 0; i < NC; i++)
        printf("\n%-20s %-20s %-10d %-10d %-10d", 
            companies[i].companyName,
            companies[i].rocketName,
            companies[i].pricePerLaunch,
            companies[i].successfulFlights,
            companies[i].failureFlights);
    
    _getch();
    return 0;
}
