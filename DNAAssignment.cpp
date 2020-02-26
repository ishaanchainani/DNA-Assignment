#include <iostream>
#include <fstream>
#include <math.h>
#define _USE_MATH_DEFINES

#include <string>

//brings in type ostringstream.
#include <sstream>

//IO that helps characters
#include <ctype.h>

using namespace std;

//filling in variables
void filler(ifstream& file);

//filling in bigram variables
void bigramFiller(ifstream& file);

int sum();
int meanVal();
float varianceVal(ifstream& file);
float stanDeviation(float variance);

//these variables are filled
int countA = 0;
int countC = 0;
int countT = 0;
int countG = 0;
int lineCount = 0;
float stanDev = 0.0;
float DNASum = 0;
float mean = 0.0;
int aa = 0; int cc = 0; int gg = 0; int tt = 0;
int ac = 0; int at = 0; int ag = 0;
int ca = 0; int ct = 0; int cg = 0;
int ta = 0; int tc = 0; int tg = 0;
int ga = 0; int gc = 0; int gt = 0;


int main(int argc, char** argv){

string line;

// setting inputFile to argument vector command line argument
ifstream inputFile(argv[1]);

//opening file
inputFile.open(line);
ofstream outFile;
outFile.open("ishaan.out");

if(outFile.is_open()){
  outFile << "Your file is valid.\n";

}

else{
  cout << "Unable to open file";
  return 0;
}


filler(inputFile);

cout << countA << endl;
cout << countC << endl;
cout << countT << endl;
cout << countG << endl;
cout<< "Sum: " << sum() << endl;
cout << "Mean:" << meanVal() << endl;

//clearing the previous section
inputFile.clear();
inputFile.seekg(0, ios::beg);

float variance = varianceVal(inputFile);
cout << "Variance: " << variance << endl;
cout << "Standard Deviation: " << stanDeviation(variance) << endl;

inputFile.clear();
inputFile.seekg(0, ios::beg);


//Output to ishaan.out
  outFile << "Ishaan Chainani" << endl;
  outFile << "Student ID: 2315756" << endl;
  outFile << "CPSC-350-02" << endl;
  outFile << "COUNT OF A: " << countA << endl;
  outFile << "COUNT OF C: " << countC << endl;
  outFile << "COUNT OF T: " << countT << endl;
  outFile << "COUNT OF G: " << countG << endl;


bigramFiller(inputFile);
cout << aa << endl;
cout << gg << endl;
cout << cc << endl;
cout << tt << endl;

inputFile.close();

}
//declaring filler function
void filler(ifstream& file) {
  char c;
  while(file.get(c)){
    cout << c << endl;
    if(tolower(c)=='a'){
      countA++;
    }
    if(tolower(c)=='c'){
      countC++;
    }
    if(tolower(c)=='t'){
      countT++;
    }
    if(tolower(c)=='g'){
      countG++;
    }
    if(c == '\n'){
      lineCount++;
    }
  }

}

//calculating number of bigrams
void bigramFiller(ifstream& file) {
  char c;
  char prev_c = '0';
  string s;
  while(file.get(c)){
    //sliding window algorithm: save the old grab the new
    if(prev_c == '0'){
      prev_c = c;
      continue;

    }
    prev_c = tolower(prev_c);
    c = tolower(c);

    //use ostringstream to avoid making character array.
    ostringstream os;
    os << prev_c << c;
    s = os.str();


    prev_c = c;
    //combining two characters into an o string stream and converting that into a string which converts
    //into a char *
    if(strncmp(s.c_str(), "aa", 2) == 0){
      aa++;
    }
    if(strncmp(s.c_str(), "ac", 2) == 0){
      ac++;
    }
    if(strncmp(s.c_str(), "ca", 2) == 0){
      ca++;
    }
    if(strncmp(s.c_str(), "ta", 2) == 0){
      ta++;
    }
    if(strncmp(s.c_str(), "ga", 2) == 0){
      ga++;
    }
    if(strncmp(s.c_str(), "cc", 2) == 0){
      cc++;
    }
    if(strncmp(s.c_str(), "at", 2) == 0){
      at++;
    }
    if(strncmp(s.c_str(), "ct", 2) == 0){
      ct++;
    }
    if(strncmp(s.c_str(), "tc", 2) == 0){
      tc++;
    }
    if(strncmp(s.c_str(), "gc", 2) == 0){
      gc++;
    }
    if(strncmp(s.c_str(), "gg", 2) == 0){
      gg++;
    }
    if(strncmp(s.c_str(), "ag", 2) == 0){
      ag++;
    }
    if(strncmp(s.c_str(), "cg", 2) == 0){
      cg++;
    }
    if(strncmp(s.c_str(), "tg", 2) == 0){
      tg++;
    }
    if(strncmp(s.c_str(), "gt", 2) == 0){
      gt++;
    }
    if(strncmp(s.c_str(), "tt", 2) == 0){
      tt++;
    }


    if(c == '\n'){
      lineCount++;
    }
  }

}


int meanVal(){
  DNASum = countA + countC + countT + countG;
  return (DNASum + 0.0) / lineCount;
}


float varianceVal (ifstream& file){

string line;
float sum = 0;
float m = meanVal();
while (getline(file,line)){

  cout << line << endl;

//summation equation
sum+=pow(line.length() - mean, 2);


file.close();

}

return sum/(lineCount-1);

}

float stanDeviation(float variance){

  return stanDev = sqrt(variance);

}

int sum(){
  return countA + countC + countT + countG;
}
