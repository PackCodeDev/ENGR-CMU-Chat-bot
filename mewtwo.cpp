#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// สถานะย่อยสำหรับระบบนักศึกษาปี 1 (Freshman / Curriculum)
enum FreshmanState {
    FRESH_STATE_SELECT_PROGRAM, // เลือกภาค (ปกติ, พิเศษ, นานาชาติ)
    FRESH_STATE_SELECT_MAJOR,   // เลือกสาขา
    FRESH_STATE_DETAIL,         // คำถามเจาะลึก (เรียนอะไรบ้าง)
    FRESH_STATE_Building,       // ข้อมูลตึกที่เรียน
    FRESH_STATE_ACCESSORIES,    // อุปกรณ์ที่ใช้เรียน
    FRESH_STATE_DORMITORY,      // หอพัก
    FRESH_STATE_CLOTHES,        // ชุด
};

class FreshmanHandler {
public:
    FreshmanState currentState = FRESH_STATE_SELECT_PROGRAM;
    std::string selectedProgram = "";
    std::string selectedMajor = "";
    std::string selectedDetail = "";
    std::string selectedBuilding = "";
    std::string selectedAccessories = "";  
    std::string guide =
        "\nคุณสามารถพิมพ์:\n"
        "เรียนอะไร\n"
        "อาคารเรียน\n"
        "อุปกรณ์\n"
        "เปลี่ยนสาขา\n"
        "เปลี่ยนภาค\n"
        "หอพัก\n"
        "เครื่องแต่งกาย\n"
        "ออก\n";
    std::string toLower(std::string s){
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

    // ฟังก์ชันเช็คคีย์เวิร์ด
    bool hasKeyword(std::string input, std::string keyword){
    input = toLower(input);
    keyword = toLower(keyword);
    return input.find(keyword) != std::string::npos;
}

    // ฟังก์ชันหลักประมวลผลการทำงาน
    bool processFreshman(std::string input, std::vector<std::string>& chatHistory) {
        
        auto reply = [&](std::string text) {
            chatHistory.push_back("Chatbot: " + text);
        };

        // ตรวจสอบการออกจากโหมด
        if (hasKeyword(input, "ออก") || hasKeyword(input, "กลับ") || hasKeyword(input, "เมนูหลัก")) {
            currentState = FRESH_STATE_SELECT_PROGRAM;
            selectedProgram = ""; 
            selectedMajor = ""; 
            selectedDetail = "";
            return false; // ส่งสัญญาณ false กลับไปให้ main.cpp ดึงกลับเมนูหลัก
        }

        switch (currentState) {
            case FRESH_STATE_SELECT_PROGRAM:
                if (hasKeyword(input, "ปกติ")) {
                    selectedProgram = "ปกติ";
                    reply("เลือกภาคปกติแล้วครับ ต่อไปพิมพ์ชื่อสาขาที่สนใจได้เลยครับ\n(เช่น คอมพิวเตอร์, เครื่องกล, โยธา, ไฟฟ้า, เซมิคอนดักเตอร์, บูรณาการ)");
                    currentState = FRESH_STATE_SELECT_MAJOR;
                } 
                else if (hasKeyword(input, "พิเศษ")) {
                    selectedProgram = "พิเศษ";
                    reply("เลือกภาคพิเศษแล้วครับ ต่อไปพิมพ์ชื่อสาขาที่สนใจได้เลยครับ\n(เช่น อุตสาหการ, ไฟฟ้า, เครื่องกล)");
                    currentState = FRESH_STATE_SELECT_MAJOR;
                } 
                else if (hasKeyword(input, "นานาชาติ")) {
                    selectedProgram = "นานาชาติ";
                    reply("เลือกภาคนานาชาติแล้วครับ ต่อไปพิมพ์ชื่อสาขาที่สนใจได้เลยครับ\n(เช่น เครื่องกล, บูรณาการ, ไฟฟ้า, โยธา, ISNE, อุตสาหการ)");
                    currentState = FRESH_STATE_SELECT_MAJOR;
                } 
                else {
                    reply("กรุณาเลือกภาคที่ต้องการ: ปกติ, พิเศษ หรือ นานาชาติ ครับ\n(หรือพิมพ์ 'ออก' เพื่อกลับเมนูหลัก)");
                }
                break;

// =========================================================================================================================================

            case FRESH_STATE_SELECT_MAJOR:
                // ---------------- ภาคปกติ ----------------
                if ((hasKeyword(input, "คอม") || hasKeyword(input, "คอมพิวเตอร์")) && selectedProgram == "ปกติ") {
                    selectedMajor = "คอมพิวเตอร์";
                    reply("ต้องการสอบถามเรื่องใดเกี่ยวกับวิศวกรรมคอมพิวเตอร์ครับ?");
                    currentState = FRESH_STATE_DETAIL;
                }
                else if ((hasKeyword(input, "เครื่องกล") || hasKeyword(input, "เครื่อง")) && selectedProgram == "ปกติ") {
                    selectedMajor = "เครื่องกล";
                    reply("ต้องการสอบถามเรื่องใดเกี่ยวกับวิศวกรรมเครื่องกลครับ?");
                    currentState = FRESH_STATE_DETAIL;
                }
                else if ((hasKeyword(input, "ไฟฟ้า") || hasKeyword(input, "ไฟ")) && selectedProgram == "ปกติ") {
                    selectedMajor = "ไฟฟ้า";
                    reply("ต้องการสอบถามเรื่องใดเกี่ยวกับวิศวกรรมไฟฟ้าครับ?");
                    currentState = FRESH_STATE_DETAIL;
                }
                else if (hasKeyword(input, "โยธา") && selectedProgram == "ปกติ") {
                    selectedMajor = "โยธา";
                    reply("ต้องการสอบถามเรื่องใดเกี่ยวกับวิศวกรรมโยธาครับ?");
                    currentState = FRESH_STATE_DETAIL;
                }
                else if ((hasKeyword(input, "อุตสาหการ") || hasKeyword(input, "IE")) && selectedProgram == "ปกติ") {
                    selectedMajor = "อุตสาหการ";
                    reply("ต้องการสอบถามเรื่องใดเกี่ยวกับวิศวกรรมอุตสาหการครับ?");
                    currentState = FRESH_STATE_DETAIL;
                }
                else if (hasKeyword(input, "สิ่งแวดล้อม") && selectedProgram == "ปกติ") {
                    selectedMajor = "สิ่งแวดล้อม";
                    reply("ต้องการสอบถามเรื่องใดเกี่ยวกับวิศวกรรมสิ่งแวดล้อมครับ?");
                    currentState = FRESH_STATE_DETAIL;
                }
                else if ((hasKeyword(input, "เหมืองแร่") || hasKeyword(input, "ปิโตรเลียม")) && selectedProgram == "ปกติ") {
                    selectedMajor = "เหมืองแร่";
                    reply("ต้องการสอบถามเรื่องใดเกี่ยวกับวิศวกรรมเหมืองแร่และปิโตรเลียมครับ?");
                    currentState = FRESH_STATE_DETAIL;
                }
                else if ((hasKeyword(input, "reai") || hasKeyword(input, "robot") || hasKeyword(input, "หุ่นยนต์") || hasKeyword(input, "ai")) && selectedProgram == "ปกติ") {
                    selectedMajor = "REAI";
                    reply("ต้องการสอบถามเรื่องใดเกี่ยวกับวิศวกรรมหุ่นยนต์และปัญญาประดิษฐ์ครับ? (ลองพิมพ์ 'เรียนอะไร')");
                    currentState = FRESH_STATE_DETAIL;
                }
                else if ((hasKeyword(input, "เซมิคอนดักเตอร์") || hasKeyword(input, "เซมิ")) && selectedProgram == "ปกติ") {
                    selectedMajor = "เซมิคอนดักเตอร์";
                    reply("ต้องการสอบถามเรื่องใดเกี่ยวกับวิศวกรรมเซมิคอนดักเตอร์ครับ? (ลองพิมพ์ 'เรียนอะไร')");
                    currentState = FRESH_STATE_DETAIL;
                }
                else if ((hasKeyword(input, "บูรณาการ") || hasKeyword(input, "บูรณาการณ์")) && selectedProgram == "ปกติ") {
                    selectedMajor = "บูรณาการ";
                    reply("ต้องการสอบถามเรื่องใดเกี่ยวกับวิศวกรรมบูรณาการครับ? (ลองพิมพ์ 'เรียนอะไร')");
                    currentState = FRESH_STATE_DETAIL;
                }

                // ---------------- ภาคพิเศษ ----------------
                else if (hasKeyword(input, "อุตสาหการ") && selectedProgram == "พิเศษ") {
                    selectedMajor = "อุตสาหการ";
                    reply("ต้องการสอบถามเรื่องใดเกี่ยวกับวิศวกรรมอุตสาหการ (พิเศษ) ครับ? (ลองพิมพ์ 'เรียนอะไร')");
                    currentState = FRESH_STATE_DETAIL;
                }
                else if (hasKeyword(input, "ไฟฟ้า") && selectedProgram == "พิเศษ") {
                    selectedMajor = "ไฟฟ้า";
                    reply("ต้องการสอบถามเรื่องใดเกี่ยวกับวิศวกรรมไฟฟ้า (พิเศษ) ครับ? (ลองพิมพ์ 'เรียนอะไร')");
                    currentState = FRESH_STATE_DETAIL;
                }
                else if (hasKeyword(input, "เครื่องกล") && selectedProgram == "พิเศษ") {
                    selectedMajor = "เครื่องกล";
                    reply("ต้องการสอบถามเรื่องใดเกี่ยวกับวิศวกรรมเครื่องกล (พิเศษ) ครับ? (ลองพิมพ์ 'เรียนอะไร')");
                    currentState = FRESH_STATE_DETAIL;
                }

                // ---------------- ภาคนานาชาติ ----------------
                else if (hasKeyword(input, "เครื่องกล") && selectedProgram == "นานาชาติ") {
                    selectedMajor = "เครื่องกล";
                    reply("ต้องการสอบถามเรื่องใดเกี่ยวกับเครื่องกล (นานาชาติ) ครับ? (ลองพิมพ์ 'เรียนอะไร')");
                    currentState = FRESH_STATE_DETAIL;
                }
                else if ((hasKeyword(input, "บูรณาการ") || hasKeyword(input, "บูรณาการณ์")) && selectedProgram == "นานาชาติ") {
                    selectedMajor = "บูรณาการ";
                    reply("ต้องการสอบถามเรื่องใดเกี่ยวกับบูรณาการ (นานาชาติ) ครับ? (ลองพิมพ์ 'เรียนอะไร')");
                    currentState = FRESH_STATE_DETAIL;
                }
                else if (hasKeyword(input, "ไฟฟ้า") && selectedProgram == "นานาชาติ") {
                    selectedMajor = "ไฟฟ้า";
                    reply("ต้องการสอบถามเรื่องใดเกี่ยวกับวิศวกรรมไฟฟ้า (นานาชาติ) ครับ? (ลองพิมพ์ 'เรียนอะไร')");
                    currentState = FRESH_STATE_DETAIL;
                }
                else if (hasKeyword(input, "โยธา") && selectedProgram == "นานาชาติ") {
                    selectedMajor = "โยธา";
                    reply("ต้องการสอบถามเรื่องใดเกี่ยวกับวิศวกรรมโยธา (นานาชาติ) ครับ? (ลองพิมพ์ 'เรียนอะไร')");
                    currentState = FRESH_STATE_DETAIL;
                }
                else if ((hasKeyword(input, "ISNE") || hasKeyword(input, "สารสนเทศ")) && selectedProgram == "นานาชาติ") {
                    selectedMajor = "ISNE";
                    reply("ต้องการสอบถามเรื่องใดเกี่ยวกับวิศวกรรมระบบสารสนเทศและเครือข่าย (ISNE) ครับ? (ลองพิมพ์ 'เรียนอะไร')");
                    currentState = FRESH_STATE_DETAIL;
                }
                else if (hasKeyword(input, "อุตสาหการ") && selectedProgram == "นานาชาติ") {
                    selectedMajor = "อุตสาหการ";
                    reply("ต้องการสอบถามเรื่องใดเกี่ยวกับวิศวกรรมอุตสาหการ (นานาชาติ) ครับ? (ลองพิมพ์ 'เรียนอะไร')");
                    currentState = FRESH_STATE_DETAIL;
                }
                // ถ้าพิมพ์ผิด หรือเลือกสาขาที่ไม่มีในภาคนั้นๆ
                else if (hasKeyword(input, "เปลี่ยนภาค")) {
                    currentState = FRESH_STATE_SELECT_PROGRAM;

                    selectedProgram = "";
                    selectedMajor = "";
                    selectedDetail = "";
                    selectedBuilding = "";
                    selectedAccessories = "";        

                    reply("กลับไปเลือกภาคใหม่ครับ: ปกติ / พิเศษ / นานาชาติ");
                }
                else {
                    reply("ไม่พบสาขาที่ระบุในหลักสูตรนี้ครับ ลองพิมพ์ชื่อสาขาใหม่");
                }

break; // อย่าลืมใส่ break ตรงนี้เสมอ!

// =========================================================================================================================================

            case FRESH_STATE_DETAIL:
                if (hasKeyword(input, "เรียนอะไร") || hasKeyword(input, "เกี่ยวกับอะไร") || hasKeyword(input, "เรียนเกี่ยวกับ")) {        
                    if (selectedMajor == "คอมพิวเตอร์") {
                        if (selectedProgram == "ปกติ") {
                            reply("ปี 1: พื้นฐานวิศวกรรมทั่วไป และการโปรแกรมเบื้องต้นเน้น Calculus, Physics และวิชาหัวใจหลักคือ Computer Programming (มักเริ่มด้วย C หรือ Python) เพื่อฝึกตรรกะการแก้ปัญหา (Logic)\n"
                                "ปี 2: โครงสร้างข้อมูล (Data Structures), ระบบดิจิทัล และวงจรไฟฟ้าเรียนวิชาปราบเซียนอย่าง Discrete Mathematics, Digital Systems, Data Structures & Algorithms และการออกแบบวงจรไฟฟ้าพื้นฐาน\n"
                                "ปี 3: ปีแห่งระบบปฏิบัติการ! เรียน OS, ฐานข้อมูล (Database), และเครือข่าย (Network)เน้นวิชาสายระบบอย่าง Operating Systems, Computer Architecture, Software Engineering และ Microprocessors (การเขียนโปรแกรมควบคุมบอร์ด)\n"
                                "ปี 4: ปัญญาประดิษฐ์ (AI), ความมั่นคงปลอดภัยไซเบอร์ และ Senior Project เรียนวิชาล้ำสมัยอย่าง Machine Learning (AI), Computer Security และเน้นการทำโครงงานจบการศึกษา (Senior Project) ที่สร้างนวัตกรรมหรือซอฟต์แวร์ใช้งานจริง\n"+guide);
                        } else {
                            reply("ไม่มีสาขานี้ในภาคที่คุณเลือกครับ");
                        }
                    } 
                    else if (selectedMajor == "เครื่องกล") {
                        if (selectedProgram == "ปกติ") {
                            reply("ปี 1: พื้นฐานวิศวกรรมทั่วไป และวิชาเคมีสำหรับวิศวกรเน้น Calculus 1&2 และ Physics 1&2 (โดยเฉพาะเรื่องแรงและการเคลื่อนที่) และเริ่มเรียนการเขียนแบบวิศวกรรม (Drawing) ด้วยคอมพิวเตอร์\n"
                                "ปี 2: พื้นฐานกลศาสตร์ (Mechanics), สถิติวิศวกรรม และอุณหพลศาสตร์ (Thermo)เรียนวิชาแกนหลักอย่าง Statics (สถิตยศาสตร์), Dynamics (พลศาสตร์), และ Thermodynamics (การถ่ายเทความร้อนและพลังงาน) รวมถึงเริ่มฝึกงานโรงงาน (Workshop)\n"
                                "ปี 3: ปีแห่งการคำนวณขั้นสูง! เรียนกลศาสตร์ของไหล (Fluid), การถ่ายเทความร้อน (Heat Transfer), และการออกแบบเครื่องจักรเน้นวิชาเฉพาะทางอย่าง Fluid Mechanics, Mechanical Design (การออกแบบชิ้นส่วนเครื่องกล) และระบบควบคุมอัตโนมัติ (Automatic Control)\n"
                                "ปี 4: ระบบปรับอากาศ, เครื่องยนต์สันดาปภายใน และ Senior Project เรียนวิชาประยุกต์อย่าง Power Plant Engineering, Internal Combustion Engines, การทำความเย็น และโครงงานจบการศึกษาที่เน้นการสร้างเครื่องจักรหรือแบบจำลองทางวิศวกรรม\n"+guide);
                        } else if (selectedProgram == "พิเศษ") {
                            reply("ปี 1: พื้นฐานวิศวกรรมทั่วไป และวิชาเคมีสำหรับวิศวกรเน้นการปูพื้นฐานคำนวณหนักๆ อย่าง Calculus 1&2 และ Physics 1&2 (กลศาสตร์และไฟฟ้า) รวมถึงการเขียนแบบวิศวกรรม (Engineering Drawing)\n"
                                "ปี 2: สถิติวิศวกรรม (Engineering Stat), อุณหพลศาสตร์ (Thermo) และกลศาสตร์เริ่มเข้าวิชาภาคอย่าง Statics (สถิตยศาสตร์), Dynamics (พลศาสตร์) และ Thermodynamics เพื่อเข้าใจการเปลี่ยนรูปพลังงานและแรง\n"
                                "ปี 3: ปีแห่งการคำนวณขั้นสูง! เรียนกลศาสตร์ของไหล (Fluid), การถ่ายเทความร้อน (Heat), และการออกแบบเครื่องจักรเน้นวิชาเฉพาะทางอย่าง Fluid Mechanics, Heat Transfer, ระบบควบคุมอัตโนมัติ และการออกแบบชิ้นส่วนเครื่องกล (Machine Design)\n"
                                "ปี 4: ระบบปรับอากาศ, เครื่องยนต์สันดาป และ Senior Project เรียนวิชาประยุกต์อย่างวิศวกรรมโรงไฟฟ้า, ระบบทำความเย็น, การสั่นสะเทือนทางเครื่องกล และทำโครงงานวิศวกรรมจบการศึกษา (Senior Project)\n"+guide);
                        } else if (selectedProgram == "นานาชาติ") {
                            reply("ปี 1: พื้นฐานวิศวกรรมสากล และวิชาเคมี (English Medium)เรียน Calculus, Physics และ Chemistry โดยใช้ตำราและบรรยายเป็นภาษาอังกฤษทั้งหมด พร้อมฝึกทักษะการสื่อสารทางวิศวกรรม\n"
                                "ปี 2: กลศาสตร์พื้นฐาน และการประมวลผลด้วยคอมพิวเตอร์ เรียน Statics, Dynamics, Thermodynamics และเริ่มใช้โปรแกรมคอมพิวเตอร์ในการคำนวณทางวิศวกรรมเครื่องกล (Computational Tools)\n"
                                "ปี 3: ปีแห่งวิชาแกนหลัก และโอกาสไปต่างประเทศ! เรียน Fluid Mechanics, Heat Transfer และ Machine Design โดยในช่วงนี้มักจะมีโครงการแลกเปลี่ยนหรือเตรียมตัวไปเรียนที่มหาวิทยาลัยพาร์ทเนอร์ (เช่น ในเยอรมนี หรือญี่ปุ่น)\n"
                                "ปี 4: เทคโนโลยีพลังงานสะอาด, ระบบอัตโนมัติ และ Senior Project เน้นวิชาเลือกที่ทันสมัย เช่น Renewable Energy, Robotics และทำงานวิจัยจบการศึกษา (Senior Project) โดยนำเสนอเป็นภาษาอังกฤษ\n"+guide);
                        }
                    } 
                    else if (selectedMajor == "เซมิคอนดักเตอร์") {
                        if (selectedProgram == "ปกติ") {
                            reply("ปี 1: พื้นฐานวิศวกรรมสากล และวิชาเคมีสำหรับวิศวกร เรียน Calculus, Physics และ Chemistry (ภาษาอังกฤษ) เพื่อปูพื้นฐานเรื่องโครงสร้างอะตอมและไฟฟ้า ซึ่งเป็นจุดเริ่มต้นของเซมิคอนดักเตอร์\n"
                                "ปี 2: ฟิสิกส์อุปกรณ์ (Device Physics) และวงจรอิเล็กทรอนิกส์ เรียนเรื่องอุปกรณ์เซมิคอนดักเตอร์พื้นฐาน, วงจรไฟฟ้า (Circuit), สถิติวิศวกรรม และเริ่มเรียนเรื่อง วัสดุศาสตร์ ที่ใช้ในการผลิตชิป\n"
                                "ปี 3: ปีแห่งการออกแบบและผลิต! เรียน IC Design และ Fabrication เรียนการออกแบบวงจรรวม (Integrated Circuit Design), เทคโนโลยีการผลิตสารกึ่งตัวนำ (Fabrication Technology) และระบบฝังตัว (Embedded Systems)\n"
                                "ปี 4: สหกิจศึกษารูปแบบพิเศษ (Coop+) และ Senior Project เน้นการออกไปปฏิบัติงานจริงในอุตสาหกรรมเซมิคอนดักเตอร์ (Sandbox) เพื่อแก้ปัญหาหน้างาน และทำโครงงานจบการศึกษาที่เน้นนวัตกรรมชิปหรืออุปกรณ์อิเล็กทรอนิกส์ขั้นสูง\n"+guide);
                        } else {
                            reply("ไม่มีสาขานี้ในภาคที่คุณเลือกครับ");
                        }
                    } 
                    else if (selectedMajor == "บูรณาการ") {                    
                        if (selectedProgram == "ปกติ") {
                            reply("ปี 1: พื้นฐานวิศวกรรมสากล และการปรับตัว (The Learner) เรียนวิชาพื้นฐานคณะ (Calculus, Physics, Programming) เหมือนสาขาอื่น แต่เน้นภาษาอังกฤษและการทำงานร่วมกับผู้อื่น (Soft Skills)\n"
                                "ปี 2: เลือกเส้นทาง (The Specialist Path) เริ่มเลือก Module หรือแผนการเรียนเฉพาะที่สนใจ (เช่น วิศวกรอิเล็กทรอนิกส์, พลังงานทดแทน หรือ IT) และเรียนวิชาแกนด้านสถิติและวัสดุที่เกี่ยวข้องกับเส้นทางนั้น\n"
                                "ปี 3: ปีแห่งการเจาะลึกวิชาเอกเลือก (The Deep Dive) เรียนวิชาที่ออกแบบร่วมกับบริษัทพาร์ทเนอร์ (เช่น ถ้าเลือกสาย Murata จะเน้นการผลิตและคุมคุณภาพ) เน้นเรียนในสิ่งที่ได้ใช้ เพื่อเตรียมพร้อมเข้าทำงานจริง\n"
                                "ปี 4: สหกิจศึกษาเต็มรูปแบบ และ Senior Project (The Professional) เน้นการฝึกงานระยะยาวในบริษัท (Co-op) หรือทำโครงงานนวัตกรรม (Senior Project) โดยเน้นการแก้ปัญหาจริงที่เกิดขึ้นในภาคอุตสาหกรรม\n"+guide);
                        } else if (selectedProgram == "นานาชาติ") {
                            reply("ปี 1: พื้นฐานวิศวกรรมสากล และการเป็นมืออาชีพ (International Foundation)เรียน Calculus, Physics, Chemistry (ภาษาอังกฤษ) และวิชาพิเศษอย่าง Principle of Being Professional เพื่อปูพื้นฐานจรรยาบรรณและการทำงานในระดับสากล พร้อมทักษะการใช้เครื่องมือ Workshop\n"
                                "ปี 2: กลศาสตร์วิศวกรรม และคณิตตรรกศาสตร์ (Analytical Skills)เรียน Engineering Mechanics (Statics & Dynamics), สถิติ, และ Introduction to Mathematical Logic เพื่อฝึกกระบวนการคิดวิเคราะห์เชิงระบบสำหรับงานบูรณาการ\n"
                                "ปี 3: ปีแห่งการเลือกเส้นทางและนวัตกรรม (Specialization & Innovation)คุณจะได้เลือก Major Elective ตามความสนใจ (เช่น AI, พลังงานสะอาด, หรือ Smart City) และเรียนวิชา Innovation to Market เพื่อเรียนรู้การเปลี่ยนไอเดียวิศวกรรมให้เป็นธุรกิจจริง\n"
                                "ปี 4: สหกิจศึกษาข้ามชาติ และ Senior Project (Global Professional)เน้นการออกฝึกงาน (Engineering Training) ในบริษัทข้ามชาติ หรือทำโครงงานจบการศึกษาที่เน้นการแก้ปัญหาระดับพหุวิทยาการ โดยใช้ทักษะภาษาอังกฤษสื่อสารผลงานในระดับมืออาชีพ\n"+guide);
                        } else {
                            reply("ไม่มีสาขานี้ในภาคพิเศษครับ");
                        }
                    } 
                    else if (selectedMajor == "ไฟฟ้า") {
                        if (selectedProgram == "ปกติ") {
                            reply("ปี 1: พื้นฐานวิศวกรรมทั่วไป และวิชาเคมีสำหรับวิศวกร เน้น Calculus 1&2, Physics 1&2 และ Chemistry รวมถึงการปูพื้นฐานการเขียนโปรแกรมและการเขียนแบบวิศวกรรม (Engineering Drawing)\n"
                                "ปี 2: วงจรไฟฟ้า (Circuit), อุปกรณ์อิเล็กทรอนิกส์ และการวัด เข้าสู่วิชาภาคเต็มตัวด้วย Electric Circuits 1&2, อุปกรณ์อิเล็กทรอนิกส์, สถิติวิศวกรรม และวิชาปราบเซียนอย่างการวิเคราะห์สัญญาณ (Signal Analysis)\n"
                                "ปี 3: ปีแห่งวิชาแกนหลัก! เรียนเครื่องจักรกลไฟฟ้า, สนามแม่เหล็ก และระบบควบคุม เน้นวิชาหนักที่เป็นหัวใจของไฟฟ้า เช่น สนามแม่เหล็กไฟฟ้า (Electromagnetic Fields), เครื่องจักรกลไฟฟ้า (Electrical Machines) และเริ่มแยกสายวิชาเลือกในกลุ่มไฟฟ้ากำลังหรือไฟฟ้าสื่อสาร\n"
                                "ปี 4: การออกแบบระบบไฟฟ้า, โครงงานจบการศึกษา และวิชาเลือกเฉพาะสาย เน้นการออกแบบระบบไฟฟ้า (Electrical System Design), วิศวกรรมไฟฟ้าแรงสูง และทุ่มเทให้กับ Senior Project (แผนโครงงาน) หรือเลือกออก สหกิจศึกษา (แผนปฏิบัติงานในสถานประกอบการ)\n"+guide);
                        } else if (selectedProgram == "พิเศษ") {
                            reply("ปี 1: พื้นฐานวิศวกรรมทั่วไป และวิชาเคมีสำหรับวิศวกรเน้น Calculus 1&2, Physics 1&2 และ Chemistry เพื่อปูพื้นฐานการคำนวณและวิทยาศาสตร์ที่จำเป็น รวมถึงการเขียนแบบวิศวกรรม (Drawing)\n"
                                "ปี 2: วงจรไฟฟ้า (Circuit), อุปกรณ์อิเล็กทรอนิกส์ และการวัดเริ่มเข้าวิชาภาคอย่าง Electric Circuits 1&2, การวัดและเครื่องมือวัด (Measurements), อุปกรณ์อิเล็กทรอนิกส์ และสถิติวิศวกรรม รวมถึงวิชาปราบเซียนอย่างการวิเคราะห์สัญญาณ (Signal Analysis)\n"
                                "ปี 3: ปีแห่งวิชาแกนหลัก! เรียนเครื่องจักรกลไฟฟ้า, สนามแม่เหล็ก และระบบควบคุมเน้นวิชาที่เป็นหัวใจของวิศวกรไฟฟ้า เช่น สนามแม่เหล็กไฟฟ้า (Electromagnetic Fields), เครื่องจักรกลไฟฟ้า (Electrical Machines) และอิเล็กทรอนิกส์กำลัง (Power Electronics)\n"
                                "ปี 4: การออกแบบระบบไฟฟ้า, โครงงานจบการศึกษา และวิชาเลือกเฉพาะสายเน้นการออกแบบระบบไฟฟ้า (Electrical System Design), วิศวกรรมไฟฟ้าแรงสูง และทุ่มเทให้กับ Senior Project หรือเลือกแผน สหกิจศึกษา เพื่อไปปฏิบัติงานจริงในบริษัท\n"+guide);
                        } else if (selectedProgram == "นานาชาติ") {
                            reply("ปี 1: พื้นฐานวิศวกรรมสากล และการเป็นมืออาชีพ (English Foundation)เน้น Calculus 1&2, Physics 1&2, Chemistry (ภาษาอังกฤษ) และวิชาพื้นฐานอย่าง Drawing รวมถึงวิชา Principle of Being Professional เพื่อปูพื้นฐานจรรยาบรรณวิศวกรระดับสากล\n"
                                "ปี 2: วงจรไฟฟ้า และการเขียนโปรแกรม (Circuits & Computing)เรียนวิชาแกนอย่าง Electric Circuits Analysis, Electronic Engineering, สถิติวิศวกรรม และที่สำคัญคือเริ่มเรียน Computer Programming for Engineers เพื่อใช้ในการคำนวณและควบคุมระบบ\n"
                                "ปี 3: ปีแห่งระบบอัจฉริยะ! (Smart Systems)เรียนเครื่องจักรกลไฟฟ้า (Electrical Machines), อิเล็กทรอนิกส์กำลัง, ระบบสื่อสาร และเข้าสู่หัวใจของหลักสูตรคือ Smart Grid Technology และการจัดการพลังงานยุคใหม่\n"
                                "ปี 4: การออกแบบระบบ และโครงงานนวัตกรรม (Advanced Integration)เรียนการออกแบบระบบไฟฟ้า (Electrical System Design), Distributed Generation (การผลิตไฟฟ้าแบบกระจายตัว), Electric Vehicles (EV) และทำโครงงานจบการศึกษา (Capstone Design Project) หรือเลือกออก สหกิจศึกษา ในบริษัทข้ามชาติ\n"+guide);
                        }
                    } 
                    else if (selectedMajor == "โยธา") {
                        if (selectedProgram == "ปกติ") {
                            reply("ปี 1: พื้นฐานคำนวณและวิทยาศาสตร์เรียน Calculus 1&2, Physics 1&2 (เน้นกลศาสตร์เป็นพิเศษ) และ Chemistry นอกจากนี้ยังมีวิชา Engineering Drawing ที่ต้องเป๊ะเรื่องลายเส้นและมิติสัมพันธ์\n"
                                "ปี 2: หัวใจของโยธา (Mechanics & Surveying)เริ่มเข้าวิชาภาคที่ดุเดือดอย่าง Statics (สถิตยศาสตร์), Mechanics of Solids (กลศาสตร์ของแข็ง), กลศาสตร์ของไหล และวิชาที่เป็นสัญลักษณ์ของโยธาอย่าง Surveying (การสำรวจ) ที่ต้องออกไปส่องกล้องทั่ว มช. ครับ\n"
                                "ปี 3: การออกแบบโครงสร้างและวัสดุ (Design Phase)เรียนการออกแบบอย่างจริงจัง ทั้ง RC Design (คอนกรีตเสริมเหล็ก), Steel Design (โครงสร้างเหล็ก), วิศวกรรมปฐพี (Soil Mechanics) เพื่อดูฐานราก และวิศวกรรมทางหลวง (Highway Engineering)\n"
                                "ปี 4: การบริหารงานก่อสร้างและ Senior Projectเน้นวิชาการจัดการ เช่น Construction Management, การประเมินราคา และทำโครงงานจบการศึกษา (Senior Project) หรือเลือกออก สหกิจศึกษา เพื่อไปลุยหน้างานจริงที่ไซด์งานก่อสร้าง\n"+guide);
                        } else if (selectedProgram == "นานาชาติ") {
                            reply("ปี 1: พื้นฐานวิศวกรรมสากล (Global Foundation)เรียน Calculus, Physics, Chemistry (ภาษาอังกฤษ) และวิชาพื้นฐานวิศวกรรม โดยเน้นการปรับตัวเข้าสู่การเรียนระบบนานาชาติ\n"
                                "ปี 2: กลศาสตร์และการสำรวจ (Mechanics & Surveying)เรียนวิชาแกนอย่าง Statics, Strength of Materials, Fluid Mechanics และวิชาที่เด็กโยธาต้องผ่านคือ Surveying (การสำรวจ) ซึ่งใช้ตำราและศัพท์เทคนิคภาษาอังกฤษทั้งหมด\n"
                                "ปี 3: การออกแบบโครงสร้างและเทคโนโลยี (Design & Innovation)เรียนการออกแบบคอนกรีตเสริมเหล็ก (RC Design), โครงสร้างเหล็ก และเริ่มนำเทคโนโลยีอย่าง BIM (Building Information Modeling) มาใช้ในการออกแบบและจำลองโครงสร้าง 3 มิติ\n"
                                "ปี 4: การจัดการโครงการและวิชาเลือกเฉพาะทางเรียนการบริหารงานก่อสร้าง (Construction Management), วิศวกรรมระบบราง (Railway Engineering) หรือการจัดการภัยพิบัติ และทำโครงงานจบการศึกษา (Senior Project) เป็นภาษาอังกฤษ\n"+guide);
                        } else {
                            reply("ไม่มีสาขานี้ในภาคที่คุณเลือกครับ");
                        }
                    } 
                    else if (selectedMajor == "สิ่งแวดล้อม") {                    
                        if (selectedProgram == "ปกติ") {
                            reply("ปี 1: พื้นฐานวิศวกรรมทั่วไป และวิชาเคมีสำหรับวิศวกร เรียนวิชาพื้นฐานคณะเหมือนสาขาอื่น (Calculus, Physics) แต่จะเน้น Chemistry for Engineers และแล็บเคมีเป็นพิเศษ เพื่อปูพื้นฐานการวิเคราะห์สารปนเปื้อนในสิ่งแวดล้อม\n"
                                "ปี 2: เคมีน้ำและน้ำเสีย, ชีววิทยาสิ่งแวดล้อม และกลศาสตร์ เริ่มเข้าวิชาภาคอย่าง Environmental Chemistry (เคมีน้ำ), จุลชีววิทยาสิ่งแวดล้อม, สถิติวิศวกรรม และวิชาพื้นฐานอย่าง Statics และกลศาสตร์ของไหล (Fluid Mechanics)\n"
                                "ปี 3: ปีแห่งการบำบัด! เรียนวิศวกรรมน้ำเสีย, ประปา และมลพิษอากาศ เน้นการคำนวณและออกแบบระบบ ได้แก่ Wastewater Engineering (น้ำเสีย), Water Supply (ประปา), อุทกวิทยา, และวิชาอากาศ (Air Pollution and Meteorology)\n"
                                "ปี 4: การจัดการขยะ, การออกแบบโรงงาน และ Senior Project เรียนวิชาประยุกต์อย่าง Solid Waste Management (จัดการขยะมูลฝอย), การจัดการของเสียอันตราย, การประเมินผลกระทบสิ่งแวดล้อม (EIA) และทำโครงงานจบการศึกษา (Senior Project)\n"+guide);
                        } else {
                            reply("ไม่มีสาขานี้ในภาคที่คุณเลือกครับ");
                        }
                    } 
                    else if (selectedMajor == "REAI") {                    
                        if (selectedProgram == "ปกติ") {
                            reply("ปี 1: พื้นฐานวิศวกรรม และการเขียนโปรแกรมหุ่นยนต์เรียน Calculus, Physics และวิชาหัวใจคือ Computer Programming for Automation and Robotics พร้อมเริ่มทำโครงงานหุ่นยนต์ตัวแรกในวิชา Robotics Engineering Project 1\n"
                                "ปี 2: กลศาสตร์, ระบบดิจิทัล และพลศาสตร์ (Dynamics)เรียนวิชาแกนอย่าง Statics, Mechanics of Solids, Electronics for Robotics และสถิติวิศวกรรม พร้อมลุยโครงงานต่อเนื่องใน Robotics Engineering Project 2\n"
                                "ปี 3: ปีแห่งปัญญาประดิษฐ์ และการควบคุม (AI & Control)เรียนวิชา Artificial Intelligence for Robotics, Feedback Control Systems, Microprocessors และการจำลองระบบอัตโนมัติด้วยคอมพิวเตอร์ (Simulation)\n"
                                "ปี 4: ระบบหุ่นยนต์อิสระ และ Senior Projectเรียน Autonomous Robotic System, ทักษะการเป็นผู้ประกอบการ และทุ่มเทเวลาให้กับ Senior Project (โครงงานวิศวกรรมหุ่นยนต์ 3 และ 4) เพื่อสร้างนวัตกรรมที่ใช้งานได้จริง\n"+guide);
                        } else {
                            reply("ไม่มีสาขานี้ในภาคที่คุณเลือกครับ");
                        }
                    } 
                    else if (selectedMajor == "เหมืองแร่") {                    
                        if (selectedProgram == "ปกติ") {
                            reply("ปี 1: พื้นฐานวิศวกรรมทั่วไป และวิชาเคมีสำหรับวิศวกรเรียนเหมือนภาคปกติสาขาอื่น (Calculus, Physics, Drawing) แต่จะเริ่มมีการปูพื้นฐานด้านวัสดุศาสตร์เบื้องต้น\n"
                                "ปี 2: ธรณีวิศวกรรม (Engineering Geology), กลศาสตร์ และการรังวัด (Surveying)เน้นการดูหินและแร่, การสำรวจรังวัดแผนที่ดิน, กลศาสตร์ของแข็ง และสถิติพื้นฐานเพื่อการวิเคราะห์ทางธรณีวิทยา\n"
                                "ปี 3: ปีแห่งการขุดและสกัด! เรียนการทำเหมือง (Mining Methods), การแต่งแร่ (Mineral Processing), กลศาสตร์หิน (Rock Mechanics)เน้นวิชาเฉพาะทางอย่างการออกแบบเหมืองผิวดิน/ใต้ดิน, การใช้วัตถุระเบิดในงานวิศวกรรม และเศรษฐศาสตร์แร่\n"
                                "ปี 4: วิศวกรรมสิ่งแวดล้อมเหมืองแร่, การออกแบบโรงแต่งแร่ และ Senior Project เน้นการฟื้นฟูพื้นที่เหมืองแร่, ความปลอดภัยในงานเหมือง, การจัดการสิ่งแวดล้อม และโครงงานจบการศึกษาที่เน้นการแก้ปัญหาจริงในอุตสาหกรรมแร่ธาตุหรือก่อสร้าง\n"+guide);
                        } else {
                            reply("ไม่มีสาขานี้ในภาคที่คุณเลือกครับ");
                        }
                    } 
                    else if (selectedMajor == "อุตสาหการ") {                    
                        if (selectedProgram == "ปกติ") {
                            reply("ปี 1: พื้นฐานวิศวกรรมทั่วไป และวิชาเคมีสำหรับวิศวกร (เน้นหนักที่ Calculus 1&2, Physics 1&2 และ Drawing เพื่อปูพื้นฐานการคำนวณ)\n"
                                "ปี 2: สถิติวิศวกรรม (Engineering Stat), กรรมวิธีการผลิต และกลศาสตร์ (เริ่มเข้าวิชาภาคอย่าง Material, Statics และ Strength of Materials เพื่อเข้าใจพื้นฐานโรงงาน)\n"
                                "ปี 3: ปีแห่งการวางแผน! เรียน Operations Research (OR), คุมคุณภาพ (QC), เศรษฐศาสตร์วิศวกรรม (เน้นการคำนวณเพื่อเพิ่มประสิทธิภาพการผลิตและการศึกษางาน หรือ Work Study)\n"
                                "ปี 4: การจัดการโลจิสติกส์, การออกแบบโรงงาน และ Senior Project (เน้นการนำความรู้มาออกแบบผังโรงงานจริง ความปลอดภัย และทำโครงงานวิศวกรรมจบการศึกษา)\n"+guide);
                        } else if (selectedProgram == "พิเศษ") {
                            reply("ปี 1: วางรากฐานวิศวกร เรียนวิชาพื้นฐานคำนวณและวิทยาศาสตร์ (Calculus, Physics, Chemistry), การเขียนแบบวิศวกรรม (Engineering Drawing) และการเขียนโปรแกรมเบื้องต้น\n"
                                "ปี 2: เจาะลึกกลศาสตร์และพื้นฐาน IE เรียนสถิติวิศวกรรม (Engineering Stat), กลศาสตร์ (Statics), ความแข็งแรงของวัสดุ (Strength of Materials), วัสดุวิศวกรรม และกรรมวิธีการผลิต (Manufacturing)\n"
                                "ปี 3: ปีแห่งการวิเคราะห์และการเพิ่มประสิทธิภาพ (Optimization) เรียนการวิจัยดำเนินงาน (OR), การศึกษางาน (Work Study), การควบคุมคุณภาพ (QC), เศรษฐศาสตร์วิศวกรรม และการวางแผนควบคุมการผลิต\n"
                                "ปี 4: บูรณาการการจัดการและโครงงานจบการศึกษา เรียนการจัดการโลจิสติกส์และโซ่อุปทาน, การออกแบบผังโรงงาน (Plant Design), วิศวกรรมความปลอดภัย และทำโครงงานวิศวกรรม (Senior Project)\n"+guide);
                        } else if (selectedProgram == "นานาชาติ") {
                            reply("ปี 1: พื้นฐานวิศวกรรมสากล และการโปรแกรมเน้น Calculus, Physics (ภาษาอังกฤษทั้งหมด) และที่ต่างคือเริ่มเรียน Computer Programming อย่างเข้มข้นตั้งแต่ปี 1 เพื่อปูพื้นฐานด้านระบบสารสนเทศ\n"
                                "ปี 2: สถิติวิศวกรรม (Engineering Stat), พื้นฐานไอที และเศรษฐศาสตร์เรียนสถิติขั้นสูง, ระบบฐานข้อมูล (Database), และวิชาด้านการจัดการเบื้องต้น เพื่อเตรียมพร้อมสำหรับการวิเคราะห์ข้อมูลขนาดใหญ่ (Big Data)\n"
                                "ปี 3: ปีแห่งการเพิ่มประสิทธิภาพ (Optimization) และโลจิสติกส์!เรียนวิจัยดำเนินงาน (OR), การจัดการโซ่อุปทาน (Supply Chain), การจำลองสถานการณ์ด้วยคอมพิวเตอร์ (Simulation) และการควบคุมคุณภาพ (QC)\n"
                                "ปี 4: การจัดการโลจิสติกส์ขั้นสูง, โครงงานนวัตกรรม และ Senior Project เน้นการออกแบบระบบโลจิสติกส์อัจฉริยะ, การจัดการการดำเนินงานสากล และทำโครงงานจบการศึกษาที่เน้นการแก้ปัญหาด้วยเทคโนโลยีสมัยใหม่\n"+guide);
                        }
                    }
                    else if (selectedMajor == "ISNE" && selectedProgram == "นานาชาติ") {
                        reply("ปี 1: พื้นฐานวิศวกรรมและโปรแกรมมิ่ง (Foundation & Programming) เน้นวิชา Programming (C++/Python), Calculus และ Physics เป็นภาษาอังกฤษทั้งหมด\n"
                              "ปี 2: โครงสร้างข้อมูลและเครือข่ายเบื้องต้น เรียน Data Structures, Database Systems และ Computer Networks เพื่อเข้าใจสถาปัตยกรรมของระบบสารสนเทศ\n"
                              "ปี 3: ความมั่นคงปลอดภัยและระบบขั้นสูง (Security & Advanced Systems) เข้าสู่วิชาแกนอย่าง Cybersecurity, Cloud Computing และ Software Engineering\n"
                              "ปี 4: โครงงานและสหกิจศึกษา ทำ Senior Project เพื่อแก้ปัญหาทาง IT และมีโอกาสฝึกงาน (Co-op) กับบริษัทเทคโนโลยีชั้นนำทั้งในและต่างประเทศ\n"+guide);
                    }
                    // หากผู้ใช้พิมพ์มาแล้วอยากเลือกสาขาอื่นต่อ
                    reply("\nหากต้องการดูสาขาอื่น พิมพ์ 'เปลี่ยนสาขา' หรือพิมพ์ 'ออก' เพื่อกลับเมนูหลักครับ");
                } 
                else if (hasKeyword(input, "เปลี่ยนสาขา")) {
                    currentState = FRESH_STATE_SELECT_MAJOR;
                    reply("กลับมาหน้าเลือกสาขาแล้วครับ กรุณาพิมพ์ชื่อสาขาที่สนใจได้เลยครับ");
                }
                else {
                    reply("ลองพิมพ์คำว่า 'เรียนอะไร' ดูนะครับ เพื่อดูรายละเอียดหลักสูตร\n(หรือพิมพ์ 'เปลี่ยนสาขา' / 'ออก')");
                }
                break;

                // Maps
                case FRESH_STATE_Building:

                    if (hasKeyword(input, "อาคารเรียน") || hasKeyword(input, "อาคาร") || hasKeyword(input, "ตึก")) {
                        selectedBuilding = "อาคารเรียน";
                        reply("อาคารเรียนหลักของคณะวิศวกรรมศาสตร์ มช. คือ ตึก30ปี ซึ่งเป็นอาคารเรียนที่ทันสมัยและมีสิ่งอำนวยความสะดวกครบครัน นอกจากนี้ยังมีอาคารวิจัยและห้องปฏิบัติการต่างๆ ที่สนับสนุนการเรียนการสอนและงานวิจัยของคณะครับ");
                        reply("นอกจากนี้ยังมีอาคารเรียนอื่นๆ เช่น อาคารวิศวกรรมโยธา, อาคารวิศวกรรมไฟฟ้า, และอาคารวิศวกรรมเครื่องกล ซึ่งแต่ละอาคารจะมีห้องเรียนและห้องปฏิบัติการที่เหมาะสมกับสาขาวิชาต่างๆ ของคณะครับ");
                        reply("นี่เป็นแผนที่สำหรับน้องๆปี1 ที่จะได้ใช้บ่อยๆครับ: https://cmu.to/maps");
                    currentState = FRESH_STATE_Building;
                }
                
                break;
                
                // Accessories
                case FRESH_STATE_ACCESSORIES:
                
                    if (hasKeyword(input, "อุปกรณ์") || hasKeyword(input, "ของใช้") || hasKeyword(input, "เครื่องมือ")|| hasKeyword(input, "ของ")) {
                        selectedAccessories = "อุปกรณ์";
                        reply("อุปกรณ์ที่จำเป็นสำหรับนักศึกษาวิศวกรรมศาสตร์ มช. มีหลายอย่างครับ ขึ้นอยู่กับสาขาวิชาและวิชาที่เรียน แต่โดยทั่วไปแล้วจะมีอุปกรณ์พื้นฐานดังนี้ครับ:");
                        reply("1. ไม้ธี หรือไม้บรรทัด: ใช้ในการเขียนแบบและการวาดภาพวิศวกรรม\n2. เครื่องคิดเลขวิศวกรรม: เช่น Casio fx-991ES Plus");

                    if (hasKeyword(input, "ไม้ธี") || hasKeyword(input, "ไม้บรรทัด")) {
                        reply("ไม้ธี หรือไม้บรรทัด เป็นอุปกรณ์ที่นักศึกษาวิศวกรรมศาสตร์ มช. ใช้ในการเขียนแบบและการวาดภาพวิศวกรรม โดยเฉพาะในวิชาที่ต้องใช้การเขียนแบบด้วยมือ เช่น Engineering Drawing ครับ ");
                        reply("สามารถหาซื้อได้เองหรือมีการสั่งซื้อพร้อมกับอุปกรณ์อื่นๆ ในช่วงเปิดเทอมครับ(ทางสโมสรรนักศึกษามักจะมีการจัดชุดอุปกรณ์สำหรับนักศึกษาใหม่ที่รวมไม้ธีไว้ด้วยครับ)");
                    }
                    else if (hasKeyword(input, "เครื่องคิดเลข") || hasKeyword(input, "แลป")) {
                        reply("เครื่องคิดเลขที่นิยมใช้ในคณะวิศวกรรมศาสตร์ มช. คือเครื่องคิดเลขวิศวกรรม เช่น Casio fx-991ES Plus ซึ่งมีฟังก์ชันที่จำเป็นสำหรับการคำนวณทางวิศวกรรม เช่น การคำนวณเมทริกซ์, การคำนวณเชิงสถิติ และการคำนวณทางวิทยาศาสตร์ครับ");
                        reply("สามารถหาซื้อได้เองหรือมีการสั่งซื้อพร้อมกับอุปกรณ์อื่นๆ ในช่วงเปิดเทอมครับ(ทางสโมสรรนักศึกษามักจะมีการจัดชุดอุปกรณ์สำหรับนักศึกษาใหม่ที่รวมเครื่องคิดเลขไว้ด้วยครับ)");
                        currentState = FRESH_STATE_ACCESSORIES;
                    }                   
                }
                break;

                case FRESH_STATE_DORMITORY:

                if(hasKeyword(input, "หอพัก")){
                    reply("ต้องการสอบถามเรื่องใดเกี่ยวกับหอพักครับ?")
                    currentState = FRESH_STATE_DORMITORY;
                    
                    if(hasKeyword(input, "จำนวนหอพัก") || hasKeyword(input, "มีกี่หอ")){
                        reply("โดยปกติจะแบ่งเป็น หอพักในกำกับ (หอธรรมดา) และ หอพักในกำกับเชิงพาณิชย์ (หอปรับปรุง/หอสีชมพู) โดยมีรายละเอียดดังนี้ครับ\n");
                        reply("หอพักนักศึกษาชาย (รวม 8 อาคาร) โดยจะมี\n");
                        reply("หอพักในกำกับ (หอธรรมดา): มี 7 อาคาร คือ หอ 1 ชาย ถึง หอ 7 ชาย\n");
                        reply("หอพักในกำกับเชิงพาณิชย์: มี 1 อาคาร คือ หอพักนักศึกษาชายอาคาร 40 ปี (หรือที่เรียกกันว่า หอสีชมพูฝั่งชาย)\n");
                        reply("หอพักนักศึกษาหญิง (รวม 11 อาคาร) โดยจะมี\n")
                        reply("หอพักในกำกับ (หอธรรมดา/ปรับปรุง): มี 10 อาคาร คือ หอ 1 หญิง ถึง หอ 10 หญิง \n****บางหอในกลุ่มนี้ เช่น หอ 4, 6, 7 และ 8 หญิง ได้รับการปรับปรุงเป็นหอพักแบบพรีเมียม (ห้องน้ำในตัว/กึ่งส่วนตัว) ซึ่งค่าเทอมจะสูงกว่าหอธรรมดา\n");
                        reply("หอพักในกำกับเชิงพาณิชย์: มี 1 อาคาร คือ หอพักนักศึกษาหญิงอาคาร 40 ปี (หอสีชมพูฝั่งหญิง ซึ่งเป็นหอยอดฮิต)\n");

                    }else if(hasKeyword(input, "ข้อมูล")){
                        reply("ช่องทางติดต่อ, ราคา, ค่าน้ำ-ค่าไฟ, วิธีจองหอพัก, จำนวนหอพัก");

                    }else if(hasKeyword(input, "ราคา") || hasKeyword(input, "ค่าใช้จ่ายหอ")){
                        reply("หอพักในกำกับ (หอธรรมดา) เป็นหอพักดั้งเดิม (หอ 1-7 ชาย และ หอ 1-3, 5, 8-9 หญิง บางหออาจมีการปรับปรุง)\n");
                        reply("เทอมแรก (แรกเข้า): ประมาณ 2,400 บาท\n");
                        reply("เทอมถัดไป: ประมาณ 2,200 บาท\n");
                        reply("ลักษณะ: พัดลม, ห้องน้ำรวม (หารกันจ่ายถูกมาก เฉลี่ยเดือนละไม่กี่ร้อยบาท)\n");
                        reply("หอพักปรับปรุง (พรีเมียม)เช่น หอหญิง 4, 6, 7 และบางอาคารที่รีโนเวทใหม่\n");
                        reply("เทอมแรก (แรกเข้า): ประมาณ 10,850 บาท\n");
                        reply("เทอมถัดไป: ประมาณ 8,750 บาท\n");
                        reply("ลักษณะ: ห้องน้ำในตัวหรือกึ่งส่วนตัว, เฟอร์นิเจอร์ครบชุด, สภาพห้องใหม่กว่า\n");
                        reply("หอพักอาคาร 40 ปี (หอสีชมพู) หอยอดฮิตที่อยู่ใกล้ตลาดฝายหิน\n");
                        reply("แรกเข้า (รวมค่าประกัน): ประมาณ 10,100 - 10,850 บาท\n");
                        reply("เทอมถัดไป: ประมาณ 9,000 บาท\n");
                        reply("ลักษณะ: มีทั้งแบบพัก 2 คน หรือเหมาห้อง, มีระเบียง, ใกล้แหล่งของกิน\n");
                        
                    }else if(hasKeyword(input, "ค่าน้ำ") || hasKeyword(input, "ค่าไฟ")){
                        reply("หอธรรมดา: มักรวมอยู่ในค่าเทอมแล้ว (ยกเว้นเครื่องใช้ไฟฟ้าพิเศษ)\n");
                        reply("หอปรับปรุง/หอ 40 ปี: จ่ายตามมิเตอร์จริง (ค่าไฟหน่วยละประมาณ 6 บาท, ค่าน้ำเหมาจ่ายหรือตามหน่วย) ต้องจ่ายทุกเดือนภายในวันที่ 5\n");
                        reply("ค่าธรรมเนียมเครื่องใช้ไฟฟ้า: หากนำเครื่องใช้ไฟฟ้ามาเอง (เช่น ตู้เย็น, หม้อหุงข้าว) ต้องลงทะเบียนจ่ายเพิ่มประมาณ 100 - 300 บาท ต่อเทอม\n");
                        reply("ค่าประกันของเสียหาย: จ่ายครั้งแรกที่เข้าพัก (ประมาณ 500 - 2,000 บาท ขึ้นอยู่กับประเภทหอ) และจะได้คืนเมื่อย้ายออกหากห้องไม่เสียหาย\n");

                    }else if(hasKeyword(input, "จองหอ") || hasKeyword(input, "วิธีจองหอ")){
                        reply("ขั้นตอนการจอง (ระบบออนไลน์) คุณต้องทำตามลำดับขั้นตอนผ่านเว็บไซต์ 'udo.oop.cmu.ac.th' หรือ 'reg.cmu.ac.th'\n");
                        reply("1.สร้างบัญชีผู้ใช้งาน (ครั้งแรก): ใช้นักศึกษาใหม่ (ปี 1) ต้องเข้าไปลงทะเบียนสร้างบัญชีโดยใช้ เลขประจำตัวประชาชน และ วันเดือนปีเกิด \n****สำคัญ: ต้องระบุเพศให้ถูกต้อง เพราะระบบจะล็อกหอพักตามเพศไว้ครับ\n");
                        reply("2.ล็อกอินเข้าระบบจอง: เมื่อถึงวันและเวลาที่ประกาศเปิดจอง (มักจะเป็นช่วงหลังประกาศผล TCAS ในแต่ละรอบ) ให้รีบล็อกอินเข้าสู่ระบบ\n");
                        reply("3.ระบบจะแสดงรายชื่อหอพักที่ยังว่างอยู่ คุณสามารถเลือกเลขห้องและเลขเตียงที่ต้องการได้ทันที \n****ตรงนี้หอปรับปรุงและหอ 40 ปี จะเต็มเร็วมากภายในไม่กี่นาที แนะนำให้เล็งห้องในใจไว้ก่อนครับ \n");
                        reply("4.ยืนยันการจองและพิมพ์ใบชำระเงิน: เมื่อจองสำเร็จ ระบบจะให้พิมพ์ใบแจ้งหนี้เพื่อไปชำระเงินที่ธนาคารหรือผ่านแอปฯ ธนาคารตามที่กำหนด\n");

                    }else if(hasKeyword(input, "ช่องทางติดต่อ") || hasKeyword(input, "เว็บหอ")){
                        reply("เว็บไซต์จองหอพัก (ระบบหลัก) 'https://udo.oop.cmu.ac.th' (สำนักงานหอพักนักศึกษา มหาวิทยาลัยเชียงใหม่)");
                        reply("ช่องทางประกาศข่าวสาร (สำคัญมาก) 'Facebook: สำนักงานหอพักนักศึกษา มหาวิทยาลัยเชียงใหม่'")
                    }
                }else{
                    reply("ลองพิมพ์คำว่า 'ข้อมูล' ดูนะครับ เพื่อดูรายละเอียดต่างๆ ที่มีปัจจุบันครับ\n(หรือพิมพ์ 'ออก' เพื่อกลับหน้าแรก)")
                }
                break;

                case FRESH_STATE_CLOTHES:

                    if(hasKeyword(input, "ชุด") || hasKeyword(input, "เครื่องแต่งกาย")){
                        reply("การแต่งกายจะมีดังนี้ครับ\n");
                        reply("ชุดนักศึกษาถูกระเบียบ (ชุดพิธีการ): ใช้สำหรับงานพิธีการสำคัญ เช่น วันปฐมนิเทศ, วันไหว้ครู, และวันสอบ\n");
                        reply("นักศึกษาชาย\nเสื้อ: เชิ้ตแขนยาวสีขาว ผูกเนคไทสีม่วง (มีตรามหาวิทยาลัย)\nกางเกง: กางเกงสแล็คขายาว สีสุภาพ (ดำ/กรมท่า)\nเข็มขัด: สายหนังสีดำ หัวเข็มขัดตรามหาวิทยาลัย\nรองเท้า: รองเท้าคัทชูสีดำ ถุงเท้าสีดำ\n");
                        reply("นักศึกษาหญิง\nเสื้อ: เสื้อเชิ้ตสีขาว แขนสั้น ติดกระดุมโลหะตรามหาวิทยาลัย และเข็มวิทยฐานะที่อกซ้าย\nกระโปรง: กระโปรงทรงสอบ (สีดำ/กรมท่า) ความยาวคลุมเข่า\nเข็มขัด: สายเข็มขัดหนังสีดำ/น้ำตาล หัวเข็มขัดตรามหาวิทยาลัย\nรองเท้า: รองเท้าคัทชูสีดำปิดหัวปิดส้น\n");
                        reply("ชุดนักศึกษาทั่วไป (ชุดเรียนปกติ) มช. ค่อนข้างให้อิสระในการแต่งกายแบบสุภาพ โดย \nนักศึกษาชาย: เสื้อเชิ้ตขาวแขนสั้น/ยาว กางเกงสแล็คหรือยีนส์สีเข้ม (ขึ้นอยู่กับระเบียบของแต่ละคณะ)\nนักศึกษาหญิง: เสื้อนักศึกษาขาว กระโปรงพลีท (จีบรอบ) สีเข้ม หรือกระโปรงทรงสอบ รองเท้าผ้าใบสีสุภาพ\n");
                    }else if(hasKeyword(input, "เข็มกลัด") || hasKeyword(input, "กระดุม") || hasKeyword(input, "เนคไท") || hasKeyword(input, "หัวเข็มขัด") || hasKeyword(input, "ตุ้งติ้ง") || hasKeyword(input, "อุปกรณ์")){
                        reply("สามารถหาซื้อได้ที่สหกรณ์มหาวิทยาลัยเชียงใหม่ ตั้งอยู่บริเวณลานจอดรถหอหญิง 2 และสาขาฝั่งหน้า มช. เป็นแหล่งรวมเครื่องหมายที่ถูกต้องตามระเบียบที่สุด หรือ ร้านค้าหน้ามช. มีร้านขายชุดนักศึกษาให้เลือกหลายร้าน ซึ่งมักจะมีทรงเสื้อและเนื้อผ้าที่หลากหลายกว่า\n");
                    }
                break;
        }
        return true;
    }

};
