#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

// ฟังก์ชันช่วยเช็คคำสำคัญ (Keyword)
bool hasKeyword(string input, string keyword) {
    return input.find(keyword) != string::npos;
}

// --- ฟังก์ชันเจาะลึกรายละเอียดคณะ ---
void handleMajorDetails() {
    string input;
    cout << "AI: อยากทราบเกณฑ์ของคณะไหนดีครับ? (เช่น วิศวะ, บริหาร, วิทยาศาสตร์)" << endl;
    cout << "User: ";
    getline(cin, input);

    if (hasKeyword(input, "วิศวะ")) {
        cout << "AI: คณะวิศวกรรมศาสตร์ รอบนี้รับ 50 คนครับ ใช้คะแนน TGAT และ TPAT3 เกณฑ์ขั้นต่ำ GPAX 3.00 ครับ" << endl;
    } else if (hasKeyword(input, "บริหาร")) {
        cout << "AI: คณะบริหารธุรกิจ รับ 100 คนครับ เน้นคะแนนภาษาอังกฤษและคณิตศาสตร์ครับ" << endl;
    } else {
        cout << "AI: ขออภัยครับ ผมยังไม่มีข้อมูลเกณฑ์คะแนนของคณะนี้" << endl;
    }
}

// --- ฟังก์ชันหลักสำหรับการรับเข้าศึกษา ---
void handleAdmission() {
    string input;
    cout << "สนใจวางแผนเข้าวิศวฯ รอบไหนเป็นพิเศษไหมครับ? จะเป็นรอบ Portfolio (รอบ 1), โควตา (รอบ 2), Admission (รอบ 3) หรือรอบเก็บตก (รอบ 4) บอกผมได้เลยนะ เดี๋ยวผมช่วยเช็กรายละเอียดให้ครับ" << endl;
    cout << "User: ";
    getline(cin, input);

    if (hasKeyword(input, "1") || hasKeyword(input, "พอร์ต") || hasKeyword(input, "Portfolio")|| hasKeyword(input, "เกณฑ์การให้คะเเนน")) {
        cout << "รอบ 1 หรือรอบ Portfolio จะเน้นดูที่ผลงานและความสามารถของเราเป็นหลักครับ โดยจะพิจารณาจากแฟ้มสะสมผลงาน เกรดเฉลี่ย (GPAX) และการสัมภาษณ์ครับ ความพิเศษของรอบนี้คือไม่ต้องใช้คะแนนสอบข้อเขียนอย่าง TGAT/TPAT เลยครับ" << endl;
        handleMajorDetails(); // ถามลึกลงไปเรื่องคณะต่อ
    } 
    else if (hasKeyword(input, "3") || hasKeyword(input, "แอดมิชชั่น")|| hasKeyword(input, "คะเเนนอื่นๆ")) {
        cout << "AI: รอบ 3 Admission จะใช้คะแนนสอบส่วนกลางเป็นหลักครับ" << endl;
        handleMajorDetails(); // ถามลึกลงไปเรื่องคณะต่อ
    }
    else if (hasKeyword(input, "4") || hasKeyword(input, "เก็บตก")|| hasKeyword(input, "คะเเนน")) {
        cout << "AI: รอบ 4 หรือรอบเก็บตก จะใช้คะแนนสอบส่วนกลางเป็นหลักครับ" << endl;
        handleMajorDetails(); // ถามลึกลงไปเรื่องคณะต่อ
    }
    else {
        cout << "AI: สำหรับรอบอื่นๆ คุณสามารถเช็คกำหนดการได้ที่หน้าเว็บไซต์หลักครับ" << endl;
    }
}

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    string input;
    bool keepRunning = true;

    cout << "AI: สวัสดีครับ ยินดีต้อนรับสู่ ENGR CMU bot ครับ มีข้อมูลส่วนไหนของคณะวิศวกรรมศาสตร์ที่อยากให้ผมช่วยหาให้ไหมครับ? พิมพ์ถามได้เลย!" << endl;

    while (keepRunning) {
        cout << "\nUser: ";
        getline(cin, input);

        if (hasKeyword(input, "รับเข้า") || hasKeyword(input, "สมัคร")) {
            handleAdmission(); // เรียกใช้ Function เมื่อ User สนใจเรื่องการรับเข้า
        } 
        else if (hasKeyword(input, "นักศึกษา")) {
            cout << "AI: เรื่องนักศึกษา ติดต่อได้ที่กองพัฒนานักศึกษาครับ" << endl;
        } 
        else if (hasKeyword(input, "ลา") || hasKeyword(input, "พอแล้ว") || hasKeyword(input, "หยุด")|| hasKeyword(input, "ไม่มี")|| hasKeyword(input, "เเล้ว")) {
            cout << "AI: ยินดีที่ได้ช่วยเหลือครับ ขอให้โชคดีกับการเรียนนะครับ ลาก่อน!" << endl;
            keepRunning = false;
            break;
        } 
        else {
            cout << "AI: ผมอาจจะไม่เข้าใจสิ่งที่คุณพิมพ์ กุณาพิมพ์ใหม่อีกครั้งนะครับ" << endl;
        }

        // ส่วนที่ถามว่าต้องการถามอะไรอีกไหม
        if (keepRunning) {
            cout << "\nAI: ต้องการถามอะไรเพิ่มเติมอีกไหมครับ?" << endl;
        }
    }

    return 0;
}