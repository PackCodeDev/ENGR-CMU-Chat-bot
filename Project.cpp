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

    selectUserStatus(&select);

    if (select == 1) {
        handleAdmission();
    } else if (select == 2) {
        handleFreshman();
    } else if (select == 3) {
        handleGeneral();
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
    string message;
    bool keepAsking = true; // ตัวแปรสำหรับเช็คว่าจะให้ถามต่อไหม
    cout << "\nChatbot: ยินดีด้วยนะลูกช้างใหม่! การเริ่มต้นชีวิตในรั้ววิศวะอาจจะงงหน่อย แต่ผมพร้อมเป็นคู่หูให้ครับ" << endl;

    cout << "อยากรู้เรื่องอะไรถามมาได้เลย เช่น 'ตารางสอน', 'ขึ้นดอย' หรือ 'ชุดนักศึกษา เเละอื่นๆ'" << endl;

    // ล้างบัฟเฟอร์ค้างจากเมนูก่อนหน้าเพียงครั้งเดียวที่ต้นฟังก์ชัน
    cin.ignore(1000, '\n');

    while (keepAsking) {
        cout << "\n-------------------------" << endl;
        cout << "User : ";
        getline(cin, message);

        // 1. เช็คก่อนว่า User อยากเลิกถามหรือยัง
        if (message.find("ออก") != string::npos || message.find("จบ") != string::npos || message.find("exit") != string::npos) {
            cout << "Chatbot: รับทราบครับ! ไว้คุยกันใหม่นะลูกช้าง" << endl;
            keepAsking = false; // หลุดออกจาก Loop
        }
        // 2. ตรวจสอบ Keyword อื่นๆ
        else if (message.find("ตารางสอน") != string::npos || message.find("เรียน") != string::npos) {
            cout << "Chatbot: คุณสามารถเช็คตารางเรียนได้ที่เว็บ REG CMU ครับ" << endl;
        } 
        else if (message.find("ขึ้นดอย") != string::npos) {
            cout << "Chatbot: ประเพณีขึ้นดอยปกติจะจัดช่วงต้นเทอม 1 เตรียมร่างกายให้พร้อมนะ!" << endl;
        } 
        else if (message.find("ชุดนักศึกษา") != string::npos || message.find("แต่งกาย") != string::npos) {
            cout << "Chatbot: ปี 1 แต่งกายถูกระเบียบ เชิ้ตขาว รองเท้าขาว ติดเข็มคณะครับ" << endl;
        } 
        else if (message.find("หอพัก") != string::npos || message.find("หอใน") != string::npos) {
            if (message.find("ติดต่อ") != string::npos || message.find("เบอร์") != string::npos) {
                cout << "Chatbot: ติดต่อหอพักได้ที่เบอร์โทร: 5588432331 ครับ" << endl;
            } else {
                cout << "Chatbot: น้องๆ ปี 1 ส่วนใหญ่ต้องจองหอในผ่านระบบของมหาวิทยาลัยครับ" << endl;
            }
        }
        // 3. กรณีเข้า Else (ไม่เจอ Keyword) มันจะวนลูปกลับมาให้พิมพ์ใหม่เองอัตโนมัติ
        else {
            cout << "Chatbot: ขอโทษครับ ผมยังไม่เข้าใจ... ลองถามเรื่อง 'หอพัก', 'ขึ้นดอย' หรือ 'ตารางสอน' ดูไหม?" << endl;
            cout << "Chatbot: (หรือพิมพ์ 'ออก' เพื่อเลิกถาม)" << endl;
        }
    }
}

void handleGeneral() {
    cout << "\nChatbot: มีเรื่องอะไรที่อยากทราบเป็นพิเศษไหมครับ? พิมพ์ถามผมได้เลย!" << endl;
}