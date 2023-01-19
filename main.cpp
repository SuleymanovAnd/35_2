#include <iostream>
#include <unordered_set>
#include <vector>
#include<memory>
#include <map>


std::unique_ptr <std::vector <int>> uniqueNum (std::unordered_set<int> uniq){
    std::vector <int> unique;
    for(auto u :uniq){
        unique.push_back(u);
    }
  return std::make_unique <std::vector <int>> (unique);
}

int main() {
    std::vector<int> num = {1,3,22,5,15,4,2,1,15,6,3,77,45,1};

    auto f =  [num](){
        std::unordered_set<int> numCount;
        std::map <int,int> repeatedNum;
        for (auto n : num){
            if(numCount.find(n) == numCount.end()){
                numCount.emplace(n);
            } else {
                if (repeatedNum.find(n)!=repeatedNum.end()){
                repeatedNum[n] += 1;
                }else {repeatedNum[n] = 1;}
            }
        }
        for(auto n : repeatedNum){
            std::cout << "number "<<n.first << " repeated " << n.second << " times.\n";
        }
        return numCount;
    };

    std::unordered_set<int> uniq = f();
    auto l =  uniqueNum(uniq);
}
