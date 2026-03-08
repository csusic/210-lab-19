// COMSC-210 | Lab 19 | Christine Susic

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string> 
#include <vector>
#include <cmath>
using namespace std;

const int SIZE = 4; //size of linked list
const int MIN = 1, MAX = 5; //random double range of 1-5

class Movie {
    private:
    string movieTitle;
    double rating;
    string review;
    struct Node {
        double rating;
        string review;
        Node *next;
    };
    public:
    //setter and getter functions
    string getMovieTitle() const    {return movieTitle;}      
    void setMovieTitle(string m)    {movieTitle = m;} 
    double getRating() const        {return rating;}      
    void setRating(double t)        {rating = t;} 
    string getReview() const        {return review;}      
    void setReview(string r)        {review = r;} 
};

int main() {
    //declarations
    //vector
    vector<Movie> movies;
    //random doubles 1-5
    srand(time(0));
    double r1 = rand() % (MAX - MIN + 1) + MIN;
    double r2 = rand() % (MAX - MIN + 1) + MIN;
    double r3 = rand() % (MAX - MIN + 1) + MIN;
    double r4 = rand() % (MAX - MIN + 1) + MIN;
    //container of four Movie objects
    //Movie 1
    Movie m1;
    m1.setMovieTitle("Hello");
    m1.setRating(r1);
    m1.setReview("Review");
    movies.push_back(m1);
    //Movie 2
    Movie m2;
    m2.setMovieTitle("This");
    m2.setRating(r2);
    m2.setReview("J");
    movies.push_back(m2);
    //Movie 3
    Movie m3;
    m3.setMovieTitle("How");
    m3.setRating(r3);
    m3.setReview("K");
    movies.push_back(m3);
    //Movie 4
    Movie m4;
    m4.setMovieTitle("Now");
    m4.setRating(r4);
    m4.setReview("L");
    movies.push_back(m4);
    
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
        cout << "Movie Title: " << val.getMovieTitle() << endl;
        cout << "Movie Rating: " << fixed << setprecision(1);
        cout << val.getRating() << endl;
        cout << "Movie Review: " << val.getReview() << endl << endl;
    }
    
    return 0;
}