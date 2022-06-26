class Solution {
public:
    vector<string> fizzBuzz(int turnedOn) {
        
        vector<string> fizzy;
        
        for(int i = 1; i <= turnedOn; i++){      
            if((i%3 == 0) && (i%5 == 0)){
                fizzy.push_back("FizzBuzz");
            }else if(i%3 == 0){
                fizzy.push_back("Fizz");
            }else if(i%5 == 0){
                fizzy.push_back("Buzz");
            }else{
                fizzy.push_back(to_string(i));
            }
        }
        
        return fizzy;
    }
};