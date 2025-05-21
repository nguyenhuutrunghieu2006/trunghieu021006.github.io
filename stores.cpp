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
    vector<pair<string, double>> Dichvu;
    unordered_map<string, array<ThuCung, MAX_SIZE>> danhSachThuCungMacDinh;
    unordered_map<string, array<ThuCung, MAX_SIZE>> danhSachThuCungCaoCap;
    unordered_map<string, array<ThuCung, MAX_SIZE>> danhSachThuCungThongThuong;
    map<string,int> soLuongThuCungCaoCap ;
    map<string,int> soLuongThuCungThongThuong ;

public:
    CuaHangThuCung(const string& ten, const string& dc){
        tenCuaHang = ten;
        diaChi = dc;
        Dichvu = {
            {"Tắm", 50000.0},
            {"Chải lông", 30000.0},
            {"Cắt móng", 20000.0},
            {"Tiêm phòng", 100000.0},
            {"Khám bệnh", 150000.0}
        };
        danhSachThuCungCaoCap["Chó"] ={
            ThuCung("Bông", "Chó", 2, 5500000.0),
            ThuCung("Milo", "Chó", 1, 5000000.0),
            ThuCung("Poodle", "Chó", 3, 5600000.0),
            ThuCung("Husky", "Chó", 2, 4900000.0),
            ThuCung("Golden", "Chó", 3, 4850000.0),
            ThuCung("Beagle", "Chó", 1, 480000.0),
            ThuCung("Bulldog", "Chó", 4, 6800000.0),
            ThuCung("Corgi", "Chó", 2, 7500000.0)
        };
        danhSachThuCungCaoCap["Mèo"] = {
            ThuCung("Miu", "Mèo", 1, 3700000.0),
            ThuCung("Ba Tư", "Mèo", 2, 3800000.0),
            ThuCung("Anh Lông Ngắn", "Mèo", 1, 2900000.0),
            ThuCung("Mèo Xiêm", "Mèo", 2, 2800000.0),
            ThuCung("Mèo Ragdoll", "Mèo", 3, 3000000.0),
            ThuCung("Mèo Maine Coon", "Mèo", 4, 2800000.0),
            ThuCung("Mèo Bengal", "Mèo", 2, 4200000.0),
            ThuCung("Mèo Sphynx", "Mèo", 3, 4000000.0)
        };
        danhSachThuCungCaoCap["Chuột"] = {
            ThuCung("Jerry", "Chuột", 1, 2100000.0),
            ThuCung("Speedy", "Chuột", 2, 2600000.0),
            ThuCung("Mickey", "Chuột", 1, 2000000.0),
            ThuCung("Stuart", "Chuột", 2, 3300000.0),
            ThuCung("Remy", "Chuột", 3, 3400000.0),
            ThuCung("Pinky", "Chuột", 1, 2900000.0),
            ThuCung("Brain", "Chuột", 2, 2950000.0),
            ThuCung("Gus", "Chuột", 1, 2800000.0)
        };
        danhSachThuCungCaoCap["Chim"] = {
            ThuCung("Rio", "Chim", 2, 4000000.0),
            ThuCung("Sky", "Chim", 1, 3800000.0),
            ThuCung("Coco", "Chim", 3, 3200000.0),
            ThuCung("Kiwi", "Chim", 2, 2900000.0),
            ThuCung("Sunny", "Chim", 1, 3700000.0),
            ThuCung("Buddy", "Chim", 3, 3100000.0),
            ThuCung("Charlie", "Chim", 2, 2300000.0),
            ThuCung("Angel", "Chim", 1, 4600000.0)
        };
        danhSachThuCungCaoCap["Thỏ"] = {
            ThuCung("Bunny", "Thỏ", 1, 3800000.0),
            ThuCung("Snowball", "Thỏ", 2, 4900000.0),
            ThuCung("Fluffy", "Thỏ", 1, 6850000.0),
            ThuCung("Thumper", "Thỏ", 2, 6950000.0),
            ThuCung("Clover", "Thỏ", 1, 4700000.0),
            ThuCung("Daisy", "Thỏ", 2, 4750000.0),
            ThuCung("Lola", "Thỏ", 1, 5800000.0),
            ThuCung("Peter", "Thỏ", 3, 51000000.0)
        };
        danhSachThuCungThongThuong["Chó"] = {
            ThuCung("Mimi", "Chó", 1, 1500000.0),
            ThuCung("Lucky", "Chó", 2, 1800000.0),
            ThuCung("Max", "Chó", 1, 1500000.0),
            ThuCung("Rocky", "Chó", 2, 1200000.0),
            ThuCung("Bella", "Chó", 1, 1900000.0),
            ThuCung("Daisy", "Chó", 2, 1950000.0),
            ThuCung("Charlie", "Chó", 1, 1700000.0),
            ThuCung("Lucy", "Chó", 2, 1800000.0)     
        };
        danhSachThuCungThongThuong["Mèo"] = {
            ThuCung("Luna", "Mèo", 1, 1500000.0),
            ThuCung("Milo", "Mèo", 2, 2000000.0),
            ThuCung("Oliver", "Mèo", 1, 2100000.0),
            ThuCung("Leo", "Mèo", 2, 2000000.0),
            ThuCung("Bella", "Mèo", 1, 2330000.0),
            ThuCung("Lily", "Mèo", 2, 2000000.0),
            ThuCung("Charlie", "Mèo", 1, 1500000.0),
            ThuCung("Lucy", "Mèo", 2, 800000.0)
        };
        danhSachThuCungThongThuong["Chim"] = {
            ThuCung("Tweety", "Chim", 1, 1500000.0),
            ThuCung("Sunny", "Chim", 2, 2000000.0),
            ThuCung("Sky", "Chim", 1, 2400000.0),
            ThuCung("Rio", "Chim", 2, 1300000.0),
            ThuCung("Blue", "Chim", 1, 1500000.0),
            ThuCung("Coco", "Chim", 2, 900000.0),
            ThuCung("Buddy", "Chim", 1, 1500000.0),
            ThuCung("Angel", "Chim", 2, 1000000.0)
        };
        danhSachThuCungThongThuong["Chuột"] = {
            ThuCung("Nibbles", "Chuột", 1, 1500000.0),
            ThuCung("Jerry", "Chuột", 2, 2000000.0),
            ThuCung("Tom", "Chuột", 1, 2200000.0),
            ThuCung("Speedy", "Chuột", 2, 1400000.0),
            ThuCung("Mickey", "Chuột", 1, 1700000.0),
            ThuCung("Minnie", "Chuột", 2, 1300000.0),
            ThuCung("Stuart", "Chuột", 1, 1100000.0),
            ThuCung("Remy", "Chuột", 2, 2000000.0)
        };
        danhSachThuCungThongThuong["Thỏ"] = {
            ThuCung("Bunny", "Thỏ", 1, 1500000.0),
            ThuCung("Snowball", "Thỏ", 2, 2000000.0),
            ThuCung("Fluffy", "Thỏ", 1, 2300000.0),
            ThuCung("Thumper", "Thỏ", 2, 2000000.0),
            ThuCung("Clover", "Thỏ", 1, 2400000.0),
            ThuCung("Daisy", "Thỏ", 2, 850000.0),
            ThuCung("Lola", "Thỏ", 1, 950000.0),
            ThuCung("Peter", "Thỏ", 2, 2000000.0)
        };
        // Cập nhật số lượng hiện tại cho từng loài
        soLuongThuCungCaoCap["Chó"] = 8;
        soLuongThuCungCaoCap["Mèo"] = 8;
        soLuongThuCungCaoCap["Chim"] = 8;
        soLuongThuCungCaoCap["Chuột"] = 8;
        soLuongThuCungCaoCap["Thỏ"] = 8;
        soLuongThuCungThongThuong["Chó"] = 8;
        soLuongThuCungThongThuong["Mèo"] = 8;
        soLuongThuCungThongThuong["Chim"] = 8;
        soLuongThuCungThongThuong["Chuột"] = 8;
        soLuongThuCungThongThuong["Thỏ"] = 8;
    }
    bool themthucung(const ThuCung& tc){
        double gia = tc.getGia();
        bool hople = false ;
        if(gia > 2000000.0){
            for(auto& thucung : danhSachThuCungCaoCap){
                const string& loai = thucung.first;
                if(loai == tc.getLoai()){
                    hople = true ;
                    int &sltc = soLuongThuCungCaoCap[loai];
                    if(sltc < MAX_SIZE){
                        danhSachThuCungCaoCap[loai][sltc++] = tc;
                        cout << "Thêm thú cưng vào danh sách cao cấp thành công!\n";
                        return true;
                    }
                    else cout << "Danh sách thú cưng cao cấp đã đầy!\n" ;
                }
            }
            if(!hople){
                cout << "Loại thú cưng không có trong danh sách mac dinh cao cap !\n";
                return false ;
            }
        }
        else{
            for(auto& thucung : danhSachThuCungThongThuong){
                const string& loai = thucung.first;
                if(loai == tc.getLoai()){
                    hople = true ;
                    int &sltc = soLuongThuCungThongThuong[loai];
                    if(sltc < MAX_SIZE){
                        danhSachThuCungThongThuong[loai][sltc++] = tc;
                        cout << "Thêm thú cưng vào danh sách thông thường thành công!\n";
                        return true;
                    }
                    else cout << "Danh sách thú cưng thông thường đã đầy!\n" ;
                }
            }
            if(!hople){
                cout << "Loại thú cưng ko có trong danh sách!\n";
                return false ;
            }
        }
        return false;
    }     
    void xoaThucung(const ThuCung& tc) {
        // Xóa trong danh sách cao cấp
        for (auto& thucung : danhSachThuCungCaoCap) {
            const string& loai = thucung.first; // tên loài
            auto& danhsach = thucung.second; // mảng chứa thú cưng của loài hiện tại
            int& sl = soLuongThuCungCaoCap[loai]; // Số lượng thú cưng của loài này
            if (loai == tc.getLoai()) {
                for (int i = 0; i < sl; ++i) {
                    if (danhsach[i].getTen() == tc.getTen()) {
                        // Nếu tên thú cưng trong danh sách trùng với tên cần xóa
                        for (int j = i; j < sl - 1; j++) {
                            danhsach[j] = danhsach[j + 1]; // Đẩy các phần tử về trước
                        }
                        danhsach[sl - 1] = ThuCung(); // Đặt phần tử cuối thành rỗng
                        sl--; // Giảm số lượng thú cưng
                        cout << "Đã xóa thú cưng " << tc.getTen() << " khỏi danh sách cao cấp.\n";
                        return;
                    }
                }
            }
        }
    
        // Xóa trong danh sách thông thường
        for (auto& thucung : danhSachThuCungThongThuong) {
            const string& loai = thucung.first; // tên loài
            auto& ds = thucung.second; // mảng chứa thú cưng của loài hiện tại
            int& sl = soLuongThuCungThongThuong[loai]; // Số lượng thú cưng của loài này
            if (loai == tc.getLoai()) {
                for (int i = 0; i < sl; ++i) {
                    if (ds[i].getTen() == tc.getTen()) {
                        // Nếu tên thú cưng trong danh sách trùng với tên cần xóa
                        for (int j = i; j < sl - 1; j++) {
                            ds[j] = ds[j + 1]; // Đẩy các phần tử về trước
                        }
                        ds[sl - 1] = ThuCung(); // Đặt phần tử cuối thành rỗng
                        sl--; // Giảm số lượng thú cưng
                        cout << "Đã xóa thú cưng " << tc.getTen() << " khỏi danh sách thông thường.\n";
                        return;
                    }
                }
            }
        }
        cout << "Không tìm thấy thú cưng " << tc.getTen() << " để xóa.\n";
    }    
    friend ostream& operator<<(ostream& os, const CuaHangThuCung& ch) {
        os << "Tên cửa hàng: " << ch.tenCuaHang << "\n";
        os << "Địa chỉ: " << ch.diaChi << "\n";
        for (const auto& tc : ch.danhSachThuCungCaoCap) {
            const string& loai = tc.first;
            os << "Danh sách thú cưng thông thường của loài " << loai << ":\n";
            const array<ThuCung, MAX_SIZE>& danhsach = tc.second;
            int sl = ch.soLuongThuCungCaoCap.at(loai);
            for (int i = 0; i < sl; ++i) {
                os << danhsach[i] << endl;
            }
        }
        
        return os;
    }
};
// Hàm main
int main() {
    CuaHangThuCung cuaHang("Pet Shop Tổng", "789 Đường Lớn");
    ThuCung tc ;
    cin >> tc ;
    cuaHang.xoaThucung(tc) ;
    cout << cuaHang ;

    return 0;
};