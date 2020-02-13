#include <iostream>
#include <string>
using namespace std;


int A, B, C, D, E, F, G, H;
int counter;
std::string answer("");

int clean_cube()
{
    while (A!=0 && B!=0&&counter<=1000){
        answer+="AB-\n";
        A--;
        B--;
        counter++;
    }
    while (A!=0 && D!=0&&counter<=1000){
        answer+="AD-\n";
        A--;
        D--;
        counter++;
    }
    while (A!=0 && E!=0&&counter<=1000){
        answer+="AE-\n";
        A--;
        E--;
        counter++;
    }
    while (B!=0 && C!=0&&counter<=1000){
        answer+="BC-\n";
        B--;
        C--;
        counter++;
    }
    while (B!=0 && F!=0&&counter<=1000){
        answer+="BF-\n";
        B--;
        F--;
        counter++;
    }
    while (C!=0 && D!=0&&counter<=1000){
        answer+="CD-\n";
        C--;
        D--;
        counter++;
    }
    while (C!=0 && G!=0&&counter<=1000){
        answer+="CG-\n";
        C--;
        G--;
        counter++;
    }
    while (D!=0 && H!=0&&counter<=1000){
        answer+="DH-\n";
        D--;
        H--;
        counter++;
    }
    while (E!=0 && F!=0&&counter<=1000){
        answer+="EF-\n";
        E--;
        F--;
        counter++;
    }
    while (E!=0 && H!=0&&counter<=1000){
        answer+="EH-\n";
        E--;
        H--;
        counter++;
    }
    while (G!=0 && F!=0&&counter<=1000){
        answer+="GF-\n";
        G--;
        F--;
        counter++;
    }
    while (G!=0 && H!=0&&counter<=1000){
        answer+="GH-\n";
        G--;
        H--;
        counter++;
    }
    while (A!=0 && G!=0&&counter<=1000){
        answer+="DH+\nAD-\nGH-\n";
        A--;
        G--;
        counter+=3;
    }
    while (E!=0 && C!=0&&counter<=1000){
        answer+="DH+\nCD-\nEH-\n";
        E--;
        C--;
        counter+=3;
    }
    while (F!=0 && D!=0&&counter<=1000){
        answer+="CG+\nCD-\nGF-\n";
        F--;
        D--;
        counter+=3;
    }
    while (H!=0 && B!=0&&counter<=1000){
        answer+="CG+\nCB-\nGH-\n";
        H--;
        B--;
        counter+=3;
    }
    return 0;
}

int solve(){
    while ((A>0||B>0||C>0||D>0||E>0||F>0||G>0||H>0)&&counter<=1000){
        clean_cube();
    }
    if(counter>1000){
        cout << "IMPOSSIBLE";
    }else{
        cout << answer;
    }
    return 0;
}


int main()
{
    // 8 numbers: A, ..., H - amount of duons in every cormer of cube.
    cin >> A >> B >> C >> D >> E >> F >> G >> H;
    //check for possibility:
    counter = 0;
    if (A + C + F + H != B + D + E + G){
        cout << "IMPOSSIBLE";
    }else{
        solve();
    }
    return 0;
}


