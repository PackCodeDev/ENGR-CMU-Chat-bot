#include <iostream>
#include <string>
#include <set>

using namespace std;

bool hasKeyword(string input, string keyword);
bool checkRegularMajor(string input);
bool checkSpecialMajor(string input);

int main() {
    system("chcp 65001 > nul"); 
    string input;
    string* selectedProgram = nullptr;
    string normalLabel = "Normal";
    string specialLabel = "Special";
    
    string selectedMajor = "";
    bool keepRunning = true;
    
    cout << "สวัสดีครับ! ผมเป็นบอทแนะนำหลักสูตรวิศวกรรมศาสตร์" << endl;
    cout << "คุณสนใจ 'ภาคปกติ' หรือ 'ภาคพิเศษ(นานาชาติ)' ครับ? (พิมพ์ 'ออก' เพื่อจบการทำงาน)" << endl;

    while(keepRunning){
        cout << "\nคุณ: ";
        if(!getline(cin, input) || input.empty()) continue;

        if(hasKeyword(input, "ออก") || hasKeyword(input, "พอแล้ว") || hasKeyword(input, "หยุด")){
            cout << "บอท: ขอบคุณที่ใช้บริการครับ!" << endl;
            keepRunning = false;
            break;
        }
        //ยังไม่ได้เลือกหลักสูตร
        if(selectedProgram == nullptr){
            if(hasKeyword(input, "ปกติ") || hasKeyword(input, "ภาคปกติ") || hasKeyword(input, "Normal") || hasKeyword(input, "normal")){
                selectedProgram = &normalLabel;
                cout << "บอท: รับทราบครับ 'ภาคปกติ' แล้วสนใจสาขาไหนครับ?" << endl;
                cout << "(เช่น คอมพิวเตอร์, โยธา, ไฟฟ้า...)" << endl;
            }else if(hasKeyword(input, "พิเศษ") || hasKeyword(input, "ภาคพิเศษ") || hasKeyword(input, "Special") || hasKeyword(input, "special")){
                selectedProgram = &specialLabel;
                cout << "บอท: ยินดีครับ 'ภาคพิเศษ(นานาชาติ)' สนใจสาขาไหนครับ?" << endl;
                cout << "(เช่น เซมิคอนดักเตอร์, ระบบสารสนเทศ...)" << endl;
            }else{
                cout << "บอท: ขอโทษครับ ผมเข้าใจแค่ 'ภาคปกติ' หรือ 'ภาคพิเศษ' กรุณาลองใหม่ครับ" << endl;
            }
        }
        //เลือกหลักสูตรแล้ว
        else{
            if(*selectedProgram == "Normal"){
                if(checkRegularMajor(input)){
                    selectedMajor = input;
                    cout << "บอท: ยอดเยี่ยม! คุณเลือก " << input << " (ภาคปกติ)" << endl;
                    cout << "พิมพ์ 'ออก' เพื่อจบ หรือพิมพ์ 'เริ่มใหม่' เพื่อเปลี่ยนหลักสูตร" << endl;
                }
            } 
            else if(*selectedProgram == "Special"){
                if(checkSpecialMajor(input)){
                    selectedMajor = input;
                    cout << "บอท: ยอดเยี่ยม! คุณเลือก " << input << " (ภาคพิเศษ)" << endl;
                    cout << "พิมพ์ 'ออก' เพื่อจบ หรือพิมพ์ 'เริ่มใหม่' เพื่อเปลี่ยนหลักสูตร" << endl;
                }
            }
            if(hasKeyword(input, "เริ่มใหม่")){
                selectedProgram = nullptr;
                cout << "บอท: รีเซ็ตระบบแล้วครับ กรุณาเลือกหลักสูตรใหม่อีกครั้ง (ปกติ/พิเศษ)" << endl;
            }
        }
    }
    return 0;
}

bool hasKeyword(string input, string keyword){
    return input.find(keyword) != string::npos;
}

bool checkRegularMajor(string input) {
    set<string> majors = {"โยธา", "ไฟฟ้า", "เครื่องกล", "อุตสาหการ", "คอมพิวเตอร์", "สิ่งแวดล้อม", "เหมืองแร่", "หุ่นยนต์", "บูรณาการ"};
    for (const string& m : majors) {
        if (hasKeyword(input, m)) return true;
    }
    cout << "บอท: ภาคปกติไม่มีสาขา '" << input << "' ครับ ลองระบุใหม่นะ" << endl;
    return false;
}

bool checkSpecialMajor(string input){
    set<string> majors = {"โครงการวิศวกรรม", "โยธา", "โลจิสติกส์", "โครงข่ายไฟฟ้า", "ไซเบอร์", "พหุวิทยาการ", "เซมิคอนดักเตอร์"};
    for(const string& m : majors){
        if(hasKeyword(input, m)) return true;
    }
    cout << "บอท: ภาคพิเศษไม่มีสาขา '" << input << "' ครับ ลองระบุใหม่นะ" << endl;
    return false;
}