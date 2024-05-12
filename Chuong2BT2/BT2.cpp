#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

class CauhoiTN {
private:
    string cauhoi;
    string dapAnA;
    string dapAnB;
    char dapAnDung;

public:
    void nhap() {
        cout << "Nhap cau hoi: ";
        getline(cin, cauhoi);
        cout << "Nhap dap an A: ";
        getline(cin, dapAnA);
        cout << "Nhap dap an B: ";
        getline(cin, dapAnB);
        cout << "Nhap dap an dung (A hoac B): ";
        cin >> dapAnDung;
        cin.ignore(); // Đọc bỏ ký tự Enter sau khi nhập dapAnDung
    }

    void docfile(ifstream& f) {
        getline(f, cauhoi);
        getline(f, dapAnA);
        getline(f, dapAnB);
        f >> dapAnDung;
        f.ignore(); // Đọc bỏ ký tự Enter sau khi đọc dapAnDung
    }

    void ghifile(ofstream& f) {
        f << cauhoi << endl;
        f << dapAnA << endl;
        f << dapAnB << endl;
        f << dapAnDung << endl;
    }

    void kiemtra() {
        char luaChon;
        cout << "Cau hoi: " << cauhoi << endl;
        cout << "A. " << dapAnA << endl;
        cout << "B. " << dapAnB << endl;
        cout << "Nhap lua chon cua ban (A hoac B): ";
        cin >> luaChon;
        if (toupper(luaChon) == toupper(dapAnDung)) {
            cout << "Ban da chon dung!" << endl;
        }
        else {
            cout << "Ban da chon sai! Dap an dung la: " << dapAnDung << endl;
        }
    }

    void xuat() {
        cout << "Cau hoi: " << cauhoi << endl;
        cout << "A. " << dapAnA << endl;
        cout << "B. " << dapAnB << endl;
        cout << "Dap an dung la: " << dapAnDung << endl;
    }

    friend bool giongnhau(CauhoiTN cau1, CauhoiTN cau2);
};

bool giongnhau(CauhoiTN cau1, CauhoiTN cau2) {
    if (cau1.cauhoi == cau2.cauhoi && cau1.dapAnA == cau2.dapAnA && cau1.dapAnB == cau2.dapAnB && cau1.dapAnDung == cau2.dapAnDung) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    // In thông tin sinh viên
    cout << "MSSV: 054204001759 - Ten: Nguyen Thanh Khiem" << endl;

    int choice;
    CauhoiTN cauhoi;
    ifstream inputFile;
    ofstream outputFile;

    do {
        cout << "\n=== MENU ===" << endl;
        cout << "1. Nhap cau hoi moi" << endl;
        cout << "2. Doc file cau hoi" << endl;
        cout << "3. Kiem tra cau hoi" << endl;
        cout << "4. Xuat cau hoi" << endl;
        cout << "5. Thoat" << endl;
        cout << "Lua chon cua ban: ";
        cin >> choice;
        cin.ignore(); // Đọc bỏ ký tự Enter sau khi nhập lua chon

        switch (choice) {
        case 1:
            cauhoi.nhap();
            break;
        case 2:
            inputFile.open("cauhoi.TTN");
            if (!inputFile) {
                cerr << "Khong the mo file!" << endl;
                break;
            }
            while (!inputFile.eof()) {
                cauhoi.docfile(inputFile);
                cauhoi.xuat();
            }
            inputFile.close();
            break;
        case 3:
            cauhoi.kiemtra();
            break;
        case 4:
            outputFile.open("cauhoi.TTN", ios::app);
            if (!outputFile) {
                cerr << "Khong the mo file!" << endl;
                break;
            }
            cauhoi.ghifile(outputFile);
            outputFile.close();
            break;
        case 5:
            cout << "Ket thuc chuong trinh. Tam biet!" << endl;
            break;
        default:
            cout << "Lua chon khong hop le. Vui long thu lai!" << endl;
            break;
        }
    } while (choice != 5);

    return 0;
}
