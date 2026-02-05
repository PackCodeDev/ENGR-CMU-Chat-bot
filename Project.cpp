#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

int main(){
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    string name;

    cout << "Chatbot : สวัสดีครับ! ยินดีต้อนรับสู่ ENGR CMU Chat Bot" << endl ;
    cout << "Chatbot : ก่อนอื่น บอกชื่อของคุณให้ผมรู้จักหน่อยได้ไหมครับ?" << endl ;
    cout << "User : ";
    getline(cin,name);

    cout << "Chatbot : " << "ยินดีที่ได้รู้จักครับ คุณ "<< name <<"! เพื่อความแม่นยำของข้อมูล" << "\n" << "กรุณาเลือกสถานะของคุณหน่อยนะครับ:" << endl;


}
