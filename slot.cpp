#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <windows.h>
using namespace std;

// Mang cac bieu tuong co the xuat hien
const string SYMBOLS[] = {"7", "BAR", "$", "@", "&", "#"};
const int NUM_SYMBOLS = 6;

void printSlots(string slots[], int size) {
    cout << "\n+---+---+---+\n";
    cout << "| ";
    for(int i = 0; i < size; i++) {
        cout << slots[i] << " | ";
    }
    cout << "\n+---+---+---+\n";
}

int main() {
    srand(time(0));
    int tien = 1000;  // So tien ban dau
    int cuoc;
    char choi;
    string slots[3];  // 3 o slot
    
    cout << "CHAO MUNG DEN VOI GAME SLOT MACHINE!\n";
    cout << "====================================\n";
    cout << "Luat choi:\n";
    cout << "- Ba ky hieu giong nhau: Thang gap 10\n";
    cout << "- Hai ky hieu giong nhau: Thang gap 2\n";
    cout << "- Ba so 7: Thang Jackpot (gap 20)\n";
    cout << "====================================\n\n";
    
    do {
        // Hien thi so tien hien co
        cout << "\nSo tien hien tai: " << tien << "$\n";
        
        // Nhap tien cuoc
        do {
            cout << "Nhap so tien cuoc (0 de thoat): ";
            cin >> cuoc;
            if(cuoc < 0 || cuoc > tien) {
                cout << "So tien khong hop le!\n";
            }
        } while(cuoc < 0 || cuoc > tien);
        
        if(cuoc == 0) break;
        
        // Tru tien cuoc
        tien -= cuoc;
        
        // Quay slot
        cout << "\nDang quay";
        for(int i = 0; i < 3; i++) {
            cout << "." << flush;
            Sleep(500);
        }
        cout << endl;
        
        // Random cac bieu tuong
        for(int i = 0; i < 3; i++) {
            slots[i] = SYMBOLS[rand() % NUM_SYMBOLS];
        }
        
        // Hien thi ket qua
        printSlots(slots, 3);
        
        // Kiem tra ket qua
        if(slots[0] == slots[1] && slots[1] == slots[2]) {
            // Ba bieu tuong giong nhau
            if(slots[0] == "7") {
                cout << "JACKPOT!!! Ban thang x20!\n";
                tien += cuoc * 20;
            } else {
                cout << "Chuc mung! Ba ky hieu giong nhau! Ban thang x10!\n";
                tien += cuoc * 10;
            }
        }
        else if(slots[0] == slots[1] || slots[1] == slots[2] || slots[0] == slots[2]) {
            cout << "Hay! Hai ky hieu giong nhau! Ban thang x2!\n";
            tien += cuoc * 2;
        }
        else {
            cout << "Rat tiec, ban da thua!\n";
        }
        
        // Kiem tra con tien khong
        if(tien <= 0) {
            cout << "\nBan da het tien!\n";
            break;
        }
        
        // Hoi co choi tiep khong
        cout << "\nBan co muon choi tiep khong? (y/n): ";
        cin >> choi;
        
    } while(tolower(choi) == 'y');
    
    cout << "\nCam on ban da choi! So tien cuoi cung: " << tien << "$\n";
    
    return 0;
}