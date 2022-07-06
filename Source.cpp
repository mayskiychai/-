#include <iostream>
#include <string>
#include <vector>
using namespace std;

// получает входную строку и отдает кол-во блоков
int GetBlocksCount(string text) {
    int blockcount = 0; // кол-во блоков по 17
    blockcount = ceil((float)text.length() / 17); // сколько блоков понадобится в зависимости от длины сообщения
    //cout << "Количество блоков = " << blockcount << endl; // вывод кол-ва блоков
    return blockcount;
}

// делит строку на блоки по 17
string split(string text) {
    string block17 = "";
    /*
    for (int i = 0; i < 17; i++) {
        block17 += text[i];
    }
    */

    int stopindex = 0; // номер индекса где остановился блок на 17, если блоков больше
    // заполнить массив из данной строки
    if (text.length() < 17) {
        for (int i = 0; i < text.length(); i++) {
            stopindex += 1;
            if (text[i] == ' ') {
                block17 += '_';
            }
            else {
                block17 += text[i];
            }
        }
        for (int i = text.length(); i < 17; i++) {
            stopindex += 1;
            block17 += '_';
        }
    }
    else {
        for (int i = 0; i < 17; i++) {
            stopindex +=1;
            if (text[i] == ' ') {
                block17 += '_';
            }
            else {
                block17 += text[i];
            }
        }
    }

    cout << "Stopindex = " << stopindex << endl;
    /*
    // вывод номеров для видимости (от 0 до 16)
    for (int i = 0; i < 17; i++) {
        printf("%3i", i); 
    }
    cout << endl;
    */
    return block17;
}

// вывод чисел от 1 до 17*кол-во блоков
void getvid() {
    for (int i = 0; i < 17; i++) {
        printf("%3i", i);
    }
    cout << endl;
}

// получаем шифрованный код
void getcode(string text) {
    string code;
    /*
    for (int i = 0; i < GetBlocksCount(text); i++) {
        getvid();
    }
    */
    /*
    for (int i = 0; i < 17*text.length(); i++) {
        //code = split(text);
        //printf("%3c", code[i]);
    }
    */
    int stopindex = 0; // номер индекса где остановился блок на 17, если блоков больше
    int realindex = 0;
    for (int k = 0; k < GetBlocksCount(text); k++) {
        getvid();
        // создание массива под букву и шифр
        char** arr = new char* [2]; // две строки в массиве
        for (int count = 0; count < 2; count++) {
            arr[count] = new char[17]; // столбцы
        }

        // заполнение массива букв
        for (int i = 0; i < text.length(); i++) {
            if (text[i+stopindex] == ' ') {
                arr[0][i] = '_';
            }
            else {
                arr[0][i] = text[i+stopindex];
            }
        }
        for (int i = text.length(); i < 17; i++) {
            arr[0][i] = '_';
        }

        int temp[17]; // временный массив для чисел( чтобы не повторялись)
        memset(temp, 0, sizeof(temp));
        // массив случайных чисел до 15
        bool table[18] = { false };
        for (int col = 0; col < 17; ++col) {
            int n;
            while (table[n = rand() % 17]);
            table[n] = true;
            temp[col] = n;
        }

        // подставляем во вторую строку буквы и тд
        for (int col = 0; col < 17; col++) {
            arr[1][col] = arr[0][temp[col]];
        }

        /*
        // вывод случайных чисел до 17
        for (int col = 0; col < 17; col++) {
            //printf("%3i !", temp[col]);
        }
        cout << endl;
        */

        // вывод таблицы
        for (int row = 0; row < 2; row++) {
            for (int col = 0; col < 17; col++) {
                printf("%3c", arr[row][col]);
            }
            cout << endl;
        }

        // вывод случайных номеров позиций
        for (int col = 0; col < 17; col++) {
            printf("%3i", temp[col]);
        }

        stopindex += 17;
        cout << "\nstop:" << stopindex << endl << endl;
    }
    cout << endl << endl;
}

// не использовать
string fun(string text) {
    // что то внизу
    /*
    // таблица заполнена
    int arr[2][15];
    int i = 0;
    for (int col = 0; col < 15; col++) {
        i++;
        arr[0][col] = i;
    }
    bool table[16] = { false };
    for (int col = 0; col < 15; ++col) {
        int n;
        while (table[n = rand() % 15 + 1]);
        table[n] = true;
        arr[1][col] = n;
    }

    // вывод таблицы
    for (int row = 0; row < 2; row++) {
        for (int col = 0; col < 15; col++) {
            printf("%3i ", arr[row][col]);
        }
        cout << endl;
    }
    cout << "----------------" << endl;
    */

    int blockcount = 0; // кол-во блоков по 17
    blockcount = ceil((float)text.length() / 17); // сколько блоков понадобится в зависимости от длины сообщения
    cout << "Block = " << blockcount << endl; // вывод кол-ва блоков
    // можно и без векторов
    // vector <char> arr(15*blockcount); // массив всех символов в предложении
    // какая то шняга внизу 
    /*
    for (int k = 0; k < blockcount; k++) {
        if (text.length() >= 15) {
            for (int i = 0; i < text.length(); i++) {
                if (text[i] == ' ') {
                    arr[i] = '_';
                }
                else {
                    arr[i] = text[i];
                }
            }
        }
        else {
            for (int i = 0; i < text.length(); i++) {
                if (text[i] == ' ') {
                    arr[i] = '_';
                }
                else {
                    arr[i] = text[i];
                }
            }
            for (int i = text.length(); i < 15 * blockcount; i++) {
                arr[i] = '_';
            }
        }
    }
    */

    char **arr = new char*[2]; // массив входящих слов и их эквивалент
    for (int count = 0; count < 2; count++) { // 2 столбца (1-начальные символы, 2-их эквивалент)
        arr[count] = new char[17 * blockcount]; // символы на кол-во блоков*17
    }
    // создание таблицы 1 строка
    for (int k = 0; k < blockcount; k++) {
        /*
        if (text.length() >= 15) {
            for (int i = 0; i < text.length(); i++) {
                if (text[i] == ' ') {
                    arr[0][i] = '_';
                }
                else {
                    arr[0][i] = text[i];
                }
            }
            
            for (int i = text.length(); i < 15 * blockcount; i++) {
                arr[0][i] = '_';
            }
        }
        else {
            for (int i = 0; i < text.length(); i++) {
                if (text[i] == ' ') {
                    arr[0][i] = '_';
                }
                else {
                    arr[0][i] = text[i];
                }
            }
            for (int i = text.length(); i < 15 * blockcount; i++) {
                arr[0][i] = '_';
            }
        }
        */
        for (int i = 0; i < text.length(); i++) {
            if (text[i] == ' ') {
                arr[0][i] = '_';
            }
            else {
                arr[0][i] = text[i];
            }
        }
        for (int i = text.length(); i < 17 * blockcount; i++) {
            arr[0][i] = '_';
        }

        // второй этап
        
    }
    
    // вывод
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 17 * blockcount; j++) {
            cout << arr[i][j];
        }
        cout << endl;
    }
    cout << endl;

    return text;
}

int main() {
    setlocale(LC_ALL, "russian");
    string sometext = "";
    getline(cin, sometext);

    //fun(sometext);
    //cout << fun(sometext) << endl;
    cout << "Количество блоков = " << GetBlocksCount(sometext) << endl; // вывод кол-ва блоков
    getcode(sometext);

    system("pause");
    return 0;
}