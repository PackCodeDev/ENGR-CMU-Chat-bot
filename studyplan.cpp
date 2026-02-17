#include <windows.h>
#include <iostream>
#include <string>

using namespace std;

void openImage(string path) {
    HINSTANCE result = ShellExecuteA(NULL, "open", path.c_str(), NULL, NULL, SW_SHOWNORMAL);
    if ((INT_PTR)result <= 32) {
        cout << "เปิดรูปไม่สำเร็จ!\n";
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int programChoice, majorChoice;

    string allMajors[] = {
        "Computer",
        "Mechanical",
        "Semiconductor",
        "Integrated",
        "Electrical",
        "Civil",
        "Environmental",
        "Robotics Engineering and Artificial Intelligence",
        "Mining and Petroleum Engineering",
        "Industrial Engineering",
        "ISNE"
    };

    //REG
    string regularMajors[] = {
        "Computer","Mechanical","Semiconductor","Integrated",
        "Electrical","Civil","Environmental",
        "Robotics Engineering and Artificial Intelligence",
        "Mining and Petroleum","Industrial"
    };

    string regularDesc[] = {
        "Computer (Regular): เรียนเขียนโปรแกรม ระบบซอฟต์แวร์ และ AI",
        "Mechanical (Regular): เครื่องจักรและระบบพลังงาน",
        "Semiconductor (Regular): เทคโนโลยีชิปและอุปกรณ์อิเล็กทรอนิกส์",
        "Integrated (Regular): ระบบวงจรรวมและฮาร์ดแวร์",
        "Electrical (Regular): ระบบไฟฟ้าและพลังงาน",
        "Civil (Regular): โครงสร้าง อาคาร ถนน สะพาน",
        "Environmental (Regular): การจัดการสิ่งแวดล้อม",
        "Robotics & AI (Regular): หุ่นยนต์และปัญญาประดิษฐ์",
        "Mining & Petroleum (Regular): เหมืองแร่และปิโตรเลียม",
        "Industrial (Regular): การจัดการอุตสาหกรรม"
    };

    //SPECIAL
    string specialMajors[] = {
        "Industrial","Electrical","Mechanical"
    };

    string specialDesc[] = {
        "Industrial (Special): เรียนวันเสาร์-อาทิตย์ เน้นคนทำงาน",
        "Electrical (Special): ภาคพิเศษสำหรับผู้ทำงานแล้ว",
        "Mechanical (Special): ระบบเครื่องกลภาคพิเศษ"
    };

    //INTER
    string interMajors[] = {
        "Mechanical","Integrated","Electrical",
        "Civil Engineering","ISNE",
        "Industrial Engineering and Logistics Management"
    };

    string interDesc[] = {
        "Mechanical (International): หลักสูตรภาษาอังกฤษ",
        "Integrated (International): IC Design ภาคนานาชาติ",
        "Electrical (International): ระบบไฟฟ้าอินเตอร์",
        "Civil Engineering (International): วิศวกรรมโยธาอินเตอร์",
        "ISNE (International): Information Systems & Network English Program",
        "Industrial (International): โลจิสติกส์และการจัดการภาษาอังกฤษ"
    };

    while (true) {

        cout << "\n===== Faculty of Engineering =====\n";
        cout << "\nเมเจอร์ทั้งหมดในคณะ:\n\n";

        for (int i = 0; i < 11; i++) {
            cout << "- " << allMajors[i] << endl;
        }

        cout << "เลือกภาค\n";
        cout << "1. Regular\n";
        cout << "2. Special\n";
        cout << "3. International Program\n";
        cout << "0. Exit\n";
        cout << "เลือก: ";
        cin >> programChoice;

        if (programChoice == 0) break;
        if (programChoice < 1 || programChoice > 3) {
            cout << "เลือกไม่ถูกต้อง!\n";
            continue;
        }

        string* majorList = nullptr;
        string* descList = nullptr;
        int size = 0;
        string suffix;

        if (programChoice == 1) {
            majorList = regularMajors;
            descList = regularDesc;
            size = 10;
            suffix = "_regular.jpg";
        }
        else if (programChoice == 2) {
            majorList = specialMajors;
            descList = specialDesc;
            size = 3;
            suffix = "_special.jpg";
        }
        else {
            majorList = interMajors;
            descList = interDesc;
            size = 6;
            suffix = "_international.jpg";
        }

        cout << "\nเมเจอร์ที่เปิด:\n\n";
        for (int i = 0; i < size; i++) {
            cout << i + 1 << ". " << majorList[i] << endl;
        }

        cout << "0. กลับ\n";
        cout << "เลือกเมเจอร์: ";
        if (!(cin >> majorChoice)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "กรุณาใส่ตัวเลขเท่านั้น\n";
         continue;
        }


        if (majorChoice == 0) continue;

        if (majorChoice >= 1 && majorChoice <= size) {
        cout << "\nรายละเอียดเมเจอร์:\n";
        cout << descList[majorChoice - 1] << endl;
        }
        else {
        cout << "เลือกไม่ถูกต้อง!\n";
        continue;
        }


        string imagePath = majorList[majorChoice - 1] + suffix;

        cout << "\nกำลังเปิดรูป...\n";
        openImage(imagePath);

        int again;
        cout << "\nต้องการเลือกใหม่หรือไม่? (1=ใช่, 0=ออก): ";
        cin >> again;

        if (again == 0)
        break;

    }
    
    return 0;
}
