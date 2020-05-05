#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

ifstream fin ("NIST04_TEST.key");
ofstream fout1 ("NIST04trial_langs.txt");
ofstream fout2 ("NIST04trial_channels.txt");
ofstream fout3 ("NIST04trial_dialect.txt");
ofstream fout4 ("NIST04trial_mic.txt");
ofstream fout5 ("NIST04trial_phone.txt");
ofstream fout6 ("NIST04trial_lengths.txt");

vector <string> langs;
vector <string> channels;
vector <string> dialects;
vector <string> mic_types;
vector <string> phone_types;
vector <double> lengths;
double big_leng;

void check_to_add_lang (string x){
	bool exist = false;
	for ( int i=0; i<langs.size(); ++i )
		if ( langs[i] == x )
			exist = true;
	if ( !exist )
		langs.push_back(x);
}
void check_to_add_channel (string x){
	bool exist = false;
	for ( int i=0; i<channels.size(); ++i )
		if ( channels[i] == x )
			exist = true;
	if ( !exist )
		channels.push_back(x);
}
void check_to_add_dia (string x){
	bool exist = false;
	for ( int i=0; i<dialects.size(); ++i )
		if ( dialects[i] == x )
			exist = true;
	if ( !exist )
		dialects.push_back(x);
}
void check_to_add_mic (string x){
	bool exist = false;
	for ( int i=0; i<mic_types.size(); ++i )
		if ( mic_types[i] == x )
			exist = true;
	if ( !exist )
		mic_types.push_back(x);
}
void check_to_add_phone (string x){
	bool exist = false;
	for ( int i=0; i<phone_types.size(); ++i )
		if ( phone_types[i] == x )
			exist = true;
	if ( !exist )
		phone_types.push_back(x);
}

void check_to_add_length (double x){
	bool exist = false;
	for ( int i=0; i<lengths.size(); ++i )
		if ( lengths[i] == x )
			exist = true;
	if ( !exist )
		lengths.push_back(x);
}

int main (){
	string line;
	string part;
	double leng;
	getline(fin,line);
	while ( getline(fin,line) ){

		istringstream iss(line);
		iss>>part;
		iss>>part;
		iss>>part;
		iss>>part;
		
		check_to_add_lang(part);

		iss>>part;
		iss>>part;

		check_to_add_channel(part);

		iss>>part;
		iss>>part;
		iss>>part;
		iss>>leng;
		
		if ( leng>big_leng )
			big_leng = leng;
		check_to_add_length(leng);

		iss>>part;

		check_to_add_dia(part);

		iss>>part;

		check_to_add_mic(part);

		iss>>part;

		check_to_add_phone(part);
		
	}
	for ( int i=0; i<langs.size(); ++i )
		fout1 << langs[i] << endl;
	
	for ( int i=0; i<channels.size(); ++i )
		fout2 << channels[i] << endl;
	
	for ( int i=0; i<dialects.size(); ++i )
		fout3 << dialects[i] << endl;
	
	for ( int i=0; i<mic_types.size(); ++i )
		fout4 << mic_types[i] << endl;
	
	for ( int i=0; i<phone_types.size(); ++i )
		fout5 << phone_types[i] << endl;
	cout << big_leng << endl;
	for ( int i=0; i<lengths.size(); ++i )
		fout6 << lengths[i] << endl;
	return 0;
}


