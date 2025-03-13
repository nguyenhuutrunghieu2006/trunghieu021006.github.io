// chuẩn hóa tên và ngày sinh sau đó in ra gpa từ cao xuống tháp 
// nếu cùng gpa in ra theo thứ tự mã sv tăng dần
#include <bits/stdc++.h>
using namespace std ;
class SV24DT1{
private :
    string ma , name , ngaysinh ;
    float gpa , tuoi ;
public:
    SV24DT1(){}
    SV24DT1(string ma , string name , string ngaysinh , float gpa , float tuoi ){
        this->ma = ma;
        this->name = name;
        this->ngaysinh = ngaysinh ;
        this->gpa = gpa;
        this->tuoi = tuoi;
    }
    void chuanhoaten(){
        stringstream ss(name);
        string word;
        string res;
        while(ss >> word){
            res += toupper(word[0]);
            for ( int i = 1; i < word.size() ; i++){
                res += tolower(word[i]);
            }
            res += ' ';
        }
        res.pop_back();
        this->name = res ;
    }
    void chuanhoangaysinh(){
        if(ngaysinh[2] != '/') ngaysinh = "0" + ngaysinh;
        if(ngaysinh[5] != '/') ngaysinh.insert(3, "0");
    }
    void in(){
        cout << name << ' ' << ngaysinh << ' ' << gpa << ' ' << tuoi << endl;
    }
    float getgpa(){
        return gpa;
    }
    string getma(){
        return ma;
    }
};
bool check(SV24DT1 x, SV24DT1 y){
    if(x.getgpa() != y.getgpa()){
        return x.getgpa() > y.getgpa();
    }
    else return x.getma() < y.getma();
}
//dùng mảng
int main(){
    int n ; cin >> n;
    SV24DT1 a[1000];
    for ( int i = 0; i < n ; i++){
        string ma , name , ngaysinh ;
        float gpa , tuoi ;
        cin.ignore();
        getline(cin , ma);
        getline(cin, name);
        getline(cin , ngaysinh);
        cin >> gpa >> tuoi ;
        SV24DT1 h(ma , name , ngaysinh , gpa , tuoi);
        h.chuanhoaten();
        h.chuanhoangaysinh();
        a[i] = h;
    }
    sort(a , a + n , check);
    for ( int i = 0 ; i< n ; i++){
        a[i].in();
    }
}
// dùng vector
int main(){
    int n ; cin >> n;
    vector<int> a;
    for ( int i = 0; i < n ; i++){
        string ma , name , ngaysinh ;
        float gpa , tuoi ;
        cin.ignore();
        getline(cin , ma);
        getline(cin, name);
        getline(cin , ngaysinh);
        cin >> gpa >> tuoi ;
        SV24DT1 h(ma , name , ngaysinh , gpa , tuoi);
        h.chuanhoaten();
        h.chuanhoangaysinh();
        a.push_back(h);
    }
    sort(a.begin(), a.end() , check);
    for ( int i = 0 ; i< n ; i++){
        a[i].in();
    }
}