#include<iostream>
#include<string>
#include<vector>
using namespace std;

enum ShowState {
    SELECT_PROGRAM, //เลือกภาค
    SELECT_MAJORS, //เลือกเจอร์
    SELECT_DETAIL //คำถาม
};

class WaitSelect{
    public:
        ShowState currentState = SELECT_PROGRAM;
        std::string selectedProgram = "";
        std::string selectedMajor = "";
        std::string selectedDetail = "";

    bool hasKeyword(std::string input, std::string keyword) {
        return input.find(keyword) != std::string::npos;
    };
    
    bool processHistory(std::string input, std::vector<std::string>& chatHistory){
        auto reply = [&](std::string text) {
            chatHistory.push_back("Chatbot: " + text);
        };

        if(hasKeyword(input, "ออก") || hasKeyword(input, "เมนูหลัก")){
            reply(" ");
            currentState = SELECT_PROGRAM;
            selectedMajor = ""; selectedDetail = "";
            return false;
        };

        switch(currentState){
            case SELECT_PROGRAM:
                if(hasKeyword(input, "ปกติ")){
                    selectedProgram = "ปกติ";
                    reply("เลือกภาคปกติแล้วครับ ต่อไปเลือกสาขาที่สนใจได้เลย");
                    currentState = SELECT_MAJORS;
                }else if(hasKeyword(input, "พิเศษ")){
                    selectedProgram = "พิเศษ";
                    reply("เลือกภาคพิเศษแล้วครับ ต่อไปเลือกสาขาที่สนใจได้เลย");
                    currentState = SELECT_MAJORS;
                }else if(hasKeyword(input, "นานาชาติ")){
                    selectedProgram = "นานาชาติ";
                    reply("เลือกภาคนานาชาติแล้วครับ ต่อไปเลือกสาขาที่สนใจได้เลย");
                    currentState = SELECT_MAJORS;
                }else{
                    reply("กรุณาเลือกภาคที่ต้องการ: ปกติ พิเศษ หรือ นานาชาติ ครับ");
                }break;

//=========================================================================================================================================

//                                                ภาคปกติ

                                                //Computer
            case SELECT_MAJORS:
                if((hasKeyword(input, "คอม") || hasKeyword(input, "คอมพิวเตอร์")) && selectedProgram == "ปกติ"){
                    selectedMajor = "คอมพิวเตอร์";
                    reply("ต้องการสอบถามเรื่องใดเกี่ยวกับวิศวกรรมคอมพิวเตอร์ครับ?");
                    currentState = SELECT_DETAIL;
                }
                                                //Mechanical
                else if(hasKeyword(input, "เครื่องกล") && selectedProgram == "ปกติ"){
                    selectedMajor = "เครื่องกล";
                    reply("ต้องการสอบถามเรื่องใดเกี่ยวกับวิศวกรรมเครื่องกลครับ?");
                    currentState = SELECT_DETAIL;
                }
                                                //Electrical
                else if(hasKeyword(input, "ไฟฟ้า") && selectedProgram == "ปกติ"){
                    selectedMajor = "ไฟฟ้า";
                    reply("ต้องการสอบถามเรื่องใดเกี่ยวกับวิศวกรรมไฟฟ้าครับ?");
                    currentState = SELECT_DETAIL;
                }
                                                //Civil
                else if(hasKeyword(input, "โยธา") && selectedProgram == "ปกติ"){
                    selectedMajor = "โยธา";
                    reply("ต้องการสอบถามเรื่องใดเกี่ยวกับวิศวกรรมโยธาครับ?");
                    currentState = SELECT_DETAIL;
                }
                                                //Industrial
                else if(hasKeyword(input, "อุตสาหการ") && selectedProgram == "ปกติ"){
                    selectedMajor = "อุตสาหการ";
                    reply("ต้องการสอบถามเรื่องใดเกี่ยวกับวิศวกรรมอุตสาหการครับ?");
                    currentState = SELECT_DETAIL;
                }
                                                //Environmental
                else if(hasKeyword(input, "สิ่งแวดล้อม") && selectedProgram == "ปกติ"){
                    selectedMajor = "สิ่งแวดล้อม";
                    reply("ต้องการสอบถามเรื่องใดเกี่ยวกับวิศวกรรมสิ่งแวดล้อมครับ?");
                    currentState = SELECT_DETAIL;
                }
                                                //Mining & Petroleum
                else if((hasKeyword(input, "เหมืองแร่") || hasKeyword(input, "ปิโตรเลี่ยม")) && selectedProgram == "ปกติ"){
                    selectedMajor = "เหมืองแร่";
                    reply("ต้องการสอบถามเรื่องใดเกี่ยวกับวิศวกรรมเหมืองแร่และปิโตรเลี่ยมครับ?");
                    currentState = SELECT_DETAIL;
                }
                                                //REAI (Robotics & AI)
                else if((hasKeyword(input, "REAI") || hasKeyword(input, "robot") || hasKeyword(input, "Ai")) && selectedProgram == "ปกติ"){
                    selectedMajor = "REAI";
                    reply("ต้องการสอบถามเรื่องใดเกี่ยวกับวิศวกรรมหุ่นยนต์ และAIครับ?");
                    currentState = SELECT_DETAIL;
                }
                                                //Integrated
                else if(hasKeyword(input, "บูรณาการณ์") && selectedProgram == "ปกติ"){
                    selectedMajor = "บูรณาการณ์";
                    reply("ต้องการสอบถามเรื่องใดเกี่ยวกับวิศวกรรมบูรณาการณ์ครับ?");
                    currentState = SELECT_DETAIL;
                }

//                                                ภาคพิเศษ

                                                //Industrial
                else if(hasKeyword(input, "อุตสาหการ") && selectedProgram == "พิเศษ"){
                    selectedMajor = "อุตสาหการ";
                    reply("ต้องการสอบถามเรื่องใดเกี่ยวกับวิศวกรรมอุตสาหการ(พิเศษ)ครับ?");
                    currentState = SELECT_DETAIL;
                }
                                                //Electrical
                else if(hasKeyword(input, "ไฟฟ้า") && selectedProgram == "พิเศษ"){
                    selectedMajor = "ไฟฟ้า";
                    reply("ต้องการสอบถามเรื่องใดเกี่ยวกับวิศวกรรมไฟฟ้า(พิเศษ)ครับ?");
                    currentState = SELECT_DETAIL;
                }
                                                //Mechanical
                else if(hasKeyword(input, "เครื่องกล") && selectedProgram == "พิเศษ"){
                    selectedMajor = "เครื่องกล";
                    reply("ต้องการสอบถามเรื่องใดเกี่ยวกับวิศวกรรมเครื่องกล(พิเศษ)ครับ?");
                    currentState = SELECT_DETAIL;
                }

//                                                นานาชาติ

                                                //Mechanical
                else if(hasKeyword(input, "เครื่องกล") && selectedProgram == "นานาชาติ"){
                    selectedMajor = "เครื่องกล";
                    reply("ต้องการสอบถามเรื่องใดเกี่ยวกับเครื่องกล(นานาชาติ)ครับ?");
                    currentState = SELECT_DETAIL;
                }
                                                //Integrated
                else if(hasKeyword(input, "บูรณาการณ์") && selectedProgram == "นานาชาติ"){
                    selectedMajor = "บูรณาการณ์";
                    reply("ต้องการสอบถามเรื่องใดเกี่ยวกับบูรณาการณ์(นานาชาติ)ครับ?");
                    currentState = SELECT_DETAIL;
                }
                                                //Electrical
                else if(hasKeyword(input, "ไฟฟ้า") && selectedProgram == "นานาชาติ"){
                    selectedMajor = "ไฟฟ้า";
                    reply("ต้องการสอบถามเรื่องใดเกี่ยวกับวิศวกรรมไฟฟ้า(นานาชาติ)ครับ?");
                    currentState = SELECT_DETAIL;
                }
                                                //Civil
                else if(hasKeyword(input, "โยธา") && selectedProgram == "นานาชาติ"){
                    selectedMajor = "โยธา";
                    reply("ต้องการสอบถามเรื่องใดเกี่ยวกับวิศวกรรมโยธา(นานาชาติ)ครับ?");
                    currentState = SELECT_DETAIL;
                }
                                                //ISNE
                else if(hasKeyword(input, "ISNE") && selectedProgram == "นานาชาติ"){
                    selectedMajor = "ISNE";
                    reply("ต้องการสอบถามเรื่องใดเกี่ยวกับวิศวกรรมระบบสารสนเทศและเครือข่าย(ISNE)ครับ?");
                    currentState = SELECT_DETAIL;
                }
                                                //Industrial
                else if(hasKeyword(input, "อุตสาหการ") && selectedProgram == "นานาชาติ"){
                    selectedMajor = "อุตสาหการ";
                    reply("ต้องการสอบถามเรื่องใดเกี่ยวกับวิศวกรรมอุตสาหการ(นานาชาติ)ครับ?");
                    currentState = SELECT_DETAIL;
                }

//=========================================================================================================================================

                else{
                    reply("ลองพิมพ์ชื่อสาขาใหม่ดูนะครับ (เช่น อุตสาหการ, คอมพิวเตอร์, โยธา)");
                }
                break;

//=========================================================================================================================================

//                                                คำถาม

            case SELECT_DETAIL:
                if(hasKeyword(input, "เรียนอะไร") || hasKeyword(input, "เกี่ยวกับอะไร")){        
                    if(selectedMajor == "คอมพิวเตอร์"){
                        if(selectedProgram == "ปกติ"){
                            reply("● ปี 1: พื้นฐานวิศวกรรมทั่วไป และการโปรแกรมเบื้องต้นเน้น Calculus, Physics และวิชาหัวใจหลักคือ Computer Programming (มักเริ่มด้วย C หรือ Python) เพื่อฝึกตรรกะการแก้ปัญหา (Logic)\n"
                                "● ปี 2: โครงสร้างข้อมูล (Data Structures), ระบบดิจิทัล และวงจรไฟฟ้าเรียนวิชาปราบเซียนอย่าง Discrete Mathematics, Digital Systems, Data Structures & Algorithms และการออกแบบวงจรไฟฟ้าพื้นฐาน\n"
                                "● ปี 3: ปีแห่งระบบปฏิบัติการ! เรียน OS, ฐานข้อมูล (Database), และเครือข่าย (Network)เน้นวิชาสายระบบอย่าง Operating Systems, Computer Architecture, Software Engineering และ Microprocessors (การเขียนโปรแกรมควบคุมบอร์ด)\n"
                                "● ปี 4: ปัญญาประดิษฐ์ (AI), ความมั่นคงปลอดภัยไซเบอร์ และ Senior Project เรียนวิชาล้ำสมัยอย่าง Machine Learning (AI), Computer Security และเน้นการทำโครงงานจบการศึกษา (Senior Project) ที่สร้างนวัตกรรมหรือซอฟต์แวร์ใช้งานจริง");
                        }else if(selectedProgram == "พิเศษ"){
                            reply("ไม่มีสาขานี้ในภาคพิเศษครับ");
                        }else if(selectedProgram == "นานาชาติ"){
                            reply("ไม่มีสาขานี้ในภาคนานาชาติครับ");
                        }
                    }else if(selectedMajor == "เครื่องกล"){
                        if(selectedProgram == "ปกติ"){
                            reply("● ปี 1: พื้นฐานวิศวกรรมทั่วไป และวิชาเคมีสำหรับวิศวกรเน้น Calculus 1&2 และ Physics 1&2 (โดยเฉพาะเรื่องแรงและการเคลื่อนที่) และเริ่มเรียนการเขียนแบบวิศวกรรม (Drawing) ด้วยคอมพิวเตอร์\n"
                                "● ปี 2: พื้นฐานกลศาสตร์ (Mechanics), สถิติวิศวกรรม และอุณหพลศาสตร์ (Thermo)เรียนวิชาแกนหลักอย่าง Statics (สถิตยศาสตร์), Dynamics (พลศาสตร์), และ Thermodynamics (การถ่ายเทความร้อนและพลังงาน) รวมถึงเริ่มฝึกงานโรงงาน (Workshop)\n"
                                "● ปี 3: ปีแห่งการคำนวณขั้นสูง! เรียนกลศาสตร์ของไหล (Fluid), การถ่ายเทความร้อน (Heat Transfer), และการออกแบบเครื่องจักรเน้นวิชาเฉพาะทางอย่าง Fluid Mechanics, Mechanical Design (การออกแบบชิ้นส่วนเครื่องกล) และระบบควบคุมอัตโนมัติ (Automatic Control)\n"
                                "● ปี 4: ระบบปรับอากาศ, เครื่องยนต์สันดาปภายใน และ Senior Project เรียนวิชาประยุกต์อย่าง Power Plant Engineering, Internal Combustion Engines, การทำความเย็น และโครงงานจบการศึกษาที่เน้นการสร้างเครื่องจักรหรือแบบจำลองทางวิศวกรรม");
                            }else if(selectedProgram == "พิเศษ"){
                            reply("● ปี 1: พื้นฐานวิศวกรรมทั่วไป และวิชาเคมีสำหรับวิศวกรเน้นการปูพื้นฐานคำนวณหนักๆ อย่าง Calculus 1&2 และ Physics 1&2 (กลศาสตร์และไฟฟ้า) รวมถึงการเขียนแบบวิศวกรรม (Engineering Drawing)\n"
                                "● ปี 2: สถิติวิศวกรรม (Engineering Stat), อุณหพลศาสตร์ (Thermo) และกลศาสตร์เริ่มเข้าวิชาภาคอย่าง Statics (สถิตยศาสตร์), Dynamics (พลศาสตร์) และ Thermodynamics เพื่อเข้าใจการเปลี่ยนรูปพลังงานและแรง\n"
                                "● ปี 3: ปีแห่งการคำนวณขั้นสูง! เรียนกลศาสตร์ของไหล (Fluid), การถ่ายเทความร้อน (Heat), และการออกแบบเครื่องจักรเน้นวิชาเฉพาะทางอย่าง Fluid Mechanics, Heat Transfer, ระบบควบคุมอัตโนมัติ และการออกแบบชิ้นส่วนเครื่องกล (Machine Design)\n"
                                "● ปี 4: ระบบปรับอากาศ, เครื่องยนต์สันดาป และ Senior Project เรียนวิชาประยุกต์อย่างวิศวกรรมโรงไฟฟ้า, ระบบทำความเย็น, การสั่นสะเทือนทางเครื่องกล และทำโครงงานวิศวกรรมจบการศึกษา (Senior Project)");
                            }else if(selectedProgram == "นานาชาติ"){
                            reply("● ปี 1: พื้นฐานวิศวกรรมสากล และวิชาเคมี (English Medium)เรียน Calculus, Physics และ Chemistry โดยใช้ตำราและบรรยายเป็นภาษาอังกฤษทั้งหมด พร้อมฝึกทักษะการสื่อสารทางวิศวกรรม\n"
                                "● ปี 2: กลศาสตร์พื้นฐาน และการประมวลผลด้วยคอมพิวเตอร์ เรียน Statics, Dynamics, Thermodynamics และเริ่มใช้โปรแกรมคอมพิวเตอร์ในการคำนวณทางวิศวกรรมเครื่องกล (Computational Tools)\n"
                                "● ปี 3: ปีแห่งวิชาแกนหลัก และโอกาสไปต่างประเทศ! เรียน Fluid Mechanics, Heat Transfer และ Machine Design โดยในช่วงนี้มักจะมีโครงการแลกเปลี่ยนหรือเตรียมตัวไปเรียนที่มหาวิทยาลัยพาร์ทเนอร์ (เช่น ในเยอรมนี หรือญี่ปุ่น)\n"
                                "● ปี 4: เทคโนโลยีพลังงานสะอาด, ระบบอัตโนมัติ และ Senior Project เน้นวิชาเลือกที่ทันสมัย เช่น Renewable Energy, Robotics และทำงานวิจัยจบการศึกษา (Senior Project) โดยนำเสนอเป็นภาษาอังกฤษ");
                            }
                    }else if(selectedMajor == "เซมิคอนดักเตอร์"){
                        if(selectedProgram == "ปกติ"){
                            reply("● ปี 1: พื้นฐานวิศวกรรมสากล และวิชาเคมีสำหรับวิศวกร เรียน Calculus, Physics และ Chemistry (ภาษาอังกฤษ) เพื่อปูพื้นฐานเรื่องโครงสร้างอะตอมและไฟฟ้า ซึ่งเป็นจุดเริ่มต้นของเซมิคอนดักเตอร์\n"
                                "● ปี 2: ฟิสิกส์อุปกรณ์ (Device Physics) และวงจรอิเล็กทรอนิกส์ เรียนเรื่องอุปกรณ์เซมิคอนดักเตอร์พื้นฐาน, วงจรไฟฟ้า (Circuit), สถิติวิศวกรรม และเริ่มเรียนเรื่อง วัสดุศาสตร์ ที่ใช้ในการผลิตชิป\n"
                                "● ปี 3: ปีแห่งการออกแบบและผลิต! เรียน IC Design และ Fabrication เรียนการออกแบบวงจรรวม (Integrated Circuit Design), เทคโนโลยีการผลิตสารกึ่งตัวนำ (Fabrication Technology) และระบบฝังตัว (Embedded Systems)\n"
                                "● ปี 4: สหกิจศึกษารูปแบบพิเศษ (Coop+) และ Senior Project เน้นการออกไปปฏิบัติงานจริงในอุตสาหกรรมเซมิคอนดักเตอร์ (Sandbox) เพื่อแก้ปัญหาหน้างาน และทำโครงงานจบการศึกษาที่เน้นนวัตกรรมชิปหรืออุปกรณ์อิเล็กทรอนิกส์ขั้นสูง");
                        }else if(selectedProgram == "พิเศษ"){
                            reply("ไม่มีสาขานี้ในภาคพิเศษครับ");
                        }else if(selectedProgram == "นานาชาติ"){
                            reply("ไม่มีสาขานี้ในภาคนานาชาติครับ");
                        }
                    }else if(selectedMajor == "บูรณาการณ์"){                    
                        if(selectedProgram == "ปกติ"){
                            reply("● ปี 1: พื้นฐานวิศวกรรมสากล และการปรับตัว (The Learner) เรียนวิชาพื้นฐานคณะ (Calculus, Physics, Programming) เหมือนสาขาอื่น แต่เน้นภาษาอังกฤษและการทำงานร่วมกับผู้อื่น (Soft Skills)\n"
                                "● ปี 2: เลือกเส้นทาง (The Specialist Path) เริ่มเลือก Module หรือแผนการเรียนเฉพาะที่สนใจ (เช่น วิศวกรอิเล็กทรอนิกส์, พลังงานทดแทน หรือ IT) และเรียนวิชาแกนด้านสถิติและวัสดุที่เกี่ยวข้องกับเส้นทางนั้น\n"
                                "● ปี 3: ปีแห่งการเจาะลึกวิชาเอกเลือก (The Deep Dive) เรียนวิชาที่ออกแบบร่วมกับบริษัทพาร์ทเนอร์ (เช่น ถ้าเลือกสาย Murata จะเน้นการผลิตและคุมคุณภาพ) เน้นเรียนในสิ่งที่ได้ใช้ เพื่อเตรียมพร้อมเข้าทำงานจริง\n"
                                "● ปี 4: สหกิจศึกษาเต็มรูปแบบ และ Senior Project (The Professional) เน้นการฝึกงานระยะยาวในบริษัท (Co-op) หรือทำโครงงานนวัตกรรม (Senior Project) โดยเน้นการแก้ปัญหาจริงที่เกิดขึ้นในภาคอุตสาหกรรม");
                        }else if(selectedProgram == "พิเศษ"){
                            reply("ไม่มีสาขานี้ในภาคพิเศษครับ");
                        }else if(selectedProgram == "นานาชาติ"){
                            reply("● ปี 1: พื้นฐานวิศวกรรมสากล และการเป็นมืออาชีพ (International Foundation)เรียน Calculus, Physics, Chemistry (ภาษาอังกฤษ) และวิชาพิเศษอย่าง Principle of Being Professional เพื่อปูพื้นฐานจรรยาบรรณและการทำงานในระดับสากล พร้อมทักษะการใช้เครื่องมือ Workshop\n"
                                "● ปี 2: กลศาสตร์วิศวกรรม และคณิตตรรกศาสตร์ (Analytical Skills)เรียน Engineering Mechanics (Statics & Dynamics), สถิติ, และ Introduction to Mathematical Logic เพื่อฝึกกระบวนการคิดวิเคราะห์เชิงระบบสำหรับงานบูรณาการ\n"
                                "● ปี 3: ปีแห่งการเลือกเส้นทางและนวัตกรรม (Specialization & Innovation)คุณจะได้เลือก Major Elective ตามความสนใจ (เช่น AI, พลังงานสะอาด, หรือ Smart City) และเรียนวิชา Innovation to Market เพื่อเรียนรู้การเปลี่ยนไอเดียวิศวกรรมให้เป็นธุรกิจจริง\n"
                                "● ปี 4: สหกิจศึกษาข้ามชาติ และ Senior Project (Global Professional)เน้นการออกฝึกงาน (Engineering Training) ในบริษัทข้ามชาติ หรือทำโครงงานจบการศึกษาที่เน้นการแก้ปัญหาระดับพหุวิทยาการ โดยใช้ทักษะภาษาอังกฤษสื่อสารผลงานในระดับมืออาชีพ");
                        }
                    }else if(selectedMajor == "ไฟฟ้า"){
                        if(selectedProgram == "ปกติ"){
                            reply("● ปี 1: พื้นฐานวิศวกรรมทั่วไป และวิชาเคมีสำหรับวิศวกร เน้น Calculus 1&2, Physics 1&2 และ Chemistry รวมถึงการปูพื้นฐานการเขียนโปรแกรมและการเขียนแบบวิศวกรรม (Engineering Drawing)\n"
                                "● ปี 2: วงจรไฟฟ้า (Circuit), อุปกรณ์อิเล็กทรอนิกส์ และการวัด เข้าสู่วิชาภาคเต็มตัวด้วย Electric Circuits 1&2, อุปกรณ์อิเล็กทรอนิกส์, สถิติวิศวกรรม และวิชาปราบเซียนอย่างการวิเคราะห์สัญญาณ (Signal Analysis)\n"
                                "● ปี 3: ปีแห่งวิชาแกนหลัก! เรียนเครื่องจักรกลไฟฟ้า, สนามแม่เหล็ก และระบบควบคุม เน้นวิชาหนักที่เป็นหัวใจของไฟฟ้า เช่น สนามแม่เหล็กไฟฟ้า (Electromagnetic Fields), เครื่องจักรกลไฟฟ้า (Electrical Machines) และเริ่มแยกสายวิชาเลือกในกลุ่มไฟฟ้ากำลังหรือไฟฟ้าสื่อสาร\n"
                                "● ปี 4: การออกแบบระบบไฟฟ้า, โครงงานจบการศึกษา และวิชาเลือกเฉพาะสาย เน้นการออกแบบระบบไฟฟ้า (Electrical System Design), วิศวกรรมไฟฟ้าแรงสูง และทุ่มเทให้กับ Senior Project (แผนโครงงาน) หรือเลือกออก สหกิจศึกษา (แผนปฏิบัติงานในสถานประกอบการ)");
                        }else if(selectedProgram == "พิเศษ"){
                            reply("● ปี 1: พื้นฐานวิศวกรรมทั่วไป และวิชาเคมีสำหรับวิศวกรเน้น Calculus 1&2, Physics 1&2 และ Chemistry เพื่อปูพื้นฐานการคำนวณและวิทยาศาสตร์ที่จำเป็น รวมถึงการเขียนแบบวิศวกรรม (Drawing)\n"
                                "● ปี 2: วงจรไฟฟ้า (Circuit), อุปกรณ์อิเล็กทรอนิกส์ และการวัดเริ่มเข้าวิชาภาคอย่าง Electric Circuits 1&2, การวัดและเครื่องมือวัด (Measurements), อุปกรณ์อิเล็กทรอนิกส์ และสถิติวิศวกรรม รวมถึงวิชาปราบเซียนอย่างการวิเคราะห์สัญญาณ (Signal Analysis)\n"
                                "● ปี 3: ปีแห่งวิชาแกนหลัก! เรียนเครื่องจักรกลไฟฟ้า, สนามแม่เหล็ก และระบบควบคุมเน้นวิชาที่เป็นหัวใจของวิศวกรไฟฟ้า เช่น สนามแม่เหล็กไฟฟ้า (Electromagnetic Fields), เครื่องจักรกลไฟฟ้า (Electrical Machines) และอิเล็กทรอนิกส์กำลัง (Power Electronics)\n"
                                "● ปี 4: การออกแบบระบบไฟฟ้า, โครงงานจบการศึกษา และวิชาเลือกเฉพาะสายเน้นการออกแบบระบบไฟฟ้า (Electrical System Design), วิศวกรรมไฟฟ้าแรงสูง และทุ่มเทให้กับ Senior Project หรือเลือกแผน สหกิจศึกษา เพื่อไปปฏิบัติงานจริงในบริษัท");
                        }else if(selectedProgram == "นานาชาติ"){
                            reply("● ปี 1: พื้นฐานวิศวกรรมสากล และการเป็นมืออาชีพ (English Foundation)เน้น Calculus 1&2, Physics 1&2, Chemistry (ภาษาอังกฤษ) และวิชาพื้นฐานอย่าง Drawing รวมถึงวิชา Principle of Being Professional เพื่อปูพื้นฐานจรรยาบรรณวิศวกรระดับสากล\n"
                                "● ปี 2: วงจรไฟฟ้า และการเขียนโปรแกรม (Circuits & Computing)เรียนวิชาแกนอย่าง Electric Circuits Analysis, Electronic Engineering, สถิติวิศวกรรม และที่สำคัญคือเริ่มเรียน Computer Programming for Engineers เพื่อใช้ในการคำนวณและควบคุมระบบ\n"
                                "● ปี 3: ปีแห่งระบบอัจฉริยะ! (Smart Systems)เรียนเครื่องจักรกลไฟฟ้า (Electrical Machines), อิเล็กทรอนิกส์กำลัง, ระบบสื่อสาร และเข้าสู่หัวใจของหลักสูตรคือ Smart Grid Technology และการจัดการพลังงานยุคใหม่\n"
                                "● ปี 4: การออกแบบระบบ และโครงงานนวัตกรรม (Advanced Integration)เรียนการออกแบบระบบไฟฟ้า (Electrical System Design), Distributed Generation (การผลิตไฟฟ้าแบบกระจายตัว), Electric Vehicles (EV) และทำโครงงานจบการศึกษา (Capstone Design Project) หรือเลือกออก สหกิจศึกษา ในบริษัทข้ามชาติ");
                        }
                    }else if(selectedMajor == "โยธา"){
                        if(selectedProgram == "ปกติ"){
                            reply("● ปี 1: พื้นฐานคำนวณและวิทยาศาสตร์เรียน Calculus 1&2, Physics 1&2 (เน้นกลศาสตร์เป็นพิเศษ) และ Chemistry นอกจากนี้ยังมีวิชา Engineering Drawing ที่ต้องเป๊ะเรื่องลายเส้นและมิติสัมพันธ์\n"
                                "● ปี 2: หัวใจของโยธา (Mechanics & Surveying)เริ่มเข้าวิชาภาคที่ดุเดือดอย่าง Statics (สถิตยศาสตร์), Mechanics of Solids (กลศาสตร์ของแข็ง), กลศาสตร์ของไหล และวิชาที่เป็นสัญลักษณ์ของโยธาอย่าง Surveying (การสำรวจ) ที่ต้องออกไปส่องกล้องทั่ว มช. ครับ\n"
                                "● ปี 3: การออกแบบโครงสร้างและวัสดุ (Design Phase)เรียนการออกแบบอย่างจริงจัง ทั้ง RC Design (คอนกรีตเสริมเหล็ก), Steel Design (โครงสร้างเหล็ก), วิศวกรรมปฐพี (Soil Mechanics) เพื่อดูฐานราก และวิศวกรรมทางหลวง (Highway Engineering)\n"
                                "● ปี 4: การบริหารงานก่อสร้างและ Senior Projectเน้นวิชาการจัดการ เช่น Construction Management, การประเมินราคา และทำโครงงานจบการศึกษา (Senior Project) หรือเลือกออก สหกิจศึกษา เพื่อไปลุยหน้างานจริงที่ไซด์งานก่อสร้าง");
                        }else if(selectedProgram == "พิเศษ"){
                            reply("ไม่มีสาขานี้ในภาคพิเศษครับ");
                        }else if(selectedProgram == "นานาชาติ"){
                            reply("● ปี 1: พื้นฐานวิศวกรรมสากล (Global Foundation)เรียน Calculus, Physics, Chemistry (ภาษาอังกฤษ) และวิชาพื้นฐานวิศวกรรม โดยเน้นการปรับตัวเข้าสู่การเรียนระบบนานาชาติ\n"
                                "● ปี 2: กลศาสตร์และการสำรวจ (Mechanics & Surveying)เรียนวิชาแกนอย่าง Statics, Strength of Materials, Fluid Mechanics และวิชาที่เด็กโยธาต้องผ่านคือ Surveying (การสำรวจ) ซึ่งใช้ตำราและศัพท์เทคนิคภาษาอังกฤษทั้งหมด\n"
                                "● ปี 3: การออกแบบโครงสร้างและเทคโนโลยี (Design & Innovation)เรียนการออกแบบคอนกรีตเสริมเหล็ก (RC Design), โครงสร้างเหล็ก และเริ่มนำเทคโนโลยีอย่าง BIM (Building Information Modeling) มาใช้ในการออกแบบและจำลองโครงสร้าง 3 มิติ\n"
                                "● ปี 4: การจัดการโครงการและวิชาเลือกเฉพาะทางเรียนการบริหารงานก่อสร้าง (Construction Management), วิศวกรรมระบบราง (Railway Engineering) หรือการจัดการภัยพิบัติ และทำโครงงานจบการศึกษา (Senior Project) เป็นภาษาอังกฤษ");
                        }
                    }else if(selectedMajor == "สิ่งแวดล้อม"){                   
                        if(selectedProgram == "ปกติ"){
                            reply("● ปี 1: พื้นฐานวิศวกรรมทั่วไป และวิชาเคมีสำหรับวิศวกร เรียนวิชาพื้นฐานคณะเหมือนสาขาอื่น (Calculus, Physics) แต่จะเน้น Chemistry for Engineers และแล็บเคมีเป็นพิเศษ เพื่อปูพื้นฐานการวิเคราะห์สารปนเปื้อนในสิ่งแวดล้อม\n"
                                "● ปี 2: เคมีน้ำและน้ำเสีย, ชีววิทยาสิ่งแวดล้อม และกลศาสตร์ เริ่มเข้าวิชาภาคอย่าง Environmental Chemistry (เคมีน้ำ), จุลชีววิทยาสิ่งแวดล้อม, สถิติวิศวกรรม และวิชาพื้นฐานอย่าง Statics และกลศาสตร์ของไหล (Fluid Mechanics)\n"
                                "● ปี 3: ปีแห่งการบำบัด! เรียนวิศวกรรมน้ำเสีย, ประปา และมลพิษอากาศ เน้นการคำนวณและออกแบบระบบ ได้แก่ Wastewater Engineering (น้ำเสีย), Water Supply (ประปา), อุทกวิทยา, และวิชาอากาศ (Air Pollution and Meteorology)\n"
                                "● ปี 4: การจัดการขยะ, การออกแบบโรงงาน และ Senior Project เรียนวิชาประยุกต์อย่าง Solid Waste Management (จัดการขยะมูลฝอย), การจัดการของเสียอันตราย, การประเมินผลกระทบสิ่งแวดล้อม (EIA) และทำโครงงานจบการศึกษา (Senior Project)");
                        }else if(selectedProgram == "พิเศษ"){
                            reply("ไม่มีสาขานี้ในภาคพิเศษครับ");
                        }else if(selectedProgram == "นานาชาติ"){
                            reply("ไม่มีสาขานี้ในภาคพิเศษครับ");
                        }
                    }else if(selectedMajor == "REAI"){                    
                        if(selectedProgram == "ปกติ"){
                            reply("● ปี 1: พื้นฐานวิศวกรรม และการเขียนโปรแกรมหุ่นยนต์เรียน Calculus, Physics และวิชาหัวใจคือ Computer Programming for Automation and Robotics พร้อมเริ่มทำโครงงานหุ่นยนต์ตัวแรกในวิชา Robotics Engineering Project 1\n"
                                "● ปี 2: กลศาสตร์, ระบบดิจิทัล และพลศาสตร์ (Dynamics)เรียนวิชาแกนอย่าง Statics, Mechanics of Solids, Electronics for Robotics และสถิติวิศวกรรม พร้อมลุยโครงงานต่อเนื่องใน Robotics Engineering Project 2\n"
                                "● ปี 3: ปีแห่งปัญญาประดิษฐ์ และการควบคุม (AI & Control)เรียนวิชา Artificial Intelligence for Robotics, Feedback Control Systems, Microprocessors และการจำลองระบบอัตโนมัติด้วยคอมพิวเตอร์ (Simulation)\n"
                                "● ปี 4: ระบบหุ่นยนต์อิสระ และ Senior Projectเรียน Autonomous Robotic System, ทักษะการเป็นผู้ประกอบการ และทุ่มเทเวลาให้กับ Senior Project (โครงงานวิศวกรรมหุ่นยนต์ 3 และ 4) เพื่อสร้างนวัตกรรมที่ใช้งานได้จริง");
                        }else if(selectedProgram == "พิเศษ"){
                            reply("ไม่มีสาขานี้ในภาคพิเศษครับ");
                        }else if(selectedProgram == "นานาชาติ"){
                            reply("ไม่มีสาขานี้ในภาคพิเศษครับ");
                        }
                    }else if(selectedMajor == "เหมืองแร่"){                   
                        if(selectedProgram == "ปกติ"){
                            reply("● ปี 1: พื้นฐานวิศวกรรมทั่วไป และวิชาเคมีสำหรับวิศวกรเรียนเหมือนภาคปกติสาขาอื่น (Calculus, Physics, Drawing) แต่จะเริ่มมีการปูพื้นฐานด้านวัสดุศาสตร์เบื้องต้น\n"
                                "● ปี 2: ธรณีวิศวกรรม (Engineering Geology), กลศาสตร์ และการรังวัด (Surveying)เน้นการดูหินและแร่, การสำรวจรังวัดแผนที่ดิน, กลศาสตร์ของแข็ง และสถิติพื้นฐานเพื่อการวิเคราะห์ทางธรณีวิทยา\n"
                                "● ปี 3: ปีแห่งการขุดและสกัด! เรียนการทำเหมือง (Mining Methods), การแต่งแร่ (Mineral Processing), กลศาสตร์หิน (Rock Mechanics)เน้นวิชาเฉพาะทางอย่างการออกแบบเหมืองผิวดิน/ใต้ดิน, การใช้วัตถุระเบิดในงานวิศวกรรม และเศรษฐศาสตร์แร่\n"
                                "● ปี 4: วิศวกรรมสิ่งแวดล้อมเหมืองแร่, การออกแบบโรงแต่งแร่ และ Senior Project เน้นการฟื้นฟูพื้นที่เหมืองแร่, ความปลอดภัยในงานเหมือง, การจัดการสิ่งแวดล้อม และโครงงานจบการศึกษาที่เน้นการแก้ปัญหาจริงในอุตสาหกรรมแร่ธาตุหรือก่อสร้าง");
                        }else if(selectedProgram == "พิเศษ"){
                            reply("ไม่มีสาขานี้ในภาคพิเศษครับ");
                        }else if(selectedProgram == "นานาชาติ"){
                            reply("ไม่มีสาขานี้ในภาคพิเศษครับ");
                        }
                    }else if(selectedMajor == "อุตสาหการ"){                    
                        if(selectedProgram == "ปกติ"){
                            reply("● ปี 1: พื้นฐานวิศวกรรมทั่วไป และวิชาเคมีสำหรับวิศวกร (เน้นหนักที่ Calculus 1&2, Physics 1&2 และ Drawing เพื่อปูพื้นฐานการคำนวณ)\n"
                                "● ปี 2: สถิติวิศวกรรม (Engineering Stat), กรรมวิธีการผลิต และกลศาสตร์ (เริ่มเข้าวิชาภาคอย่าง Material, Statics และ Strength of Materials เพื่อเข้าใจพื้นฐานโรงงาน)\n"
                                "● ปี 3: ปีแห่งการวางแผน! เรียน Operations Research (OR), คุมคุณภาพ (QC), เศรษฐศาสตร์วิศวกรรม (เน้นการคำนวณเพื่อเพิ่มประสิทธิภาพการผลิตและการศึกษางาน หรือ Work Study)\n"
                                "● ปี 4: การจัดการโลจิสติกส์, การออกแบบโรงงาน และ Senior Project (เน้นการนำความรู้มาออกแบบผังโรงงานจริง ความปลอดภัย และทำโครงงานวิศวกรรมจบการศึกษา)");
                        }else if(selectedProgram == "พิเศษ"){
                            reply("● ปี 1: วางรากฐานวิศวกร * เรียนวิชาพื้นฐานคำนวณและวิทยาศาสตร์ (Calculus, Physics, Chemistry), การเขียนแบบวิศวกรรม (Engineering Drawing) และการเขียนโปรแกรมเบื้องต้น\n"
                              "● ปี 2: เจาะลึกกลศาสตร์และพื้นฐาน IE เรียนสถิติวิศวกรรม (Engineering Stat), กลศาสตร์ (Statics), ความแข็งแรงของวัสดุ (Strength of Materials), วัสดุวิศวกรรม และกรรมวิธีการผลิต (Manufacturing\n)"
                              "● ปี 3: ปีแห่งการวิเคราะห์และการเพิ่มประสิทธิภาพ (Optimization) เรียนการวิจัยดำเนินงาน (OR), การศึกษางาน (Work Study), การควบคุมคุณภาพ (QC), เศรษฐศาสตร์วิศวกรรม และการวางแผนควบคุมการผลิต\n"
                              "● ปี 4: บูรณาการการจัดการและโครงงานจบการศึกษา เรียนการจัดการโลจิสติกส์และโซ่อุปทาน, การออกแบบผังโรงงาน (Plant Design), วิศวกรรมความปลอดภัย และทำโครงงานวิศวกรรม (Senior Project)");
                        }else if(selectedProgram == "นานาชาติ"){
                            reply("● ปี 1: พื้นฐานวิศวกรรมสากล และการโปรแกรมเน้น Calculus, Physics (ภาษาอังกฤษทั้งหมด) และที่ต่างคือเริ่มเรียน Computer Programming อย่างเข้มข้นตั้งแต่ปี 1 เพื่อปูพื้นฐานด้านระบบสารสนเทศ\n"
                                "● ปี 2: สถิติวิศวกรรม (Engineering Stat), พื้นฐานไอที และเศรษฐศาสตร์เรียนสถิติขั้นสูง, ระบบฐานข้อมูล (Database), และวิชาด้านการจัดการเบื้องต้น เพื่อเตรียมพร้อมสำหรับการวิเคราะห์ข้อมูลขนาดใหญ่ (Big Data)\n"
                                "● ปี 3: ปีแห่งการเพิ่มประสิทธิภาพ (Optimization) และโลจิสติกส์!เรียนวิจัยดำเนินงาน (OR), การจัดการโซ่อุปทาน (Supply Chain), การจำลองสถานการณ์ด้วยคอมพิวเตอร์ (Simulation) และการควบคุมคุณภาพ (QC)\n"
                                "● ปี 4: การจัดการโลจิสติกส์ขั้นสูง, โครงงานนวัตกรรม และ Senior Project เน้นการออกแบบระบบโลจิสติกส์อัจฉริยะ, การจัดการการดำเนินงานสากล และทำโครงงานจบการศึกษาที่เน้นการแก้ปัญหาด้วยเทคโนโลยีสมัยใหม่");
                        }
                    }
                }
                break;
        }
        return true;
    }
};
