/**
 @file       Voice.cpp
 @author		Marcin Umiński
 @version
 @date        12-09-2016
 @brief      

 */

#include <step_voice/Voice.h>

Voice::Voice():
    nh_priv("~")
{
    voice_sub=nh.subscribe("step_command", 10, &Voice::VoiceReceived, this);

    male_voice = new spirit::RobotVoice(spirit::RobotVoice::POLISH);
    //female_voice = new spirit::RobotVoice(spirit::RobotVoice::FEMALE);


    _package_path = ros::package::getPath(ROS_PACKAGE_NAME);

    _gender=MALE_VOICE;
    _speech=LOUD;

    male_voice->SayIt(0, "Dzień dobry");
}

Voice::~Voice()
{

}

void Voice::VoiceReceived(const std_msgs::String &voice)
{
    male_voice->SayIt(0, voice.data);
//    if (!voice.data.empty())
//    {
//            if(divideVoice(voice.data))
//            {
//                for(int i=0; i<words_number; i++)
//                    std::cout << voice_words[i]<<"\t";
//                std::cout << "Recognized\n";
//                reactToVoice();
//            }

//            else
//                std::cout <<" Not recognized\n";

//    }
//    else
//    {
//           std::cout << "No words\n";
//    }
}



void Voice::loadText(std::string path, std::string &line)
{
    std::ifstream myfile (path.c_str());
    if (myfile.is_open())
    {
        std::getline (myfile,line);
        myfile.close();
    }
    else std::cout << "Unable to open file\n";
}

void Voice::setGender(int gender)
{
    this->_gender=gender;
}

void Voice::setSpeech(int speech)
{
    this->_speech=speech;
}
