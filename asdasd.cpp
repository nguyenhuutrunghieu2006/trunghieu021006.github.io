#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 1000;
const int MAX_LICHSU_MUAHANG = 100;
const int MAX_DANHSACH_THUCUNG = 1000;
const int MAX_DANHSACH_DICHVU = 30;
const int MAX_DANHSACH_SANPHAM = 50;
const int MAX_HOADON = 100;
const int MAX_NHANVIEN = 20;
const int MAX_KHACHHANG = 100;
const int MAX_DICHVU = 100;

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

    string getTen() const { return ten; }
    string getLoai() const { return loai; }
    int getTuoi() const { return tuoi; }
    double getGia() const { return gia; }

    void setTen(const string& t) { ten = t; }
    void setLoai(const string& l) { loai = l; }
    void setTuoi(int tu) { tuoi = tu; }
    void setGia(double g) { gia = g; }

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

// Lớp NhanVien
class NhanVien {
private:
    string maNV;
    string hoTen;
    double luongCoBan;
    double heSoLuong;

public:
    NhanVien(string ma = "", string ten = "", double luong = 5000000.0, double heSo = 1.0)
        : maNV(ma), hoTen(ten), luongCoBan(luong), heSoLuong(heSo) {}

    double tinhLuong() const { return luongCoBan * heSoLuong; }

    friend istream& operator>>(istream& is, NhanVien& nv) {
        cout << "Nhập mã nhân viên: ";
        getline(is, nv.maNV);
        cout << "Nhập họ tên: ";
        getline(is, nv.hoTen);
        cout << "Nhập lương cơ bản: ";
        is >> nv.luongCoBan;
        cout << "Nhập hệ số lương: ";
        is >> nv.heSoLuong;
        is.ignore();
        return is;
    }

    friend ostream& operator<<(ostream& os, const NhanVien& nv) {
        os << "Mã NV: " << nv.maNV << ", Họ tên: " << nv.hoTen
           << ", Lương: " << fixed << setprecision(2) << nv.tinhLuong() << " VNĐ";
        return os;
    }

    string getMaNV() const { return maNV; }
};

// Lớp KhachHang
class KhachHang {
private:
    string maKH;
    string hoTen;
    string soDienThoai;
    array<string, MAX_LICHSU_MUAHANG> lichSuMuaHang;
    int soLuongLichSu;

public:
    KhachHang(string ma = "", string ten = "", string sdt = "")
        : maKH(ma), hoTen(ten), soDienThoai(sdt), soLuongLichSu(0) {
        lichSuMuaHang.fill("");
    }

    void themHoaDon(const string& maHD) {
        if (soLuongLichSu < MAX_LICHSU_MUAHANG) {
            lichSuMuaHang[soLuongLichSu++] = maHD;
        } else {
            cout << "Danh sách lịch sử mua hàng đã đầy.\n";
        }
    }

    friend istream& operator>>(istream& is, KhachHang& kh) {
        cout << "Nhập mã khách hàng: ";
        getline(is, kh.maKH);
        cout << "Nhập họ tên: ";
        getline(is, kh.hoTen);
        cout << "Nhập số điện thoại: ";
        getline(is, kh.soDienThoai);
        return is;
    }

    friend ostream& operator<<(ostream& os, const KhachHang& kh) {
        os << "Mã KH: " << kh.maKH << ", Họ tên: " << kh.hoTen
           << ", SĐT: " << kh.soDienThoai << "\n";
        os << "Lịch sử mua hàng:\n";
        if (kh.soLuongLichSu == 0) {
            os << "  Không có giao dịch.\n";
        } else {
            for (int i = 0; i < kh.soLuongLichSu; ++i) {
                os << "  - Hóa đơn: " << kh.lichSuMuaHang[i] << "\n";
            }
        }
        return os;
    }

    string getMaKH() const { return maKH; }
    string getHoTen() const { return hoTen; }
    string getSoDienThoai() const { return soDienThoai; }
};

// Lớp SanPham
class SanPham {
private:
    string tenSP;
    int soLuong;
    double gia;

public:
    SanPham(string ten = "", int sl = 0, double g = 0.0)
        : tenSP(ten), soLuong(sl), gia(g) {}

    friend istream& operator>>(istream& is, SanPham& sp) {
        cout << "Nhập tên sản phẩm: ";
        getline(is, sp.tenSP);
        cout << "Nhập số lượng: ";
        is >> sp.soLuong;
        cout << "Nhập giá: ";
        is >> sp.gia;
        is.ignore();
        return is;
    }

    friend ostream& operator<<(ostream& os, const SanPham& sp) {
        os << "Sản phẩm: " << sp.tenSP << ", Số lượng: " << sp.soLuong
           << ", Giá: " << fixed << setprecision(2) << sp.gia << " VNĐ";
        return os;
    }

    string getTenSP() const { return tenSP; }
    int getSoLuong() const { return soLuong; }
    double getGia() const { return gia; }

    void capNhatSoLuong(int sl) { soLuong += sl; }
};

// Lớp HoaDon
class HoaDon {
private:
    string maHoaDon;
    string maKhachHang;
    array<pair<ThuCung, int>, MAX_DANHSACH_THUCUNG> danhSachThuCung;
    array<pair<string, double>, MAX_DANHSACH_DICHVU> dichVu;
    array<pair<SanPham, int>, MAX_DANHSACH_SANPHAM> sanPham;
    int soLuongThuCung;
    int soLuongDichVu;
    int soLuongSanPham;
    double tongTien;
    string ngayLap;

public:
    HoaDon(string ma = "", string maKH = "", string ngay = "")
        : maHoaDon(ma), maKhachHang(maKH), soLuongThuCung(0), soLuongDichVu(0),
          soLuongSanPham(0), tongTien(0.0), ngayLap(ngay) {}

    void themThuCung(const ThuCung& tc, int soLuong) {
        if (soLuongThuCung < MAX_DANHSACH_THUCUNG) {
            danhSachThuCung[soLuongThuCung++] = {tc, soLuong};
            tongTien += tc.getGia() * soLuong;
        } else {
            cout << "Danh sách thú cưng đã đầy.\n";
        }
    }

    void themDichVu(const string& tenDV, double gia) {
        if (soLuongDichVu < MAX_DANHSACH_DICHVU) {
            dichVu[soLuongDichVu++] = {tenDV, gia};
            tongTien += gia;
        } else {
            cout << "Danh sách dịch vụ đã đầy.\n";
        }
    }

    void themSanPham(const SanPham& sp, int soLuong) {
        if (soLuongSanPham < MAX_DANHSACH_SANPHAM) {
            sanPham[soLuongSanPham++] = {sp, soLuong};
            tongTien += sp.getGia() * soLuong;
        } else {
            cout << "Danh sách sản phẩm đã đầy.\n";
        }
    }

    double getTongTien() const { return tongTien; }
    string getMaHoaDon() const { return maHoaDon; }
    string getMaKhachHang() const { return maKhachHang; }

    friend ostream& operator<<(ostream& os, const HoaDon& hd) {
        os << "Hóa đơn: " << hd.maHoaDon << ", Ngày lập: " << hd.ngayLap << "\n";
        os << "Mã khách hàng: " << hd.maKhachHang << "\n";
        os << "Danh sách thú cưng:\n";
        if (hd.soLuongThuCung == 0) os << "  Không có.\n";
        for (int i = 0; i < hd.soLuongThuCung; ++i) {
            os << "  - " << hd.danhSachThuCung[i].first << ", Số lượng: "
               << hd.danhSachThuCung[i].second << "\n";
        }
        os << "Danh sách dịch vụ:\n";
        if (hd.soLuongDichVu == 0) os << "  Không có.\n";
        for (int i = 0; i < hd.soLuongDichVu; ++i) {
            os << "  - " << hd.dichVu[i].first << ": " << fixed << setprecision(2)
               << hd.dichVu[i].second << " VNĐ\n";
        }
        os << "Danh sách sản phẩm:\n";
        if (hd.soLuongSanPham == 0) os << "  Không có.\n";
        for (int i = 0; i < hd.soLuongSanPham; ++i) {
            os << "  - " << hd.sanPham[i].first << ", Số lượng: "
               << hd.sanPham[i].second << "\n";
        }
        os << "Tổng tiền: " << fixed << setprecision(2) << hd.tongTien << " VNĐ\n";
        return os;
    }
};

// Lớp LichSuGiaoDich
class LichSuGiaoDich {
private:
    array<HoaDon, MAX_HOADON> danhSachHoaDon;
    int soLuongHoaDon;

public:
    LichSuGiaoDich() : soLuongHoaDon(0) {}

    void themHoaDon(const HoaDon& hd) {
        if (soLuongHoaDon < MAX_HOADON) {
            danhSachHoaDon[soLuongHoaDon++] = hd;
        } else {
            cout << "Danh sách hóa đơn đã đầy.\n";
        }
    }

    void hienThiLichSu() const {
        cout << "Lịch sử giao dịch:\n";
        if (soLuongHoaDon == 0) {
            cout << "Không có giao dịch nào.\n";
            return;
        }
        for (int i = 0; i < soLuongHoaDon; ++i) {
            cout << danhSachHoaDon[i] << "\n";
        }
    }

    void ghiFile(const string& filename) const {
        ofstream ofs(filename);
        if (!ofs) {
            cout << "Không thể mở file " << filename << " để ghi.\n";
            return;
        }
        for (int i = 0; i < soLuongHoaDon; ++i) {
            ofs << danhSachHoaDon[i].getMaHoaDon() << ","
                << danhSachHoaDon[i].getMaKhachHang() << ","
                << danhSachHoaDon[i].getTongTien() << "\n";
        }
        ofs.close();
        cout << "Đã ghi lịch sử giao dịch vào " << filename << "\n";
    }

    void docFile(const string& filename) {
        ifstream ifs(filename);
        if (!ifs) {
            cout << "Không thể mở file " << filename << " để đọc.\n";
            return;
        }
        string line;
        while (getline(ifs, line)) {
            stringstream ss(line);
            string maHD, maKH;
            double tongTien;
            getline(ss, maHD, ',');
            getline(ss, maKH, ',');
            ss >> tongTien;
            if (soLuongHoaDon < MAX_HOADON) {
                danhSachHoaDon[soLuongHoaDon++] = HoaDon(maHD, maKH, "2025-05-19");
            }
        }
        ifs.close();
        cout << "Đã đọc lịch sử giao dịch từ " << filename << "\n";
    }
};

// Lớp CuaHangThuCung
class CuaHangThuCung {
protected:
    string tenCuaHang;
    string diaChi;
    double tongDoanhThu;
    unordered_map<string, array<ThuCung, MAX_SIZE>> danhSachThuCung;
    array<NhanVien, MAX_NHANVIEN> danhSachNhanVien;
    array<KhachHang, MAX_KHACHHANG> danhSachKhachHang;
    unordered_map<string, SanPham> khoHang;
    LichSuGiaoDich lichSu;
    int soLuongNhanVien;
    int soLuongKhachHang;

public:
    CuaHangThuCung(const string& ten, const string& dc)
        : tenCuaHang(ten), diaChi(dc), tongDoanhThu(0.0),
          soLuongNhanVien(0), soLuongKhachHang(0) {}

    virtual void hienThiDanhSachDichVu() const {
        cout << "Không có dịch vụ nào.\n";
    }

    virtual void themDichVu(const string&, double) {}

    unordered_map<string, int> soLuongThuCung; // Thêm biến đếm cho từng loài

    void themThuCung(const ThuCung& thuCung) {
        string loai_tc = thuCung.getLoai();
    
        if (danhSachThuCung.find(loai_tc) == danhSachThuCung.end()) {
            danhSachThuCung[loai_tc] = array<ThuCung, MAX_SIZE>();
            //Tạo một mảng (array<ThuCung, MAX_SIZE>) cho loài đó trong danhSachThuCung.
            soLuongThuCung[loai_tc] = 0; // Khởi tạo số lượng thú cưng cho loài mới
        }
    
        array<ThuCung, MAX_SIZE>& danhSach = danhSachThuCung[loai_tc];
        int& sltc = soLuongThuCung[loai_tc];
    
        for (int i = 0; i < sltc; ++i) {
            if (danhSach[i].getTen() == thuCung.getTen()) {
                cout << "Thú cưng \"" << thuCung.getTen() << "\" đã tồn tại.\n";
                return;
            }
        }
    
        if (sltc < MAX_SIZE) {
            danhSach[sltc++] = thuCung;
            cout << "Đã thêm thú cưng: " << thuCung.getTen() << " (" << loai_tc << ").\n";
        } else {
            cout << "Không thể thêm: Mảng đầy.\n";
        }
    }
    void xoaThuCung(const string& ten, const string& loai) {
        auto it = danhSachThuCung.find(loai);
        if (it != danhSachThuCung.end()) {
            array<ThuCung, MAX_SIZE>& danhSach = it->second;
            int& sltc = soLuongThuCung[loai];
    
            for (int i = 0; i < sltc; ++i) {
                if (danhSach[i].getTen() == ten) {
                    for (int j = i; j < sltc - 1; ++j) {
                        danhSach[j] = danhSach[j + 1];
                    }
                    danhSach[--soLuongThuCung] = ThuCung(); // Đặt phần tử cuối cùng về mặc định
                    cout << "Đã xóa thú cưng: " << ten << " (" << loai << ").\n";
                    return;
                }
            }
            cout << "Không tìm thấy thú cưng \"" << ten << "\" thuộc loài \"" << loai << "\".\n";
        } else {
            cout << "Loài \"" << loai << "\" không tồn tại.\n";
        }
    }

    void hienThiThuCungCanMua(const string& loai) const {
        auto it = danhSachThuCung.find(loai);
        if (it != danhSachThuCung.end()) {
            cout << "Danh sách thú cưng loại " << loai << ":\n";
            int count = 0;
            for (const auto& tc : it->second) {
                if (!tc.getTen().empty()) {
                    cout << tc << "\n";
                    count++;
                }
            }
            if (count == 0) {
                cout << "Không có thú cưng nào thuộc loài " << loai << ".\n";
            }
        } else {
            cout << "Loài \"" << loai << "\" không tồn tại.\n";
        }
    }

    void themNhanVien(const NhanVien& nv) {
        for (int i = 0; i < soLuongNhanVien; ++i) {
            if (danhSachNhanVien[i].getMaNV() == nv.getMaNV()) {
                cout << "Nhân viên với mã \"" << nv.getMaNV() << "\" đã tồn tại.\n";
                return;
            }
        }
        if (soLuongNhanVien < MAX_NHANVIEN) {
            danhSachNhanVien[soLuongNhanVien++] = nv;
            cout << "Đã thêm nhân viên: " << nv.getMaNV() << "\n";
        } else {
            cout << "Danh sách nhân viên đã đầy.\n";
        }
    }

    void hienThiNhanVien() const {
        cout << "Danh sách nhân viên:\n";
        if (soLuongNhanVien == 0) {
            cout << "Không có nhân viên.\n";
            return;
        }
        for (int i = 0; i < soLuongNhanVien; ++i) {
            cout << danhSachNhanVien[i] << "\n";
        }
    }

    void themKhachHang(const KhachHang& kh) {
        for (int i = 0; i < soLuongKhachHang; ++i) {
            if (danhSachKhachHang[i].getMaKH() == kh.getMaKH()) {
                cout << "Khách hàng với mã \"" << kh.getMaKH() << "\" đã tồn tại.\n";
                return;
            }
        }
        if (soLuongKhachHang < MAX_KHACHHANG) {
            danhSachKhachHang[soLuongKhachHang++] = kh;
            cout << "Đã thêm khách hàng: " << kh.getMaKH() << "\n";
        } else {
            cout << "Danh sách khách hàng đã đầy.\n";
        }
    }

    void hienThiKhachHang() const {
        cout << "Danh sách khách hàng:\n";
        if (soLuongKhachHang == 0) {
            cout << "Không có khách hàng.\n";
            return;
        }
        for (int i = 0; i < soLuongKhachHang; ++i) {
            cout << danhSachKhachHang[i] << "\n";
        }
    }

    void themSanPham(const SanPham& sp) {
        if (khoHang.find(sp.getTenSP()) != khoHang.end()) {
            khoHang[sp.getTenSP()].capNhatSoLuong(sp.getSoLuong());
            cout << "Đã cập nhật số lượng sản phẩm: " << sp.getTenSP() << "\n";
        } else {
            khoHang[sp.getTenSP()] = sp;
            cout << "Đã thêm sản phẩm: " << sp.getTenSP() << "\n";
        }
    }

    void xoaSanPham(const string& tenSP, int soLuong) {
        auto it = khoHang.find(tenSP);
        if (it != khoHang.end()) {
            if (it->second.getSoLuong() >= soLuong) {
                it->second.capNhatSoLuong(-soLuong);
                cout << "Đã xóa " << soLuong << " sản phẩm: " << tenSP << "\n";
                if (it->second.getSoLuong() == 0) {
                    khoHang.erase(it);
                }
            } else {
                cout << "Số lượng sản phẩm không đủ.\n";
            }
        } else {
            cout << "Sản phẩm \"" << tenSP << "\" không tồn tại.\n";
        }
    }

    void hienThiKhoHang() const {
        cout << "Danh sách sản phẩm trong kho:\n";
        if (khoHang.empty()) {
            cout << "Kho trống.\n";
            return;
        }
        for (const auto& sp : khoHang) {
            cout << sp.second << "\n";
        }
    }

    void ghiFileThuCung(const string& filename) const {
        ofstream ofs(filename);
        if (!ofs) {
            cout << "Không thể mở file " << filename << " để ghi.\n";
            return;
        }
        for (const auto& loai : danhSachThuCung) {
            for (const auto& tc : loai.second) {
                if (!tc.getTen().empty()) {
                    ofs << tc.getLoai() << "," << tc.getTen() << ","
                        << tc.getTuoi() << "," << tc.getGia() << "\n";
                }
            }
        }
        ofs.close();
        cout << "Đã ghi danh sách thú cưng vào " << filename << "\n";
    }

    void docFileThuCung(const string& filename) {
        ifstream ifs(filename);
        if (!ifs) {
            cout << "Không thể mở file " << filename << " để đọc.\n";
            return;
        }
        string line;
        while (getline(ifs, line)) {
            stringstream ss(line);
            string loai, ten;
            int tuoi;
            double gia;
            getline(ss, loai, ',');
            getline(ss, ten, ',');
            ss >> tuoi;
            ss.ignore(1);
            ss >> gia;
            ThuCung tc(ten, loai, tuoi, gia);
            themThuCung(tc);
        }
        ifs.close();
        cout << "Đã đọc danh sách thú cưng từ " << filename << "\n";
    }

    void ghiFileKhachHang(const string& filename) const {
        ofstream ofs(filename);
        if (!ofs) {
            cout << "Không thể mở file " << filename << " để ghi.\n";
            return;
        }
        for (int i = 0; i < soLuongKhachHang; ++i) {
            ofs << danhSachKhachHang[i].getMaKH() << "," << danhSachKhachHang[i].getHoTen()
                << "," << danhSachKhachHang[i].getSoDienThoai() << "\n";
        }
        ofs.close();
        cout << "Đã ghi danh sách khách hàng vào " << filename << "\n";
    }

    void docFileKhachHang(const string& filename) {
        ifstream ifs(filename);
        if (!ifs) {
            cout << "Không thể mở file " << filename << " để đọc.\n";
            return;
        }
        string line;
        while (getline(ifs, line)) {
            stringstream ss(line);
            string maKH, hoTen, sdt;
            getline(ss, maKH, ',');
            getline(ss, hoTen, ',');
            getline(ss, sdt, ',');
            KhachHang kh(maKH, hoTen, sdt);
            themKhachHang(kh);
        }
        ifs.close();
        cout << "Đã đọc danh sách khách hàng từ " << filename << "\n";
    }

    void ghiFileKhoHang(const string& filename) const {
        ofstream ofs(filename);
        if (!ofs) {
            cout << "Không thể mở file " << filename << " để ghi.\n";
            return;
        }
        for (const auto& sp : khoHang) {
            ofs << sp.second.getTenSP() << "," << sp.second.getSoLuong() << ","
                << sp.second.getGia() << "\n";
        }
        ofs.close();
        cout << "Đã ghi danh sách kho hàng vào " << filename << "\n";
    }

    void docFileKhoHang(const string& filename) {
        ifstream ifs(filename);
        if (!ifs) {
            cout << "Không thể mở file " << filename << " để đọc.\n";
            return;
        }
        string line;
        while (getline(ifs, line)) {
            stringstream ss(line);
            string tenSP;
            int soLuong;
            double gia;
            getline(ss, tenSP, ',');
            ss >> soLuong;
            ss.ignore(1);
            ss >> gia;
            SanPham sp(tenSP, soLuong, gia);
            themSanPham(sp);
        }
        ifs.close();
        cout << "Đã đọc danh sách kho hàng từ " << filename << "\n";
    }

    virtual void ghiFileDichVu(const string& filename) const {}
    virtual void docFileDichVu(const string& filename) {}

    friend ostream& operator<<(ostream& os, const CuaHangThuCung& ch) {
        os << "Cửa hàng: " << ch.tenCuaHang << "\n"
           << "Địa chỉ: " << ch.diaChi << "\n"
           << "Tổng doanh thu: " << fixed << setprecision(2) << ch.tongDoanhThu << " VNĐ\n";
        os << "Danh sách thú cưng:\n";
        for (const auto& loai : ch.danhSachThuCung) {
            os << "Loài: " << loai.first << "\n";
            int count = 0;
            for (const auto& tc : loai.second) {
                if (!tc.getTen().empty()) {
                    os << "  " << tc << "\n";
                    count++;
                }
            }
            if (count == 0) {
                os << "  Không có thú cưng nào.\n";
            }
        }
        return os;
    }

    bool timThuCung(const string& ten, const string& loai, ThuCung& result) const {
        auto it = danhSachThuCung.find(loai);
        if (it != danhSachThuCung.end()) {
            for (const auto& tc : it->second) {
                if (tc.getTen() == ten && !tc.getTen().empty()) {
                    result = tc;
                    return true;
                }
            }
        }
        return false;
    }

    bool timSanPham(const string& tenSP, SanPham& result) const {
        auto it = khoHang.find(tenSP);
        if (it != khoHang.end() && it->second.getSoLuong() > 0) {
            result = it->second;
            return true;
        }
        return false;
    }

    bool timKhachHang(const string& maKH, KhachHang& result) const {
        for (int i = 0; i < soLuongKhachHang; ++i) {
            if (danhSachKhachHang[i].getMaKH() == maKH) {
                result = danhSachKhachHang[i];
                return true;
            }
        }
        return false;
    }

    void capNhatDoanhThu(double soTien) {
        tongDoanhThu += soTien;
    }

    LichSuGiaoDich& getLichSu() { return lichSu; }
};

// Lớp CuaHangThuCungCaoCap
class CuaHangThuCungCaoCap : public CuaHangThuCung {
private:
    array<pair<string, double>, MAX_DICHVU> danhSachDichVu;
    int soLuongDichVu;
    double tyLeGiamGia;
    unordered_map<string, array<ThuCung, MAX_SIZE>> danhSachThuCungMacDinh;

public:
    CuaHangThuCungCaoCap(const string& ten, const string& dc, double giamGia)
        : CuaHangThuCung(ten, dc), tyLeGiamGia(giamGia), soLuongDichVu(0) {
        danhSachDichVu[soLuongDichVu++] = {"Tắm bùn khoáng", 500000.0};
        danhSachDichVu[soLuongDichVu++] = {"Cắt tỉa lông", 500000.0};
        danhSachDichVu[soLuongDichVu++] = {"Kiểm tra sức khỏe", 700000.0};
        khoiTaoDanhSachMacDinh();
        themThuCungMacDinh();
    }

    void khoiTaoDanhSachMacDinh() {
        danhSachThuCungMacDinh["Chó"] = {
            ThuCung("Bông", "Chó", 2, 2500000.0),
            ThuCung("Milo", "Chó", 1, 2000000.0),
            ThuCung("Poodle", "Chó", 3, 2600000.0)
        };
        danhSachThuCungMacDinh["Mèo"] = {
            ThuCung("Miu", "Mèo", 1, 1700000.0),
            ThuCung("Ba Tư", "Mèo", 2, 1800000.0)
        };
    }

    void themThuCungMacDinh() {
        for (const auto& loai : danhSachThuCungMacDinh) {
            for (const auto& tc : loai.second) {
                if (!tc.getTen().empty()) {
                    themThuCung(tc);
                }
            }
        }
    }

    void hienThiDanhSachDichVu() const override {
        cout << "Danh sách dịch vụ:\n";
        if (soLuongDichVu == 0) {
            cout << "Không có dịch vụ.\n";
            return;
        }
        for (int i = 0; i < soLuongDichVu; ++i) {
            cout << "- " << danhSachDichVu[i].first << ": " << fixed << setprecision(2)
                 << danhSachDichVu[i].second << " VNĐ\n";
        }
    }

    void themDichVu(const string& tenDV, double gia) override {
        if (soLuongDichVu < MAX_DICHVU) {
            danhSachDichVu[soLuongDichVu++] = {tenDV, gia};
            cout << "Đã thêm dịch vụ: " << tenDV << "\n";
        } else {
            cout << "Danh sách dịch vụ đã đầy.\n";
        }
    }

    void ghiFileDichVu(const string& filename) const override {
        ofstream ofs(filename);
        if (!ofs) {
            cout << "Không thể mở file " << filename << " để ghi.\n";
            return;
        }
        for (int i = 0; i < soLuongDichVu; ++i) {
            ofs << danhSachDichVu[i].first << "," << danhSachDichVu[i].second << "\n";
        }
        ofs.close();
        cout << "Đã ghi danh sách dịch vụ vào " << filename << "\n";
    }

    void docFileDichVu(const string& filename) override {
        ifstream ifs(filename);
        if (!ifs) {
            cout << "Không thể mở file " << filename << " để đọc.\n";
            return;
        }
        string line;
        while (getline(ifs, line)) {
            stringstream ss(line);
            string tenDV;
            double gia;
            getline(ss, tenDV, ',');
            ss >> gia;
            themDichVu(tenDV, gia);
        }
        ifs.close();
        cout << "Đã đọc danh sách dịch vụ từ " << filename << "\n";
    }

    bool timDichVu(const string& tenDV, double& gia) const {
        for (int i = 0; i < soLuongDichVu; ++i) {
            if (danhSachDichVu[i].first == tenDV) {
                gia = danhSachDichVu[i].second * (1.0 - tyLeGiamGia);
                return true;
            }
        }
        return false;
    }

    friend ostream& operator<<(ostream& os, const CuaHangThuCungCaoCap& ch) {
        os << static_cast<const CuaHangThuCung&>(ch);
        ch.hienThiDanhSachDichVu();
        return os;
    }
};

// Hàm main
int main() {
    CuaHangThuCungCaoCap cuaHang("Pet Shop Cao Cấp", "123 Đường Chính", 0.1);
    
    // Đọc dữ liệu từ file
    cuaHang.docFileThuCung("thucung.txt");
    cuaHang.docFileDichVu("dichvu.txt");
    cuaHang.docFileKhachHang("khachhang.txt");
    cuaHang.docFileKhoHang("khohang.txt");
    cuaHang.getLichSu().docFile("lichsu.txt");

    while (true) {
        cout << "\nHệ thống quản lý cửa hàng thú cưng\n";
        cout << "1. Thêm thú cưng\n";
        cout << "2. Hiển thị danh sách thú cưng và dịch vụ\n";
        cout << "3. Mua thú cưng/sản phẩm/dịch vụ\n";
        cout << "4. Quản lý kho hàng\n";
        cout << "5. Quản lý khách hàng\n";
        cout << "6. Quản lý nhân viên\n";
        cout << "7. Xem lịch sử giao dịch\n";
        cout << "8. Thoát\n";
        cout << "Nhập lựa chọn: ";
        int choice;
        cin >> choice;
        cin.ignore();

        if (choice == 8) {
            cuaHang.ghiFileThuCung("thucung.txt");
            cuaHang.ghiFileDichVu("dichvu.txt");
            cuaHang.ghiFileKhachHang("khachhang.txt");
            cuaHang.ghiFileKhoHang("khohang.txt");
            cuaHang.getLichSu().ghiFile("lichsu.txt");
            cout << "Đã lưu dữ liệu và thoát.\n";
            break;
        }

        switch (choice) {
        case 1: {
            ThuCung tc;
            cout << "Nhập thông tin thú cưng:\n";
            cin >> tc;
            cuaHang.themThuCung(tc);
            break;
        }
        case 2: {
            cout << cuaHang << "\n";
            cuaHang.hienThiNhanVien();
            cuaHang.hienThiKhachHang();
            cuaHang.hienThiKhoHang();
            break;
        }
        case 3: {
            string maKH;
            cout << "Nhập mã khách hàng: ";
            getline(cin, maKH);
            KhachHang kh;
            if (!cuaHang.timKhachHang(maKH, kh)) {
                cout << "Khách hàng không tồn tại. Nhập thông tin khách hàng mới:\n";
                kh = KhachHang();
                cin >> kh;
                cuaHang.themKhachHang(kh);
            }
            HoaDon hd("HD" + to_string(rand()), maKH, "2025-05-19");
            string loai;
            cout << "Nhập loài thú cưng muốn mua (nhập 'khong' để bỏ qua): ";
            getline(cin, loai);
            if (loai != "khong") {
                cuaHang.hienThiThuCungCanMua(loai);
                cout << "Nhập tên thú cưng muốn mua: ";
                string tenTC;
                getline(cin, tenTC);
                ThuCung tc;
                if (cuaHang.timThuCung(tenTC, loai, tc)) {
                    cout << "Nhập số lượng: ";
                    int soLuong;
                    cin >> soLuong;
                    cin.ignore();
                    hd.themThuCung(tc, soLuong);
                    for (int i = 0; i < soLuong; ++i) {
                        cuaHang.xoaThuCung(tenTC, loai);
                    }
                } else {
                    cout << "Không tìm thấy thú cưng.\n";
                }
            }
            cout << "Nhập tên dịch vụ (nhập 'khong' để bỏ qua): ";
            string tenDV;
            getline(cin, tenDV);
            if (tenDV != "khong") {
                double gia;
                if (cuaHang.timDichVu(tenDV, gia)) {
                    hd.themDichVu(tenDV, gia);
                } else {
                    cout << "Dịch vụ không tồn tại.\n";
                }
            }
            cout << "Nhập tên sản phẩm kho (nhập 'khong' để bỏ qua): ";
            string tenSP;
            getline(cin, tenSP);
            if (tenSP != "khong") {
                SanPham sp;
                if (cuaHang.timSanPham(tenSP, sp)) {
                    cout << "Nhập số lượng: ";
                    int soLuong;
                    cin >> soLuong;
                    cin.ignore();
                    if (sp.getSoLuong() >= soLuong) {
                        hd.themSanPham(sp, soLuong);
                        cuaHang.xoaSanPham(tenSP, soLuong);
                    } else {
                        cout << "Số lượng sản phẩm không đủ.\n";
                    }
                } else {
                    cout << "Sản phẩm không tồn tại.\n";
                }
            }
            if (hd.getTongTien() > 0) {
                cout << hd << "\n";
                cuaHang.capNhatDoanhThu(hd.getTongTien());
                cuaHang.getLichSu().themHoaDon(hd);
                for (int i = 0; i < cuaHang.getSoLuongKhachHang(); ++i) {
                    if (cuaHang.getKhachHangAt(i).getMaKH() == maKH) {
                        cuaHang.getKhachHangAt(i).themHoaDon(hd.getMaHoaDon());
                        break;
                    }
                }
            }
            break;
        }
        case 4: {
            cout << "1. Thêm sản phẩm\n2. Xóa sản phẩm\n3. Hiển thị kho\nNhập lựa chọn: ";
            int subChoice;
            cin >> subChoice;
            cin.ignore();
            if (subChoice == 1) {
                SanPham sp;
                cin >> sp;
                cuaHang.themSanPham(sp);
            } else if (subChoice == 2) {
                cout << "Nhập tên sản phẩm: ";
                string tenSP;
                getline(cin, tenSP);
                cout << "Nhập số lượng muốn xóa: ";
                int soLuong;
                cin >> soLuong;
                cin.ignore();
                cuaHang.xoaSanPham(tenSP, soLuong);
            } else if (subChoice == 3) {
                cuaHang.hienThiKhoHang();
            } else {
                cout << "Lựa chọn không hợp lệ.\n";
            }
            break;
        }
        case 5: {
            cout << "1. Thêm khách hàng\n2. Hiển thị khách hàng\nNhập lựa chọn: ";
            int subChoice;
            cin >> subChoice;
            cin.ignore();
            if (subChoice == 1) {
                KhachHang kh;
                cin >> kh;
                cuaHang.themKhachHang(kh);
            } else if (subChoice == 2) {
                cuaHang.hienThiKhachHang();
            } else {
                cout << "Lựa chọn không hợp lệ.\n";
            }
            break;
        }
        case 6: {
            cout << "1. Thêm nhân viên\n2. Hiển thị nhân viên\nNhập lựa chọn: ";
            int subChoice;
            cin >> subChoice;
            cin.ignore();
            if (subChoice == 1) {
                NhanVien nv;
                cin >> nv;
                cuaHang.themNhanVien(nv);
            } else if (subChoice == 2) {
                cuaHang.hienThiNhanVien();
            } else {
                cout << "Lựa chọn không hợp lệ.\n";
            }
            break;
        }
        case 7: {
            cuaHang.getLichSu().hienThiLichSu();
            break;
        }
        default:
            cout << "Lựa chọn không hợp lệ.\n";
        }
    }

    return 0;
}