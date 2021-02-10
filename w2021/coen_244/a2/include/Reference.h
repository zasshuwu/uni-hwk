#pragma once

#include <iostream>
#include <string>

using namespace std;

class Reference {
    public:
        Reference();
        Reference(const Reference &ref);

        static int instance_count;

        string GetTitle() const;
        void SetTitle(string);

        string GetAuthor() const;
        void SetAuthor(string);

        int GetPubYear() const;
        void SetPubYear(int);

        int GetUID() const;
        void SetUID(int);

        void PrintInfo();

        ~Reference();

    private:
        int uid; // unique identifier
        string title;
        string author;
        int pub_year; // year of publication

};