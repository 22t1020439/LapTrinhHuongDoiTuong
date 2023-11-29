#include<bits/stdc++.h>
using namespace std;
class Sinh_vien;
class Nguoi{
    private:
        string Ho_dem;
        string Ten;
        string Ngay_sinh;
    public:
        Nguoi();
        Nguoi(string , string, string);
        Nguoi(const Nguoi& other);
        string getHo_dem(){
            return Ho_dem;
        }
        string getTen(){
            return Ten;
        }
        string getNgay_sinh(){
            return Ngay_sinh;
        }
        void setHo_dem(string Ho_dem){
            this->Ho_dem = Ho_dem;
        }
        void setTen(string Ten){
            this->Ten = Ten;
        }
        void setNgay_sinh(string Ngay_sinh){
            this->Ngay_sinh = Ngay_sinh;
        }
        virtual void Nhap();
        virtual void Xuat();
        friend bool operator > (const Nguoi& a, const Nguoi&b);
        ~Nguoi();
};
Nguoi::Nguoi(){
    Ho_dem = Ten = Ngay_sinh = "";
}
Nguoi::Nguoi(string Ho_dem, string Ten, string Ngay_sinh){
    this->Ho_dem = Ho_dem;
    this->Ten = Ten;
    this->Ngay_sinh = Ngay_sinh;
}
Nguoi::Nguoi(const Nguoi& other){
    Ho_dem = other.Ho_dem;
    Ten = other.Ten;
    Ngay_sinh = other.Ngay_sinh;
}

void chuanhoa(string &Ten, string &Ho_dem){
    vector<string> v;
    stringstream ss(Ten);
    string token, res = " ";
    while(ss >> token){
        v.push_back(token);
    }
    for (int i = 0; i < v.size() - 2; i++){
        Ho_dem += v[i] + ' ';
    }
    Ho_dem += v[v.size() - 2];
    Ten = v[v.size() - 1];

}

string chuanhoa2(string &Ngay_sinh){
    if(Ngay_sinh[2] != '/') Ngay_sinh = '0' + Ngay_sinh;
    if(Ngay_sinh[5] != '/') Ngay_sinh.insert(Ngay_sinh.begin() + 3, '0');
    return Ngay_sinh;
}

void Nguoi::Nhap(){
    cin.ignore();
    cout << "Nhap Ho Ten: " ; getline(cin, Ten);
    try{
        chuanhoa(Ten, Ho_dem);
    }
    catch(...){
        Ten = Ten;
        Ho_dem = "";
    }
    cout << "Nhap Nam sinh(dd/mm/yy): "; getline(cin, Ngay_sinh);
    Ngay_sinh = chuanhoa2(Ngay_sinh);
}
void Nguoi::Xuat(){
    cout << "Ho Dem: " << Ho_dem << endl;
    cout << "Ten: " << Ten << endl;
    cout << "Ngay sinh: " << Ngay_sinh;
}
bool operator > (const Nguoi& a, const Nguoi&b){
    if(a.Ten == b.Ten){
        return a.Ho_dem > b.Ho_dem;
    }
    return a.Ten > b.Ten;
}
Nguoi::~Nguoi(){
    Ten = Ho_dem = Ngay_sinh = "";
}

class Sinh_vien : public Nguoi{
    private:
        string Ma_sv;
        double Gpa;
    public:
        Sinh_vien();
        Sinh_vien(string Ten, string Ho_dem, string Ngay_sinh, string Ma_sv, double Gpa);
        Sinh_vien(Sinh_vien& other);
        string getMa_sv(){
            return Ma_sv;
        }
        double getGpa(){
            return Gpa;
        }
        void setMa_sv(string Ma_sv){
            this->Ma_sv = Ma_sv;
        }
        void setGpa(double Gpa){
            this->Gpa = Gpa;
        }
        void Nhap();
        void Xuat();
        friend bool operator > (Sinh_vien& a, Sinh_vien& b);
        ~Sinh_vien();
};

Sinh_vien::Sinh_vien() : Nguoi(){
    Ma_sv = "";
    Gpa = 0;
}

Sinh_vien::Sinh_vien(string Ten, string Ho_dem, string Ngay_sinh, string Ma_sv, double Gpa) : Nguoi(Ten, Ho_dem, Ngay_sinh){
    this->Ma_sv = Ma_sv;
    this->Gpa = Gpa;
}

Sinh_vien::Sinh_vien(Sinh_vien& other){
    this->setTen(other.getMa_sv());
    this->setHo_dem(other.getHo_dem());
    this->setNgay_sinh(other.getNgay_sinh());
    Ma_sv = other.Ma_sv;
    Gpa = other.Gpa;
}

void Sinh_vien::Nhap(){
    Nguoi::Nhap();
    cout << "Nhap Ma sv: "; getline(cin, Ma_sv);
    cout << "Nhap Gpa: "; cin >> Gpa;
}

void Sinh_vien::Xuat(){
    Nguoi::Xuat(); cout << endl;
    cout << "Ma sv: " << Ma_sv << endl;
    cout << "Gpa: " << Gpa;
}

//bool operator > (Sinh_vien& a, Sinh_vien& b){
//    if(a.getTen() != b.getTen()){
//        return a.getTen() > b.getTen();
//    }
//    return a.getHo_dem() > b.getHo_dem();
//}

Sinh_vien::~Sinh_vien(){
    this->setTen("");
    this->setHo_dem("");
    this->setNgay_sinh("");
    Ma_sv = "";
    Gpa = 0;
}

class Thu_vien{
    private:
        vector<Sinh_vien*> ds_Sinhvien;
    public:
        void Menu();
};

bool cmp(Sinh_vien* a, Sinh_vien *b){
    if(a->getTen() != b->getTen()){
        return a->getTen() < b->getTen();
    }
    return a->getHo_dem() < b->getHo_dem();
}

void Thu_vien::Menu(){
    int lc;
    while(1){
        system("cls");
        cout << "\n\n\t\t<---Menu--->" << endl;
        cout << "\t1. Nhap Sinh Vien." << endl;
        cout << "\t2. Xuat Sinh Vien." << endl;
        cout << "\t3. Sap Xep Tang Dan." << endl;
        cout << "\t4. Xuat Sinh Vien(Gpa cao nhat): " << endl;
        cout << ">>>Nhap: "; cin >> lc;
        if(lc == 1){
            Sinh_vien *x = new Sinh_vien;
            x->Nhap();
            ds_Sinhvien.push_back(x);
        }
        else if(lc == 2){
            cout << "\t<---DS SINH VIEN--->" << endl;
            for (int i = 0; i < ds_Sinhvien.size(); i++){
                cout << "->>SV" << i + 1 << endl;
                ds_Sinhvien[i]->Xuat();
                cout << endl;
            }
            system("pause");
        }
        else if(lc == 3){
            sort(ds_Sinhvien.begin(), ds_Sinhvien.end(), cmp);
            cout << "DANH SACH SINH VIEN DA DUOC SAP XEP!!!!" << endl;
            system("pause");
        }

    }
}

int main(){
    Thu_vien x;
    x.Menu();
    return 0;
}
