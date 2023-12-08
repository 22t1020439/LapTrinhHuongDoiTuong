//Câu 1. (3.00 điểm):
//Xây dựng lớp Computer mô tả thông tin về máy tính gồm các thuộc tính: mã máy tính, hãng sản
//xuất, năm sản xuất, giá bán. Viết các phương thức cho lớp Computer bao gồm:
//- Các hàm tạo của lớp;
//- Các phương thức thiết lập và lấy thông tin của các thuộc tính;
//- Phương thức nhập dữ liệu cho các thuộc tính;
//- Phương thức hiển thị thông tin về phương tiện bao gồm: mã máy tính, hãng sản xuất, năm sản xuất,
//giá bán.

//Câu 2. (3.50 điểm):
//Xây dựng lớp Laptop mô tả thông tin về máy tính xách tay, lớp kế thừa từ lớp Computer và bổ
//sung thêm các thuộc tính: cân nặng (tính bằng gram), độ dày (tính bằng mm), kích thước màn hình (tính
//bằng inch), hệ điều hành. Viết các phương thức cho lớp Laptop bao gồm:
//- Các hàm tạo của lớp;
//- Các phương thức thiết lập và lấy thông tin của các thuộc tính;
//- Phương thức nhập dữ liệu cho các thuộc tính;
//- Phương thức hiển thị thông tin máy tính xách tay bao gồm: mã, hãng sản xuất, năm sản xuất, giá
//bán, cân nặng, độ dày, kích thước màn hình, số năm sử dụng (năm hiện thời – năm sản xuất), giá trị còn
//lại (nếu hệ điều hành sử dụng là Windows thì giá trị còn lại = giá bán - số năm sử dụng*10%*giá bán,
//nếu không thì giá trị còn lại = giá bán - số năm sử dụng*5%*giá bán; giá trị còn lại luôn lớn hơn hoặc
//bằng 0).
//- Toán tử tải bội > để so sánh hai đối tượng của lớp Laptop (dựa vào tiêu chí giá trị còn lại của
//laptop).

#include<bits/stdc++.h>
using namespace std;

const int Nam_ht = 2023;

class Computer{
    private:
        string Ma_mt;
        string Hang_sx;
        int Nam_sx;
        float Gia;
    public:
        Computer();
        Computer(string Ma_mt, string Hang_sx, int Nam_sx, float Gia);
        Computer(const Computer& other);
        string getMa_mt(){
            return Ma_mt;
        }
        string getHang_sx(){
            return Hang_sx;
        }
        int getNam_sx(){
            return Nam_sx;
        }
        float getGia(){
            return Gia;
        }
        int getNam_sd(){
            return Nam_ht - getNam_sx();
        }
        virtual float getGia_tri_con_lai(){
            return 0;
        }
        void setMa_mt(string Ma_mt){
            this->Ma_mt = Ma_mt;
        }
        void setHang_sx(string Hang_sx){
            this->Hang_sx = Hang_sx;
        }
        void setNam_sx(int Nam_sx){
            this->Nam_sx = Nam_sx;
        }
        void setGia(float Gia){
            this->Gia = Gia;
        }
        virtual void Input();
        virtual void Output();
        ~Computer();
};

Computer::Computer(){
    Ma_mt = Hang_sx = "";
    Nam_sx = Gia = 0;
}

Computer::Computer(string Ma_mt, string Hang_sx, int Nam_sx, float Gia){
    this->Ma_mt = Ma_mt;
    this->Hang_sx = Hang_sx;
    this->Nam_sx = Nam_sx;
    this->Gia = Gia;
}

Computer::Computer(const Computer& other){
    Ma_mt = other.Ma_mt;
    Hang_sx = other.Hang_sx;
    Nam_sx = other.Nam_sx;
    Gia = other.Gia;
}

void Computer::Input(){
    cout << "Nhap Ma May Tinh: "; cin >>  Ma_mt;
    cin.ignore();
    cout << "Nhap Hang San Xuat: "; getline(cin, Hang_sx);
    cout << "Nhap Nam San Xuat: "; cin >> Nam_sx;
    cout << "Nhap Gia: "; cin >> Gia;
}

void Computer::Output(){
//    cout << "Ma May Tinh: " << Ma_mt << endl;
//    cout << "Hang San Xuat: " << Hang_sx << endl;
//    cout << "Nam San Xuat: " << Nam_sx << endl;
//    cout << "Gia: " << fixed << Gia;
    cout << Ma_mt << " " << Hang_sx << " " << Nam_sx << " " << fixed << Gia << " ";
}

Computer::~Computer(){
    Ma_mt = Hang_sx = "";
    Nam_sx = Gia = 0;
}

class Laptop : public Computer{
    private:
        float Can_nang;
        float Do_day;
        float Kich_thuoc_mh;
        string He_dh;
    public:
        Laptop();
        Laptop(string Ma_mt, string Hang_sx, int Nam_sx, float Gia, float Can_nang, float Do_day, float Kich_thuoc_mh, string He_dh);
        Laptop(Laptop& other);
        float getCan_nang(){
            return Can_nang;
        }
        float getDo_day(){
            return Do_day;
        }
        float getKic_thuoc_mh(){
            return Kich_thuoc_mh;
        }
        string getHe_dh(){
            return He_dh;
        }
        float getGia_tri_con_lai(){
            if (He_dh == "Windows"){
                return getGia()*(1 - getNam_sd()*0.1);
            }
            return getGia()*(1 - getNam_sd()*0.05);
        }
        void setCan_nang(float Can_nang){
            this->Can_nang = Can_nang;
        }
        void setDo_day(float Do_day){
            this->Do_day = Do_day;
        }
        void setKich_thuoc_mh(float Kich_thuoc_mh){
            this->Kich_thuoc_mh = Kich_thuoc_mh;
        }
        void setHe_dh(string He_dh){
            this->He_dh = He_dh;
        }
        void Input();
        void Output();
        ~Laptop();
        friend bool operator > (Laptop& a, Laptop& b);
};
Laptop::Laptop():Computer(){
    Can_nang = Do_day = Kich_thuoc_mh = 0;
    He_dh = "";
}

Laptop::Laptop(string Ma_mt, string Hang_sx, int Nam_sx, float Gia, float Can_nang, float Do_day, float Kich_thuoc_mh, string He_dh) : Computer(Ma_mt, Hang_sx, Nam_sx, Gia){
    this->Can_nang = Can_nang;
    this->Do_day = Do_day;
    this->Kich_thuoc_mh = Kich_thuoc_mh;
    this->He_dh = He_dh;
}

Laptop::Laptop(Laptop& other){
    this->setMa_mt(other.getMa_mt());
    this->setHang_sx(other.getHang_sx());
    this->setNam_sx(other.getNam_sx());
    this->setGia(other.getGia());
    Can_nang = other.Can_nang;
    Do_day = other.Do_day;
    Kich_thuoc_mh = other.Kich_thuoc_mh;
    He_dh = other.He_dh;
}

void Laptop::Input(){
    Computer::Input();
    cout << "Nhap Can Nang(gram): "; cin >> Can_nang;
    cout << "Nhap Do Day(mm): "; cin >> Do_day;
    cout << "Nhap Kich Thuoc Man Hinh(inch): "; cin >> Kich_thuoc_mh;
    cin.ignore();
    cout << "Nhap He Dieu Hanh: "; getline(cin, He_dh);
}

float Gia_tri_con_lai(float Gia, string He_dh, int Nam_sx){
    if (He_dh == "Windows"){
        return abs(Gia*(1 - (Nam_ht - Nam_sx)*0.1));
    }
        return abs(Gia*(1 - (Nam_ht - Nam_sx)*0.05));
}

void Laptop::Output(){
//    Computer::Output(); cout << endl;
//    cout << "Can Nang(gram): " << Can_nang << endl;
//    cout << "Do Day(mm): " << Do_day << endl;
//    cout << "Kich Thuoc Man Hinh(inch): " << Kich_thuoc_mh << endl;
//    cout << "So Nam su dung: " << Nam_ht - getNam_sx() << endl;
//    cout << "Gia tri con lai: " << Gia_tri_con_lai(getGia(), He_dh, getNam_sx());
    Computer::Output();
    cout << Can_nang << " " << Do_day << " " << Kich_thuoc_mh << " "  << Nam_ht - getNam_sx() << " " << Gia_tri_con_lai(getGia(), He_dh, getNam_sx());
}

Laptop::~Laptop(){
    setMa_mt("");
    setHang_sx("");
    setNam_sx(0);
    setGia(0);
    Can_nang = Do_day = Kich_thuoc_mh = 0;
    He_dh = "";
}

bool operator > (Laptop& a, Laptop& b){
    if(a.getGia() > b.getGia()){
        return true;
    }
    return false;
}

//bool cmp(Laptop* a, Laptop* b){
//    if(Gia_tri_con_lai(a->getGia(), a->getHe_dh(), a->getNam_sx()) < Gia_tri_con_lai(b->getGia(), b->getHe_dh(), b->getNam_sx())){
//        return true;
//    }
//    return false;
//}

bool cmp(Computer* a, Computer *b){
    if(a->getGia_tri_con_lai() > b->getGia_tri_con_lai()){
        return true;
    }
    return false;
}

bool cmp1(Computer* a, Computer* b){
    if(a->getNam_sd() > b->getNam_sd()){
        return true;
    }
    return false;
}

class Thu_vien{
    private:
        vector<Computer*> ds_laptop;
    public:
        void menu();
};

void Thu_vien::menu(){
    while(1){
        system("cls");
        int lc;
        cout << "\n\n\t\t<---Menu--->";
        cout << "\n\t0. Thoat.";
        cout << "\n\t1. Them LapTop.";
        cout << "\n\t2. Xuat LapTop.";
        cout << "\n\t3. Xuat Danh Danh Sach LapTop(Gia tri con lai).";
        cout << "\n\t4. Xuat Danh Sach LapTop(so nam su dung nhieu nhat).";
        cout << "\n\t5. Xoa LapTop(Them Hang San Xuat).";
        cout << "\n>>>Nhap Lua chon: "; cin >> lc;
        Computer *x;
        if(lc == 0){
            cout << "KET THUC CHUONG TRINH!!!!" << endl;
            system("pause");
//            break;
        }
        else if(lc == 1){
            x = new Laptop;
            x->Input();
            ds_laptop.push_back(x);
        }
        else if (lc == 2){
            cout << "\t<<---DANH SACH LAPTOP--->>" << endl;
            for(int i = 0; i < ds_laptop.size(); i++){
                ds_laptop[i]->Output(); cout << endl;
            }
            system("pause");
        }
        else if (lc == 3){
            cout << "!!!DANH SACH LapTop(Gia tri con lai)" << endl;
            vector<Computer*> ds_laptop_ao(ds_laptop);
            sort(ds_laptop_ao.begin(), ds_laptop_ao.end(), cmp);
            for(int i = 0; i < ds_laptop_ao.size(); i++){
                ds_laptop_ao[i]->Output();
                cout << " | " << ds_laptop_ao[i]->getGia_tri_con_lai();
                cout << endl;
            }
            system("pause");
        }
        else if (lc == 4){
            cout << "!!!DANH SACH LAPTOP(So nam su dung)" << endl;
            vector<Computer*> ds_laptop_ao(ds_laptop);
            sort(ds_laptop_ao.begin(), ds_laptop_ao.end(), cmp1);
            for(int i = 0; i < ds_laptop_ao.size(); i++){
                ds_laptop_ao[i]->Output();
                cout << " | " << ds_laptop_ao[i]->getNam_sd();
                cout << endl;
            }
            system("pause");
        }
        else if (lc == 5){
            string hsx;
            cout << "Nhap HANG SAN XUAT muon xoa: "; cin >> hsx;
            for(int i = 0; i < ds_laptop.size(); i++){
                if(ds_laptop[i]->getHang_sx() == hsx){
                    ds_laptop.erase(ds_laptop.begin() + i);
                }
            }
            cout << "Da Xoa Thanh Cong!!!";
        }
    }
}

int main(){
    Thu_vien a;
    a.menu();
//    vector<Laptop*> ds_laptop;
//    int n; cout << "Nhap n: "; cin >> n;
//    int dd_Nam;
//    for (int i = 0; i < n; i++){
//        cout << "Nhap Laptop" << "[" << i + 1 << "]" << endl;
//        Laptop *a = new Laptop;
//        a->Input();
//        dd_Nam = max(dd_Nam, Nam_ht - a->getNam_sx());
//        ds_laptop.push_back(a);
//    }
//    sort(ds_laptop.begin(), ds_laptop.end(), cmp);
//    for(int i = 0; i < ds_laptop.size(); i++){
//        ds_laptop[i]->Output(); cout << endl;
//    }
//    cout << "danh sach Nam su dung nhieu nhat: " << endl;
//    for(int i = 0; i < ds_laptop.size(); i++){
//        if((Nam_ht - ds_laptop[i]->getNam_sx()) == dd_Nam){
//            ds_laptop[i]->Output();
//            cout << endl;
//        }
//    }
//    string Ma_xoa;
//    cout << "Nhap Ma Muon Xoa: "; cin >> Ma_xoa;
//    for(int i = 0; i < ds_laptop.size(); i++){
//        if(ds_laptop[i]->getHang_sx() == Ma_xoa){
//            ds_laptop.erase(ds_laptop.begin() + i);
//        }
//    }
//    cout << "Danh sach sau khi xoa: " << endl;
//    for (int i = 0; i < ds_laptop.size(); i++){
//        ds_laptop[i]->Output();
//        cout << endl;
//    }
    return 0;
}
