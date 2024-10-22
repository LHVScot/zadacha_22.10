#include <iostream>
#include <locale>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    // Массив для хранения количества жильцов в каждой квартире
    int house[40]; // 4 подъезда * 5 этажей * 2 квартиры = 40 квартир

    // Ввод количества жильцов для каждой квартиры
    cout << "Введите количество жильцов для каждой квартиры:\n";
    for (int i = 0; i < 40; i++) {
        cout << "Квартира " << i + 1 << ": ";
        cin >> house[i];
    }

    // Суммарное количество жильцов для каждого подъезда
    int entranceResidents[4] = { 0 }; 

    // Подсчет количества жильцов в каждом подъезде
    for (int i = 0; i < 40; i++) {
        // Определение номера подъезда
        int entrance = (i / 8) + 1; 
        entranceResidents[entrance - 1] += house[i];
    }

    // Вывод суммарного количества жильцов в каждом подъезде
    cout << "\nСуммарное количество жильцов в каждом подъезде:\n";
    for (int i = 0; i < 4; i++) {
        cout << "Подъезд " << i + 1 << ": " << entranceResidents[i] << " жильцов\n";
    }

    // Получение номера квартиры от пользователя
    int chosenhouse;
    cout << "Введите номер квартиры: ";
    cin >> chosenhouse;

    // Проверка ввода
    if (chosenhouse < 1 || chosenhouse > 40) {
        cout << "Некорректный номер квартиры!\n";
        return 1;
    }

    // Вычисление индекса выбранной квартиры в массиве
    chosenhouse--;

    // Определение номера этажа
    int floor = (chosenhouse / 8) + 1;

    // Определение номера подъезда
    int entrance = (chosenhouse / 8) + 1;
    // Определение индексов соседей
    int neighbor1 = chosenhouse - 1;
    int neighbor2 = chosenhouse + 1;

    // Проверка, является ли выбранная квартира крайняя в подъезде
    if (chosenhouse % 2 == 0) {
        neighbor1 = chosenhouse - 2;
    }
    else {  
        neighbor2 = chosenhouse + 2;
    }

    // Вывод информации о количестве жильцов
    cout << "В выбранной квартире (" << chosenhouse + 1 << ") проживает " << house[chosenhouse] << " жильцов.\n";

    // Вывод информации о количестве жильцов у соседей
    if (neighbor1 >= 0 && neighbor1 < 40) {
        cout << "У левого соседа проживает " << house[neighbor1] << " жильцов.\n";
    }
    if (neighbor2 >= 0 && neighbor2 < 40) {
        cout << "У правого соседа проживает " << house[neighbor2] << " жильцов.\n";
    }
    // Вывод номеров квартир, где живут многодетные семьи
    cout << "\nНомера квартир, где живут многодетные семьи:\n";
    for (int i = 0; i < 40; i++) {
        if (house[i] > 5) {
            cout << "Квартира " << i + 1 << endl;
        }
    }


    return 0;

}
