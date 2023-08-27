#include "Functions.hpp"


void Utils::init_Stopwords(const locale loc){//OK
    wstring word;
    wifstream file("./dataset/stopwords.txt");
    if(!file.is_open()){
        cerr << "Não foi possível abrir o arquivo!" << endl;
        exit(1);
    }
    file.imbue(loc);
    while (file >> word){this->Hash_stopwords.insert(word);}
    file.close();
}

void Utils::ADD_Main_Hash(wstring word){
    if(Hash_stopwords.find(word) == Hash_stopwords.end()){
        this->Main_Hash[word]++;   
    }
}

void Utils::print_Main_Hash(){//OK
    for (auto const &pair: Main_Hash) {
        wcout << "{" << pair.f << ": " << pair.s << "}\n";
    }
}

void Utils::print_stopwords(){//OK
    for (auto itr = Hash_stopwords.begin(); itr != Hash_stopwords.end();itr++){
        wcout << (*itr) << endl;
    }
}

void Utils::init_Heap(){
    for (auto const &pair: Main_Hash){
        if(Heap.size() < K){
            this->Heap.pb(make_pair(pair.f,pair.s));
            if(Heap.size() == K){
                make_heap(Heap.begin(),Heap.end(),greater1());//CRIAR O HEAP
            }
        }
        else{
            pop_heap(Heap.begin(), Heap.end());
            Heap.pop_back();
            if(pair.s > Heap[0].s){
                pop_heap(Heap.begin(), Heap.end());
                Heap.pop_back();
                Heap.pb(make_pair(pair.f,pair.s));
                push_heap(Heap.begin(),Heap.end());
            }
        }
    }

}

void Utils::set_Hash_stopwords(unordered_set<wstring> Hash_stopwords){
    this->Hash_stopwords=Hash_stopwords;
} 
unordered_set<wstring> Utils::get_Hash_stopwords(){
    return this->Hash_stopwords;
}

void Utils::set_Main_Hash(unordered_map<wstring,int> Main_Hash){
    this->Main_Hash=Main_Hash;
}

unordered_map<wstring,int> Utils::get_Main_Hash(){
    return this->Main_Hash;
}

void Utils::set_Heap(vector<pair<wstring,int>> Heap){
    this->Heap=Heap;
}

vector<pair<wstring,int>>  Utils::get_Heap(){
    return this->Heap;    
}


void Utils::Print_Heap(){
    for (auto const &pair: Heap) {
        wcout << "{" << pair.f << ": " << pair.s << "}\n";
    }
}

wchar_t* Utils::getText(const locale loc, string name)
{
  wifstream txt(name, ios::binary);

  if(!txt.is_open())
  {
    cerr << "Não foi possível abrir o arquivo " << name << endl;
    exit(1);
  }

  txt.imbue(loc);
  txt.seekg(0, ios::end);
  streampos tamanho = txt.tellg();
  txt.seekg(0, ios::beg);
  wchar_t* buffer = new wchar_t[tamanho];
  txt.read(buffer, tamanho);
  txt.close();

  return buffer;
}


