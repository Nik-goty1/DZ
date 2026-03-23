#include <iostream>
using namespace std;

class String {
    char* ptr;
    int length;

public:
    int GetLength() const { return length; }

    String() {
        length = 0;
        ptr = new char[1]; 
        ptr[0] = '\0';
    }

    String(const String& other) {
        length = other.length;
        ptr = new char[length + 1];
        for(int i = 0; i <= length; i++) ptr[i] = other.ptr[i];
    }

    String(const char* input) {
        length = 0;
        while (input[length] != '\0') length++;
        
        ptr = new char[length + 1];
        for(int i = 0; i <= length; i++) ptr[i] = input[i];
    }
    
    String(const char* ptr, int length) {
    this->length = length;
    this->ptr = new char[length + 1];
    for(int i = 0; i < length; i++) {
        this->ptr[i] = ptr[i];
    }
    this->ptr[length] = '\0';
}

    ~String() {
        delete[] ptr;
    }

    void Print() const {
        if (ptr) cout << ptr << endl;
    }

    void Append(const char* suffix) {
        int suffix_len = 0;
        while (suffix[suffix_len] != '\0') suffix_len++;

        char* new_ptr = new char[length + suffix_len + 1];

        for(int i = 0; i < length; i++) new_ptr[i] = ptr[i];
        for(int i = 0; i <= suffix_len; i++) new_ptr[i + length] = suffix[i];

        delete[] ptr;
        ptr = new_ptr;
        length += suffix_len;
    }

    void Append(const String& other) {
        Append(other.ptr);
    }
    
    bool Contains(const char* substring) const{
        if (!substring) return false;

        int sub_len = 0;
        while (substring[sub_len] != '\0') sub_len++;

        if (sub_len == 0)
            return true;

        for (int i = 0; i <= length - sub_len; i++){
            int j = 0;
            while (j < sub_len && ptr[i + j] == substring[j]) {
                j++;
            }
            if (j == sub_len)
                return true;
        }
        
        return false;
    }
    
    int Count(const char* substring) const{
        if (!substring) return 0;

        int sub_len = 0;
        while (substring[sub_len] != '\0')
            sub_len++;

        if (sub_len == 0)
            return 0;

        int count = 0;

        for (int i = 0; i <= length - sub_len; i++){
            int j = 0;
            while (j < sub_len && ptr[i + j] == substring[j]){
                j++;
            }
            if (j == sub_len){
                count++;
                i += sub_len - 1; 
            }
        }

        return count;
    }
    
    void Insert(int position, const char* substring) {
    if (!substring) return;
    if (position < 0) position = 0;
    if (position > length) position = length;

    int sub_len = 0;
    while (substring[sub_len] != '\0') sub_len++;

    char* new_ptr = new char[length + sub_len + 1];

    for (int i = 0; i < position; i++) {
        new_ptr[i] = ptr[i];
    }

    for (int i = 0; i < sub_len; i++) {
        new_ptr[position + i] = substring[i];
    }

    for (int i = position; i < length; i++) {
        new_ptr[i + sub_len] = ptr[i];
    }

    new_ptr[length + sub_len] = '\0';

    delete[] ptr;
    ptr = new_ptr;
    length += sub_len;
}

    void Clear() {
        delete[] ptr;
        length = 0;
        ptr = new char[1];
        ptr[0] = '\0';
    }
};

int main()

{

    String string;
    int length = 8;

    const char* ptr = "My text1"; 
    char ptr2[] = "My text2"; 

    String var1(ptr, length);
    String var2(ptr2);

    var1.Print();
    var2.Print();

    String var3(var2);
    var3.Print();

    var1.Append(var2);
    var1.Print();

    var2.Append(" | Test");
    var2.Print();
    string.Print();
    string.Append("First string");
    string.Print();

    var1.Print();
    var1.Clear();
    var1.Print();

    cout << "-----------------" << '\n';
    
    String test("Hello people people");
    cout << test.Contains("Hello") << endl;
    cout << test.Contains("people") << endl;
    cout << test.Contains("stop") << endl;
    cout << test.Contains("e p") << endl;
    
    cout << "=============================" << "\n";
    
    cout << test.Count("Hello") << endl;
    cout << test.Count("hello") << endl;
    cout << test.Count("people") << endl;
    cout << test.Count("start") << endl;
    
    cout << "=============================" << "\n";
    
    test.Insert(6, "OYY");
    test.Print();
    
    test.Insert(20, "END");
    test.Print();

    return 0;

}