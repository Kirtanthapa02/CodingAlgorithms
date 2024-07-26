//Given a number this will give all the combinations of 1 and 2 that will add up to the input
#include <iostream>
#include <vector>
using namespace std;

void generateAllSequences(int n)
{
    vector<string> v0 = {""};
    vector<string> v1 = {"1"};
    int i = 2;
    while(i<=n)
    {
        vector<string> temp(v1);
        for(auto& str1:v0){
            str1 = str1 + "2";
        }
        for(auto& str2:v1){
            str2 = str2 + "1";
        }
        v1.insert(v1.end(),v0.begin(),v0.end());
        v0 = temp;
        i++;
    }
    for(const auto& str:v1)
    {
        cout<<str<<endl;
    }
}
int main()
{
    int n;
    cout<<"Enter a number:";
    cin>>n;

    generateAllSequences(n);

    return 0;
}