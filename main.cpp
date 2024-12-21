#include <bits/stdc++.h>
#include<windows.h>
//#include<Qlabel>
using namespace std;
bool kt(string a, string b)
{
    if(a.size() != b.size()) return false;
    for(int i = 0; i < a.size(); i++)
    {
        if(a[i] != b[i]) return false;
    }
    return true;
}
class login // luu ten dang nhap, mat khau
{
private:
    string USERNAME, PASSWORD;
public:
    login(string a, string b)
    {
        USERNAME = a;
        PASSWORD = b;
    }
    void change(string a, string b)
    {
        USERNAME = a;
        PASSWORD = b;
    }
    bool check(login a)
    {
        return this->USERNAME == a.USERNAME && this->PASSWORD == a.PASSWORD;
    }
    void output()
    {
        cout << USERNAME << ' ' << PASSWORD;
    }
};
class nhanvien
{
private:
    string manv, hoten, ngaysinh;
public:
    nhanvien(string a, string b, string c)
    {
        manv = a, hoten = b, ngaysinh = c;
    }
    friend istream& operator >> (istream &in, nhanvien &a);
    friend ostream& operator << (ostream &out, nhanvien a);
};
istream& operator >> (istream &in, nhanvien &a)
{
    in >> a.manv >> a.hoten >> a.ngaysinh;
}
ostream& operator << (ostream &out, nhanvien a)
{
    cout << a.manv << a.hoten << a.ngaysinh;
}
bool kiemtradauvao(int inp, int sl) // kiem tra dau vao co hop le khong
{
    return inp <= sl && inp > 0;
}
void themnhanvien()//them nhan vien vao danh sach
{
    cout << "nhap thong tin nhan vien ban muon them\n";
    fstream file;
    file.open("dsnhanvien.csv");
    string manv, hoten, ngaysinh, lienhe;
    cout << "Manv: "; getline(cin, manv);
    bool check = false;
    while(!file.eof())
    {
        string s;
        getline(file, s, '-');
        if(s == manv)
        {
            check = true;
            break;
        }
        getline(file, s);
    }
    file.close();
    if(check == true)
    {
        cout << "manv da ton tai, vui long nhap lai!\n";
        themnhanvien();
    }
    file.open("dsnhanvien.csv", ios::app);
    cout << "Hoten: "; getline(cin, hoten);
    cout << "Ngaysinh(giua ngay, thang, nam can co dau '\'): "; getline(cin, ngaysinh);
    cout << "Lienhe: "; getline(cin, lienhe);
    file << manv << '-' << hoten << '-' << ngaysinh << '-' << lienhe;
}
void xoanhanvien()//xoa nhan vien
{
    cout << "Nhap manv cua nhan vien ban muon xoa: ";
    string manv;
    getline(cin, manv);
    fstream file, filetam;
    file.open("dsnhanvien.csv");
    filetam.open("filetam.csv");
    while(!file.eof())
    {
        string s;
        getline(file, s);
        filetam << s << '\n';
    }
    file.close();
    filetam.close();
    file.open("dsnhanvien.csv", ios::out);
    file.close();
    file.open("dsnhanvien.csv");
    filetam.open("filetam.csv");
    while(!filetam.eof())
    {
        string s;
        getline(filetam, s);
        int i;
        //cout << s;
        for(i = 0; i < 9; i++) if(s[i] != manv[i]) break;
        if(i == 9) continue;
        file << s << '\n';
    }
    filetam.close();
    filetam.open("filetam.csv", ios::out);
    filetam.close();
}
void quanlynhanvien() // trang quan ly nhan vien
{
    cout << "___________________________\n";
    cout << "|Thu tu|      Lua chon     |\n";
    cout << "|--------------------------|\n";
    cout << "|   1  |Danh sach nhan vien|\n";
    cout << "|--------------------------|\n";
    cout << "|   2  |Thong tin nhan vien|\n";
    cout << "|--------------------------|\n";
    cout << "|   3  |  Them nhan vien   |\n";
    cout << "|--------------------------|\n";
    cout << "|   4  |   xoa nhan vien   |\n";
    cout << "___________________________ nhap lua chon: ";
    int opt;
    cin >> opt;
    cin.ignore();
    while(true)
    {
        if(kiemtradauvao(opt, 4))
        {
            switch(opt)
            {
                case(1):
                    {cout << "___________________________________________________________\n";
                    cout << "|  Manv   |         Ho ten         | Ngay sinh | Lien he  |\n";
                    fstream file;
                    file.open("dsnhanvien.csv");
                    while(!file.eof())
                    {
                        string s;
                        getline(file, s, '-');
                        while(s.size() < 9) s += " ";
                        cout << "-----------------------------------------------------------\n";
                        cout << "|" << s << "|";
                        getline(file, s, '-');
                        while(s.size() < 24) s += " ";
                        cout << s << "|";
                        getline(file, s, '-');
                        while(s.size() < 11) s += " ";
                        cout << s << "|";
                        getline(file, s);
                        while(s.size() < 10) s += " ";
                        cout << s << "|\n";
                    }
                    file.close();
                    cout << "___________________________________________________________";
                    break;}
                case(2):
                    {cout << "Nhap ma so nhan vien ban can tim: ";
                    string manv;
                    bool check = false;
                    cin >> manv;
                    fstream file;
                    file.open("dsnhanvien.csv");
                    while(!file.eof())
                    {
                        string s;
                        getline(file, s, '-');
                        if(s == manv)
                        {
                            check = true;
                            cout << s << ' ';
                            getline(file, s, '-');
                            cout << s << ' ';
                            getline(file, s, '-');
                            cout << s << ' ';
                            getline(file, s);
                            cout << s << '\n';
                            break;
                        }
                        getline(file, s);
                    }
                    file.close();
                    if(!check)
                    {
                        cout << "Khong tim thay nhan vien\n";
                        quanlynhanvien();
                    }
                    break;}
                    case(3): themnhanvien();
                    case(4): xoanhanvien();
            }
        }
        break;
    }
}
void quanlybanan()
{
    cout << "Day la tinh trang ban an cua cua hang hien tai\n";

}
void trangchuquanly() // trang chu quan ly
{
    cout << "Chao mung quan ly cua hang! Hay nhap lua chon cua ban\n";
    cout << "__________________________\n";
    cout << "|Thu tu|     Lua chon     |\n";
    cout << "|-------------------------|\n";
    cout << "|   1  |Quan ly nhan vien |\n";
    cout << "|-------------------------|\n";
    cout << "|   2  |  Quan ly ban an  |\n";
    cout << "|-------------------------|\n";
    cout << "|   3  |thoat chuong trinh|\n";
    cout << "__________________________ nhap lua chon: ";
    int opt;
    while(true)
    {
        cin >> opt;
        if(kiemtradauvao(opt, 3))
        {
            switch(opt)
            {
                case(1):
                    quanlynhanvien(); break;
                case(2):
                    quanlybanan(); break;
                case(3):
                    cout << "\n\t\t\t\t\t\tGoodbye and see you again ^^"; break;
            }
            break;
        }
        else cout << "Ban da nhap sai cu phap, vui long nhap lai!\n";
    }
}
void dnql() // trang dang nhap cho quan ly
{
    fstream file;
    string username, password;
    //cin.ignore();
    cout << "\t\tdien ten dang nhap va mat khau cua ban de dang nhap sau do nhan enter de tiep tuc!\n\n\t\t\t\tUsername:";
    getline(cin, username);
    cout << "\n\t\t\t\tPassword:";
    getline(cin, password);
    login tk(username, password);
    file.open("taikhoan.csv");
    vector<login> arr;
    //kiemtrataikhoandangnhapcodungkhong
    while(!file.eof())
    {
        string s1, s2;
        getline(file, s1, '@');
        getline(file, s2);
        login a(s1, s2);
        arr.push_back(a);
    }
    int i = 0;
    for(i; i < arr.size(); i++)
    {
        if(tk.check(arr[i])) break;
    }
    char a= 178, b = 219;
    cout << "\n\t\t\t\tloading....\n\n";
    cout << "\t\t\t\t\t";
    for(int i = 0; i < 25; i++) cout << a;
    cout << "\r";
    cout << "\t\t\t\t\t";
    for(int i = 0; i < 25; i++) {cout << b; Sleep(30);}
    file.close();
    if(i == arr.size())
    {
        cout << "\nsai ten dang nhap hoac mat khau\n";
        dnql();
    }
    cout << "\n\t\t\t\t\tdangnhapThanhCong";
    Sleep(1000);
    int j = 0;
    while (j < 3) {
        system("cls"); // Xóa màn hình console
        cout << "dangchuyenhuong Loading.";
        Sleep(250);
        system("cls");
        cout << "dangchuyenhuong Loading..";
        Sleep(250);
        system("cls");
        cout << "dangchuyenhuong Loading...";
        Sleep(250);
        j++;
    }
    system("cls");
    trangchuquanly();

}
void dnnv() // trang dang nhap cho nhan vien
{
    cout << "dien ten dang nhap va mat khau cua ban de dang nhap";
}
void vaitro() // trang lua chon vai tro
{
    int opt, sl = 2;
    cout << "\t\t\t\t\t\tVai tro cua ban la gi?\n";
    cout << "\t\t\t\t\t   ";
    cout << setw(10) << left << "1. Quan ly" << setw(20) << right << "2. Nhan vien" << endl;
    while(true)
    {
        cout << "Nhap lua chon cua ban: ";
        cin >> opt;
        if(kiemtradauvao(opt, sl))
        {
           switch(opt)
           {
               case 1: cin.ignore(); dnql(); break;
               case 2: dnnv();
           }
           break;
        }
        cout << "Ban da nhap sai cu phap, vui long nhap lai!\n";

    }
}

int main()
{
    cout << "\n\t\t\t\t\tWELCOME TO THE SERVICE RESTAURANT SYSTEM";
    cout << "\n\t\t\t\t\tnhan 1 de tiep tuc, bam 2 de thoat: ";
    int opt;
    while(cin >> opt)
    {
        if(opt == 1) {vaitro(); break;}
        else if(opt == 2) {cout << "\n\t\t\t\t\t\tGoodbye and see you again ^^"; return 0;}
        else
        {
            cout << "Ban da nhap sai cu phap, vui long nhap lai!\n";
        }
    }
    return 0;
}
