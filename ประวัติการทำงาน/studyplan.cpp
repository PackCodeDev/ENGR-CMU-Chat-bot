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
        "REAI",
        "Mining&Petroleum Engineering",
        "Industrial Engineering",
        "ISNE"
    };

    //REG
    string regularMajors[] = {
        "Computer","Mechanical","Semiconductor","Integrated",
        "Electrical","Civil","Environmental",
        "REAI",
        "Mining&Petroleum","Industrial"
    };

    string regularDesc[] = {
        "Computer (Regular): เรียนเกี่ยวกับด้าน Hardware, Software รวมถึงระบบเครือข่ายและการจัดการข้อมูล และการเขียนโปรแกรม",
        "Mechanical (Regular): เป็นหัวใจของอุตสาหกรรมทุกประเภท เกี่ยวข้องกับการเคลื่อนที่ พลังงาน และการออกแบบเครื่องจักรต่างๆ",
        "Semiconductor (Regular): เทคโนโลยีชิปและอุปกรณ์อิเล็กทรอนิกส์",
        "Integrated (Regular): เป็นหลักสูตรที่ยืดหยุ่น เน้นการนำองค์ความรู้หลายแขนงมาประยุกต์ใช้เพื่อตอบโจทย์อุตสาหกรรมสมัยใหม่",
        "Electrical (Regular): ครอบคลุมตั้งแต่ความรู้ระบบไฟฟ้ากำลังที่ใช้ในเมือง ไปจนถึงระบบสื่อสารและอิเล็กทรอนิกส์ขนาดเล็ก",
        "Civil (Regular): เน้นการออกแบบและควบคุมการก่อสร้างโครงสร้างพื้นฐาน ตั้งแต่บ้าน อาคารสูง ถนน ไปจนถึงเขื่อนและสะพาน",
        "Environmental (Regular): มุ่งเน้นการแก้ปัญหามลพิษและการจัดการทรัพยากรธรรมชาติเพื่อความยั่งยืน",
        "REAI (Regular): รวมเอาเครื่องกล ไฟฟ้า และคอมพิวเตอร์เข้าด้วยกัน เพื่อสร้างระบบอัตโนมัติที่ชาญฉลาด",
        "Mining&Petroleum (Regular): เรียนเกี่ยวกับการสำรวจ สกัด และแปรรูปทรัพยากรธรณีและพลังงานจากใต้ดิน",
        "Industrial (Regular): เรียนรู้วิธีการบริหารจัดการ คน เครื่องจักร และงบประมาณ ให้ทำงานร่วมกันได้อย่างมีประสิทธิภาพสูงสุด"
    };

    //SPECIAL
    string specialMajors[] = {
        "Industrial","Electrical","Mechanical"
    };

    string specialDesc[] = {
        "Industrial (Special): เน้นการจัดการระบบการผลิตและห่วงโซ่อุปทานที่เชื่อมโยงกันทั่วโลก เรียนวันเสาร์-อาทิตย์ เน้นคนทำงาน",
        "Electrical (Special): ยกระดับวิศวกรรมไฟฟ้าแบบเดิมเข้าสู่ยุคพลังงานสะอาดและระบบดิจิทัล ภาคพิเศษสำหรับผู้ทำงานแล้ว",
        "Mechanical (Special): เป็นการนำพื้นฐานวิศวกรรมเครื่องกลมาบวกกับทักษะการบริหารจัดการแบบนักบริหาร"
    };

    //INTER
    string interMajors[] = {
        "Mechanical","Integrated","Electrical",
        "Civil Engineering","ISNE",
        "Industrial Engineering and Logistics Management"
    };

    string interDesc[] = {
        "Mechanical (International):  นอกจากเครื่องกลหลัก (Thermodynamics, Fluid) จะเน้นเรื่องการวางแผนโครงการ, การบริหารความเสี่ยง, และเศรษฐศาสตร์สำหรับวิศวกร",
        "Integrated (International): ไม่ได้เจาะจงสาขาเดียว แต่จะเน้นการแก้ปัญหาที่ต้องใช้ความรู้หลายด้าน เช่น หุ่นยนต์การแพทย์ หรือเทคโนโลยีด้านอาหาร",
        "Electrical (International): วิเคราะห์โครงสร้าง, เทคโนโลยีก่อสร้างสมัยใหม่, การจัดการทรัพยากรน้ำ และภาษาอังกฤษทางวิศวกรรม",
        "Civil Engineering (International): วิศวกรรมโยธาอินเตอร์ เน้นการออกแบบและก่อสร้างโครงสร้างพื้นฐานตามมาตรฐานสากล",
        "ISNE (International): เน้นความปลอดภัยของข้อมูล ซึ่งเป็นหัวใจสำคัญของโลกดิจิทัลปัจจุบัน",
        "Industrial (International): การบริหารคลังสินค้า, ระบบขนส่ง, การวิจัยดำเนินงาน (OR), และการปรับปรุงกระบวนการแบบ Lean"
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


        string imagePath = "studyplan_photo\\" + majorList[majorChoice - 1] + suffix;

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

