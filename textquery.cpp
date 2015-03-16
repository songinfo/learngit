/*************************************************************************
	> File Name: textquery.cpp
	> Author: Chao
	> Mail:1311159643@qq.com 
	> Created Time: Mon 16 Mar 2015 09:27:09 AM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<fstream>
#include<string>
#include<sstream>
#include<iterator>
#include<cstdlib>
#include<stdio.h>
//#include<>

class TextQuery
{
public:
	//typedef to make declarations easier
	typedef std::vector<std::string>::size_type line_no;
	/*interface
	 * read_file builds internal data structures for the given file
	 * run_query finds the given word and returns set of lines on which it appears
	 * text_file returns a requested line from the input file
	 */
void read_file(std::ifstream &is)
{
	store_file(is); 
	build_map();
}
std::set<line_no> run_query(const std::string&) const;
std::string text_line(line_no) const;

private:
//utility functions used by read_file
void store_file(std::ifstream&);  //store input file
void build_map(); //associated each word with a set of line numbers
//remember the whole input file
std::vector<std::string> lines_of_text;
//map word to set of the lines on which it occurs
std::map<std::string, std::set<line_no> > word_map;
};

std::ifstream& open_file(std::ifstream &in, const std::string & file);
//progeam takes single argument specifying the file to query 
void print_results(const std::set<TextQuery::line_no>& locs, const std::string & sought, const TextQuery &file);
int main(int argc, char **argv)
{
//open the file from which user will query words
	std::ifstream infile;
if(argc < 2 || !open_file(infile, argv[1]))
{
	std::cerr << "No input file !" << std::endl;
	return -1;
}
TextQuery tq;
tq.read_file(infile);//builds query map
//iterate with the user :prompt for a word to find and print results
//loop indefinitely ;the loop exit is inside the while
 while(true)
{
	std::cout << "enter word to look for, or q to quit: ";
	std::string s;
	std::cin >> s;
	//stop if hit eof on input or a 'q' is entered 
	if(!std::cin || s == "q")
		break;
	//get the set of line numbers on which this word appears
	std::set<TextQuery::line_no> locs = tq.run_query(s);
	//print count and all occurences , if any
	print_results(locs, s, tq);
}

return 0;
}
std::string make_plural(size_t ctr, const std::string &word, const std::string ending)
{
return (ctr == 1) ? word : word + ending;
}
void print_results(const std::set<TextQuery::line_no>& locs, const std::string & sought, const TextQuery &file)
{
//if the word was found , then print count and all occurrences 
typedef std::set <TextQuery::line_no> line_nums;
line_nums::size_type size = locs.size();
std::cout << "\n" << sought 
	    << std::endl 
	    << "occurs "
	      << size << " "
		  << make_plural(size, "time", "s") << std::endl;
// print each line in which the word appeared
line_nums::const_iterator it = locs.begin();
for(; it != locs.end(); ++it)
{
	std::cout << "(line "
		      << (*it) + 1 << ")"
			  << file.text_line(*it) << std::endl;
}

}

//read input file: store each line as element in lines_of_text
void TextQuery::store_file(std::ifstream &is)
{
	std::string textline;
while(getline(is, textline))
{
lines_of_text.push_back(textline);
}

}

//finds whitespace_separated words in the input vector 
//and puts the the word_map along with the line number 
void TextQuery::build_map()
{
//process each line from the input vector
for(line_no line_num = 0;
		line_num != lines_of_text.size();
		++line_num)
{
//we'll use line to read the text a word at a time
	std::istringstream line(lines_of_text[line_num]);
	std::string word;
while(line >> word)
	word_map[word].insert(line_num);
}

}

std::set<TextQuery::line_no>
TextQuery::run_query(const std::string &query_word) const
{
	std::map<std::string,std::set<line_no> >::const_iterator
	loc = word_map.find(query_word);
if(loc == word_map.end())
	return std::set<line_no>();
else
	return loc->second;


}
std::string TextQuery::text_line(line_no line) const
{
if(line < lines_of_text.size())
{
	return lines_of_text[line];
}
//throw out_of_range("line number out of range");
}

std::ifstream& open_file(std::ifstream &in, const std::string & file)
{
in.close();
in.clear();
in.open(file.c_str());
return in;
}




