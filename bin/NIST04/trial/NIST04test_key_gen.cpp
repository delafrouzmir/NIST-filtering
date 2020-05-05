#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

ifstream fin ("key-v2.txt");
ifstream gin1 ("1conv.key");
ifstream gin2 ("1side.key");
ifstream gin3 ("10sec.key");
ifstream gin4 ("30sec.key");
ofstream fout ("NIST04test.key");

vector <pair<string,string> > lines;

int main(){
	fout << "model_name,model_id,segment_id,language,source,channel,segment_type,speaker_id,gender,segment_len,dialect,mic_type,phone_type" << endl;
	
	string line;
	string segment;
	string printable;

	while ( getline(fin,line) ){
		int j=0;
		while ( j< line.length() && line[j]!=' ')
			++j;
		lines.push_back(make_pair(line.substr(0,j),line));
	}

	while ( getline(gin1,line) ){
		int j=0;
		while ( j< line.length() && line[j]!=' ')
			++j;
		printable = "1conv "+line.substr(0,j);
		++j;
		while ( j< line.length() && line[j]!=' ')
			++j;
		++j;
		segment = line.substr(j,line.length());
		
		int l=0;
		while ( l<lines.size() && lines[l].first!=segment )
			++l;
		while ( l<lines.size() && lines[l].first==segment ){
			fout << printable << ' ' << lines[l].second << endl;
			++l;
		}
	}

	while ( getline(gin2,line) ){
		int j=0;
		while ( j< line.length() && line[j]!=' ')
			++j;
		printable = "1side "+line.substr(0,j);
		++j;
		while ( j< line.length() && line[j]!=' ')
			++j;
		++j;
		segment = line.substr(j,line.length());
		
		int l=0;
		while ( l<lines.size() && lines[l].first!=segment )
			++l;
		while ( l<lines.size() && lines[l].first==segment ){
			fout << printable << ' ' << lines[l].second << endl;
			++l;
		}
	}

	while ( getline(gin3,line) ){
		int j=0;
		while ( j< line.length() && line[j]!=' ')
			++j;
		printable = "10sec "+line.substr(0,j);
		++j;
		while ( j< line.length() && line[j]!=' ')
			++j;
		++j;
		segment = line.substr(j,line.length());
		
		int l=0;
		while ( l<lines.size() && lines[l].first!=segment )
			++l;
		while ( l<lines.size() && lines[l].first==segment ){
			fout << printable << ' ' << lines[l].second << endl;
			++l;
		}
	}

	while ( getline(gin4,line) ){
		int j=0;
		while ( j< line.length() && line[j]!=' ')
			++j;
		printable = "30sec "+line.substr(0,j);
		++j;
		while ( j< line.length() && line[j]!=' ')
			++j;
		++j;
		segment = line.substr(j,line.length());
		
		int l=0;
		while ( l<lines.size() && lines[l].first!=segment )
			++l;
		while ( l<lines.size() && lines[l].first==segment ){
			fout << printable << ' ' << lines[l].second << endl;
			++l;
		}
	}

	return 0;
}
