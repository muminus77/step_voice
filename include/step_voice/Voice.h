/**
 @file        Voice.h
 @author		Marcin Umiński
 @version
 @date        12-09-2016
 @brief	      Voice recognition and speaking

 */


#ifndef Voice_h
#define Voice_h

#include <ros/ros.h>
#include <ros/package.h>
#include <iostream>
#include <fstream>
#include <string>
#include "std_msgs/String.h"
#include <step_voice/enum_comm.h>
#include <geometry_msgs/Twist.h>
#include <step_voice_libs/voice.h>

enum gender{
    MALE_VOICE,
    FEMALE_VOICE,
};
enum speech{
    LOUD,
    WHISPER,
};

class Voice
{
	public:
        Voice();
        ~Voice();
        ros::NodeHandle nh;
        ros::NodeHandle nh_priv;
        ros::Subscriber voice_sub;

        /**
         * @brief receives the transripter voice from pocketsphinx
         */
        void VoiceReceived(const std_msgs::String &voice);


        /**
         * @brief loads text saved in given file to given string
         */
        void loadText(std::string path, std::string &line);

        void setGender(int gender);

        void setSpeech(int speech);

        spirit::RobotVoice *male_voice;


        private:        

        int _gender;
        int _speech;

        std::string _package_path;

        spirit::RobotVoice *female_voice;

};

#endif
