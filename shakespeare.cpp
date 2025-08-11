#include <string>
using namespace std;

#include "Bridges.h"
#include "DataSource.h"
#include "data_src/Shakespeare.h"
#include <map>
using namespace bridges;
// Function that is used to clean the word by two steps:
// 1. Non-alphanumeric characters are removed 
// 2. All letters are converted to lowercase
string cleanWord(string word){
    string cleaned= " ";
    for (int i=0;i<word.length(); i++){
        if(isalnum(word[i])){// Keeps only the letters and digits
            cleaned+=tolower(word[i]);// Converts to lowercase
        }
    }
    return cleaned;
}
// Recursive function that counts word frequencies
// Words: pointer to vector of words
// Index: current index in the vector
// Freq: map to store word counts
void countwords(vector<string>* words,int index,map<string,int>& freq) {
    // Base case: stop when there aren't any words lrft
    if ((int)words->size()-index == 0){
        return;
    }
string cleaned=cleanWord((*words)[index]);// Cleans the current word
//Increments the frequency if the word isn't empty
if (cleaned!=" "){
    freq[cleaned]=freq[cleaned]+1;
}
// Recursive call for the next word 
countwords(words,index+1,freq);
}

// This program fragment illustrates how to access and retrieve the Shakespeare data
int main(int argc, char **argv) {

	// create Bridges object
	Bridges bridges(2, "m", "16");

	// set title
	bridges.setTitle("Accessing Shakespeare Plays, Poems, Sonnets Dataset");

	// create a data source object
	DataSource ds (&bridges);

	// get the data
	vector<Shakespeare> shakespeare_data = ds.getShakespeareData();

// Randomly selects one work from the dataset
srand(time(0));
int i=rand() % shakespeare_data.size();
Shakespeare work= shakespeare_data[i];
string text= work.getText();

// Split text into the words 
vector <string> words;
string word=" ";
for (int i=0; i!=text.length(); i=i+1){
    char c=text[i];
    if (c == ' '|| c == '\n'|| c== '\t'){
        if (word!= " "){
            words.push_back(word);
            word=" ";
        }
    }else{
    word=word+c;
    }
}
if (word!=" "){
    words.push_back(word);
}
// Map to store the word frequencies
map<string,int> freq;
countwords(&words,0,freq);

// Converts map into vector for sorting
vector<pair<string,int>>sorted(freq.begin(),freq.end());

// Bubble sort by frequency (descending order)
for (int i=0;i!=sorted.size(); i=i+1){
    for (int j=0;j+1!=sorted.size();j=j+1){
        if (sorted[j].second<sorted[j+1].second){
            pair<string,int>temp=sorted[j];
            sorted[j]=sorted[j+1];
            sorted[j+1]=temp;
        }
    }
}
// The top 10 most common words are displayed
cout << endl << "Top 10 Most Common Words:" <<endl;
int count=0;
while (count!=10 && count!=sorted.size()){
cout<< sorted[count].first <<" : "<<sorted[count].second<<endl;
count=count+1;
}
	return 0;
}