#ifndef TTS_H
#define TTS_H
#include <string>

enum Source {
    FROM_TEXT = 0,
    FROM_FILE,
};

class TextToSpeech {
      private:
        std::string m_lang = "-l=";
        std::string m_picoExec = "/usr/bin/pico2wave";
        std::string m_soxExec = "/usr/bin/sox"; 
        std::string m_rmExec = "/usr/bin/rm"; 
        std::string m_out = "/tmp/picoTmp.wav";
        std::string m_in = "";
        std::string m_new = "/tmp/new.wav";
        std::string m_text = "";
        std::string m_speed = "1.0";
        std::string m_pitch = "0";
        Source m_source;
        int m_pid;
        int m_status; 
        void checkLanguage(std::string& lang); 

    public:
        TextToSpeech(std::string lang, std::string speed, std::string pitch, std::string output, std::string input, Source from);
        ~TextToSpeech();
        void setSpeedAndPitch();
        bool checkProgram(const std::string cmd); 
        void clearTmp();
        void createAudio();
        void createAudio(std::string text);
        void loadText(std::string filePath); 
        void process();
        void work();
};

#endif //TTS_H