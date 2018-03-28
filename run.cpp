#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>
using namespace std;
const int NUM = 26;
const string wordlist [NUM] = { "river" , "battle", "perfect",
"danger" , "window" , "nature" , "home", "health" , "angry" ,
"night", "keeper" , "internet" , "manage", "noone", "begin",
"play" , "door" , "student", "lesson" , "train" , "useful",
"image" , "sunny", "snow" , "mouse", "function" };
int main ()
{
using std::tolower;
srand(time(0));
char play;
cout << "Play game in words ? <y/n> ";
cin>>play;
play = tolower(play) ;
while (play == 'y' )
{
 string target = wordlist [rand()%NUM] ;
 int length = target.length () ;
 string attempt(length ,'-');
 string badchars;
 int guesses = 6;
 cout << "Guess my secret word. It contains " << length
 << " letters, and you can guess\n"
 << "one letter at a time. You are given " << guesses
 << " wrong guessing. \n" ;
 cout << " Your word: " << attempt << endl ;
 while ( guesses > 0 && attempt != target)
 {
  char letter;
  cout << "Guess the letter : ";
  cin >> letter ;
  if ( badchars.find( letter)!= string::npos
  || attempt.find( letter)!= string::npos)
  {
    cout << " You already asked her. Try again. \n" ;
    cout <<"-------------------------------"<<endl;
   continue ;}
   int loc = target.find(letter);
   if (loc == string::npos )
    {
       cout << " Wrong! \n" ;
       --guesses ;
       badchars += letter;
    } // добавить к строке
  else
  {
    cout << " Correctly ! \n" ;
    attempt[loc] =letter;
    loc = target.find(letter, loc+1) ;
  while ( loc != string::npos )
   {
     attempt [ loc ] =letter ;
     loc = target .find ( letter, loc + 1 ) ;
   }
  }
  cout << " Your word : " << attempt << endl ;
  if ( attempt != target)
   {
    if (badchars.length () > 0)
    cout << " Wrong Variants : " << badchars << endl ;
    cout <<" Wrong variants left : "<<guesses <<endl ;
    cout <<"-------------------------------"<<endl;
  }
 }
  if ( guesses > 0)
   cout << " Guessed ! \n " ;
  else
   cout << " It is a pity, but the word was conceived : " << target << ". \n" ;
   cout <<"-------------------------------"<<endl;
   cout << "Playing more ? <y/n> ";
   cin >> play;
 }
play = tolower (play) ;
cout << " Good luck! \n" ;
return 0;
}
