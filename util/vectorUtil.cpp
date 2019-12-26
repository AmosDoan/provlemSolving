//
// Created by Amos on 2019/12/26.
//

#include "vectorUtil.h"

#include <iostream>

using namespace std;

void traversal2DVector(vector<vector<int>> &v) {
    // https://stackoverflow.com/questions/5192874/question-about-vector-iterator-in-template-functions
    for (vector<vector<int>>::iterator it = v.begin();
         it != v.end(); ++it) {
        int index = std::distance(v.begin(), it);
        cout << "row " << index << ":";
        for (auto& col: *it) {
            cout << col << " ";
        }
        cout << '\n';
    }
}

