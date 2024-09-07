/*

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().

WrittenBy : Himanshu Srivastava
Problem : Implement strStr()
TimeComplexity : O(n)
 
*/

class Solution {
    
    vector<int> kmp1( string needle){
        
        int n = needle.size();
        vector<int> res(n,0);
        
        for( int i = 1, len = 0 ; i < n;){
            if(needle[i] == needle[len]){
                res[i++] == len++;
            }else if(len){                
                len = res[len -1 ];
            }else{
                res[i++] = 0;
            }            
        }
        for( int i = 0 ; i < res.size();i++){
            cout<<res[i];
        }
        return res;
    }
    
public:
    int strStr1(string haystack, string needle) {
        int m =  haystack.size();
        int n = needle.size();
        cout<<m<<" "<<n<<endl;
        vector<int> lps = kmp( needle);
        for( int i = 0 ; i < lps.size();i++){
            // cout<<lps[i];
        }
        for( int i =0 , j = 0 ; i < m; ){
            
            if( haystack[i] == needle[j]){
                i++;
                j++;
            }
            
            if( j == n ){
                
                return i - j;
            }
            
            if(i < m && haystack[i] != needle[j]){
                
                j ? j = lps[j - 1] : i++;
            }
            
            
        }
        
        return -1;
    }
    int strStr1(string haystack, string needle) {
        int m = haystack.size(), n = needle.size(), p = 0;
        while (p + n - 1 < m) {
            if (haystack.substr(p, n) == needle) {
                return p;
            }
            while (p++ + n - 1 < m && haystack[p] != needle[0]);
        }
        return -1;
    }

 vector<int> kmp( string st){
        int n = st.size();
        vector<int> res(n,0);

        int i = 0;
        int j = 1;
        
        while( j < n){

            if( st[i] == st[j]){
                res[j] = i + 1;
                i++;
                j++;
            }else if ( i> 0 ) {
                i = res[i-1];
            }else{
                res[j] = 0;
                j++;
            }
        }

        return res;

    }

    int strStr(string haystack, string needle) {

        int h_len = haystack.size();
        int n_len = needle.size();

        vector<int> lmp = kmp(needle);
        int i = 0;
        int j = 0;
        while( i < h_len ){

            if( haystack[i] == needle[j]){

                i++;
                j++;
            }

            if ( j == n_len ){
                return i -j;
            }

            if( i< h_len && haystack[i] != needle[j]){
                if( j > 0 ){
                    j = lmp[j-1];
                }else{
                    i++;
                }
                
            }
        }

        return -1;

        
    }

    int strStr(string haystack, string needle) {
        int h=haystack.size();
        int n=needle.size();
        if(h<n) return -1;
        int k=0,j;
        for(int i=0 ; i<h ; i++){
            j=i;
            while(k<n && i<h && haystack[j]==needle[k] ){
                k++,j++;
            }
            if(k==n) return i;
            k=0; 
        }
        return -1;
    }
    
    
};


void displayInt(vector<string>input){
    cout<<"Displaying size "<<input.size()<<endl;
    for (std::vector<string>::size_type i = 0; i < input.size(); i++) {
        std::cout << input.at(i) << ' ';
    }
}

int main(){

    Solution sol;

    vector<string>input{"abcabcbb"}

    displayInt(sol.strStr(input));

    return 0;
}
