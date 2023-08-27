#include "Functions.hpp"

int main(){
int num;
Utils u;
setlocale(LC_ALL, "pt_BR.UTF-8");
locale loc(locale(), new codecvt_utf8<wchar_t>);
u.init_Stopwords(loc);
wstring word;

cout<<"DIGITE A QUANTIDADE DE ARQUIVOS: " <<endl; cin >> num;

for(int i=1;i<=num;i++){
string arquivo = "./dataset/input"+to_string(i)+".data";
wchar_t* txt = u.getText(loc, arquivo), *ch = txt;
    while(*ch){
        switch(*ch){
            case L' ':  case L'!': case L'?': case L'.': 
            case L'\n': case L',': case L'(': case L')': 
            case L';':  case L'/': case L':': case L'—': 
            case L'"':  case L'\'':
            if(!word.empty()){
                u.ADD_Main_Hash(word);
                word.clear();
            }
            break;
            default:
                if(*ch == '-' && word.size() == 0)
                {
                    break;
                }
                word += tolower(*ch);
            break;
        }
        ch++;
    }
    delete[] txt;
}
u.init_Heap();
u.Print_Heap();

return 0;
}




















/*unordered_set<string> Hash_stopwords;
ifstream arq1;
arq1.open("stopwords.txt");
string line;
while(!arq1.eof()){
    getline(arq1,line);
    Hash_stopwords.insert(line);
    line="";
}
arq1.close();

for (auto itr = Hash_stopwords.begin(); itr != Hash_stopwords.end();itr++){
        cout << (*itr) << endl;
    }
cout<<"=-=-=-=-=-=--===-=-=-=-=-=-=-=-=-=-=-=-=-=-=-"<<endl;*/




/*u.init_Heap();
cout<<"=-=-=-=-=-=--===-=-=-=-=-=-=-=-=-=-=-=-=-=-=-"<<endl;
u.Print_Heap();
cout<<"=-=-=-=-=-=--===-=-=-=-=-=-=-=-=-=-=-=-=-=-=-"<<endl;
u.print_Main_Hash();*/
