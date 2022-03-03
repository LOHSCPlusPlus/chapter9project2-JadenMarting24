#include <iostream>
#include <fstream>
using namespace std;
// this creates everything that will be stored in CarType
struct BirdType{
  enum {MAX_CHAR_LEN = 100};
  char birdName[MAX_CHAR_LEN];
  char sciName[MAX_CHAR_LEN];
  char status[MAX_CHAR_LEN];
  char color[MAX_CHAR_LEN];
  char diet[MAX_CHAR_LEN];
  
  BirdType();
    
};
// this defines everything in CarType
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
// This function is connected with the readCars function to allow the program to read the description of the car
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

      inFile.get(bird.diet, BirdType::MAX_CHAR_LEN, ';');
      inFile.ignore(100,';');
      
      
  
    return bird;
}
// this function reads the cars in the file and stores it into the cars[] array
int readBirds(BirdType birds[]) {
    ifstream birdFile("birds.txt");
    int numBirds = 0;
    while(birdFile.peek() != EOF && numBirds < MAX_BIRDS) {
        birds[numBirds] = readBirdData(birdFile);
        numBirds++;
    }
    return numBirds;
}
// this function gets the list of cars already stored into the cars[] array and shows the information to the user.
void printBirds(BirdType birds[], int numBirds){
  
    for(int index = 0; index < numBirds; index++){
      
      
        cout << "Index " << index << ": ";
        cout << birds[index].birdName << ";";
        cout << birds[index].sciName << ";";
        cout << birds[index].status << ";";
        cout << birds[index].color << ";";
        cout << birds[index].diet << "\n";
        
      
      
      
    }
}
// this function prints the car based off of what the user entered the Origin as. the cars[index].Origin allows us to do this because it compares what the user entered with what is stored.
void printBirdsByColor(BirdType birds[]){
  string comparison = "";
  cout << "Type a requested region of Origin: ";
  cin >> comparison;
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
// removes a car from the cars[] array
void removeBird(BirdType birds[]){
  int temp = readInt("Enter index to remove");

  birds[temp] = birds[temp + 1];

}
// goes through all of the information stored in cars[] until it finds an unvalid car. Once it finds one it will  promt the user for the cars information and then break
int addBird(BirdType birds[], int numBirds){
  for(int index = 0; index <= numBirds; index++){
    
      cout << "Enter the cars Name: ";
      cin.ignore(100, '\n');
      cin.get(birds[numBirds].birdName, BirdType::MAX_CHAR_LEN);
      cout << "Enter the birds known name: ";
      cin >> birds[numBirds].birdName;
      cout << "Enter the birds scientific name: ";
      cin >> birds[numBirds].sciName;
      cout << "Enter the birds status: ";
      cin >> birds[numBirds].status;
      cout << "Enter the birds color: ";
      cin >> birds[numBirds].color;
      cout << "Enter the birds diet: ";
      cin >> birds[numBirds].diet;
     
      break;
  
    if(index == 500){
      cout << "database is full";
      return 0;
    } 
    }
  return 0;
  
}
// where everything will end up being called and will display a menu for the user.
int main() {
    BirdType birds[MAX_BIRDS]; 

    int num = readBirds(birds);
    int enter = 1200231;
    cout << "Nums: " << num << endl;
    readBirds(birds);
    while(enter != 5){
      cout << " Display the car list(1)\n Remove a car from the list(2)\n Add a car to the list(3)\n Display cars by origin(4)\n Quit(5)\n Enter: ";
      cin >> enter;
      
      if(enter == 2){
        removeBird(birds);
      }
      else if(enter == 1){
        printBirds(birds, num);
      }
      else if(enter == 3){
        addBird(birds, num);
      }
      else if(enter == 4){
        printBirdsByColor(birds);
      }
      else if(enter == 7){
        cout << endl << "Goodbye";
        return 0;
      }
    }
  return 0;
}
