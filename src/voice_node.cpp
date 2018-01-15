#include <step_voice/Voice.h>
#include <iostream>


int main(int argc, char **argv) 
{
	ros::init(argc, argv, "voice_node");
         Voice voice_interpreter;
	ros::Rate loop_rate(20);
        std::string text_to_speak;
        std::cin >> text_to_speak;
    while(ros::ok() && text_to_speak!="stop")
	{
              std::getline (std::cin,text_to_speak);
            voice_interpreter.male_voice->SayIt(0, text_to_speak);
		ros::spinOnce();
		loop_rate.sleep();
	}
}
