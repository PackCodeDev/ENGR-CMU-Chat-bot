#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <conio.h> // สำหรับใช้ _getch()
#include <cstdlib>

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
        cout << "    1. ประเภทโครงการ การรับนักกีฬาที่มีความสามารถดีเด่นระดับนานาชาติ/ระดับชาติ และนักกีฬาตามยุทธศาสตร์  🧑‍🎓 จำนวนรับ แบบ 1.1: 2 คน, แบบ 1.2: 0 คน" << endl;
        cout << "    2. ประเภทโครงการ การรับนักเรียนจาก โครงการห้องเรียนวิทยาศาสตร์ในโรงเรียน โดยการกำกับดูแลของมหาวิทยาลัย (โครงการ วมว.)  🧑‍🎓 จำนวนรับ แบบ 1.1: 5 คน, แบบ 1.2: 0 คน" << endl;
        cout << "    3. ประเภทโครงการ โครงการพิเศษอื่นๆ (โครงการรับนักเรียนผู้มีความรู้ ความสามารถพิเศษ ) 🧑‍🎓จำนวนรับ แบบ 1.1: 5 คน, แบบ 1.2: 5 คน" << endl;
        cout << "    4. ประเภทโครงการ โครงการพิเศษอื่นๆ (โครงการรับนักเรียนผู้มีผลการเรียนดีเด่น )  🧑‍🎓จำนวนรับ แบบ 1.1: 10 คน, แบบ 1.2: 10 คน" << endl;
        cout << "    5. ประเภทโครงการ โครงการพิเศษอื่นๆ (โครงการรับนักเรียนผู้มีความรู้ ความสามารถทางวิศวกรรม )  🧑‍🎓จำนวนรับ แบบ 1.1: 10 คน, แบบ 1.2: 0 คน" << endl;
        cout << "AI: อยากสมัครวิศวกรรมโยธาในโครงการอะไรดีครับครับ🙂?" << endl;
        
            while (keepRunning)
            {
                cout << "User: ";
                getline(cin, input);

                bool found = false;

                if (hasKeyword(input, "1") || hasKeyword(input, "นักกีฬา") || hasKeyword(input, "นักกีฬาตามยุทธศาสตร์")) { //โครงการ 1
                    cout << "AI: โดยทั่วไปคุณสมบัติพื้นฐานที่มักกำหนดไว้ เช่น:" << endl;
                    cout << "    ✔ จบหรือกำลังจะจบ ม.6 หรือเทียบเท่า (เช่น GED)" << endl;
                    cout << "    ✔ มีความสามารถด้านกีฬา โดดเด่นจริง (ระดับชนะเลิศ หรือได้เป็นตัวแทนแข่งขันในระดับชาติ/นานาชาติ)" << endl;
                    cout << "    ✔ มีผลงานหรือผลงานการแข่งขันที่สามารถนำไปอยู่ในแฟ้มสะสมงานเพื่อใช้พิจารณา" << endl;
                    cout << "    รหัสโครงการ 00410601102011" << endl;
                    cout << "    คณะวิศวกรรมศาสตร์ สาขา วิศวกรรมโยธา หลักสูตร ไทย รูปแบบของหลักสูตร ปกติ" << endl;
                    cout << "AI: คุณสนใจรายละเอียดเพิ่มเติมเกี่ยวกับโครงการนี้ไหมครับ?" << endl;
                    while (keepRunning) {
                        
                        cout << "User: ";
                        getline(cin, input);

                        bool found = false;

                        if (hasKeyword(input, "แนวทางการประกอบอาชีพ") || hasKeyword(input, "อาชีพ") || hasKeyword(input, "แนวทาง") ) {
        
                        cout << "AI : สามารถประกอบอาชีพได้หลากหลาย เช่น วิศวกรก่อสร้าง, วิศวกรโครงการ , วิศวกรด้านผลิตภัณฑ์วัสดุ , วิศวกรสำรวจเส้นทางในการสร้างถนน หรือระบบขนส่ง, ที่ปรึกษางานก่อสร้าง / ผู้รับเหมา" << endl;

                        found = true;
                        

                        } 
                        if (hasKeyword(input, "ค่าธรรมเนียม") || hasKeyword(input, "ค่าใช้จ่าย") || hasKeyword(input, "ค่าการศึกษา") || hasKeyword(input, "ค่าเทอม") ) {
        
                        cout << "AI : ค่าธรรมเนียมการศึกษา ภาคการศึกษาแรก 23,000 บาท" << endl;

                        found = true;
                        

                        } 
                        if (hasKeyword(input, "คุณสมบัติผู้สมัคร") || hasKeyword(input, "คุณสมบัติ") || hasKeyword(input, "คุณสมบัติของผู้สมัคร") ) {
        
                        cout << "AI : คุณสมบัติผู้สมัคร 1. จบหรือกำลังจะจบ ม.6 หรือเทียบเท่า (เช่น GED) 2. มีคะแนนเฉลี่ยไม่ต่ำกว่า 3.00" << endl;
                        cout << "   โปรดดูรายละเอียดคุณสมบัติของผู้สมัครเพิ่มเติม ทางเว็บไซต์: \x1B]8;;https://admission.reg.cmu.ac.th/tcas/  \x1B\\https://admission.reg.cmu.ac.th/tcas/  \x1B]8;;\x1B\\" << std::endl;
                             

                        found = true;
                        

                        } 

                        if (hasKeyword(input, "เอกสารประกอบการสมัคร") || hasKeyword(input, "เอกสาร") || hasKeyword(input, "เอกสารที่ต้องใช้") ) {
        
                        cout << "AI : คุณสามารถส่งเอกสารทางออนไลน์เท่านั้นครับ" << endl;
                        cout << "AI :เอกสารประกอบการสมัคร\n"
                                "    1.ใบสมัคร\n"
                                "    2.สำเนาบัตรประจำตัวประชาชน\n"
                                "    3.ใบแสดงผลการเรียน\n"
                                "    4.แฟ้มสะสมผลงาน (Portfolio) (ไม่มีแบบฟอร์ม) เป็นไปตามเอกสารแนบท้ายประกาศการรับสมัครนักเรียนเข้าศึกษาในระดับปริญญาตรีโครงการรับนักกีฬาที่มีความสามารถดีเด่นระดับนานาชาติ/ระดับชาติ และนักกีฬาตามยุทธศาสตร์\n"
                                "    5.หลักฐานการมีผลงานหรือผลงานการแข่งขันที่สามารถนำไปอยู่ในแฟ้มสะสมงานเพื่อใช้พิจารณา\n"   ;                            

                        cout << "AI: เอกสารประกอบการสัมภาษณ์"
                                "     บัตรประจำตัวประชาชน\n";
                                

                        found = true;
                        

                        } 

                        if (hasKeyword(input, "โครงการอื่น") || hasKeyword(input, "อันอื่น") || hasKeyword(input, "อื่น") ) {
        
                        cout << "AI : สามารถประกอบอาชีพได้หลากหลาย เช่น วิศวกรก่อสร้าง, วิศวกรโครงการ , วิศวกรด้านผลิตภัณฑ์วัสดุ , วิศวกรสำรวจเส้นทางในการสร้างถนน หรือระบบขนส่ง, ที่ปรึกษางานก่อสร้าง / ผู้รับเหมา" << endl;

                        found = false;
                        break;
                        

                        } 

                        if (hasKeyword(input, "ลา") || hasKeyword(input, "พอแล้ว") || hasKeyword(input, "หยุด")|| hasKeyword(input, "ไม่มี") || hasKeyword(input, "ไม่")) {
                        cout << "AI: ลาก่อนครับ ขอให้โชคดีกับการเรียนนะครับ!" << endl;
                        keepRunning = false;
                        exit(0);
                        }
        

                        if (!found) {
                            cout << "AI: ขออภัยครับ ผมไม่เข้าใจคำที่คุณพูดครับ" << endl;
                        }

                        if (keepRunning) {
                            cout << "AI: คุณลองถามรายละเอียดที่คุณต้องการรู้ดูครับ" << endl;
                        }
                    }
                }

                if (hasKeyword(input, "วมว") || hasKeyword(input, "ห้องเรียนวิทยาศาสตร์") || hasKeyword(input, "2")) { //โครงการ 2
                    cout << "AI: โครงการ วมว. (ห้องเรียนวิทยาศาสตร์ในโรงเรียน โดยการกำกับดูแลของมหาวิทยาลัย) เป็นโครงการที่พัฒนานักเรียนที่มีความสามารถด้าน วิทยาศาสตร์และคณิตศาสตร์ โดยมหาวิทยาลัยร่วมดูแลการเรียนการสอนกับโรงเรียน เพื่อสร้างนักเรียนที่มีพื้นฐานด้านวิทยาศาสตร์และเทคโนโลยีที่เข้มแข็ง" << endl;
                    cout << "AI: ✔ เป็นนักเรียนใน โครงการ วมว." << endl;
                    cout << "AI: ✔ กำลังเรียนหรือจบ ม.6 สายวิทย์-คณิต" << endl;
                    cout << "AI: ✔ มี GPAX ไม่ต่ำประมาณ 3.25" << endl;
                    cout << "AI: รหัสโครงการ 00410601104011" << endl;
                    cout << "AI: คณะวิศวกรรมศาสตร์ สาขา วิศวกรรมโยธา หลักสูตร ไทย รูปแบบของหลักสูตร ปกติ" << endl;
                    cout << "AI: คุณสนใจรายละเอียดเพิ่มเติมเกี่ยวกับโครงการนี้ไหมครับ?" << endl;
                    while (keepRunning) {
                        
                        
                        cout << "User: ";
                        getline(cin, input);

                        bool found = false;

                        if (hasKeyword(input, "แนวทางการประกอบอาชีพ") || hasKeyword(input, "อาชีพ") || hasKeyword(input, "แนวทาง") ) {
        
                        cout << "AI : สามารถประกอบอาชีพได้หลากหลาย เช่น วิศวกรก่อสร้าง, วิศวกรโครงการ , วิศวกรด้านผลิตภัณฑ์วัสดุ , วิศวกรสำรวจเส้นทางในการสร้างถนน หรือระบบขนส่ง, ที่ปรึกษางานก่อสร้าง / ผู้รับเหมา" << endl;

                        found = true;
                        

                        } 
                        if (hasKeyword(input, "ค่าธรรมเนียม") || hasKeyword(input, "ค่าใช้จ่าย") || hasKeyword(input, "ค่าการศึกษา") || hasKeyword(input, "ค่าเทอม") ) {
        
                        cout << "AI : ค่าธรรมเนียมการศึกษา ภาคการศึกษาแรก 23,000 บาท" << endl;

                        found = true;
                        

                        } 
                        if (hasKeyword(input, "คุณสมบัติผู้สมัคร") || hasKeyword(input, "คุณสมบัติ") || hasKeyword(input, "คุณสมบัติของผู้สมัคร") ) {
        
                        cout << "AI : เป็นผู้มีคุณสมบัติตามประกาศโครงการสนับสนุนการจัดตั้งห้องเรียนวิทยาศาสตร์ในโรงเรียน (วมว.)  " << endl;
                        cout << "   โปรดดูรายละเอียดคุณสมบัติของผู้สมัครเพิ่มเติม ทางเว็บไซต์: \x1B]8;;https://admission.reg.cmu.ac.th/tcas/  \x1B\\https://admission.reg.cmu.ac.th/tcas/  \x1B]8;;\x1B\\" << std::endl;
                             

                        found = true;
                        

                        } 

                        if (hasKeyword(input, "เอกสารประกอบการสมัคร") || hasKeyword(input, "เอกสาร") || hasKeyword(input, "เอกสารที่ต้องใช้") ) {
        
                        cout << "AI : คุณสามารถส่งเอกสารทางออนไลน์เท่านั้นครับ" << endl;
                        cout << "AI :เอกสารประกอบการสมัคร\n"
                                "    1.ใบสมัคร\n"
                                "    2.สำเนาบัตรประจำตัวประชาชน\n"
                                "    3.หนังสือรับรองคุณสมบัติผู้สมัครการรับบุคคลเข้าศึกษาในโครงการ วมว.\n"
                                "    4.ใบแสดงผลการเรียน\n"
                                "    5.แฟ้มสะสมผลงาน (Portfolio) (ไม่มีแบบฟอร์ม) "
                                "       • การจัดทำแฟ้มสะสมผลงาน จำนวนไม่เกิน 10 หน้า A4 ไม่รวมปก ประกอบไปด้วยเอกสารดังต่อไปนี้\n"
                                "         - หน้าที่ 1-2 ประวัติส่วนตัวของนักเรียน\n"
                                "         - หน้าที่ 3-10 รูปผลงานที่แสดงถึงความรู้ ความสามารถ ทักษะทางด้านวิศวกรรม พร้อมการอธิบายรายละเอียดประกอบ\n"
                                "    6.หลักฐานการมีผลงานหรือผลงานการแข่งขันที่สามารถนำไปอยู่ในแฟ้มสะสมงานเพื่อใช้พิจารณา\n"   ;                            

                        cout << "AI: เอกสารประกอบการสัมภาษณ์"
                                "     บัตรประจำตัวประชาชน\n";
                                

                        found = true;
                        

                        } 

                        if (hasKeyword(input, "โครงการอื่น") || hasKeyword(input, "อันอื่น") || hasKeyword(input, "อื่น") ) {
        
                        cout << "AI : สามารถประกอบอาชีพได้หลากหลาย เช่น วิศวกรก่อสร้าง, วิศวกรโครงการ , วิศวกรด้านผลิตภัณฑ์วัสดุ , วิศวกรสำรวจเส้นทางในการสร้างถนน หรือระบบขนส่ง, ที่ปรึกษางานก่อสร้าง / ผู้รับเหมา" << endl;

                        found = false;
                        break;
                        

                        } 

                        if (hasKeyword(input, "ลา") || hasKeyword(input, "พอแล้ว") || hasKeyword(input, "หยุด")|| hasKeyword(input, "ไม่มี") || hasKeyword(input, "ไม่") ) {
                        cout << "AI: ลาก่อนครับ ขอให้โชคดีกับการเรียนนะครับ!" << endl;
                        keepRunning = false;
                        exit(0);
                        }
        

                        if (!found) {
                            cout << "AI: ขออภัยครับ ผมไม่เข้าใจคำที่คุณพูดครับ" << endl;
                        }

                        if (keepRunning) {
                            cout << "AI: คุณลองถามรายละเอียดที่คุณต้องการรู้ดูครับ" << endl;
                        }
                    }

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
    bool keepRunning = true;
    vector<string> history;

    cout << "AI: สนใจเข้าวิศวกรรมสาขาไหนครับ?" << endl;

    while (keepRunning) {
        
        cout << "User: ";
        getline(cin, input);

        bool found = false;

        if (hasKeyword(input, "โยธา") || hasKeyword(input, "Civil")) {
        
        CivilMajorDetails();

            found = true;
        } 
        
        

        if (!found) {
             cout << "AI: ขออภัยครับ ผมไม่เข้าใจคำที่คุณพูดครับ ลองพิมพ์ใหม่ได้ไหมครับ?" << endl;
        }

        if (keepRunning) {
            
        }
    }
}


// --- ฟังก์ชันจัดการเนื้อหาการรับเข้า (เจาะลึก) ---
void handleAdmissionLogic() {
    string input;
    bool keepRunning = true;
    vector<string> history;
    
    cout << "AI: ที่วิศวฯ มช. มีทั้งภาคปกติ ภาคพิเศษ และหลักสูตรนานาชาติ (English Program) สนใจดูเกณฑ์ของหลักสูตรไหนเป็นพิเศษไหมครับ?" << endl;

    while (keepRunning) {
        
        cout << "User: ";
        getline(cin, input);

        bool found = false;

        if (hasKeyword(input, "ปกติ") || hasKeyword(input, "ภาคปกติ")) {
        
        handleMajorDetails();

            found = true;
        } 
        
        

        if (!found) {
             cout << "AI: ขออภัยครับ ผมไม่เข้าใจคำที่คุณพูดครับ ลองพิมพ์ใหม่ได้ไหมครับ?" << endl;
        }

        if (keepRunning) {
            cout << "AI: คณะวิศวกรรมศาสตร์ มช. มี 3 หลักสูตรครับ" << endl;
            cout << "AI: 1. ภาคปกติ🧑‍🎓" << endl;
            cout << "AI: 2. ภาคพิเศษ 🧑‍🎓" << endl;
            cout << "AI: 3. หลักสูตรนานาชาติ (English Program) 🧑‍🎓" << endl;
            cout << "คุณลองพิมพ์ชื่อหลักสูตรที่คุณสนใจดูครับ" << endl;
        }
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

        if (hasKeyword(input, "ลา") || hasKeyword(input, "พอแล้ว") || hasKeyword(input, "หยุด")|| hasKeyword(input, "ไม่มี") || hasKeyword(input, "ไม่")) {
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