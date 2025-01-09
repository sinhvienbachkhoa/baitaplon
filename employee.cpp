#include <bits/stdc++.h>
#include <windows.h>

using namespace std;

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


int main(){
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
//Khi chọn nhân viên đăng nhập, hãy copy nguyên cái hàm main, paste vào cái hàm nào đó rồi gọi nó là đc
//Đang để tạm là hàm main