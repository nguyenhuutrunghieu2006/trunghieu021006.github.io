#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 1000;

// Lớp ThuCung
class ThuCung {
private:
    string ten;  // Tên thú cưng
    string loai; // Loài (chó, mèo, vẹt, v.v.)
    int tuoi;    // Tuổi
    double gia;  // Giá bán

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
    unordered_map<string, array<ThuCung, MAX_SIZE>> danhSachThuCung;

public:
    CuaHangThuCung(const string& ten, const string& dc)
        : tenCuaHang(ten), diaChi(dc), tongDoanhThu(0.0) {}

    // Hàm thêm danh sách thú cưng mặc định từ lớp con sang danhSachThuCung của lớp cha
    void themDanhSachThuCungMacDinh(const unordered_map<string, array<ThuCung, MAX_SIZE>>& danhSachMacDinh) {
        for (const auto& loai : danhSachMacDinh) {
            const string& tenLoai = loai.first;
            const array<ThuCung, MAX_SIZE>& danhSach = loai.second;

            // Khởi tạo danh sách trống nếu chưa tồn tại
            if (danhSachThuCung.find(tenLoai) == danhSachThuCung.end()) {
                danhSachThuCung[tenLoai] = array<ThuCung, MAX_SIZE>();
            }

            array<ThuCung, MAX_SIZE>& danhSach = danhSachThuCung[tenLoai];

            // Thêm thú cưng từ danh sách mặc định vào danh sách chính
            for (int i = 0; i < MAX_SIZE; ++i) {
                if (danhSachMacDinh[i].getTen().empty()) break;
                // Tìm vị trí trống trong danhSach để thêm
                bool daCo = false;
                for (int j = 0; j < MAX_SIZE; ++j) {
                    if (!danhSach[j].getTen().empty() && danhSach[j].getTen() == danhSachMacDinh[i].getTen()) {
                        daCo = true;
                        break;
                    }
                }
                if (!daCo) {
                    for (int k = 0; k < MAX_SIZE; ++k) {
                        if (danhSach[k].getTen().empty()) {
                            danhSach[k] = danhSachMacDinh[i];
                            cout << "Đã thêm thú cưng mặc định: " << danhSachMacDinh[i].getTen() << " (" << tenLoai << ").\n";
                            break;
                        }
                    }
                }
            }
        }
    }

    // hiển thị loài mà khách hàng muốn mua
    void hienThiThuCungCanMua(const string& loai) const {
        auto it = danhSachThuCung.find(loai);
        if (it != danhSachThuCung.end()) {
            cout << "Danh sách thú cưng loại " << loai << ":\n";
            // bool hasPet = false;
            int count = 0 ;
            for (const auto& tc : it->second) {
                if (!tc.getTen().empty()) {
                    cout << tc << "\n";
                    // hasPet = true;
                    count++;
                }
            }
            if(count == 0) {
                cout << "Không có thú cưng nào thuộc loài " << loai << ".\n";
            }
            // if (!hasPet) cout << "Không có thú cưng nào thuộc loài " << loai << ".\n";
        } else {
            cout << "Loài \"" << loai << "\" không tồn tại.\n";
        }
    }
    
    bool themThuCung(const ThuCung& thuCung) {
        const string& loai = thuCung.getLoai();
        auto it = danhSachThuCung.find(loai);
        if (it != danhSachThuCung.end()) {
            array<ThuCung, MAX_SIZE>& danhSach = it->second;
            for (int i = 0; i < MAX_SIZE; ++i) {
// duyệt qua tất cả các vị trí trong cả mảng thú cưng của loài đó 
                if (danhSach[i].getTen().empty()) {
                    danhSach[i] = thuCung;
// duyệt qua danh sách thú cưng của loài đó và lấy tên của từng thú cưng , nếu tên thú cưng đó đã có trong danh sach thì không thêm còn nếu chưa có thì thêm vào 
                    cout << "Đã thêm thú cưng: " << thuCung.getTen() << " (" << loai << ").\n";
                    return true;
                }
            }
            cout << "Không thể thêm thú cưng: Mảng đã đầy.\n";
            return false;
        } else {
            cout << "Loài \"" << loai << "\" không được hỗ trợ.\n";
            return false;
        }
    }

    void xoaThuCung(const string& ten, const string& loai) {
        auto it = danhSachThuCung.find(loai);
        if (it != danhSachThuCung.end()) {
            array<ThuCung, MAX_SIZE>& danhSach = it->second;
            for (int i = 0; i < MAX_SIZE; ++i) {
                if (danhSach[i].getTen() == ten && danhSach[i].getLoai() == loai) {
                    for (int j = i; j < MAX_SIZE - 1; ++j) {
                        danhSach[j] = danhSach[j + 1];
                    }
                    danhSach[MAX_SIZE - 1] = ThuCung();
                    cout << "Đã xóa thú cưng: " << ten << " (" << loai << ").\n";
                    return;
                }
            }
            cout << "Không tìm thấy thú cưng có tên \"" << ten << "\" thuộc loài \"" << loai << "\".\n";
        } else {
            cout << "Loài \"" << loai << "\" không tồn tại trong danh sách.\n";
        }
    }

    friend ostream& operator<<(ostream& os, const CuaHangThuCung& ch) {
        os << "Cửa hàng: " << ch.tenCuaHang << "\n"
           << "Địa chỉ: " << ch.diaChi << "\n";
        for (const auto& loai : ch.danhSachThuCung) {
            bool hasPet = false;
            for (const auto& tc : loai.second) {
                if (!tc.getTen().empty()) {
                    if (!hasPet) {
                        os << "loài \"" << loai.first << "\" : ";
                        hasPet = true;
                    } else {
                        os << " , ";
                    }
};

// Lớp CuaHangThuCungCaoCap
class CuaHangThuCungCaoCap : public CuaHangThuCung {
private:
    unordered_map<string, int> soLuongHienTai; // Theo dõi số lượng thú cưng thực tế
    vector<pair<string, double>> danhSachDichVuCaoCap;
    double tyLeGiamGia;
    unordered_map<string, array<ThuCung, MAX_SIZE>> danhSachThuCungMacDinh;

public:
    CuaHangThuCungCaoCap(const string& ten, const string& dc, double giamGia)
        : CuaHangThuCung(ten, dc), tyLeGiamGia(giamGia) {
        danhSachDichVuCaoCap = {
            {"Tắm bùn khoáng", 500000.0},
            {"Cắt tỉa lông theo 'couture'", 500000.0},
            {"Kiểm tra sức khỏe đầy đủ", 700000.0},
            {"Massage và chăm sóc da", 600000.0},
            {"Huấn luyện EQ và IQ", 10000000.0}
        };
        khoiTaoDanhSachMacDinh();
        // Gọi hàm của lớp cha để thêm thú cưng mặc định
        themDanhSachThuCungMacDinh(danhSachThuCungMacDinh);
    }

    void khoiTaoDanhSachMacDinh() {
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

    void themThuCungMacDinh() {
        for (const auto& tc : danhSachThuCungMacDinh) {
            const string& tenLoai = tc.first;
            //tạo 1 danh sách mặc định để nhận các thú cưng của 1 loài cụ thể
            const array<ThuCung, MAX_SIZE>& danhSachMacDinh = tc.second;
    
            // Khởi tạo danh sách trống cho loài nếu chưa tồn tại
            if (danhSachThuCung.find(tenLoai) == danhSachThuCung.end()) {
                danhSachThuCung[tenLoai] = array<ThuCung, MAX_SIZE>();
                soLuongHienTai[tenLoai] = 0; // Khởi tạo số lượng thực tế là 0
            }
    
            // Sao chép thú cưng từ danh sách mặc định vào danh sách chính
            for (const auto& thuCung : danhSachMacDinh) {
                if (!thuCung.getTen().empty()) { // Chỉ thêm thú cưng hợp lệ
                    int& soLuong = soLuongHienTai[tenLoai];
                    if (soLuong < MAX_SIZE) {
                        danhSachThuCung[tenLoai][soLuong] = thuCung;
//danhSachThuCung[tenLoai]: Truy cập mảng array<ThuCung, MAX_SIZE> của loài tenLoai trong danhSachThuCung.
//[soLuong]: Truy cập vị trí thứ soLuong trong mảng array<ThuCung, MAX_SIZE> của loài tenLoai.
                        soLuong++; // Tăng số lượng thực tế
                    } else {
                        cout << "Không thể thêm thú cưng: Mảng của loài \"" << tenLoai << "\" đã đầy.\n";
                        break;
                    }
                }
            }
        }
    }
    
    int getSoLuongHienTai(const string& loai) const {
        auto it = soLuongHienTai.find(loai);
        if (it != soLuongHienTai.end()) {
            return it->second;
        }
        return 0; // Nếu không tìm thấy, trả về 0
    }
    void hienThiDichVu() const {
        cout << "Dịch vụ tại cửa hàng:\n";
        for (const auto& dv : danhSachDichVuCaoCap) {
            cout << "- " << dv.first << ": " << fixed << setprecision(2) << dv.second << " VNĐ\n";
        }
    }

    void themDichVu(const string& tenDichVu, double gia) {
        danhSachDichVuCaoCap.emplace_back(tenDichVu, gia);
    }

    // friend ostream& operator<<(ostream& os, const CuaHangThuCungCaoCap& ch) {
    //     os << "Danh sách dịch vụ cao cấp:\n";
    //     for (const auto& dv : ch.danhSachDichVuCaoCap) {
    //         os << "- " << dv.first << ": " << fixed << setprecision(2) << dv.second << " VNĐ\n";
    //     }
    //     return os;
    // }
};

// Lớp CuaHangThuCungThuong
class CuaHangThuCungThuong : public CuaHangThuCung {
private:
    unordered_map<string, array<ThuCung, MAX_SIZE>> danhSachThuCungMacDinh;
    vector<pair<string, double>> danhSachDichVuThongThuong;

public:
    CuaHangThuCungThuong(const string& ten, const string& dc) : CuaHangThuCung(ten, dc) {
        danhSachDichVuThongThuong = {
            {"Dắt chó đi dạo", 100000.0},
            {"Chải lông", 100000.0},
            {"Phối giống", 200000.0},
            {"Vệ sinh tai", 100000.0},
            {"Tắm", 150000.0}
        };
        khoiTaoDanhSachMacDinh();
        themThuCungMacDinh();
    }

    void khoiTaoDanhSachMacDinh() {
        danhSachThuCungMacDinh["Chó"] = {
            ThuCung("Husky", "Chó", 2, 1200000.0),
            ThuCung("Golden", "Chó", 3, 1500000.0)
        };
        danhSachThuCungMacDinh["Mèo"] = {
            ThuCung("Anh Lông Ngắn", "Mèo", 1, 900000.0),
            ThuCung("Mèo Xiêm", "Mèo", 2, 800000.0)
        };
        danhSachThuCungMacDinh["Chuột"] = {
            ThuCung("Betta", "Chuột", 1, 50000.0),
            ThuCung("Vàng", "Chuột", 1, 200000.0)
        };
    }

    void themThuCungMacDinh() {
        for (const auto& loai : danhSachThuCungMacDinh) {
            const string& tenLoai = loai.first;
            danhSachThuCung[tenLoai]; // Tạo danh sách trống nếu chưa có
            const array<ThuCung, MAX_SIZE>& danhSachMacDinh = loai.second;
            for (const auto& thuCung : danhSachMacDinh) {
                if (!thuCung.getTen().empty()) {
                    themThuCung(thuCung);
                }
            }
        }
    }

    void hienThiDichVu() const {
        cout << "Dịch vụ tại cửa hàng:\n";
        for (const auto& dv : danhSachDichVuThongThuong) {
            cout << "- " << dv.first << ": " << fixed << setprecision(2) << dv.second << " VNĐ\n";
        }
    }

    void themDichVu(const string& tenDichVu, double gia) {
        danhSachDichVuThongThuong.emplace_back(tenDichVu, gia);
    }

    friend ostream& operator<<(ostream& os, const CuaHangThuCungThuong& ch) {
        os << static_cast<const CuaHangThuCung&>(ch);
        os << "Danh sách dịch vụ thông thường:\n";
        for (const auto& dv : ch.danhSachDichVuThongThuong) {
            os << "- " << dv.first << ": " << fixed << setprecision(2) << dv.second << " VNĐ\n";
        }
        return os;
    }
};

// Hàm main
int main() {
    // Tạo cửa hàng thú cưng
    CuaHangThuCungCaoCap cuaHang("Cửa Hàng Thú Cưng", "456 Đường Phố" , 0.1);
    CuaHangThuCung ch("Cửa Hàng Thú Cưng", "456 Đường Phố");
    cout << ch ;
    // ThuCung tc("MOON" , "Chó" , 1 , 324365353.0);
    // cuaHang.themThuCung(tc);
    // Vòng lặp để thêm thú cưng từ bàn phím
    // char tiepTuc;
    // do {
    //     ThuCung thuCung;
    //     cout << "Nhập thông tin thú cưng:\n";
    //     cin >> thuCung; // Nhập thông tin thú cưng từ bàn phím

    //     // Thêm thú cưng vào danh sách
    //     if (cuaHang.themThuCung(thuCung)) {
    //         cout << "Thêm thú cưng thành công!\n";
    //     } else {
    //         cout << "Thêm thú cưng thất bại.\n";
    //     }

    //     // Hỏi người dùng có muốn tiếp tục thêm thú cưng không
    //     cout << "Bạn có muốn thêm thú cưng khác không? (y/n): ";
    //     cin >> tiepTuc;
    //     cin.ignore(); // Bỏ qua ký tự xuống dòng còn lại trong bộ đệm
    // } while (tiepTuc == 'y' || tiepTuc == 'Y');

    // // Hiển thị danh sách thú cưng theo loài
    // string loai;
    // cout << "Nhập loài thú cưng bạn muốn xem: ";
    // getline(cin, loai);
    // cuaHang.hienThiThuCungCanMua(loai);

    return 0;
}