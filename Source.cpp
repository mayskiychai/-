#include <iostream>
#include <string>
#include <vector>
using namespace std;

// �������� ������� ������ � ������ ���-�� ������
int GetBlocksCount(string text) {
    int blockcount = 0; // ���-�� ������ �� 17
    blockcount = ceil((float)text.length() / 17); // ������� ������ ����������� � ����������� �� ����� ���������
    //cout << "���������� ������ = " << blockcount << endl; // ����� ���-�� ������
    return blockcount;
}

// ����� ������ �� ����� �� 17
string split(string text) {
    string block17 = "";
    /*
    for (int i = 0; i < 17; i++) {
        block17 += text[i];
    }
    */

    int stopindex = 0; // ����� ������� ��� ����������� ���� �� 17, ���� ������ ������
    // ��������� ������ �� ������ ������
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
    // ����� ������� ��� ��������� (�� 0 �� 16)
    for (int i = 0; i < 17; i++) {
        printf("%3i", i); 
    }
    cout << endl;
    */
    return block17;
}

// ����� ����� �� 1 �� 17*���-�� ������
void getvid() {
    for (int i = 0; i < 17; i++) {
        printf("%3i", i);
    }
    cout << endl;
}

// �������� ����������� ���
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
    int stopindex = 0; // ����� ������� ��� ����������� ���� �� 17, ���� ������ ������
    int realindex = 0;
    for (int k = 0; k < GetBlocksCount(text); k++) {
        getvid();
        // �������� ������� ��� ����� � ����
        char** arr = new char* [2]; // ��� ������ � �������
        for (int count = 0; count < 2; count++) {
            arr[count] = new char[17]; // �������
        }

        // ���������� ������� ����
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

        int temp[17]; // ��������� ������ ��� �����( ����� �� �����������)
        memset(temp, 0, sizeof(temp));
        // ������ ��������� ����� �� 15
        bool table[18] = { false };
        for (int col = 0; col < 17; ++col) {
            int n;
            while (table[n = rand() % 17]);
            table[n] = true;
            temp[col] = n;
        }

        // ����������� �� ������ ������ ����� � ��
        for (int col = 0; col < 17; col++) {
            arr[1][col] = arr[0][temp[col]];
        }

        /*
        // ����� ��������� ����� �� 17
        for (int col = 0; col < 17; col++) {
            //printf("%3i !", temp[col]);
        }
        cout << endl;
        */

        // ����� �������
        for (int row = 0; row < 2; row++) {
            for (int col = 0; col < 17; col++) {
                printf("%3c", arr[row][col]);
            }
            cout << endl;
        }

        // ����� ��������� ������� �������
        for (int col = 0; col < 17; col++) {
            printf("%3i", temp[col]);
        }

        stopindex += 17;
        cout << "\nstop:" << stopindex << endl << endl;
    }
    cout << endl << endl;
}

// �� ������������
string fun(string text) {
    // ��� �� �����
    /*
    // ������� ���������
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

    // ����� �������
    for (int row = 0; row < 2; row++) {
        for (int col = 0; col < 15; col++) {
            printf("%3i ", arr[row][col]);
        }
        cout << endl;
    }
    cout << "----------------" << endl;
    */

    int blockcount = 0; // ���-�� ������ �� 17
    blockcount = ceil((float)text.length() / 17); // ������� ������ ����������� � ����������� �� ����� ���������
    cout << "Block = " << blockcount << endl; // ����� ���-�� ������
    // ����� � ��� ��������
    // vector <char> arr(15*blockcount); // ������ ���� �������� � �����������
    // ����� �� ����� ����� 
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

    char **arr = new char*[2]; // ������ �������� ���� � �� ����������
    for (int count = 0; count < 2; count++) { // 2 ������� (1-��������� �������, 2-�� ����������)
        arr[count] = new char[17 * blockcount]; // ������� �� ���-�� ������*17
    }
    // �������� ������� 1 ������
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

        // ������ ����
        
    }
    
    // �����
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
    cout << "���������� ������ = " << GetBlocksCount(sometext) << endl; // ����� ���-�� ������
    getcode(sometext);

    system("pause");
    return 0;
}