#include <cctype>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>

bool cmp(std::pair<std::string, int>& a, std::pair<std::string, int>& b)
{
	if(a.second > b.second)
		return true;
	else if(a.second == b.second)
	{
		if(a.first > b.first) 
			return true;
		else return false; 
	}
	return false;
}

std::vector<std::pair<std::string, int>> map_sort(std::map<std::string, int>& my_map)
{
	

	std::vector<std::pair<std::string, int> > arr;
	for (const auto &item : my_map) {
		arr.emplace_back(item);
	}

	std::sort(arr.begin(), arr.end(), cmp);

	std::map<std::string, int> new_map;
	for(unsigned int i = 0; i < arr.size(); i ++)
	{
		new_map.emplace(arr[i]); 
	}
	return arr;
}

int main()
{
	std::ifstream fin("file.txt");
	std::string s, delim = " ,.!?";

	getline(fin, s);
	
	std::vector <std::string> words;
	std::stringstream stream(s);  

	std::string s2;  
	for(size_t i = 0; i < delim.size(); i++){
		while(getline(stream, s2, delim[i]))  
			words.push_back(s2);
	}

	for(auto &s : words){
		transform(s.begin(), s.end(), s.begin(), ::tolower);
	}

	std::map<std::string, int> words_and_count;

	for(auto word : words)
	{
		words_and_count[word] = std::count(words.begin(), words.end(), word);
	}
	
	auto sorted_map = map_sort(words_and_count);

	for(auto entry : sorted_map)
	{
		std::cout << "\"" << entry.first << "\" => " << entry.second << std :: endl;
	}
		
	return 0;
}
