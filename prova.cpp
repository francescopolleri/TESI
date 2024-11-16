#include <iostream>
#include <vector>
#include <algorithm> // For std::max_element
using namespace std; 


int THRESHOLD(vector<int> test){

    int min_thr=10;

    vector<int> bin;

    int thr;

    // Step 1: Check if all entries are less than 8
    bool all_entries_less_than_8 = true;
    for (int x : test) {
        if (x >= 8) {
            all_entries_less_than_8 = false;
            break;
        }
    }

    if (all_entries_less_than_8) {
        cout << "All entries are less than 8" << endl;
        thr=0;
        //cout<<thr<<endl;
        return thr;
    }

    // Step 2: Collect indices where test[i] >= 8
    for (size_t i = 0; i < test.size(); i++) {
        if (test[i] >= 8) {
            bin.push_back(i);
        }
    }

    // Step 3: Handle cases based on bin size
    if (bin.size() == 1) {
        cout << "Un solo valore" << endl;
        thr = bin[0]+min_thr; // Only one value
    } else {
        // Step 4: Find sequences of consecutive indices
        vector<vector<int>> sequences;
        vector<int> curr_seq = {bin[0]};

        for (size_t i = 1; i < bin.size(); i++) {
            if (bin[i] == bin[i - 1] + 1) { // Consecutive index
                curr_seq.push_back(bin[i]);
            } else { // Break in sequence
                sequences.push_back(curr_seq);
                curr_seq = {bin[i]};
            }
        }
        if (!curr_seq.empty()) {
            sequences.push_back(curr_seq); // Add the last sequence
        }

        // Step 5: Find the longest sequence
        vector<int> longest_sequence = *max_element(sequences.begin(), sequences.end(), 
            [](const vector<int>& a, const vector<int>& b) {
                return a.size() < b.size();
            });
        
        thr = longest_sequence[0]+min_thr;

        /*
        // Output the results
        cout << "Sequences:" << endl;
        for (const auto& seq : sequences) {
            cout << "[";
            for (size_t i = 0; i < seq.size(); i++) {
                cout << seq[i];
                if (i < seq.size() - 1) cout << ", ";
            }
            cout << "]" << endl;
        }

        cout << "Longest sequence:" << endl;
        cout << "[";
        for (size_t i = 0; i < longest_sequence.size(); i++) {
            cout << longest_sequence[i];
            if (i < longest_sequence.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
        */

    }

    return thr;

}

int main(){


vector<int> test1{1,2,3,4,5,6,7,8,9,10};  //una sola sequenza  
vector<int> test2{10,10,3,4,5,6,7,8,9,10};  //due sequenze
vector<int> test3{1,1,3,4,5,6,7,8,0,0};  //un solo valore
vector<int> test4{1,1,3,4,5,6,7,7,7,1};  //nessun valore

cout<<THRESHOLD(test1)<<endl;
cout<<THRESHOLD(test2)<<endl;
cout<<THRESHOLD(test3)<<endl;
cout<<THRESHOLD(test4)<<endl;

}

//Decidere se come soglia si vuole prendere il valore più alto o più basso possibile (oppure quello intermendio così sono lontano dai "buchi")

//Nel programma vero dovrò creare un vettore per ogni canale all'interno del loop


void EvaluateThr::SaveBestThr(){

 std::ofstream outfile(m_nomefile_thr.c_str()); //.c_str());

  int th;
  for(int j=1; j<256+1; j++){
     th=0;
     vector<int> channel_values;
     for(int i=1; i<m_nbinx+1; i++){
        channel_values.push_back(m_isto_summary->GetBinContent(i,j))
      }
     th=THRESHOLD(channel_values);

     if(th==0) {
          std::cout<<"Il pixel "<<j-1<<" non ha mai acquisito dati "<<std::endl;
        th=30;
      }
     outfile<<th<<std::endl;
   }

   outfile.close();
}












