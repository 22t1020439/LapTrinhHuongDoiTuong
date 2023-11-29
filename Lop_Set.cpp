#include<iostream>
using namespace std;
const int maxCard = 100;
class Set{
    private:
        int elems[maxCard];
        int card;
    public:
        Set(){
            card = 0;
        }
        Set(int elems[], int card){
            this->card = card;
            for(int i = 0; i < card; i++){
                this->elems[i] = elems[i];
            }
        }
        void Addelem (const int elem){
            this->elems[card] = elem;
            this->card += 1;
        }
        void Copy(Set &Set){
            Set.card = this->card;
            for (int i = 0; i < card; i++){
                Set.elems[i] = this->elems[i];
            }
        }
        void Print(){
            cout << "Card = " << this->card << endl;
            for (int i = 0; i < this->card; i++){
                cout << elems[i] << " ";
            }
        }
        friend bool operator & (const int, Set&);
        friend bool operator == (Set&, Set&);
        friend bool operator != (Set&, Set&);
        friend Set operator * (Set&, Set&);
        friend Set operator + (Set&, Set&);

};

bool operator & (const int n, Set &other){
    for (int i = 0; i < other.card; i++){
        if (other.elems[i] == n){
            return true;
        }
    }
    return false;
}

int main(){
    Set n;
    for(int i = 0; i < 10; i++){
        n.Addelem(i);
    }
    n.Print();
    if (11 & n){
        cout << "thuoc";
    }
    else cout << "Ko thuoc";
    return 0;
}
