#include <string>
#include <random>
#include <iostream> 
#include <cassert>

using namespace std;

/*  I assume that we are operating on elements 
    from Ascii Table between 32 and 126.
    Our cypher is like Caesar cipher,but numer
    of positions we are moving is random number
    between 1 and 30 and this is our key */

int generateKey(){
    std::random_device device;
    std::mt19937 generator(device());
    std::uniform_int_distribution<int> distribution(1,30);
    return distribution(generator);
}

string encrypt(string message,int key){
    for (unsigned i=0; i<message.length(); ++i){
        int currentCharacter = int(message[i]);
        int newCharacter = (currentCharacter - 32 + key) % 94;
        message[i] = char (newCharacter + 32);
    }
    return message;
}

string decrypt(string message,int key){
    for (unsigned i=0; i<message.length(); ++i){
        int currentCharacter = int(message[i]);
        int newCharacter = (currentCharacter - 32 - key) % 94;
        if(newCharacter < 0){
            newCharacter += 126;
        } else {
            newCharacter += 32;
        }
        message[i] = char (newCharacter);
    }
    return message;
}

int main() {

    string message = "Hello, Coders School!";
    auto key = generateKey();
    auto cypher = encrypt(message, key);
    auto result = decrypt(cypher, key);

    cout << "Message: " << message << '\n';
    std::cout << "Cypher: " << cypher << '\n';
    cout << "Result: " << result << '\n';

    assert(message == result);

    return 0;
}
