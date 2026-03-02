#include <windows.h>
#include <iostream>
#include <string>

using namespace std;

bool hasKeyword(string input, string keyword);
bool checkRegularMajor(string input);
bool checkSpecialMajor(string input);
bool checkInternationalMajor(string input);

int main() {
    system("chcp 65001 > nul"); 
    string input;
    string* selectedProgram = nullptr;
    string normalLabel = "Normal";
    string specialLabel = "Special";

    int programChoice, majorChoice;
    string selectedMajor = "";
    bool keepRunning = true;

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

    cout << "สวัสดีครับ! ผมเป็นบอทแนะนำหลักสูตรวิศวกรรมศาสตร์" << endl;
    cout << "คุณสนใจ 'Regular(ภาคปกติ)' 'Special(ภาคพิเศษ)' 'International Program(นานาชาติ)' ครับ? (พิมพ์ 'Exit' เพื่อจบการทำงาน)" << endl;

    while(keepRunning){
        cout << "\nคุณ: ";
        if(!getline(cin, input) || input.empty()) continue;

        if(hasKeyword(input, "ออก") || hasKeyword(input, "exit")){
            cout << "บอท: ขอบคุณที่ใช้บริการครับ!" << endl;
            keepRunning = false;
            break;
        }

        if(selectedProgram == nullptr){
            if(hasKeyword(input, "Regular") || hasKeyword(input, "ภาคปกติ") || hasKeyword(input, "ปกติ")){
                selectedProgram = &regularMajors;
                cout << "บอท: รับทราบครับ 'Regular(ภาคปกติ)' แล้วสนใจสาขาไหนครับ?" << endl;
                cout << "(คอมพิวเตอร์, โยธา, ไฟฟ้า, เครื่องกล, เซมิคอนดักเตอร์, บูรณาการณ์, สิ่งแวดล้อม, หุ่นยนต์, เหมืองแร่, อุตสาหการ)" << endl;
            }else if(hasKeyword(input, "Special") || hasKeyword(input, "ภาคพิเศษ") || hasKeyword(input, "พิเศษ")){
                selectedProgram = &specialMajors;
                cout << "บอท: รับทราบครับ 'Special(ภาคพิเศษ)' สนใจสาขาไหนครับ?" << endl;
                cout << "(อุตสาหการ, ไฟฟ้า, เครื่องกล)" << endl;
            }else if(hasKeyword(input, "International") || hasKeyword(input, "นานาชาติ") || hasKeyword(input, "Inter") || hasKeyword(input, "อินเตอร์")){
                selectedProgram = &interMajors;
                cout << "บอท: รับทราบครับ 'International(นานาชาติ)' สนใจสาขาไหนครับ?" << endl;
                cout << "(เครื่องกล, บูรณาการณ์, ไฟฟ้า, โยธา, ISNE, อุตสาหการ)" << endl;
            }else{
                cout << "บอท: ขอโทษครับ ผมเข้าใจแค่ 'Regualr(ภาคปกติ)' 'Special(ภาคพิเศษ)' หรือ 'International(นานาชาติ)'กรุณาลองใหม่ครับ" << endl;
            }
        }else{
            if(*selectedProgram == "Regular"){
                if(checkRegularMajor(input)){
                    selectedMajor = input;
                    cout << "บอท: คุณเลือก " << input << " Regular(ภาคปกติ)" << endl;
                    if(hasKeyword(input, "Computer") || (hasKeyword(input, "คอมพิวเตอร์"))){
                        cout << "Software, AI, Cloud, และ Data Science" << endl;
                        cout << "● ปี 1: ปูพื้นฐาน Calculus, Physics และ Computer Programming (C/Python) ฝึก Logic เบื้องต้น" << endl;
                        cout << "● ปี 2: เข้าสู่แกนหลัก Computer Engineering เจอ Data Structures, Discrete Math, Digital Logic และเริ่ม Circuit" << endl;
                        cout << "● ปี 3: ปีมหาโหด! เรียน Operating Systems, Database, Network, Software Engineering และ Microprocessors" << endl;
                        cout << "● ปี 4: เลือกวิชาเลือกเฉพาะทาง (AI, Security, Cloud) และทำ Senior Project ตลอดทั้งปี" << endl;
                        //โชว์แผนการเรียน
                    }else if(hasKeyword(input, "Mechanical") || (hasKeyword(input, "เครื่องกล")){
                        cout << "พลังงาน, ยานยนต์, และการออกแบบเครื่องจักร" << endl;
                        cout << "● ปี 1: เน้น Physics, Calculus และวิชา Engineering Drawing (หัดวาดแบบวิศวกรรมทั้งมือและ CAD)" << endl;
                        cout << "● ปี 2: เริ่มวิชาคำนวณแรงหลัก Statics, Dynamics, Thermodynamics และพื้นฐานวัสดุวิศวกรรม" << endl;
                        cout << "● ปี 3: เจาะลึก Fluid Mechanics, Heat Transfer, Machine Design และเครื่องจักรกลความร้อน" << endl;
                        cout << "● ปี 4: เลือกสายเจาะลึก (Automotive/Energy) และทำโครงงานวิศวกรรมเครื่องกล" << endl;
                        //โชว์แผนการเรียน
                    }else if(hasKeyword(input, "Semiconductor") || (hasKeyword(input, "เซมิคอนดักเตอร์")){
                        cout << "วัสดุศาสตร์และฟิสิกส์ของอุปกรณ์ , การออกแบบวงจรรวม , กระบวนการผลิต , การทดสอบและการแพ็คเกจ" << endl;
                        cout << "● ปี 1: Physics of Semiconductor" << endl;
                        cout << "● ปี 2: IC Design, VLSI" << endl;
                        cout << "● ปี 3: Semiconductor Fabrication" << endl;
                        cout << "● ปี 4: Internship ในอุตสาหกรรมชิปประมวลผล" << endl;
                        //โชว์แผนการเรียน
                    }else if(hasKeyword(input, "Integrated") || (hasKeyword(input, "บูรณาการณ์")){
                        cout << "การเรียนรู้แบบพหุวิทยาการเพื่อตอบโจทย์นวัตกรรม" << endl;
                        cout << "● ปี 1-4: เน้นการเรียนแบบโมดูล (Module) และ Project-based Learning" << endl;
                        cout << "เรียนรู้ข้ามศาสตร์ระหว่างสาขาต่างๆ เช่นคอมพิวเตอร์ ไฟฟ้า และเครื่องกล"<< endl;
                        //โชว์แผนการเรียน
                    }else if(hasKeyword(input, "Electrical") || (hasKeyword(input, "ไฟฟ้า")){
                        cout << "ระบบไฟฟ้ากำลัง, อิเล็กทรอนิกส์ และสมาร์ทคอนโทรล" << endl;
                        cout << "● ปี 1: พื้นฐานวิศวกรรม เน้นฟิสิกส์ไฟฟ้าและแม่เหล็ก และคณิตศาสตร์วิศวกรรม" << endl;
                        cout << "● ปี 2: เข้าสู่หัวใจอย่าง Circuit Analysis 1-2, Digital Circuit และสัญญาณและระบบ (Signals)" << endl;
                        cout << "● ปี 3: เรียน Electromagnetic Fields, Machines, ระบบควบคุม และการส่งจ่ายกำลังไฟฟ้า" << endl;
                        cout << "● ปี 4: แยกสายกำลังหรืออิเล็กทรอนิกส์ขั้นสูง และทำ Senior Project" << endl;
                        //โชว์แผนการเรียน
                    }else if(hasKeyword(input, "Civil") || (hasKeyword(input, "โยธา")){
                        cout << "ออกแบบโครงสร้าง, ถนน, การสำรวจ และงานฐานราก" << endl;
                        cout << "● ปี 1: พื้นฐานวิศวกรรมและ Drawing เพื่อหัดอ่านและวาดแบบแปลนก่อสร้าง" << endl;
                        cout << "● ปี 2: เริ่มคำนวณ Mechanics of Solids และออกฝึกสำรวจ (Surveying) กลางแจ้ง" << endl;
                        cout << "● ปี 3: ออกแบบคอนกรีตเสริมเหล็ก (RC Design), โครงสร้างเหล็ก และวิศวกรรมฐานราก (Soil Mech)" << endl;
                        cout << "● ปี 4: การบริหารงานก่อสร้าง, ชลศาสตร์ และทำโครงการจบวิศวกรรมโยธา" << endl;
                        //โชว์แผนการเรียน
                    }else if(hasKeyword(input, "Environmental") || (hasKeyword(input, "สิ่งแวดล้อม")){
                        cout << "การจัดการน้ำ, อากาศ, มลพิษ และสิ่งแวดล้อมยั่งยืน" << endl;
                        cout << "● ปี 1: เน้นพื้นฐานเคมีสิ่งแวดล้อมและชีววิทยามากเป็นพิเศษ" << endl;
                        cout << "● ปี 2: ระบบประปา, ระบบระบายน้ำ, จุลชีววิทยาสิ่งแวดล้อม และกลศาสตร์ของไหล" << endl;
                        cout << "● ปี 3: ระบบบำบัดน้ำเสียขั้นสูง, มลพิษทางอากาศ และการจัดการขยะมูลฝอยและของเสียอันตราย" << endl;
                        cout << "● ปี 4: การประเมินผลกระทบสิ่งแวดล้อม (EIA), พลังงานสะอาด และ Senior Project" << endl;
                        //โชว์แผนการเรียน
                    }else if(hasKeyword(input, "REAI") || (hasKeyword(input, "คอมพิวเตอร์")){
                        cout << "(Robotics & AI) บูรณาการหุ่นยนต์, ปัญญาประดิษฐ์ และระบบอัตโนมัติ" << endl;
                        cout << "● ปี 1: เริ่มฝึก Robotics Programming ทันทีควบคู่ไปกับพื้นฐาน Physics/Math" << endl;
                        cout << "● ปี 2: เรียนเรื่อง Sensor, Actuators, Embedded Systems และระบบควบคุมหุ่นยนต์" << endl;
                        cout << "● ปี 3: เจาะลึก AI for Robotics, Machine Vision, Kinematics และการออกแบบกลไกแขนกล" << endl;
                        cout << "● ปี 4: เน้นการทำ Project-Based ร่วมกับภาคอุตสาหกรรมนวัตกรรมหุ่นยนต์สมัยใหม่" << endl;
                        //โชว์แผนการเรียน
                    }else if(hasKeyword(input, "Mining&Petroleum") || (hasKeyword(input, "เหมืองแร่")){
                        cout << "ทรัพยากรธรณี, การขุดเจาะ และวิศวกรรมปิโตรเลียม" << endl;
                        cout << "● ปี 1: พื้นฐานธรณีวิทยา (Physical Geology) และพื้นฐานวิศวกรรม" endl;
                        cout << "● ปี 2: การทำเหมืองเปิด, เหมืองใต้ดิน, การวิเคราะห์สินแร่ และการสำรวจธรณี" << endl;
                        cout << "● ปี 3: การระเบิดหิน, Rock Mechanics, การแต่งแร่ และเศรษฐศาสตร์ทรัพยากรธรณี" << endl;
                        cout << "● ปี 4: ออกแบบเหมือง, วิศวกรรมปิโตรเลียมเบื้องต้น และโครงงานจบการศึกษา" << endl;
                        //โชว์แผนการเรียน
                    }else if(hasKeyword(input, "Industrial") || (hasKeyword(input, "อุตสาหการ")){
                        cout << "การเพิ่มประสิทธิภาพการผลิต, บริหารจัดการ และโลจิสติกส์" << endl;
                        cout << "● ปี 1: พื้นฐานวิศวกรรมทั่วไป และวิชาเคมีสำหรับวิศวกร" << endl;
                        cout << "● ปี 2: สถิติวิศวกรรม (Engineering Stat), กรรมวิธีการผลิต และพื้นฐานความปลอดภัย" << endl;
                        cout << "● ปี 3: ปีแห่งการวางแผน! เรียน Operations Research (OR), คุมคุณภาพ (QC), เศรษฐศาสตร์วิศวกรรม" << endl;
                        cout << "● ปี 4: การจัดการโลจิสติกส์, การออกแบบโรงงาน และ Senior Project" << endl;
                        //โชว์แผนการเรียน
                    }
                    cout << "พิมพ์ 'Exit' เพื่อจบ หรือพิมพ์ 'Restart' เพื่อเปลี่ยนหลักสูตร" << endl;
                }
            } 
            else if(*selectedProgram == "Special"){
                if(checkSpecialMajor(input)){
                    selectedMajor = input;
                    cout << "บอท: ยอดเยี่ยม! คุณเลือก " << input << " Special(ภาคพิเศษ)" << endl;
                    if(hasKeyword(input, "Mechanical") || (hasKeyword(input, "เครื่องกล"))){
                        cout << "(Mechanical & Project Management) เครื่องกลและการบริหารโครงการวิศวกรรม" << endl;
                        cout << "● ปี 1-2: เน้นวิชาแกนวิศวกรรมเครื่องกล (Thermo, Fluid, Statics)" << endl;
                        cout << "● ปี 3-4: เสริมทักษะบริหารจัดการโครงการ (Project Management)" << endl;
                        //โชว์แผนการเรียน
                    }else if(hasKeyword(input, "Industrial") || (hasKeyword(input, "อุตสาหการ")){
                        cout << "(IE & Logistics Management) อุตสาหการและการจัดการโลจิสติกส์" << endl;
                        cout << "● ปี 1-2: แกนวิศวกรรมอุตสาหการ" << endl;
                        cout << "● ปี 3-4: เจาะลึกการบริหารคลังสินค้า และระบบขนส่งอัจฉริยะ" << endl;
                        //โชว์แผนการเรียน
                    }else if(hasKeyword(input, "Electrical") || (hasKeyword(input, "ไฟฟ้า")){
                        cout << "(Smart Grid Technology) ไฟฟ้าและเทคโนโลยีโครงข่ายไฟฟ้าอัจฉริยะ" << endl;
                        cout << "● ปี 1-2: พื้นฐานไฟฟ้าและอิเล็กทรอนิกส์" << endl;
                        cout << "● ปี 3-4: เน้นระบบ Smart Grid และพลังงานทดแทน" << endl;
                        //โชว์แผนการเรียน
                    }
                    cout << "พิมพ์ 'Exit' เพื่อจบ หรือพิมพ์ 'Restart' เพื่อเปลี่ยนหลักสูตร" << endl;
                }
            }else if(*selectedProgram == "International"){
                if(checkInternationalMajor(input)){
                    selectedMajor = input;
                    cout << "AI: ยอดเยี่ยม! คุณเลือก " << input << " International(ภาคนานาชาติ)" << endl;
                    if(hasKeyword(input, "Mechanical") || (hasKeyword(input, "เครื่องกล"))){
                        cout << "AI: เน้นเครื่องกลหลักร่วมกับการบริหารความเสี่ยงและเศรษฐศาสตร์วิศวกรรม" << endl;
                        cout << "● ปี 1-2: เน้นวิชาแกนวิศวกรรมเครื่องกล (Thermo, Fluid, Statics)" << endl;
                        cout << "● ปี 3-4: เสริมทักษะบริหารจัดการโครงการ (Project Management)" << endl;
                        //โชว์แผนการเรียน
                    }else if(hasKeyword(input, "Integrated") || (hasKeyword(input, "บูรณาการณ์")){
                        cout << "AI: เน้นแก้ปัญหาข้ามศาสตร์ เช่น หุ่นยนต์การแพทย์ หรือเทคโนโลยีอาหาร" << endl;
                        cout << "● ปี 1-4: เรียนเป็นภาษาอังกฤษทั้งหมด เน้น Systems Thinking และงานวิจัยข้ามศาสตร์" << endl;
                        //โชว์แผนการเรียน
                    }else if(hasKeyword(input, "Electrical") || (hasKeyword(input, "ไฟฟ้า")){
                        cout << "AI: (IE & Logistics Management) อุตสาหการและการจัดการโลจิสติกส์" << endl;
                        cout << "● ปี 1-2: แกนวิศวกรรมอุตสาหการ" << endl;
                        cout << "● ปี 3-4: เจาะลึกการบริหารคลังสินค้า และระบบขนส่งอัจฉริยะ" << endl;
                        //โชว์แผนการเรียน
                    }else if(hasKeyword(input, "Civil") || (hasKeyword(input, "โยธา")){
                        cout << "AI: เน้นการออกแบบโครงสร้างตามมาตรฐานสากลและภาษาอังกฤษเชิงวิศวกรรม" << endl;
                        cout << "● ปี 1-2: พื้นฐานไฟฟ้าและอิเล็กทรอนิกส์" << endl;
                        cout << "● ปี 3-4: เน้นระบบ Smart Grid และพลังงานทดแทน" << endl;
                        //โชว์แผนการเรียน
                    }else if(hasKeyword(input, "ISNE") || (hasKeyword(input, "ISNE")){
                        cout << "AI: ระบบสารสนเทศและความปลอดภัยไซเบอร์" << endl;
                        cout << "● ปี 1: Computing Fundamentals" << endl;
                        cout << "● ปี 2: Cyber Security" << endl;
                        cout << "● ปี 3: Network Security, Cloud Infrastructure" << endl;
                        cout << "● ปี 4: International Internship" << endl;
                        //โชว์แผนการเรียน
                    }else if(hasKeyword(input, "Industrial") || (hasKeyword(input, "อุตสาหการ")){
                        cout << "AI: การบริหารคลังสินค้า, การวิจัยดำเนินงาน และระบบ Lean" << endl;
                        cout << "● ปี 1-2: พื้นฐานไฟฟ้าและอิเล็กทรอนิกส์" << endl;
                        cout << "● ปี 3-4: เน้นระบบ Smart Grid และพลังงานทดแทน" << endl;
                        //โชว์แผนการเรียน
                    }
                    cout << "พิมพ์ 'Exit' เพื่อจบ หรือพิมพ์ 'Restart' เพื่อเปลี่ยนหลักสูตร" << endl;
                }
            }
            if(hasKeyword(input, "เริ่มใหม่") || (hasKeyword(input, "Restart")){
                selectedProgram = nullptr;
                cout << "บอท: กรุณาเลือกหลักสูตรใหม่อีกครั้ง (Regular(ภาคปกติ)/Special(ภาคพิเศษ)/International(ภาคนานาชาติ))" << endl;
            }
        }
    }
        return 0;
}

void openImage(string path){
    HINSTANCE result = ShellExecuteA(NULL, "open", path.c_str(), NULL, NULL, SW_SHOWNORMAL);
    if ((INT_PTR)result <= 32) {
        cout << "เปิดรูปไม่สำเร็จ!\n";
    }
}

bool hasKeyword(string input, string keyword) {
    if (input.empty() || keyword.empty()) return false;
    return input.find(keyword) != string::npos;
}

bool checkRegularMajor(string input){
    set<string> majors = {"Computer","Mechanical","Semiconductor","Integrated","Electrical","Civil","Environmental","REAI","Mining","Industrial","คอมพิวเตอร์","เครื่องกล","เซมิคอนดักเตอร์","บูรณาการ","ไฟฟ้า","โยธา","สิ่งแวดล้อม","หุ่นยนต์","เหมืองแร่","อุตสาหการ"};
    for(const string& m : majors){
        if(hasKeyword(input, m)) return true;
    }
    cout << "AI: ภาคปกติไม่มีสาขา '" << input << "' ครับ ลองระบุใหม่อีกครั้ง" << endl;
    return false;
}

bool checkSpecialMajor(string input){
    set<string> majors = {"Industrial","Electrical","Mechanical","อุตสาหการ","ไฟฟ้า","เครื่องกล"};
    for(const string& m : majors){
        if(hasKeyword(input, m)) return true;
    }
    cout << "AI: ภาคพิเศษไม่มีสาขา '" << input << "' ครับ ลองระบุใหม่อีกครั้ง" << endl;
    return false;
}

bool checkInternationalMajor(string input){
    set<string> majors = {"Mechanical","Integrated","Electrical","Civil","ISNE","Industrial","เครื่องกล","บูรณาการ","ไฟฟ้า","โยธา","อุตสาหการ"};
    for(const string& m : majors){
        if(hasKeyword(input, m)) return true;
    }
    cout << "AI: ภาคนานาชาติไม่มีสาขา '" << input << "' ครับ ลองระบุใหม่อีกครั้ง" << endl;
    return false;
}