#include "filesystem" // include the header file for the C++17 Filesystem library
#include "map"
#include "string"
#include "iostream"
#include "fstream"

struct unit{
    std::string name;
    int times;
    unit(const std::string& n,const int i){times=i;name=n;}
};

int fileNum=675;
void load_dict(std::string& dict_base,std::map<std::string,std::vector<unit>>&dict)
{
    std::fstream f(dict_base+"/dict.txt",std::ios::in);
    std::string word,trash;
    while(f>>word) {
        int size;
        f>>size;
        std::getline(f,trash);
        int num;std::string arc;
        for(int i=0;i<size;i++) {
            std::getline(f,arc);
            f>>num;
            dict[word].emplace_back(arc,num);
            std::getline(f,trash);
        }
    }
}

std::map<std::string,std::vector<unit>> dict;  // to store the dictionary read from the file
std::map<int,std::string> total;
int main()
{
    std::string dict_base("../dict"); // Base directory for the dictionary files
    load_dict(dict_base,dict); // Load the dictionary files into a map
    //calculate each words' frequency inside the dictionary.
    for(auto &p:dict)
    {
        int tot=0;
        long long tot_square=0;
        for(auto &t:p.second)
            tot+=t.times,tot_square+=t.times*t.times;
        total[tot]=p.first;
    }
    //Print out the 100 most frequently occurring words
    auto iter=total.end();
    for(int i=0;i<100;i++)
    {
        iter--;
        std::cout<<iter->second<<" "<<iter->first<<std::endl;
    }
    return 0;
}