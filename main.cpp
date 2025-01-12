#include <bits/stdc++.h>
#include<windows.h>
//#include<Qlabel>
using namespace std;
class banan {
    int soban;
    string trangthai;
public:
    banan(int soban, string trangthai)
    {
        this->soban = soban;
        this->trangthai = trangthai;

    }
    int getsoban()
    {
        return soban;
    }
    string gettrangthai()
    {
        return trangthai;
    }
    void settrangthai(string trangthaimoi)
    {
        trangthai = trangthaimoi;
    }
    void hienthiban()
    {
        cout << "Ban so" << soban << ": " << trangthai << endl;
    }
};
class quanlybanan
{
private:
    vector<banan> danhsachban;
public:
    quanlybanan(int soluongbanan)
    {
        for(int i = 1; i <= soluongbanan; i++)
        {
            banan k(i, "dangtrong");
            danhsachban.push_back(k);
        }
    }
    void hienthidanhsach()
    {
        for(int i = 0; i < danhsachban.size(); i++)
        {
            danhsachban[i].hienthiban();
        }
    }
    void capnhattrangthai(int soban, string trangthaimoi) {
        if (soban > 0 && soban <= danhsachban.size()) {
            danhsachban[soban - 1].settrangthai(trangthaimoi);
            cout << "da cap nhat trang thai ban " << soban << " thanh " << trangthaimoi << endl;
        } else {
            cout << "so ban khong hop le!" << endl;
        }
    }
    void kiemtratrangthaiban(int soban)
    {
        if (soban > 0 && soban <= danhsachban.size()) {
            cout << "Trang thai cua ban so " << soban << ":" << danhsachban[soban - 1].gettrangthai() << '\n';
        }
        else cout << "So ban khong hop le!" << '\n';
    }
};
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
void qlbanan()//quan ly ban an nha hang
{
    quanlybanan qlban(5);
    int opt, soban;
    string trangthai;
     cout << "Day la quan ly ban an cua nha hang! Hay nhap lua chon cua ban\n";
    cout << "__________________________\n";
    cout << "|Thu tu|        Lua chon       |\n";
    cout << "|------------------------------|\n";
    cout << "|   1  |      Xem danh sach    |\n";
    cout << "|------------------------------|\n";
    cout << "|   2  |cap nhat trang thai ban|\n";
    cout << "|------------------------------|\n";
    cout << "|   3  |kiem tra trang thai ban|\n";
    cout << "|------------------------------|\n";
    cout << "|   4  |   thoat chuong trinh  |\n";
    cout << "________________________________ nhap lua chon: ";
    cin >> opt;
    while(true)
    {
        if(kiemtradauvao(opt, 4))
        {
            switch(opt)
            {
            case 1:
                qlban.hienthidanhsach();
                break;
            case 2:
                cout << "Nhap so ban can cap nhat: ";
                cin >> soban;
                cout << "Nhap trang thai moi: ";
                cin.ignore();
                getline(cin, trangthai);
                qlban.capnhattrangthai(soban, trangthai);
                break;
            case 3:
                cout << "Nhap so ban can kiem tra: ";
                cin >> soban;
                qlban.kiemtratrangthaiban(soban);
                break;
            }
            break;
        }
        else cout << "Ban da nhap sai cu phap, vui long nhap lai!\n";
    }
}
void suathucdon()//sua thuc don
{
    cout << "ban muon them hay xoa danh sach thuc don. chon 1 neu muon them, 2 neu muon xoa!\n";
    int opt, sltd = 0;
    cin >> opt;
    while(true)
    {
        if(kiemtradauvao(opt, 2))
        {
            if(opt == 1)
            {
                cout << "nhap ten mon an ban muon them: ";
                string a;
                cin.ignore();
                getline(cin, a);
                fstream file, filesl;
                file.open("thucdon.csv", ios::app);
                filesl.open("soluong.txt");
                string s;
                while(!filesl.eof())
                {
                    getline(filesl, s);
                }
                for(int i = 0; i < s.size(); i++)
                {
                    sltd = sltd * 10 + s[i] - 48;
                }
                sltd++;
                file << sltd << ". " << a << '\n';
                file.close();
                filesl.close();
                filesl.open("soluong.txt", ios::out);
                filesl << sltd;
                filesl.close();
            }
            else
            {
                cout << "nhap so thu tu mon an ban muon xoa: ";
                int stt;
                cin >> stt;
                fstream file, filetam, filesl;
                file.open("thucdon.csv");
                filetam.open("filetam.csv", ios::app);
                filesl.open("soluong.txt", ios::out);
                filesl << '0';
                filesl.close();
                while(!file.eof())
                {
                    string s, s1 = "";
                    int so = 0;
                    getline(file, s);
                    int i = 0;
                    while(s[i] != '.')
                    {
                        so = so * 10 + s[i] - 48;
                        i++;
                    }
                    if(so == stt) continue;
                    for(int j = i + 1; j < s.size(); j++) s1 += s[j];
                    filetam << s1 << '\n';
                }
                file.close();
                filetam.close();
                file.open("thucdon.csv", ios::out);
                file.close();
                file.open("thucdon.csv", ios::app);
                filetam.open("filetam.csv");
                while(!filetam.eof())
                {
                    string s;
                    getline(filetam, s);
                    if(s == "") break;
                    string s1;
                    while(!filesl.eof())
                    {
                        getline(filesl, s1);
                    }
                    for(int i = 0; i < s1.size(); i++)
                    {
                        sltd = sltd * 10 + s1[i] - 48;
                    }
                    sltd++;
                    file << sltd << '.' << s << '\n';
                }
                filesl.open("soluong.txt", ios::out);
                filesl.close();
                filesl.open("soluong.txt", ios::app);
                filesl << sltd;
                filesl.close();
                file.close();
                filetam.close();
                filetam.open("filetam.csv", ios::out);
                filetam.close();
            }
            break;
        }
        else cout << "Ban da nhap sai cu phap, vui long nhap lai!\n";
    }
}
void inthucdon()//in thuc don nha hang
{
    fstream file;
    file.open("thucdon.csv");
    while(!file.eof())
    {
        string s;
        getline(file, s);
        cout << s << '\n';
    }
}
void quanlythucdon()// quan ly thuc don nha hang
{
    cout << "Day la thuc don cua hang! Hay nhap lua chon cua ban\n";
    cout << "__________________________\n";
    cout << "|Thu tu|     Lua chon     |\n";
    cout << "|-------------------------|\n";
    cout << "|   1  |   sua thuc don   |\n";
    cout << "|-------------------------|\n";
    cout << "|   2  |   in thuc don    |\n";
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
                    suathucdon(); break;
                case(2):
                    inthucdon(); break;
                case(3):
                    cout << "\n\t\t\t\t\t\tGoodbye and see you again ^^"; break;
            }
            break;
        }
        else cout << "Ban da nhap sai cu phap, vui long nhap lai!\n";
    }

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
    cout << "|   3  | Quan ly thuc don |\n";
    cout << "|-------------------------|\n";
    cout << "|   4  |thoat chuong trinh|\n";
    cout << "__________________________ nhap lua chon: ";
    int opt;
    while(true)
    {
        cin >> opt;
        if(kiemtradauvao(opt, 4))
        {
            switch(opt)
            {
                case(1):
                    quanlynhanvien(); break;
                case(2):
                    qlbanan(); break;
                case(3):
                    quanlythucdon(); break;
                case(4):
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
/*-----------------------------------------------------------------------------*/
void moveCursor(int x, int y){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position;
    position.X = x;
    position.Y = y;
    SetConsoleCursorPosition(hConsole, position);
    return ;
}//Di chuyển con trỏ

void deleteSection(int startX, int startY, int length){
    moveCursor(startX, startY);
    while(length){
        cout<<' ';
        --length;
    }
    return ;
}//Xóa một số kí tự nếu cần bằng cách fill string đã nhập = dấu cách

class UserCommunication{
    public:
        string selection;
        void loginInput(string &eID, string &password){
            moveCursor(31, 3);
            getline(cin, eID);
            if(eID.empty()){
                return ;
            }
            moveCursor(26, 4);
            getline(cin, password);
            if(password.empty()){
                return ;
            }
        }//Thao tác nhập username, password

        char selectionInput(string state){
            getline(cin, selection);
            if(selection.empty()){
                return 'I';
            }//nếu enter mà không nhập gì cả thì coi là sai, bắt nhập lại
            if(state == "MAIN"){
                if((selection[0] <= '3' && selection[0] >= '1')  || selection[0] == 'L' || selection[0] == 'l'){
                    return selection[0];
                }//Nếu đang ở trang main, các thao tác đều đc accept
                else{
                    return 'I';
                }
            }
            else{//nếu ở các trang con, chỉ có duy nhất tùy chọn quay về
                if(selection[0] == 'B' || selection[0] == 'b'){
                    return selection[0];
                }
                else{
                    return 'I';
                }
            }
        }//quản lý thao tác nhập lựa chọn

        void showError(string currPage){
            if(currPage == "MAIN"){
                moveCursor(1, 17);
                cout<<"Nhap sai, vui long nhap lai!";
                deleteSection(54, 13, selection.length());
                moveCursor(54, 13);

            }
            else if(currPage ==  "SCHED_INFO"){
                moveCursor(1, 25);
                cout<<"Nhap sai, vui long nhap lai!";
                deleteSection(18, 23, selection.length());
                moveCursor(18, 23);
            }
            else if(currPage == "SALARY_INFO"){
                moveCursor(54, 13);
                cout<<"Nhap sai, vui long nhap lai!";
                deleteSection(18, 15, selection.length());
                moveCursor(18, 15);
            }
            else if(currPage == "PERSONAL_INFO"){
                moveCursor(1, 17);
                cout<<"Nhap sai, vui long nhap lai!";
                deleteSection(18, 15, selection.length());
                moveCursor(18, 15);
            }
            selection.clear();
        }

        void showLoginError(){
            moveCursor(5, 5);
            cout<<"Ma so nhan vien hoac mat khau khong dung!";
            moveCursor(5, 6);
            cout<<"Khong nho thong tin dang nhap? Vui long lien he voi quan ly";
            return ;
        }//Hiển thị lỗi đăng nhập

        void employeeLoginPanel(){
            system("cls");
            cout<<"\n\n\tChao mung tro lai, vui long dang nhap de tiep tuc\n";
            cout<<"\t\tTen dang nhap: \n\t\tMat khau: ";
            return ;
        }//Màn hình đăng nhập nhân viên

        void showEmployeeMainPage(const string eID){
            system("cls");
            //printing out the info at the left top corner
            cout<<"MSNV: "<<eID<<endl;//2
            cout<<"\n\n\n"<<endl;//4,5
            cout<<"\t\t\t  _____________________________________________________________________"<<endl;//6
            cout<<"\t\t\t  |                                                                   |"<<endl;//7
            cout<<"\t\t\t  |                   VUI LONG NHAP LUA CHON CUA BAN                  |"<<endl;//8
            cout<<"\t\t\t  |                    [1]: Xem thong tin ca nhan                     |"<<endl;//9
            cout<<"\t\t\t  |                    [2]: Xem thong tin tien luong                  |"<<endl;//10
            cout<<"\t\t\t  |                    [3]: Xem lich lam viec                         |"<<endl;//11
            cout<<"\t\t\t  |                    [L]: Dang xuat                                 |"<<endl;//12
            cout<<"\t\t\t  |                                                                   |"<<endl;//13
            cout<<"\t\t\t  |         Lua chon cua ban:                                         |"<<endl;//14
            cout<<"\t\t\t  |                                                                   |"<<endl;//15
            cout<<"\t\t\t  |___________________________________________________________________|"<<endl;//16
            moveCursor(54, 13);
            return ;
        }//in màn hình chính nhân viên

        void employeePersonalInfoPage(vector <string> &data){
            system("cls");
            cout<<"\n\n\n\n\n";
            cout<<"\t\t\t       ____________________________________________________________"<<endl;//5
            cout<<"\t\t\t       |                     THONG TIN CA NHAN                    |"<<endl;//6
            cout<<"\t\t\t       |               Ho va ten:                                 |"<<endl;//7
            cout<<"\t\t\t       |               Ma nhan vien:                              |"<<endl;//8
            cout<<"\t\t\t       |               Ngay sinh:                                 |"<<endl;//9
            cout<<"\t\t\t       |               So dien thoai:                             |"<<endl;//10
            cout<<"\t\t\t       |__________________________________________________________|"<<endl;//11
            cout<<"\n  De sua doi thong tin ca nhan, vui long lien he quan ly"<<endl;//12
            cout<<"   [B]: QUAY LAI";//13
            cout<<"\nLua chon cua ban: ";//14
            moveCursor(58, 7);
            cout<<data[1];
            moveCursor(61, 8);
            cout<<data[0];
            moveCursor(58, 9);
            cout<<data[2];
            moveCursor(62, 10);
            cout<<data[3];
            moveCursor(18, 15);
            return ;
        }//in thông tin cá nhân

        void employeeSalaryInfoPage(vector <string> &data){

        }

        void employeeWorkSchedulePage(vector <string> &data){
            system("cls");
            cout<<"Chu thich: ";//1
            cout<<"\nX: Di lam";//2
            cout<<"\nO: Nghi";//3
            cout<<"\n\n\n";
            cout<<"\t\t___________________________________________________________________________________________"<<endl;//6
            cout<<"\t\t|                   |         |         |         |         |         |         |         |"<<endl;//7
            cout<<"\t\t|  Ngay/Ca lam viec |  Thu 2  |  Thu 3  |  Thu 4  |  Thu 5  |  Thu 6  |  Thu 7  | Chu nhat|"<<endl;//8
            cout<<"\t\t|___________________|_________|_________|_________|_________|_________|_________|_________|"<<endl;//9
            cout<<"\t\t|                   |         |         |         |         |         |         |         |"<<endl;//10
            cout<<"\t\t|      Ca sang      |         |         |         |         |         |         |         |"<<endl;//11
            cout<<"\t\t|   (7:45 - 11:00)  |         |         |         |         |         |         |         |"<<endl;//12
            cout<<"\t\t|___________________|_________|_________|_________|_________|_________|_________|_________|"<<endl;//13
            cout<<"\t\t|                   |         |         |         |         |         |         |         |"<<endl;//14
            cout<<"\t\t|      Ca chieu     |         |         |         |         |         |         |         |"<<endl;//15
            cout<<"\t\t|  (13:30 - 17:30)  |         |         |         |         |         |         |         |"<<endl;//16
            cout<<"\t\t|___________________|_________|_________|_________|_________|_________|_________|_________|"<<endl;//17
            cout<<"\t\t|                   |         |         |         |         |         |         |         |"<<endl;//18
            cout<<"\t\t|       Ca toi      |         |         |         |         |         |         |         |"<<endl;//19
            cout<<"\t\t|  (17:30 - 21:30)  |         |         |         |         |         |         |         |"<<endl;//20
            cout<<"\t\t|___________________|_________|_________|_________|_________|_________|_________|_________|"<<endl;//21
            cout<<"\n   [B]: QUAY LAI";//23
            cout<<"\nLua chon cua ban: ";//24
            auto it = data[1].begin();
            for(int i = 0; i < 7; ++i){
                int X = 41 + 10*i;
                for(int j = 0; j < 3; ++j){
                    moveCursor(X, 10 + 4*j);
                    cout<<*it;
                    ++it;
                }
            }//in thông tin lịch trình
            moveCursor(18, 23);
        }
        void logout(){
            system("cls");
            cout<<"Da dang xuat, dang tro ve trang chu...";
            Sleep(2500);
            return ;
        }//hiển thị trạng thái đăng xuấtxuất
};

class FileOperations{
    public:
        //bool writeFile(){}
        void readFileContents(vector<string> &storage, int numberOfElements, string fileName, string indicator){
            storage.clear();
            fstream file;
            file.open(fileName, ios::in);
            string str;
            while(!file.eof()){
                getline(file, str, '@');
                if(str != indicator){
                    getline(file, str);
                }//Nếu indicator không khớp, loại bỏ thông tin theo sau gắn với msnv
                else{//Nếu khớp, push_back() indicator vào vector string
                    storage.push_back(indicator);
                    for(int i = 0; i < numberOfElements - 1; ++i){
                        getline(file, str, '@');
                        storage.push_back(str);
                    }//push_back() thông tin gắn theo msnvmsnv
                    getline(file, str);//do string cuối cùng không kết thúc bằng @ nên phải phụ vào để đọc hoàn chỉnh thông tin
                    storage.push_back(str);
                    file.close();
                    return ;
                }
            }
            return ;
        }
};
//Class thao tác filefile


class Security{
    private:
        string eID;
        bool loginStatus;
        vector <string> data;
        FileOperations fileBrowse;
    public:
        Security() : eID("UNKNOWN"), loginStatus(false), data(2, "NO_DATA"){}
        bool authenticate(const string &eID, const string &password){
            fileBrowse.readFileContents(data, 2, "User.csv", eID);//đọc dữ liệu file User để lấy thông tin đăng nhập
            if(password == data[1]){
                this->eID = eID;
                loginStatus = true;
                return true;
            }//Nếu đúng, lưu giữ eID, chuyển trạng thái đăng nhập thành true, trả về true
            else{
                return false;
            }//Nếu sai, báo về false
        }

        bool logout(){
            loginStatus = false;
            eID = "UNKNOWN";
            return true;
        }//đăng xuất, chuyển trạng thái đăng nhập thành false, đồng thời xóa thông tin password và eID đã lưu

        string retrieveeID(){
            return eID;
        }//Hàm thao tác lấy thông tin eID

        bool checkLoginStatus(){
            return loginStatus;
        }//Hàm thao tác lấy trạng thái đăng nhập
};

class EmployeeAction{
    private:
        string eID, password;
        FileOperations file;
        vector <string> data;
    public:
        vector <string> page;
        UserCommunication user;
        Security sec;
        EmployeeAction(){
            page.push_back("MAIN");
        }
        void login(){
            user.employeeLoginPanel();
            do{
                user.loginInput(eID, password);
                if(!sec.authenticate(eID, password)){
                    deleteSection(31, 3, sizeof(eID));
                    deleteSection(26, 4, sizeof(password));
                    user.showLoginError();
                }
            }
            while(!sec.checkLoginStatus());
        }//User login

        void logout(){
            sec.logout();
            user.logout();
        }//đăng xuất

        void selectionPage(){
            user.showEmployeeMainPage(sec.retrieveeID());
        }
        void getPersonalInfo(){
            if(sec.checkLoginStatus()){
                file.readFileContents(data, 3, "PERSONAL_INFO.csv", sec.retrieveeID());
                user.employeePersonalInfoPage(data);
            }
        }
        void getSchedule(){
            if(sec.checkLoginStatus()){
                file.readFileContents(data, 2, "SCHEDULE.csv", sec.retrieveeID());
                user.employeeWorkSchedulePage(data);
            }
        }
        void getSalaryInfo(){
            if(sec.checkLoginStatus()){
                //file.readFileContents(data, , "SALARY.csv", eID);//Chưa cócó
                user.employeeSalaryInfoPage(data);
            }
        }
};

void dnnv() // trang dang nhap cho nhan vien
{
    EmployeeAction EMP1;
    EMP1.login();
    EMP1.selectionPage();
    while(EMP1.sec.checkLoginStatus()){
        char selection = EMP1.user.selectionInput(EMP1.page.back());//kiểm tra đầu vào hợp lệ
        if(selection == 'B' || selection == 'b'){
            EMP1.page.pop_back();
            EMP1.selectionPage();
        }
        else if(selection == '1'){
            EMP1.getPersonalInfo();
            EMP1.page.push_back("PERSONAL_INFO");
        }
        else if(selection == '2'){
            EMP1.getSalaryInfo();
            EMP1.page.push_back("SALARY_INFO");
        }
        else if(selection == '3'){
            EMP1.getSchedule();
            EMP1.page.push_back("SCHED_INFO");
        }
        else if(selection == 'I'){
            EMP1.user.showError(EMP1.page.back());
        }
        else if(selection == 'L' || selection == 'l'){
            EMP1.logout();
            EMP1.login();
            EMP1.selectionPage();
        }
    }
}
/*--------------------------------------------------------------------------*/
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
