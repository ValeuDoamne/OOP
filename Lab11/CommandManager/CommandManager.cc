#include "CommandManager.h"
#include "MyException.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

void CommandManager::run()
{

	std::string command_line;
	while(std::getline(cin, command_line))
	{
		std::vector<std::string> args;
		std::string command;
		std::string word;
		std::istringstream iss(command_line);
		

		std::getline(iss, command, ' ');

		while(std::getline(iss, word, ' '))
			args.push_back(word);
		
		try{
			commands[command](args);
		} catch (const OpenFileException& e)
		{
			cerr << "Exception: " << e.what() << std::endl;
		} catch (const ReadFileException& e)
		{
			cerr << "Exception: " << e.what() << std::endl;
		} catch (const WriteFileException& e)
		{
			cerr << "Exception: " << e.what() << std::endl;
		}
	}
}

void CommandManager::add(string name, function<void(vector<string>)> fn) {
    commands[name] = fn;
}
