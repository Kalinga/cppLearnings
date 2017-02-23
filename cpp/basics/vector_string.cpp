    #include<vector>
    #include<string>
    #include<iostream>
    #include<algorithm>
    using namespace std;

    int main()  // small program messing around with strings
    {
        cout << "enter some whitespace-separated words:\n";

        vector<string> v;
        string s;

        while (cin>>s) v.push_back(s);
      //    sort(v.begin(),v.end());

        string cat;

        for (auto & str : v) cat += str+"..";
        cout << cat << '\n';
    }


    //Compile this file: g++-4.8 vector_string.cpp -std=c++11
