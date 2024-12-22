#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
#include <cmath>

#include "Akuarium.h"
#include "Custom_Struct.h"

// Kontruktor Akuarium
Akuarium::Akuarium(float maxVolume, float currentTemp) {
    temp = currentTemp; // suhu
    tanki.max = maxVolume; // volume maksimal tanki (cm^3)
    tanki.current = maxVolume; // volume saat ini tanki (cm^3)
    dirtyPercen = 0; // persentase kekotoran akuarium
}

// Metode untuk mengembalikan nilai total ikan yang ada pada akuarium
int Akuarium::getFishCount() const {
    int count = 0;

    for(const Fish f : fishs) { // iterasi list fishs pada akuarium
        count += f.count;
    }
    return count;
}
// Metode untuk mengembalikan kapasitas maksimal ikan yang bisa ditampung akuarium
int Akuarium::getTotalFishCount() const {
    int fishSize = 3; // in cm

    return tanki.current / pow(fishSize, 3); // rumus volume tanki / (ukuran ikan pangkat 3)
}
// Metode untuk mengembalikan data string dari ikan yang ada pada akuarium
string Akuarium::stringFish() {
    string res;
    for(const Fish f : fishs) {
        res.append("\n- " + f.type + ": " + to_string(f.count)); // menambahkan "\n <namaIkan>: <jumlah>" tiap iterasi
    }
    return res;
}
// Metode untuk mengembalikan objek Fish yang sama dengan tipe yang diinput
list<Fish>::iterator Akuarium::getFish(string fishType) {
    list<Fish>::iterator it = find_if(fishs.begin(), fishs.end(), [&fishType](const Fish& fish) { // menggunakan function find_if yang disediakan di module algorithm untuk mencari objek
        return fish.type == fishType; // mencocokan apakah tipe ikan dari iterasi saat itu sama dengan yang dicari
    });
    return it;
}
// Metode untuk menambahkan ikan ke akuarium
void Akuarium::addFish(string fishType, int amount) {
    list<Fish>::iterator it = getFish(fishType); // mencari data pada list
    if(it != fishs.end()) { // jika ketemu maka hanya menambahkan jumlahnya saja
        it->count += amount;
    } else { // jika tidak ketemu maka akan membuat objek Fish baru di bagian belakang
        fishs.push_back({ type: fishType, count: amount });
    }
}
// Metode untuk mengurangi jumlah ikan pada akuarium
void Akuarium::minFish(string fishType, int amount) {
    list<Fish>::iterator it = getFish(fishType);

    if(it == fishs.end()) return; // jika tidak ketemu maka langsung keluar dari metode

    if(it->count <= amount) { // mengecek jika count kurang dari atau sama dengan amount, maka hapus ikan tipe tersebut dari list
        fishs.erase(it);
    } else { // jika tidak maka dikurangi saja
        it->count -= amount;
    }
}
// Metode untuk mengatur jumlah tipe ikan yang ada pada akuarium
void Akuarium::setFish(string fishType, int value) {
    list<Fish>::iterator it = getFish(fishType);

    if(it == fishs.end()) { // jika tidak ketemu maka, tambahkan objek Fish baru
        addFish(fishType, value);
    } else { // jika ketemu maka hanya mengatur count dengan value
        it->count = value;
    }
}

// Metode untuk mengembalikan nilai dari temperatur saat itu
float Akuarium::getTemp() const {
    return temp;
}
// Metode untuk menambahkan nilai suhu
void Akuarium::upTemp(float amount) {
    temp += amount;
}
// Metode untuk mengurangi nilai suhu
void Akuarium::downTemp(float amount) {
    upTemp(-amount);
}
// Metode untuk mengatur nilai suhu menjadi value
void Akuarium::setTemp(float value) {
    temp = value;
}

// Metode untuk mengembalikan Volume tanki akuarium 
Volume Akuarium::getTanki() const {
    return tanki;
}
// Metode untuk mengembalikan nilai total kapasitas tanki (L)
float Akuarium::tankiCapacity() {
    return getTanki().max * 0.001;
}
// Metode untuk menambahkan volume air akuarium
void Akuarium::addCurrentTanki(float amount) {
    if(tanki.current + amount > tanki.max) return setCurrentTanki(tanki.max);
    tanki.current += amount;
}
// Metode untuk mengurangi volume air akuarium
void Akuarium::minCurrentTanki(float amount) {
    if(tanki.current - amount < 0) return setCurrentTanki(0);
    addCurrentTanki(-amount);
}
// Metode untuk mengatur volume air akuarium menjadi value
void Akuarium::setCurrentTanki(float value) {
    tanki.current = value;
}

// Metode untuk mengembalikan nilai persentase kekotoran akuarium
float Akuarium::getDirty() const {
    return dirtyPercen;
}
// Metode untuk menambahkan persentase kekotoran akuarium
void Akuarium::upDirty(float amount) {
    if(dirtyPercen + amount > 100) return setDirty(100);
    dirtyPercen += amount;
}
// Metode untuk mengurangi persentase kekotoran akuarium
void Akuarium::downDirty(float amount) {
    if(dirtyPercen - amount < 0) return setDirty(0);
    upDirty(-amount);
}
// Metode untuk mengatur persentase kekotoran akuarium menjadi value
void Akuarium::setDirty(float value) {
    dirtyPercen = value;
}

// Menampilkan properti akuarium
void Akuarium::display() {
    cout << "Akuarium" << endl
        << "Volume         : " << getTanki().current << "/" << getTanki().max << " cm^3" << endl\
        << "Tanki Capacity : " << tankiCapacity() << "L" << endl
        << "Fish Count     : " << getFishCount() << "/" << getTotalFishCount() << " Fish" << endl
        << "Fish Detail    : " << stringFish() << endl
        << "Fish Stres     : " << isFishStress() << endl
        << "Temperature    : " << getTemp() << " deg" << endl
        << "Dirty Percen   : " << getDirty() << "%" << endl << endl;
}

string Akuarium::isFishStress() {
    string res = "False";
    if(getFishCount() > getTotalFishCount() || getDirty() > 30) res = "True";
    return res;
}