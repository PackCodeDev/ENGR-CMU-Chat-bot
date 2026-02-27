#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <algorithm>

using namespace std;

struct Major{
    string key;
    string displayName;
    string description;
    string imageSuffix;
};

void openImage(string path){
    HINSTANCE result = ShellExecuteA(NULL, "open", path.c_str(), NULL, NULL, SW_SHOWNORMAL);
    if((INT_PTR)result <= 32){
        cout << "บอท: (โน้ต: ไม่พบไฟล์รูปภาพที่ " << path << ")" << endl;
    }else{
        cout << "บอท: ผมเปิดรูปแผนการเรียนให้แล้วครับ!" << endl;
    }
}

bool hasKeyword(string input, string keyword) {
    if(input.empty() || keyword.empty()) return false;
    return input.find(keyword) != string::npos;
}

int main(){
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    vector<Major> regularMajors = {
        {"คอมพิวเตอร์", "Computer", "เรียนเกี่ยวกับด้าน Hardware, Software รวมถึงระบบเครือข่ายและการจัดการข้อมูล และการเขียนโปรแกรม", "_regular.jpg"},
        {"เครื่องกล", "Mechanical", "เป็นหัวใจของอุตสาหกรรมทุกประเภท เกี่ยวข้องกับการเคลื่อนที่ พลังงาน และการออกแบบเครื่องจักรต่างๆ", "_regular.jpg"},
        {"เซมิคอนดักเตอร์", "Semiconductor", "เทคโนโลยีชิปและอุปกรณ์อิเล็กทรอนิกส์", "_regular.jpg"},
        {"บูรณาการ", "Integrated", "หลักสูตรที่ยืดหยุ่น เน้นการนำองค์ความรู้หลายแขนงมาประยุกต์ใช้เพื่อตอบโจทย์อุตสาหกรรมสมัยใหม่", "_regular.jpg"},
        {"ไฟฟ้า", "Electrical", "ครอบคลุมตั้งแต่ความรู้ระบบไฟฟ้ากำลังที่ใช้ในเมือง ไปจนถึงระบบสื่อสารและอิเล็กทรอนิกส์ขนาดเล็ก", "_regular.jpg"},
        {"โยธา", "Civil", "เน้นการออกแบบและควบคุมการก่อสร้างโครงสร้างพื้นฐาน ตั้งแต่บ้าน อาคารสูง ไปจนถึงเขื่อนและสะพาน", "_regular.jpg"},
        {"สิ่งแวดล้อม", "Environmental", "มุ่งเน้นการแก้ปัญหามลพิษและการจัดการทรัพยากรธรรมชาติเพื่อความยั่งยืน", "_regular.jpg"},
        {"หุ่นยนต์", "REAI", "รวมเอาเครื่องกล ไฟฟ้า และคอมพิวเตอร์เข้าด้วยกัน เพื่อสร้างระบบอัตโนมัติที่ชาญฉลาด", "_regular.jpg"},
        {"เหมืองแร่", "Mining&Petroleum Engineering", "เรียนเกี่ยวกับการสำรวจ สกัด และแปรรูปทรัพยากรธรณีและพลังงานจากใต้ดิน", "_regular.jpg"},
        {"อุตสาหการ", "Industrial Engineering", "เรียนรู้วิธีการบริหารจัดการ คน เครื่องจักร และงบประมาณ ให้ทำงานร่วมกันได้อย่างมีประสิทธิภาพสูงสุด", "_regular.jpg"}
    };

    vector<Major> specialMajors = {
        {"อุตสาหการ", "Industrial", "เน้นการจัดการระบบการผลิตและห่วงโซ่อุปทานที่เชื่อมโยงกันทั่วโลก เรียนวันเสาร์-อาทิตย์ เน้นคนทำงาน", "_special.jpg"},
        {"ไฟฟ้า", "Electrical", "ยกระดับวิศวกรรมไฟฟ้าแบบเดิมเข้าสู่ยุคพลังงานสะอาดและระบบดิจิทัล ภาคพิเศษสำหรับผู้ทำงานแล้ว", "_special.jpg"},
        {"เครื่องกล", "Mechanical", "เป็นการนำพื้นฐานวิศวกรรมเครื่องกลมาบวกกับทักษะการบริหารจัดการแบบนักบริหาร", "_special.jpg"}
    };

    vector<Major> interMajors = {
        {"เครื่องกล", "Mechanical", "เน้นเรื่องการวางแผนโครงการ, การบริหารความเสี่ยง, และเศรษฐศาสตร์สำหรับวิศวกร (หลักสูตรภาษาอังกฤษ)", "_international.jpg"},
        {"บูรณาการ", "Integrated", "เน้นการแก้ปัญหาที่ต้องใช้ความรู้หลายด้าน เช่น หุ่นยนต์การแพทย์ หรือเทคโนโลยีด้านอาหาร", "_international.jpg"},
        {"ไฟฟ้า", "Electrical", "วิเคราะห์โครงสร้าง, เทคโนโลยีก่อสร้างสมัยใหม่ และภาษาอังกฤษทางวิศวกรรม", "_international.jpg"},
        {"โยธา", "Civil Engineering", "วิศวกรรมโยธาอินเตอร์ เน้นการออกแบบและก่อสร้างโครงสร้างพื้นฐานตามมาตรฐานสากล", "_international.jpg"},
        {"isne", "ISNE", "เน้นความปลอดภัยของข้อมูล ซึ่งเป็นหัวใจสำคัญของโลกดิจิทัลปัจจุบัน", "_international.jpg"},
        {"โลจิสติกส์", "Industrial Engineering and Logistics Management", "การบริหารคลังสินค้า, ระบบขนส่ง, และการปรับปรุงกระบวนการแบบ Lean", "_international.jpg"}
    };

    string input;
    string currentMode = "SELECT_PROGRAM";
    vector<Major>* currentList = nullptr;
    string programSuffix = "";

    cout << "บอท: สวัสดีครับ! ผมเป็น AI แนะนำหลักสูตรวิศวะฯ ยินดีที่ได้ช่วยเหลือครับ" << endl;
    cout << "บอท: ตอนนี้คุณสนใจ 'ภาคปกติ', 'ภาคพิเศษ' หรือ 'นานาชาติ' ดีครับ?" << endl;

    while(true){
        cout << "\nคุณ: ";
        if(!getline(cin, input) || input.empty()) continue;

        if(hasKeyword(input, "ออก") || hasKeyword(input, "พอแล้ว") || hasKeyword(input, "Exit") || hasKeyword(input, "exit")){
            cout << "บอท: ขอบคุณที่แวะมาปรึกษาครับ ขอให้ได้เรียนในคณะที่ฝันนะ!" << endl;
            break;
        }

        if(hasKeyword(input, "เริ่มใหม่") || hasKeyword(input, "เปลี่ยนภาค")){
            currentMode = "SELECT_PROGRAM";
            cout << "บอท: ได้เลยครับ! กลับมาเริ่มที่เลือกภาคใหม่ คุณเลือกภาคไหนดี?" << endl;
            continue;
        }

        if(currentMode == "SELECT_PROGRAM"){
            if(hasKeyword(input, "ปกติ") || hasKeyword(input, "normal") || hasKeyword(input, "ภาคปกติ") || hasKeyword(input, "Normal")){
                currentList = &regularMajors;
                programSuffix = "ปกติ";
                currentMode = "SELECT_MAJOR";
                cout << "บอท: ภาคปกติมีสาขาเยอะมากครับ เช่น คอมพิวเตอร์, โยธา, เครื่องกล... คุณสนใจสาขาไหนครับ?" << endl;
            } 
            else if(hasKeyword(input, "พิเศษ") || hasKeyword(input, "special") || hasKeyword(input, "ภาคพิเศษ") || hasKeyword(input, "Special")){
                currentList = &specialMajors;
                programSuffix = "พิเศษ";
                currentMode = "SELECT_MAJOR";
                cout << "บอท: ภาคพิเศษมี อุตสาหการ, ไฟฟ้า และเครื่องกล ครับ สนใจตัวไหนดี?" << endl;
            } 
            else if(hasKeyword(input, "นานาชาติ") || hasKeyword(input, "อินเตอร์") || hasKeyword(input, "inter") || hasKeyword(input, "Inter")){
                currentList = &interMajors;
                programSuffix = "นานาชาติ";
                currentMode = "SELECT_MAJOR";
                cout << "บอท: ภาคนานาชาติมีทั้ง ISNE, โลจิสติกส์, โยธา... พิมพ์ชื่อสาขามาได้เลยครับ" << endl;
            } 
            else{
                cout << "บอท: ขออภัยครับ ผมเข้าใจแค่ 'ภาคปกติ', 'ภาคพิเศษ' หรือ 'นานาชาติ' ครับ" << endl;
            }
        }
        else if(currentMode == "SELECT_MAJOR"){
            bool found = false;
            for(const auto& m : *currentList){
                if(hasKeyword(input, m.key) || hasKeyword(input, m.displayName)){
                    cout << "\n--- ข้อมูลสาขาที่พบ ---" << endl;
                    cout << "สาขา: " << m.displayName << " (" << programSuffix << ")" << endl;
                    cout << "รายละเอียด: " << m.description << endl;

                    string fullPath = "studyplan_photo\\" + m.displayName + m.imageSuffix;
                    openImage(fullPath);

                    cout << "\nบอท: สนใจสาขาอื่นอีกไหม? หรือพิมพ์ 'เริ่มใหม่' เพื่อเปลี่ยนภาคได้ครับ" << endl;
                    found = true;
                    break;
                }
            }
            if(!found){
                cout << "บอท: ไม่พบสาขา '" << input << "' ในภาค" << programSuffix << " ครับ ลองระบุใหม่นะ" << endl;
            }
        }
    }
    return 0;
}