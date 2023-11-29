#include<bits/stdc++.h>
using namespace std;

class Book;
class Video;
class Media{
    private:
        string Ten_goi;
        float Gia;
        bool Danh_dau;
    public:
        Media();
        Media(string, float);
        Media(const Media& other);
        string getTen_goi(){
            return Ten_goi;
        }
        float getGia(){
            return Gia;
        }
        void setTen_goi(string Ten_goi){
            this->Ten_goi = Ten_goi;
        }
        bool getDanh_dau(){
            return Danh_dau;
        }
        void setDanh_dau(bool Danh_dau){
            this->Danh_dau = Danh_dau;
        }
        void setGia(float Gia){
            this->Gia = Gia;
        }
        virtual void Nhap();
        virtual void Xuat();
        ~Media();
};

Media::Media(){
    Ten_goi = "";
    Gia = 0;
}

Media::Media(string Ten_goi, float Gia){
    this->Ten_goi = Ten_goi;
    this->Gia = Gia;
}

Media::Media(const Media& other){
    this->Ten_goi = other.Ten_goi;
    this->Gia = other.Gia;
}

void Media::Nhap(){
    cin.ignore();
    cout << "Nhap Ten goi: "; getline(cin, Ten_goi);
    cout << "Nhap Gia: "; cin >> Gia;
}

void Media::Xuat(){
    cout << "Ten goi: " << Ten_goi << endl;
    cout << "Gia: " << Gia;
}

Media::~Media(){
    Ten_goi = "";
    Gia = 0;
}

class Book : public Media{
    private:
        int So_trang;
        string Tac_gia;
    public:
        Book();
        Book(string Ten_goi, float Gia, int So_trang, string Tac_gia);
        Book(Book& other);
        int getSo_trang(){
            return So_trang;
        }
        string getTac_gia(){
            return Tac_gia;
        }
        void setSo_trang(int So_trang){
            this->So_trang = So_trang;
        }
        void setTac_gia(string Tac_gia){
            this->Tac_gia = Tac_gia;
        }
        void Nhap();
        void Xuat();
        friend bool operator > (const Book& a, const Book& b);
        ~Book();
};

Book::Book() : Media(){
    this->So_trang = 0;
    this->Tac_gia = "";
}
Book::Book(string Ten_goi, float Gia, int So_trang, string Tac_gia) : Media(Ten_goi, Gia){
    this->So_trang = So_trang;
    this->Tac_gia = Tac_gia;
}

void Book::Nhap(){
    Media::Nhap();
    cout << "Nhap So trang: "; cin >> So_trang;
    cin.ignore();
    cout << "Nhap Tac gia: "; getline(cin, Tac_gia);
}

void Book::Xuat(){
    Media::Xuat(); cout << endl;
    cout << "So trang: " << So_trang << endl;
    cout << "Tac gia: " << Tac_gia;
}
bool operator > (const Book& a, const Book& b){
    return a.So_trang > b.So_trang;
}

Book::Book(Book& other){
    this->setTen_goi(other.getTen_goi());
    this->setGia(other.getGia());
    this->So_trang = other.So_trang;
    this->Tac_gia = other.Tac_gia;
}

Book::~Book(){
    setTen_goi("");
    setGia(0);
    So_trang = 0;
    Tac_gia = "";
}

struct Time{
    int Gio;
    int Phut;
    int Giay;
};
typedef struct Time Time;

class Video : public Media{
    private:
        int Thoi_gian;
        string Nha_san_xuat;
    public:
        Video();
        Video(string Ten_goi, float Gia, int Thoi_gian, string Nha_san_xuat);
        Video(Video& other);
        int getThoi_gian(){
            return Thoi_gian;
        }
        string getNha_san_xuat(){
            return Nha_san_xuat;
        }
        void setThoi_gian(int Thoi_gian){
            this->Thoi_gian = Thoi_gian;
        }
        void setNha_san_xuat(string Nha_san_xuat){
            this->Nha_san_xuat = Nha_san_xuat;
        }
        void Nhap();
        void Xuat();
        friend bool operator > (const Video& a, const Video& b);
        ~Video();
};
Video::Video() : Media(){
    Thoi_gian = 0;
    Nha_san_xuat = "";
}
Video::Video(string Ten_goi, float Gia, int Thoi_gian, string Nha_san_xuat) : Media(Ten_goi, Gia){
    this->Thoi_gian = Thoi_gian;
    this->Nha_san_xuat = Nha_san_xuat;
}
Video::Video(Video& other){
    this->setTen_goi(other.getTen_goi());
    this->setGia(other.getGia());
    this->Thoi_gian = other.Thoi_gian;
    this->Nha_san_xuat = other.Nha_san_xuat;
}
void Video::Nhap(){
    Media::Nhap();
    cin.ignore();
    Time tg;
    cout << "Nhap Thoi gian(hh:mm:ss): "; cin >> tg.Gio >> tg.Phut >> tg.Giay;
//    Thoi_gian = to_string(tg.Gio) + ':' + to_string(tg.Phut) + ':' + to_string(tg.Giay);
    Thoi_gian = tg.Gio*3600 + tg.Phut*60 + tg.Giay;
    cin.ignore();
    cout << "Nhap Nha san xuat: "; getline(cin, Nha_san_xuat);
}

string chuanhoa(int Thoi_gian){
    Time tg;
    tg.Gio = Thoi_gian/3600;
    Thoi_gian %= 3600;
    tg.Phut = Thoi_gian/60;
    Thoi_gian %= 60;
    tg.Giay = Thoi_gian;
    return to_string(tg.Gio) + ':' + to_string(tg.Phut) + ':' + to_string(tg.Giay);
}

void Video::Xuat(){
    Media::Xuat(); cout << endl;
    cout << "Thoi gian: " << chuanhoa(Thoi_gian) << endl;
    cout << "Nha san xuat: " << Nha_san_xuat;
}

Video::~Video(){
    this->setTen_goi("");
    this->setGia(0);
    Thoi_gian = 0;
    Nha_san_xuat = "";
}

bool operator > (const Video& a, const Video& b){
    return a.Thoi_gian > b.Thoi_gian;
}

class Thu_vien{
    private:
//        vector<Media*> Thu_vien;
        vector<Book*> ds_Book;
        vector<Video*> ds_Video;
    public:
        void Menu();
};

bool cmp(Book* a, Book* b){
  return a->getSo_trang() < b->getSo_trang();
}

bool cmp1(Video* a, Video* b){
    return a->getThoi_gian() < b->getThoi_gian();
}

void Thu_vien::Menu(){
    int lc;
    while(1){
        system("cls");
        cout << "\n\n\t\t<---Menu--->" << endl;
        cout << "\t1. Nhap Book. " << endl;
        cout << "\t2. Nhap Video. " << endl;
        cout << "\t3. Xuat ds Book. " << endl;
        cout << "\t4. Xuat ds Video. " << endl;
        cout << "\t5. Sap xep Book(Theo So_trang). " << endl;
        cout << "\t6. Sap xep Video(Theo Thoi_gian). " << endl;
        cout << ">>>Nhap: "; cin >> lc;
        if (lc == 1){
            Book *x = new Book;
            x->Nhap();
            x->Xuat();
            ds_Book.push_back(x);
        }
        else if (lc == 2){
            Video *x = new Video;
            x->Nhap();
            x->Xuat();
            ds_Video.push_back(x);
        }
        else if (lc == 3){
            cout << "\t<---DS BOOK--->" << endl;
            for (int i = 0; i < ds_Book.size(); i++){
                cout << "->>BOOK" << i + 1 << endl;
                ds_Book[i]->Xuat(); cout << endl;
            }
             system("pause");
        }
        else if (lc == 4){
            cout << "\t<---DS VIDEO--->" << endl;
            for (int i = 0; i < ds_Video.size(); i++){
                cout << "->>VIDEO" << i + 1 << endl;
                ds_Video[i]->Xuat(); cout << endl;
            }
            system("pause");
        }
        else if (lc == 5){
            sort(ds_Book.begin(), ds_Book.end(), cmp);
//            for (int i = 0; i < ds_Book.size(); i++){
//                for (int j = i; j < ds_Book.size(); j++){
//                    if(ds_Book[i]->getSo_trang() > ds_Book[j]->getSo_trang()){
//                        swap(ds_Book[i], ds_Book[j]);
//                    }
//                }
//            }
        }
        else if (lc == 6){
            sort(ds_Video.begin(), ds_Video.end(), cmp1);
        }
    }
}

int main(){
    Thu_vien tv;
    tv.Menu();
    return 0;
}
