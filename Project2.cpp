#include <iostream>
#include <fstream>
using namespace std;
// this creates everything that will be stored in struct BirdType
struct BirdType{
  enum {MAX_CHAR_LEN = 100};
  char birdName[MAX_CHAR_LEN];
  char sciName[MAX_CHAR_LEN];
  char status[MAX_CHAR_LEN];
  char color[MAX_CHAR_LEN];
  char diet[MAX_CHAR_LEN];
  
  BirdType();
    
};
// this defines everything in default constructor BirdType
BirdType::BirdType() {
  
  for(int index = 0; index < MAX_CHAR_LEN; index++){
    birdName[index] = 0;
    sciName[index] = 0;
    status[index] = 0;
    color[index] = 0;
    diet[index] = 0;
  }

}
const int MAX_BIRDS = 500;
// This function is connected with the readCars function to allow the program to read the description of the birds
BirdType readBirdData(ifstream &inFile){
    BirdType bird;
   
      
      inFile.get(bird.birdName, BirdType::MAX_CHAR_LEN, ';');
      inFile.ignore(100,';');
      
      inFile.get(bird.sciName, BirdType::MAX_CHAR_LEN, ';');
      inFile.ignore(100,';');

      inFile.get(bird.status, BirdType::MAX_CHAR_LEN, ';');
      inFile.ignore(100,';');

      inFile.get(bird.color, BirdType::MAX_CHAR_LEN, ';');
      inFile.ignore(100,';');

      inFile.get(bird.diet, BirdType::MAX_CHAR_LEN);
      inFile.ignore(100,'\n');
      
      
  
    return bird;
}
// this function reads the cars in the birds.txt file and stores it into the birds[] array
int readBirds(BirdType birds[]) {
    ifstream birdFile("birds.txt");
    int numBirds = 0;
    while(birdFile.peek() != EOF && numBirds < MAX_BIRDS) {
        birds[numBirds] = readBirdData(birdFile);
        numBirds++;
    }
    return numBirds;
}
//  this reads birds in the save.txt file 
int readBirdies(BirdType birds[]) {
    ifstream birdFile("save.txt");
    int numBirds = 0;
    while(birdFile.peek() != EOF && numBirds < MAX_BIRDS) {
        birds[numBirds] = readBirdData(birdFile);
        numBirds++;
    }
    return numBirds;
}
// this function gets the list of birds already stored into the birds[] array and shows the information to the user.
void printBirds(BirdType birds[], int numBirds){
  
    for(int index = 0; index < numBirds; index++){
      
      
        cout << "Index " << index << ": ";
        cout << birds[index].birdName << ";";
        cout << birds[index].sciName << ";";
        cout << birds[index].status << ";";
        cout << birds[index].color << ";";
        cout << birds[index].diet << endl;
        
      
      
      
    }
}
// this function prints the bird based off of what the user entered the Color as. the birds[index].Color allows us to do this because it compares what the user entered with what is stored.
void printBirdsByColor(BirdType birds[]){
  string comparison = "";
  cout << "Type a requested region of color: ";
  cin >> comparison;
  cout << "--------------------" << endl;
  for(int index = 0; index < MAX_BIRDS; index++){
    if(birds[index].color == comparison){
        cout << "Index " << index << ": ";
        cout << birds[index].birdName << ";";
        cout << birds[index].sciName << ";";
        cout << birds[index].status << ";";
        cout << birds[index].color << ";";
        cout << birds[index].diet << endl;

    }
  }
  cout << "--------------------" << endl;
}
// used for promting the user for data but for doubles
int readDouble(const char prompt[]){
    double temp = 0;
    cout << prompt;
    cin >> temp;
    while (!cin) {
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Invalid Data!" << endl;
        cout << prompt;
        cin >> temp;
    }
    return temp;
}
// used for promting the user for data but for ints
int readInt(const char prompt[]){
    int temp = 0;
    cout << prompt;
    cin >> temp;
    while (!cin) {
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Invalid Data!" << endl;
        cout << prompt;
        cin >> temp;
    }
    return temp;
}
// replaces the bird chosen with the index above the current index.
void removeBird(BirdType birds[], int numBirds){
  int temp = readInt("Enter index to remove");
  for(int index = temp; index < numBirds; index++){
    birds[index] = birds[index + 1];

    }
}
// refreshes bird data from save.txt
void reloadData(BirdType birds[]){
  readBirdies(birds);
}
// file outs everything in BirdType birds
void printExample(ostream &out, BirdType birds){
    out << birds.birdName << ";";
    out << birds.sciName << ";";
    out << birds.status << ";";
    out << birds.color << ";";
    out << birds.diet << endl;
}
// saves everything into the save.txt file using printExample to print to the file
void saveData(BirdType birds[], int numBirds){
  ofstream outFile("save.txt");
    for (int index = 0; index < numBirds; index++) {
      printExample(outFile, birds[index]);
    }
}
// adds a bird to the birds[] array by using cin.gets because they are all char arrays
int addBird(BirdType birds[], int numBirds){
  
    
      cin.ignore(100, '\n');
      
      cout << "Enter the birds known name: ";
      cin.get(birds[numBirds].birdName, BirdType::MAX_CHAR_LEN);
      cin.ignore(100, '\n');
      cout << "Enter the birds scientific name: ";
      cin.get(birds[numBirds].sciName, BirdType::MAX_CHAR_LEN);
  cin.ignore(100, '\n');
      cout << "Enter the birds status: ";
      cin.get(birds[numBirds].status, BirdType::MAX_CHAR_LEN);
  cin.ignore(100, '\n');
      cout << "Enter the birds color: ";
      cin.get(birds[numBirds].color, BirdType::MAX_CHAR_LEN);
  cin.ignore(100, '\n');
      cout << "Enter the birds diet: ";
      cin.get(birds[numBirds].diet, BirdType::MAX_CHAR_LEN);
  cin.ignore(100, '\n');
  
  
  return 0;
  
}
// where everything will end up being called and will display a menu for the user.
int main() {
    BirdType birds[MAX_BIRDS]; 

    int num = readBirds(birds);
    int enter = 1200231;
    cout << "Nums: " << num << endl;
    readBirds(birds);

    while(enter != 7){
      cout << " Reload Bird Data(1)\n Print Bird Data(2)\n Add Bird Data(3)\n Remove Bird Data(4)\n Print Bird By Color(5)\n Save Bird Data(6)\n Quit(7)\n Enter: ";
      cin >> enter;
      
      if(enter == 4){
        removeBird(birds, num);
        num--;
      }
      else if(enter == 6){
        saveData(birds, num);
      }
      else if(enter == 1){
        reloadData(birds);
      }
      else if(enter == 2){
        printBirds(birds, num);
      }
      else if(enter == 3){
        if(num < MAX_BIRDS){
          addBird(birds, num);
          num++;
        }
      }
      else if(enter == 5){
        printBirdsByColor(birds);
      }
      else if(enter == 7){
        cout << endl << "Goodbye";
        return 0;
      }
    }
  return 0;
}
