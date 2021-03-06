/**
 * @file main.cpp
 * @author DennisMi (https://www.dennisthink.com/)
 * @brief ImRobot的主程序文件
 * @version 0.1
 * @date 2019-12-18
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "CommonFunction.h"
#include "CImRobot.h"
int main(int argc, char** argv) {
	
	if (argc > 1)
	{
		std::string strcfg, errinfo;
		load_txtfile(argv[1], strcfg);
		if (!strcfg.length()) {
			printf("no Configure\n");
			return 1;
		}
		CIMRobot robot;
		
		if (robot.loadConfig(strcfg))
		{
			robot.Run();
		}
		else
		{
			printf("Load Config Failed\r\n");
		}
	}
	return 0;
}
