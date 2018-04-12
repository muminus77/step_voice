#include <step_voice/Voice.h>
#include <iostream>

int main(int argc, char **argv) 
{
	ros::init(argc, argv, "voice_node");
    bool test=false;
    if(argc==2)
    {
        if(strcmp(argv[1],"test") == 0)
        {
            std::cout << argv[1] << "\n";
            test=true;
        }
    }
    Voice voice_interpreter;
	ros::Rate loop_rate(20);
    std::string text_to_speak="";
    while(ros::ok())// &&
	{
        if(test)
        {
            std::getline (std::cin,text_to_speak);
            voice_interpreter.male_voice->SayIt(0, text_to_speak);
            if(text_to_speak=="stop")
                break;
        }

		ros::spinOnce();
		loop_rate.sleep();
	}
}
