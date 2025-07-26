/*
 * Copyright (c) ghgltggamer 2025
 * Written by ghgltggamer
 * Licensed under the MIT License
 * Checkout the README.md for more information about the project
 * LLAW - Open Linux Local Ai Wrapper Around LLama.cpp
*/

// Standard Libraries
#include <algorithm>
#include <chrono>
#include <iostream>
#include <fstream>
#include <ratio>
#include <string>
#include <thread>

// Local libraries
#include <htmlui/HTMLUI.h>
#include <llaw-ui/llaw-ui.hh>
#include <casci/casci.hh>
#include <linuxtools/linuxtools.hh>
#include <hell6.99mo/lib/cxx/Model0/ModelO-HELL6.99.hh>

int main(){
    // Convert the CASCI Data back to the
    CASCI Casci_Ui_Html_Data (llaw::ui); 
    std::string ui_html_code = Casci_Ui_Html_Data.decrypt("0");

    std::string output_file_directory_path = linuxtools::get_home_directory() + "/.config/llaw/";
    std::cout << output_file_directory_path<<"\n";
    std::system (std::string ("mkdir -p " + output_file_directory_path).c_str());
    std::string output_file_path = output_file_directory_path + "/output.txt";
    std::string settings_file_path = output_file_directory_path + "/settings.cfg";


    // Ai Brain Manager
    std::string user_name = "Annonymous",
                model_path = "../model/model.gguf",
                user_bio = "Annonymous",
                user_gender = "Annonymous",
                user_origin = "Annonymous",
                user_hobies = "Annonymous",
                ai_type = "Casual",
                ai_gender = "Female",
                ai_name = "Open Linux Local Ai",
                ai_author = "Author is unknown because it depends on the model",
                llaw_prompts = "you are running on Open Linux Local Ai Wrapper Around Llama.cpp (LLAW) which is giving you this behaviour, And the (LLAW) is an open source project under MIT License made by darkyboys/ghgltggamer but now is managed by the Open Source Community, Github repository is : https://github.com/darkyboys/llaw and this chat is completely private and stored in the RAM , And no one can see you and your client so feel free to talk.";



    // Config Loader
    std::ifstream settings_ifile (settings_file_path);
    if (!settings_ifile){
        HELL6_99MO Settings_File (settings_file_path);
        Settings_File.new_key ("user.name", "string");
        Settings_File.new_key ("user.bio", "string");
        Settings_File.new_key ("user.hobby", "string");
        Settings_File.new_key ("user.gender", "string");
        Settings_File.new_key ("user.origin", "string");
        Settings_File.new_key ("ai.type", "string");
        Settings_File.new_key ("ai.gender", "string");
        Settings_File.new_key ("ai.name", "string");
        Settings_File.new_key ("ai.author", "string");
        Settings_File.new_key ("llaw.prompts", "string");
        Settings_File.new_key ("model.path", "string");

        Settings_File.set ("user.name", user_name);
        Settings_File.set ("user.bio", user_bio);
        Settings_File.set ("user.hobby", user_hobies);
        Settings_File.set ("user.gender", user_gender);
        Settings_File.set ("user.origin", user_origin);
        Settings_File.set ("ai.type", ai_type);
        Settings_File.set ("ai.gender", ai_gender);
        Settings_File.set ("ai.name", ai_name);
        Settings_File.set ("ai.author", ai_author);
        Settings_File.set ("model.path", model_path);
        Settings_File.set ("llaw.prompts", llaw_prompts);
        Settings_File.write (settings_file_path);
    }
    else {
        HELL6_99MO Settings_File (settings_file_path);
        Settings_File.Parse();
        HELL6_99MO_TYPE userName = Settings_File.get("user.name");
        if (userName.type == "string")
            user_name = userName.string_value;

        HELL6_99MO_TYPE userBio = Settings_File.get("user.bio");
        if (userBio.type == "string")
            user_bio = userBio.string_value;

        HELL6_99MO_TYPE userHobby = Settings_File.get("user.hobby");
        if (userHobby.type == "string")
            user_hobies = userHobby.string_value;

        HELL6_99MO_TYPE userOrigin = Settings_File.get("user.origin");
        if (userOrigin.type == "string")
            user_origin = userOrigin.string_value;

        HELL6_99MO_TYPE userGender = Settings_File.get("user.gender");
        if (userGender.type == "string")
            user_gender = userGender.string_value;

        HELL6_99MO_TYPE aiType = Settings_File.get("ai.type");
        if (aiType.type == "string")
            ai_type = aiType.string_value;

        HELL6_99MO_TYPE aiName = Settings_File.get("ai.name");
        if (aiName.type == "string")
            ai_name = aiName.string_value;

        HELL6_99MO_TYPE aiGender = Settings_File.get("ai.gender");
        if (aiGender.type == "string")
            ai_gender = aiGender.string_value;

        HELL6_99MO_TYPE aiAuthor = Settings_File.get("ai.author");
        if (aiAuthor.type == "string")
            ai_author = aiAuthor.string_value;

        HELL6_99MO_TYPE modelPath = Settings_File.get("model.path");
        if (modelPath.type == "string")
            model_path = modelPath.string_value;

        HELL6_99MO_TYPE llawPrompts = Settings_File.get("llaw.prompts");
        if (llawPrompts.type == "string")
            llaw_prompts = llawPrompts.string_value;
    }



    // Render the ui
    HTMLUI MainWindow ("Open Linux Local Ai Wrapper Around LLama.cpp By Darkyboys", 800, 400);
    MainWindow.loadHTML (ui_html_code);

    // Load the settings
    std::string Settings_JavaScript_Execution_One_Time = "document.getElementById('user_name').value = `" + user_name + "`;\n"
                                                         "document.getElementById('user_gender').value = `" + user_gender + "`;\n"
                                                         "document.getElementById('user_origin').value = `" + user_origin + "`;\n"
                                                         "document.getElementById('user_hobies').value = `" + user_hobies + "`;\n"
                                                         "document.getElementById('user_bio').value = `" + user_bio + "`;\n"
                                                         "document.getElementById('ai_type').value = `" + ai_type + "`;\n"
                                                         "document.getElementById('ai_name').value = `" + ai_name + "`;\n"
                                                         "document.getElementById('ai_author').value = `" + ai_author + "`;\n"
                                                         "document.getElementById('llaw_prompts').value = `" + llaw_prompts + "`;\n"
                                                         "document.getElementById('model_path').value = `" + model_path + "`;\n"
                                                         "document.getElementById('ai_gender').value = `" + ai_gender + "`;\n";
    MainWindow.executeJS (Settings_JavaScript_Execution_One_Time);

    // Backend API
    std::string on_chat_memory;
    MainWindow.registerFunction ("makeResponse", [&](std::string prompt){
        std::string sended_prompt = linuxtools::to_bash(prompt);
        std::cout << "Prompt: "<<sended_prompt << "\n";
        std::thread ([&](){
            on_chat_memory += "[User]: " + sended_prompt + ".";
            std::string system_command_stack = "<<SYS>>This is a system prompt by the LLAW C++ Runtime, This section will contain all the instructions you must follow during your response generation. Setting metadata: (This data is given to you by the LLAW Runtime and you must follow this!) user name: " + user_name + ", user bio: " + user_bio + ", user origin: " + user_origin + ", user gender: " + user_gender + ", user hobbies: " + user_hobies + ", Your behaviour section! ai type: " + ai_type + ", ai name: " + ai_name + ", ai gender: " + ai_gender + ", ai author: " + ai_author + ", Important instructions!!: " + llaw_prompts + ". This section ends here, Memory: (These are the previous messages of the user already responded by you, So continue the message from here) : " + on_chat_memory + "<</SYS>>[END] User Prompt: ";
            std::system(std::string("chmod +x llama-cli\n./llama-cli -m " + model_path + " -t 6 -p \"[INST] " + system_command_stack + sended_prompt + "[/INST]\" 2>/dev/null > " + output_file_path).c_str());
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            for (unsigned int memory = 0;on_chat_memory.length() > 2000;memory+=10){ // memory trimmer
                on_chat_memory = on_chat_memory.substr(memory);
            }
        }).detach();

        // std::thread ([&](){
        //     std::system ();
        // });


        std::this_thread::sleep_for(std::chrono::milliseconds(200));

        std::thread([&]() {
            std::string content;
            int run = 1;
            std::string ai_response;
            while (run) {
                std::this_thread::sleep_for(std::chrono::milliseconds(200));
                std::string file_content, file_content_buffer;
                std::ifstream output_txt(output_file_path);
                if (!output_txt.is_open()) {
                    MainWindow.executeJS("alert ('Error --> Can\\'t open the output path, Please make sure to resolve the dependencies first!');freeInput();");
                    run = 0;
                } else {
                    while (std::getline(output_txt, file_content_buffer))
                        file_content += file_content_buffer + '\n';

                    if (file_content.empty()) {
                        continue; // Wait for first real write
                    }
                    if (file_content == content && file_content.find("[end of text]") != std::string::npos) {
                        std::ofstream ofile (output_file_path);
                        run = 0;
                    } else {
                        // std::cout << "[Updated Content]\n" << content << "\n"; // for debugging only
                        std::size_t found_inst = file_content.find("[/INST]");
                        if (found_inst == std::string::npos){
                            found_inst = 0;
                        }
                        std::string js_content = file_content.substr(found_inst+7);
                        content = file_content;
                        // for (unsigned long long i = 0;i < js_content.length();i++){
                        //     if (js_content[i] == '`' and js_content[i-1] != '\\'){
                        //         js_content.replace(i, i+1, "\\`");
                        //     }
                        // }
                        js_content = linuxtools::replaceAll(js_content, "`", "\\`");

                        std::string javaScript = "writeResponse (`" + js_content + "`);";
                        ai_response = js_content;
                        // std::cout << js_content;
                        // std::cout << file_content;
                        MainWindow.executeJS (javaScript);
                    }
                }
            }

            std::cout << "The loop ended!\n";
            // std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            // on_chat_memory += "[user]: " + sended_prompt + "[ai response]" + ai_response + ".";
            MainWindow.executeJS("currentUserMessage = '';freeInput();");
            // MainWindow.executeJS("freeInput();");
        }).detach();
    });




    MainWindow.registerFunction ("cfgSetUserName", [&](std::string message){
        user_name = message;
    });

    MainWindow.registerFunction ("AppendOnChatMemory", [&](std::string message){
        on_chat_memory = message;
    });

    MainWindow.registerFunction ("cfgSetUserGender", [&](std::string message){
        user_gender = message;
    });

    MainWindow.registerFunction ("cfgSetUserOrigin", [&](std::string message){
        user_origin = message;
    });

    MainWindow.registerFunction ("cfgSetUserHobby", [&](std::string message){
        user_hobies = message;
    });

    MainWindow.registerFunction ("cfgSetUserBio", [&](std::string message){
        user_bio = message;
    });

    MainWindow.registerFunction ("cfgSetAiName", [&](std::string message){
        ai_name = message;
    });

    MainWindow.registerFunction ("cfgSetAiType", [&](std::string message){
        ai_type = message;
    });

    MainWindow.registerFunction ("cfgSetAiGender", [&](std::string message){
        ai_gender = message;
    });

    MainWindow.registerFunction ("cfgSetAiAuthor", [&](std::string message){
        ai_author = message;
    });

    MainWindow.registerFunction ("cfgSetModelPath", [&](std::string message){
        model_path = message;
    });

    MainWindow.registerFunction ("cfgSetLlawPrompts", [&](std::string message){
        llaw_prompts = message;
    });

    MainWindow.registerFunction ("cfgWrite", [&](std::string message){
        // Config Loader
        HELL6_99MO Settings_File (settings_file_path);
        Settings_File.new_key ("user.name", "string");
        Settings_File.new_key ("user.bio", "string");
        Settings_File.new_key ("user.hobby", "string");
        Settings_File.new_key ("user.gender", "string");
        Settings_File.new_key ("user.origin", "string");
        Settings_File.new_key ("ai.type", "string");
        Settings_File.new_key ("ai.gender", "string");
        Settings_File.new_key ("ai.name", "string");
        Settings_File.new_key ("ai.author", "string");
        Settings_File.new_key ("llaw.prompts", "string");
        Settings_File.new_key ("model.path", "string");
        Settings_File.set ("user.name", user_name);
        Settings_File.set ("user.bio", user_bio);
        Settings_File.set ("user.hobby", user_hobies);
        Settings_File.set ("user.gender", user_gender);
        Settings_File.set ("user.origin", user_origin);
        Settings_File.set ("ai.type", ai_type);
        Settings_File.set ("ai.gender", ai_gender);
        Settings_File.set ("ai.name", ai_name);
        Settings_File.set ("ai.author", ai_author);
        Settings_File.set ("model.path", model_path);
        Settings_File.set ("llaw.prompts", llaw_prompts);
        Settings_File.write (settings_file_path);
    });

    MainWindow.run();

}