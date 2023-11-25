#include <iostream>
#include<string>
#include<vector>
using namespace std;

class Doc_gia_nguoi_lon;
class Doc_gia_tre_em;
class Doc_gia{
    protected:
        string Ho_ten;
        string Ngay_lap_the;
        int So_thang_hieu_luc;
        bool danh_dau;
    public:
        Doc_gia(){
            Ho_ten = Ngay_lap_the = "";
            So_thang_hieu_luc = 0;
        }
        Doc_gia(string Ho_ten, string Ngay_lap_the, int So_thang_hieu_luc){
            this->Ho_ten = Ho_ten;
            this->Ngay_lap_the = Ngay_lap_the;
            this->So_thang_hieu_luc = So_thang_hieu_luc;
        }
        Doc_gia(const Doc_gia& other){
            Ho_ten = other.Ho_ten;
            Ngay_lap_the = other.Ngay_lap_the;
            So_thang_hieu_luc = other.So_thang_hieu_luc;
        }
        ~Doc_gia(){
            Ho_ten = Ngay_lap_the = "";
            So_thang_hieu_luc = 0;
        }
        virtual void Input(){
            cout << "Nhap Ho_ten: "; getline(cin, Ho_ten);
            cout << "Nhap Ngay_lap_the: "; cin >> Ngay_lap_the;
            cout << "Nhap So_thang_hieu_luc: "; cin >> So_thang_hieu_luc;
        }
        virtual void Output(){
            cout << "HoTen: " << Ho_ten << endl;
            cout << "NgayLapThe: " << Ngay_lap_the << endl;
            cout << "SoThangHieuLuc: " << So_thang_hieu_luc;
        }
        bool getdanh_dau(){
            return danh_dau;
        }
        void setdanh_dau(bool danh_dau){
            this->danh_dau = danh_dau;
        }
        friend istream& operator >> (istream& in, Doc_gia& other);
        friend ostream& operator << (ostream& out, Doc_gia other);
};
//
//istream& operator >> (istream& in, Doc_gia& other){
//    in.ignore();
//    cout << "Nhap Ho_ten: "; getline(in, other.Ho_ten);
//    cout << "Nhap Ngay_lap_the: "; in >> other.Ngay_lap_the;
//    cout << "Nhap So_thang_hieu_luc: "; in >> other.So_thang_hieu_luc;
//    return in;
//}
//
//ostream& operator << (ostream& out, Doc_gia other){
//    out << "HoTen: " << other.Ho_ten << endl;
//    out << "NgayLapThe: " << other.Ngay_lap_the << endl;
//    out << "SoThangHieuLuc: " << other.So_thang_hieu_luc;
//    return out;
//}

class Doc_gia_tre_em : public Doc_gia {
    private:
        string Nguoi_dai_dien;
    public:
        void Input(){
            cin.ignore();
            Doc_gia::Input(); cin.ignore();
            cout << "Nhap Nguoi_dai_dien: "; getline(cin, Nguoi_dai_dien);
        }
        void Output(){
            Doc_gia::Output(); cout << endl;
            cout << "Nguoi dai dien: " << Nguoi_dai_dien;
        }
        int Tinh_tien_lam_the(){
            return So_thang_hieu_luc*5000;
        }
};


class Doc_gia_nguoi_lon : public Doc_gia{
    private:
        string CMND;
    public:
        void Input(){
            cin.ignore();
            Doc_gia::Input(); cin.ignore();
            cout << "Nhap CMND: "; getline(cin, CMND);
        }
        void Output(){
            Doc_gia::Output(); cout << endl;
            cout << "CMND: " << CMND;
        }
        int Tinh_tien_lam_the(){
            return So_thang_hieu_luc*10000;
        }
};

class Thu_vien{
    private:
        vector<Doc_gia*> ds_docgia;
    public:
        void menu();
        void Output();

};


void Thu_vien::menu(){
    int lc;
    while(1){
        system("cls");
        cout << "\n\n\t<--------MENU------->\n";
        cout << "\t1. Nhap Doc gia tre em." << endl;
        cout << "\t2. Nhap Doc gia nguoi lon." << endl;
        cout << "\t3. Xuat DS Doc Gia tre em." << endl;
        cout << "\t4. Xuat DS Doc Gia nguoi lon." << endl;
        cout << "\t5. Xuat Tat ca DS Doc Gia theo thu tu nhap vao." << endl;
        cout << "\t0. Thoat." << endl;
        cout << "\Nhap Lua chon: ";
        cin >> lc;
        Doc_gia *x;
        if (lc == 0) break;
        else if(lc == 1){
            x = new Doc_gia_tre_em;
            cout << "\n\t\tNhap thong tin doc gia" << endl;
            x->Input(); //cin >> *x
            x->setdanh_dau(true);
            ds_docgia.push_back(x);

        }
        else if (lc == 2){
            x = new Doc_gia_nguoi_lon;
            cout << "\n\t\tNhap thong tin doc gia" << endl;
            x->Input();
            x->setdanh_dau(false);
            ds_docgia.push_back(x);
        }
        else if (lc == 3){
            cout << "\n\t<---Danh sach Doc Gia tre em--->" << endl;
            for(int i = 0; i < ds_docgia.size(); i++){
                if(ds_docgia[i]->getdanh_dau() == true) ds_docgia[i]->Output(); cout << endl;
            }
            system("pause");
        }
        else if (lc == 4){
            cout << "\n\t<---Danh sach Doc Gia nguoi lon--->" << endl;
            for(int i = 0; i < ds_docgia.size(); i++){
                if(ds_docgia[i]->getdanh_dau() == false) ds_docgia[i]->Output(); cout << endl;
            }
            system("pause");
        }
        else if (lc == 5){
            cout << "\n\<---Danh sach Doc Gia--->" << endl;
            for (int i = 0; i < ds_docgia.size(); i++){
                ds_docgia[i]->Input();
            }
        }
        else if (lc == 6){

        }
    }
}

int main()
{
    class Thu_vien x;
    x.menu();
    return 0;
}

