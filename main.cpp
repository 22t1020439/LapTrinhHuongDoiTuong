#include<bits/stdc++.h>
using namespace std;

const int Nam_ht = 2023;

class Vehicle{
    private:
        string Ma_pt;
        string Ten_pt;
        int Nam_sx;
        float Gia_ban;
    public:
        Vehicle();
        Vehicle(string Ma_pt, string Ten_pt, int Nam_sx, float Gia_ban);
        Vehicle(const Vehicle& other);
        string getMa_pt(){ return Ma_pt; }
        string getTen_pt(){ return Ten_pt; }
        int getNam_sx(){ return Nam_sx; }
        float getGia_ban(){ return Gia_ban; }
        void setMa_pt(string Ma_pt){
            this->Ma_pt = Ma_pt;
        }
        void setTen_pt(string Ten_pt){
            this->Ten_pt = Ten_pt;
        }
        void setNam_sx(int Nam_sx){
            this->Nam_sx = Nam_sx;
        }
        void setGia_ban(float Gia_ban){
            this->Gia_ban = Gia_ban;
        }
        void Input();
        void Output();
        ~Vehicle();
};


Vehicle::Vehicle(){
    Ma_pt = Ten_pt = "";
    Gia_ban = Nam_sx = 0;
}

Vehicle::Vehicle(string Ma_pt, string Ten_pt, int Nam_sx, float Gia_ban){
    this->Ma_pt = Ma_pt;
    this->Ten_pt = Ten_pt;
    this->Nam_sx = Nam_sx;
    this->Gia_ban = Gia_ban;
}

Vehicle::Vehicle(const Vehicle& other){
    this->Ma_pt = other.Ma_pt;
    this->Ten_pt = other.Ten_pt;
    this->Nam_sx = other.Nam_sx;
    this->Gia_ban = other.Gia_ban;
}

void Vehicle::Input(){
    cout << "Nhap Ma Phuong Tien: "; cin >> Ma_pt;
    cin.ignore();
    cout << "Nhap Ten Phuong Tien: "; getline(cin, Ten_pt);
    cout << "Nhap Nam san xuat: "; cin >> Nam_sx;
    cout << "Nhap Gia san pham: "; cin >> Gia_ban;
}


void Vehicle::Output(){
    cout << Ma_pt << " | " << Ten_pt << " | " << Nam_sx << " | " << Gia_ban;
}

Vehicle::~Vehicle(){
    Ma_pt = Ten_pt = "";
    Gia_ban = Nam_sx = 0;
}

class Car : public Vehicle{
    private:
        int So_cn;
        float Dung_tich;
        string Nhien_lieu;
    public:
        Car(): Vehicle(){
            So_cn = Dung_tich = 0;
            Nhien_lieu = "";
        }
        Car(string Ma_pt, string Ten_pt, int Nam_sx, float Gia_ban, int So_cn, float Dung_tich, string Nhien_lieu) : Vehicle(Ma_pt, Ten_pt, Nam_sx, Gia_ban){
            this->So_cn = So_cn;
            this->Dung_tich = Dung_tich;
            this->Nhien_lieu = Nhien_lieu;
        }
        Car(Car& other){
            this->setMa_pt(other.getMa_pt());
            this->setTen_pt(other.getTen_pt());
            this->setNam_sx(other.getNam_sx());
            this->setGia_ban(other.getGia_ban());
            this->So_cn = other.So_cn;
            this->Dung_tich = other.Dung_tich;
            this->Nhien_lieu = other.Nhien_lieu;
        }
        int getSo_cn(){
            return So_cn;
        }
        float getDung_tich(){
            return Dung_tich;
        }
        string getNhien_lieu(){
            return Nhien_lieu;
        }
        float Gia_tri_con_lai(){
            float Gia_tri = (Nhien_lieu == "Xang") ? getGia_ban()*(1 - (Nam_ht-getNam_sx())*0.1) : getGia_ban()*(1 - (Nam_ht-getNam_sx())*0.05);
            return (Gia_tri >= 0) ? Gia_tri : 0;
        }
        void setSo_cn(int So_cn){
            this->So_cn = So_cn;
        }
        void setDung_tich(float Dung_tich){
            this->Dung_tich = Dung_tich;
        }
        void setNhien_lieu(string Nhien_lieu){
            this->Nhien_lieu = Nhien_lieu;
        }
        void Input();
        void Output();
        ~Car(){
            setMa_pt("");
            setTen_pt("");
            setNam_sx(0);
            setGia_ban(0);
            So_cn = Dung_tich = 0;
            Nhien_lieu = "";
        }
        friend bool operator > (Car& a, Car& b);
};

bool operator > (Car& a, Car& b){
    return a.getGia_ban() > b.getGia_ban();
}

void Car::Input(){
    Vehicle::Input();
    cout << "Nhap so cho ngoi: "; cin >> So_cn;
    cout << "Nhap Dung Tich(cm^3): "; cin >> Dung_tich;
    cin.ignore();
    cout << "Nhap Nhien lieu: "; getline(cin, Nhien_lieu);
}

void Car::Output(){
    Vehicle::Output();
    cout << " | " << So_cn << " | " << Dung_tich << " | " << Nhien_lieu << " || " << Gia_tri_con_lai();
}

bool cmp(Car *x, Car *y){
    return y->getGia_ban() > x->getGia_ban();
}

int main(){
    vector<Car*> ds_car;
    int n;
    cout << "Nhap n doi tuong o to: "; cin >> n;
    for (int i = 0; i < n; i++){
        cout << "-->NHAP O TO " << i + 1 << ":" << endl;
        Car *x = new Car;
        x->Input();
        ds_car.push_back(x);
    }

    sort(ds_car.begin(), ds_car.end(), cmp);

    float Tong_gia_ban, Tong_gia_tri_con_lai;
    cout << endl << "DANH SACH O TO" << endl;
    for (int i = 0; i < ds_car.size(); i++){
        ds_car[i]->Output(); cout << endl;
        Tong_gia_ban += ds_car[i]->getGia_ban();
        Tong_gia_tri_con_lai += ds_car[i]->Gia_tri_con_lai();
    }

    cout << endl << "Xe o to(gia tri thap nhat): " << endl;
    ds_car[0]->Output(); cout << endl << endl;

    cout << "TONG GIA BAN: " << fixed << Tong_gia_ban << endl;
    cout << "TONG GIA TRI CON LAI: " << fixed << Tong_gia_tri_con_lai << endl;
    cout << "GIA TRI TRUNG BINH: " << fixed << Tong_gia_ban/ds_car.size() << endl;
    cout << "GIA TRI TRUNG BINH CON LAI: " << fixed << Tong_gia_tri_con_lai/ds_car.size() << endl;
    return 0;
}
