#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;

// ฟังก์ชันเช็คคำสำคัญ
bool hasKeyword(string input, string keyword) {
    return input.find(keyword) != string::npos;
}

// ฟังก์ชันเช็คประวัติ
bool checkHistory(const vector<string>& history, string topic) {
    for (const string& item : history) {
        if (item == topic) return true;
    }
    return false;
}
//ฟังก์ชันสาขาโยธา //เเก้ตรงนี้ให้มันสามารถวนถามได้เรื่อยๆ


// ฟังก์ชันโยธา
void CivilMajorDetails() {
    string input;
    string name;
    bool keepRunning = true;
    vector<string> history;

    while (keepRunning) {
        cout << "AI: อยากสมัครวิศวกรรมโยธาในรอบไหนครับ?" << endl;
        cout << "User: ";
        getline(cin, input);

        bool found = false;

        if (hasKeyword(input, "1") || hasKeyword(input, "Portfolio")) {
        cout << "AI: สำหรับรอบ Portfolio ของสาขาวิศวกรรมโยธา ตอนนี้มีทั้งหมด 5 โครงการครับ  " << endl;
        cout << "AI: 1. ประเภทโครงการ การรับนักกีฬาที่มีความสามารถดีเด่นระดับนานาชาติ/ระดับชาติ และนักกีฬาตามยุทธศาสตร์  🧑‍🎓 จำนวนรับ แบบ 1.1: 2 คน, แบบ 1.2: 0 คน" << endl;
        cout << "AI: 2. ประเภทโครงการ การรับนักเรียนจาก โครงการห้องเรียนวิทยาศาสตร์ในโรงเรียน โดยการกำกับดูแลของมหาวิทยาลัย (โครงการ วมว.)  🧑‍🎓 จำนวนรับ แบบ 1.1: 5 คน, แบบ 1.2: 0 คน" << endl;
        cout << "AI: 3. ประเภทโครงการ โครงการพิเศษอื่นๆ (โครงการรับนักเรียนผู้มีความรู้ ความสามารถพิเศษ ) 🧑‍🎓จำนวนรับ แบบ 1.1: 5 คน, แบบ 1.2: 5 คน" << endl;
        cout << "AI: 4. ประเภทโครงการ โครงการพิเศษอื่นๆ (โครงการรับนักเรียนผู้มีผลการเรียนดีเด่น )  🧑‍🎓จำนวนรับ แบบ 1.1: 10 คน, แบบ 1.2: 10 คน" << endl;
        cout << "AI: 5. ประเภทโครงการ โครงการพิเศษอื่นๆ (โครงการรับนักเรียนผู้มีความรู้ ความสามารถทางวิศวกรรม )  🧑‍🎓จำนวนรับ แบบ 1.1: 10 คน, แบบ 1.2: 0 คน" << endl;
        cout << "AI: อยากสมัครวิศวกรรมโยธาในโครงการอะไรดีครับครับ🙂?" << endl;
        cout << "User: ";
        getline(cin, input);
            while (keepRunning)
            {
                cout << "AI: อยากสมัครวิศวกรรมโยธาในโครงการอะไรดีครับครับ🙂?" << endl;
                cout << "User: ";
                getline(cin, input);

                bool found = false;

                if (hasKeyword(input, "1") || hasKeyword(input, "นักกีฬา") || hasKeyword(input, "นักกีฬาตามยุทธศาสตร์")) {
                    cout << "AI: โดยทั่วไปคุณสมบัติพื้นฐานที่มักกำหนดไว้ เช่น:" << endl;
                    cout << "AI: ✔ จบหรือกำลังจะจบ ม.6 หรือเทียบเท่า (เช่น GED)" << endl;
                    cout << "AI: ✔ มีความสามารถด้านกีฬา โดดเด่นจริง (ระดับชนะเลิศ หรือได้เป็นตัวแทนแข่งขันในระดับชาติ/นานาชาติ)" << endl;
                    cout << "AI: ✔ มีผลงานหรือผลงานการแข่งขันที่สามารถนำไปอยู่ในแฟ้มสะสมงานเพื่อใช้พิจารณา" << endl;
                    
                    while (keepRunning) {
                        cout << "AI: คุณสนใจรายละเอียดเพิ่มเติมเกี่ยวกับโครงการนี้ไหมครับ?" << endl;
                        cout << "User: ";
                        getline(cin, input);

                        bool found = false;

                        if (hasKeyword(input, "1") || hasKeyword(input, "Portfolio")) {
        
                        getline(cin, input);

                        found = true;
                        

                        } 
                        if (hasKeyword(input, "ลา") || hasKeyword(input, "พอแล้ว") || hasKeyword(input, "หยุด")|| hasKeyword(input, "ไม่มี") ) {
                        cout << "AI: ลาก่อนครับ ขอให้โชคดีกับการเรียนนะครับ!" << endl;
                        keepRunning = false;
                        exit(0);
                        }
        

                        if (!found) {
                            cout << "AI: ขออภัยครับ ผมไม่เข้าใจคำที่คุณพูดครับ" << endl;
                        }

                        if (keepRunning) {
                            cout << "AI: คุณรายละเอียดที่คุณต้องการถามดูครับ" << endl;
                        }
                    }
                }
                if (hasKeyword(input, "2") || hasKeyword(input, "Portfolio")) {

                }
                if (hasKeyword(input, "3") || hasKeyword(input, "Portfolio")) {

                }
                if (hasKeyword(input, "4") || hasKeyword(input, "Portfolio")) {

                }
                if (hasKeyword(input, "5") || hasKeyword(input, "Portfolio")) {

                }

                if (!found){
                    cout << "AI: ขออภัยครับ ผมไม่เข้าใจคำที่คุณพูดครับ" << endl;
                }
                if (keepRunning)  {
                    cout << "AI: คุณลองพิมพ์ชื่อโครงการที่คุณสนใจดูครับ" << endl;
                    
                }
            }
            
            found = true;
        } 
        
        if (hasKeyword(input, "2") || hasKeyword(input, "Quota")) {
            
            found = true;
        }

        if (hasKeyword(input, "3") || hasKeyword(input, "admission")  ) {
            cout << "AI: ลาก่อนครับ ขอให้โชคดีกับการเรียนนะครับ!" << endl;
            found = true;
            
        }

        if (hasKeyword(input, "4") || hasKeyword(input, "direct admission")  | hasKeyword(input, "direct")) {
            cout << "AI: ลาก่อนครับ ขอให้โชคดีกับการเรียนนะครับ!" << endl;
            found = true;
            
        }

        if (!found) {
            cout << "AI: ขออภัยครับ ผมไม่เข้าใจคำที่คุณพูดครับ ลองพิมพ์ใหม่ได้ไหมครับ?" << endl;
            
        }

        if (keepRunning) {
            cout << "AI: การรับเข้าของคณะเรามีทั้งหมด 4 รอบครับ" << endl;
            cout << "AI: 1. รอบ (Portfolio)🧑‍🎓" << endl;
            cout << "AI: 2. รอบ (Quota) 🧑‍🎓" << endl;
            cout << "AI: 3. รอบรับตรงร่วมกับ (admission) 🧑‍🎓" << endl;
            cout << "AI: 4. รอบรับตรงอิสระ(direct admission) 🧑‍🎓" << endl;
        }
    }

   
}

void  handleMajorDetails() {
    string input;
    cout << "AI: สนใจเข้าวิศวกรรมสาขาไหนครับ?" << endl;
    cout << "User: ";
    getline(cin, input);

    if (hasKeyword(input, "โยธา") || hasKeyword(input, "Civil")) {
        CivilMajorDetails();
    } else {
        cout << "AI: " << endl;
    }
}


// --- ฟังก์ชันจัดการเนื้อหาการรับเข้า (เจาะลึก) ---
void handleAdmissionLogic() {
    string input;
    cout << "AI: ที่วิศวฯ มช. มีทั้งภาคปกติ ภาคพิเศษ และหลักสูตรนานาชาติ (English Program) สนใจดูเกณฑ์ของหลักสูตรไหนเป็นพิเศษไหมครับ?" << endl;
    cout << "User: ";
    getline(cin, input);

    if (hasKeyword(input, "ปกติ") || hasKeyword(input, "ภาคปกติ") ) {
        handleMajorDetails();
    }else {
        cout << "AI: สามารถเช็ครายละเอียดเพิ่มเติมได้ที่เว็บ Admission ของมหาวิทยาลัยครับ" << endl;
        
    } 

 }


// --- ฟังก์ชันรวม (จัดการประวัติและการเรียกฟังก์ชันย่อย) ---
void handleTopic(vector<string>& history, string topicName, string firstTimeMsg, string repeatMsg) {
    if (checkHistory(history, topicName)) {
        cout << "AI: " << repeatMsg << endl;
    } else {
        cout << "AI: " << firstTimeMsg << endl;
        history.push_back(topicName); // บันทึกว่าเคยคุยเรื่องนี้แล้ว
    }

    // ถ้าเป็นเรื่องการรับเข้า ให้ไปที่ Logic เจาะลึกต่อ
    if (topicName == "การรับเข้า") {
        handleAdmissionLogic();
    } 
    // ถ้าเป็นเรื่องนักศึกษา (คุณสามารถสร้าง handleStudentLogic เพิ่มได้ในอนาคต)
    else if (topicName == "นักศึกษา") {
        string input;
        cout << "User: ";
        getline(cin, input);
        if (hasKeyword(input, "ทุน")) {
            cout << "AI: ทุนการศึกษามีทั้งทุนเรียนดีและทุนช่วยเหลือนักศึกษาครับ" << endl;
        } else {
            cout << "AI: ติดต่อสอบถามได้ที่กองพัฒนานักศึกษาครับ" << endl;
        }
    }
}

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    string input;
    string name;
    bool keepRunning = true;
    vector<string> history;

    cout << "AI: สวัสดีครับ ยินดีต้อนรับสู่ ENGR CMU bot 😊" << endl;
    cout << "AI: ก่อนอื่น ขอทราบชื่อของคุณเพื่อใช้ในการติดต่อได้ไหมครับ?" << endl;
    cout << "User: ";
    getline(cin, name);

    cout << "AI: ยินดีที่ได้รู้จักครับ คุณ " << name << "! ผมคือ ENGR CMU bot พร้อมช่วยตอบคำถามเกี่ยวกับคณะวิศวกรรมศาสตร์ มหาวิทยาลัยเชียงใหม่ มีอะไรอยากถามสามารถถามผมได้เลยนะครับ" << endl;

    while (keepRunning) {
        cout << "User: ";
        getline(cin, input);

        bool found = false;

        if (hasKeyword(input, "รับเข้า") || hasKeyword(input, "สมัคร")) {
            handleTopic(history, "การรับเข้า", 
                        "ยินดีครับ! ", 
                        "เราเคยคุยเรื่องการรับเข้าไปแล้ว อยากเช็กข้อมูลรอบอื่นเพิ่มเติมไหม?");
            found = true;
        } 
        
        if (hasKeyword(input, "นักศึกษา") || hasKeyword(input, "ทุน")) {
            handleTopic(history, "นักศึกษา", 
                        "อยากทราบเรื่อง ทุนการศึกษา, การลงทะเบียน หรือกิจกรรมครับ?", 
                        "เรื่องนักศึกษาเราคุยกันไปแล้ว มีจุดไหนที่ยังสงสัยอยู่ไหมครับ?");
            found = true;
        }

        if (hasKeyword(input, "ลา") || hasKeyword(input, "พอแล้ว") || hasKeyword(input, "หยุด")|| hasKeyword(input, "ไม่มี") ) {
            cout << "AI: ลาก่อนครับ ขอให้โชคดีกับการเรียนนะครับ!" << endl;
            keepRunning = false;
            break;
        }

        if (!found) {
            cout << "AI: ขออภัยครับ ผมไม่เข้าใจ ลองระบุหัวข้อที่ต้องการถามใหม่ดูครับ" << endl;
        }

        if (keepRunning) {
            cout << "AI: ลองถามเเรื่อง 'การรับเข้า' หรือ 'นักศึกษา' ดูครับ" << endl;
        }
    }
    return 0;
}