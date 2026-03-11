#pragma once
#include <iostream>
#include <string>
#include <vector>

// สถานะย่อยสำหรับระบบ Admission เท่านั้น
enum AdmissionState {
    ADM_STATE_SELECT_PROGRAM,      // เลือกหลักสูตร
    ADM_STATE_SELECT_MAJOR,        // เลือกสาขา
    ADM_STATE_SELECT_ROUND,        // เลือกรอบ
    ADM_STATE_SELECT_PROJECT,      // เลือกโครงการ
    ADM_STATE_PROJECT_DETAILS,     // ถามรายละเอียด
    ADM_STATE_SELECT_MAJOR_SPECIAL, // เลือกสาขาในภาคพิเศษ 
    ADM_STATE_SELECT_ROUND_SPECIAL, // เลือกรอบในภาคพิเศษ
    ADM_STATE_SELECT_PROJECT_SPECIAL, // เลือกโครงการในภาคพิเศษ
    ADM_STATE_PROJECT_DETAILS_SPECIAL, // ถามรายละเอียดในภาคพิเศษ
    ADM_STATE_SELECT_MAJOR_INTL, // เลือกสาขาในภาคนานาชาติ
    ADM_STATE_SELECT_ROUND_INTL, // เลือกรอบในภาคนานาชาติ
    ADM_STATE_SELECT_PROJECT_INTL, // เลือกโครงการในภาคนานาชาติ
    ADM_STATE_PROJECT_DETAILS_INTL // ถามรายละเอียดในภาคนานาชาติ
};

class AdmissionHandler {
public:
    AdmissionState currentState = ADM_STATE_SELECT_PROGRAM;
    std::string selectedMajor = "";
    std::string selectedRound = "";
    std::string selectedProject = "";

    bool hasKeyword(std::string input, std::string keyword) {
        return input.find(keyword) != std::string::npos;
    }

    // ฟังก์ชันนี้จะรับข้อความและ "ประวัติแชทหลัก" เข้ามา เพื่อพิมพ์ตอบกลับไปที่หน้าจอโดยตรง
    // คืนค่า true = ทำงานต่อ, คืนค่า false = ผู้ใช้พิมพ์ "ออก" (ให้ main.cpp ดึงกลับเมนูหลัก)
    bool processAdmission(std::string input, std::vector<std::string>& chatHistory) {
        
        // ฟังก์ชันช่วยพิมพ์ตอบกลับ
        auto reply = [&](std::string text) {
            chatHistory.push_back("Chatbot: " + text);
        };

        // ถ้าพิมพ์ "ออก" ให้คืนค่า false เพื่อส่งสัญญาณกลับไปให้ ChatbotLogic หลัก
        if (hasKeyword(input, "ออก") || hasKeyword(input, "กลับ") || hasKeyword(input, "เมนูหลัก")) {
            currentState = ADM_STATE_SELECT_PROGRAM; // รีเซ็ตสถานะเผื่อเข้ามาใหม่
            selectedMajor = ""; selectedRound = ""; selectedProject = "";
            return false; 
        }

        switch (currentState) {
            case ADM_STATE_SELECT_PROGRAM:
                if (hasKeyword(input, "ปกติ") || hasKeyword(input, "ภาคปกติ")) {
                    reply("สนใจเข้าวิศวกรรมสาขาไหนครับ? (เช่น โยธา, ไฟฟ้า, เครื่องกล)");
                    currentState = ADM_STATE_SELECT_MAJOR;
                }
                else if (hasKeyword(input, "พิเศษ") || hasKeyword(input, "ภาคพิเศษ")) {
                    reply("ภาคพิเศษในปีนี้เปิดรับสมัครเฉพาะสาขาอุตสาหการครับ สนใจสมัครวิศวกรรมอุตสาหการภาคพิเศษไหมครับ? ");
                    currentState = ADM_STATE_SELECT_MAJOR_SPECIAL;
                }
                else if (hasKeyword(input, "นานาชาติ") || hasKeyword(input, "ภาคนานาชาติ")) {
                    reply("สนใจเข้าวิศวกรรมสาขาไหนครับ? (เช่น โยธา, ไซเบอร์, อุตสาหการ)");
                    currentState = ADM_STATE_SELECT_MAJOR_INTL; 
                }
                else {
                    reply("คณะเรามี 3 หลักสูตร: 1. ภาคปกติ 2. ภาคพิเศษ 3. นานาชาติ\nลองพิมพ์ชื่อหลักสูตรที่สนใจดูครับ หรือพิมพ์ 'ออก' เพื่อกลับเมนูหลัก");
                }
                break;
            
// ============================================================================================================================== //

                                                 // โซนโปรเจกต์ของสาขาต่างๆ ภาคปกติ
            case ADM_STATE_SELECT_MAJOR:
                if (hasKeyword(input, "โยธา") || hasKeyword(input, "Civil")|| hasKeyword(input, "CE")) {
                    selectedMajor = "โยธา";
                    reply("อยากสมัครวิศวกรรมโยธาในรอบไหนครับ?\n1. Portfolio\n2. Quota\n3. Admission\n4. Direct Admission");
                    currentState = ADM_STATE_SELECT_ROUND;
                }
                else if (hasKeyword(input, "ไฟฟ้า") || hasKeyword(input, "Electric")|| hasKeyword(input, "EE")) {
                    selectedMajor = "ไฟฟ้า";
                    reply("อยากสมัครวิศวกรรมไฟฟ้าในรอบไหนครับ?\n1. Portfolio\n2. Quota\n3. Admission\n4. Direct Admission");
                    currentState = ADM_STATE_SELECT_ROUND;
                }
                else if (hasKeyword(input, "เครื่องกล") || hasKeyword(input, "Mechanical")|| hasKeyword(input, "ME")) {
                    selectedMajor = "เครื่องกล";
                    reply("อยากสมัครวิศวกรรมเครื่องกลในรอบไหนครับ?\n1. Portfolio\n2. Quota\n3. Admission\n4. Direct Admission");
                    currentState = ADM_STATE_SELECT_ROUND;
                }
                else if (hasKeyword(input, "อุตสาหการ") || hasKeyword(input, "Industrial") || hasKeyword(input, "IE")) {
                    selectedMajor = "อุตสาหการ";
                    reply("อยากสมัครวิศวกรรมอุตสาหการในรอบไหนครับ?\n1. Portfolio\n2. Quota\n3. Admission\n4. Direct Admission");
                    currentState = ADM_STATE_SELECT_ROUND;
                }
                else if (hasKeyword(input, "คอมพิวเตอร์") || hasKeyword(input, "Computer") || hasKeyword(input, "CPE")) {
                    selectedMajor = "คอมพิวเตอร์";
                    reply("อยากสมัครวิศวกรรมคอมพิวเตอร์ในรอบไหนครับ?\n1. Portfolio\n2. Quota\n3. Admission\n4. Direct Admission");
                    currentState = ADM_STATE_SELECT_ROUND;
                }
                else if (hasKeyword(input, "สิ่งเเวดล้อม") || hasKeyword(input, "Environmental") || hasKeyword(input, "Env")|| hasKeyword(input, "ENV")) {
                    selectedMajor = "สิ่งเเวดล้อม";
                    reply("อยากสมัครวิศวกรรมสิ่งแวดล้อมในรอบไหนครับ?\n1. Portfolio\n2. Quota\n3. Admission\n4. Direct Admission");
                    currentState = ADM_STATE_SELECT_ROUND;
                }
                else if (hasKeyword(input, "เหมืองแร่และปิโตรเลียม") || hasKeyword(input, "Mining") || hasKeyword(input, "MnE")) {
                    selectedMajor = "เหมืองแร่และปิโตรเลียม";
                    reply("อยากสมัครวิศวกรรมเหมืองแร่และปิโตรเลียมในรอบไหนครับ?\n1. Portfolio\n2. Quota\n3. Admission\n4. Direct Admission");
                    currentState = ADM_STATE_SELECT_ROUND;
                }
                else if (hasKeyword(input, "หุ่นยนต์และปัญญาประดิษฐ์") || hasKeyword(input, "Robotics and AI") || hasKeyword(input, "RAI")) {
                    selectedMajor = "หุ่นยนต์และปัญญาประดิษฐ์";
                    reply("อยากสมัครวิศวกรรมหุ่นยนต์และปัญญาประดิษฐ์ในรอบไหนครับ?\n1. Portfolio\n2. Quota\n3. Admission\n4. Direct Admission");
                    currentState = ADM_STATE_SELECT_ROUND;
                }
                else if (hasKeyword(input, "บูรณาการ") || hasKeyword(input, "Interdisciplinary") || hasKeyword(input, "IGE")) {
                    selectedMajor = "บูรณาการ";
                    reply("อยากสมัครวิศวกรรมบูรณาการในรอบไหนครับ?\n1. Portfolio\n2. Quota\n3. Admission\n4. Direct Admission");
                    currentState = ADM_STATE_SELECT_ROUND;
                }
                else {
                    reply("ลองพิมพ์ชื่อสาขาใหม่ดูนะครับ (เช่น โยธา)");
                }
                break;

// ============================================================================================================================== //
            case ADM_STATE_SELECT_ROUND:
                if (hasKeyword(input, "1") || hasKeyword(input, "Portfolio")) {
                    selectedRound = "Portfolio";

                    if (selectedMajor == "โยธา")reply("รอบ Portfolio สาขาโยธามี 5 โครงการครับ:\n1. นักกีฬา\n2. วมว.\n3. ความสามารถพิเศษ\n4. ผลการเรียนดีเด่น\n5. ความสามารถทางวิศวกรรม\nอยากสมัครโครงการไหนครับ? ");
                    else if (selectedMajor == "ไฟฟ้า") reply("รอบ Portfolio สาขาไฟฟ้ามี 4 โครงการครับ:\n1. นักกีฬา\n2. ความสามารถพิเศษ\n3. ผลการเรียนดีเด่น\n4. ความสามารถทางวิศวกรรม\nอยากสมัครโครงการไหนครับ? ");
                    else if (selectedMajor == "เครื่องกล") reply("รอบ Portfolio สาขาเครื่องกลมี 5 โครงการครับ:\n1. นักกีฬา\n2. ความสามารถพิเศษ\n3. ผลการเรียนดีเด่น\n4. หุ่นยนต์และเทคโนโลยี\n5. ความสามารถทางวิศวกรรม\nอยากสมัครโครงการไหนครับ? ");
                    else if (selectedMajor == "อุตสาหการ") reply("รอบ Portfolio สาขาอุตสาหการมี 7 โครงการครับ:\n1. นักกีฬา\n2. ความสามารถพิเศษ\n3. หุ่นยนต์และเทคโนโลยี\n4. ผลการเรียนดีเด่น\n5. ผู้มีความสามารถทางภาษาอังกฤษ\n6. Women in Engineering\n7. ความสามารถทางวิศวกรรม\nอยากสมัครโครงการไหนครับ? ");
                    else if (selectedMajor == "คอมพิวเตอร์") reply("รอบ Portfolio สาขาคอมพิวเตอร์มี 5 โครงการครับ:\n1. นักกีฬา\n2. อัจฉริยภาพทางคอมพิวเตอร์\n3. ผลการเรียนดีเด่น\n4. ความสามารถทางวิศวกรรม\n5. ร่วมมือสร้างสังคมแห่งการเรียนรู้นวัตกรรมด้านพลังงานและสิ่งแวดล้อม\nอยากสมัครโครงการไหนครับ? ");
                    else if (selectedMajor == "สิ่งเเวดล้อม") reply("รอบ Portfolio สาขาสิ่งแวดล้อมมี 5 โครงการครับ:\n1. นักกีฬา\n2. ผลการเรียนดีเด่น \n3. ผลการเรียนวิชาฟิสิกส์และเคมีดีเด่น \n4. ความสามารถทางวิศวกรรม\n5. ร่วมมือสร้างสังคมแห่งการเรียนรู้นวัตกรรมด้านพลังงานและสิ่งแวดล้อม\nอยากสมัครโครงการไหนครับ? ");
                    else if (selectedMajor == "เหมืองแร่และปิโตรเลียม") reply("รอบ Portfolio สาขาเหมืองแร่และปิโตรเลียมมี 1 โครงการครับ:\n1. ความสามารถทางวิศวกรรม\nอยากสมัครโครงการไหนครับ? ");
                    else if (selectedMajor == "หุ่นยนต์และปัญญาประดิษฐ์") reply("รอบ Portfolio สาขาหุ่นยนต์และปัญญาประดิษฐ์มี 3 โครงการครับ:\n1. ผลการเรียนดีเด่น (สำหรับหลักสูตรแกนกลาง)\n2. ผลการเรียนดีเด่น (สำหรับหลักสูตรอาชีวศึกษา)\n3. ความสามารถทางวิศวกรรม\nอยากสมัครโครงการไหนครับ? ");
                    else if (selectedMajor == "บูรณาการ") reply("รอบ Portfolio สาขาบูรณาการมี 2 โครงการครับ:\n1. นักกีฬา \n2. ผลการเรียนดีเด่น\nอยากสมัครโครงการไหนครับ? ");

                    currentState = ADM_STATE_SELECT_PROJECT;
                }
                else if (hasKeyword(input, "2") || hasKeyword(input, "Quota")) {
                    selectedRound = "Quota";

                    if (selectedMajor == "โยธา") reply("รอบ Quota สาขาโยธามี 2 โครงการครับ:\n1. โควตาภาคเหนือ\n2. ผู้มีความสามารถด้านกีฬา\nอยากสมัครโครงการไหนครับ? ");
                    else if (selectedMajor == "ไฟฟ้า") reply("รอบ Quota สาขาไฟฟ้ามี 2 โครงการครับ:\n1. โควตาภาคเหนือ\n2. ผู้มีความสามารถด้านกีฬา\nอยากสมัครโครงการไหนครับ? ");
                    else if (selectedMajor == "เครื่องกล") reply("รอบ Quota สาขาเครื่องกลมี 2 โครงการครับ:\n1. โควตาภาคเหนือ\n2. ผู้มีความสามารถด้านกีฬา\nอยากสมัครโครงการไหนครับ? ");
                    else if (selectedMajor == "อุตสาหการ") reply("รอบ Quota สาขาอุตสาหการมี 2 โครงการครับ:\n1. โควตาภาคเหนือ\n2. ผู้มีความสามารถด้านกีฬา\nอยากสมัครโครงการไหนครับ? ");
                    else if (selectedMajor == "คอมพิวเตอร์") reply("รอบ Quota สาขาคอมพิวเตอร์มี 4 โครงการครับ:\n1. โควตาภาคเหนือ\n2. ผู้มีความสามารถด้านกีฬา\n3.  การรับนักเรียนพิการ\n4. ควตานอกเขต 17 จังหวัดภาคเหนือ\nอยากสมัครโครงการไหนครับ? ");
                    else if (selectedMajor == "สิ่งเเวดล้อม") reply("รอบ Quota สาขาสิ่งแวดล้อมมี 2 โครงการครับ:\n1. โควตาภาคเหนือ\n2. ผู้มีความสามารถด้านกีฬา\nอยากสมัครโครงการไหนครับ? ");
                    else if (selectedMajor == "เหมืองแร่และปิโตรเลียม") reply("รอบ Quota สาขาเหมืองแร่และปิโตรเลียมมี 1 โครงการครับ:\n1. โควตาภาคเหนือ\nอยากสมัครโครงการไหนครับ? ");
                    else if (selectedMajor == "หุ่นยนต์และปัญญาประดิษฐ์") reply("รอบ Quota สาขาหุ่นยนต์และปัญญาประดิษฐ์มี 1 โครงการครับ:\n1. โควตาภาคเหนือ\nอยากสมัครโครงการไหนครับ?");
                    else if (selectedMajor == "บูรณาการ") reply("รอบ Quota สาขาบูรณาการมี 1 โครงการครับ:\n1. โควตาภาคเหนือ\nอยากสมัครโครงการไหนครับ? ");

                    currentState = ADM_STATE_SELECT_PROJECT;
                }
                else if (hasKeyword(input, "3") || hasKeyword(input, "Admission") || hasKeyword(input, "admission")) {
                    selectedRound = "Admission";
                    if (selectedMajor == "โยธา") reply("รอบ Admission สาขาโยธามี 1 โครงการครับ:\n1. รับตรงร่วมกัน\nอยากสมัครโครงการหรือสนใจรายละเอียดโครงการไหนไหมครับ? ");
                    else if (selectedMajor == "ไฟฟ้า") reply("รอบ Admission สาขาไฟฟ้ามี 1 โครงการครับ:\n1. รับตรงร่วมกัน\nอยากสมัครโครงการหรือสนใจรายละเอียดโครงการไหนไหมครับ? ");
                    else if (selectedMajor == "เครื่องกล") reply("รอบ Admission สาขาเครื่องกลมี 1 โครงการครับ:\n1. รับตรงร่วมกัน\nอยากสมัครโครงการหรือสนใจรายละเอียดโครงการไหนไหมครับ? ");
                    else if (selectedMajor == "อุตสาหการ") reply("รอบ Admission สาขาอุตสาหการมี 1 โครงการครับ:\n1. รับตรงร่วมกัน\nอยากสมัครโครงการหรือสนใจรายละเอียดโครงการไหนไหมครับ? ");
                    else if (selectedMajor == "คอมพิวเตอร์") reply("รอบ Admission สาขาคอมพิวเตอร์มี 1 โครงการครับ:\n1. รับตรงร่วมกัน\nอยากสมัครโครงการหรือสนใจรายละเอียดโครงการไหนไหมครับ? ");
                    else if (selectedMajor == "สิ่งเเวดล้อม") reply("รอบ Admission สาขาสิ่งแวดล้อมมี 1 โครงการครับ:\n1. รับตรงร่วมกัน\nอยากสมัครโครงการหรือสนใจรายละเอียดโครงการไหนไหมครับ? ");
                    else if (selectedMajor == "เหมืองแร่และปิโตรเลียม") reply("รอบ Admission สาขาเหมืองแร่และปิโตรเลียมมี 1 โครงการครับ:\n1. รับตรงร่วมกัน\nอยากสมัครโครงการหรือสนใจรายละเอียดโครงการไหนไหมครับ? ");
                    else if (selectedMajor == "หุ่นยนต์และปัญญาประดิษฐ์") reply("รอบ Admission สาขาหุ่นยนต์และปัญญาประดิษฐ์มี 1 โครงการครับ:\n1. รับตรงร่วมกัน\nอยากสมัครโครงการหรือสนใจรายละเอียดโครงการไหนไหมครับ? ");
                    else if (selectedMajor == "บูรณาการ") reply("รอบ Admission สาขาบูรณาการมี 1 โครงการครับ:\n1. รับตรงร่วมกัน\nอยากสมัครโครงการหรือสนใจรายละเอียดโครงการไหนไหมครับ? ");

                    currentState = ADM_STATE_SELECT_PROJECT;
                }
                else if (hasKeyword(input, "4") || hasKeyword(input, "Direct") || hasKeyword(input, "direct")) {
                    reply("โปรดติดตามคณะสาขาที่เปิด และคุณสมบัติการรับ TCAS รอบที่ 4 ปีการศึกษา 2569 อีกครั้งในวันที่ 28 พฤษภาคม 2569 ครับ\nลองดูรอบอื่นเพิ่มเติมไหมครับ? (เช่น รอบ Portfolio, รอบ Quota, รอบ Admission) ");
                }
                else {
                    reply("สามารถพิมพ์ 'ออก' เพื่อกลับเมนูหลักครับ");
                }
                break;

// ============================================================================================================================== //
            case ADM_STATE_SELECT_PROJECT:
                // เช็คโปรเจกต์ตามรอบที่เลือกไว้
                if (selectedRound == "Portfolio") {
                    // --- โซนสาขา โยธา ---
                    if (selectedMajor == "โยธา") {
                        if (hasKeyword(input, "1") || hasKeyword(input, "นักกีฬา") || hasKeyword(input, "โดดเด่นระดับชาติ")) {
                            selectedProject = "นักกีฬา_Port";
                            reply("โครงการนักกีฬา:\n จบ ม.6 หรือเทียบเท่า\n มีความสามารถด้านกีฬาโดดเด่นระดับชาติ\n\nสนใจรายละเอียดอะไรเพิ่มไหมครับ? (อาชีพ, ค่าเทอม, จำนวนรับ, เกรด, เอกสาร, อื่นๆ)");
                            currentState = ADM_STATE_PROJECT_DETAILS;
                        }
                        else if (hasKeyword(input, "2") || hasKeyword(input, "วมว")) {
                            selectedProject = "วมว_Port";
                            reply("โครงการ วมว.:\n เป็นนักเรียนโครงการ วมว.\n กำลังเรียน ม.6 สายวิทย์-คณิต\n\nสนใจรายละเอียดอะไรเพิ่มไหมครับ?");
                            currentState = ADM_STATE_PROJECT_DETAILS;
                        }
                        else if (hasKeyword(input, "3") || hasKeyword(input, "พิเศษ")) {
                            selectedProject = "พิเศษ_Port";
                            reply("โครงการความสามารถพิเศษ:\n กำลังเรียน ม.6 สายวิทย์-คณิต\n มีผลงานพิเศษ/นวัตกรรม\n\nสนใจรายละเอียดอะไรเพิ่มไหมครับ?");
                            currentState = ADM_STATE_PROJECT_DETAILS;
                        }
                        else if (hasKeyword(input, "4") || hasKeyword(input, "เรียนดี")) {
                            selectedProject = "เรียนดี_Port";
                            reply("โครงการผลการเรียนดีเด่น:\n กำลังเรียน ม.6 สายวิทย์-คณิต\n GPAX ค่อนข้างสูง\n\nสนใจรายละเอียดอะไรเพิ่มไหมครับ?");
                            currentState = ADM_STATE_PROJECT_DETAILS;
                        }
                        else if (hasKeyword(input, "5") || hasKeyword(input, "วิศวกรรม")) {
                            selectedProject = "วิศวกรรม_Port";
                            reply("โครงการความสามารถทางวิศวกรรม:\n กำลังเรียน ม.6 สายวิทย์-คณิต\n มีผลงานด้านวิศวกรรม/เทคโนโลยี\n\nสนใจรายละเอียดอะไรเพิ่มไหมครับ?");
                            currentState = ADM_STATE_PROJECT_DETAILS;
                        } 
                        else { reply("สาขาโยธามี 5 โครงการ พิมพ์หมายเลข 1-5 ที่คุณสนใจดูครับ"); }
                    }
                    // --- โซนสาขา ไฟฟ้า ---
                    else if (selectedMajor == "ไฟฟ้า") {
                        if (hasKeyword(input, "1") || hasKeyword(input, "นักกีฬา")) {
                            selectedProject = "นักกีฬา_Port";
                            reply("โครงการนักกีฬา:\n จบ ม.6 หรือเทียบเท่า\n มีความสามารถด้านกีฬาโดดเด่นระดับชาติ\n\nสนใจรายละเอียดอะไรเพิ่มไหมครับ?");
                            currentState = ADM_STATE_PROJECT_DETAILS;
                        }
                        else if (hasKeyword(input, "2") || hasKeyword(input, "พิเศษ")) {
                            selectedProject = "พิเศษ_Port";
                            reply("โครงการความสามารถพิเศษ:\n กำลังเรียน ม.6 สายวิทย์-คณิต\n มีผลงานพิเศษ/นวัตกรรม\n\nสนใจรายละเอียดอะไรเพิ่มไหมครับ?");
                            currentState = ADM_STATE_PROJECT_DETAILS;
                        }
                        else if (hasKeyword(input, "3") || hasKeyword(input, "เรียนดี")) {
                            selectedProject = "เรียนดี_Port";
                            reply("โครงการผลการเรียนดีเด่น:\n กำลังเรียน ม.6 สายวิทย์-คณิต\n GPAX ค่อนข้างสูง\n\nสนใจรายละเอียดอะไรเพิ่มไหมครับ?");
                            currentState = ADM_STATE_PROJECT_DETAILS;
                        }
                        else if (hasKeyword(input, "4") || hasKeyword(input, "วิศวกรรม")) {
                            selectedProject = "วิศวกรรม_Port";
                            reply("โครงการความสามารถทางวิศวกรรม:\n กำลังเรียน ม.6 สายวิทย์-คณิต\n มีผลงานด้านวิศวกรรม/เทคโนโลยี\n\nสนใจรายละเอียดอะไรเพิ่มไหมครับ?");
                            currentState = ADM_STATE_PROJECT_DETAILS;
                        }
                        else { reply("สาขาไฟฟ้ามี 4 โครงการ พิมพ์หมายเลข 1-4 ที่คุณสนใจดูครับ"); }
                    }
                    // --- โซนสาขา เครื่องกล ---
                    else if (selectedMajor == "เครื่องกล") {
                        if (hasKeyword(input, "1") || hasKeyword(input, "นักกีฬา")) {
                            selectedProject = "นักกีฬา_Port_Mech";
                            reply("โครงการนักกีฬา:\n จบ ม.6 หรือเทียบเท่า\n มีความสามารถด้านกีฬาโดดเด่นระดับชาติ\n\nสนใจรายละเอียดอะไรเพิ่มไหมครับ?");
                            currentState = ADM_STATE_PROJECT_DETAILS;
                        }
                        else if (hasKeyword(input, "2") || hasKeyword(input, "พิเศษ")) {
                            selectedProject = "พิเศษ_Port_Mech";
                            reply("โครงการความสามารถพิเศษ:\n กำลังเรียน ม.6 สายวิทย์-คณิต\n มีผลงานพิเศษ/นวัตกรรม\n\nสนใจรายละเอียดอะไรเพิ่มไหมครับ?");
                            currentState = ADM_STATE_PROJECT_DETAILS;
                        }
                        else if (hasKeyword(input, "3") || hasKeyword(input, "เรียนดี")) {
                            selectedProject = "เรียนดี_Port_Mech";
                            reply("โครงการผลการเรียนดีเด่น:\n กำลังเรียน ม.6 สายวิทย์-คณิต\n GPAX ค่อนข้างสูง\n\nสนใจรายละเอียดอะไรเพิ่มไหมครับ?");
                            currentState = ADM_STATE_PROJECT_DETAILS;
                        }
                        else if (hasKeyword(input, "4") || hasKeyword(input, "หุ่นยนต์") || hasKeyword(input, "เทคโนโลยี")) {
                            selectedProject = "หุ่นยนต์_Port_Mech";
                            reply("โครงการความสามารถด้านหุ่นยนต์:\n กำลังเรียน ม.6 สายวิทย์-คณิต\n มีผลงานด้านหุ่นยนต์ / Robotics / Automation\n\nสนใจรายละเอียดอะไรเพิ่มไหมครับ?");
                            currentState = ADM_STATE_PROJECT_DETAILS;
                        }
                        else if (hasKeyword(input, "5") || hasKeyword(input, "วิศวกรรม")) {
                            selectedProject = "วิศวกรรม_Port_Mech";
                            reply("โครงการความสามารถทางวิศวกรรม:\n กำลังเรียน ม.6 สายวิทย์-คณิต\n มีผลงานด้านวิศวกรรม/เทคโนโลยี\n\nสนใจรายละเอียดอะไรเพิ่มไหมครับ?");
                            currentState = ADM_STATE_PROJECT_DETAILS;
                        } 
                        else { reply("สาขาเครื่องกลมี 5 โครงการ พิมพ์หมายเลข 1-5 ที่คุณสนใจดูครับ"); }
                    }
                    // --- โซนสาขา อุตสาหการ ---
                    else if (selectedMajor == "อุตสาหการ") {
                        if (hasKeyword(input, "1") || hasKeyword(input, "นักกีฬา") || hasKeyword(input, "ความสามารถดีเด่น")) {
                            selectedProject = "นักกีฬา_Port_Ind";
                            reply("โครงการนักกีฬา:\n จบ ม.6 หรือเทียบเท่า\n มีความสามารถด้านกีฬาโดดเด่นระดับชาติ\n\nสนใจรายละเอียดอะไรเพิ่มไหมครับ?");
                            currentState = ADM_STATE_PROJECT_DETAILS;
                        }
                        else if (hasKeyword(input, "2") || hasKeyword(input, "พิเศษ") || hasKeyword(input, "ผู้มีความรู้")) {
                            selectedProject = "พิเศษ_Port_Ind";
                            reply("โครงการความสามารถพิเศษ:\n กำลังเรียน ม.6 สายวิทย์-คณิต\n มีผลงานพิเศษ/นวัตกรรม\n\nสนใจรายละเอียดอะไรเพิ่มไหมครับ?");
                            currentState = ADM_STATE_PROJECT_DETAILS;
                        }
                        else if (hasKeyword(input, "3") || hasKeyword(input, "หุ่นยนต์") || hasKeyword(input, "เทคโนโลยี")) {
                            selectedProject = "หุ่นยนต์_Port_Ind";
                            reply("โครงการความสามารถด้านหุ่นยนต์:\n กำลังเรียน ม.6 สายวิทย์-คณิต\n มีผลงานด้านหุ่นยนต์ / Robotics / Automation\n\nสนใจรายละเอียดอะไรเพิ่มไหมครับ?");
                            currentState = ADM_STATE_PROJECT_DETAILS;
                        }
                        else if (hasKeyword(input, "4") || hasKeyword(input, "เรียนดี")|| hasKeyword(input, "ผลการเรียนดีเด่น")) {
                            selectedProject = "เรียนดี_Port_Ind";
                            reply("โครงการผลการเรียนดีเด่น:\n กำลังเรียน ม.6 สายวิทย์-คณิต\n GPAX ค่อนข้างสูง\n\nสนใจรายละเอียดอะไรเพิ่มไหมครับ?");
                            currentState = ADM_STATE_PROJECT_DETAILS;
                        }
                        else if (hasKeyword(input, "5") || hasKeyword(input, "ภาษาอังกฤษ") || hasKeyword(input, "ความสามารถทางภาษาอังกฤษ")) {
                            selectedProject = "ภาษาอังกฤษ_Port_Ind";
                            reply("โครงการความสามารถทางภาษาอังกฤษ:\n กำลังเรียน ม.6 สายวิทย์-คณิต\n มีผลงานด้านภาษาอังกฤษ\n\nสนใจรายละเอียดอะไรเพิ่มไหมครับ?");
                            currentState = ADM_STATE_PROJECT_DETAILS;
                        }
                        else if (hasKeyword(input, "6") || hasKeyword(input, "Women in Engineering")|| hasKeyword(input, "Women")) {
                            selectedProject = "Women_in_Engineering_Port_Ind";
                            reply("โครงการผู้หญิงในวิศวกรรม:\n กำลังเรียน ม.6 สายวิทย์-คณิต\n มีผลงานด้านผู้หญิงในวิศวกรรม\n\nสนใจรายละเอียดอะไรเพิ่มไหมครับ?");
                            currentState = ADM_STATE_PROJECT_DETAILS;
                        }
                        else if (hasKeyword(input, "7") || hasKeyword(input, "วิศวกรรม")) {
                            selectedProject = "วิศวกรรม_Port_Ind";
                            reply("โครงการความสามารถทางวิศวกรรม:\n กำลังเรียน ม.6 สายวิทย์-คณิต\n มีผลงานด้านวิศวกรรม/เทคโนโลยี\n\nสนใจรายละเอียดอะไรเพิ่มไหมครับ?");
                            currentState = ADM_STATE_PROJECT_DETAILS;
                        } 
                        else { reply("สาขาอุตสาหการมี 7 โครงการ พิมพ์หมายเลข 1-7 ที่คุณสนใจดูครับ"); }
                    }
                    // --- โซนสาขา คอมพิวเตอร์ ---
                    else if (selectedMajor == "คอมพิวเตอร์") {
                        if (hasKeyword(input, "1") || hasKeyword(input, "นักกีฬา")) {
                            selectedProject = "นักกีฬา_Port_Comp";
                            reply("โครงการนักกีฬา:\n จบ ม.6 หรือเทียบเท่า\n มีความสามารถด้านกีฬาโดดเด่นระดับชาติ\n\nสนใจรายละเอียดอะไรเพิ่มไหมครับ?");
                            currentState = ADM_STATE_PROJECT_DETAILS;
                        }
                        else if (hasKeyword(input, "2") || hasKeyword(input, "อัจฉริยภาพ")|| hasKeyword(input, "คอมพิวเตอร์ ")) {
                            selectedProject = "อัจฉริยภาพ_Port_Comp";
                            reply("ครงการรับนักเรียนที่มีอัจฉริยภาพทางคอมพิวเตอร์:\n กำลังเรียน ม.6 สายวิทย์-คณิต\n มี ผลงานด้านคอมพิวเตอร์หรือเทคโนโลยี\n\nสนใจรายละเอียดอะไรเพิ่มไหมครับ?");
                            currentState = ADM_STATE_PROJECT_DETAILS;
                        }
                        else if (hasKeyword(input, "3") || hasKeyword(input, "เรียนดี")) {
                            selectedProject = "เรียนดี_Port_Comp";
                            reply("โครงการผลการเรียนดีเด่น:\n กำลังเรียน ม.6 สายวิทย์-คณิต\n GPAX ค่อนข้างสูง\n\nสนใจรายละเอียดอะไรเพิ่มไหมครับ?");
                            currentState = ADM_STATE_PROJECT_DETAILS;
                        }
                        else if (hasKeyword(input, "4") || hasKeyword(input, "วิศวกรรม")) {
                            selectedProject = "วิศวกรรม_Port_Comp";
                            reply("โครงการความสามารถทางวิศวกรรม:\n กำลังเรียน ม.6 สายวิทย์-คณิต\n มีผลงานด้านวิศวกรรม/เทคโนโลยี\n\nสนใจรายละเอียดอะไรเพิ่มไหมครับ?");
                            currentState = ADM_STATE_PROJECT_DETAILS;
                        } 
                        else if (hasKeyword(input, "5") || hasKeyword(input, "เรียนรู้นวัตกรรม") || hasKeyword(input, "พลังงาน")|| hasKeyword(input, "สิ่งแวดล้อม")) {
                            selectedProject = "ร่วมมือสร้างสังคมแห่งการเรียนรู้นวัตกรรมด้านพลังงานและสิ่งแวดล้อม_Port_Comp";
                            reply("ครงการความร่วมมือสร้างสังคมแห่งการเรียนรู้นวัตกรรมด้านพลังงานและสิ่งแวดล้อม:\n กำลังเรียน ม.6 สายวิทย์-คณิต\n มี ความสนใจหรือผลงานด้านพลังงาน / สิ่งแวดล้อม / นวัตกรรม\n\nสนใจรายละเอียดอะไรเพิ่มไหมครับ?");
                            currentState = ADM_STATE_PROJECT_DETAILS;
                        }
                        else { reply("สาขาคอมพิวเตอร์มี 5 โครงการ พิมพ์หมายเลข 1-5 ที่คุณสนใจดูครับ"); }
                    }
                    // --- โซนสาขา สิ่งเเวดล้อม ---
                    else if (selectedMajor == "สิ่งเเวดล้อม") {
                        if (hasKeyword(input, "1") || hasKeyword(input, "นักกีฬา")) {
                            selectedProject = "นักกีฬา_Port_Env";
                            reply("โครงการนักกีฬา:\n จบ ม.6 หรือเทียบเท่า\n มีความสามารถด้านกีฬาโดดเด่นระดับชาติ\n\nสนใจรายละเอียดอะไรเพิ่มไหมครับ?");
                            currentState = ADM_STATE_PROJECT_DETAILS;
                        }
                        else if (hasKeyword(input, "2") || hasKeyword(input, "เรียนดี")|| hasKeyword(input, "ผลการเรียนดีเด่น")) {
                            selectedProject = "เรียนดี_Port_Env";
                            reply("โครงการผลการเรียนดีเด่น:\n กำลังเรียน ม.6 สายวิทย์-คณิต\n GPAX ค่อนข้างสูง\n\nสนใจรายละเอียดอะไรเพิ่มไหมครับ?");
                            currentState = ADM_STATE_PROJECT_DETAILS;
                        }
                        else if (hasKeyword(input, "3") || hasKeyword(input, "ฟิสิกส์") || hasKeyword(input, "เคมี")) {
                            selectedProject = "ฟิสิกส์เคมี_Port_Env";
                            reply("โครงการผลการเรียนวิชาฟิสิกส์และเคมีดีเด่น:\n กำลังเรียน ม.6 สายวิทย์-คณิต\n มีผลการเรียนวิชาฟิสิกส์และเคมีดีเด่น\n\nสนใจรายละเอียดอะไรเพิ่มไหมครับ?");
                            currentState = ADM_STATE_PROJECT_DETAILS;
                        }
                        else if (hasKeyword(input, "4") || hasKeyword(input, "วิศวกรรม")) {
                            selectedProject = "วิศวกรรม_Port_Env";
                            reply("โครงการความสามารถทางวิศวกรรม:\n กำลังเรียน ม.6 สายวิทย์-คณิต\n มีผลงานด้านวิศวกรรม/เทคโนโลยี\n\nสนใจรายละเอียดอะไรเพิ่มไหมครับ?");
                            currentState = ADM_STATE_PROJECT_DETAILS;
                        } 
                        else if (hasKeyword(input, "5") || hasKeyword(input, "เรียนรู้นวัตกรรม") || hasKeyword(input, "พลังงาน")|| hasKeyword(input, "สิ่งแวดล้อม")) {
                            selectedProject = "ร่วมมือสร้างสังคมแห่งการเรียนรู้นวัตกรรมด้านพลังงานและสิ่งแวดล้อม_Port_Env";
                            reply("โครงการความร่วมมือสร้างสังคมแห่งการเรียนรู้นวัตกรรมด้านพลังงานและสิ่งแวดล้อม:\n กำลังเรียน ม.6 สายวิทย์-คณิต\n มี ความสนใจหรือผลงานด้านพลังงาน / สิ่งแวดล้อม / นวัตกรรม\n\nสนใจรายละเอียดอะไรเพิ่มไหมครับ?");
                            currentState = ADM_STATE_PROJECT_DETAILS;
                        }
                        else { reply("สาขาสิ่งแวดล้อมมี 5 โครงการ พิมพ์หมายเลข 1-5 ที่คุณสนใจดูครับ"); }
                    }
                    // --- โซนสาขา เหมืองแร่และปิโตรเลียม ---
                    else if (selectedMajor == "เหมืองแร่และปิโตรเลียม") {
                        if (hasKeyword(input, "1") || hasKeyword(input, "วิศวกรรม")) {
                            selectedProject = "วิศวกรรม_Port_Mining";
                            reply("โครงการความสามารถทางวิศวกรรม:\n เรียน ม.6 สายวิทย์-คณิต\n มีผลงานด้านวิศวกรรม/เทคโนโลยี\n\nสนใจรายละเอียดอะไรเพิ่มไหมครับ?");
                            currentState = ADM_STATE_PROJECT_DETAILS;
                        }
                        else { reply("สาขาเหมืองแร่และปิโตรเลียมมี 1 โครงการ พิมพ์หมายเลข 1 ที่คุณสนใจดูครับ"); }
                    }
                    // --- โซนสาขา หุ่นยนต์และปัญญาประดิษฐ์ ---
                    else if (selectedMajor == "หุ่นยนต์และปัญญาประดิษฐ์") {
                        if (hasKeyword(input, "1") || hasKeyword(input, "แกนกลาง")) {
                            selectedProject = "เรียนดี_Port_Robotics_Core";
                            reply("โครงการผลการเรียนดีเด่น (สำหรับหลักสูตรแกนกลาง):\n กำลังเรียน ม.6 สายวิทย์-คณิต\n GPAX ค่อนข้างสูง\n\nสนใจรายละเอียดอะไรเพิ่มไหมครับ?");
                            currentState = ADM_STATE_PROJECT_DETAILS;
                        }
                        else if (hasKeyword(input, "2") || hasKeyword(input, "อาชีวศึกษา")) {
                            selectedProject = "เรียนดี_Port_Robotics_Voc";
                            reply("โครงการผลการเรียนดีเด่น (สำหรับหลักสูตรอาชีวศึกษา):\n กำลังเรียน ม.6 สายวิทย์-คณิต\n GPAX ค่อนข้างสูง\n\nสนใจรายละเอียดอะไรเพิ่มไหมครับ?");
                            currentState = ADM_STATE_PROJECT_DETAILS;
                        }
                        else if (hasKeyword(input, "3") || hasKeyword(input, "วิศวกรรม")) {
                            selectedProject = "วิศวกรรม_Port_Robotics";
                            reply("โครงการความสามารถทางวิศวกรรม:\n กำลังเรียน ม.6 สายวิทย์-คณิต\n มีผลงานด้านวิศวกรรม/เทคโนโลยี\n\nสนใจรายละเอียดอะไรเพิ่มไหมครับ?");
                            currentState = ADM_STATE_PROJECT_DETAILS;
                        }
                        else { reply("สาขาหุ่นยนต์และปัญญาประดิษฐ์มี 3 โครงการ พิมพ์หมายเลข 1-3 ที่คุณสนใจดูครับ"); }
                    }
                    // --- โซนสาขา บูรณาการ ---
                    else if (selectedMajor == "บูรณาการ") {
                        if (hasKeyword(input, "1") || hasKeyword(input, "นักกีฬา")) {
                            selectedProject = "นักกีฬา_Port_Inter";
                            reply("โครงการนักกีฬา:\n จบ ม.6 หรือเทียบเท่า\n มีความสามารถด้านกีฬาโดดเด่นระดับชาติ\n\nสนใจรายละเอียดอะไรเพิ่มไหมครับ?");
                            currentState = ADM_STATE_PROJECT_DETAILS;
                        }
                        else if (hasKeyword(input, "2") || hasKeyword(input, "เรียนดี")|| hasKeyword(input, "ผลการเรียนดีเด่น")) {
                            selectedProject = "เรียนดี_Port_Inter";
                            reply("โครงการผลการเรียนดีเด่น:\n กำลังเรียน ม.6 สายวิทย์-คณิต\n GPAX ค่อนข้างสูง\n\nสนใจรายละเอียดอะไรเพิ่มไหมครับ?");
                            currentState = ADM_STATE_PROJECT_DETAILS;
                        }
                        else { reply("สาขาบูรณาการมี 2 โครงการ พิมพ์หมายเลข 1-2 ที่คุณสนใจดูครับ"); }
                    }
                } // ปิดบล็อก if (selectedRound == "Portfolio")

// ============================================================================================================================== //
                else if (selectedRound == "Quota") {
                    if (hasKeyword(input, "1") || hasKeyword(input, "ภาคเหนือ")) {
                        selectedProject = "ภาคเหนือ_Quota";
                        reply("โควตาภาคเหนือ:\n เรียน ม.6 สายวิทย์-คณิต ในโรงเรียนภาคเหนือ\n\nสนใจรายละเอียดอะไรเพิ่มไหมครับ?");
                        currentState = ADM_STATE_PROJECT_DETAILS;
                    }
                    else if (hasKeyword(input, "2") || hasKeyword(input, "กีฬา")) {
                        selectedProject = "กีฬา_Quota";
                        reply("โควตากีฬา:\n เรียน ม.6 สายวิทย์-คณิต\n มีผลงานกีฬาระดับโรงเรียน/จังหวัด/ภาค\n\nสนใจรายละเอียดอะไรเพิ่มไหมครับ?");
                        currentState = ADM_STATE_PROJECT_DETAILS;
                    } 
                    // Quota computer มี 4 โครงการ
                    else if (hasKeyword(input, "3") || hasKeyword(input, "พิการ") || hasKeyword(input, "การรับนักเรียนพิการ")) {
                        selectedProject = "พิการ_Quota_Comp";
                        reply("โควตาการรับนักเรียนพิการ:\n เรียน ม.6 สายวิทย์-คณิต\n เป็นนักเรียนพิการตามที่ กสพท. กำหนด\n\nสนใจรายละเอียดอะไรเพิ่มไหมครับ?");
                        currentState = ADM_STATE_PROJECT_DETAILS;
                    }
                    else if (hasKeyword(input, "4") || hasKeyword(input, "นอกเขต") || hasKeyword(input, "17 จังหวัดภาคเหนือ")) {
                        selectedProject = "นอกเขต_Quota_Comp";
                        reply("โควตานอกเขต 17 จังหวัดภาคเหนือ:\n เรียน ม.6 สายวิทย์-คณิต ในโรงเรียนที่ไม่ใช่ 17 จังหวัดภาคเหนือ\n\nสนใจรายละเอียดอะไรเพิ่มไหมครับ?");
                        currentState = ADM_STATE_PROJECT_DETAILS;
                    }
                    else { reply("พิมพ์ 1 หรือ 2 เพื่อเลือกโครงการครับ"); }
                }
                else if (selectedRound == "Admission") {
                    if (hasKeyword(input, "1") || hasKeyword(input, "รับตรง")) {
                        selectedProject = "รับตรง_Admin";
                        reply("รับตรงร่วมกัน:\n ใช้คะแนนสอบแข่งขัน ไม่ต้องใช้ Portfolio\n\nสนใจรายละเอียดอะไรเพิ่มไหมครับ?");
                        currentState = ADM_STATE_PROJECT_DETAILS;
                    } else { reply("พิมพ์ 1 เพื่อดูรายละเอียดครับ"); }
                }
                break;

// ============================================================================================================================== //
            case ADM_STATE_PROJECT_DETAILS:
                if (hasKeyword(input, "อาชีพ") || hasKeyword(input, "ทำงาน")) {
                    if (selectedMajor == "โยธา") reply("สามารถประกอบอาชีพได้หลากหลาย เช่น วิศวกรก่อสร้าง, วิศวกรโครงการ, วิศวกรด้านผลิตภัณฑ์วัสดุ, วิศวกรสำรวจเส้นทาง หรือที่ปรึกษางานก่อสร้าง/ผู้รับเหมา ครับ");
                    else if (selectedMajor == "ไฟฟ้า") reply("วิศวกรไฟฟ้ากำลัง, วิศวกรไฟฟ้าสื่อสารและโทรคมนาคม, วิศวกรอิเล็กทรอนิกส์ด้านการออกแบบและผลิตชิ้นส่วนอิเล็กทรอนิกส์, วิศวกรด้านสมองกลฝังตัวและปัญญาประดิษฐ์, วิศวกรด้านการวิเคราะห์และออกแบบระบบไฟฟ้า ครับ");
                    else if (selectedMajor == "เครื่องกล") reply("วิศวกรนักออกแบบเครื่องจักรกล, วิศวกรซ่อมบำรุงเครื่องจักร, วิศวกรพลังงาน, วิศวกรระบบอัตโนมัติ, วิศวกรบริหารโครงการ ครับ");
                    else if (selectedMajor == "อุตสาหการ") reply("วิศวกรโรงงาน, วิศวกรฝ่ายควบคุมคุณภาพ, วิศวกรควบคุมกระบวนการผลิต , วิศวกรโลจิสติกส์, วิศวกรความปลอดภัย ครับ");
                    else if (selectedMajor == "คอมพิวเตอร์") reply("วิศวกรซอฟต์แวร์, วิศวกรระบบเครือข่าย, วิศวกรความปลอดภัยไซเบอร์, วิศวกรปัญญาประดิษฐ์, วิศวกรด้านข้อมูล ครับ");
                    else if (selectedMajor == "สิ่งเเวดล้อม") reply("วิศวกรสิ่งแวดล้อม, วิศวกรพลังงานทดแทน, วิศวกรจัดการทรัพยากรน้ำ, วิศวกรจัดการของเสีย, วิศวกรด้านการประเมินผลกระทบสิ่งแวดล้อม ครับ");
                    else if (selectedMajor == "เหมืองแร่และปิโตรเลียม") reply("วิศวกรเหมืองแร่, วิศวกรปิโตรเลียม, วิศวกรสำรวจแหล่งทรัพยากรธรรมชาติ, วิศวกรด้านความปลอดภัยในการทำงาน, วิศวกรด้านสิ่งแวดล้อม ครับ");
                    else if (selectedMajor == "หุ่นยนต์และปัญญาประดิษฐ์") reply("วิศวกรหุ่นยนต์, วิศวกรปัญญาประดิษฐ์, วิศวกรระบบอัตโนมัติ, วิศวกรด้านการออกแบบและพัฒนาหุ่นยนต์, วิศวกรด้านการประยุกต์ใช้ AI ครับ");
                    else if (selectedMajor == "บูรณาการ") reply("วิศวกรส่วนประกอบอิเล็กทรอนิกส์ (Electronics Component Engineer), วิศวกรด้านพลังงานทดแทน (Renewable Energy Engineer), วิศวกรเขียนแบบจำลองสารสนเทศอาคาร (BIM Engineer), ผู้พัฒนาซอฟต์แวร์ (Software Developer), ที่ปรึกษาด้านวิศวกรรม (Engineering Consultant) ครับ");
                } 
                else if (hasKeyword(input, "ค่าธรรมเนียม") || hasKeyword(input, "ค่าใช้จ่าย") || hasKeyword(input, "ค่าเทอม")) {
                    reply("ค่าธรรมเนียมการศึกษา ภาคการศึกษาแรก 23,000 บาท ครับ");
                }
                else if (hasKeyword(input, "ค่าธรรมเนียมหุ่นยนต์") || hasKeyword(input, "ค่าใช้จ่ายหุ่นยนต์") || hasKeyword(input, "ค่าเทอมหุ่นยนต์")) {
                    reply("ค่าธรรมเนียมการศึกษา ภาคการศึกษาแรก 35,000 บาท ครับ");
                } 
// ============================================================================================================================== //
                // --- เรื่องจำนวนรับ (เช็คตามสาขาและโปรเจกต์) ---
                else if (hasKeyword(input, "จำนวนรับเข้า") || hasKeyword(input, "จำนวนรับ") || hasKeyword(input, "จำนวน")) {
                    if (selectedMajor == "โยธา") {
                        if (selectedProject == "นักกีฬา_Port" || selectedProject == "กีฬา_Quota") reply("จำนวนรับเข้า 2 คน ครับ");
                        else if (selectedProject == "วมว_Port") reply("จำนวนรับเข้า 5 คน ครับ");
                        else if (selectedProject == "พิเศษ_Port") reply("แบบ 1.1: 5 คน\nแบบ 1.2: 5 คน ครับ");
                        else if (selectedProject == "เรียนดี_Port") reply("แบบ 1.1: 10 คน\nแบบ 1.2: 10 คน ครับ");
                        else if (selectedProject == "วิศวกรรม_Port") reply("แบบ 1.1: 10 คน\nแบบ 1.2: 0 คน ครับ");
                        else if (selectedProject == "ภาคเหนือ_Quota") reply("จำนวนรับเข้า 50 คน ครับ");
                        else if (selectedProject == "รับตรง_Admin") reply("จำนวนรับเข้า 20 คน ครับ");
                    }
                    else if (selectedMajor == "ไฟฟ้า") {
                        if (selectedProject == "นักกีฬา_Port" || selectedProject == "กีฬา_Quota") reply("จำนวนรับเข้า 2 คน ครับ");
                        else if (selectedProject == "พิเศษ_Port") reply("แบบ 1.1: 5 คน\nแบบ 1.2: 0 คน ครับ");
                        else if (selectedProject == "เรียนดี_Port") reply("แบบ 1.1: 15 คน\nแบบ 1.2: 5 คน ครับ");
                        else if (selectedProject == "วิศวกรรม_Port") reply("แบบ 1.1: 10 คน\nแบบ 1.2: 0 คน ครับ");
                        else if (selectedProject == "ภาคเหนือ_Quota") reply("จำนวนรับเข้า 40 คน ครับ");
                        else if (selectedProject == "รับตรง_Admin") reply("จำนวนรับเข้า 10 คน ครับ");
                    }
                    else if (selectedMajor == "เครื่องกล") {
                        if (selectedProject == "นักกีฬา_Port_Mech" || selectedProject == "กีฬา_Quota") reply("จำนวนรับเข้า 2 คน ครับ");
                        else if (selectedProject == "พิเศษ_Port_Mech") reply("แบบ 1.1: 5 คน\nแบบ 1.2: 2 คน ครับ");
                        else if (selectedProject == "เรียนดี_Port_Mech") reply("แบบ 1.1: 52 คน\nแบบ 1.2: 15 คน ครับ");
                        else if (selectedProject == "หุ่นยนต์_Port_Mech") reply("แบบ 1.1: 4 คน\nแบบ 1.2: 1 คน ครับ");
                        else if (selectedProject == "วิศวกรรม_Port_Mech") reply("แบบ 1.1: 7 คน\nแบบ 1.2: 0 คน ครับ");
                        else if (selectedProject == "ภาคเหนือ_Quota") reply("จำนวนรับเข้า 120 คน ครับ");
                        else if (selectedProject == "รับตรง_Admin") reply("จำนวนรับเข้า 10 คน ครับ");
                    }
                    else if (selectedMajor == "อุตสาหการ") {
                        if (selectedProject == "นักกีฬา_Port_Ind") reply("จำนวนรับเข้า 2 คน ครับ");
                        else if (selectedProject == "พิเศษ_Port_Ind") reply("แบบ 1.1: 15 คน\nแบบ 1.2: 0 คน ครับ");
                        else if (selectedProject == "หุ่นยนต์_Port_Ind") reply("แบบ 1.1: 3 คน\nแบบ 1.2: 0 คน ครับ");
                        else if (selectedProject == "เรียนดี_Port_Ind") reply("แบบ 1.1: 25 คน\nแบบ 1.2: 0 คน ครับ");
                        else if (selectedProject == "ภาษาอังกฤษ_Port_Ind") reply("แบบ 1.1: 5 คน\nแบบ 1.2: 0 คน ครับ");
                        else if (selectedProject == "Women_in_Engineering_Port_Ind") reply("แบบ 1.1: 10 คน\nแบบ 1.2: 0 คน ครับ");
                        else if (selectedProject == "วิศวกรรม_Port_Ind") reply("แบบ 1.1: 10 คน\nแบบ 1.2: 0 คน ครับ");
                        else if (selectedProject == "ภาคเหนือ_Quota") reply("จำนวนรับเข้า 80 คน ครับ");
                        else if (selectedProject == "กีฬา_Quota") reply("จำนวนรับเข้า 2 คน ครับ");
                        else if (selectedProject == "รับตรง_Admin") reply("จำนวนรับเข้า 40 คน ครับ");
                    }
                    else if (selectedMajor == "คอมพิวเตอร์") {
                         if (selectedProject == "นักกีฬา_Port_Comp") reply("จำนวนรับเข้า 1 คน ครับ");
                        else if (selectedProject == "อัจฉริยภาพ_Port_Comp") reply("แบบ 1.1: 27 คน\nแบบ 1.2: 3 คน ครับ");
                        else if (selectedProject == "เรียนดี_Port_Comp") reply("แบบ 1.1: 22 คน\nแบบ 1.2: 3 คน ครับ");
                        else if (selectedProject == "วิศวกรรม_Port_Comp") reply("แบบ 1.1: 10 คน\nแบบ 1.2: 0 คน ครับ");
                        else if (selectedProject == "ร่วมมือสร้างสังคมแห่งการเรียนรู้นวัตกรรมด้านพลังงานและสิ่งแวดล้อม_Port_Comp") reply("แบบ 1.1: 3 คน\nแบบ 1.2: 0 คน ครับ");
                        else if (selectedProject == "ภาคเหนือ_Quota") reply("จำนวนรับเข้า 30 คน ครับ");
                        else if (selectedProject == "กีฬา_Quota") reply("จำนวนรับเข้า 1 คน ครับ");
                        else if (selectedProject == "พิการ_Quota_Comp") reply("จำนวนรับเข้า 2 คน ครับ");
                        else if (selectedProject == "นอกเขต_Quota_Comp") reply("จำนวนรับเข้า 10 คน ครับ");
                        else if (selectedProject == "รับตรง_Admin") reply("จำนวนรับเข้า 10 คน ครับ");
                    }
                    else if (selectedMajor == "สิ่งเเวดล้อม") {
                        if (selectedProject == "นักกีฬา_Port_Env") reply("จำนวนรับเข้า 2 คน ครับ");
                        else if (selectedProject == "เรียนดี_Port_Env") reply("แบบ 1.1: 20 คน\nแบบ 1.2: 0 คน ครับ");
                        else if (selectedProject == "ฟิสิกส์เคมี_Port_Env") reply("แบบ 1.1: 15 คน\nแบบ 1.2: 0 คน ครับ");
                        else if (selectedProject == "วิศวกรรม_Port_Env") reply("แบบ 1.1: 10 คน\nแบบ 1.2: 0 คน ครับ");
                        else if (selectedProject == "ร่วมมือสร้างสังคมแห่งการเรียนรู้นวัตกรรมด้านพลังงานและสิ่งแวดล้อม_Port_Env") reply("แบบ 1.1: 3 คน\nแบบ 1.2: 0 คน ครับ");
                        else if (selectedProject == "ภาคเหนือ_Quota") reply("จำนวนรับเข้า 35 คน ครับ");
                        else if (selectedProject == "กีฬา_Quota") reply("จำนวนรับเข้า 2 คน ครับ");
                        else if (selectedProject == "รับตรง_Admin") reply("จำนวนรับเข้า 5 คน ครับ");
                    }
                     else if (selectedMajor == "เหมืองแร่และปิโตรเลียม") {
                        if (selectedProject == "วิศวกรรม_Port_Mining") reply("แบบ 1.1: 10 คน\nแบบ 1.2: 0 คน ครับ");
                        else if (selectedProject == "ภาคเหนือ_Quota") reply("จำนวนรับเข้า 25 คน ครับ");
                        else if (selectedProject == "รับตรง_Admin") reply("จำนวนรับเข้า 5 คน ครับ");
                    }
                    else if (selectedMajor == "หุ่นยนต์และปัญญาประดิษฐ์") {
                        if (selectedProject == "เรียนดี_Port_Robotics_Core") reply("แบบ 1.1: 10 คน\nแบบ 1.2: 10 คน ครับ");
                        else if (selectedProject == "เรียนดี_Port_Robotics_Voc") reply("แบบ 1.1: 5 คน\nแบบ 1.2: 0 คน ครับ");
                        else if (selectedProject == "วิศวกรรม_Port_Robotics") reply("แบบ 1.1: 10 คน\nแบบ 1.2: 0 คน ครับ");
                        else if (selectedProject == "ภาคเหนือ_Quota") reply("จำนวนรับเข้า 20 คน ครับ");
                        else if (selectedProject == "รับตรง_Admin") reply("จำนวนรับเข้า 20 คน ครับ");
                    }
                    else if (selectedMajor == "บูรณาการ") {
                        if (selectedProject == "นักกีฬา_Port_Inter") reply("จำนวนรับเข้า 2 คน ครับ");
                        else if (selectedProject == "เรียนดี_Port_Inter") reply("แบบ 1.1: 20 คน\nแบบ 1.2: 0 คน ครับ");
                        else if (selectedProject == "ภาคเหนือ_Quota") reply("จำนวนรับเข้า 25 คน ครับ");
                        else if (selectedProject == "รับตรง_Admin") reply("จำนวนรับเข้า 10 คน ครับ");
                    }
                }
                else if (hasKeyword(input, "เกรด") || hasKeyword(input, "ผลการเรียน")) {
                    if (selectedProject == "นักกีฬา_Port") reply("GPAX 5 เทอม ไม่น้อยกว่า 3.00");
                    else if (selectedProject == "วมว_Port" || selectedProject == "พิเศษ_Port") reply("GPAX 5 เทอม ไม่น้อยกว่า 3.25");
                    else if (selectedProject == "เรียนดี_Port") reply("GPAX 5 เทอม ไม่น้อยกว่า 3.50");
                    else if (selectedProject == "วิศวกรรม_Port") reply("ต้องผ่านหลักสูตรอบรมระยะสั้น Entaneer Academy เกรดไม่น้อยกว่า B จำนวน 3 วิชา");
                    else if (selectedRound == "Quota" || selectedRound == "Admission") reply("ใช้คะแนนสอบ TGAT / TPAT หรือ A-Level ในการยื่นสมัครครับ");

                    else if (selectedProject == "นักกีฬา_Port_Mech") reply("GPAX 5 เทอม ไม่น้อยกว่า 3.00");
                    else if (selectedProject == "พิเศษ_Port_Mech" || selectedProject == "หุ่นยนต์_Port_Mech") reply("GPAX 5 เทอม ไม่น้อยกว่า 3.25");
                    else if (selectedProject == "เรียนดี_Port_Mech") reply("GPAX 5 เทอม ไม่น้อยกว่า 3.75");
                    else if (selectedProject == "วิศวกรรม_Port_Mech") reply("ต้องผ่านหลักสูตรอบรมระยะสั้น Entaneer Academy เกรดไม่น้อยกว่า B จำนวน 3 วิชา");

                    else if (selectedProject == "นักกีฬา_Port_Ind") reply("GPAX 5 เทอม ไม่น้อยกว่า 3.00 ครับ");
                    else if (selectedProject == "พิเศษ_Port_Ind") reply("GPAX 5 เทอม ไม่น้อยกว่า 3.00 ครับ");
                    else if (selectedProject == "หุ่นยนต์_Port_Ind") reply("GPAX 5 เทอม ไม่น้อยกว่า 3.00 ครับ");
                    else if (selectedProject == "เรียนดี_Port_Ind") reply("GPAX 5 เทอม ไม่น้อยกว่า 3.50 ครับ");
                    else if (selectedProject == "ภาษาอังกฤษ_Port_Ind") reply("GPAX 5 เทอม ไม่น้อยกว่า 3.00 ครับ");
                    else if (selectedProject == "Women_in_Engineering_Port_Ind") reply("GPAX 5 เทอม ไม่น้อยกว่า 3.25 ครับ");
                    else if (selectedProject == "วิศวกรรม_Port_Ind") reply("ต้องผ่านหลักสูตรอบรมระยะสั้น Entaneer Academy เกรดไม่น้อยกว่า B จำนวน 3 วิชา ครับ");

                    else if (selectedProject == "นักกีฬา_Port_Comp") reply("GPAX 5 เทอม ไม่น้อยกว่า 3.00 ครับ");
                    else if (selectedProject == "อัจฉริยภาพ_Port_Comp") reply("GPAX 5 เทอม ไม่น้อยกว่า 3.00 ครับ");
                    else if (selectedProject == "เรียนดี_Port_Comp") reply("GPAX 5 เทอม ไม่น้อยกว่า 3.50 ครับ");
                    else if (selectedProject == "วิศวกรรม_Port_Comp") reply("ต้องผ่านหลักสูตรอบรมระยะสั้น Entaneer Academy เกรดไม่น้อยกว่า B จำนวน 3 วิชา ครับ");
                    else if (selectedProject == "ร่วมมือสร้างสังคมแห่งการเรียนรู้นวัตกรรมด้านพลังงานและสิ่งแวดล้อม_Port_Comp") reply("GPAX 5 เทอม ไม่น้อยกว่า 3.00 ครับ");
                   
                    else if (selectedProject == "นักกีฬา_Port_Env") reply("GPAX 5 เทอม ไม่น้อยกว่า 3.00 ครับ");
                    else if (selectedProject == "เรียนดี_Port_Env") reply("GPAX 5 เทอม ไม่น้อยกว่า 3.50 ครับ");
                    else if (selectedProject == "ฟิสิกส์เคมี_Port_Env") reply("GPAX 5 เทอม ไม่น้อยกว่า 3.00 ครับ");
                    else if (selectedProject == "วิศวกรรม_Port_Env") reply("ต้องผ่านหลักสูตรอบรมระยะสั้น Entaneer Academy เกรดไม่น้อยกว่า B จำนวน 3 วิชา ครับ");
                    else if (selectedProject == "ร่วมมือสร้างสังคมแห่งการเรียนรู้นวัตกรรมด้านพลังงานและสิ่งแวดล้อม_Port_Env") reply("GPAX 5 เทอม ไม่น้อยกว่า 3.00 ครับ");
                    
                    else if (selectedProject == "วิศวกรรม_Port_Mining") reply("ต้องผ่านหลักสูตรอบรมระยะสั้น Entaneer Academy เกรดไม่น้อยกว่า B จำนวน 3 วิชา ครับ");

                    else if (selectedProject == "เรียนดี_Port_Robotics_Core") reply("GPAX 5 เทอม ไม่น้อยกว่า 3.75 ครับ");
                    else if (selectedProject == "เรียนดี_Port_Robotics_Voc") reply("GPAX 5 เทอม ไม่น้อยกว่า 3.50 ครับ");
                    else if (selectedProject == "วิศวกรรม_Port_Robotics") reply("ต้องผ่านหลักสูตรอบรมระยะสั้น Entaneer Academy เกรดไม่น้อยกว่า B จำนวน 3 วิชา ครับ");

                    else if (selectedProject == "นักกีฬา_Port_Inter") reply("GPAX 5 เทอม ไม่น้อยกว่า 3.00 ครับ");
                    else if (selectedProject == "เรียนดี_Port_Inter") reply("GPAX 5 เทอม ไม่น้อยกว่า 3.25 ครับ");
                }
                // --- เรื่องคุณสมบัติ ---
                else if (hasKeyword(input, "คุณสมบัติ")) {
                    if (selectedRound == "Admission") {
                        reply("รับผู้สำเร็จ ม.6, ปวช. หรือ กศน. ระดับมัธยมปลาย ครับ");
                    } else {
                        reply("โปรดดูรายละเอียดคุณสมบัติเพิ่มเติม ทางเว็บไซต์: https://admission.reg.cmu.ac.th/tcas/ ครับ");
                    }
                }
// ============================================================================================================================== //
                // --- เรื่องคะแนนสอบ ---
                else if (hasKeyword(input, "คะเเนน") || hasKeyword(input, "คะแนนสอบ")) {
                    
                    if (selectedMajor == "โยธา") {
                        if (selectedRound == "Quota") {
                            reply("เกณฑ์ขั้นต่ำ: TPAT3, Math1, Physics, English >= 45 ทุกวิชา\nสัดส่วน: TPAT3(20%), Math1(20%), Phy(20%), Chem(10%), Bio(5%), Soc(5%), Thai(5%), Eng(15%)");
                        } 
                        else if (selectedRound == "Admission") {
                            reply("เกณฑ์ขั้นต่ำ: TPAT3, Math1, Physics, English >= 45\nสัดส่วน: TGAT(20%), TPAT3(30%), Math1(25%), Phy(25%)");
                        } 
                        else if (selectedProject == "พิเศษ_Port" || selectedProject == "เรียนดี_Port") {
                            reply("เกณฑ์ขั้นต่ำ: TPAT3 >= 45\nสัดส่วน: พิจารณาจาก Portfolio และคะแนน TPAT3 ตามประกาศโครงการครับ");
                        } 
                        else { reply("โครงการนี้พิจารณาคะเเนนที่ยื่น เป็นหลักครับ"); }
                    }
                    else if (selectedMajor == "ไฟฟ้า") {
                        if (selectedRound == "Quota") {
                            reply("เกณฑ์ขั้นต่ำ: TPAT3, Math1, Physics, English >= 45\nสัดส่วน: TPAT3(15%), Math1(20%), Phy(20%), Chem(15%), Bio(5%), Soc(5%), Thai(5%), Eng(15%)");
                        } 
                        else if (selectedRound == "Admission") {
                            reply("เกณฑ์ขั้นต่ำ: TPAT3, Math1, Physics, English >= 45\nสัดส่วน: TGAT(20%), TPAT3(40%), Math1(20%), Phy(20%)");
                        } 
                        else if (selectedProject == "พิเศษ_Port" || selectedProject == "เรียนดี_Port") {
                            reply("เกณฑ์ขั้นต่ำ: TPAT3 >= 45\nสัดส่วน: Portfolio(40%), TGAT1(15%), TGAT2(15%), TPAT3(30%)");
                        } 
                        else { reply("โครงการนี้พิจารณาคะเเนนที่ยื่น เป็นหลักครับ"); }
                    }
                    else if (selectedMajor == "เครื่องกล") {
                        if (selectedRound == "Quota") {
                            reply("เกณฑ์ขั้นต่ำ: TPAT3, Math1, Physics, English >= 45\nสัดส่วน: TPAT3(15%), Math1(20%), Phy(20%), Chem(15%), Bio(5%), Soc(5%), Thai(5%), Eng(15%)");
                        } 
                        else if (selectedRound == "Admission") {
                            reply("เกณฑ์ขั้นต่ำ: TPAT3, Math1, Physics, English >= 45\nสัดส่วน: TGAT(20%), TPAT3(40%), Math1(20%), Phy(20%)");
                        } 
                        else if (selectedProject == "พิเศษ_Port_Mech" || selectedProject == "เรียนดี_Port_Mech") {
                            reply("เกณฑ์ขั้นต่ำ: TPAT3 >= 45\nสัดส่วน: Portfolio(20%), TGAT1(16%), TGAT2(16%), TPAT3(48%)");
                        } 
                        else { reply("โครงการนี้พิจารณาคะเเนนที่ยื่น เป็นหลักครับ"); }
                    }
                    else if (selectedMajor == "อุตสาหการ") {
                        if (selectedRound == "Quota") {
                            reply("เกณฑ์ขั้นต่ำ: TPAT3, Math1, Physics, English >= 45\nสัดส่วน: TPAT3(15%), Math1(20%), Phy(20%), Chem(15%), Bio(5%), Soc(5%), Thai(5%), Eng(15%)");
                        } 
                        else if (selectedRound == "Admission") {
                            reply("เกณฑ์ขั้นต่ำ: TPAT3, Math1, Physics, English >= 45\nสัดส่วน: TGAT(20%), TPAT3(40%), Math1(20%), Phy(20%)");
                        } 
                        else if (selectedProject == "พิเศษ_Port_Mech" || selectedProject == "เรียนดี_Port_Mech") {
                            reply("เกณฑ์ขั้นต่ำ: TPAT3 >= 45\nสัดส่วน: Portfolio(20%), TGAT1(16%), TGAT2(16%), TPAT3(48%)");
                        } 
                        else { reply("โครงการนี้พิจารณาคะเเนนที่ยื่น เป็นหลักครับ"); }
                    }
                    else if (selectedMajor == "คอมพิวเตอร์") {
                        if (selectedRound == "Quota") {
                            reply("คุณต้องการเข้าโควตาโครงการไหนครับ? ");
                            if (hasKeyword(input, "3") || hasKeyword(input, "พิการ") || hasKeyword(input, "การรับนักเรียนพิการ")) {
                                selectedProject = "พิการ_Quota_Comp";
                                reply("เกณฑ์ขั้นต่ำ: TPAT3, Math1, Physics, English >= 45\nสัดส่วน: TPAT3(15%), Math1(20%), Phy(20%), Chem(5%), Bio(5%), Soc(5%), Thai(10%), Eng(20%)");
                                currentState = ADM_STATE_PROJECT_DETAILS;
                            }
                            else if (hasKeyword(input, "4") || hasKeyword(input, "นอกเขต") || hasKeyword(input, "17 จังหวัดภาคเหนือ")) {
                                selectedProject = "นอกเขต_Quota_Comp";
                                reply("เกณฑ์ขั้นต่ำ: TPAT3, Math1, Physics, English >= 45\nสัดส่วน: TPAT3(15%), Math1(20%), Phy(20%), Chem(5%), Bio(5%), Soc(5%), Thai(10%), Eng(20%)");
                                currentState = ADM_STATE_PROJECT_DETAILS;
                            }
                            else if (hasKeyword(input, "1") || hasKeyword(input, "ภาคเหนือ")) {
                                selectedProject = "ภาคเหนือ_Quota";
                                reply("เกณฑ์ขั้นต่ำ: TPAT3, Math1, Physics, English >= 45\nสัดส่วน: TPAT3(15%), Math1(20%), Phy(20%), Chem(15%), Bio(5%), Soc(5%), Thai(5%), Eng(15%)");
                                currentState = ADM_STATE_PROJECT_DETAILS;
                            }
                            else if (hasKeyword(input, "2") || hasKeyword(input, "กีฬา")) {
                                selectedProject = "กีฬา_Quota";
                                reply("เกณฑ์ขั้นต่ำ: TPAT3, Math1, Physics, English >= 45\nสัดส่วน: TPAT3(15%), Math1(20%), Phy(20%), Chem(15%), Bio(5%), Soc(5%), Thai(5%), Eng(15%)");
                                currentState = ADM_STATE_PROJECT_DETAILS;
                           } 
                             else { reply("ลองเลือกโครงการที่อยากเข้าดูครับ"); }
                            } 
                        else if (selectedRound == "Admission") {
                            reply("เกณฑ์ขั้นต่ำ: TPAT3, Math1, Physics, English >= 45\nสัดส่วน: TGAT(20%), TPAT3(40%), Math1(20%), Phy(20%)");
                        } 
                        else if (selectedProject == "อัจฉริยภาพ_Port_Comp" || selectedProject == "เรียนดี_Port_Comp") {
                            reply("เกณฑ์ขั้นต่ำ: TPAT3 >= 45\nสัดส่วน: Portfolio(30%), TGAT1(10%), TGAT2(10%), TPAT3(50%)");
                        } 
                           else { reply("โครงการนี้พิจารณาคะเเนนที่ยื่น เป็นหลักครับ"); }
                    }
                    else if (selectedMajor == "สิ่งเเวดล้อม") {
                        if (selectedRound == "Quota") {
                            reply("เกณฑ์ขั้นต่ำ: TPAT3, Math1, Physics, English >= 45\nสัดส่วน: TPAT3(15%), Math1(20%), Phy(20%), Chem(15%), Bio(5%), Soc(5%), Thai(5%), Eng(15%)");
                        } 
                        else if (selectedRound == "Admission") {
                            reply("เกณฑ์ขั้นต่ำ: TPAT3, Math1, Physics, English >= 45\nสัดส่วน: TGAT(20%), TPAT3(40%), Math1(20%), Phy(20%)");
                        } 
                        else { reply("โครงการนี้พิจารณาคะเเนนที่ยื่น เป็นหลักครับ"); }
                    }
                    else if (selectedMajor == "เหมืองแร่และปิโตรเลียม") {
                        if (selectedRound == "Quota") {
                                reply("เกณฑ์ขั้นต่ำ: TPAT3, Math1, Physics, English >= 45\nสัดส่วน: TPAT3(15%), Math1(20%), Phy(20%), Chem(15%), Bio(5%), Soc(5%), Thai(5%), Eng(15%)");
                        } 
                        else if (selectedRound == "Admission") {
                                reply("เกณฑ์ขั้นต่ำ: TPAT3, Math1, Physics, English >= 45\nสัดส่วน: TGAT(20%), TPAT3(40%), Math1(20%), Phy(20%)");
                        } 
                        else { reply("โครงการนี้พิจารณาคะเเนนที่ยื่น เป็นหลักครับ"); }
                    }
                    else if (selectedMajor == "หุ่นยนต์และปัญญาประดิษฐ์") {
                        if (selectedRound == "Quota") {
                            reply("เกณฑ์ขั้นต่ำ: TPAT3, Math1, Physics, English >= 45\nสัดส่วน: TPAT3(15%), Math1(25%), Phy(20%), Chem(5%), Bio(5%), Soc(5%), Thai(10%), Eng(15%)");
                        } 
                        else if (selectedRound == "Admission") {
                            reply("เกณฑ์ขั้นต่ำ: TPAT3, Math1, Physics, English >= 45\nสัดส่วน: TGAT(20%), TPAT3(40%), Math1(20%), Phy(20%)");
                        } 
                        else if (selectedProject == "เรียนดี_Port_Robotics_Core" || selectedProject == "เรียนดี_Port_Robotics_Voc") {
                            reply("เกณฑ์ขั้นต่ำ: TPAT3 >= 45\nสัดส่วน: Portfolio(30%), TGAT1(10%), TGAT2(10%), TPAT3(50%)");
                        } 
                        else { reply("โครงการนี้พิจารณาคะเเนนที่ยื่น เป็นหลักครับ"); }
                    }
                    else if (selectedMajor == "บูรณาการ") {
                        if (selectedRound == "Quota") {
                            reply("เกณฑ์ขั้นต่ำ: TPAT3, Math1, Physics, English >= 45\nสัดส่วน: TPAT3(15%), Math1(20%), Phy(20%), Chem(15%), Bio(5%), Soc(5%), Thai(5%), Eng(15%)");
                        } 
                        else if (selectedRound == "Admission") {
                            reply("เกณฑ์ขั้นต่ำ: TPAT3, Math1, Physics, English >= 45\nสัดส่วน: TGAT(20%), TPAT3(40%), Math1(20%), Phy(20%)");
                        } 
                        else { reply("โครงการนี้พิจารณาคะเเนนที่ยื่น เป็นหลักครับ"); }
                    }
                }
                // --- เรื่องเอกสาร (ใช้ร่วมกันได้ทุกสาขา) ---
                else if (hasKeyword(input, "เอกสาร")) {
                    reply("เอกสารส่งออนไลน์เท่านั้น:\n1. ใบสมัคร\n2. สำเนาบัตรประชาชน\n3. ใบแสดงผลการเรียน\n4. Portfolio (ไม่เกิน 10 หน้า)\n5. หลักฐานผลงานตามที่โครงการกำหนด\n(วันสัมภาษณ์ใช้บัตรประชาชนตัวจริงครับ)");
                }
                // --- ปุ่มย้อนกลับ (เปลี่ยนโครงการ) ---
                else if (hasKeyword(input, "โครงการอื่น") || hasKeyword(input, "อื่น")) {
                    reply("ได้เลยครับ สนใจโครงการไหนเพิ่มเติมพิมพ์หมายเลขมาได้เลยครับ (พิมพ์ 'ออก' เพื่อกลับเมนูหลัก)");
                    currentState = ADM_STATE_SELECT_PROJECT;
                }
                // --- เผื่อผู้ใช้พิมพ์ผิด หรือถามนอกเหนือจากที่มี ---
                else {
                    reply("ลองถามคำว่า 'ค่าเทอม', 'เกรด', 'คะแนนสอบ', 'จำนวนรับ', 'เอกสาร', 'อาชีพ' หรือพิมพ์ 'โครงการอื่น' ดูนะครับ");
                }
                break;

// ============================================================================================================================== //
                                                    // ของภาคพิเศษ
            case ADM_STATE_SELECT_MAJOR_SPECIAL: 
                if (hasKeyword(input, "อุตสาหการ") || hasKeyword(input, "Industrial") || hasKeyword(input, "IE")|| hasKeyword(input, "ใช่")|| hasKeyword(input, "สนใจ")) {
                    selectedMajor = "อุตสาหการ";
                    reply("อยากสมัครวิศวกรรมอุตสาหการในรอบไหนครับ?\n2. Quota\n3. Admission \nภาคพิเศษเปิดรับเเต่ 2 รอบนี้ครับ");
                    currentState = ADM_STATE_SELECT_ROUND_SPECIAL;
                }
                break;
        
            case ADM_STATE_SELECT_ROUND_SPECIAL: 
                if (hasKeyword(input, "2") || hasKeyword(input, "Quota")) {
                    selectedRound = "Quota";
                    if (selectedMajor == "อุตสาหการ") reply("รอบ Quota สาขาอุตสาหการมี 1 โครงการครับ:\n1. โควตาภาคเหนือ\nสามารถพิมพ์ 1 เพื่อดูรายละเอียดได้ครับ?");
                    currentState = ADM_STATE_SELECT_PROJECT_SPECIAL;
                }
                else if (hasKeyword(input, "3") || hasKeyword(input, "Admission") || hasKeyword(input, "admission")) {
                    selectedRound = "Admission";
                    if (selectedMajor == "อุตสาหการ") reply("รอบ Admission สาขาอุตสาหการมี 1 โครงการครับ:\n1. รับตรงร่วมกัน\nสามารถพิมพ์ 1 เพื่อดูรายละเอียดได้ครับ?");
                    currentState = ADM_STATE_SELECT_PROJECT_SPECIAL;
                }
                break;

// ============================================================================================================================== //
            case ADM_STATE_SELECT_PROJECT_SPECIAL:
                if (selectedRound == "Quota") {
                    if (hasKeyword(input, "1") || hasKeyword(input, "ภาคเหนือ")) {
                        selectedProject = "ภาคเหนือ_Quota";
                        reply("โควตาภาคเหนือ:\n เรียน ม.6 สายวิทย์-คณิต ในโรงเรียนภาคเหนือ\n\nสนใจรายละเอียดอะไรเพิ่มไหมครับ?");
                        currentState = ADM_STATE_PROJECT_DETAILS_SPECIAL;
                    }
                }
                else if (selectedRound == "Admission") {
                    if (hasKeyword(input, "1") || hasKeyword(input, "รับตรง")) {
                        selectedProject = "รับตรง_Admin";
                        reply("รับตรงร่วมกัน:\n ใช้คะแนนสอบแข่งขัน ไม่ต้องใช้ Portfolio\n\nสนใจรายละเอียดอะไรเพิ่มไหมครับ?");
                        currentState = ADM_STATE_PROJECT_DETAILS_SPECIAL;
                    } else { reply("พิมพ์ 1 เพื่อดูรายละเอียดครับ"); }
                }
                break;
        
// ============================================================================================================================== //
            case ADM_STATE_PROJECT_DETAILS_SPECIAL:
                if (hasKeyword(input, "อาชีพ") || hasKeyword(input, "งาน") || hasKeyword(input, "ทำงานอะไร")) {
                    if (selectedMajor == "อุตสาหการ") reply("วิศวกรอุตสาหการ (Industrial Engineer), วิศวกรระบบ (Systems Engineer), วิศวกรคุณภาพ (Quality Engineer), วิศวกรซัพพลายเชน (Supply Chain Engineer), วิศวกรความปลอดภัย (Safety Engineer) ครับ");
                }
                else if (hasKeyword(input, "ค่าธรรมเนียม") || hasKeyword(input, "ค่าใช้จ่าย") || hasKeyword(input, "ค่าเทอม")) {
                    reply("ค่าธรรมเนียมการศึกษา ภาคการศึกษาแรก 35,000 บาท ครับ");
                }
                // --- เรื่องจำนวนรับ (เช็คตามสาขาและโปรเจกต์) ---
                else if (hasKeyword(input, "จำนวนรับเข้า") || hasKeyword(input, "จำนวนรับ") || hasKeyword(input, "จำนวน")) {
                    if (selectedMajor == "อุตสาหการ") {
                        if (selectedProject == "ภาคเหนือ_Quota") reply("จำนวนรับเข้า 10 คน ครับ");
                        else if (selectedProject == "รับตรง_Admin") reply("จำนวนรับเข้า 60 คน ครับ");
                    }
                }
                // --- เรื่องคุณสมบัติ ---
                else if (hasKeyword(input, "คุณสมบัติ")) {
                    if (selectedRound == "Admission") {
                        reply("รับผู้สำเร็จ ม.6, ปวช. หรือ กศน. ระดับมัธยมปลาย ครับ");
                    } else {
                        reply("โปรดดูรายละเอียดคุณสมบัติเพิ่มเติม ทางเว็บไซต์: https://admission.reg.cmu.ac.th/tcas/ ครับ");
                    }
                }
                // --- เรื่องคะแนนสอบ ---
                else if (hasKeyword(input, "คะเเนน") || hasKeyword(input, "คะแนนสอบ")) {
                    if (selectedMajor == "อุตสาหการ") {
                        if (selectedRound == "Quota") {
                            reply("เกณฑ์ขั้นต่ำ: TPAT3, Math1, Physics, English >= 45 ทุกวิชา\nสัดส่วน: TPAT3(20%), Math1(20%), Phy(20%), Chem(10%), Bio(5%), Soc(5%), Thai(5%), Eng(15%)");
                        } 
                        else if (selectedRound == "Admission") {
                            reply("เกณฑ์ขั้นต่ำ: TPAT3, Math1, Physics, English >= 35\nสัดส่วน: TGAT(20%), TPAT3(40%), Math1(20%), Phy(20%)");
                        } 
                        else { reply("ภาคพิเศษเปิดรับเข้าเพียง 2 รอบครับ"); }
                    }
                }
                // --- เรื่องเอกสาร ---
                else if (hasKeyword(input, "เอกสาร")) {
                    reply("เอกสารส่งออนไลน์เท่านั้น:\n1. ใบสมัคร\n2. สำเนาบัตรประชาชน\n3. ใบแสดงผลการเรียน\n4. Portfolio (ไม่เกิน 10 หน้า)\n5. หลักฐานผลงานตามที่โครงการกำหนด\n(วันสัมภาษณ์ใช้บัตรประชาชนตัวจริงครับ)");
                }
                // --- ปุ่มย้อนกลับ ---
                else if (hasKeyword(input, "โครงการอื่น") || hasKeyword(input, "อื่น")) {
                    reply("ได้เลยครับ สนใจโครงการไหนเพิ่มเติมพิมพ์หมายเลขมาได้เลยครับ (พิมพ์ 'ออก' เพื่อกลับเมนูหลัก)");
                    currentState = ADM_STATE_SELECT_PROJECT_SPECIAL;
                }
                else {
                    reply("ลองถามคำว่า 'ค่าเทอม', 'เกรด', 'คะแนนสอบ', 'จำนวนรับ', 'เอกสาร', 'อาชีพ' หรือพิมพ์ 'โครงการอื่น' ดูนะครับ");
                }
                break;

// ============================================================================================================================== //
                                                    // ของภาคนานาชาติ
            case ADM_STATE_SELECT_MAJOR_INTL: 
                if (hasKeyword(input, "วิศวกรรมเครื่องกลและการบริหารโครงการวิศวกรรม (นานาชาติ ช่องทาง TCAS)") || hasKeyword(input, "เครื่องกล") || hasKeyword(input, "Mechanical") || hasKeyword(input, "Mech")) {
                    selectedMajor = "เครื่องกลและการบริหารโครงการวิศวกรรม(นานาชาติ)";
                    reply("อยากสมัครวิศวกรรมเครื่องกลและการบริหารโครงการวิศวกรรมในรอบไหนครับ?\n1. Portfolio\n2. Quota\n3. Admission\n4. Direct Admission");
                    currentState = ADM_STATE_SELECT_ROUND_INTL;
                }
                else if (hasKeyword(input, "โยธา")  || hasKeyword(input, "Civil") || hasKeyword(input, "Civ") || hasKeyword(input, "โยธา(นานาชาติ)")) {
                    selectedMajor = "โยธา(นานาชาติ)";
                    reply("อยากสมัครวิศวกรรมโยธาในรอบไหนครับ?\n1. Portfolio\n2. Quota\n3. Admission\n4. Direct Admission");
                    currentState = ADM_STATE_SELECT_ROUND_INTL;
                }
                else if (hasKeyword(input, "อุตสาหการ") || hasKeyword(input, "Industrial") || hasKeyword(input, "Ind") || hasKeyword(input, "อุตสาหการ(นานาชาติ)")|| hasKeyword(input, "อุตสาหการและการจัดการโลจิสติกส์นานาชาติ)")) {
                    selectedMajor = "อุตสาหการและการจัดการโลจิสติกส์นานาชาติ(นานาชาติ)";
                    reply("อยากสมัครวิศวกรรมอุตสาหการในรอบไหนครับ?\n1. Portfolio\n2. Quota\n3. Admission\n4. Direct Admission");
                    currentState = ADM_STATE_SELECT_ROUND_INTL;
                }
                else if (hasKeyword(input, "ไฟฟ้า") || hasKeyword(input, "Electrical") || hasKeyword(input, "Ele") || hasKeyword(input, "ไฟฟ้า(นานาชาติ)")|| hasKeyword(input, "วิศวกรรมไฟฟ้าและเทคโนโลยีโครงข่ายไฟฟ้าอัจฉริยะ(นานาชาติ)")) {
                    selectedMajor = "วิศวกรรมไฟฟ้าและเทคโนโลยีโครงข่ายไฟฟ้าอัจฉริยะ(นานาชาติ)";
                    reply("อยากสมัครวิศวกรรมไฟฟ้าและเทคโนโลยีโครงข่ายไฟฟ้าอัจฉริยะในรอบไหนครับ?\n1. Portfolio\n2. Quota\n3. Admission\n4. Direct Admission");
                    currentState = ADM_STATE_SELECT_ROUND_INTL;
                }
                else if (hasKeyword(input, "ไซเบอร์") || hasKeyword(input, "Cyber") || hasKeyword(input, "Cybersecurity") || hasKeyword(input, "ระบบสารสนเทศ")) {
                    selectedMajor = "ระบบสารสนเทศและความมั่นคงปลอดภัยไซเบอร์(นานาชาติ)";
                    reply("อยากสมัครวิศวกรรมระบบสารสนเทศและความมั่นคงปลอดภัยไซเบอร์ในรอบไหนครับ?\n1. Portfolio\n2. Quota\n3. Admission\n4. Direct Admission");
                    currentState = ADM_STATE_SELECT_ROUND_INTL;
                }
                else if (hasKeyword(input, "สถาปัตยกรรม") || hasKeyword(input, "Architecture") || hasKeyword(input, "Design")) {
                    selectedMajor = "การออกแบบเชิงบูรณาการสถาปัตยกรรมแนวใหม่(นานาชาติ)";
                    reply("อยากสมัครวิศวกรรมการออกแบบเชิงบูรณาการสถาปัตยกรรมแนวใหม่ในรอบไหนครับ?\n1. Portfolio\n2. Quota\n3. Admission\n4. Direct Admission");
                    currentState = ADM_STATE_SELECT_ROUND_INTL;
                }
                else if (hasKeyword(input, "วิศวกรรมบูรณา") || hasKeyword(input, "multidisciplinary") || hasKeyword(input, "วิศวกรรมบูรณาการและพหุวิทยาการ(นานาชาติ)")) {
                    selectedMajor = "วิศวกรรมบูรณาการและพหุวิทยาการ(นานาชาติ)";
                    reply("วิศวกรรมบูรณาการและพหุวิทยาการเปิดรับเฉพาะรอบ Quota ครับ\nอยากสมัครวิศวกรรมบูรณาการและพหุวิทยาการในรอบ Quota ครับ?\n1. Portfolio\n2. Quota\n3. Admission\n4. Direct Admission");
                    currentState = ADM_STATE_SELECT_ROUND_INTL;
                }
                else {
                    reply("ลองพิมพ์ชื่อสาขาใหม่ดูนะครับ (เช่น โยธา)");
                }
                break;

// ============================================================================================================================== //
        
            case ADM_STATE_SELECT_ROUND_INTL: 
                if (hasKeyword(input, "1") || hasKeyword(input, "Portfolio")) {
                    selectedRound = "Portfolio";

                    if (selectedMajor == "เครื่องกลและการบริหารโครงการวิศวกรรม(นานาชาติ)") reply("รอบ Portfolio สาขาเครื่องกลและการบริหารโครงการวิศวกรรมมี 4 โครงการครับ:\n1. Women in Engineering\n2. ผลการเรียนดีเด่น \n3. ความสามารถพิเศษ\n4. ความสามารถทางภาษาอังกฤษ\nอยากสมัครโครงการไหนครับ? ");
                    else if (selectedMajor == "โยธา(นานาชาติ)") reply("รอบ Portfolio สาขาโยธามี 4 โครงการครับ:\n1. ความสามารถพิเศษ \n2. ผลการเรียนดีเด่น \n3. ผความสามารถทางภาษาอังกฤษ\n4. Women in Engineering\nอยากสมัครโครงการไหนครับ? (พิมพ์ตัวเลข)");
                    else if (selectedMajor == "อุตสาหการและการจัดการโลจิสติกส์นานาชาติ(นานาชาติ)") reply("รอบ Portfolio สาขาอุตสาหการและการจัดการโลจิสติกส์นานาชาติมี 4 โครงการครับ:\n1. ความสามารถพิเศษ \n2. ผลการเรียนดีเด่น \n3. ผความสามารถทางภาษาอังกฤษ\n4. Women in Engineering\nอยากสมัครโครงการไหนครับ?");
                    else if (selectedMajor == "วิศวกรรมไฟฟ้าและเทคโนโลยีโครงข่ายไฟฟ้าอัจฉริยะ(นานาชาติ)") reply("รอบ Portfolio สาขาวิศวกรรมไฟฟ้าและเทคโนโลยีโครงข่ายไฟฟ้าอัจฉริยะมี 4 โครงการครับ:\n1. ความสามารถทางภาษาอังกฤษ \n2. ความสามารถทางด้านอิเล็กทรอนิกส์ \n3. ผลการเรียนดีเด่น\n4. Women in Engineering\nอยากสมัครโครงการไหนครับ? ");
                    else if (selectedMajor == "ระบบสารสนเทศและความมั่นคงปลอดภัยไซเบอร์(นานาชาติ)") reply("รอบ Portfolio สาขาระบบสารสนเทศและความมั่นคงปลอดภัยไซเบอร์มี 4 โครงการครับ:\n1. อัจฉริยภาพทางคอมพิวเตอร์ \n2. ผมีความสามารถทางภาษาอังกฤษ  \n3. ผลการเรียนดีเด่น\n4. Women in Engineering\nอยากสมัครโครงการไหนครับ? ");
                    else if (selectedMajor == "การออกแบบเชิงบูรณาการสถาปัตยกรรมแนวใหม่(นานาชาติ)") reply("รอบ Portfolio สาขาการออกแบบเชิงบูรณาการสถาปัตยกรรมแนวใหม่มี 4 โครงการครับ:\n1. การรับด้วยแฟ้มสะสมผลงาน\nอยากสมัครโครงการไหนครับ? (พิมพ์ตัวเลข)");
                    
                    currentState = ADM_STATE_SELECT_PROJECT_INTL;
                }
                else if (hasKeyword(input, "2") || hasKeyword(input, "Quota")) {
                    selectedRound = "Quota";

                    if (selectedMajor == "เครื่องกลและการบริหารโครงการวิศวกรรม(นานาชาติ)") reply("รอบ Quota สาขาเครื่องกลและการบริหารโครงการวิศวกรรมมี 1 โครงการครับ:\n1. โควตาภาคเหนือ\nอยากสมัครโครงการไหนครับ? ");
                    else if (selectedMajor == "โยธา(นานาชาติ)") reply("รอบ Quota สาขาโยธามี 2 โครงการครับ:\n1. โควตาภาคเหนือ\nอยากสมัครโครงการไหนครับ? (พิมพ์ตัวเลข)");
                    else if (selectedMajor == "อุตสาหการและการจัดการโลจิสติกส์นานาชาติ(นานาชาติ)") reply("รอบ Quota สาขาอุตสาหการและการจัดการโลจิสติกส์นานาชาติมี 1 โครงการครับ:\n1. โควตาภาคเหนือ\nอยากสมัครโครงการไหนครับ? ");
                    else if (selectedMajor == "วิศวกรรมไฟฟ้าและเทคโนโลยีโครงข่ายไฟฟ้าอัจฉริยะ(นานาชาติ)") reply("รอบ Quota สาขาวิศวกรรมไฟฟ้าและเทคโนโลยีโครงข่ายไฟฟ้าอัจฉริยะมี 1 โครงการครับ:\n1. โควตาภาคเหนือ\nอยากสมัครโครงการไหนครับ? ");
                    else if (selectedMajor == "ระบบสารสนเทศและความมั่นคงปลอดภัยไซเบอร์(นานาชาติ)") reply("รอบ Quota สาขาระบบสารสนเทศและความมั่นคงปลอดภัยไซเบอร์มี 1 โครงการครับ:\n1. โควตาภาคเหนือ\nอยากสมัครโครงการไหนครับ? ");
                    else if (selectedMajor == "การออกแบบเชิงบูรณาการสถาปัตยกรรมแนวใหม่(นานาชาติ)") reply("รอบ Quota สาขาการออกแบบเชิงบูรณาการสถาปัตยกรรมแนวใหม่มี 1 โครงการครับ:\n1. โควตาภาคเหนือค่าเทอม ค่าเทอม 65000 บาท\nอยากสมัครโครงการไหนครับ? ");
                    else if (selectedMajor == "วิศวกรรมบูรณาการและพหุวิทยาการ(นานาชาติ)") reply("รอบ Quota สาขาวิศวกรรมบูรณาการและพหุวิทยาการมี 1 โครงการครับ:\n1. โควตาภาคเหนือค่าเทอม ค่าเทอม 50000 บาท\nอยากสมัครโครงการไหนครับ? ");

                    currentState = ADM_STATE_SELECT_PROJECT_INTL;
                }
                else if (hasKeyword(input, "3") || hasKeyword(input, "Admission") || hasKeyword(input, "admission")) {
                    selectedRound = "Admission";
                    if (selectedMajor == "เครื่องกลและการบริหารโครงการวิศวกรรม(นานาชาติ)") reply("รอบ Admission สาขาเครื่องกลและการบริหารโครงการวิศวกรรมมี 1 โครงการครับ:\n1. รับตรงร่วมกัน\nพิมพ์ 1 เพื่อดูรายละเอียดครับ");
                    else if (selectedMajor == "โยธา(นานาชาติ)") reply("รอบ Admission สาขาโยธามี 1 โครงการครับ:\n1. รับตรงร่วมกัน\nพิมพ์ 1 เพื่อดูรายละเอียดครับ");
                    else if (selectedMajor == "อุตสาหการและการจัดการโลจิสติกส์นานาชาติ(นานาชาติ)") reply("รอบ Admission สาขาอุตสาหการและการจัดการโลจิสติกส์นานาชาติมี 1 โครงการครับ:\n1. รับตรงร่วมกัน\nพิมพ์ 1 เพื่อดูรายละเอียดครับ");
                    else if (selectedMajor == "วิศวกรรมไฟฟ้าและเทคโนโลยีโครงข่ายไฟฟ้าอัจฉริยะ(นานาชาติ)") reply("รอบ Admission สาขาวิศวกรรมไฟฟ้าและเทคโนโลยีโครงข่ายไฟฟ้าอัจฉริยะมี 1 โครงการครับ:\n1. รับตรงร่วมกัน\nพิมพ์ 1 เพื่อดูรายละเอียดครับ");
                    else if (selectedMajor == "ระบบสารสนเทศและความมั่นคงปลอดภัยไซเบอร์(นานาชาติ)") reply("รอบ Admission สาขาระบบสารสนเทศและความมั่นคงปลอดภัยไซเบอร์มี 1 โครงการครับ:\n1. รับตรงร่วมกัน\nพิมพ์ 1 เพื่อดูรายละเอียดครับ");
                    else if (selectedMajor == "การออกแบบเชิงบูรณาการสถาปัตยกรรมแนวใหม่(นานาชาติ)") reply("รอบ Admission สาขาการออกแบบเชิงบูรณาการสถาปัตยกรรมแนวใหม่มี 1 โครงการครับ:\n1. รับตรงร่วมกัน\nพิมพ์ 1 เพื่อดูรายละเอียดครับ");

                    currentState = ADM_STATE_SELECT_PROJECT_INTL ;
                }
                else if (hasKeyword(input, "4") || hasKeyword(input, "Direct") || hasKeyword(input, "direct")) {
                    reply("โปรดติดตามคณะสาขาที่เปิด และคุณสมบัติการรับ TCAS รอบที่ 4 ปีการศึกษา 2569 อีกครั้งในวันที่ 28 พฤษภาคม 2569 ครับ\n(ลองดูรายละเอียดรอบอื่นๆ ในระหว่างนี้ได้นะครับ)");
                }
                else {
                    reply("สามารถพิมพ์ 'ออก' เพื่อกลับเมนูหลักครับ");
                }
                break;

// ============================================================================================================================== //
            case ADM_STATE_SELECT_PROJECT_INTL:
                if (selectedRound == "Portfolio") {
                    if (selectedMajor == "เครื่องกลและการบริหารโครงการวิศวกรรม(นานาชาติ)") {
                        if (hasKeyword(input, "1") || hasKeyword(input, "Women")|| hasKeyword(input, "หญิง")) {
                            selectedProject = "Women_Port_Mech_INL";
                            reply("โครงการWomen:\n กำลังเรียน ม.6 สายวิทย์-คณิต\n มีความสามารถพิเศษในด้านเพศหญิง\n\nสนใจรายละเอียดอะไรเพิ่มไหมครับ? (อาชีพ, ค่าเทอม, จำนวนรับ, เกรด, เอกสาร, อื่นๆ)");
                            currentState = ADM_STATE_PROJECT_DETAILS_INTL;
                        }
                        else if (hasKeyword(input, "2")     || hasKeyword(input, "ผลการเรียนดีเด่น") ) {
                            selectedProject = "ผลการเรียนดีเด่น_Port_Mech_INL";
                            reply("โครงการผลการเรียนดีเด่น:\n กำลังเรียน ม.6 สายวิทย์-คณิต\n GPAX ค่อนข้างสูง\n\nสนใจรายละเอียดอะไรเพิ่มไหมครับ?");
                            currentState = ADM_STATE_PROJECT_DETAILS_INTL;
                        }
                        else if (hasKeyword(input, "3") || hasKeyword(input, "ความสามารถพิเศษ")|| hasKeyword(input, "ผลงานพิเศษ")) {
                            selectedProject = "ความสามารถพิเศษ_Port_Mech_INL";
                            reply("โครงการความสามารถพิเศษ:\n กำลังเรียน ม.6 สายวิทย์-คณิต\n มีผลงานพิเศษ/นวัตกรรม\n\nสนใจรายละเอียดอะไรเพิ่มไหมครับ?");
                            currentState = ADM_STATE_PROJECT_DETAILS_INTL;
                        }
                        else if (hasKeyword(input, "4") || hasKeyword(input, "ความสามารถทางภาษาอังกฤษ")|| hasKeyword(input, "อังกฤษ")) {
                            selectedProject = "ความสามารถทางภาษาอังกฤษ_Port_Mech_INL";
                            reply("โครงการความสามารถทางภาษาอังกฤษ:\n กำลังเรียน ม.6 สายวิทย์-คณิต\n มีความสามารถทางภาษาอังกฤษ\n\nสนใจรายละเอียดอะไรเพิ่มไหมครับ?");
                            currentState = ADM_STATE_PROJECT_DETAILS_INTL;
                        }
                        else { reply("สาขาเครื่องกลและการบริหารโครงการวิศวกรรม(นานาชาติ)มี 4 โครงการ พิมพ์หมายเลข 1-4 ที่คุณสนใจดูครับ"); }
                    }
                    else if (selectedMajor == "โยธา(นานาชาติ)") {
                        if (hasKeyword(input, "1") || hasKeyword(input, "ความสามารถพิเศษ")) {
                            selectedProject = "ความสามารถพิเศษ_Port_Civil_INL";
                            reply("โครงการความสามารถพิเศษ:\n กำลังเรียน ม.6 สายวิทย์-คณิต\n มีผลงานพิเศษ/นวัตกรรม\n\nสนใจรายละเอียดอะไรเพิ่มไหมครับ?");
                            currentState = ADM_STATE_PROJECT_DETAILS_INTL;
                        }
                        else if (hasKeyword(input, "2") || hasKeyword(input, "ผลการเรียนดีเด่น")) {
                            selectedProject = "ผลการเรียนดีเด่น_Port_Civil_INL";
                            reply("โครงการผลการเรียนดีเด่น:\n กำลังเรียน ม.6 สายวิทย์-คณิต\n GPAX ค่อนข้างสูง\n\nสนใจรายละเอียดอะไรเพิ่มไหมครับ?");
                            currentState = ADM_STATE_PROJECT_DETAILS_INTL;
                        }
                        else if (hasKeyword(input, "3") || hasKeyword(input, "วิศวกรรม")) {
                            selectedProject = "ความสามารถทางภาษาอังกฤษ_Port_Civil_INL";
                            reply("โครงการความสามารถทางภาษาอังกฤษ:\n กำลังเรียน ม.6 สายวิทย์-คณิต\n มีความสามารถทางภาษาอังกฤษ\n\nสนใจรายละเอียดอะไรเพิ่มไหมครับ?");
                            currentState = ADM_STATE_PROJECT_DETAILS_INTL;
                        }
                        else if (hasKeyword(input, "4") || hasKeyword(input, "เรียนดี")) {
                            selectedProject = "Women_Port_Civil_INL";
                            reply("โครงการเพศหญิง:\n กำลังเรียน ม.6 สายวิทย์-คณิต\n มีความสามารถพิเศษในด้านเพศหญิง\n\nสนใจรายละเอียดอะไรเพิ่มไหมครับ?");
                            currentState = ADM_STATE_PROJECT_DETAILS_INTL;
                        }
                        else { reply("สาขาโยธา(นานาชาติ) มี 4 โครงการ พิมพ์หมายเลข 1-4 ที่คุณสนใจดูครับ"); }
                    }
                    else if (selectedMajor == "อุตสาหการและการจัดการโลจิสติกส์นานาชาติ(นานาชาติ)") {
                        if (hasKeyword(input, "1") || hasKeyword(input, "ความสามารถพิเศษ")) {
                            selectedProject = "ความสามารถพิเศษ_Port_Ind_INL";
                            reply("โครงการความสามารถพิเศษ:\n กำลังเรียน ม.6 สายวิทย์-คณิต\n มีผลงานพิเศษ/นวัตกรรม\n\nสนใจรายละเอียดอะไรเพิ่มไหมครับ?");
                            currentState = ADM_STATE_PROJECT_DETAILS_INTL;
                        }
                        else if (hasKeyword(input, "2") || hasKeyword(input, "ผลการเรียนดีเด่น")) {
                            selectedProject = "ผลการเรียนดีเด่น_Port_Ind_INL";
                            reply("โครงการผลการเรียนดีเด่น:\n กำลังเรียน ม.6 สายวิทย์-คณิต\n GPAX ค่อนข้างสูง\n\nสนใจรายละเอียดอะไรเพิ่มไหมครับ?");
                            currentState = ADM_STATE_PROJECT_DETAILS_INTL;
                        }
                        else if (hasKeyword(input, "3") || hasKeyword(input, "วิศวกรรม")) {
                            selectedProject = "ความสามารถทางภาษาอังกฤษ_Port_Ind_INL";
                            reply("โครงการความสามารถทางภาษาอังกฤษ:\n กำลังเรียน ม.6 สายวิทย์-คณิต\n มีความสามารถทางภาษาอังกฤษ\n\nสนใจรายละเอียดอะไรเพิ่มไหมครับ?");
                            currentState = ADM_STATE_PROJECT_DETAILS_INTL;
                        }
                        else if (hasKeyword(input, "4") || hasKeyword(input, "Women")) {
                            selectedProject = "Women_Port_Ind_INL";
                            reply("โครงการเพศหญิง:\n กำลังเรียน ม.6 สายวิทย์-คณิต\n มีความสามารถพิเศษในด้านเพศหญิง\n\nสนใจรายละเอียดอะไรเพิ่มไหมครับ?");
                            currentState = ADM_STATE_PROJECT_DETAILS_INTL;
                        }
                        else { reply("สาขาอุตสาหการและการจัดการโลจิสติกส์นานาชาติ(นานาชาติ) มี 4 โครงการ พิมพ์หมายเลข 1-4 ที่คุณสนใจดูครับ"); }
                    }
                    else if (selectedMajor == "ไฟฟ้าและเทคโนโลยีโครงข่ายไฟฟ้าอัจฉริยะ(นานาชาติ)") {
                        if (hasKeyword(input, "1") || hasKeyword(input, "ภาษาอังกฤษ")) {
                            selectedProject = "ความสามารถทางภาษาอังกฤษ_Port_Ele_INL";
                            reply("โครงการความสามารถทางภาษาอังกฤษ:\n กำลังเรียน ม.6 สายวิทย์-คณิต\n มีความสามารถทางภาษาอังกฤษ\n\nสนใจรายละเอียดอะไรเพิ่มไหมครับ?");
                            currentState = ADM_STATE_PROJECT_DETAILS_INTL;
                        }
                        else if (hasKeyword(input, "2") || hasKeyword(input, "อิเล็กทรอนิกส์")) {
                            selectedProject = "ความสามารถทางด้านอิเล็กทรอนิกส์_Port_Ele_INL";
                            reply("โครงการความสามารถทางด้านอิเล็กทรอนิกส์:\n กำลังเรียน ม.6 สายวิทย์-คณิต\n มีความสามารถทางด้านอิเล็กทรอนิกส์\n\nสนใจรายละเอียดอะไรเพิ่มไหมครับ?");
                            currentState = ADM_STATE_PROJECT_DETAILS_INTL;
                        }
                        else if (hasKeyword(input, "3") || hasKeyword(input, "ผลการเรียนดีเด่น")) {
                            selectedProject = "ผลการเรียนดีเด่น_Port_Ele_INL";
                            reply("โครงการผลการเรียนดีเด่น:\n กำลังเรียน ม.6 สายวิทย์-คณิต\n GPAX ค่อนข้างสูง\n\nสนใจรายละเอียดอะไรเพิ่มไหมครับ?");
                            currentState = ADM_STATE_PROJECT_DETAILS_INTL;
                        }
                        else if (hasKeyword(input, "4") || hasKeyword(input, "เWomen")) {
                            selectedProject = "Women_Port_Ele_INL";
                            reply("โครงการเพศหญิง:\n กำลังเรียน ม.6 สายวิทย์-คณิต\n มีความสามารถพิเศษในด้านเพศหญิง\n\nสนใจรายละเอียดอะไรเพิ่มไหมครับ?");
                            currentState = ADM_STATE_PROJECT_DETAILS_INTL;
                        }
                        else { reply("สาขาวิศวกรรมไฟฟ้าและเทคโนโลยีโครงข่ายไฟฟ้าอัจฉริยะ(นานาชาติ) มี 4 โครงการ พิมพ์หมายเลข 1-4 ที่คุณสนใจดูครับ"); }
                    }
                    else if (selectedMajor == "ระบบสารสนเทศและความมั่นคงปลอดภัยไซเบอร์(นานาชาติ)") {
                        if (hasKeyword(input, "1") || hasKeyword(input, "อัจฉริยภาพทางคอมพิวเตอร์")|| hasKeyword(input, "อัจฉริยภาพ")) {
                            selectedProject = "อัจฉริยภาพทางคอมพิวเตอร์_Port_Cyber_INL";
                            reply("โครงการอัจฉริยภาพทางคอมพิวเตอร์:\n กำลังเรียน ม.6 สายวิทย์-คณิต\n มีความสามารถทางอัจฉริยภาพทางคอมพิวเตอร์\n\nสนใจรายละเอียดอะไรเพิ่มไหมครับ?");
                            currentState = ADM_STATE_PROJECT_DETAILS_INTL;
                        }
                        else if (hasKeyword(input, "2") || hasKeyword(input, "ภาษาอังกฤษ")|| hasKeyword(input, "อังกฤษ")) {
                            selectedProject = "มีความสามารถทางภาษาอังกฤษ_Port_Cyber_INL";
                            reply("โครงการความสามารถทางภาษาอังกฤษ:\n กำลังเรียน ม.6 สายวิทย์-คณิต\n มีความสามารถทางภาษาอังกฤษ\n\nสนใจรายละเอียดอะไรเพิ่มไหมครับ?");
                            currentState = ADM_STATE_PROJECT_DETAILS_INTL;
                        }
                        else if (hasKeyword(input, "3") || hasKeyword(input, "ผลการเรียนดีเด่น")) {
                            selectedProject = "ผลการเรียนดีเด่น_Port_Cyber_INL";
                            reply("โครงการผลการเรียนดีเด่น:\n กำลังเรียน ม.6 สายวิทย์-คณิต\n GPAX ค่อนข้างสูง\n\nสนใจรายละเอียดอะไรเพิ่มไหมครับ?");
                            currentState = ADM_STATE_PROJECT_DETAILS_INTL;
                        }
                        else if (hasKeyword(input, "4") || hasKeyword(input, "Women")) {
                            selectedProject = "Women_Port_Cyber_INL";
                            reply("โครงการเพศหญิง:\n กำลังเรียน ม.6 สายวิทย์-คณิต\n มีความสามารถพิเศษในด้านเพศหญิง\n\nสนใจรายละเอียดอะไรเพิ่มไหมครับ?");
                            currentState = ADM_STATE_PROJECT_DETAILS_INTL;
                        }
                        else { reply("สาขาวิศวกรรมโซนสาขา ระบบสารสนเทศและความมั่นคงปลอดภัยไซเบอร์(นานาชาติ) มี 4 โครงการ พิมพ์หมายเลข 1-4 ที่คุณสนใจดูครับ"); }
                    }
                    else if (selectedMajor == "การออกแบบเชิงบูรณาการสถาปัตยกรรมแนวใหม่(นานาชาติ)") {
                        if (hasKeyword(input, "1") || hasKeyword(input, "แฟ้มสะสมผลงาน") || hasKeyword(input, "Portfolio")) {
                            selectedProject = "การรับด้วยแฟ้มสะสมผลงาน_Port_Arch_INL";
                            reply("โครงการการรับด้วยแฟ้มสะสมผลงาน:\n กำลังเรียน ม.6 สายวิทย์-คณิต\n มีแฟ้มสะสมผลงานที่แสดงถึงความสามารถทางด้านการออกแบบ\n\nสนใจรายละเอียดอะไรเพิ่มไหมครับ?");
                            currentState = ADM_STATE_PROJECT_DETAILS_INTL;
                        }
                        else { reply("สาขาการออกแบบเชิงบูรณาการสถาปัตยกรรมแนวใหม่(นานาชาติ) มี 1 โครงการ พิมพ์หมายเลข 1 ที่คุณสนใจดูครับ"); }
                    }
                }
                else if (selectedRound == "Quota") {
                    if (hasKeyword(input, "1") || hasKeyword(input, "ภาคเหนือ")) {
                        selectedProject = "ภาคเหนือ_Quota_INL";
                        reply("โควตาภาคเหนือ:\n เรียน ม.6 สายวิทย์-คณิต ในโรงเรียนภาคเหนือ\n\nสนใจรายละเอียดอะไรเพิ่มไหมครับ?");
                        currentState = ADM_STATE_PROJECT_DETAILS_INTL;
                    }
                    else if (hasKeyword(input, "3") || hasKeyword(input, "นอกเขต") || hasKeyword(input, "โควตานอกเขต 17 จังหวัดภาคเหนือ")) {
                        selectedProject = "นอกเขต_Quota_Cyber_INL";
                        reply("โควตาการรับนักเรียนนอกเขต:\n เรียน ม.6 สายวิทย์-คณิต\n เป็นนักเรียนนอกเขต 17 จังหวัดภาคเหนือ\n\nสนใจรายละเอียดอะไรเพิ่มไหมครับ?");
                        currentState = ADM_STATE_PROJECT_DETAILS_INTL;
                    }
                }
                else if (selectedRound == "Admission") {
                    if (hasKeyword(input, "1") || hasKeyword(input, "รับตรง")) {
                        selectedProject = "รับตรง_Admin_INL";
                        reply("รับตรงร่วมกัน:\n ใช้คะแนนสอบแข่งขัน ไม่ต้องใช้ Portfolio\n\nสนใจรายละเอียดอะไรเพิ่มไหมครับ?");
                        currentState = ADM_STATE_PROJECT_DETAILS_INTL;
                    } else { reply("พิมพ์ 1 เพื่อดูรายละเอียดครับ"); }
                }
                break;
        
// ============================================================================================================================== //
            case ADM_STATE_PROJECT_DETAILS_INTL:
                if (hasKeyword(input, "อาชีพ") || hasKeyword(input, "งาน") || hasKeyword(input, "ทำงานอะไร")) {
                    if (selectedMajor == "เครื่องกลและการบริหารโครงการวิศวกรรม(นานาชาติ)") reply("วิศวกรนักออกแบบเครื่องจักรกล (Machine Design Engineer), วิศวกรซ่อมบำรุงเครื่องจักร (Maintenance Engineer), วิศวกรพลังงาน (Energy Engineer), วิศวกรระบบอัตโนมัติ (Automation Engineer), วิศวกรบริหารโครงการ (Project Engineer) ครับ");
                    else if (selectedMajor == "โยธา(นานาชาติ)") reply("วิศวกรโยธา (Civil Engineer), วิศวกรโครงสร้าง (Structural Engineer), วิศวกรสิ่งแวดล้อม (Environmental Engineer), วิศวกรจราจร (Traffic Engineer), วิศวกรบริหารโครงการก่อสร้าง (Construction Project Engineer) ครับ");
                    else if (selectedMajor == "อุตสาหการและการจัดการโลจิสติกส์นานาชาติ(นานาชาติ)") reply("วิศวกรโรงงาน, วิศวกรฝ่ายควบคุมคุณภาพ, วิศวกรควบคุมกระบวนการผลิต , วิศวกรโลจิสติกส์, วิศวกรความปลอดภัย ครับ");
                    else if (selectedMajor == "วิศวกรรมไฟฟ้าและเทคโนโลยีโครงข่ายไฟฟ้าอัจฉริยะ(นานาชาติ)") reply("วิศวกรไฟฟ้ากำลัง, วิศวกรไฟฟ้าสื่อสารและโทรคมนาคม , วิศวกรอิเล็กทรอนิกส์ด้านการออกแบบและผลิตชิ้นส่วนอิเล็กทรอนิกส์, วิศวกรด้านสมองกลฝังตัวและปัญญาประดิษฐ์, วิศวกรด้านการวิเคราะห์และออกแบบระบบไฟฟ้ ครับ");
                    else if (selectedMajor == "ระบบสารสนเทศและความมั่นคงปลอดภัยไซเบอร์(นานาชาติ)") reply("Information Systems Administrator, IT Consultant / IT Engineer, System Engineer / System Analyst, Network Engineer / Computer Network Architect, Cybersecurity Professionals ครับ");
                    else if (selectedMajor == "การออกแบบเชิงบูรณาการสถาปัตยกรรมแนวใหม่(นานาชาติ)") reply("การออกแบบสถาปัตยกรรม, การทำงานวิชาชีพสร้างสรรค์แนวคิด, การนำเสนองานออกแบบ โฆษณา, การออกแบบผลิตภัณฑ์, การออกแบบสื่อสร้างสรรค์ ครับ");
                    else if (selectedMajor == "วิศวกรรมบูรณาการและพหุวิทยาการ(นานาชาติ)") reply("วิศวกร, ผู้ประกอบการ/เจ้าของธุรกิจ, อาจารย์, นักวิจัย, นักประดิษฐ์อิสระ ครับ");
                }
                else if (hasKeyword(input, "ค่าธรรมเนียม") || hasKeyword(input, "ค่าใช้จ่าย") || hasKeyword(input, "ค่าเทอม")) {
                    reply("ค่าธรรมเนียมการศึกษา ภาคการศึกษาแรก 50,000 บาท ครับ");
                }
                else if (hasKeyword(input, "ค่าธรรมเนียมไซเบอร์ ") || hasKeyword(input, "ค่าใช้จ่ายไซเบอร์ ") || hasKeyword(input, "ค่าเทอมไซเบอร์")) {
                    reply("ค่าธรรมเนียมการศึกษา ภาคการศึกษาแรก 80,000 บาท ครับ");
                }
                // --- เรื่องจำนวนรับ (เช็คตามสาขาและโปรเจกต์) ---
                else if (hasKeyword(input, "จำนวนรับเข้า") || hasKeyword(input, "จำนวนรับ") || hasKeyword(input, "จำนวน")|| hasKeyword(input, "รับ")|| hasKeyword(input, "เข้า")) {
                     if (selectedMajor == "เครื่องกลและการบริหารโครงการวิศวกรรม(นานาชาติ)") {
                        if (selectedProject == "Women_Port_Mech_INL" ) reply("แบบ 1.1: 3 คน\nแบบ 1.2: 0 คน ครับ");
                        else if (selectedProject == "เรียนดี_Port_Mech_INL") reply("แบบ 1.1: 6 คน\nแบบ 1.2: 2 คน ครับ");
                        else if (selectedProject == "พิเศษ_Port_Mech_INL") reply("แบบ 1.1: 4 คน\nแบบ 1.2: 0 คน ครับ");
                        else if (selectedProject == "ภาษาอังกฤษ_Port_Mech_Ind") reply("แบบ 1.1: 3 คน\nแบบ 1.2: 0 คน ครับ");
                        else if (selectedProject == "ภาคเหนือ_Quota_INL") reply("จำนวนรับเข้า 15 คน ครับ");
                        else if (selectedProject == "รับตรง_Admin_INL") reply("จำนวนรับเข้า 10 คน ครับ");
                    }
                    else if (selectedMajor == "โยธา(นานาชาติ)") {
                        if (selectedProject == "ความสามารถพิเศษ_Port_Civil_INL") reply("แบบ 1.1: 3 คน\nแบบ 1.2: 0 คน ครับ");
                        else if (selectedProject == "ผลการเรียนดีเด่น_Port_Civil_INL") reply("แบบ 1.1: 5 คน\nแบบ 1.2: 0 คน ครับ");
                        else if (selectedProject == "ความสามารถทางภาษาอังกฤษ_Port_Civil_INL") reply("แบบ 1.1: 3 คน\nแบบ 1.2: 0 คน ครับ");
                        else if (selectedProject == "Women_Port_Civil_INL") reply("แบบ 1.1: 3 คน\nแบบ 1.2: 0 คน ครับ");
                        else if (selectedProject == "ภาคเหนือ_Quota_Civil_INL") reply("จำนวนรับเข้า 15 คน ครับ");
                        else if (selectedProject == "รับตรง_Admin_Civil_INL") reply("จำนวนรับเข้า 10 คน ครับ");
                    }
                    else if (selectedMajor == "อุตสาหการและการจัดการโลจิสติกส์นานาชาติ(นานาชาติ)") {
                        if (selectedProject == "ความสามารถพิเศษ_Port_Ind_INL") reply("แบบ 1.1: 4 คน\nแบบ 1.2: 0 คน ครับ");
                        else if (selectedProject == "ผลการเรียนดีเด่น_Port_Ind_INL") reply("แบบ 1.1: 6 คน\nแบบ 1.2: 2 คน ครับ");
                        else if (selectedProject == "ความสามารถทางภาษาอังกฤษ_Port_Ind_INL") reply("แบบ 1.1: 3 คน\nแบบ 1.2: 0 คน ครับ");
                        else if (selectedProject == "Women_Port_Ind_INL") reply("แบบ 1.1: 3 คน\nแบบ 1.2: 0 คน ครับ");
                        else if (selectedProject == "ภาคเหนือ_Quota_Ind_INL") reply("จำนวนรับเข้า 15 คน ครับ");
                        else if (selectedProject == "รับตรง_Admin_Ind_INL") reply("จำนวนรับเข้า 10 คน ครับ");
                    }
                    else if (selectedMajor == "วิศวกรรมไฟฟ้าและเทคโนโลยีโครงข่ายไฟฟ้าอัจฉริยะ(นานาชาติ)") {
                        if (selectedProject == "ความสามารถทางภาษาอังกฤษ_Port_Ele_INL") reply("แบบ 1.1: 3 คน\nแบบ 1.2: 0 คน ครับ");
                        else if (selectedProject == "ความสามารถทางด้านอิเล็กทรอนิกส์_Port_Ele_INL") reply("แบบ 1.1: 4 คน\nแบบ 1.2: 0 คน ครับ");
                        else if (selectedProject == "ผลการเรียนดีเด่น_Port_Ele_INL") reply("แบบ 1.1:  8 คน\nแบบ 1.2: 0 คน ครับ");
                        else if (selectedProject == "Women_Port_Ele_INL") reply("แบบ 1.1: 3 คน\nแบบ 1.2: 0 คน ครับ");
                        else if (selectedProject == "ภาคเหนือ_Quota_Ele_INL") reply("จำนวนรับเข้า 15 คน ครับ");
                        else if (selectedProject == "รับตรง_Admin_Ele_INL") reply("จำนวนรับเข้า 10 คน ครับ");
                    }
                    else if (selectedMajor == "ระบบสารสนเทศและความมั่นคงปลอดภัยไซเบอร์(นานาชาติ)") {
                        if (selectedProject == "อัจฉริยภาพทางคอมพิวเตอร์_Port_Cyber_INL") reply("แบบ 1.1: 3 คน\nแบบ 1.2: 1 คน ครับ");
                        else if (selectedProject == "มีความสามารถทางภาษาอังกฤษ_Port_Cyber_INL") reply("แบบ 1.1: 3 คน\nแบบ 1.2: 1 คน ครับ");
                        else if (selectedProject == "ผลการเรียนดีเด่น_Port_Cyber_INL") reply("แบบ 1.1: 3 คน\nแบบ 1.2: 1 คน ครับ");
                        else if (selectedProject == "Women_Port_Cyber_INL") reply("แบบ 1.1: 3 คน\nแบบ 1.2: 1 คน ครับ");
                        else if (selectedProject == "ภาคเหนือ_Quota_Cyber_INL") reply("จำนวนรับเข้า 15 คน ครับ");
                        else if (selectedProject == "นอกเขต_Quota_Cyber_INL") reply("จำนวนรับเข้า 8 คน ครับ");
                        else if (selectedProject == "รับตรง_Admin_Cyber_INL") reply("จำนวนรับเข้า 8 คน ครับ");
                    }
                    else if (selectedMajor == "การออกแบบเชิงบูรณาการสถาปัตยกรรมแนวใหม่(นานาชาติ)") {
                        if (selectedProject == "การรับด้วยแฟ้มสะสมผลงาน_Port_Arch_INL") reply("แบบ 1.1: 5 คน\nแบบ 1.2: 0 คน ครับ");
                        else if (selectedProject == "โควตาภาคเหนือ_Quota_Arch_INL") reply("แบบ 1.1: 3 คน\nแบบ 1.2: 0 คน ครับ");
                        else if (selectedProject == "รับตรง_Admin_Arch_INL") reply("จำนวนรับเข้า 5 คน ครับ");
                    }
                    else if (selectedMajor == "วิศวกรรมบูรณาการและพหุวิทยาการ(นานาชาติ)") {
                        if (selectedProject == "โควตาภาคเหนือ_Quota_Multi_INL") reply("จำนวนรับเข้า 10 คน ครับ");
                    }
                }
// ============================================================================================================================== //
                else if (hasKeyword(input, "เกรด") || hasKeyword(input, "ผลการเรียน")) {
                    if (selectedProject == "นักกีฬา_Port") reply("GPAX 5 เทอม ไม่น้อยกว่า 3.00");
                    else if (selectedProject == "วมว_Port" || selectedProject == "พิเศษ_Port") reply("GPAX 5 เทอม ไม่น้อยกว่า 3.25");
                    else if (selectedProject == "เรียนดี_Port") reply("GPAX 5 เทอม ไม่น้อยกว่า 3.50");
                    else if (selectedProject == "วิศวกรรม_Port") reply("ต้องผ่านหลักสูตรอบรมระยะสั้น Entaneer Academy เกรดไม่น้อยกว่า B จำนวน 3 วิชา");
                    else if (selectedRound == "Quota" || selectedRound == "Admission") reply("ใช้คะแนนสอบ TGAT / TPAT หรือ A-Level ในการยื่นสมัครครับ");

                    if (selectedProject == "Women_Port_INL" ) reply("GPAX 5 เทอม ไม่น้อยกว่า 3.25");
                    else if (selectedProject == "เรียนดี_Port_Mech_INL") reply("GPAX 5 เทอม ไม่น้อยกว่า 3.50 ครับ");
                    else if (selectedProject == "พิเศษ_Port_Mech_INL") reply("GPAX 5 เทอม ไม่น้อยกว่า 3.50 ครับ");
                    else if (selectedProject == "ภาษาอังกฤษ_Port_Mech_Ind") reply("GPAX 5 เทอม ไม่น้อยกว่า 3.00 ครับ");
                    
                    else if (selectedProject == "ความสามารถพิเศษ_Port_Civil_INL") reply("GPAX 5 เทอม ไม่น้อยกว่า 3.00 ครับ");
                    else if (selectedProject == "ผลการเรียนดีเด่น_Port_Civil_INL") reply("GPAX 5 เทอม ไม่น้อยกว่า 3.50 ครับ");
                    else if (selectedProject == "ความสามารถทางภาษาอังกฤษ_Port_Civil_INL") reply("GPAX 5 เทอม ไม่น้อยกว่า 3.00 ครับ");
                    else if (selectedProject == "Women_Port_Civil_INL") reply("GPAX 5 เทอม ไม่น้อยกว่า 3.25 ครับ");
                    
                    else if (selectedProject == "ความสามารถพิเศษ_Port_Ind_INL") reply("GPAX 5 เทอม ไม่น้อยกว่า 3.00 ครับ");
                    else if (selectedProject == "ผลการเรียนดีเด่น_Port_Ind_INL") reply("GPAX 5 เทอม ไม่น้อยกว่า 3.50 ครับ");
                    else if (selectedProject == "ความสามารถทางภาษาอังกฤษ_Port_Ind_INL") reply("GPAX 5 เทอม ไม่น้อยกว่า 3.00 ครับ");
                    else if (selectedProject == "Women_Port_Ind_INL") reply("GPAX 5 เทอม ไม่น้อยกว่า 3.25 ครับ");   
                
                    else if (selectedProject == "ความสามารถทางภาษาอังกฤษ_Port_Ele_INL") reply("GPAX 5 เทอม ไม่น้อยกว่า 3.25 ครับ");
                    else if (selectedProject == "ความสามารถทางด้านอิเล็กทรอนิกส์_Port_Ele_INL") reply("GPAX 5 เทอม ไม่น้อยกว่า 3.25 ครับ");
                    else if (selectedProject == "ผลการเรียนดีเด่น_Port_Ele_INL") reply("GPAX 5 เทอม ไม่น้อยกว่า 3.50 ครับ");
                    else if (selectedProject == "Women_Port_Ele_INL") reply("GPAX 5 เทอม ไม่น้อยกว่า 3.25 ครับ");

                    else if (selectedProject == "อัจฉริยภาพทางคอมพิวเตอร์_Port_Cyber_INL") reply("GPAX 5 เทอม ไม่น้อยกว่า 3.00 ครับ");
                    else if (selectedProject == "มีความสามารถทางภาษาอังกฤษ_Port_Cyber_INL") reply("GPAX 5 เทอม ไม่น้อยกว่า 3.00 ครับ");
                    else if (selectedProject == "ผลการเรียนดีเด่น_Port_Cyber_INL") reply("GPAX 5 เทอม ไม่น้อยกว่า 3.00 ครับ");
                    else if (selectedProject == "Women_Port_Cyber_INL") reply("GPAX 5 เทอม ไม่น้อยกว่า 3.00 ครับ");
                    
                    else if (selectedProject == "การรับด้วยแฟ้มสะสมผลงาน_Port_Arch_INL") reply("GPAX 5 เทอม ไม่น้อยกว่า 3.00 ครับ");
                    else { reply("โปรดดูรายละเอียดเกรดเพิ่มเติม ทางเว็บไซต์: https://admission.reg.cmu.ac.th/tcas/ ครับ"); }
                }
// ============================================================================================================================== //
                // --- เรื่องคุณสมบัติ ---
                else if (hasKeyword(input, "คุณสมบัติ")) {
                    if (selectedRound == "Admission") {
                        reply("รับผู้สำเร็จ ม.6, ปวช. หรือ กศน. ระดับมัธยมปลาย ครับ");
                    } else {
                        reply("โปรดดูรายละเอียดคุณสมบัติเพิ่มเติม ทางเว็บไซต์: https://admission.reg.cmu.ac.th/tcas/ ครับ");
                    }
                }
                // --- เรื่องคะแนนสอบ ---
                else if (hasKeyword(input, "คะเเนน") || hasKeyword(input, "คะแนนสอบ")) {
                    if (selectedMajor == "เครื่องกลและการบริหารโครงการวิศวกรรม(นานาชาติ)") {
                        if (selectedRound == "Quota") {
                            reply("เกณฑ์ขั้นต่ำ: TPAT3, Math1, Physics >= 45\nEnglish >= 50\nสัดส่วน: TPAT3(20%), Math1(20%), Phy(20%), Chem(5%), Bio(5%), Soc(5%), Thai(5%), Eng(20%)");
                        } 
                        else if (selectedRound == "Admission") {
                            reply("เกณฑ์ขั้นต่ำ: TPAT3, Math1, Physics >= 45\nEnglish >= 50\nสัดส่วน: TGAT(10%), TPAT3(30%), Math1(20%), Phy(20%) , Eng(20%)");
                        } 
                    }
                    else if (selectedMajor == "โยธา(นานาชาติ)") {
                        if (selectedRound == "Quota") {
                                reply("เกณฑ์ขั้นต่ำ: TPAT3, Math1, Physics >= 45\nEnglish >= 50\nสัดส่วน: TPAT3(20%), Math1(20%), Phy(20%), Chem(11%), Bio(3%), Soc(3%), Thai(3%), Eng(20%)");
                        } 
                        else if (selectedRound == "Admission") {
                                reply("เกณฑ์ขั้นต่ำ: TPAT3, Math1, Physics >= 45\nEnglish >= 50\nสัดส่วน: TGAT(10%), TPAT3(30%), Math1(20%), Phy(20%) , Eng(20%)");
                        } 
                        else { reply("โครงการนี้พิจารณาจากผลงานและ Portfolio เป็นหลักครับ"); }
                    }
                    else if (selectedMajor == "อุตสาหการและการจัดการโลจิสติกส์นานาชาติ(นานาชาติ)") {
                        if (selectedRound == "Quota") {
                            reply("เกณฑ์ขั้นต่ำ: TPAT3, Math1, Physics >= 45\nEnglish >= 50\nสัดส่วน: TPAT3(20%), Math1(20%), Phy(20%), Chem(11%), Bio(3%), Soc(3%), Thai(3%), Eng(20%)");
                        } 
                        else if (selectedRound == "Admission") {
                            reply("เกณฑ์ขั้นต่ำ: TPAT3, Math1, Physics >= 45\nEnglish >= 50\nสัดส่วน: TGAT(10%), TPAT3(30%), Math1(20%), Phy(20%) , Eng(20%)");
                        } 
                        else { reply("โครงการนี้พิจารณาจากผลงานและ Portfolio เป็นหลักครับ"); }
                    }
                    else if (selectedMajor == "วิศวกรรมไฟฟ้าและเทคโนโลยีโครงข่ายไฟฟ้าอัจฉริยะ(นานาชาติ)") {
                        if (selectedRound == "Quota") {
                            reply("เกณฑ์ขั้นต่ำ: TPAT3, Math1, Physics >= 45\nEnglish >= 50\nสัดส่วน: TPAT3(20%), Math1(20%), Phy(20%), Chem(5%), Bio(5%), Soc(5%), Thai(5%), Eng(20%)");
                        } 
                        else if (selectedRound == "Admission") {
                            reply("เกณฑ์ขั้นต่ำ: TPAT3, Math1, Physics >= 45\nEnglish >= 50\nสัดส่วน: TGAT(10%), TPAT3(30%), Math1(20%), Phy(20%) , Eng(20%)");
                        } 
                        else { reply("โครงการนี้พิจารณาจากผลงานและ Portfolio เป็นหลักครับ"); }
                    }
                    else if (selectedMajor == "ระบบสารสนเทศและความมั่นคงปลอดภัยไซเบอร์(นานาชาติ)") {
                        if (selectedRound == "Quota") {
                            reply("เกณฑ์ขั้นต่ำ: TPAT3, Math1, Physics >= 45\nEnglish >= 50\nสัดส่วน: TPAT3(20%), Math1(20%), Phy(20%), Chem(5%), Bio(5%), Soc(5%), Thai(5%), Eng(20%)");
                        } 
                        else if (selectedRound == "Admission") {
                            reply("เกณฑ์ขั้นต่ำ: TPAT3, Math1, Physics >= 45\nEnglish >= 50\nสัดส่วน: TGAT(10%), TPAT3(30%), Math1(20%), Phy(20%) , Eng(20%)");
                        } 
                        else { reply("โครงการนี้พิจารณาจากผลงานและ Portfolio เป็นหลักครับ"); }
                    }
                    else if (selectedMajor == "การออกแบบเชิงบูรณาการสถาปัตยกรรมแนวใหม่(นานาชาติ)") {
                        if (selectedRound == "Quota") {
                            reply("เกณฑ์ขั้นต่ำ:  TPAT 4 , Math1 >= 45, Physics >= 40, Chem >= 35, Bio >= 35, Soc >= 35, Thai >= 35, Eng >= 50\nสัดส่วน: TPAT4(36%), Math1(18%), Phy(18%), Chem(2%), Bio(2%), Soc(2%), Thai(2%), Eng(20%)");
                        } 
                        else if (selectedRound == "Admission") {
                            reply("เกณฑ์ขั้นต่ำ: TPAT 4 , Math1 >= 45, Physics >= 40, Eng >= 50\nEnglish >= 50\nสัดส่วน:, TPAT4(40%), Math1(20%), Phy(20%) , Eng(20%)");
                        } 
                        else { reply("โครงการนี้พิจารณาจากผลงานและ Portfolio เป็นหลักครับ"); }
                    }
                    else if (selectedMajor == "วิศวกรรมบูรณาการและพหุวิทยาการ(นานาชาติ)") {
                        if (selectedRound == "Quota") {
                            reply("เกณฑ์ขั้นต่ำ: TPAT3, Math1, Physics >= 45\nEnglish >= 50\nสัดส่วน: TPAT3(15%), Math1(25%), Phy(20%), Chem(5%), Bio(5%), Soc(5%), Thai(5%), Eng(20%)");
                        } 
                        else { reply("วิศวกรรมบูรณาการและพหุวิทยาการเปิดรับเเค่รอบ Quota ครับ"); }
                    }
                }
// ============================================================================================================================== //
                // --- เรื่องเอกสาร ---
                else if (hasKeyword(input, "เอกสาร")) {
                    reply("เอกสารส่งออนไลน์เท่านั้น:\n1. ใบสมัคร\n2. สำเนาบัตรประชาชน\n3. ใบแสดงผลการเรียน\n4. Portfolio (ไม่เกิน 10 หน้า)\n5. หลักฐานผลงานตามที่โครงการกำหนด\n(วันสัมภาษณ์ใช้บัตรประชาชนตัวจริงครับ)");
                }
                // --- ปุ่มย้อนกลับ ---
                else if (hasKeyword(input, "โครงการอื่น") || hasKeyword(input, "อื่น")) {
                    reply("ได้เลยครับ สนใจโครงการไหนเพิ่มเติมพิมพ์หมายเลขมาได้เลยครับ (พิมพ์ 'ออก' เพื่อกลับเมนูหลัก)");
                    currentState = ADM_STATE_SELECT_PROJECT_INTL;
                }
                // --- เผื่อผู้ใช้พิมพ์ผิด ---
                else {
                    reply("ลองถามคำว่า 'ค่าเทอม', 'เกรด', 'คะแนนสอบ', 'จำนวนรับ', 'เอกสาร', 'อาชีพ' หรือพิมพ์ 'โครงการอื่น' ดูนะครับ");
                }
                break;
        } // ปิดคำสั่ง switch(currentState)
        return true; 
    }
};