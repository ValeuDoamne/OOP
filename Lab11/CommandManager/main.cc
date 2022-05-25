#include "CommandManager.h"
#include "MyException.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

// the CommandManager class should implement a mini terminal that receive commands and dispatches them.
// example: copy a.jpg b.jpg
// this will search the map for a "copy" command, and if it finds it, it will invoke its callback with a vector made of {"a.jpg", "b.jpg"}
// no global(or statics!) variables allowed




int main() {
    CommandManager manager;
    // number_of_errors represents the number of IO errors (eg. file errors) that happened in the commands
    // this is only relevant for the append and copy commands
    unsigned number_of_errors = 0;

    // prints pong!
    auto ping = [](vector<string> args) { printf("pong!\n"); };
    manager.add("ping", ping);

    // prints the number of arguments it received
    // `count a b c` -> will print `counted 3 args`
    // auto count = ...;
    auto count = [](vector<string> args) {printf("counted %d args\n", args.size());};
    manager.add("count", count);

    // the first argument will be treated as a file name
    // the rest of the arguments will be appended to that file with a space as delimiter
    // remember to count the errors, if any
    auto append = [](vector<string> args) { ofstream fout(args[0], std::ios_base::app); fout << " " << args[1]; fout.close(); };
    manager.add("append", append);

    // will print the number of times the command was called
    // do not capture any reference for this lambda
    auto times = [](vector<string> args) { static int times; printf("%d\n", times); times++;};
    manager.add("times", times);

    // copy a file; args[0] will provide the source, and args[1] the destination
    // make sure it works with binary files (test it with an image)
    // remember to count the errors, if any
    auto copy = [](vector<string> args) {
    	FILE *source = fopen(args[0].c_str(), "rb");
	if(source == NULL)
	{
		throw OpenFileException(args[0]);
	}
    	FILE *destination = fopen(args[1].c_str(), "wb");
	if(destination == NULL)
	{
		throw OpenFileException(args[1]);
	}
	char buffer[1024];
	while(!feof(source)){
		int ret;
		ret = fread(buffer, 1024, 1, source);
		if(ret == 0)
			throw ReadFileException(args[0]);

		ret = fwrite(buffer, 1024, 1, destination);
		if(ret == 0)
			throw WriteFileException(args[1]);
	}
	fclose(source);
	fclose(destination);
    };
    manager.add("copy", copy);

    // will sort the arguments by size
    // `sort_size abc a 1234` -> will print `a abc 1234`
    // use std::sort with a lambda comparator to sort
    // and std::for_each with a lambda to print afterwards
    auto sort_size = [](vector<string> args){
	auto sort_function = [](const string& s1,const string& s2)
	{
		return s1.length() < s2.length();
	};
	sort(args.begin(), args.end(), sort_function);
	for(auto x : args)
		cout << x << " ";
	cout << " ";
    };
    manager.add("sort_size", sort_size);

    // add one more command of anything you'd like
    try{
    	manager.run();
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

    printf("number of errors: %u\ndone!\n", number_of_errors);
}

