// COMSC-210 | Lab 19 | Christine Susic

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

const int W1 = 8;

class Movie {
    private:
    string movieTitle;
    string review;
    struct Node {
        
    };
    public:
    //setter and getter functions
    string getReview() const         {return review;}      
    void setReview (string r)        {review = r;} 
};

int main() {
    vector<Movie> movies; //vector
    
    ifstream fin ("input.txt"); //read from input file
    string m;  //temp movie title
    
    //read from file into vector
    if (fin.good()) {
        while (getline(fin, m)) {
            //temp Movie object
            Movie tmp;
            tmp.setReview(m);
            //push data into vector
            movies.push_back(tmp);
        }
        fin.close();
    }
    else
        cout << "Input file not found.\n";
        
    //output vector
    for (auto val : movies) {
        cout << "Movie Review: " << val.getReview() << endl;
    }
 
    Movie container;
    Movie movie1;
    Movie movie2;
    Movie movie3;
    Movie movie4;
    
    return 0;
}

