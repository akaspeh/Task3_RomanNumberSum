#include <iostream>
#include <string>
#include <vector>



using namespace std;

int binary_pow(int num,int s){
    if(s == 0)return 1;
    if(s%2!=0){
        return num * binary_pow(num,s-1);
    }
    else {
        int a = binary_pow(num,s/2);
        return a * a;
    }
}

int romanToInt(char a){
    switch(a){
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
    }
}

string ToRoman(int a){
    string s;
    switch(a){
        case 1:
            s ="I";
            return s;
        case 5:
            s ="V";
            return s;
        case 10:
            s ="X";
            return s;
        case 50:
            s ="L";
            return s;
        case 100:
            s ="C";
            return s;
        case 500:
            s ="D";
            return s;
        case 1000:
            s ="M";
            return s;
    }
}

int convertToInt(string num){
    int res=0;
    int *buf = new int[num.length()];
    for(int i = 0; i < num.length();i++){
        buf[i]=romanToInt(num[i]);
        cout << buf[i] << " ";
    }
    cout << " \n";
    for(int i = 0; i < num.length();i++){
        if(buf[i]<buf[i+1] && i != num.length()-1){
            buf[i] *= -1;
        }
        cout << buf[i] << " ";
        res += buf[i];
    }
    cout << " \n";
    cout << res << endl;
    delete [] buf;
    return res;
}


void rec(int num10,vector<int> &buf,int num,int iteration){
    if(num10 == 0){
        return;
    }

    num10 /= 10;
    int reminder = num%10;
    num -= reminder;
    reminder = reminder * binary_pow(10,iteration);

    num = num/10;
    iteration++;
    rec(num10, buf,num,iteration);
    if(reminder != 0) {
        buf.push_back(reminder);
    }
}

void print(vector<int>& a,int arraySize) {
    for(int i = 0; i < arraySize; i++)
        cout << a[i] << " ";
    cout << endl;
}

string inttoroman(int num){
    int x = num;
    int count = -1;
    while(x!=0){
        x/=10;
        count++;
    }
    if(num<4*binary_pow(10,count)){
        string s;
        for(int i = 0;i<num;i+=binary_pow(10,count))
        s += ToRoman(binary_pow(10,count));
        return s;
    }
    else if(num>8*binary_pow(10,count)){
        string s;
        if(num==9*binary_pow(10,count)){
            s+=ToRoman(binary_pow(10,count));
            s+=ToRoman(5*binary_pow(10,count));
            return s;
        }
        s+=ToRoman(10*binary_pow(10,count));
    }
    else{
        string s;
        if(num==4*binary_pow(10,count)){
            s+=ToRoman(binary_pow(10,count));
            s+=ToRoman(5*binary_pow(10,count));
            return s;
        }
        s += ToRoman(5*binary_pow(10,count));

        for(int i = 5*binary_pow(10,count);i<num;i+=binary_pow(10,count))
            s += ToRoman(binary_pow(10,count));
        return s;
    }

}

string intTostring(int num){
    vector<int> buf;
    rec(num,buf,num,0);
    print(buf,buf.size());
    string res;
    for(int i = 0; i < buf.size();i++) {
        res += inttoroman(buf[i]);
    }
    return res;
}

int main() {
    string num1;
    cin >> num1;
    string num2;
    cin >> num2;
    int res = convertToInt(num1) + convertToInt(num2);
    cout << res << " \n";
    string romanRes = intTostring(res);
    cout << romanRes;
    cout << endl;
}
