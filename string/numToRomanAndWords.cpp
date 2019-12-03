#include<iostream>
#include<bits/stdc++.h>



using namespace std;

string numToRoman( int num){

    vector<string> roman = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    vector<int> digit = {1000,900,500,400,100,90,50,40,10,9,5,4,1};

    string res ="";
    
    for( int i = 0 ; i < digit.size();i++){
        while( num >= digit[i]){
            num -= digit[i];
            res += roman[i];
            // cout<<num<<" "<<res<<endl;
        }
    }

    return res;


}



string numToword(int num, string postFix){

    vector<string> Y = {"", "","Twenty ","Thirty ","Fourty ","Fifty ","Sixty ","Seventy ","Eighty ","Ninety "};

    vector<string> X = {"","One ","Two ","Three ","Four ","Five ","Six ","Seven ","Eight ","Nine ","Ten ","Eleven ","Twelve","Thirteen ",
    "Fourteen ","Fifteen ","Sixteen ","Seventeen ","Eighteen ","Nineteen "};

    if( num == 0 ){
        return "";
    } 

    if( num > 19 ){
        return Y[num/10] + X[num % 10 ] + postFix;
    }else{
        return X[num] + postFix;
    }



}
 
string numToWords( int nums){

    string res = numToword(nums % 100," ");

    res = numToword( ( nums / 100 ) % 10,"Hundred ") + res;
    res = numToword(( nums / 1000 ) % 100, "Thousand ") + res;
    res = numToword(( nums / 100000 ) % 100, "Lacs ") + res;
    res = numToword(( nums / 10000000 ) % 100, "Crore ") + res;
    res = numToword(( nums / 1000000000) % 100, "Billion " ) + res;
    


    return res;

}



int main(int* argc,char** argv ){

    cout<<argv[1]<<endl;
    cout<<numToRoman(atoi(argv[1]))<<endl;
    cout<<numToWords(atoi(argv[1]))<<endl;
    return 0;
}