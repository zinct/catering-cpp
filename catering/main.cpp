//
//  main.cpp
//  catering
//
//  Created by Indra Mahesa on 16/12/23.
//

#include <iostream>
#include "catering.h"

using namespace std;

int main() {
    CateringList cateringList;
    FoodMenuList foodMenuList;
    
    createCateringList(cateringList);
    createFoodMenuList(foodMenuList);
    
    int menu;
    
    do {
        cout << "========== Selamat datang di layanan catering ==========" << endl;
        cout << "1. Tambah Catering" << endl;
        cout << "2. Tambah Menu Makanan" << endl;
        cout << "3. Hubungkan Catering dan Menu Makanan" << endl;
        cout << "4. Hapus Data Catering" << endl;
        cout << "5. Hapus Data Menu Makanan" << endl;
        cout << "6. Tampilkan Data Catering" << endl;
        cout << "7. Tampilkan Data Makanan" << endl;
        cout << "8. Tampilkan Data Catering Beserta Makanan" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> menu;
        
        // Menu process
        if(menu == 1) {
            CateringInfoType cateringInfo;
            cateringInfo.id = getMaxCateringID(cateringList) + 1;
            cout << "Masukkan Nama Catering: ";
            cin.ignore();
            getline(cin, cateringInfo.name);
            cout << "Masukkan Harga: ";
            cin >> cateringInfo.price;
            
            insertCatering(cateringList, createCateringElement(cateringInfo));
            cout << "Catering berhasil ditambahkan." << endl;
        } else if(menu == 2) {
            FoodMenuInfoType foodMenuInfo;
            foodMenuInfo.id = getMaxFoodMenuID(foodMenuList) + 1;
            foodMenuInfo.totalOrdered = 0;
            cout << "Masukkan Nama Menu Makanan: ";
            cin.ignore();
            getline(cin, foodMenuInfo.name);
            
            insertFoodMenu(foodMenuList, createFoodMenuElement(foodMenuInfo));
            cout << "Menu makanan berhasil ditambahkan." << endl;
        } else if(menu == 3) {
            int cateringId;
            cout << "Masukkan ID Catering: ";
            cin >> cateringId;
            
            CateringAddress catering = findCatering(cateringList, cateringId);
            
            if(catering == NULL) {
                cout << "Data Catering tidak ditemukan!" << endl;
                continue;
            }
            
            int foodId;
            cout << "Masukkan ID Makanan: ";
            cin >> foodId;
            
            FoodMenuAddress foodMenu = findFoodMenu(foodMenuList, foodId);
            
            if(foodMenu == NULL) {
                cout << "Data Makanan tidak ditemukan!" << endl;
                continue;
            }
            
            connectCateringToFoodMenu(catering, foodMenu);
            
            cout << "Berhasil menguhubungkan Catering dengan Makanan" << endl;
            
        } else if(menu == 4) {
            int id;
            cout << "Masukkan ID yang ingin dihapus: ";
            cin >> id;
            cout << id << endl;
            
            CateringAddress deletedCatering = findCatering(cateringList, id);
            
            if(deletedCatering == NULL) {
                cout << "ID Tidak ditemukan!" << endl;
            } else {
                deleteCatering(cateringList, deletedCatering);
                cout << "Berhasil menghapus catering" << endl;
            }
        } else if(menu == 5) {
            int id;
            cout << "Masukkan ID yang ingin dihapus: ";
            cin >> id;
            cout << id << endl;
            
            FoodMenuAddress deletedFoodMenu = findFoodMenu(foodMenuList, id);
            
            if(deletedFoodMenu == NULL) {
                cout << "ID Tidak ditemukan!" << endl;
            } else {
                //deleteFoodMenu(cateringList, deletedFoodMenu);
                cout << "Berhasil menghapus makanan" << endl;
            }
        } else if(menu == 6) {
            showCateringList(cateringList);
        } else if(menu == 7) {
            showFoodMenuList(foodMenuList);
        } else {
            cout << "Menu Tidak ditemukan!" << endl;
        }
        
    } while (menu != 0);
    
    cout << "Berhasil keluar aplikasi" << endl;
    
    return 0;
}
