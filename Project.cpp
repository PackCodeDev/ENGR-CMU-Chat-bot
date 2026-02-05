#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

void selectUserStatus(int *statusPtr); 
void handleAdmission();
void handleFreshman();
void handleGeneral();

int main(){
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    int select = 0; 
    string name;

    cout << "Chatbot : สวัสดีครับ! ยินดีต้อนรับสู่ ENGR CMU Chat Bot" << endl;
    cout << "Chatbot : ก่อนอื่น บอกชื่อของคุณให้ผมรู้จักหน่อยได้ไหมครับ?" << endl;
    cout << "User : ";
    getline(cin, name);

    cout << "Chatbot : ยินดีที่ได้รู้จักครับ คุณ " << name << "! เพื่อความแม่นยำของข้อมูล" << endl;

   while (true) {
        selectUserStatus(&select);

        if (select == 1) {
            handleAdmission();
        } else if (select == 2) {
            handleFreshman();
        } else if (select == 3) {
            handleGeneral();
        } else {
            cout << "Chatbot : เลือกเมนู 1-3 นะครับ" << endl;
        }
        
        cout << "\n--- กลับเข้าสู่เมนูหลัก ---\n" << endl;
    }
    return 0;
}

void selectUserStatus(int *statusPtr) {

    const char *menu[] = {
        "สนใจเข้าเรียน (Admission)",
        "นักศึกษาใหม่ปี 1 (Freshman)",
        "ถามตอบทั่วไป (General Q&A)"
    };

    int choice;
    cout << "-------------------------" << endl;
    cout << "Chatbot : กรุณาเลือกสถานะของคุณหน่อยนะครับ:" << endl;

    for (int i = 0; i < 3; i++) {
        cout << "[" << i + 1 << "] " << *(menu + i) << endl;
    }
    cout << "-------------------------" << endl;
    cout << "User (เลือกเลข): ";
    cin >> choice;

    *statusPtr = choice; 
}

void handleAdmission() {
    cout << "\nChatbot: ยินดีมากเลยครับที่คุณสนใจมาเป็นครอบครัว Entaneer CMU!" << endl;
    cout << "คณะเรามีสาขาที่น่าสนใจเพียบเลย คุณอยากทราบข้อมูลส่วนไหนครับ?" << endl;
    cout << "เช่น 'รอบรับเข้า', 'คะแนนย้อนหลัง' หรือ 'สาขาที่เปิดรับ'" << endl;
}

void handleFreshman() {
   
    cout << "\nChatbot: ยินดีด้วยนะลูกช้างใหม่! การเริ่มต้นชีวิตในรั้ววิศวะอาจจะงงหน่อย แต่ผมพร้อมเป็นคู่หูให้ครับ" << endl;

    cout << "อยากรู้เรื่องอะไรถามมาได้เลย เช่น 'ตารางสอน', 'ขึ้นดอย' หรือ 'ชุดนักศึกษา เเละอื่นๆ'" << endl;

}

void handleGeneral() {
    cout << "\nChatbot: มีเรื่องอะไรที่อยากทราบเป็นพิเศษไหมครับ? พิมพ์ถามผมได้เลย!" << endl;
}