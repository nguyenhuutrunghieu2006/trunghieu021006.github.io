#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 1000;

// Lớp ThuCung
class ThuCung {
private:
    string ten;
    string loai;
    int tuoi;
    double gia;

public:
    ThuCung(string t = "", string l = "", int tu = 0, double g = 0.0)
        : ten(t), loai(l), tuoi(tu), gia(g) {}
    ~ThuCung() {}

    void setTen(const string& t) { ten = t; }
    void setLoai(const string& l) { loai = l; }
    void setTuoi(int tu) { tuoi = tu; }
    void setGia(double g) { gia = g; }

    string getTen() const { return ten; }
    string getLoai() const { return loai; }
    int getTuoi() const { return tuoi; }
    double getGia() const { return gia; }

    friend istream& operator>>(istream& is, ThuCung& tc) {
        cout << "Nhập tên thú cưng: ";
        getline(is, tc.ten);
        cout << "Nhập loài: ";
        getline(is, tc.loai);
        cout << "Nhập tuổi: ";
        is >> tc.tuoi;
        cout << "Nhập giá: ";
        is >> tc.gia;
        is.ignore();
        return is;
    }

    friend ostream& operator<<(ostream& os, const ThuCung& tc) {
        if (tc.ten.empty()) return os;
        os << "Tên: " << tc.ten << ", Loài: " << tc.loai
           << ", Tuổi: " << tc.tuoi << ", Giá: " << fixed
           << setprecision(2) << tc.gia << " VNĐ";
        return os;
    }
};

// Lớp CuaHangThuCung
class CuaHangThuCung {
protected:
    string tenCuaHang;
    string diaChi;
    double tongDoanhThu;
    unordered_map<string, array<ThuCung, MAX_SIZE>> danhSachThuCungMacDinh;

public:
    CuaHangThuCung(const string& ten, const string& dc) : tenCuaHang(ten), diaChi(dc), tongDoanhThu(0.0) {
        danhSachThuCungMacDinh["Chó"] = {
            ThuCung("Bông", "Chó", 2, 2500000.0),
            ThuCung("Milo", "Chó", 1, 2000000.0),
            ThuCung("Poodle", "Chó", 3, 2600000.0),
            ThuCung("Husky", "Chó", 2, 1900000.0),
            ThuCung("Golden", "Chó", 3, 1850000.0),
            ThuCung("Beagle", "Chó", 1, 1950000.0),
            ThuCung("Bulldog", "Chó", 4, 2800000.0),
            ThuCung("Corgi", "Chó", 2, 1500000.0)
        };
        danhSachThuCungMacDinh["Mèo"] = {
            ThuCung("Miu", "Mèo", 1, 1700000.0),
            ThuCung("Ba Tư", "Mèo", 2, 1800000.0),
            ThuCung("Anh Lông Ngắn", "Mèo", 1, 2900000.0),
            ThuCung("Mèo Xiêm", "Mèo", 2, 1800000.0),
            ThuCung("Mèo Ragdoll", "Mèo", 3, 2000000.0),
            ThuCung("Mèo Maine Coon", "Mèo", 4, 2500000.0),
            ThuCung("Mèo Bengal", "Mèo", 2, 2200000.0),
            ThuCung("Mèo Sphynx", "Mèo", 3, 3000000.0)
        };
        danhSachThuCungMacDinh["Chuột"] = {
            ThuCung("Jerry", "Chuột", 1, 2100000.0),
            ThuCung("Speedy", "Chuột", 2, 2600000.0),
            ThuCung("Mickey", "Chuột", 1, 2000000.0),
            ThuCung("Stuart", "Chuột", 2, 3300000.0),
            ThuCung("Remy", "Chuột", 3, 1400000.0),
            ThuCung("Pinky", "Chuột", 1, 1900000.0),
            ThuCung("Brain", "Chuột", 2, 2950000.0),
            ThuCung("Gus", "Chuột", 1, 2800000.0)
        };
        danhSachThuCungMacDinh["Chim"] = {
            ThuCung("Rio", "Chim", 2, 2000000.0),
            ThuCung("Sky", "Chim", 1, 1800000.0),
            ThuCung("Coco", "Chim", 3, 2200000.0),
            ThuCung("Kiwi", "Chim", 2, 1900000.0),
            ThuCung("Sunny", "Chim", 1, 1700000.0),
            ThuCung("Buddy", "Chim", 3, 2100000.0),
            ThuCung("Charlie", "Chim", 2, 2300000.0),
            ThuCung("Angel", "Chim", 1, 1600000.0)
        };
        danhSachThuCungMacDinh["Thỏ"] = {
            ThuCung("Bunny", "Thỏ", 1, 800000.0),
            ThuCung("Snowball", "Thỏ", 2, 900000.0),
            ThuCung("Fluffy", "Thỏ", 1, 850000.0),
            ThuCung("Thumper", "Thỏ", 2, 950000.0),
            ThuCung("Clover", "Thỏ", 1, 700000.0),
            ThuCung("Daisy", "Thỏ", 2, 750000.0),
            ThuCung("Lola", "Thỏ", 1, 800000.0),
            ThuCung("Peter", "Thỏ", 3, 1000000.0)
        };
    }

    void chuyenThuCung(CuaHangThuCungCaoCap& cuaHangCaoCap, CuaHangThuCungThuong& cuaHangThuong) {
        for (const auto& loai : danhSachThuCungMacDinh) {
            for (const auto& tc : loai.second) {
                if (!tc.getTen().empty()) {
                    if (tc.getGia() > 1000000.0) {
                        cuaHangCaoCap.themThuCung(tc);
                    } else {
                        cuaHangThuong.themThuCung(tc);
                    }
                }
            }
        }
        cout << "Đã phân loại và chuyển thú cưng từ danh sách mặc định.\n";
    }
};

// Lớp CuaHangThuCungCaoCap
class CuaHangThuCungCaoCap : public CuaHangThuCung {
private:
    unordered_map<string, int> soLuongHienTai;
    vector<pair<string, double>> danhSachDichVuCaoCap;
    double tyLeGiamGia;
    unordered_map<string, array<ThuCung, MAX_SIZE>> danhSachThuCungCaoCap;

public:
    CuaHangThuCungCaoCap(const string& ten, const string& dc) : CuaHangThuCung(ten, dc) {
        tyLeGiamGia = 0.1;
        danhSachDichVuCaoCap = {
            {"Tắm bùn khoáng", 600000.0},
            {"Cắt tỉa lông theo 'couture'", 600000.0},
            {"Kiểm tra sức khỏe đầy đủ", 700000.0},
            {"Massage và chăm sóc da", 800000.0},
            {"Huấn luyện EQ và IQ", 10000000.0}
        };
    }

    void themThuCung(const ThuCung& thuCung) {
        string loai = thuCung.getLoai();
        if (danhSachThuCungCaoCap.find(loai) == danhSachThuCungCaoCap.end()) {
            danhSachThuCungCaoCap[loai] = array<ThuCung, MAX_SIZE>();
            soLuongHienTai[loai] = 0;
        }
        array<ThuCung, MAX_SIZE>& danhSach = danhSachThuCungCaoCap[loai];
        int& sltc = soLuongHienTai[loai];
        if (sltc < MAX_SIZE) {
            for (int i = 0; i < sltc; ++i) {
                if (danhSach[i].getTen() == thuCung.getTen()) {
                    cout << "Thú cưng \"" << thuCung.getTen() << "\" đã tồn tại trong danh sách cao cấp.\n";
                    return;
                }
            }
            danhSach[sltc++] = thuCung;
            cout << "Đã thêm thú cưng \"" << thuCung.getTen() << "\" vào danh sách cao cấp.\n";
        } else {
            cout << "Danh sách thú cưng cao cấp cho loài \"" << loai << "\" đã đầy.\n";
        }
    }
};

// Lớp CuaHangThuCungThuong
class CuaHangThuCungThuong : public CuaHangThuCung {
private:
    unordered_map<string, int> soLuongHienTai;
    vector<pair<string, double>> danhSachDichVuThongThuong;
    unordered_map<string, array<ThuCung, MAX_SIZE>> danhSachThuCungThongThuong;

public:
    CuaHangThuCungThuong(const string& ten, const string& dc) : CuaHangThuCung(ten, dc) {
        danhSachDichVuThongThuong = {
            {"Dắt chó đi dạo", 100000.0},
            {"Chải lông", 100000.0},
            {"Phối giống", 200000.0},
            {"Vệ sinh tai", 100000.0},
            {"Tắm", 150000.0}
        };
    }

    void themThuCung(const ThuCung& thuCung) {
        string loai = thuCung.getLoai();
        if (danhSachThuCungThongThuong.find(loai) == danhSachThuCungThongThuong.end()) {
            danhSachThuCungThongThuong[loai] = array<ThuCung, MAX_SIZE>();
            soLuongHienTai[loai] = 0;
        }
        array<ThuCung, MAX_SIZE>& danhSach = danhSachThuCungThongThuong[loai];
        int& sltc = soLuongHienTai[loai];
        if (sltc < MAX_SIZE) {
            for (int i = 0; i < sltc; ++i) {
                if (danhSach[i].getTen() == thuCung.getTen()) {
                    cout << "Thú cưng \"" << thuCung.getTen() << "\" đã tồn tại trong danh sách thông thường.\n";
                    return;
                }
            }
            danhSach[sltc++] = thuCung;
            cout << "Đã thêm thú cưng \"" << thuCung.getTen() << "\" vào danh sách thông thường.\n";
        } else {
            cout << "Danh sách thú cưng thông thường cho loài \"" << loai << "\" đã đầy.\n";
        }
    }
};

// Hàm main
int main() {
    CuaHangThuCungCaoCap cuaHangCaoCap("Pet Shop Cao Cấp", "123 Đường Chính");
    CuaHangThuCungThuong cuaHangThuong("Pet Shop Thông Thường", "456 Đường Phụ");
    
    CuaHangThuCung cuaHang("Pet Shop Tổng", "789 Đường Lớn");
    cuaHang.chuyenThuCung(cuaHangCaoCap, cuaHangThuong);

    while (true) {
        cout << "\nHệ thống quản lý cửa hàng thú cưng\n";
        cout << "1. Phân loại thú cưng từ danh sách mặc định\n";
        cout << "2. Thoát\n";
        cout << "Nhập lựa chọn: ";
        int choice;
        cin >> choice;
        cin.ignore();

        if (choice == 2) {
            cout << "Đã thoát chương trình.\n";
            break;
        }

        switch (choice) {
        case 1: {
            cuaHang.chuyenThuCung(cuaHangCaoCap, cuaHangThuong);
            break;
        }
        default:
            cout << "Lựa chọn không hợp lệ.\n";
        }
    }

    return 0;
}