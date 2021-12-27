#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

int dx[8] = {1,0,-1,0,1,-1,-1,1};
int dy[8] = {0,1,0,-1,1,1,-1,-1};

char board[5][5];
vector<vector<unordered_map<string,int>>>dp;

const int BOARD_SIZE = 5;


// return true if it's possible to find the word[k:] starting from (i, j) 
bool canFind(string &word, int k, int i, int j){
    // Base Cases
    if(i<0 || i>=BOARD_SIZE || j<0 || j>=BOARD_SIZE) return false;
    if(board[i][j] != word[k]) return false;
    if(k == word.size() - 1) return board[i][j] == word.back();

    string curWord = word.substr(k);

    // Memoization - early return
    if(dp[i][j].count(curWord)) return dp[i][j][curWord];

    // Go to all 8 directions
    for(int dir=0; dir<8; dir++){
        if(canFind(word, k+1, i+dx[dir], j+dy[dir])) return dp[i][j][curWord] = true; // memoization
    }
    
    return dp[i][j][curWord] = false; // memoization
}

int main(){
    int num_test_cases;

    // INPUT: # test cases
    cin>>num_test_cases;

    vector<string>words;
    vector<string>res;

    dp.clear();
    dp.resize(BOARD_SIZE, vector<unordered_map<string,int>>(BOARD_SIZE));


    while(num_test_cases--){
        dp.clear();
        dp.resize(BOARD_SIZE, vector<unordered_map<string,int>>(BOARD_SIZE));

        for(int i=0; i<BOARD_SIZE; i++) cin >> board[i];
        
        int num_words;
        string word;
        // INPUT: # words
        cin >> num_words;

        for(int i=0; i<num_words; i++){
            // INPUT: word
            cin >> word;

            // possible: To break out of double for-loop
            bool possible = false;

            // Go throgh each grid-cell. The grid-cell's character should match the 1st character of the target word
            for(int i=0; i<BOARD_SIZE; i++){
                for(int j=0; j<BOARD_SIZE; j++){
                    if(board[i][j] != word[0]) continue; // If 1st character doesn't match, continue
                    if(canFind(word, 0, i, j)){ // If the word is found, break
                        possible = true;
                        break;
                    }
                }
                if(possible) break; // early break
            }

            if(possible) res.push_back(word + " YES");
            else res.push_back(word + " NO");
        }
    }

    for(auto &r: res){
        cout<<r<<"\n";
    }
}
