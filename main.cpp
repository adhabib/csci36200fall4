#include <iostream>
#include <string>
#include <list>
#include <vector>

// create class for hash
class Hash {
	// the amount of nodes/indexes in the table
	int nodes;
	// create pointer to the table of nodes
	std::list<int> *hashTable;

	public:
		// initialize constructor
		Hash(int i);
		// get the tenth digit through modulo
        	int hashTenDigit(int var1);
		// get the one digit through modulo
        	int hashOneDigit(int var1);
		// print out table depending on user input
        	void showTable(int q);
		// insert key into node
        	void insertKey(int z);
		// unused
        	void deleteKey(int p);
};

Hash::Hash(int i){
    // new pointer
    this->nodes = i;
    hashTable = new std::list<int>[nodes];
}

int Hash::hashTenDigit(int var1){
    // modulo to get tens digit
    int var2 = (var1 / 10) % 10;
    return var2;
}

int Hash::hashOneDigit(int var1){
    // modulo to get ones digit
    int var2 = (var1 % 10);
    return var2;
}

void Hash::showTable(int q){
	// print out node
	std::cout << q;
        for (auto x : hashTable[q]){
            std::cout << " -> " << x;
        }
        std::cout << std::endl;
}

void Hash::insertKey(int z){
    int modulo = hashTenDigit(z);
    // counter is used to track duplicate number
    int counter = -1;
    // iterate through node
    std::list<int> :: iterator x;
    for (x = hashTable[modulo].begin(); x != hashTable[modulo].end(); x++){
	// if we find a duplicate, increment
        if (*x == z){
		counter++;
	}
    }
    // if no duplicates found, insert into node
    if (counter < 0){
                hashTable[modulo].push_back(z);
	}
}

// works similarly to insert function but is unused
void Hash::deleteKey(int p){
    int modulo = hashTenDigit(p);
    int modulo2 = hashOneDigit(p);
    int counter = -1;
    std::list<int> :: iterator x;
    	  for (x = hashTable[modulo].begin(); x != hashTable[modulo].end(); x++){
        	  if (*x == p){
            	  counter++;
              	  if (counter > 0){
                	hashTable[modulo].erase(x);
            	  }
		  }
    	  }	
}

int main(){
    // user input
    int q;
    // array of numbers
    int array[1000];
    // range of numbers
    int min = 10;
    int max = 99;
    // seed random number generator
    srand(time(NULL));
    for (int i = 0; i < 1000; i++){
	// generate random number between range and put into arrau
        array[i] = rand() % (max + 1 - min) + min;
	//arr.push_back(array[i]);
    }
    // get size of array
    int n = sizeof(array)/sizeof(array[0]);
    // create instance of size ten
    Hash h(10);
    for (int i = 0; i < n; i++){
	// insert number from array into hash table
        h.insertKey(array[i]);
    }
    //for (int i = 10; i < 100; i++){
      //  h.deleteKey(i);
    //}
    //get user input
    std::cout << "please select a table slot between 1 and 9 ";
    std::cin >> q;

    // print out hash table
    h.showTable(q);

    return 0;
}
