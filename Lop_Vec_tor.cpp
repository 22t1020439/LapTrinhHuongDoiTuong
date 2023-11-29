//Câu 2:
//a. Xây dựng lớp Vector để mô tả các đối tượng vector, lớp gồm các thành phần:
//- Số phần tử có ký hiệu thuộc tính là dim
//- Một con trỏ ký hiệu thuộc tính là *vec để trỏ vào vùng nhớ chứa các phần tử dữ liệu.
//- Hàm thiết lập.
//- Hàm thiết lập sao chép.
//- Hàm nhập các phần tử của vector
//- Hàm xuất các phần tử của vector.
//- Các hàm cộng, trừ hai vector.
//- Hàm nhân để nhân một vector với một số thực, kết quả trả về một vector.
//- Hàm huỷ bỏ.
//b. Viết chương trình nhập vào hai vector a, b có cùng số phần tử, sau đó:
//- In ra màn hình vector a, vector b.
//- Tính và in ra vector a+b, a-b.

#include<bits/stdc++.h>

using namespace std;

class Vec_tor{
    private:
        int dim;
        double *vec;
    public:
        Vec_tor();
        Vec_tor(int dim, double *vec);
        Vec_tor(const Vec_tor& other);
        void nhap();
        void xuat();

        friend istream& operator >> (istream& in, Vec_tor& a);
        friend ostream& operator << (ostream& out, Vec_tor a);

        friend Vec_tor operator + (const Vec_tor& a, const Vec_tor& b);
        friend Vec_tor operator - (const Vec_tor& a, const Vec_tor& b);
        friend Vec_tor operator * (const Vec_tor& a, const Vec_tor& b);
//        friend Vec_tor operator / (const Vec_tor& a, const Vec_tor& b);
//        friend Vec_tor operator % (const Vec_tor& a, const Vec_tor& b);
//        friend Vec_tor operator += (const Vec_tor& a, const Vec_tor& b);
//        friend Vec_tor operator -= (const Vec_tor& a, const Vec_tor& b);
//        friend Vec_tor operator *= (const Vec_tor& a, const Vec_tor& b);
//        friend Vec_tor operator /= (const Vec_tor& a, const Vec_tor& b);
//        friend Vec_tor operator %= (const Vec_tor& a, const Vec_tor& b);

        friend Vec_tor operator ++ (Vec_tor& a);
        friend Vec_tor operator ++ (Vec_tor& a, int);
        friend Vec_tor operator -- (Vec_tor& a);
        friend Vec_tor operator -- (Vec_tor& a, int);
        Vec_tor& operator = (const Vec_tor& a);
        friend bool operator == (const Vec_tor& a, const Vec_tor& b);
        friend bool operator != (const Vec_tor& a, const Vec_tor& b);


//        friend Vec_tor
//        Vec_tor operator ++ ();
        double& operator [] (int index);
        double& operator () (int index);
        double sum ();
        ~Vec_tor();
};

Vec_tor::Vec_tor(){
    this->dim = 0;
    this->vec = nullptr;
}

Vec_tor::Vec_tor(int dim, double *vec){
    this->dim = dim;
    this->vec = vec;
}

Vec_tor::Vec_tor(const Vec_tor& other){
    this->dim = other.dim;
    this->vec = new double[dim];
    for (int i = 0; i < this->dim; i++){
        vec[i] = other.vec[i];
    }
}

istream& operator >> (istream& in, Vec_tor &a){
    cout << "Nhap so phan tu vector: "; in >> a.dim;
    a.vec = new double[a.dim];
    for(int i = 0; i < a.dim; i++){
        cout << "V[" << i << "] = ";
        in >> a.vec[i];
    }
    return in;
}

ostream& operator << (ostream &out, Vec_tor a){
    out << "So phan tu cua vector: " << a.dim << endl;
    for (int i = 0; i < a.dim; i++){
        out << "V[" << i << "] = " << a.vec[i] << endl;
    }
    return out;
}

void Vec_tor::nhap(){
    cout << "Nhap so phan tu vector: "; cin >> this->dim;
    vec = new double[this->dim];
    for(int i = 0; i < dim; i++){
      cout << "V[" << i << "] = ";
      cin >> this->vec[i];
    }
}

void Vec_tor::xuat(){
    cout << "So phan tu cua vector: " << this->dim << endl;
    for (int i = 0; i < dim; i++) {
      cout << vec[i] << " ";
    }
    cout << endl;
}

Vec_tor::~Vec_tor(){
    if(vec!=nullptr){
        delete [] vec;
    }
}

Vec_tor operator + (const Vec_tor& a, const Vec_tor& b){
    Vec_tor res;
    res.dim = a.dim;
    res.vec = new double[res.dim];
    for (int i = 0; i < a.dim; i++) {
      res.vec[i] = a.vec[i] + b.vec[i];
    }
    return res;
}

Vec_tor operator - (const Vec_tor& a, const Vec_tor& b){
    Vec_tor res;
    res.dim = a.dim;
    res.vec = new double[res.dim];
    for (int i = 0; i < a.dim; i++) {
      res.vec[i] = a.vec[i] - b.vec[i];
    }
    return res;
}

Vec_tor operator * (const Vec_tor& a, const Vec_tor& b){
    Vec_tor res;
    res.dim = a.dim;
    res.vec = new double[res.dim];
    for (int i = 0; i < a.dim; i++) {
      res.vec[i] = a.vec[i]* b.vec[i];
    }
    return res;
}

double& Vec_tor::operator [] (const int index){
    if (index < 0 || index >= this->dim){
        /*Đoạn code đó là một cách xử lý khi một người dùng cố gắng truy cập phần tử của vector với một chỉ số không hợp lệ (ngoài phạm vi của vector).
         Trong trường hợp này, có một số cách tiếp cận khác nhau:
        Trả về giá trị mặc định: Trong trường hợp này, nếu chỉ số nằm ngoài phạm vi của vector,
         hàm operator[] sẽ trả về một giá trị mặc định, ở đây là 0.0.
         Điều này giúp tránh lỗi runtime khi bạn truy cập một phần tử không hợp lệ và thay vào đó cung cấp một giá trị an toàn.

        Ném ngoại lệ: Thay vì trả về giá trị mặc định, bạn cũng có thể chọn ném một ngoại lệ, ví dụ như out_of_range.
         Điều này có thể giúp báo cáo lỗi ngay khi có sự cố xảy ra, thường dễ debug hơn.

        Việc sử dụng một biến dummy có kiểu dữ liệu static đảm bảo rằng nó tồn tại suốt thời gian chạy của chương trình
        và không bị giải phóng khi ra khỏi phạm vi của hàm.
         Điều này cho phép trả về một tham chiếu hợp lệ, ngay cả sau khi hàm operator[] đã kết thúc.
         Nếu bạn chọn sử dụng ngoại lệ thay vì giá trị mặc định,
         bạn có thể bỏ qua phần khai báo và sử dụng throw out_of_range("Index out of range"); thay cho return dummy;.*/
        // Trả về giá trị mặc định hoặc ném ngoại lệ
        static double dummy = 0.0;
        return dummy; // giá trị mặc định
        //throw out_of_range("Index out of range"); // giái trị ngoại lệ
    }

    return this->vec[index];
}

double& Vec_tor::operator () (int index){
    if(index < 0 || index >= this->dim){
        static double dummy = 0.0;
        return dummy;
    }
    return this->vec[index];
}

//Tiền Tố
Vec_tor operator ++ (Vec_tor &a){ // nếu ko có & gia trị sẽ ko thay đổi khi kết thúc hàm
    for (int i = 0; i < a.dim; i++){
        ++a.vec[i];
    }
    return a;
}
//Hậu Tố có thêm int
Vec_tor operator ++ (Vec_tor &a, int){ // nếu ko có & gia trị sẽ ko thay đổi khi kết thúc hàm
    for (int i = 0; i < a.dim; i++){
        a.vec[i]++;
    }
    return a;
}
//Tiền tố
Vec_tor operator -- (Vec_tor &a){
    for (int i = 0; i < a.dim; i++){
        --a.vec[i];
    }
    return a;
}
//Hậu Tố
Vec_tor operator -- (Vec_tor &a, int){
    for (int i = 0; i < a.dim; i++){
        a.vec[i]--;
    }
    return a;
}

Vec_tor& Vec_tor::operator = (const Vec_tor& a) {
    if (this != &a) {  // Tránh gán cho chính đối tượng
        delete[] vec;  // Giải phóng bộ nhớ cũ
        dim = a.dim;
        vec = new double[dim];
        for (int i = 0; i < dim; i++) {
            vec[i] = a.vec[i];
        }
    }
    return *this;
}

bool operator == (const Vec_tor &a, const Vec_tor &b){
    if (a.dim != b.dim){
        return false;
    }
    for (int i = 0; i < a.dim; i++){
        if(a.vec[i] != b.vec[i]){
            return false;
        }
    }
    return true;
}

bool operator != (const Vec_tor &a, const Vec_tor &b){
    if(a.dim == b.dim){
        for(int i = 0; i < a.dim; i++){
            if(a.dim != b.dim){
                return true;
            }
        }
        return false;
    }
    return true;
}

double Vec_tor::sum (){
    double sum;
    for (int  i = 0; i < dim; i++){
        sum += vec[i];
    }
    return sum;
}

int main(){
    Vec_tor a, b;
//    cin >> a >> b;
//    cout << a << b;
//    Vec_tor sum = a + b;
//    sum.xuat();
    Vec_tor x;
    Vec_tor y, z;
    cin >> x;
    cout << x(4);
    x[4] = 2;
    cout << x;
    return 0;
}

// int *array = new int[3]{ 1, 3, 2 };
