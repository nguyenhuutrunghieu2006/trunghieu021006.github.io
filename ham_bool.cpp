    #include <bits/stdc++.h>
using namespace std;

class GiangVien {
private:
    string ma, hoTen, boMon;

public:
    GiangVien(int stt, string hoTen, string boMon) {
        this->hoTen = hoTen;
        this->boMon = boMon ;
        ma = "GV" ;
        if(stt < 10) ma = ma + "0" + to_string(stt);
    }
    void chuanhoabomon(){
        stringstream ss(boMon);
        string word, result;
        while (ss >> word) {
            result += toupper(word[0]);
        }
        boMon = result;
    }
    string getxetchucuoi(){
        return hoTen ;
    }
    string getMa(){
        return ma ;
    }

    void inThongTin(){
        cout << ma << " " << hoTen << " " << boMon << endl;
    }
};

bool cmp(GiangVien a, GiangVien b) {
    if (a.getxetchucuoi() != b.getxetchucuoi())
        return a.getxetchucuoi() < b.getxetchucuoi();
    return a.getMa() < b.getMa();
}

int main() {
    int n;
    cin >> n;
    cin.ignore();
    vector<GiangVien> danhSach;
    for (int i = 1; i <= n; i++) {
        string hoTen, boMon;
        getline(cin, hoTen);
        getline(cin, boMon);
        GiangVien x( i , hoTen , boMon);
        x.chuanhoabomon();
        danhSach.push_back(x) ;
    }

    sort(danhSach.begin(), danhSach.end(), cmp);
    for(int i =0 ; i < n ; i++) {
        danhSach[i].inThongTin();
    }

    return 0;
}
