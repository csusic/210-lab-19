// COMSC-210 | Lab 19 | Christine Susic

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

//set column widths
const int W1 = 8;
const double MIN = 1, MAX = 5; //range of 1-5

class Movie {
    private:
    string movieTitle;
    struct Node {
        double rating;
        string review;
        Node *next;
    };
    public:
    //setter and getter functions
    string getMovieTitle() const     {return movieTitle;}      
    void setMovieTitle(string m)     {movieTitle = m;} 
    string getRating() const         {return rating;}      
    void setRating(double t)         {rating = t;} 
    string getReview() const         {return review;}      
    void setReview(string r)         {review = r;} 
};

int main() {
    //declarations
    srand(time(0));
    //random number calculation
    double r1 = rand() % static_cast<int>(MAX - MIN + 1) + MIN; 
    double r2 = rand() % static_cast<int>(MAX - MIN + 1) + MIN; 
    double r3 = rand() % static_cast<int>(MAX - MIN + 1) + MIN; 
    double r4 = rand() % static_cast<int>(MAX - MIN + 1) + MIN; 
    cout << setprecision(1);
    
    //vector
    std::array<Movie, 3> objArray = { Movie(10), Movie(20), Movie(30) };
    
    ifstream fin ("input.txt"); //read from input file
    string r;  //temp review comments
    //read from file into vector
    if (fin.good()) {
        while (getline(fin, r)) {
            //temp Movie object
            Movie tmp;
            tmp.setReview(r);
            //push data into vector
            movies.push_back(tmp);
        }
        fin.close();
    }
    else
        cout << "Input file not found.\n";
        
    //output vector
    for (auto val : movies) {
        cout << "\tMovie Title: " << val.getTitle() << endl;
        cout << "\tMovie Rating: " << val.getRating() << endl;
        cout << "\tMovie Review: " << val.getReview() << endl;
    }
 
    Movie movie1;
    Movie movie2;
    Movie movie3;
    Movie movie4;
    
    return 0;
}

