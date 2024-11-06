#include <bits/stdc++.h>

using namespace std;

int main() {

    unordered_map<string, int> umap;

    umap["apple"] = 1;
    umap["banana"] = 2;
    umap["cat"] = 3;

    cout << umap["apple"];

    if (umap.find("banana") != umap.end()) {
        cout << "found!";
    }

    for (auto& pair: umap) {
        cout << pair.first << "\n";
        cout << pair.second << "\n";
    }
    
    return 0;
}