#include <iostream>
#include "functions.h"
#include <limits>
#include <fstream>
using namespace std;


int main() {
    system("chcp 65001");
    ofstream file_output;
    ifstream file_input;
    int n, q_input, q_output, q = 1, i = INT_MAX, j = INT_MAX, k = INT_MAX, l = INT_MAX;
    double* arr = new double[n];
    double time;
    string input_path = "../input.txt";
    string output_path = "../output.txt";
    string ans_input_q = "Вы ввели не число(!!!). Введите только число 1 или 0(1-чтение из файла; 0-из консоли) : ";
    string ans_n = "Вы ввели не число(!!!). Введите только число, больше или равно 4: ";
    string ans_output_q = "Вы ввели не число(!!!). Введите только число 1 ил 0(1-вывод в файл; 0-в консоль): ";
    string ans_time = "Вы ввели не число(!!!). Введите только число: ";
        cout << "Каким способом хотите ввести данные?(1-чтение из файла; 0-из консоли): ";
        cin >> q_input;
        q_input = checking_number(q_input, ans_input_q);

        if (q_input == 1) {
            file_input.open(input_path);
            file_input >> n;
            for (int x = 0; x < n; x++) {
                file_input >> time;
                arr[x] = time;
            }
            file_input.close();
        } else if (q_input == 0) {
            cout << "Введите кол-во участников (больше 4): ";
            cin >> n;
            n = checking_number(n, ans_n);
            while (n < 4) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Число меньше 4 или не целое(!), введите еще раз: ";
                cin >> n;
            }
            for (int x = 0; x < n; x++) {
                cin >> time;
                time = checking_number(time, ans_time);
                arr[x] = time;
            }
        }

        int *pointer = search_min(arr, n);
        for (int y = 0; y < 4; y++) {
            if (pointer[y] < i) {
                l = k;
                k = j;
                j = i;
                i = pointer[y];
            } else if (pointer[i] < j) {
                l = k;
                k = j;
                j = pointer[y];
            } else if (pointer[y] < k) {
                l = k;
                k = pointer[y];
            } else if (pointer[y] < l) {
                l = pointer[y];
            }
        }
        cout << "Как вывести данные?(1-вывод в файл; 0-в консоль): ";
        cin >> q_output;
        q_output = checking_number(q_output, ans_output_q);

        if (q_output == 1) {
            file_output.open(output_path);
            file_output << "Индекс первого участника: " << i << endl << "Индекс второго участника: " << j << endl;
            file_output << "Индекс третьего участника: " << k << endl << "Индекс четвертого участника: " << l << endl;
            file_output.close();
        } else if (q_output == 0) {
            cout << "Индекс первого участника: " << i << endl << "Индекс второго участника: " << j << endl;
            cout << "Индекс третьего участника: " << k << endl << "Индекс четвертого участника: " << l << endl;
        }
        // cout << "Хотите еще? 1 если да, иначе любая другая клавиша: ";
        // cin >> q;
    return 0;
}
