
#include<bits/stdc++.h>
using namespace std;

class Canbo{
    private:
        string Ma_cb;
        string Ho_ten;
        string Gioi_tinh;
    public:
        Canbo();
        Canbo(string Ma_cb, string Ho_ten, string Gioi_tinh);
        Canbo(const Canbo& other);
        string getMa_cb(){
            return Ma_cb;
        }
        string getHo_ten(){
            return Ho_ten;
        }
        string getGioi_tinh(){
            return Gioi_tinh;
        }
        void setMa_cb(string Ma_cb){
            this->Ma_cb = Ma_cb;
        }
        void setHo_ten(string Ho_ten){
            this->Ho_ten = Ho_ten;
        }
        void setGioi_tinh(string Gioi_tinh){
            this->Gioi_tinh = Gioi_tinh;
        }
        void Input();
        void Output();
        ~Canbo();
};

Canbo::Canbo(){
    Ma_cb = Ho_ten = Gioi_tinh = "";
}

Canbo::Canbo(string Ma_cb, string Ho_ten, string Gioi_tinh){
    this->Ma_cb = Ma_cb;
    this->Ho_ten = Ho_ten;
    this->Gioi_tinh = Gioi_tinh;
}

Canbo::Canbo(const Canbo& other){
    Ma_cb = other.Ma_cb;
    Ho_ten = other.Ho_ten;
    Gioi_tinh = other.Gioi_tinh;
}

void Canbo::Input(){
    cout << "Nhap Ma Can Bo: "; cin >> Ma_cb;
    cin.ignore();
    cout << "Nhap Ho Ten: "; getline(cin, Ho_ten);
    cout << "Nhap Gioi Tinh: "; cin >> Gioi_tinh;
}

void Canbo::Output(){
    cout << Ma_cb << " | " << Ho_ten << " | " << Gioi_tinh;
}

Canbo::~Canbo(){
    Ma_cb = Ho_ten = Gioi_tinh = "";
}

struct Time{
    int Ngay;
    int Thang;
    int Nam;
};

class Congnhan : public Canbo{
    private:
        int Bac_cb;
        int So_ngay_lv;
        int Ngay_ki_hop_dong;
    public:
        Congnhan() : Canbo(){
            Bac_cb = So_ngay_lv = 0;
            Ngay_ki_hop_dong = 0;
        }
        Congnhan(string Ma_cb, string Ho_ten, string Gioi_tinh, int Bac_cb, int So_ngay_lv, int Ngay_ki_hop_dong) : Canbo(Ma_cb, Ho_ten, Gioi_tinh){
            this->Bac_cb = Bac_cb;
            this->So_ngay_lv = So_ngay_lv;
            this->Ngay_ki_hop_dong = Ngay_ki_hop_dong;
        }
        int getBac_cb(){
            return Bac_cb;
        }
        int getSo_ngay_lv(){
            return So_ngay_lv;
        }
        int getNgay_ki_hop_dong(){
            return Ngay_ki_hop_dong;
        }
        float Tien_luong(){
            return getSo_ngay_lv()*(300000 + (getBac_cb() - 1)*50000);
        }
        void setBac_cb(int Bac_cb){
            this->Bac_cb = Bac_cb;
        }
        void setSo_ngay_lv(int So_ngay_lv){
            this->So_ngay_lv = So_ngay_lv;
        }
        void setNgay_ki_hop_dong(int Ngay_ki_hop_dong){
            this->Ngay_ki_hop_dong = Ngay_ki_hop_dong;
        }
        void Input(){
            Canbo::Input();
            cout << "Nhap Bac Can Bo(1-3): "; cin >> Bac_cb;
            cout << "Nhap So Ngay Lam Viec: "; cin >> So_ngay_lv;
            Time Tg;
            cout << "Nhap Ngay ki hop dong(ss hh yyyy): "; cin >> Tg.Ngay >> Tg.Thang >> Tg.Nam;
            Ngay_ki_hop_dong = Tg.Nam*420 + Tg.Thang*32 + Tg.Ngay;
        }
        void Output(){
            Canbo::Output();
            Time Tg;
            Tg.Nam = Ngay_ki_hop_dong/420; Ngay_ki_hop_dong %= 420;
            Tg.Thang = Ngay_ki_hop_dong/32; Ngay_ki_hop_dong %= 32;
            Tg.Ngay = Ngay_ki_hop_dong;
            cout << " | " << Bac_cb << " | " << So_ngay_lv << " | " << Tg.Ngay << "/" << Tg.Thang << "/" << Tg.Nam  << " | " << setprecision(0) << fixed << Tien_luong();
        }
        ~Congnhan(){
            setMa_cb("");
            setHo_ten("");
            setGioi_tinh("");
            Bac_cb = So_ngay_lv = Ngay_ki_hop_dong = 0;
        }
        friend bool operator > (Congnhan& a, Congnhan& b);
};

bool operator > (Congnhan& a, Congnhan& b){
    return a.getNgay_ki_hop_dong() > b.getNgay_ki_hop_dong();
}

bool cmp(Congnhan *a, Congnhan *b){
    return a->getNgay_ki_hop_dong() > b->getNgay_ki_hop_dong();
}

int main(){
    vector<Congnhan*> ds_Congnhan;
    int n; cout << "Nhap n doi tuong Can Bo: "; cin >> n;
    for(int i = 0; i < n; i++){
        cout << "-->>Nhap Can Bo " << i + 1 << ":" << endl;
        Congnhan *x = new Congnhan;
        x->Input();
        ds_Congnhan.push_back(x);
    }
    sort(ds_Congnhan.begin(), ds_Congnhan.end(), cmp);
    cout << endl << "DANH SACH CAN BO" << endl;
    vector<Congnhan*> ds_CongnhanNAM;
    float TienLuongCaoNhat;
    for(int i = 0; i < ds_Congnhan.size(); i++){
        ds_Congnhan[i]->Output(); cout << endl;
        if(ds_Congnhan[i]->getGioi_tinh() == "Nam"){
            ds_CongnhanNAM.push_back(ds_Congnhan[i]);
            TienLuongCaoNhat = max(TienLuongCaoNhat, ds_Congnhan[i]->Tien_luong());
        }
    }
    cout << endl << "DANH SACH CAN BO(NAM) CO TIEN LUONG CAO NHAT" << endl;
    for(int i = 0; i < ds_CongnhanNAM.size(); i++){
        if(ds_CongnhanNAM[i]->Tien_luong() == TienLuongCaoNhat){
            ds_CongnhanNAM[i]->Output(); cout << endl;
        }
    }
    return 0;
}
