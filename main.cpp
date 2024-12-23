#include <iostream>
#include <vector>
#include <sstream>
#include <atomic>
#include <chrono>
#include <thread>
#include <fstream>

#include "Akuarium.h"
#include "Custom_Struct.h"

using namespace std;

// global variable looping
atomic<bool> isRunning(true);

// Prosedur interval untuk mengupdate akuarium
void updateAkuarium(Akuarium* ak) {
    while(isRunning) { //  berhenti jika var isRunning == false
        (*ak).upDirty((*ak).getFishCount() * 0.2); // meningkatkan kekotoran akuarium dengan rumus = currentFish * 0.2

        (*ak).upTemp(((float)rand())/RAND_MAX * 4.0 - 2.0); // meningkatkan atau menurunkan suhu akuarium antara -2.0 sampain 2 dalam float
        this_thread::sleep_for(chrono::seconds(5)); // berhenti sejenak selama 5 detik
    }
    cout << "Close function updateAkuarium";
}

int main() {
    Akuarium akuarium1(800.0, 34.5); // var akuarium
    string input; // var input
    vector<string> words; // var input tetapi sudah di potong per kata

    thread updateFunction(updateAkuarium, &akuarium1); // inisiasi loop

    cout << "Program Simulasi Akuarium" << endl
        << "- addfish, minfish, setfish         mengatur ikan, <addfish|minfish|setfish> <namaIkan> <jumlah>" << endl
        << "- clean                             membersihkan akuarium" << endl
        << "- downtemp, uptemp, settemp         mengatur nilai suhu akuarium, <downtemp|uptemp|settemp> <nilai>" << endl
        << "- draintanki, filltanki, settanki   mengatur tanki, <draintanki|filltanki|settanki> <nilai>" << endl
        << "- v                                 menampilkan status akuarium" << endl
        << "- x                                 export status akuarium saat ini" << endl
        << "- q                                 keluar dari program" << endl << endl;


    while(isRunning) { // berjalan sampai var isRunning == false atau user menekan q
        cout << "$> ";
        input = "";
        getline(cin, input); // mengambil input sebaris

        stringstream ss(input); // memecah var input per kata
        string word;
        words.clear();

        while(ss >> word) words.push_back(word); // menambahkan kata tersebut ke vektor words

        // input user
        if(words[0] == "q") { // jika menekan q maka program berhenti
            cout << "Mematikan Program" << endl;
            isRunning = false;
        } else if(words[0] == "v") { // jika menekan v maka akan menampilkan properti akuarium1
            akuarium1.display(cout);
        } else if(words[0] == "clean") { // membersikan akuarium
            akuarium1.setDirty(0.0);
            cout << "Membersikan akuarium" << endl;
        } else if(words[0] == "addfish") { // Menambahkan ikan
            // format: addfish <string: namaIkan> <int: jumlah>
            string type = words[1], typeDefault =  "Alien";
            int amount = stoi(words[2]); // mengubah string menjadi integer

            if(akuarium1.getFishCount() + amount > akuarium1.getTotalFishCount()) { // Jika maksimal ikan lebih dari total yang seharusnya maka tidak akan di tambahkan
                cout << "Akuarium tidak muat" << endl;
                continue;
            }

            if(type.empty()) type = typeDefault;

            akuarium1.addFish(type, amount);
            cout << "Menambahkan " << amount << " " << type << " ke akuarium" << endl; 
        } else if(words[0] == "minfish") { // Mengambil ikan
            // format: minfish <string: namaIkan> <int: jumlah>
            string type = words[1], typeDefault =  "Alien";
            int amount = stoi(words[2]);

            if(type.empty()) type = typeDefault;

            akuarium1.minFish(type, amount);
            cout << "Mengurangi " << amount << " " << type << " dari akuarium" << endl; 
        } else if(words[0] == "setfish") { // Mengatur jumlah ikan
            // format: setfish <string: namaIkan> <int: amount>
            string type = words[1], typeDefault =  "Alien";
            int amount = stoi(words[2]);

            if(type.empty()) type = typeDefault;

            akuarium1.setFish(type, amount);
            cout << "Mengatur jumlah ikan " << type << " dari akuarium" << "menjadi" << amount << endl; 
        } else if(words[0] == "uptemp") { // Menambah nilai suhu
            // format: uptemp <nilai>
            float amount = stof(words[1]); // mengubah string ke float

            akuarium1.upTemp(amount);
            cout << "Meningkatkan suhu akuarium sebesar " << amount << " deg" << endl;
        } else if(words[0] == "downtemp") { // Menurunkan nilai suhu
            // format: downtemp <nilai>
            float amount = stof(words[1]);
            
            akuarium1.downTemp(amount);
            cout << "Menurunkan suhu akuarium sebesar " << amount << " deg" << endl;
        } else if(words[0] == "settemp") { // Mengatur nilai suhu
            // format: settemp <nilai>
            float amount = stof(words[1]);
            
            akuarium1.setTemp(amount);
            cout << "Mengatur suhu akuarium menjadi " << amount << " deg" << endl;
        } else if(words[0] == "filltanki") { // Mengisi tanki
            // format: filltanki <nilai>
            float amount = stof(words[1]);

            if(akuarium1.getTanki().current + amount > akuarium1.getTanki().max) {
                akuarium1.setCurrentTanki(akuarium1.getTanki().max);
                cout << "Tanki full" << endl;
                continue;
            }

            akuarium1.addCurrentTanki(amount);
            cout << "Mengisi volume tanki sebanyak " << amount << "L" << endl;
        } else if(words[0] == "draintanki") { // Mengurangi tanki
            // format: draintanki <nilai>
            float amount = stof(words[1]);

            if(akuarium1.getTanki().current < amount) {
                akuarium1.setCurrentTanki(0);
                cout << "Tanki kosong" << endl;
                continue;
            }

            akuarium1.minCurrentTanki(amount);
            cout << "Membuang volume tanki sebanyak " << amount << "L" << endl;
        } else if(words[0] == "settanki") { // Mengatur tanki
            // format: settanki <nilai>
            float amount = stof(words[1]);

            akuarium1.setCurrentTanki(amount);
            cout << "Mengatur volume tanki menjadi " << amount << "L" << endl;
        } else if(words[0] == "x") { // Export ke dalam csv
            ofstream outFile("output.csv");

            if (!outFile.is_open()){
                cerr << "Error: Tidak dapat membuka file untuk menulis!" << endl;
                return 1;
            }
            akuarium1.display(outFile);
            outFile.close();
            cout << "Status akuarium berhasil disimpan ke file output.csv" << endl;
        }
    }
    updateFunction.join(); // menjalankan prosedur looping pada background

    return 0;
}